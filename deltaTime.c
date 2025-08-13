#include "deltaTime.h"

int deltaTime(float* clock, float interval) {
	*clock += GetFrameTime();

	if(*clock >= interval) {
        *clock = 0;
        return (1);
    } else return (0);
}