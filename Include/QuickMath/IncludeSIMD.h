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
	struct IntrinsicTraits<float, 2>
	{
		typedef __m64 Type;

		static float& At(Type& storage, unsigned int index) { return storage.m64_f32[index]; }
		static const float At(const Type& storage, unsigned int index) { return storage.m64_f32[index]; }
	};

	/**
	 * Intrinsic traits for float vector 3.
	 */
	template<>
	struct IntrinsicTraits<float, 3>
	{
		typedef __m128 Type;

		static float& At(Type& storage, unsigned int index) { return storage.m128_f32[index]; }
		static const float At( const Type& storage, unsigned int index) { return storage.m128_f32[index]; }
	};

	/**
	 * Intrinsic traits for float vector 4.
	 */
	template<>
	struct IntrinsicTraits<float, 4>
	{
		typedef __m128 Type;

		static float& At(Type& storage, unsigned int index) { return storage.m128_f32[index]; }
		static const float At(const Type& storage, unsigned int index) { return storage.m128_f32[index]; }
	};

	/**
	 * Intrinsic traits for float vector 8.
	 */
	template<>
	struct IntrinsicTraits<float, 8>
	{
		typedef __m256 Type;

		static float& At(Type& storage, unsigned int index) { return storage.m256_f32[index]; }
		static const float At(const Type& storage, unsigned int index) { return storage.m256_f32[index]; }
	};

	/** Int Intrinsic Types */

	/**
	 * Intrinsic traits for int vector 2.
	 */
	template<>
	struct IntrinsicTraits<int, 2>
	{
		typedef __m64 Type;

		static int& At(Type& storage, unsigned int index) { return storage.m64_i32[index]; }
		static const int At(const Type& storage, unsigned int index) { return storage.m64_i32[index]; }
	};

	/**
	 * Intrinsic traits for int vector 3.
	 */
	template<>
	struct IntrinsicTraits<int, 3>
	{
		typedef __m128i Type;

		static int& At(Type& storage, unsigned int index) { return storage.m128i_i32[index]; }
		static const int At(const Type& storage, unsigned int index) { return storage.m128i_i32[index]; }
	};

	/**
	 * Intrinsic traits for int vector 4.
	 */
	template<>
	struct IntrinsicTraits<int, 4>
	{
		typedef __m128i Type;

		static int& At(Type& storage, unsigned int index) { return storage.m128i_i32[index]; }
		static const int At(const Type& storage, unsigned int index) { return storage.m128i_i32[index]; }
	};

	/**
	 * Intrinsic traits for int vector 8.
	 */
	template<>
	struct IntrinsicTraits<int, 8>
	{
		typedef __m256i Type;

		static int& At(Type& storage, unsigned int index) { return storage.m256i_i32[index]; }
		static const int At(const Type& storage, unsigned int index) { return storage.m256i_i32[index]; }
	};

	/** Double Intrinsic Types */

	/**
	 * Intrinsic traits for double vector 2.
	 */
	template<>
	struct IntrinsicTraits<double, 2>
	{
		typedef __m128d Type;

		static double& At(Type& storage, unsigned int index) { return storage.m128d_f64[index]; }
		static const double At(const Type& storage, unsigned int index) { return storage.m128d_f64[index]; }
	};

	/**
	 * Intrinsic traits for double vector 3.
	 */
	template<>
	struct IntrinsicTraits<double, 3>
	{
		typedef __m256d Type;

		static double& At(Type& storage, unsigned int index) { return storage.m256d_f64[index]; }
		static const double At(const Type& storage, unsigned int index) { return storage.m256d_f64[index]; }
	};

	/**
	 * Intrinsic traits for double vector 4.
	 */
	template<>
	struct IntrinsicTraits<double, 4>
	{
		typedef __m256d Type;

		static double& At(Type& storage, unsigned int index) { return storage.m256d_f64[index]; }
		static const double At(const Type& storage, unsigned int index) { return storage.m256d_f64[index]; }
	};

	/**
	 * Intrinsic traits for double vector 8.
	 */
	template<>
	struct IntrinsicTraits<double, 8>
	{
		typedef __m512d Type;

		static double& At(Type& storage, unsigned int index) { return storage.m512d_f64[index]; }
		static const double At(const Type& storage, unsigned int index) { return storage.m512d_f64[index]; }
	};
}