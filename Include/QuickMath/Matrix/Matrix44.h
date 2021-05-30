// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Matrix.h"
#include "../Vector/Vector4.h"

namespace QuickMath
{
	class Matrix33;

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
		Matrix44(const Vector4& vec1, const Vector4& vec2, const Vector4& vec3, const Vector4& vec4) : r(vec1), g(vec2), b(vec3), a(vec4) {}

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

			std::copy(list.begin(), list.end(), &this->x.x);
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
		 * Add two matrices.
		 *
		 * @param other: The other matrix.
		 * @return The new matrix.
		 */
		Matrix44 operator+(const Matrix44& other)
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix.x = x + other.x;
			newMatrix.y = y + other.y;
			newMatrix.z = z + other.z;

			return newMatrix;
		}

		/**
		 * Subtract two matrices.
		 *
		 * @param other: The other matrix.
		 * @return The new matrix.
		 */
		Matrix44 operator-(const Matrix44& other)
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix.x = x - other.x;
			newMatrix.y = y - other.y;
			newMatrix.z = z - other.z;

			return newMatrix;
		}

		/**
		 * Multiply the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix44 operator*(const float& value)
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix.r = r * value;
			newMatrix.g = g * value;
			newMatrix.b = b * value;
			newMatrix.a = a * value;

			return newMatrix;
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
			return (Vector4(r.x, g.x, b.x, a.x) * other.x) + (Vector4(r.y, g.y, b.y, a.y) * other.y) + (Vector4(r.z, g.z, b.z, a.z) * other.z) + (Vector4(r.w, g.w, b.w, a.w) * other.w);
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: The other matrix to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix44 operator*(const Matrix44& other)
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix.r = (r * other[0][0]) + (g * other[0][1]) + (b * other[0][2]) + (a * other[0][3]);
			newMatrix.g = (r * other[1][0]) + (g * other[1][1]) + (b * other[1][2]) + (a * other[1][3]);
			newMatrix.b = (r * other[2][0]) + (g * other[2][1]) + (b * other[2][2]) + (a * other[2][3]);
			newMatrix.a = (r * other[3][0]) + (g * other[3][1]) + (b * other[3][2]) + (a * other[3][3]);

			return newMatrix;
		}

		/**
		 * Divide the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The divided matrix.
		 */
		Matrix44 operator/(const float& value)
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix.r = r / value;
			newMatrix.g = g / value;
			newMatrix.b = b / value;
			newMatrix.a = a / value;

			return newMatrix;
		}

		/**
		 * Get the transposed matrix of this.
		 *
		 * @return The transposed matrix.
		 */
		Matrix44 Transpose() const
		{
			return Matrix44(x.x, y.x, z.x, w.x, x.y, y.y, z.y, w.y, x.z, y.z, z.z, w.z, x.w, y.w, z.w, w.w);
		}

		/**
		 * Get the determinant of the matrix.
		 *
		 * @return The determinant value.
		 */
		float Determinant() const
		{
			float a = x.x * Matrix33(y.y, y.z, y.w, z.y, z.z, z.w, w.y, w.z, w.w).Determinant();
			float b = x.y * Matrix33(y.x, y.z, y.w, z.x, z.z, z.w, w.x, w.z, w.w).Determinant();
			float c = x.y * Matrix33(y.x, y.y, y.w, z.x, z.y, z.w, w.x, w.y, w.w).Determinant();
			float d = x.y * Matrix33(y.x, y.y, y.z, z.x, z.y, z.z, w.x, w.y, w.z).Determinant();

			return a - b + c - d;
		}

		/**
		 * Get the adjugate matrix of the current matrix (Adj(x)).
		 *
		 * @return The matrix.
		 */
		Matrix44 Adjugate() const
		{
			float a = Matrix33(y.y, y.z, y.w, z.y, z.z, z.w, w.y, w.z, w.w).Determinant();
			float b = Matrix33(y.x, y.z, y.w, z.x, z.z, z.w, w.x, w.z, w.w).Determinant();
			float c = Matrix33(y.x, y.y, y.w, z.x, z.y, z.w, w.x, w.y, w.w).Determinant();
			float d = Matrix33(y.x, y.y, y.z, z.x, z.y, z.z, w.x, w.y, w.z).Determinant();

			float e = Matrix33(x.y, x.z, x.w, z.y, z.z, z.w, w.y, w.z, w.w).Determinant();
			float f = Matrix33(x.x, x.z, x.w, z.x, z.z, z.w, w.x, w.z, w.w).Determinant();
			float g = Matrix33(x.x, x.y, x.w, z.x, z.y, z.w, w.x, w.y, w.w).Determinant();
			float h = Matrix33(x.x, x.y, x.z, z.x, z.y, z.z, w.x, w.y, w.z).Determinant();

			float i = Matrix33(x.y, x.z, x.w, y.y, y.z, y.w, w.y, w.z, w.w).Determinant();
			float j = Matrix33(x.x, x.z, x.w, y.x, y.z, y.w, w.x, w.z, w.w).Determinant();
			float k = Matrix33(x.x, x.y, x.w, y.x, y.y, y.w, w.x, w.y, w.w).Determinant();
			float l = Matrix33(x.x, x.y, x.z, y.x, y.y, y.z, w.x, w.y, w.z).Determinant();

			float m = Matrix33(x.y, x.z, x.w, y.y, y.z, y.w, z.y, z.z, z.w).Determinant();
			float n = Matrix33(x.x, x.z, x.w, y.x, y.z, y.w, z.x, z.z, z.w).Determinant();
			float o = Matrix33(x.x, x.y, x.w, y.x, y.y, y.w, z.x, z.y, z.w).Determinant();
			float p = Matrix33(x.x, x.y, x.z, y.x, y.y, y.z, z.x, z.y, z.z).Determinant();

			return Matrix44(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
		}

		/**
		 * Get the inverse matrix of the current matrix.
		 *
		 * @return The inverse matrix.
		 */
		Matrix44 Inverse() const
		{
			float a = 1.0f / Determinant();
			return Adjugate() * a;
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
