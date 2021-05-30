// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Vector.h"

namespace QuickMath
{
	/**
	 * Basic 3D Vector for QuickMath.
	 * This class uses SIMD to carry out the necessary calculations.
	 */
	class Vector3 final : public Vector<Vector3, float>
	{
	public:
		Vector3() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

		/**
		 * Set one value to all the data stored.
		 *
		 * @param value: Value to be stored.
		 */
		Vector3(float value) : x(value), y(value), z(value), w(value) {}

		/**
		 * Values to be set to the internal variables.
		 *
		 * @param value1: Value to be set to x/ r/ width.
		 * @param value2: Value to be set to y/ g/ height.
		 * @param value3: Value to be set to z/ b/ depth.
		 */
		Vector3(float value1, float value2, float value3) : x(value1), y(value2), z(value3), w(0.0f) {}

		/**
		 * Construct the vector using an intrinsic value.
		 *
		 * @param intrinsic: The intrinsic value.
		 */
		Vector3(const IntrinsicTraits<float, 3>::Type& intrinsic) : intrinsic(intrinsic) {}

		/**
		 * Construct the vector using an intrinsic value.
		 *
		 * @param intrinsic: The intrinsic value.
		 */
		Vector3(IntrinsicTraits<float, 3>::Type&& intrinsic) : intrinsic(intrinsic) {}

		/**
		 * Construct the vector using an initializer list.
		 * The size of the list should be equal to 3.
		 *
		 * @param list: The initializer list.
		 */
		Vector3(std::initializer_list<float> list) : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{
			if ((list.size() > 3) || (list.size() < 3))
				return;

			std::copy(list.begin(), list.end(), &x);
		}

		/**
		 * Construct the vector using a float pointer.
		 *
		 * @param ptr: The float pointer.
		 */
		Vector3(const float* ptr) : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{
			std::copy(ptr, ptr + 3, &x);
		}

		/**
		 * Load data from an initializer list.
		 *
		 * @param list: The initializer list.
		 * @return The data added vector (this).
		 */
		Vector3 operator=(const std::initializer_list<float>& list)
		{
			if ((list.size() > 3) || (list.size() < 3))
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
		const float operator[](unsigned int index) const
		{
			return (operator const float* ())[index];
		}

		/**
		 * Get data using the [] operator.
		 *
		 * @param index: The index of the data to be accessed.
		 * @return Float value at the index.
		 */
		float& operator[](unsigned int index)
		{
			return const_cast<float&>((operator const float* ())[index]);
		}

		/**
		 * Return the address of this since it can be accessed by the [] operator.
		 *
		 * @return The address of the first element.
		 */
		operator float* ()
		{
			return &x;
		}

		/**
		 * Return the address of this since it can be accessed by the [] operator.
		 *
		 * @return The address of the first element.
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
		Vector3& operator=(const IntrinsicTraits<float, 3>::Type& intrinsic)
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
		Vector3& operator=(IntrinsicTraits<float, 3>::Type&& intrinsic)
		{
			this->intrinsic = std::move(intrinsic);
			return *this;
		}

		/**
		 * Return the stored intrinsic value.
		 *
		 * @return The const intrinsic value.
		 */
		operator const IntrinsicTraits<float, 3>::Type() const
		{
			return intrinsic;
		}

		/**
		 * Return the stored intrinsic value.
		 *
		 * @return The intrinsic value reference.
		 */
		operator IntrinsicTraits<float, 3>::Type& ()
		{
			return intrinsic;
		}

		/**
		 * Addition operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector3 operator+(const Vector3& other) const
		{
			return std::move(_mm_add_ps(*this, other));
		}

		/**
		 * Subtraction operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector3 operator-(const Vector3& other) const
		{
			return std::move(_mm_sub_ps(*this, other));
		}

		/**
		 * Multiplication operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector3 operator*(const Vector3& other) const
		{
			return std::move(_mm_mul_ps(*this, other));
		}

		/**
		 * Division operator.
		 *
		 * @param other: RHS argument.
		 * @return The calculated vector.
		 */
		Vector3 operator/(const Vector3& other) const
		{
			return std::move(_mm_div_ps(*this, other));
		}

		/**
		 * Addition operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector3 operator+(const float& value) const
		{
			return *this + Vector3(value);
		}

		/**
		 * Subtraction operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector3 operator-(const float& value) const
		{
			return *this - Vector3(value);
		}

		/**
		 * Multiplication operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector3 operator*(const float& value) const
		{
			return *this * Vector3(value);
		}

		/**
		 * Division operator.
		 *
		 * @param value: RHS value.
		 * @return The calculated vector.
		 */
		Vector3 operator/(const float& value) const
		{
			return *this / Vector3(value);
		}

		/**
		 * Is equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator==(const Vector3& other) const
		{
			Vector3 vec = std::move(_mm_cmpeq_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * Is not equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator!=(const Vector3& other) const
		{
			Vector3 vec = std::move(_mm_cmpneq_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * Is less than operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator<(const Vector3& other) const
		{
			Vector3 vec = std::move(_mm_cmplt_ps(*this, other));
			return ((vec.r) || (vec.g) || (vec.b) || (vec.a));
		}

		/**
		 * Is less than or equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator<=(const Vector3& other) const
		{
			Vector3 vec = std::move(_mm_cmple_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * Is grater than operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator>(const Vector3& other) const
		{
			Vector3 vec = std::move(_mm_cmpgt_ps(*this, other));
			return ((vec.r) || (vec.g) || (vec.b) || (vec.a));
		}

		/**
		 * Is grater than or equal operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator>=(const Vector3& other) const
		{
			Vector3 vec = std::move(_mm_cmpge_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * AND operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator&&(const Vector3& other) const
		{
			Vector3 vec = std::move(_mm_and_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * OR operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator||(const Vector3& other) const
		{
			Vector3 vec = std::move(_mm_or_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * XOR operator.
		 *
		 * @param other: RHS argument.
		 * @return Boolean value.
		 */
		bool operator^(const Vector3& other) const
		{
			Vector3 vec = std::move(_mm_xor_ps(*this, other));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * Inverse NOT operator.
		 *
		 * @return Boolean value.
		 */
		bool operator~() const
		{
			Vector3 vec = std::move(_mm_or_ps(*this, Vector3(-1.0f)));
			return ((vec.r) && (vec.g) && (vec.b) && (vec.a));
		}

		/**
		 * NOR operator.
		 *
		 * @return Boolean value.
		 */
		bool operator!() const
		{
			Vector3 vec = std::move(_mm_or_ps(*this, Vector3(0.0f)));
			return ((vec.r == 0) && (vec.g == 0) && (vec.b == 0) && (vec.a == 0));
		}

	public:
		union
		{
			struct
			{
				float x, y, z, w;
			};

			struct
			{
				float r, g, b, a;
			};

			struct
			{
				float width, height, depth, zero;
			};

			IntrinsicTraits<float, 3>::Type intrinsic;
		};
	};
}
