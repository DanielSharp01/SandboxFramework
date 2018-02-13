#include "Matrix4.h"

#include <memory>

namespace Sharp::Math
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
			res.cells[i] = getRow(i / 4).dot(other.columns[i % 4]);
		}

		return res;
	}
	Matrix4& Matrix4::operator*=(const Matrix4& other)
	{
		for (int i = 0; i < 16; i++)
		{
			cells[i] = getRow(i / 4).dot(other.columns[i % 4]);
		}

		return *this;
	}

	Vector4 Matrix4::operator*(const Vector4& other) const
	{
		return Vector4(getRow(0).dot(other), getRow(1).dot(other), getRow(2).dot(other), getRow(3).dot(other));
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
}