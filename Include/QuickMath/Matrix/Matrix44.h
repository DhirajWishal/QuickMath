// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Matrix.h"
#include "../Vector/Vector4.h"

namespace QuickMath
{
	/**
	 * Matrix 4x4 for QuickMath.
	 */
	class Matrix44 final : public Matrix<Matrix44, float>
	{
	public:
		Matrix44() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}

		/**
		 * Construct the matrix using a value.
		 *
		 * @param value: The value to construct the matrix with.
		 */
		Matrix44(float value) :
			r(value, 0.0f, 0.0f, 0.0f),
			g(0.0f, value, 0.0f, 0.0f),
			b(0.0f, 0.0f, value, 0.0f),
			a(0.0f, 0.0f, 0.0f, value) {}

		/**
		 * Construct the matrix using 4 4D vectors.
		 *
		 * @param vec1: Vector one.
		 * @param vec2: Vector two.
		 * @param vec3: Vector three.
		 * @param vec4: Vector four.
		 */
		Matrix44(Vector4 vec1, Vector4 vec2, Vector4 vec3, Vector4 vec4) : r(vec1), g(vec2), b(vec3), a(vec4) {}

		/**
		 * Construct the matrix using individual values.
		 *
		 * @param a: Value to be set to r.r.
		 * @param b: Value to be set to r.g.
		 * @param c: Value to be set to r.b.
		 * @param d: Value to be set to r.a.
		 * @param e: Value to be set to g.r.
		 * @param f: Value to be set to g.g.
		 * @param g: Value to be set to g.b.
		 * @param h: Value to be set to g.a.
		 * @param i: Value to be set to b.r.
		 * @param j: Value to be set to b.g.
		 * @param k: Value to be set to b.b.
		 * @param l: Value to be set to b.a.
		 * @param m: Value to be set to a.r.
		 * @param n: Value to be set to a.g.
		 * @param o: Value to be set to a.b.
		 * @param p: Value to be set to a.a.
		 */
		Matrix44(
			float a, float b, float c, float d,
			float e, float f, float g, float h,
			float i, float j, float k, float l,
			float m, float n, float o, float p)
			: r(a, b, c, d), g(e, f, g, h), b(i, j, k, l), a(m, n, o, p) {}

		/**
		 * Construct the matrix using an initializer list.
		 *
		 * @param list: The initialize list.
		 */
		Matrix44(std::initializer_list<float> list)
			: r(0.0f), g(0.0f), b(0.0f), a(0.0f)
		{
			if ((list.size() > 16) || (list.size() < 16))
				return;

			std::copy(list.begin(), list.end(), this);
		}

		/**
		 * Retrieve a row using the index.
		 *
		 * @param index: The index of the row.
		 * @return Vector 4D row.
		 */
		const Vector4 operator[](unsigned int index) const
		{
			return (&r)[index];
		}

		/**
		 * Retrieve a row using the index.
		 *
		 * @param index: The index of the row.
		 * @return Vector 4D row.
		 */
		Vector4& operator[](unsigned int index)
		{
			return (&r)[index];
		}

		/**
		 * Multiply the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix44& operator*(const float& value)
		{
			r *= value;
			g *= value;
			b *= value;
			a *= value;

			return *this;
		}

		/**
		 * Multiplication operator.
		 * Matrix * Vector.
		 *
		 * @param other: The vector 4D.
		 * @return The multiplied vector 4D.
		 */
		Vector4 operator*(const Vector4& other)
		{
			return {
				(r[0] * other[0]) + (r[1] * other[1]) + (r[2] * other[2]) + (r[3] * other[3]),
				(g[0] * other[0]) + (g[1] * other[1]) + (g[2] * other[2]) + (g[3] * other[3]),
				(b[0] * other[0]) + (b[1] * other[1]) + (b[2] * other[2]) + (b[3] * other[3]),
				(a[0] * other[0]) + (a[1] * other[1]) + (a[2] * other[2]) + (a[3] * other[3])
			};
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: The other matrix to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix44& operator*(const Matrix44& other)
		{
			r = (r * other[0][0]) + (g * other[0][1]) + (b * other[0][2]) + (a * other[0][3]);
			g = (r * other[1][0]) + (g * other[1][1]) + (b * other[1][2]) + (a * other[1][3]);
			b = (r * other[2][0]) + (g * other[2][1]) + (b * other[2][2]) + (a * other[2][3]);
			a = (r * other[3][0]) + (g * other[3][1]) + (b * other[3][2]) + (a * other[3][3]);

			return *this;
		}

	public:
		union
		{
			struct
			{
				Vector4 r, g, b, a;
			};

			struct
			{
				Vector4 x, y, z, w;
			};
		};
	};
}
