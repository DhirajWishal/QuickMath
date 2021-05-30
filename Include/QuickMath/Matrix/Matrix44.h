// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Matrix33.h"

namespace QuickMath
{
	/**
	 * Matrix 4x4 for QuickMath.
	 */
	template<class Primitive>
	class Matrix44 final : public Matrix<Matrix44<Primitive>, Primitive>
	{
		using Vector4 = TVector<Primitive, 4>;
		using Matrix33 = Matrix33<Primitive>;

	public:
		Matrix44() : r(Primitive()), g(Primitive()), b(Primitive()), a(Primitive()) {}

		/**
		 * Construct the matrix using a value.
		 *
		 * @param value: The value to construct the matrix with.
		 */
		Matrix44(Primitive value) :
			r({ value, Primitive(), Primitive(), Primitive() }),
			g({ Primitive(), value, Primitive(), Primitive() }),
			b({ Primitive(), Primitive(), value, Primitive() }),
			a({ Primitive(), Primitive(), Primitive(), value }) {}

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
		 * @param a: Value to be set to r[0].
		 * @param b: Value to be set to r[1].
		 * @param c: Value to be set to r[2].
		 * @param d: Value to be set to r[3].
		 * @param e: Value to be set to g[0].
		 * @param f: Value to be set to g[1].
		 * @param g: Value to be set to g[2].
		 * @param h: Value to be set to g[3].
		 * @param i: Value to be set to b[0].
		 * @param j: Value to be set to b[1].
		 * @param k: Value to be set to b[2].
		 * @param l: Value to be set to b[3].
		 * @param m: Value to be set to a[0].
		 * @param n: Value to be set to a[1].
		 * @param o: Value to be set to a[2].
		 * @param p: Value to be set to a[3].
		 */
		Matrix44(
			Primitive a, Primitive b, Primitive c, Primitive d,
			Primitive e, Primitive f, Primitive g, Primitive h,
			Primitive i, Primitive j, Primitive k, Primitive l,
			Primitive m, Primitive n, Primitive o, Primitive p)
			: r({ a, b, c, d }), g({ e, f, g, h }), b({ i, j, k, l }), a({ m, n, o, p }) {}

		/**
		 * Construct the matrix using an initializer list.
		 *
		 * @param list: The initialize list.
		 */
		Matrix44(const std::initializer_list<Primitive>& list)
			: r(Primitive()), g(Primitive()), b(Primitive()), a(Primitive())
		{
			if ((list.size() > 16) || (list.size() < 16))
				return;

			std::copy(list.begin(), list.end(), &this->x[0]);
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
		 * Add two matrices.
		 *
		 * @param other: The other matrix.
		 * @return The new matrix.
		 */
		Matrix44 operator+(const Matrix44& other) const
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix[0] = x + other[0];
			newMatrix[1] = y + other[1];
			newMatrix[2] = z + other[2];

			return newMatrix;
		}

		/**
		 * Subtract two matrices.
		 *
		 * @param other: The other matrix.
		 * @return The new matrix.
		 */
		Matrix44 operator-(const Matrix44& other) const
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix[0] = x - other[0];
			newMatrix[1] = y - other[1];
			newMatrix[2] = z - other[2];

			return newMatrix;
		}

		/**
		 * Multiply the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix44 operator*(const Primitive& value) const
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix[0] = r * value;
			newMatrix[1] = g * value;
			newMatrix[2] = b * value;
			newMatrix[3] = a * value;

			return newMatrix;
		}

		/**
		 * Multiplication operator.
		 * Matrix * Vector.
		 *
		 * @param other: The vector 4D.
		 * @return The multiplied vector 4D.
		 */
		Vector4 operator*(const Vector4& other) const
		{
			return (Vector4({ r[0], g[0], b[0], a[0] }) * other[0]) + (Vector4({ r[1], g[1], b[1], a[1] }) * other[1]) + (Vector4({ r[2], g[2], b[2], a[2] }) * other[2]) + (Vector4({ r[3], g[3], b[3], a[3] }) * other[3]);
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: The other matrix to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix44 operator*(const Matrix44& other) const
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix[0] = (r * other[0][0]) + (g * other[0][1]) + (b * other[0][2]) + (a * other[0][3]);
			newMatrix[1] = (r * other[1][0]) + (g * other[1][1]) + (b * other[1][2]) + (a * other[1][3]);
			newMatrix[2] = (r * other[2][0]) + (g * other[2][1]) + (b * other[2][2]) + (a * other[2][3]);
			newMatrix[3] = (r * other[3][0]) + (g * other[3][1]) + (b * other[3][2]) + (a * other[3][3]);

			return newMatrix;
		}

		/**
		 * Divide the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The divided matrix.
		 */
		Matrix44 operator/(const Primitive& value) const
		{
			Matrix44 newMatrix = Matrix44::Identity;
			newMatrix[0] = r / value;
			newMatrix[1] = g / value;
			newMatrix[2] = b / value;
			newMatrix[3] = a / value;

			return newMatrix;
		}

		/**
		 * Get a row from the matrix.
		 *
		 * @param index: The index of the column.
		 * @return The row vector.
		 */
		Vector4 Row(unsigned int index) const
		{
			return operator [](index);
		}

		/**
		 * Get a column from the matrix.
		 *
		 * @param index: The index of the column.
		 * @return The column vector.
		 */
		Vector4 Column(unsigned int index) const
		{
			return Vector4({ r[index], g[index], b[index], a[index] });
		}

		/**
		 * Get the transposed matrix of this.
		 *
		 * @return The transposed matrix.
		 */
		Matrix44 Transpose() const
		{
			return Matrix44(Column(0), Column(1), Column(2), Column(3));
		}

		/**
		 * Get the determinant of the matrix.
		 *
		 * @return The determinant value.
		 */
		Primitive Determinant() const
		{
			Primitive a = x[0] * Matrix33(y[1], y[2], y[3], z[1], z[2], z[3], w[1], w[2], w[3]).Determinant();
			Primitive b = x[1] * Matrix33(y[0], y[2], y[3], z[0], z[2], z[3], w[0], w[2], w[3]).Determinant();
			Primitive c = x[1] * Matrix33(y[0], y[1], y[3], z[0], z[1], z[3], w[0], w[1], w[3]).Determinant();
			Primitive d = x[1] * Matrix33(y[0], y[1], y[2], z[0], z[1], z[2], w[0], w[1], w[2]).Determinant();

			return a - b + c - d;
		}

		/**
		 * Get the adjugate matrix of the current matrix (Adj(x)).
		 *
		 * @return The matrix.
		 */
		Matrix44 Adjugate() const
		{
			Primitive a = Matrix33(y[1], y[2], y[3], z[1], z[2], z[3], w[1], w[2], w[3]).Determinant();
			Primitive b = Matrix33(y[0], y[2], y[3], z[0], z[2], z[3], w[0], w[2], w[3]).Determinant();
			Primitive c = Matrix33(y[0], y[1], y[3], z[0], z[1], z[3], w[0], w[1], w[3]).Determinant();
			Primitive d = Matrix33(y[0], y[1], y[2], z[0], z[1], z[2], w[0], w[1], w[2]).Determinant();

			Primitive e = Matrix33(x[1], x[2], x[3], z[1], z[2], z[3], w[1], w[2], w[3]).Determinant();
			Primitive f = Matrix33(x[0], x[2], x[3], z[0], z[2], z[3], w[0], w[2], w[3]).Determinant();
			Primitive g = Matrix33(x[0], x[1], x[3], z[0], z[1], z[3], w[0], w[1], w[3]).Determinant();
			Primitive h = Matrix33(x[0], x[1], x[2], z[0], z[1], z[2], w[0], w[1], w[2]).Determinant();

			Primitive i = Matrix33(x[1], x[2], x[3], y[1], y[2], y[3], w[1], w[2], w[3]).Determinant();
			Primitive j = Matrix33(x[0], x[2], x[3], y[0], y[2], y[3], w[0], w[2], w[3]).Determinant();
			Primitive k = Matrix33(x[0], x[1], x[3], y[0], y[1], y[3], w[0], w[1], w[3]).Determinant();
			Primitive l = Matrix33(x[0], x[1], x[2], y[0], y[1], y[2], w[0], w[1], w[2]).Determinant();

			Primitive m = Matrix33(x[1], x[2], x[3], y[1], y[2], y[3], z[1], z[2], z[3]).Determinant();
			Primitive n = Matrix33(x[0], x[2], x[3], y[0], y[2], y[3], z[0], z[2], z[3]).Determinant();
			Primitive o = Matrix33(x[0], x[1], x[3], y[0], y[1], y[3], z[0], z[1], z[3]).Determinant();
			Primitive p = Matrix33(x[0], x[1], x[2], y[0], y[1], y[2], z[0], z[1], z[2]).Determinant();

			return Matrix44(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
		}

		/**
		 * Get the inverse matrix of the current matrix.
		 *
		 * @return The inverse matrix.
		 */
		Matrix44 Inverse() const
		{
			Primitive a = Primitive(1) / Determinant();
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

	typedef Matrix44<float>		Matrix44f;
	typedef Matrix44<int>		Matrix44i;
	typedef Matrix44<double>	Matrix44d;
}
