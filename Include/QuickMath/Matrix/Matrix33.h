// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"

namespace QuickMath
{
	class Matrix22;

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
		Matrix33(const Vector3& vec1, const Vector3& vec2, const Vector3& vec3) : r(vec1), g(vec2), b(vec3) {}

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

			std::copy(list.begin(), list.end(), &this->x.x);
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
		 * Add two matrices.
		 *
		 * @param other: The other matrix.
		 * @return The new matrix.
		 */
		Matrix33 operator+(const Matrix33& other)
		{
			Matrix33 newMatrix = Matrix33::Identity;
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
		Matrix33 operator-(const Matrix33& other)
		{
			Matrix33 newMatrix = Matrix33::Identity;
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
		Matrix33 operator*(const float& value)
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
		Vector3 operator*(const Vector3& other)
		{
			return (Vector3(r.x, g.x, b.x) * other.x) + (Vector3(r.y, g.y, b.y) * other.y) + (Vector3(r.z, g.z, b.z) * other.z);
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: The other matrix to be multiplied with.
		 * @return The multiplied matrix.
		 */
		Matrix33 operator*(const Matrix33& other)
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
		Matrix33 operator/(const float& value)
		{
			Matrix33 newMatrix = Matrix33::Identity;
			newMatrix.r = r / value;
			newMatrix.g = g / value;
			newMatrix.b = b / value;

			return newMatrix;
		}

		/**
		 * Get the transposed matrix of this.
		 *
		 * @return The transposed matrix.
		 */
		Matrix33 Transpose() const
		{
			return Matrix33(x.x, y.x, z.x, x.y, y.y, z.y, x.z, y.z, z.z);
		}

		/**
		 * Get the determinant of the matrix.
		 *
		 * @return The determinant value.
		 */
		float Determinant() const
		{
			float a = x.x * Matrix22(y.y, y.z, z.y, z.z).Determinant();
			float b = x.y * Matrix22(y.x, y.z, z.x, z.z).Determinant();
			float c = x.z * Matrix22(y.x, y.y, z.x, z.y).Determinant();

			return a - b + c;
		}

		/**
		 * Get the adjugate matrix of the current matrix (Adj(x)).
		 *
		 * @return The matrix.
		 */
		Matrix33 Adjugate() const
		{
			float a = Matrix22(y.y, y.z, z.y, z.z).Determinant();
			float b = -Matrix22(x.y, x.z, z.y, z.z).Determinant();
			float c = Matrix22(x.y, x.z, y.y, y.z).Determinant();

			float d = -Matrix22(y.x, y.z, z.x, z.z).Determinant();
			float e = Matrix22(x.x, x.z, z.x, z.z).Determinant();
			float f = -Matrix22(x.x, x.z, y.x, y.z).Determinant();

			float g = Matrix22(y.x, y.y, z.x, z.y).Determinant();
			float h = -Matrix22(x.x, x.y, z.x, z.y).Determinant();
			float i = Matrix22(x.x, x.y, y.x, y.y).Determinant();

			return Matrix33(a, b, c, d, e, f, g, h, i);
		}

		/**
		 * Get the inverse matrix of the current matrix.
		 *
		 * @return The inverse matrix.
		 */
		Matrix33 Inverse() const
		{
			float a = 1.0f / Determinant();
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
}
