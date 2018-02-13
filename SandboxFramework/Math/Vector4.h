#pragma once

namespace Sandbox::Math
{
	struct Vector2;
	struct Vector3;
	struct Matrix4;

	struct Vector4
	{
		float x, y, z, w;
		Vector4(float x, float y, float z, float w);

		Vector4(const Vector2& other);
		Vector4(const Vector3& other);

		Vector4 operator+(const Vector4& other) const;
		Vector4& operator+=(const Vector4& other);

		Vector4 operator-(const Vector4& other) const;
		Vector4& operator-=(const Vector4& other);

		Vector4 operator*(const Vector4& other) const;
		Vector4& operator*=(const Vector4& other);
		Vector4 operator*(float other) const;
		Vector4& operator*=(float other);

		Vector4 operator/(const Vector4& other) const;
		Vector4& operator/=(const Vector4& other);
		Vector4 operator/(float other) const;
		Vector4& operator/=(float other);

		float Dot(const Vector4& other) const;
		Vector4 Transform(const Matrix4& other) const;
	};
}