// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Matrix.h"
#include "../Vector/Vector2.h"

namespace QuickMath
{
	/**
	 * Matrix 2x2 for QuickMath.
	 */
	class Matrix22 final : public Matrix<Matrix22, float>
	{
	public:
		Matrix22() : x(0.0f), y(0.0f) {}

		/**
		 * Construct the matrix using one value.
		 *
		 * @param value: The value to be constructed with.
		 */
		Matrix22(float value) :x(value, 0.0f), y(0.0f, value) {}

		/**
		 * Set values to the matrix using two 2D vectors.
		 *
		 * @param vec1: Vector one.
		 * @param vec2: Vector two.
		 */
		Matrix22(const Vector2& vec1, const Vector2& vec2) : x(vec1), y(vec2) {}

		/**
		 * Construct the matrix by setting individual values.
		 *
		 * @param a: Value to be set to x.
		 * @param b: Value to be set to y.
		 * @param c: Value to be set to z.
		 * @param d: Value to be set to w.
		 */
		Matrix22(
			float a, float b,
			float c, float d) : x(a, b), y(c, d) {}

		/**
		 * Construct the matrix using an initializer list.
		 *
		 * @param list: The initializer list.
		 */
		Matrix22(std::initializer_list<float> list) : x(0.0f), y(0.0f)
		{
			if ((list.size() > 4) || (list.size() < 4))
				return;

			std::copy(list.begin(), list.end(), &this->x.x);
		}

		/**
		 * Get a row of the matrix using the index.
		 *
		 * @param index: The index of the row.
		 * @return The requested row.
		 */
		const Vector2 operator[](int index) const
		{
			return (&r)[index];
		}

		/**
		 * Get a row of the matrix using the index.
		 *
		 * @param index: The index of the row.
		 * @return The requested row.
		 */
		Vector2& operator[](int index)
		{
			return (&r)[index];
		}

		/**
		 * Add two matrices.
		 *
		 * @param other: The other matrix.
		 * @return The new matrix.
		 */
		Matrix22 operator+(const Matrix22& other) const
		{
			Matrix22 newMatrix = Matrix22::Identity;
			newMatrix.x = x + other.x;
			newMatrix.y = y + other.y;

			return newMatrix;
		}

		/**
		 * Subtract two matrices.
		 *
		 * @param other: The other matrix.
		 * @return The new matrix.
		 */
		Matrix22 operator-(const Matrix22& other) const
		{
			Matrix22 newMatrix = Matrix22::Identity;
			newMatrix.x = x - other.x;
			newMatrix.y = y - other.y;

			return newMatrix;
		}

		/**
		 * Multiply the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix22 operator*(const float& value) const
		{
			Matrix22 newMatrix = Matrix22::Identity;
			newMatrix.r = r * value;
			newMatrix.g = g * value;

			return newMatrix;
		}

		/**
		 * Multiplication operator.
		 * Matrix * Vector.
		 *
		 * @param other: The vector 2D.
		 * @return The multiplied vector 2D.
		 */
		Vector2 operator*(const Vector2& other) const
		{
			return { (r.x * other.x) + (r.y * other.y), (g.x * other.x) + (g.y * other.y) };
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: The other matrix to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix22 operator*(const Matrix22& other) const
		{
			Matrix22 newMatrix = Matrix22::Identity;
			newMatrix.r = (x * other.x.x) + (y * other.x.y);
			newMatrix.g = (x * other.y.x) + (y * other.y.y);

			return newMatrix;
		}

		/**
		 * Divide the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The divided matrix.
		 */
		Matrix22 operator/(const float& value) const
		{
			Matrix22 newMatrix = Matrix22::Identity;
			newMatrix.r = r / value;
			newMatrix.g = g / value;

			return newMatrix;
		}

		/**
		 * Get a row from the matrix.
		 *
		 * @param index: The index of the column.
		 * @return The row vector.
		 */
		Vector2 Row(unsigned int index) const
		{
			return operator [](index);
		}

		/**
		 * Get a column from the matrix.
		 *
		 * @param index: The index of the column.
		 * @return The column vector.
		 */
		Vector2 Column(unsigned int index) const
		{
			return Vector2(r[index], g[index]);
		}

		/**
		 * Get the transposed matrix of this.
		 *
		 * @return The transposed matrix.
		 */
		Matrix22 Transpose() const
		{
			return Matrix22(Column(0), Column(1));
		}

		/**
		 * Get the determinant of the matrix.
		 *
		 * @return The determinant value.
		 */
		float Determinant() const
		{
			return (x.x * y.y) - (x.y * y.x);
		}

		/**
		 * Get the adjugate matrix of the current matrix (Adj(x)).
		 *
		 * @return The matrix.
		 */
		Matrix22 Adjugate() const
		{
			return Matrix22(y.y, -x.y, -y.x, x.x);
		}

		/**
		 * Get the inverse matrix of the current matrix.
		 *
		 * @return The inverse matrix.
		 */
		Matrix22 Inverse() const
		{
			float a = 1.0f / Determinant();
			return Adjugate() * a;
		}

	public:
		union
		{
			struct
			{
				Vector2 x, y;
			};

			struct
			{
				Vector2 r, g;
			};
		};
	};
}
