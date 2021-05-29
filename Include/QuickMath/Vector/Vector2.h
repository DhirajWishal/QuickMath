// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Vector.h"

namespace QuickMath
{
	/**
	 * The 2D vector of QuickMath.
	 */
	class Vector2 final : public Vector<Vector2, float>
	{
	public:
		Vector2() : x(0.0f), y(0.0f) {}

		/**
		 * Construct using one value which will be set to all (x, y)/ (a, b)/ (width, height).
		 *
		 * @param value: The value to be set with.
		 */
		Vector2(float value) : x(value), y(value) {}

		/**
		 * Set values to the stored data.
		 *
		 * @param value1: Value to be set to x/ a/ width.
		 * @param value2: Value to be set to y/ b/ height.
		 */
		Vector2(float value1, float value2) : x(value1), y(value2) {}

		/**
		 * Set data to the vector using an initializer list.
		 * The list size should be equal to 2.
		 *
		 * @param list: The initializer list.
		 */
		Vector2(const std::initializer_list<float>& list) : x(0.0f), y(0.0f)
		{
			if ((list.size() > 2) || (list.size() < 2))
				return;

			std::copy(list.begin(), list.end(), &x);
		}

		/**
		 * Load data from an initializer list.
		 *
		 * @param list: The initializer list.
		 * @return The data added vector (this).
		 */
		Vector2 operator=(const std::initializer_list<float>& list)
		{
			if ((list.size() > 2) || (list.size() < 2))
				return {};

			std::copy(list.begin(), list.end(), &x);
			return *this;
		}

		/**
		 * Get data using the [] operator.
		 *
		 * @param index: The index of the data to be accessed.
		 * @return Float value at the index.
		 */
		const float operator[](int index) const
		{
			return (operator const float* ())[index];
		}

		/**
		 * Get data using the [] operator.
		 *
		 * @param index: The index of the data to be accessed.
		 * @return Float value at the index.
		 */
		float& operator[](int index)
		{
			return const_cast<float&>((operator const float* ())[index]);
		}

		/**
		 * Return the address of this since it can be accessed by the [] operator.
		 *
		 * @return The pointer of the first element.
		 */
		operator float* ()
		{
			return &x;
		}

		/**
		 * Return the address of this since it can be accessed by the [] operator.
		 *
		 * @return The pointer of the first element.
		 */
		operator const float* () const
		{
			return &x;
		}

		/**
		 * Addition operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector2 operator+(const Vector2& other) const
		{
			return Vector2(x + other.x, y + other.y);
		}

		/**
		 * Subtraction operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector2 operator-(const Vector2& other) const
		{
			return Vector2(x - other.x, y - other.y);
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector2 operator*(const Vector2& other) const
		{
			return Vector2(x * other.x, y * other.y);
		}

		/**
		 * Division operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector2 operator/(const Vector2& other) const
		{
			return Vector2(x / other.x, y / other.y);
		}

		/**
		 * Addition operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector2 operator+(const float& value) const
		{
			return *this + Vector2(value);
		}

		/**
		 * Subtraction operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector2 operator-(const float& value) const
		{
			return *this - Vector2(value);
		}

		/**
		 * Multiplication operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector2 operator*(const float& value) const
		{
			return *this * Vector2(value);
		}

		/**
		 * Division operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector2 operator/(const float& value) const
		{
			return *this / Vector2(value);
		}

		/**
		 * Is equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator==(const Vector2& other) const
		{
			return (x == other.x) && (y == other.y);
		}

		/**
		 * Is not equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator!=(const Vector2& other) const
		{
			return (x != other.x) || (y != other.y);
		}

		/**
		 * Is less than operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator<(const Vector2& other) const
		{
			return (x < other.x) || (y < other.y);
		}

		/**
		 * Is less than or equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator<=(const Vector2& other) const
		{
			return (x <= other.x) || (y <= other.y);
		}

		/**
		 * Is grater than operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator>(const Vector2& other) const
		{
			return (x > other.x) || (y > other.y);
		}

		/**
		 * Is grater than or equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator>=(const Vector2& other) const
		{
			return (x >= other.x) || (y >= other.y);
		}

		/**
		 * AND operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator&&(const Vector2& other) const
		{
			return (x && other.x) && (y && other.y);
		}

		/**
		 * OR operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator||(const Vector2& other) const
		{
			return (x || other.x) || (y || other.y);
		}

		/**
		 * XOR operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator^(const Vector2& other) const
		{
			return (x || other.x) && (y || other.y);
		}

		/**
		 * Inverse NOT operator.
		 *
		 * @return Boolean value.
		 */
		bool operator~() const
		{
			return (x > 0) && (y > 0);
		}

		/**
		 * NOR operator.
		 *
		 * @return Boolean value.
		 */
		bool operator!() const
		{
			return (x != 0) && (y != 0);
		}

	public:
		union
		{
			struct
			{
				float x, y;
			};

			struct
			{
				float a, b;
			};

			struct
			{
				float width, height;
			};
		};
	};
}
