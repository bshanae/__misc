#pragma once

#include <array>

#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"

namespace Engine
{
	class Matrix4x4;
}

class Engine::Matrix4x4 final
{
public :

	static Matrix4x4 makeZero();
	static Matrix4x4 makeIdentity();

	static Matrix4x4 makeTranslation(const Vector3 &value);
	static Matrix4x4 makeTranslation(float x, float y, float z);

	static Matrix4x4 makeScale(const Vector3 &value);
	static Matrix4x4 makeScale(float x, float y, float z);

	static Matrix4x4 makeRotation(const Vector3 &value);
	static Matrix4x4 makeRotation(const Quaternion &value);

	static Matrix4x4 makePerspectiveProjection(float fovY, float aspect, float zNear, float zFar);
	static Matrix4x4 makeLookAt(const Vector3 &eye, const Vector3 &target, const Vector3 &up);

	Matrix4x4();
	Matrix4x4(const Vector4 &x, const Vector4 &y, const Vector4 &z, const Vector4 &w);

	const float *getData() const;

	const Vector4 &operator [] (int index) const;
	Vector4 &operator [] (int index);

	friend Matrix4x4 operator * (const Matrix4x4 &matrix, float value);
	friend Vector4 operator * (const Matrix4x4 &matrix, const Vector4 &vector);
	friend Vector4 operator * (const Vector4 &vector, const Matrix4x4 &matrix);
	friend Matrix4x4 operator * (const Matrix4x4 &left, const Matrix4x4 &right);

	Matrix4x4 inverse() const;

private :

	union
	{
		Vector4 columns[4];
		float data[16];
	};

	static Matrix4x4 MakeRotationX(float value);
	static Matrix4x4 MakeRotationY(float value);
	static Matrix4x4 MakeRotationZ(float value);
};