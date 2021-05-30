// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "Vector.h"

namespace QuickMath
{
	using namespace Operators;

	/**
	 * TVector object.
	 * This object is the abstract object for all vectors.
	 *
	 * @tparam Primitive: The primitive type. Supported types are: float, double and int.
	 * @tparam Layers: The number of layers in the vector. Supported are 2, 3, 4 and 8.
	 */
	template<class Primitive, int Layers>
	class TVector : public Vector<TVector<Primitive, Layers>, Primitive>
	{
		using Intrinsic = IntrinsicTraits<Primitive, Layers>;
		using Type = Intrinsic::Type;

		static_assert(std::is_same<Primitive, float>::value || std::is_same<Primitive, double>::value || std::is_same<Primitive, int>::value,
			"Unsupported Primitive type! The supported primitive types are float, double and int.");

		static_assert(Layers > 1 && Layers < 9, "Unsupported layer count! The supported layer counts are 2, 3, 4 and 8.");

	public:
		TVector() = default;

		/**
		 * Construct the vector using a single primitive value.
		 *
		 * @param primitive: The primitive value.
		 */
		TVector(const Primitive& primitive) { std::fill_n(&Intrinsic::At(mStorage, 0), Layers, primitive); }

		/**
		 * Construct the vector using a storage object.
		 *
		 * @param storage: The storage to construct with.
		 */
		TVector(const Type& storage) : mStorage(storage) {}

		/**
		 * Construct the vector using a storage object.
		 *
		 * @param storage: The storage to construct with.
		 */
		TVector(Type&& storage) : mStorage(storage) {}

		/**
		 * Construct the vector using an initializer list.
		 * The initializer list's content should match the vector size/ layer count.
		 *
		 * @param list: The initializer list.
		 */
		TVector(const std::initializer_list<Primitive>& list)
		{
			if (list.size() != Layers)
				return;

			std::copy(list.begin(), list.end(), &Intrinsic::At(mStorage, 0));
		}

		/**
		 * Get an element from a location.
		 *
		 * @param index: The index of the element.
		 * @return The primitive reference.
		 */
		Primitive& At(unsigned int index) { return Intrinsic::At(mStorage, index); }

		/**
		 * Get an element from a location.
		 *
		 * @param index: The index of the element.
		 * @return The const primitive.
		 */
		const Primitive At(unsigned int index) const { return Intrinsic::At(mStorage, index); }

	public:
		/**
		 * Copy assignment operator.
		 *
		 * @param storage: The storage object to assign.
		 * @return This vector reference.
		 */
		TVector& operator=(const Type& storage)
		{
			mStorage = storage;
			return *this;
		}

		/**
		 * Move assignment operator.
		 *
		 * @param storage: The storage object to assign.
		 * @return This vector reference.
		 */
		TVector& operator=(Type&& storage) noexcept
		{
			mStorage = std::move(storage);
			return *this;
		}

		/**
		 * The index operator.
		 *
		 * @param index: The index of the element.
		 * @return The primitive reference.
		 */
		Primitive& operator[](unsigned int index) { return At(index); }

		/**
		 * The index operator.
		 *
		 * @param index: The index of the element.
		 * @return The const primitive.
		 */
		const Primitive operator[](unsigned int index) const { return At(index); }

		/**
		 * Implicit storage conversion operator.
		 */
		operator Type& () { return mStorage; }

		/**
		 * Implicit storage conversion operator.
		 */
		operator const Type() const { return mStorage; }

		/**
		 * Add a primitive to this vector.
		 * 
		 * @param value: The primitive value.
		 * @return The added vector.
		 */
		TVector operator+(const Primitive& value) const
		{
			return mStorage + TVector(value).mStorage;
		}

		/**
		 * Add another vector to this vector.
		 *
		 * @param value: The other vector.
		 * @return The added vector.
		 */
		TVector operator+(const TVector& vector) const
		{
			return mStorage + vector.mStorage;
		}

		/**
		 * Subtract a primitive from this vector.
		 *
		 * @param value: The primitive value.
		 * @return The subtracted vector.
		 */
		TVector operator-(const Primitive& value) const
		{
			return mStorage - TVector(value).mStorage;
		}

		/**
		 * Subtract another vector from this vector.
		 *
		 * @param value: The other vector.
		 * @return The subtracted vector.
		 */
		TVector operator-(const TVector& vector) const
		{
			return mStorage - vector.mStorage;
		}

		/**
		 * Multiply a primitive with this vector.
		 *
		 * @param value: The primitive value.
		 * @return The multiplied vector.
		 */
		TVector operator*(const Primitive& value) const
		{
			return mStorage * TVector(value).mStorage;
		}

		/**
		 * Multiply another vector with this vector.
		 *
		 * @param value: The other vector.
		 * @return The multiplied vector.
		 */
		TVector operator*(const TVector& vector) const
		{
			return mStorage * vector.mStorage;
		}

		/**
		 * Divide a primitive from this vector.
		 *
		 * @param value: The primitive value.
		 * @return The divided vector.
		 */
		TVector operator/(const Primitive& value) const
		{
			return mStorage / TVector(value).mStorage;
		}

		/**
		 * Divide another vector from this vector.
		 *
		 * @param value: The other vector.
		 * @return The divided vector.
		 */
		TVector operator/(const TVector& vector) const
		{
			return mStorage / vector.mStorage;
		}

		/**
		 * Logical AND operator.
		 * 
		 * @param other: The other vector.
		 * @return The resultant vector.
		 */
		TVector operator&&(const TVector& other) const
		{
			return mStorage && other.mStorage;
		}

		/**
		 * Logical OR operator.
		 *
		 * @param other: The other vector.
		 * @return The resultant vector.
		 */
		TVector operator||(const TVector& other) const
		{
			return mStorage || other.mStorage;
		}

		/**
		 * Logical XOR operator.
		 *
		 * @param other: The other vector.
		 * @return The resultant vector.
		 */
		TVector operator^(const TVector& other) const
		{
			return mStorage ^ other.mStorage;
		}

	protected:
		Type mStorage = {};
	};

	typedef TVector<float, 2> Vector2f;
	typedef TVector<float, 3> Vector3f;
	typedef TVector<float, 4> Vector4f;
	typedef TVector<float, 8> Vector8f;

	typedef TVector<int, 2> Vector2i;
	typedef TVector<int, 3> Vector3i;
	typedef TVector<int, 4> Vector4i;
	typedef TVector<int, 8> Vector8i;

	typedef TVector<double, 2> Vector2d;
	typedef TVector<double, 3> Vector3d;
	typedef TVector<double, 4> Vector4d;
	typedef TVector<double, 8> Vector8d;
}