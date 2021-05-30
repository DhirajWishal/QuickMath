// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include <cstdint>
#include <type_traits>

#ifdef __GNUC__
#    include <x86intrin.h>         // x86intrin.h 
#else
#    include <immintrin.h>         // MS version of immintrin.h covers AVX, AVX2 and FMA3
#endif // __GNUC__

namespace QuickMath
{
	/**
	 * Intrinsic traits struct.
	 * This struct contains the intrinsic type for a given type and layer count.
	 */
	template<class Primitive, int Layers>
	struct IntrinsicTraits {};

	/** Float Intrinsic Types */

	/**
	 * Intrinsic traits for float vector 2.
	 */
	template<>
	struct IntrinsicTraits<float, 2> { typedef __m64 Type; };

	/**
	 * Intrinsic traits for float vector 3.
	 */
	template<>
	struct IntrinsicTraits<float, 3> { typedef __m128 Type; };

	/**
	 * Intrinsic traits for float vector 4.
	 */
	template<>
	struct IntrinsicTraits<float, 4> { typedef __m128 Type; };

	/**
	 * Intrinsic traits for float vector 8.
	 */
	template<>
	struct IntrinsicTraits<float, 8> { typedef __m256 Type; };

	/** Int Intrinsic Types */

	/**
	 * Intrinsic traits for int vector 2.
	 */
	template<>
	struct IntrinsicTraits<int, 2> { typedef __m64 Type; };

	/**
	 * Intrinsic traits for int vector 3.
	 */
	template<>
	struct IntrinsicTraits<int, 3> { typedef __m128 Type; };

	/**
	 * Intrinsic traits for int vector 4.
	 */
	template<>
	struct IntrinsicTraits<int, 4> { typedef __m128 Type; };

	/**
	 * Intrinsic traits for int vector 8.
	 */
	template<>
	struct IntrinsicTraits<int, 8> { typedef __m256i Type; };

	/** Double Intrinsic Types */

	/**
	 * Intrinsic traits for double vector 2.
	 */
	template<>
	struct IntrinsicTraits<double, 2> { typedef __m128d Type; };

	/**
	 * Intrinsic traits for double vector 3.
	 */
	template<>
	struct IntrinsicTraits<double, 3> { typedef __m256d Type; };

	/**
	 * Intrinsic traits for double vector 4.
	 */
	template<>
	struct IntrinsicTraits<double, 4> { typedef __m256d Type; };

	/**
	 * Intrinsic traits for double vector 8.
	 */
	template<>
	struct IntrinsicTraits<double, 8> { typedef __m512d Type; };
}