#pragma once

#include "Vector4.h"

namespace Sandbox::Math
{
	struct Matrix4
	{
		union
		{
			Vector4 columns[4];
			float cells[16];
		};

		Matrix4();
		Matrix4(Vector4 col0, Vector4 col1, Vector4 col2, Vector4 col3);
		Matrix4(float cells[16]);
		Matrix4(float diagonal);

		Matrix4 operator+(const Matrix4& other) const;
		Matrix4& operator+=(const Matrix4& other);

		Matrix4 operator-(const Matrix4& other) const;
		Matrix4& operator-=(const Matrix4& other);

		Matrix4 operator*(const Matrix4& other) const;
		Matrix4& operator*=(const Matrix4& other);
		Vector4 operator*(const Vector4& other) const;
		Matrix4 operator*(float other) const;
		Matrix4& operator*=(float other);

		Matrix4 operator/(float other) const;
		Matrix4& operator/=(float other);

		inline Vector4 GetRow(int index) const
		{
			return Vector4(cells[index], cells[index + 4], cells[index + 8], cells[index + 12]);
		}

		static Matrix4 CreateTranslation(float x, float y, float z);
		static Matrix4 CreateTranslation(Vector3 vec);

		static Matrix4 CreateScale(float x, float y, float z);
		static Matrix4 CreateScale(Vector3 vec);

		static Matrix4 CreateRotationX(float rad);
		static Matrix4 CreateRotationY(float rad);
		static Matrix4 CreateRotationZ(float rad);

		static Matrix4 CreateAxisRotation(float rad, Vector3 axis);
		static Matrix4 CreateAxisRotation(float rad, Vector3 axisStartPoint, Vector3 axisEndPoint);

		static Matrix4 CreatePerspective(float fov, float aspect, float near, float far);
		static Matrix4 CreateOrthographic(float top, float bottom, float left, float right, float near, float far);
	};
}