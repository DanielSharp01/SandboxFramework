#pragma once

#include <math.h>

namespace Sandbox::Math
{
	struct Vector2;
	struct Vector4;
	struct Matrix4;

	struct Vector3
	{
		float x, y, z;
		Vector3(float x, float y, float z);

		Vector3(const Vector2& other);
		explicit Vector3(const Vector4& other);

		Vector3 operator+(const Vector3& other) const;
		Vector3& operator+=(const Vector3& other);

		Vector3 operator-() const;
		Vector3 operator-(const Vector3& other) const;
		Vector3& operator-=(const Vector3& other);

		Vector3 operator*(const Vector3& other) const;
		Vector3& operator*=(const Vector3& other);
		Vector3 operator*(float other) const;
		Vector3& operator*=(float other);

		Vector3 operator/(const Vector3& other) const;
		Vector3& operator/=(const Vector3& other);
		Vector3 operator/(float other) const;
		Vector3& operator/=(float other);

		float Dot(const Vector3& other) const;
		Vector3 Cross(const Vector3& other) const;
		Vector3 Normalize() const;

		inline float Length() const
		{
			return sqrtf(x * x + y * y + z * z);
		}

		Vector3 Transform(const Matrix4& other) const;
	};
}