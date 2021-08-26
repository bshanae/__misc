#include "MathFunctions.h"

#include <cmath>

using namespace Engine;

float MathUtilities::degreesToRadians(float input)
{
	return input * (float)M_PI / 180.f;
}

float MathUtilities::radiansToDegrees(float input)
{
	return input * 180.f / (float)M_PI;
}