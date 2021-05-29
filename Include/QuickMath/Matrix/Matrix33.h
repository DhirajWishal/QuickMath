// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"

namespace QuickMath
{
	/**
	 * Matrix 3x3 for QuickMath.
	 */
	class Matrix33 final : public Matrix<Matrix33, float>
	{
	public:
		Matrix33() : r(0.0f), g(0.0f), b(0.0f) {}

		/**
		 * Construct the matrix using one value.
		 *
		 * @param value: The value to be constructed with.
		 */
		Matrix33(float value) :
			r(value, 0.0f, 0.0f),
			g(0.0f, value, 0.0f),
			b(0.0f, 0.0f, value) {}

		/**
		 * Construct the matrix using 3 Vector 3D structures.
		 *
		 * @param vec1: Vector one.
		 * @param vec2: Vector two.
		 * @param vec3: Vector three.
		 */
		Matrix33(Vector3 vec1, Vector3 vec2, Vector3 vec3) : r(vec1), g(vec2), b(vec3) {}

		/**
		 * Construct the matrix using individual values.
		 *
		 * @param a: Value to be set to x.x.
		 * @param b: Value to be set to x.y.
		 * @param c: Value to be set to x.z.
		 * @param d: Value to be set to y.x.
		 * @param e: Value to be set to y.y.
		 * @param f: Value to be set to y.z.
		 * @param g: Value to be set to z.x.
		 * @param h: Value to be set to z.y.
		 * @param i: Value to be set to z.z.
		 */
		Matrix33(
			float a, float b, float c,
			float d, float e, float f,
			float g, float h, float i) :
			x(a, b, c), y(d, e, f), z(g, h, i) {}

		/**
		 * Construct the matrix using an initializer list.
		 *
		 * @param list: The initializer list.
		 */
		Matrix33(std::initializer_list<float> list) : r(0.0f), g(0.0f), b(0.0f)
		{
			if ((list.size() > 9) || (list.size() < 9))
				return;

			std::copy(list.begin(), list.end(), this);
		}

		/**
		 * Retrieve a row by using the index.
		 *
		 * @param index: The index of the row.
		 * @return The Vector 3D row.
		 */
		const Vector3 operator[](unsigned int index) const
		{
			return (&r)[index];
		}

		/**
		 * Retrieve a row by using the index.
		 *
		 * @param index: The index of the row.
		 * @return The Vector 3D row.
		 */
		Vector3& operator[](unsigned int index)
		{
			return (&r)[index];
		}

		/**
		 * Multiply the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix33& operator*(const float& value)
		{
			r *= value;
			g *= value;
			b *= value;

			return *this;
		}

		/**
		 * Multiplication operator.
		 * Matrix * Vector.
		 *
		 * @param other: The vector 3D.
		 * @return The multiplied vector 3D.
		 */
		Vector3 operator*(const Vector3& other)
		{
			return {
				(r[0] * other[0]) + (r[1] * other[1]) + (r[2] * other[2]),
				(g[0] * other[0]) + (g[1] * other[1]) + (g[2] * other[2]),
				(b[0] * other[0]) + (b[1] * other[1]) + (b[2] * other[2])
			};
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: The other matrix to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix33& operator*(const Matrix33& other)
		{
			r = (r * other[0][0]) + (g * other[0][1]) + (b * other[0][2]);
			g = (r * other[1][0]) + (g * other[1][1]) + (b * other[1][2]);
			b = (r * other[2][0]) + (g * other[2][1]) + (b * other[2][2]);

			return *this;
		}

	public:
		union
		{
			struct
			{
				Vector3 x, y, z;
			};

			struct
			{
				Vector3 r, g, b;
			};
		};
	};
}
