#pragma once

namespace Sharp::Math
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

		float dot(const Vector3& other);
		Vector3 cross(const Vector3& other);
		Vector3 transform(const Matrix4& other);
	};
}