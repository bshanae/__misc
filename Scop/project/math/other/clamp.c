#include "scop_math.h"

float				clamp(float min, float max, float value)
{
	if (value > max)
		return (max);
	if (value < min)
		return (min);
	return (value);
}