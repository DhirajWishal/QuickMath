// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Matrix22.h"

namespace QuickMath
{
	/**
	 * Matrix 3x3 for QuickMath.
	 */
	template<class Primitive>
	class Matrix33 final : public Matrix<Matrix33<Primitive>, Primitive>
	{
		using Vector3 = TVector<Primitive, 3>;
		using Matrix22 = Matrix22<Primitive>;

	public:
		Matrix33() : r(Primitive()), g(Primitive()), b(Primitive()) {}

		/**
		 * Construct the matrix using one value.
		 *
		 * @param value: The value to be constructed with.
		 */
		Matrix33(Primitive value) :
			r({ value, Primitive(), Primitive() }),
			g({ Primitive(), value, Primitive() }),
			b({ Primitive(), Primitive(), value }) {}

		/**
		 * Construct the matrix using 3 Vector 3D structures.
		 *
		 * @param vec1: Vector one.
		 * @param vec2: Vector two.
		 * @param vec3: Vector three.
		 */
		Matrix33(const Vector3& vec1, const Vector3& vec2, const Vector3& vec3) : r(vec1), g(vec2), b(vec3) {}

		/**
		 * Construct the matrix using individual values.
		 *
		 * @param a: Value to be set to x[0].
		 * @param b: Value to be set to x[1].
		 * @param c: Value to be set to x[2].
		 * @param d: Value to be set to y[0].
		 * @param e: Value to be set to y[1].
		 * @param f: Value to be set to y[2].
		 * @param g: Value to be set to z[0].
		 * @param h: Value to be set to z[1].
		 * @param i: Value to be set to z[2].
		 */
		Matrix33(
			Primitive a, Primitive b, Primitive c,
			Primitive d, Primitive e, Primitive f,
			Primitive g, Primitive h, Primitive i) :
			x({ a, b, c }), y({ d, e, f }), z({ g, h, i }) {}

		/**
		 * Construct the matrix using an initializer list.
		 *
		 * @param list: The initializer list.
		 */
		Matrix33(const std::initializer_list<Primitive>& list) : r(Primitive()), g(Primitive()), b(Primitive())
		{
			if ((list.size() > 9) || (list.size() < 9))
				return;

			std::copy(list.begin(), list.end(), &this->x[0]);
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
		 * Add two matrices.
		 *
		 * @param other: The other matrix.
		 * @return The new matrix.
		 */
		Matrix33 operator+(const Matrix33& other) const
		{
			Matrix33 newMatrix = Matrix33::Identity;
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
		Matrix33 operator-(const Matrix33& other) const
		{
			Matrix33 newMatrix = Matrix33::Identity;
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
		Matrix33 operator*(const Primitive& value) const
		{
			Matrix33 newMatrix = Matrix33::Identity;
			newMatrix.r = r * value;
			newMatrix.g = g * value;
			newMatrix.b = b * value;

			return newMatrix;
		}

		/**
		 * Multiplication operator.
		 * Matrix * Vector.
		 *
		 * @param other: The vector 3D.
		 * @return The multiplied vector 3D.
		 */
		Vector3 operator*(const Vector3& other) const
		{
			return (Column(0) * other[0]) + (Column(1) * other[1]) + (Column(2) * other[2]);
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: The other matrix to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix33 operator*(const Matrix33& other) const
		{
			Matrix33 newMatrix = Matrix33::Identity;
			newMatrix.r = (r * other[0][0]) + (g * other[0][1]) + (b * other[0][2]);
			newMatrix.g = (r * other[1][0]) + (g * other[1][1]) + (b * other[1][2]);
			newMatrix.b = (r * other[2][0]) + (g * other[2][1]) + (b * other[2][2]);

			return newMatrix;
		}

		/**
		 * Divide the matrix by a value.
		 *
		 * @param value: The value to be multiplied with.
		 * @return The divided matrix.
		 */
		Matrix33 operator/(const Primitive& value) const
		{
			Matrix33 newMatrix = Matrix33::Identity;
			newMatrix.r = r / value;
			newMatrix.g = g / value;
			newMatrix.b = b / value;

			return newMatrix;
		}

		/**
		 * Get a row from the matrix.
		 *
		 * @param index: The index of the column.
		 * @return The row vector.
		 */
		Vector3 Row(unsigned int index) const
		{
			return operator [](index);
		}

		/**
		 * Get a column from the matrix.
		 *
		 * @param index: The index of the column.
		 * @return The column vector.
		 */
		Vector3 Column(unsigned int index) const
		{
			return Vector3({ r[index], g[index], b[index] });
		}

		/**
		 * Get the transposed matrix of this.
		 *
		 * @return The transposed matrix.
		 */
		Matrix33 Transpose() const
		{
			return Matrix33(Column(0), Column(1), Column(2));
		}

		/**
		 * Get the determinant of the matrix.
		 *
		 * @return The determinant value.
		 */
		Primitive Determinant() const
		{
			Primitive a = x[0] * Matrix22(y[1], y[2], z[1], z[2]).Determinant();
			Primitive b = x[1] * Matrix22(y[0], y[2], z[0], z[2]).Determinant();
			Primitive c = x[2] * Matrix22(y[0], y[1], z[0], z[1]).Determinant();

			return a - b + c;
		}

		/**
		 * Get the adjugate matrix of the current matrix (Adj(x)).
		 *
		 * @return The matrix.
		 */
		Matrix33 Adjugate() const
		{
			Primitive a =  Matrix22(y[1], y[2], z[1], z[2]).Determinant();
			Primitive b = -Matrix22(x[1], x[2], z[1], z[2]).Determinant();
			Primitive c =  Matrix22(x[1], x[2], y[1], y[2]).Determinant();

			Primitive d = -Matrix22(y[0], y[2], z[0], z[2]).Determinant();
			Primitive e =  Matrix22(x[0], x[2], z[0], z[2]).Determinant();
			Primitive f = -Matrix22(x[0], x[2], y[0], y[2]).Determinant();

			Primitive g =  Matrix22(y[0], y[1], z[0], z[1]).Determinant();
			Primitive h = -Matrix22(x[0], x[1], z[0], z[1]).Determinant();
			Primitive i =  Matrix22(x[0], x[1], y[0], y[1]).Determinant();

			return Matrix33(a, b, c, d, e, f, g, h, i);
		}

		/**
		 * Get the inverse matrix of the current matrix.
		 *
		 * @return The inverse matrix.
		 */
		Matrix33 Inverse() const
		{
			Primitive a = Primitive(1) / Determinant();
			return Adjugate() * a;
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

	typedef Matrix33<float>		Matrix33f;
	typedef Matrix33<int>		Matrix33i;
	typedef Matrix33<double>	Matrix33d;
}
