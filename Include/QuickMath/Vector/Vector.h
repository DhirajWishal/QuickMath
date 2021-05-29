// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "../IncludeSIMD.h"
#include <initializer_list>
#include <algorithm>

namespace QuickMath
{
	/**
	 * Vector base class for the QuickMath vectors.
	 * This class contains all the common methods and operators all the other vectors contain.
	 *
	 * @tparam Type: Vector Type.
	 * @tparam ValueType: The primitive value type.
	 */
	template <class Type, class ValueType>
	class Vector
	{
	public:
		/**
		 * Dereference operator to return the primitive type data.
		 *
		 * @return The vector.
		 */
		Type& operator()() { return *static_cast<Type*>(this); }

		/**
		 * Dereference operator to return the primitive type data.
		 *
		 * @return The const vector.
		 */
		const Type& operator()() const { return *static_cast<const Type*>(this); }

		/**
		 * Increment operator.
		 *
		 * @param rhs: The other vector.
		 * @return The incremented vector.
		 */
		Type& operator+=(const Type& rhs)
		{
			(*this)() = (*this)() + rhs;
			return (*this)();
		}

		/**
		 * Increment operator.
		 *
		 * @param rhs: The other primitive vector data.
		 * @return The incremented vector.
		 */
		Type& operator+=(const ValueType& rhs)
		{
			(*this)() = (*this)() + Type(rhs);
			return (*this)();
		}

		/**
		 * Increment operator (by one).
		 *
		 * @param :
		 * @return The incremented vector.
		 */
		Type operator++(int)
		{
			Type tmp = (*this)();
			(*this) += ValueType(1);
			return tmp;
		}

		/**
		 * Increment operator (by one).
		 *
		 * @param :
		 * @return The incremented vector.
		 */
		Type& operator++()
		{
			(*this)() += ValueType(1);
			return (*this)();
		}

		/**
		 * The decrement operator.
		 *
		 * @param rhs: The other vector to be decremented by.
		 * @return The decremented vector.
		 */
		Type& operator-=(const Type& rhs)
		{
			(*this)() = (*this)() - rhs;
			return (*this)();
		}

		/**
		 * The decrement operator.
		 *
		 * @param rhs: The other vector to be decremented by.
		 * @return The decremented vector.
		 */
		Type& operator-=(const ValueType& rhs)
		{
			(*this)() = (*this)() - Type(rhs);
			return (*this)();
		}

		/**
		 * Decrement operator (by one).
		 *
		 * @param :
		 * @return The decremented vector.
		 */
		Type operator--(int)
		{
			Type tmp = (*this)();
			(*this) -= ValueType(1);
			return tmp;
		}

		/**
		 * Decrement operator (by one).
		 *
		 * @param :
		 * @return The decremented vector.
		 */
		Type& operator--()
		{
			(*this)() -= ValueType(1);
			return (*this)();
		}

		/**
		 * The multiplication operator.
		 *
		 * @param rhs: The other vector to be decremented by.
		 * @return The decremented vector.
		 */
		Type& operator*=(const Type& rhs)
		{
			(*this)() = (*this)() * rhs;
			return (*this)();
		}

		/**
		 * The multiplication operator.
		 *
		 * @param rhs: The other vector to be decremented by.
		 * @return The decremented vector.
		 */
		Type& operator*=(const ValueType& rhs)
		{
			(*this)() = (*this)() * Type(rhs);
			return (*this)();
		}

		/**
		 * The division operator.
		 *
		 * @param rhs: The other vector to be decremented by.
		 * @return The decremented vector.
		 */
		Type& operator/=(const Type& rhs)
		{
			(*this)() = (*this)() / rhs;
			return (*this)();
		}

		/**
		 * The division operator.
		 *
		 * @param rhs: The other vector to be decremented by.
		 * @return The decremented vector.
		 */
		Type& operator/=(const ValueType& rhs)
		{
			(*this)() = (*this)() / Type(rhs);
			return (*this)();
		}

		/**
		 * Return this vector.
		 *
		 * @param :
		 * @return This vector.
		 */
		Vector& operator=(const Vector&) { return *this; }

		/**
		 * Initialize the vector with 0.
		 */
		static Type Zero;
	};

	/**
	 * Addition operator of the vector.
	 *
	 * @tparam Type: The type of the vector.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The added vector.
	 */
	template <class Type, class ValueType>
	Vector<Type, ValueType> operator+(const Vector<Type, ValueType>& lhs, const ValueType& rhs)
	{
		return lhs() + Type(rhs);
	}

	/**
	 * Addition operator of the vector.
	 *
	 * @tparam Type: The type of the vector.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The added vector.
	 */
	template <class Type, class ValueType>
	Vector<Type, ValueType> operator+(const ValueType& lhs, const Vector<Type, ValueType>& rhs)
	{
		return Type(lhs) + rhs();
	}

	/**
	 * Subtract operator of the vector.
	 *
	 * @tparam Type: The type of the vector.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The subtracted vector.
	 */
	template <class Type, class ValueType>
	Vector<Type, ValueType> operator-(const Vector<Type, ValueType>& lhs, const ValueType& rhs)
	{
		return lhs() - Type(rhs);
	}

	/**
	 * Subtract operator of the vector.
	 *
	 * @tparam Type: The type of the vector.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The subtracted vector.
	 */
	template <class Type, class ValueType>
	Vector<Type, ValueType> operator-(const ValueType& lhs, const Vector<Type, ValueType>& rhs)
	{
		return Type(lhs) - rhs();
	}

	/**
	 * Multiply operator of the vector.
	 *
	 * @tparam Type: The type of the vector.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The multiplied vector.
	 */
	template <class Type, class ValueType>
	Vector<Type, ValueType> operator*(const Vector<Type, ValueType>& lhs, const ValueType& rhs)
	{
		return lhs() * Type(rhs);
	}

	/**
	 * Multiply operator of the vector.
	 *
	 * @tparam Type: The type of the vector.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The multiplied vector.
	 */
	template <class Type, class ValueType>
	Vector<Type, ValueType> operator*(const ValueType& lhs, const Vector<Type, ValueType>& rhs)
	{
		return Type(lhs) * rhs();
	}

	/**
	 * Divide operator of the vector.
	 *
	 * @tparam Type: The type of the vector.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The divided vector.
	 */
	template <class Type, class ValueType>
	Vector<Type, ValueType> operator/(const Vector<Type, ValueType>& lhs, const ValueType& rhs)
	{
		return lhs() / Type(rhs);
	}

	/**
	 * Divide operator of the vector.
	 *
	 * @tparam Type: The type of the vector.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The divided vector.
	 */
	template <class Type, class ValueType>
	Vector<Type, ValueType> operator/(const ValueType& lhs, const Vector<Type, ValueType>& rhs)
	{
		return Type(lhs) / rhs();
	}

	/**
	 * Zero all the values in the vector.
	 *
	 * @tparam Type: The type of the vector.
	 * @tparam ValueType: The primitive value type.
	 */
	template <class Type, class ValueType>
	Type Vector<Type, ValueType>::Zero = Type(0.0f);
}
