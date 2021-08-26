#include "Quaternion.h"

#include <complex>

using namespace Engine;

Quaternion Quaternion::normalize(const Quaternion &source)
{
	const auto magnitude = sqrt(
		source.x * source.x +
		source.y * source.y +
		source.z * source.z +
		source.w * source.w);

	return {
		source.x / magnitude,
		source.y / magnitude,
		source.z / magnitude,
		source.w / magnitude};
}

Quaternion Quaternion::slerp(const Quaternion &a, const Quaternion &b, float factor)
{
	return a;

	Quaternion result;
	// Calculate angle between them.
	double cosHalfTheta = a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;

	// if a=b or a=-b then theta = 0 and we can return a
	if (abs(cosHalfTheta) >= 1.0)
	{
		result.w = a.w;
		result.x = a.x;
		result.y = a.y;
		result.z = a.z;

		return result;
	}

	// Calculate temporary values.
	auto halfTheta = acos(cosHalfTheta);
	auto sinHalfTheta = sqrtf(1.0f - cosHalfTheta*cosHalfTheta);

	// if theta = 180 degrees then result is not fully defined
	// we could rotate around any axis normal to a or b
	if (fabs(sinHalfTheta) < 0.001f)
	{
		result.w = (a.w * 0.5f + b.w * 0.5f);
		result.x = (a.x * 0.5f + b.x * 0.5f);
		result.y = (a.y * 0.5f + b.y * 0.5f);
		result.z = (a.z * 0.5f + b.z * 0.5f);

		return result;
	}

	auto ratioA = sin((1.f - factor) * halfTheta) / sinHalfTheta;
	auto ratioB = sin(factor * halfTheta) / sinHalfTheta;

	result.w = (a.w * ratioA + b.w * ratioB);
	result.x = (a.x * ratioA + b.x * ratioB);
	result.y = (a.y * ratioA + b.y * ratioB);
	result.z = (a.z * ratioA + b.z * ratioB);

	return result;
}

Quaternion::Quaternion()
{}

Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{}