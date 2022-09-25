#include "camera.h"
#include "player.h"
#include "../res/resources.h"

Vect2D_s16 cameraPosition;

AABB cameraDeadzone;

void setupCamera(Vect2D_s16 deadZoneCenter, Vect2D_u16 deadZoneDimensions) {
    
    // Calculate the bounds of the camera deadzone
    cameraDeadzone.min = (Vect2D_s16) {
                            deadZoneCenter.x - (deadZoneDimensions.x >> 1),
                            deadZoneCenter.y - (deadZoneDimensions.y >> 1)
                        };
    cameraDeadzone.max = (Vect2D_s16) {
                            deadZoneCenter.x + (deadZoneDimensions.x >> 1),
                            deadZoneCenter.y + (deadZoneDimensions.y >> 1)
                        };

    updateCamera();

    MAP_scrollToEx(bg, cameraPosition.x, cameraPosition.y, TRUE);
}

void updateCamera() {
	//Update camera only if the center of the player is outside the deadZone of the camera
	if (playerBody.globalPosition.x + playerBody.centerOffset.x > cameraPosition.x + cameraDeadzone.max.x) {
		cameraPosition.x = playerBody.globalPosition.x + playerBody.centerOffset.x - cameraDeadzone.max.x;

	}else if (playerBody.globalPosition.x + playerBody.centerOffset.x < cameraPosition.x + cameraDeadzone.min.x) {
		cameraPosition.x = playerBody.globalPosition.x + playerBody.centerOffset.x - cameraDeadzone.min.x;
	}

	if (playerBody.globalPosition.y + playerBody.centerOffset.y > cameraPosition.y + cameraDeadzone.max.y) {
		cameraPosition.y = playerBody.globalPosition.y + playerBody.centerOffset.y - cameraDeadzone.max.y;

	}else if (playerBody.globalPosition.y + playerBody.centerOffset.y < cameraPosition.y + cameraDeadzone.min.y) {
		cameraPosition.y = playerBody.globalPosition.y + playerBody.centerOffset.y - cameraDeadzone.min.y;
	}

	//Clamp camera to the limits of the level
	cameraPosition.x = clamp(cameraPosition.x, 0, bg->w - screenWidth); // 768 - 320 = 448 (level width - screen width)
	cameraPosition.y = clamp(cameraPosition.y, 0, bg->h - screenHeight); // 768 - 224 = 544 (level height - screen height)

	//Finally we update the position of the camera
	MAP_scrollTo(bg, cameraPosition.x, cameraPosition.y);
}

