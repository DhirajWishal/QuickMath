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
		Matrix22(Vector2 vec1, Vector2 vec2) : x(vec1), y(vec2) {}

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

			std::copy(list.begin(), list.end(), this);
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
		 * Multiply the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix22& operator*(const float& value)
		{
			r *= value;
			g *= value;

			return *this;
		}

		/**
		 * Multiplication operator.
		 * Matrix * Vector.
		 *
		 * @param other: The vector 2D.
		 * @return The multiplied vector 2D.
		 */
		Vector2 operator*(const Vector2& other)
		{
			return { (r[0] * other[0]) + (r[1] * other[1]), (g[0] * other[0]) + (g[1] * other[1]) };
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: The other matrix to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix22& operator*(const Matrix22& other)
		{
			r = (x * other[0][0]) + (y * other[0][1]);
			g = (x * other[1][0]) + (y * other[1][1]);

			return *this;
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
