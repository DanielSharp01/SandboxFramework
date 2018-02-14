#include "Matrix4.h"

#include "Vector3.h"
#include <memory>

namespace Sandbox::Math
{
	Matrix4::Matrix4()
		: Matrix4(1)
	{ }

	Matrix4::Matrix4(Vector4 col0, Vector4 col1, Vector4 col2, Vector4 col3)
		: columns{ col0, col1, col2, col3 }
	{ }

	Matrix4::Matrix4(float cells[16])
	{
		memcpy(Matrix4::cells, cells, 16 * sizeof(float));
	}

	Matrix4::Matrix4(float diagonal)
	{
		memset(Matrix4::cells, 0, 16 * sizeof(float));
		columns[0].x = diagonal;
		columns[1].y = diagonal;
		columns[2].z = diagonal;
		columns[3].w = diagonal;
	}

	Matrix4 Matrix4::operator+(const Matrix4& other) const
	{
		Matrix4 res;
		for (int i = 0; i < 16; i++)
		{
			res.cells[i] = cells[i] + other.cells[i];
		}

		return res;
	}
	Matrix4& Matrix4::operator+=(const Matrix4& other)
	{
		for (int i = 0; i < 16; i++)
		{
			cells[i] += other.cells[i];
		}

		return *this;
	}

	Matrix4 Matrix4::operator-(const Matrix4& other) const
	{
		Matrix4 res;
		for (int i = 0; i < 16; i++)
		{
			res.cells[i] = cells[i] - other.cells[i];
		}

		return res;
	}
	Matrix4& Matrix4::operator-=(const Matrix4& other)
	{
		for (int i = 0; i < 16; i++)
		{
			cells[i] -= other.cells[i];
		}

		return *this;
	}

	Matrix4 Matrix4::operator*(const Matrix4& other) const
	{
		Matrix4 res;
		for (int i = 0; i < 16; i++)
		{
			res.cells[i] = GetRow(i / 4).Dot(other.columns[i % 4]);
		}

		return res;
	}
	Matrix4& Matrix4::operator*=(const Matrix4& other)
	{
		for (int i = 0; i < 16; i++)
		{
			cells[i] = GetRow(i / 4).Dot(other.columns[i % 4]);
		}

		return *this;
	}

	Vector4 Matrix4::operator*(const Vector4& other) const
	{
		return Vector4(GetRow(0).Dot(other), GetRow(1).Dot(other), GetRow(2).Dot(other), GetRow(3).Dot(other));
	}

	Matrix4 Matrix4::operator*(float other) const
	{
		Matrix4 res;
		for (int i = 0; i < 16; i++)
		{
			res.cells[i] = cells[i] * other;
		}

		return res;
	}

	Matrix4& Matrix4::operator*=(float other)
	{
		for (int i = 0; i < 16; i++)
		{
			cells[i] *= other;
		}

		return *this;
	}

	Matrix4 Matrix4::operator/(float other) const
	{
		Matrix4 res;
		for (int i = 0; i < 16; i++)
		{
			res.cells[i] = cells[i] / other;
		}

		return res;
	}

	Matrix4& Matrix4::operator/=(float other)
	{
		for (int i = 0; i < 16; i++)
		{
			cells[i] *= other;
		}

		return *this;
	}

	Matrix4 Matrix4::CreateTranslation(float x, float y, float z)
	{
		Matrix4 mat;
		mat.columns[0] = Vector4(1, 0, 0, 0);
		mat.columns[1] = Vector4(0, 1, 0, 0);
		mat.columns[2] = Vector4(0, 0, 1, 0);
		mat.columns[3] = Vector4(x, y, z, 1);
		return mat;
	}

	Matrix4 Matrix4::CreateTranslation(Vector3 vec)
	{
		return CreateTranslation(vec.x, vec.y, vec.z);
	}

	Matrix4 Matrix4::CreateScale(float x, float y, float z)
	{
		Matrix4 mat;
		mat.columns[0] = Vector4(x, 0, 0, 0);
		mat.columns[1] = Vector4(0, y, 0, 0);
		mat.columns[2] = Vector4(0, 0, z, 0);
		mat.columns[3] = Vector4(0, 0, 0, 1);
		return mat;
	}

	Matrix4 Matrix4::CreateScale(Vector3 vec)
	{
		return CreateScale(vec.x, vec.y, vec.z);
	}

	Matrix4 Matrix4::CreateRotationX(float rad)
	{
		float c = cosf(rad);
		float s = sinf(rad);

		Matrix4 mat;
		mat.columns[0] = Vector4(1, 0, 0, 0);
		mat.columns[1] = Vector4(0, c, -s, 0);
		mat.columns[2] = Vector4(0, s, c, 0);
		mat.columns[3] = Vector4(0, 0, 0, 1);
		return mat;
	}

	Matrix4 Matrix4::CreateRotationY(float rad)
	{
		float c = cosf(rad);
		float s = sinf(rad);

		Matrix4 mat;
		mat.columns[0] = Vector4(c, 0, s, 0);
		mat.columns[1] = Vector4(0, 1, 0, 0);
		mat.columns[2] = Vector4(-s, 0, c, 0);
		mat.columns[3] = Vector4(0, 0, 0, 1);
		return mat;
	}

	Matrix4 Matrix4::CreateRotationZ(float rad)
	{
		float c = cosf(rad);
		float s = sinf(rad);

		Matrix4 mat;
		mat.columns[0] = Vector4(c, -s, 0, 0);
		mat.columns[1] = Vector4(s, c, 0, 0);
		mat.columns[2] = Vector4(0, 0, 1, 0);
		mat.columns[3] = Vector4(0, 0, 0, 1);
		return mat;
	}

	Matrix4 Matrix4::CreateAxisRotation(float rad, Vector3 axis)
	{
		Matrix4 mat;
		float c = cosf(rad);
		float omc = 1 - c;
		float s = sinf(rad);
		float u2 = axis.x * axis.x;
		float v2 = axis.y * axis.y;
		float w2 = axis.z * axis.z;
		float uvomc = omc * axis.x * axis.y;
		float uwomc = omc * axis.x * axis.z;
		float vwomc = omc * axis.y * axis.z;
		float us = axis.x * s;
		float vs = axis.y * s;
		float ws = axis.z * s;

		mat.columns[0] = Vector4(u2 + (1 - u2)*c, uvomc + ws, uwomc - vs, 0);
		mat.columns[1] = Vector4(uvomc - ws, v2 + (1 - v2)*c, vwomc + us, 0);
		mat.columns[2] = Vector4(uwomc + vs, vwomc - us, w2 + (1 - w2)*c, 0);
		mat.columns[3] = Vector4(0, 0, 0, 1);
		return mat;
	}

	Matrix4 Matrix4::CreateAxisRotation(float rad, Vector3 axisStartPoint, Vector3 axisEndPoint)
	{
		return CreateTranslation(-axisStartPoint) * CreateAxisRotation(rad, (axisEndPoint - axisStartPoint).Normalize()) * CreateTranslation(axisStartPoint);
	}

	Matrix4 Matrix4::CreatePerspective(float fov, float aspect, float near, float far)
	{
		Matrix4 mat;
		float t = 1.0f / tanf(fov/2);
		mat.columns[0] = Vector4(t * aspect, 0, 0, 0);
		mat.columns[1] = Vector4(0, t, 0, 0);
		mat.columns[2] = Vector4(0, 0, (far + near) / (near - far), -1);
		mat.columns[3] = Vector4(0, 0, (2 * far * near) / (far - near), 0);
		return mat;
	}

	Matrix4 Matrix4::CreateOrthographic(float top, float bottom, float left, float right, float near, float far)
	{
		Matrix4 mat;
		mat.columns[0] = Vector4(2 / (right-left), 0, 0, 0);
		mat.columns[1] = Vector4(0, 2 / (top - bottom), 0, 0);
		mat.columns[2] = Vector4(0, 0, 2 / (near - far), 0);
		mat.columns[3] = Vector4((right+left) / (left - right), (top + bottom) / (bottom - top), (far + near) / (near - far), 0);
		return mat;
	}
}