// Copyright (c) 2021 Dhiraj Wishal

#pragma once

namespace QuickMath
{
	/**
	 * Matrix data type for QuickMath.
	 * This class contains all the common methods and operators all the other matrices contain.
	 *
	 * @tparam Type: Matrix type.
	 * @tparam ValueType: The primitive value type.
	 */
	template<class Type, class ValueType>
	class Matrix
	{
	public:
		/**
		 * Dereference operator to return the primitive type data.
		 *
		 * @return The matrix.
		 */
		Type& operator()() { return *static_cast<Type*>(this); }

		/**
		 * Dereference operator to return the primitive type data.
		 *
		 * @return The const matrix.
		 */
		const Type& operator()() const { return *static_cast<const Type*>(this); }

		/**
		 * Increment operator.
		 *
		 * @param rhs: The other matrix.
		 * @return The incremented matrix.
		 */
		Type& operator+=(const Type& rhs)
		{
			(*this)() = (*this)() + rhs;
			return (*this)();
		}

		/**
		 * The decrement operator.
		 *
		 * @param rhs: The other matrix to be decremented by.
		 * @return The decremented matrix.
		 */
		Type& operator-=(const Type& rhs)
		{
			(*this)() = (*this)() - rhs;
			return (*this)();
		}

		/**
		 * The multiplication operator.
		 *
		 * @param rhs: The other matrix to be decremented by.
		 * @return The decremented matrix.
		 */
		Type& operator*=(const Type& rhs)
		{
			(*this)() = (*this)() * rhs;
			return (*this)();
		}

		/**
		 * The multiplication operator.
		 *
		 * @param rhs: The other matrix to be decremented by.
		 * @return The decremented matrix.
		 */
		Type& operator*=(const ValueType& rhs)
		{
			(*this)() = (*this)() * Type(rhs);
			return (*this)();
		}

		/**
		 * The division operator.
		 *
		 * @param rhs: The other matrix to be decremented by.
		 * @return The decremented matrix.
		 */
		Type& operator/=(const Type& rhs)
		{
			(*this)() = (*this)() / rhs;
			return (*this)();
		}

		/**
		 * The division operator.
		 *
		 * @param rhs: The other matrix to be decremented by.
		 * @return The decremented matrix.
		 */
		Type& operator/=(const ValueType& rhs)
		{
			(*this)() = (*this)() / Type(rhs);
			return (*this)();
		}

		/**
		 * Return this matrix.
		 *
		 * @param :
		 * @return This matrix.
		 */
		Matrix& operator=(const  Matrix&) { return *this; }

		/**
		 * Initialize as an identity matrix.
		 */
		static Type Identity;
	};

	/**
	 * Addition operator of the matrix.
	 *
	 * @tparam Type: The type of the matrix.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The added matrix.
	 */
	template<class Type, class ValueType>
	Matrix<Type, ValueType> operator+(const Matrix<Type, ValueType>& lhs, const ValueType& rhs)
	{
		return lhs() + Type(rhs);
	}

	/**
	 * Addition operator of the matrix.
	 *
	 * @tparam Type: The type of the matrix.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The added matrix.
	 */
	template<class Type, class ValueType>
	Matrix<Type, ValueType> operator+(const ValueType& lhs, const Matrix<Type, ValueType>& rhs)
	{
		return Type(lhs) + rhs();
	}

	/**
	 * Subtract operator of the matrix.
	 *
	 * @tparam Type: The type of the matrix.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The subtracted matrix.
	 */
	template<class Type, class ValueType>
	Matrix<Type, ValueType> operator-(const Matrix<Type, ValueType>& lhs, const ValueType& rhs)
	{
		return lhs() - Type(rhs);
	}

	/**
	 * Subtract operator of the matrix.
	 *
	 * @tparam Type: The type of the matrix.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The subtracted matrix.
	 */
	template<class Type, class ValueType>
	Matrix<Type, ValueType> operator-(const ValueType& lhs, const Matrix<Type, ValueType>& rhs)
	{
		return Type(lhs) - rhs();
	}

	/**
	 * Multiply operator of the matrix.
	 *
	 * @tparam Type: The type of the matrix.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The multiplied matrix.
	 */
	template<class Type, class ValueType>
	Matrix<Type, ValueType> operator*(const Matrix<Type, ValueType>& lhs, const ValueType& rhs)
	{
		return lhs() * Type(rhs);
	}

	/**
	 * Multiply operator of the matrix.
	 *
	 * @tparam Type: The type of the matrix.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The multiplied matrix.
	 */
	template<class Type, class ValueType>
	Matrix<Type, ValueType> operator*(const ValueType& lhs, const Matrix<Type, ValueType>& rhs)
	{
		return Type(lhs) * rhs();
	}

	/**
	 * Divide operator of the matrix.
	 *
	 * @tparam Type: The type of the matrix.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The divided matrix.
	 */
	template<class Type, class ValueType>
	Matrix<Type, ValueType> operator/(const Matrix<Type, ValueType>& lhs, const ValueType& rhs)
	{
		return lhs() / Type(rhs);
	}

	/**
	 * Divide operator of the matrix.
	 *
	 * @tparam Type: The type of the matrix.
	 * @tparam ValueType: The primitive value type.
	 * @param lhs: LHS argument.
	 * @param rhs: RHS argument.
	 * @return The divided matrix.
	 */
	template<class Type, class ValueType>
	Matrix<Type, ValueType> operator/(const ValueType& lhs, const Matrix<Type, ValueType>& rhs)
	{
		return Type(lhs) / rhs();
	}

	/**
	 * Initialize the matrix as an identity matrix.
	 *
	 * @tparam Type: The type of the matrix.
	 * @tparam ValueType: The primitive value type.
	 */
	template<class Type, class ValueType>
	Type Matrix<Type, ValueType>::Identity = Type(1.0f);
}
