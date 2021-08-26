#include "Matrix4x4.h"

#include <cmath>

using namespace Engine;

Matrix4x4 Matrix4x4::makeZero()
{
	return Matrix4x4();
}

Matrix4x4 Matrix4x4::makeIdentity()
{
	auto result = Matrix4x4();

	result[0] = Vector4(1, 0, 0, 0);
	result[1] = Vector4(0, 1, 0, 0);
	result[2] = Vector4(0, 0, 1, 0);
	result[3] = Vector4(0, 0, 0, 1);

	return result;
}

Matrix4x4 Matrix4x4::makeTranslation(const Vector3 &value)
{
	auto result = makeIdentity();

	result[3] = Vector4(value.x, value.y, value.z, 1);
	return result;
}

Matrix4x4 Matrix4x4::makeTranslation(float x, float y, float z)
{
	auto result = makeIdentity();

	result[3] = Vector4(x, y, z, 1);
	return result;
}

Matrix4x4 Matrix4x4::makeScale(const Vector3 &value)
{
	auto result = makeIdentity();

	result[0] = Vector4(value.x, 0, 0, 0);
	result[1] = Vector4(0, value.y, 0, 0);
	result[2] = Vector4(0, 0, value.z, 0);

	return result;
}

Matrix4x4 Matrix4x4::makeScale(float x, float y, float z)
{
	auto result = makeIdentity();

	result[0] = Vector4(x, 0, 0, 0);
	result[1] = Vector4(0, y, 0, 0);
	result[2] = Vector4(0, 0, z, 0);

	return result;
}

Matrix4x4 Matrix4x4::makeRotation(const Vector3 &value)
{
	return MakeRotationX(value.x) * MakeRotationY(value.y) * MakeRotationZ(value.z);
}

Matrix4x4 Matrix4x4::makeRotation(const Quaternion &value)
{
	const auto qx = value.x;
	const auto qy = value.y;
	const auto qz = value.z;
	const auto qw = value.w;

	Matrix4x4 result;

	result[0][0] = 1 - 2 * qy * qy - 2 * qz * qz;
	result[0][1] = 2 * qx * qy + 2 * qz * qw;
	result[0][2] = 2 * qx * qz - 2 * qy * qw;
	result[0][3] = 0;

	result[1][0] = 2 * qx * qy - 2 * qz * qw;
	result[1][1] = 1 - 2 * qx * qx - 2 * qz * qz;
	result[1][2] = 2 * qy * qz + 2 * qx * qw;
	result[1][3] = 0;

	result[2][0] = 2 * qx * qz + 2 * qy * qw;
	result[2][1] = 2 * qy * qz - 2 * qx * qw;
	result[2][2] = 1 - 2 * qx * qx - 2 * qy * qy;
	result[2][3] = 0;

	result[3][0] = 0;
	result[3][1] = 0;
	result[3][2] = 0;
	result[3][3] = 1;

	return result;
}

Matrix4x4 Matrix4x4::makePerspectiveProjection(float fovY, float aspect, float zNear, float zFar)
{
	const float tanHalfFovY = tan(fovY / 2.f);

	auto result = makeZero();

	result[0][0] = 1.f / (aspect * tanHalfFovY);
	result[1][1] = 1.f / (tanHalfFovY);
	result[2][2] = -(zFar + zNear) / (zFar - zNear);
	result[2][3] = -1.f;
	result[3][2] = -(2.f * zFar * zNear) / (zFar - zNear);

	return result;
}

Matrix4x4 Matrix4x4::makeLookAt(const Vector3 &eye, const Vector3 &target, const Vector3 &up)
{
	Vector3 zAxis = Vector3::normalize(eye - target);
	Vector3 xAxis = Vector3::normalize(Vector3::cross(up, zAxis));
	Vector3 yaxis = Vector3::cross(zAxis, xAxis);

	auto result = makeZero();

	result[0] = Vector4(xAxis.x, yaxis.x, zAxis.x, 0);
	result[1] = Vector4(xAxis.y, yaxis.y, zAxis.y, 0);
	result[2] = Vector4(xAxis.z, yaxis.z, zAxis.z, 0);
	result[3] = Vector4(-Vector3::dot(xAxis, eye), - Vector3::dot(yaxis, eye), -Vector3::dot(zAxis, eye), 1);

	return result;
}

Matrix4x4::Matrix4x4() : columns()
{}

Matrix4x4::Matrix4x4(const Vector4 &x, const Vector4 &y, const Vector4 &z, const Vector4 &w)
{
	columns[0] = x;
	columns[1] = y;
	columns[2] = z;
	columns[3] = w;
}

const float *Matrix4x4::getData() const
{
	return data;
}

const Vector4 &Matrix4x4::operator [] (int index) const
{
	return columns[index];
}

Vector4 &Matrix4x4::operator [] (int index)
{
	return columns[index];
}

Matrix4x4 Engine::operator * (const Matrix4x4 &matrix, float value)
{
	return {
		matrix[0] * value,
		matrix[1] * value,
		matrix[2] * value,
		matrix[3] * value
	};
}

Vector4 Engine::operator * (const Matrix4x4 &matrix, const Vector4 &vector)
{
	return {
		matrix[0][0] * vector[0] + matrix[1][0] * vector[1] + matrix[2][0] * vector[2] + matrix[3][0] * vector[3],
		matrix[0][1] * vector[0] + matrix[1][1] * vector[1] + matrix[2][1] * vector[2] + matrix[3][1] * vector[3],
		matrix[0][2] * vector[0] + matrix[1][2] * vector[1] + matrix[2][2] * vector[2] + matrix[3][2] * vector[3],
		matrix[0][3] * vector[0] + matrix[1][3] * vector[1] + matrix[2][3] * vector[2] + matrix[3][3] * vector[3]
	};
}

Vector4 Engine::operator * (const Vector4 &vector, const Matrix4x4 &matrix)
{
	return {
		vector[0] * matrix[0][0] + vector[1] * matrix[0][1] + vector[2] * matrix[0][2] + vector[3] * matrix[0][3],
		vector[0] * matrix[1][0] + vector[1] * matrix[1][1] + vector[2] * matrix[1][2] + vector[3] * matrix[1][3],
		vector[0] * matrix[2][0] + vector[1] * matrix[2][1] + vector[2] * matrix[2][2] + vector[3] * matrix[2][3],
		vector[0] * matrix[3][0] + vector[1] * matrix[3][1] + vector[2] * matrix[3][2] + vector[3] * matrix[3][3]
	};
}

Matrix4x4 Engine::operator * (const Matrix4x4 &left, const Matrix4x4 &right)
{
	const Vector4 x = left * right[0];
	const Vector4 y = left * right[1];
	const Vector4 z = left * right[2];
	const Vector4 w = left * right[3];

	return Matrix4x4(x, y, z, w);
}

Matrix4x4 Matrix4x4::inverse() const
{
	const float coefficient00 = columns[2][2] * columns[3][3] - columns[3][2] * columns[2][3];
	const float coefficient02 = columns[1][2] * columns[3][3] - columns[3][2] * columns[1][3];
	const float coefficient03 = columns[1][2] * columns[2][3] - columns[2][2] * columns[1][3];

	const float coefficient04 = columns[2][1] * columns[3][3] - columns[3][1] * columns[2][3];
	const float coefficient06 = columns[1][1] * columns[3][3] - columns[3][1] * columns[1][3];
	const float coefficient07 = columns[1][1] * columns[2][3] - columns[2][1] * columns[1][3];

	const float coefficient08 = columns[2][1] * columns[3][2] - columns[3][1] * columns[2][2];
	const float coefficient10 = columns[1][1] * columns[3][2] - columns[3][1] * columns[1][2];
	const float coefficient11 = columns[1][1] * columns[2][2] - columns[2][1] * columns[1][2];

	const float coefficient12 = columns[2][0] * columns[3][3] - columns[3][0] * columns[2][3];
	const float coefficient14 = columns[1][0] * columns[3][3] - columns[3][0] * columns[1][3];
	const float coefficient15 = columns[1][0] * columns[2][3] - columns[2][0] * columns[1][3];

	const float coefficient16 = columns[2][0] * columns[3][2] - columns[3][0] * columns[2][2];
	const float coefficient18 = columns[1][0] * columns[3][2] - columns[3][0] * columns[1][2];
	const float coefficient19 = columns[1][0] * columns[2][2] - columns[2][0] * columns[1][2];

	const float coefficient20 = columns[2][0] * columns[3][1] - columns[3][0] * columns[2][1];
	const float coefficient22 = columns[1][0] * columns[3][1] - columns[3][0] * columns[1][1];
	const float coefficient23 = columns[1][0] * columns[2][1] - columns[2][0] * columns[1][1];

	const Vector4 Fac0(coefficient00, coefficient00, coefficient02, coefficient03);
	const Vector4 Fac1(coefficient04, coefficient04, coefficient06, coefficient07);
	const Vector4 Fac2(coefficient08, coefficient08, coefficient10, coefficient11);
	const Vector4 Fac3(coefficient12, coefficient12, coefficient14, coefficient15);
	const Vector4 Fac4(coefficient16, coefficient16, coefficient18, coefficient19);
	const Vector4 Fac5(coefficient20, coefficient20, coefficient22, coefficient23);

	const Vector4 Vec0(columns[1][0], columns[0][0], columns[0][0], columns[0][0]);
	const Vector4 Vec1(columns[1][1], columns[0][1], columns[0][1], columns[0][1]);
	const Vector4 Vec2(columns[1][2], columns[0][2], columns[0][2], columns[0][2]);
	const Vector4 Vec3(columns[1][3], columns[0][3], columns[0][3], columns[0][3]);

	const Vector4 Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
	const Vector4 Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
	const Vector4 Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
	const Vector4 Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

	const Vector4 SignA(+1, -1, +1, -1);
	const Vector4 SignB(-1, +1, -1, +1);
	const Matrix4x4 Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

	const Vector4 Row0(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0]);

	const Vector4 Dot0(columns[0] * Row0);
	const float Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

	const float OneOverDeterminant = 1.f / Dot1;

	return Inverse * OneOverDeterminant;
}

Matrix4x4 Matrix4x4::MakeRotationX(float value)
{
	auto result = makeIdentity();

	result[1] = Vector4(0, cos(value), sin(value), 0);
	result[2] = Vector4(0, -sin(value), cos(value), 0);

	return result;
}

Matrix4x4 Matrix4x4::MakeRotationY(float value)
{
	auto result = makeIdentity();

	result[0] = Vector4(cos(value), 0, -sin(value), 0);
	result[2] = Vector4(sin(value), 0, cos(value), 0);

	return result;
}

Matrix4x4 Matrix4x4::MakeRotationZ(float value)
{
	auto result = makeIdentity();

	result[0] = Vector4(cos(value), sin(value), 0, 0);
	result[1] = Vector4(-sin(value), cos(value), 0, 0);

	return result;
}