// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Vector.h"

namespace QuickMath
{
	/**
	 * Basic 4D Vector for QuickMath.
	 * This class uses SIMD to carry out the necessary calculations.
	 */
	class Vector4 final : public Vector<Vector4, float>
	{
	public:
		Vector4() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}

		/**
		 * Set data to all the variables using one value.
		 *
		 * @param value: The value to be set.
		 */
		Vector4(float value) : r(value), g(value), b(value), a(value) {}

		/**
		 * Set values to all the variables.
		 *
		 * @param value1: Value to be set to r/ x/ width.
		 * @param value2: Value to be set to g/ y/ height.
		 * @param value3: Value to be set to b/ z/ depth.
		 * @param value4: Value to be set to a/ w/ zero.
		 */
		Vector4(float value1, float value2, float value3, float value4) : r(value1), g(value2), b(value3), a(value4) {}

		/**
		 * Construct the vector using an intrinsic value.
		 *
		 * @param intrinsic: The intrinsic value.
		 */
		Vector4(const IntrinsicTraits<float, 4>::Type& intrinsic) : intrinsic(intrinsic) {}

		/**
		 * Construct the vector using an intrinsic value.
		 *
		 * @param intrinsic: The intrinsic value.
		 */
		Vector4(IntrinsicTraits<float, 4>::Type&& intrinsic) : intrinsic(intrinsic) {}

		/**
		 * Construct the vector using an initializer list.
		 * The size of the list must be equal to 4.
		 *
		 * @param list: The initialize list.
		 */
		Vector4(std::initializer_list<float> list) : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{
			if ((list.size() > 4) || (list.size() < 4))
				return;

			std::copy(list.begin(), list.end(), &x);
		}

		/**
		 * Construct the vector using a float pointer.
		 *
		 * @param ptr: The float pointer.
		 */
		Vector4(const float* ptr) : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{
			std::copy(ptr, ptr + 4, &x);
		}

		/**
		 * Load data from an initializer list.
		 *
		 * @param list: The initializer list.
		 * @return The data added vector (this).
		 */
		Vector4 operator=(const std::initializer_list<float>& list)
		{
			if ((list.size() > 4) || (list.size() < 4))
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
		 * @return The pointer to the first element.
		 */
		operator float* ()
		{
			return &x;
		}

		/**
		 * Return the address of this since it can be accessed by the [] operator.
		 *
		 * @return The pointer to the first element.
		 */
		operator const float* () const
		{
			return &x;
		}

		/**
		 * Assign an intrinsic value to the vector.
		 *
		 * @param intrinsic: The intrinsic value to store.
		 * @return The vector reference.
		 */
		Vector4& operator=(const IntrinsicTraits<float, 4>::Type& intrinsic)
		{
			this->intrinsic = intrinsic;
			return *this;
		}

		/**
		 * Assign an intrinsic value to the vector.
		 *
		 * @param intrinsic: The intrinsic value to store.
		 * @return The vector reference.
		 */
		Vector4& operator=(IntrinsicTraits<float, 4>::Type&& intrinsic)
		{
			this->intrinsic = std::move(intrinsic);
			return *this;
		}

		/**
		 * Return the stored intrinsic value.
		 *
		 * @return The const intrinsic value.
		 */
		operator const IntrinsicTraits<float, 4>::Type() const
		{
			return intrinsic;
		}

		/**
		 * Return the stored intrinsic value.
		 *
		 * @return The intrinsic value reference.
		 */
		operator IntrinsicTraits<float, 4>::Type& ()
		{
			return intrinsic;
		}

		/**
		 * Addition operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector4 operator+(const Vector4& other) const
		{
			return std::move(_mm_add_ps(*this, other));
		}

		/**
		 * Subtraction operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector4 operator-(const Vector4& other) const
		{
			return std::move(_mm_sub_ps(*this, other));
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector4 operator*(const Vector4& other) const
		{
			return std::move(_mm_mul_ps(*this, other));
		}

		/**
		 * Division operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector4 operator/(const Vector4& other) const
		{
			return std::move(_mm_div_ps(*this, other));
		}

		/**
		 * Addition operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector4 operator+(const float& value) const
		{
			return (*this) + Vector4(value);
		}

		/**
		 * Subtraction operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector4 operator-(const float& value) const
		{
			return (*this) - Vector4(value);
		}

		/**
		 * Multiplication operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector4 operator*(const float& value) const
		{
			return (*this) * Vector4(value);
		}

		/**
		 * Division operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector4 operator/(const float& value) const
		{
			return (*this) / +Vector4(value);
		}

		/**
		 * Is equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator==(const Vector4& other) const
		{
			Vector4 vec = std::move(_mm_cmpeq_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * Is not equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator!=(const Vector4& other) const
		{
			Vector4 vec = std::move(_mm_cmpneq_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * Is less than operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator<(const Vector4& other) const
		{
			Vector4 vec = std::move(_mm_cmplt_ps(*this, other));
			return ((vec.r) || (vec.g) || (vec.b) || (vec.a));
		}

		/**
		 * Is less than or equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator<=(const Vector4& other) const
		{
			Vector4 vec = std::move(_mm_cmple_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * Is grater than operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator>(const Vector4& other) const
		{
			Vector4 vec = std::move(_mm_cmpgt_ps(*this, other));
			return ((vec.r) || (vec.g) || (vec.b) || (vec.a));
		}

		/**
		 * Is grater than or equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator>=(const Vector4& other) const
		{
			Vector4 vec = std::move(_mm_cmpge_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * AND operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator&&(const Vector4& other) const
		{
			Vector4 vec = std::move(_mm_and_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * OR operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator||(const Vector4& other) const
		{
			Vector4 vec = std::move(_mm_or_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * XOR operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator^(const Vector4& other) const
		{
			Vector4 vec = std::move(_mm_or_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * Inverse NOT operator.
		 *
		 * @return Boolean value.
		 */
		bool operator~() const
		{
			Vector4 vec = std::move(_mm_or_ps(*this, Vector4(-1.0f)));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * NOR operator.
		 *
		 * @return Boolean value.
		 */
		bool operator!() const
		{
			Vector4 vec = std::move(_mm_or_ps(*this, Vector4(0.0f)));
			return ((vec.r == 0) && (vec.g == 0) && (vec.b == 0) && (vec.a == 0));
		}

	public:
		union
		{
			struct
			{
				float r, g, b, a;
			};

			struct
			{
				float x, y, z, w;
			};

			struct
			{
				float width, height, depth, zero;
			};

			IntrinsicTraits<float, 4>::Type intrinsic;
		};
	};
}
