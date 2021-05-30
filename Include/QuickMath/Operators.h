// Copyright (c) 2021 Dhiraj Wishal

#pragma once

#include "IncludeSIMD.h"

namespace QuickMath
{
	namespace Operators
	{
		/** Additions */

		constexpr __m64 operator+(const __m64& a, const __m64& b)
		{
			__m64 result = {}; result.m64_i32[0] = a.m64_i32[0] + b.m64_i32[0], result.m64_i32[1] = a.m64_i32[1] + b.m64_i32[1]; return result;
		}

		constexpr __m128 operator+(const __m128& a, const __m128& b)
		{
			return _mm_add_ps(a, b);
		}

		constexpr __m128i operator+(const __m128i& a, const __m128i& b)
		{
			return _mm_add_epi32(a, b);
		}

		constexpr __m128d operator+(const __m128d& a, const __m128d& b)
		{
			return _mm_add_pd(a, b);
		}

		constexpr __m256 operator+(const __m256& a, const __m256& b)
		{
			return _mm256_add_ps(a, b);
		}

		constexpr __m256i operator+(const __m256i& a, const __m256i& b)
		{
			return _mm256_add_epi32(a, b);
		}

		constexpr __m256d operator+(const __m256d& a, const __m256d& b)
		{
			return _mm256_add_pd(a, b);
		}

		constexpr __m512d operator+(const __m512d& a, const __m512d& b)
		{
			return _mm512_add_pd(a, b);
		}

		/** Subtractions */

		constexpr __m64 operator-(const __m64& a, const __m64& b)
		{
			__m64 result = {}; result.m64_i32[0] = a.m64_i32[0] - b.m64_i32[0], result.m64_i32[1] = a.m64_i32[1] - b.m64_i32[1]; return result;
		}

		constexpr __m128 operator-(const __m128& a, const __m128& b)
		{
			return _mm_sub_ps(a, b);
		}

		constexpr __m128i operator-(const __m128i& a, const __m128i& b)
		{
			return _mm_sub_epi32(a, b);
		}

		constexpr __m128d operator-(const __m128d& a, const __m128d& b)
		{
			return _mm_sub_pd(a, b);
		}

		constexpr __m256 operator-(const __m256& a, const __m256& b)
		{
			return _mm256_sub_ps(a, b);
		}

		constexpr __m256i operator-(const __m256i& a, const __m256i& b)
		{
			return _mm256_sub_epi32(a, b);
		}

		constexpr __m256d operator-(const __m256d& a, const __m256d& b)
		{
			return _mm256_sub_pd(a, b);
		}

		constexpr __m512d operator-(const __m512d& a, const __m512d& b)
		{
			return _mm512_sub_pd(a, b);
		}

		/** Multiplications */

		constexpr __m64 operator*(const __m64& a, const __m64& b)
		{
			__m64 result = {}; result.m64_i32[0] = a.m64_i32[0] * b.m64_i32[0], result.m64_i32[1] = a.m64_i32[1] * b.m64_i32[1]; return result;
		}

		constexpr __m128 operator*(const __m128& a, const __m128& b)
		{
			return _mm_mul_ps(a, b);
		}

		constexpr __m128i operator*(const __m128i& a, const __m128i& b)
		{
			return _mm_mul_epu32(a, b);
		}

		constexpr __m128d operator*(const __m128d& a, const __m128d& b)
		{
			return _mm_mul_pd(a, b);
		}

		constexpr __m256 operator*(const __m256& a, const __m256& b)
		{
			return _mm256_mul_ps(a, b);
		}

		constexpr __m256i operator*(const __m256i& a, const __m256i& b)
		{
			return _mm256_mul_epu32(a, b);
		}

		constexpr __m256d operator*(const __m256d& a, const __m256d& b)
		{
			return _mm256_mul_pd(a, b);
		}

		constexpr __m512d operator*(const __m512d& a, const __m512d& b)
		{
			return _mm512_mul_pd(a, b);
		}

		/** Division */

		constexpr __m64 operator/(const __m64& a, const __m64& b)
		{
			__m64 result = {}; result.m64_i32[0] = a.m64_i32[0] / b.m64_i32[0], result.m64_i32[1] = a.m64_i32[1] / b.m64_i32[1]; return result;
		}

		constexpr __m128 operator/(const __m128& a, const __m128& b)
		{
			return _mm_div_ps(a, b);
		}

		constexpr __m128i operator/(const __m128i& a, const __m128i& b)
		{
			return _mm_div_epi32(a, b);
		}

		constexpr __m128d operator/(const __m128d& a, const __m128d& b)
		{
			return _mm_div_pd(a, b);
		}

		constexpr __m256 operator/(const __m256& a, const __m256& b)
		{
			return _mm256_div_ps(a, b);
		}

		constexpr __m256i operator/(const __m256i& a, const __m256i& b)
		{
			return _mm256_div_epi32(a, b);
		}

		constexpr __m256d operator/(const __m256d& a, const __m256d& b)
		{
			return _mm256_div_pd(a, b);
		}

		constexpr __m512d operator/(const __m512d& a, const __m512d& b)
		{
			return _mm512_div_pd(a, b);
		}

		/** Is Equal */

		constexpr __m64 operator==(const __m64& a, const __m64& b)
		{
			__m64 result = {};
			result.m64_i32[0] = a.m64_i32[0] == b.m64_i32[0];
			result.m64_i32[1] = a.m64_i32[1] == b.m64_i32[1];
			return result;
		}

		constexpr __m128 operator==(const __m128& a, const __m128& b)
		{
			return _mm_cmpeq_ps(a, b);
		}

		constexpr __m128i operator==(const __m128i& a, const __m128i& b)
		{
			return _mm_cmpeq_epi32(a, b);
		}

		constexpr __m128d operator==(const __m128d& a, const __m128d& b)
		{
			return _mm_cmpeq_pd(a, b);
		}

		constexpr __m256 operator==(const __m256& a, const __m256& b)
		{
			return _mm256_castsi256_ps(_mm256_cmpeq_epi32(_mm256_castps_si256(a), _mm256_castps_si256(b)));
		}

		constexpr __m256i operator==(const __m256i& a, const __m256i& b)
		{
			return _mm256_cmpeq_epi32(a, b);
		}

		constexpr __m256d operator==(const __m256d& a, const __m256d& b)
		{
			return _mm256_castsi256_pd(_mm256_cmpeq_epi64(_mm256_castpd_si256(a), _mm256_castpd_si256(b)));
		}

		constexpr __m512d operator==(const __m512d& a, const __m512d& b)
		{
			__m512d result = {};
			result.m512d_f64[0] = a.m512d_f64[0] == b.m512d_f64[0];
			result.m512d_f64[1] = a.m512d_f64[1] == b.m512d_f64[1];
			result.m512d_f64[2] = a.m512d_f64[2] == b.m512d_f64[2];
			result.m512d_f64[3] = a.m512d_f64[3] == b.m512d_f64[3];
			result.m512d_f64[4] = a.m512d_f64[4] == b.m512d_f64[4];
			result.m512d_f64[5] = a.m512d_f64[5] == b.m512d_f64[5];
			result.m512d_f64[6] = a.m512d_f64[6] == b.m512d_f64[6];
			result.m512d_f64[7] = a.m512d_f64[7] == b.m512d_f64[7];

			return result;
		}

		/** Is Not Equal */

		constexpr __m64 operator!=(const __m64& a, const __m64& b)
		{
			__m64 result = {};
			result.m64_i32[0] = a.m64_i32[0] != b.m64_i32[0];
			result.m64_i32[1] = a.m64_i32[1] != b.m64_i32[1];

			return result;
		}

		constexpr __m128 operator!=(const __m128& a, const __m128& b)
		{
			return _mm_cmpneq_ps(a, b);
		}

		constexpr __m128i operator!=(const __m128i& a, const __m128i& b)
		{
			return _mm_castps_si128(_mm_cmpneq_ps(_mm_castsi128_ps(a), _mm_castsi128_ps(b)));
		}

		constexpr __m128d operator!=(const __m128d& a, const __m128d& b)
		{
			return _mm_cmpneq_pd(a, b);
		}

		constexpr __m256 operator!=(const __m256& a, const __m256& b)
		{
			return _mm256_castsi256_ps(_mm256_cmpeq_epi64(_mm256_castps_si256(a), _mm256_castps_si256(b)));
		}

		constexpr __m256i operator!=(const __m256i& a, const __m256i& b)
		{
			return _mm256_cmpeq_epi64(a, b);
		}

		constexpr __m256d operator!=(const __m256d& a, const __m256d& b)
		{
			return _mm256_castsi256_pd(_mm256_cmpeq_epi64(_mm256_castpd_si256(a), _mm256_castpd_si256(b)));
		}

		constexpr __m512d operator!=(const __m512d& a, const __m512d& b)
		{
			__m512d result = {};
			result.m512d_f64[0] = a.m512d_f64[0] != b.m512d_f64[0];
			result.m512d_f64[1] = a.m512d_f64[1] != b.m512d_f64[1];
			result.m512d_f64[2] = a.m512d_f64[2] != b.m512d_f64[2];
			result.m512d_f64[3] = a.m512d_f64[3] != b.m512d_f64[3];
			result.m512d_f64[4] = a.m512d_f64[4] != b.m512d_f64[4];
			result.m512d_f64[5] = a.m512d_f64[5] != b.m512d_f64[5];
			result.m512d_f64[6] = a.m512d_f64[6] != b.m512d_f64[6];
			result.m512d_f64[7] = a.m512d_f64[7] != b.m512d_f64[7];

			return result;
		}

		/** Grater Than */

		constexpr __m64 operator>(const __m64& a, const __m64& b)
		{
			__m64 result = {};
			result.m64_i32[0] = a.m64_i32[0] > b.m64_i32[0];
			result.m64_i32[1] = a.m64_i32[1] > b.m64_i32[1];

			return result;
		}

		constexpr __m128 operator>(const __m128& a, const __m128& b)
		{
			return _mm_cmpgt_ps(a, b);
		}

		constexpr __m128i operator>(const __m128i& a, const __m128i& b)
		{
			return _mm_cmpgt_epi32(a, b);
		}

		constexpr __m128d operator>(const __m128d& a, const __m128d& b)
		{
			return _mm_cmpgt_pd(a, b);
		}

		constexpr __m256 operator>(const __m256& a, const __m256& b)
		{
			return _mm256_castsi256_ps(_mm256_cmpgt_epi64(_mm256_castps_si256(a), _mm256_castps_si256(b)));
		}

		constexpr __m256i operator>(const __m256i& a, const __m256i& b)
		{
			return _mm256_cmpgt_epi32(a, b);
		}

		constexpr __m256d operator>(const __m256d& a, const __m256d& b)
		{
			return _mm256_castsi256_pd(_mm256_cmpgt_epi64(_mm256_castpd_si256(a), _mm256_castpd_si256(b)));
		}

		constexpr __m512d operator>(const __m512d& a, const __m512d& b)
		{
			__m512d result = {};
			result.m512d_f64[0] = a.m512d_f64[0] > b.m512d_f64[0];
			result.m512d_f64[1] = a.m512d_f64[1] > b.m512d_f64[1];
			result.m512d_f64[2] = a.m512d_f64[2] > b.m512d_f64[2];
			result.m512d_f64[3] = a.m512d_f64[3] > b.m512d_f64[3];
			result.m512d_f64[4] = a.m512d_f64[4] > b.m512d_f64[4];
			result.m512d_f64[5] = a.m512d_f64[5] > b.m512d_f64[5];
			result.m512d_f64[6] = a.m512d_f64[6] > b.m512d_f64[6];
			result.m512d_f64[7] = a.m512d_f64[7] > b.m512d_f64[7];

			return result;
		}

		/** Grater Than Or Equal*/

		constexpr __m64 operator>=(const __m64& a, const __m64& b)
		{
			__m64 result = {};
			result.m64_i32[0] = a.m64_i32[0] >= b.m64_i32[0];
			result.m64_i32[1] = a.m64_i32[1] >= b.m64_i32[1];

			return result;
		}

		constexpr __m128 operator>=(const __m128& a, const __m128& b)
		{
			return _mm_cmpge_ps(a, b);
		}

		constexpr __m128i operator>=(const __m128i& a, const __m128i& b)
		{
			return _mm_castps_si128(_mm_cmpge_ps(_mm_castsi128_ps(a), _mm_castsi128_ps(b)));
		}

		constexpr __m128d operator>=(const __m128d& a, const __m128d& b)
		{
			return _mm_cmpge_pd(a, b);
		}

		constexpr __m256 operator>=(const __m256& a, const __m256& b)
		{
			return _mm256_castsi256_ps(_mm256_cmpgt_epi64(_mm256_castps_si256(a), _mm256_castps_si256(b)));
		}

		constexpr __m256i operator>=(const __m256i& a, const __m256i& b)
		{
			return _mm256_set1_epi8(_mm256_cmpge_epi32_mask(a, b));
		}

		constexpr __m256d operator>=(const __m256d& a, const __m256d& b)
		{
			return _mm256_set1_pd(_mm256_cmpge_epi64_mask(_mm256_castpd_si256(a), _mm256_castpd_si256(b)));
		}

		constexpr __m512d operator>=(const __m512d& a, const __m512d& b)
		{
			__m512d result = {};
			result.m512d_f64[0] = a.m512d_f64[0] >= b.m512d_f64[0];
			result.m512d_f64[1] = a.m512d_f64[1] >= b.m512d_f64[1];
			result.m512d_f64[2] = a.m512d_f64[2] >= b.m512d_f64[2];
			result.m512d_f64[3] = a.m512d_f64[3] >= b.m512d_f64[3];
			result.m512d_f64[4] = a.m512d_f64[4] >= b.m512d_f64[4];
			result.m512d_f64[5] = a.m512d_f64[5] >= b.m512d_f64[5];
			result.m512d_f64[6] = a.m512d_f64[6] >= b.m512d_f64[6];
			result.m512d_f64[7] = a.m512d_f64[7] >= b.m512d_f64[7];

			return result;
		}

		/** Less Than */

		constexpr __m64 operator<(const __m64& a, const __m64& b)
		{
			__m64 result = {};
			result.m64_i32[0] = a.m64_i32[0] < b.m64_i32[0];
			result.m64_i32[1] = a.m64_i32[1] < b.m64_i32[1];

			return result;
		}

		constexpr __m128 operator<(const __m128& a, const __m128& b)
		{
			return _mm_cmplt_ps(a, b);
		}

		constexpr __m128i operator<(const __m128i& a, const __m128i& b)
		{
			return _mm_cmplt_epi32(a, b);
		}

		constexpr __m128d operator<(const __m128d& a, const __m128d& b)
		{
			return _mm_cmplt_pd(a, b);
		}

		constexpr __m256 operator<(const __m256& a, const __m256& b)
		{
			__m256 result = {};
			result.m256_f32[0] = a.m256_f32[0] < b.m256_f32[0];
			result.m256_f32[1] = a.m256_f32[1] < b.m256_f32[1];
			result.m256_f32[2] = a.m256_f32[2] < b.m256_f32[2];
			result.m256_f32[3] = a.m256_f32[3] < b.m256_f32[3];
			result.m256_f32[4] = a.m256_f32[4] < b.m256_f32[4];
			result.m256_f32[5] = a.m256_f32[5] < b.m256_f32[5];
			result.m256_f32[6] = a.m256_f32[6] < b.m256_f32[6];
			result.m256_f32[7] = a.m256_f32[7] < b.m256_f32[7];

			return result;
		}

		constexpr __m256i operator<(const __m256i& a, const __m256i& b)
		{
			__m256i result = {};
			result.m256i_i32[0] = a.m256i_i32[0] < b.m256i_i32[0];
			result.m256i_i32[1] = a.m256i_i32[1] < b.m256i_i32[1];
			result.m256i_i32[2] = a.m256i_i32[2] < b.m256i_i32[2];
			result.m256i_i32[3] = a.m256i_i32[3] < b.m256i_i32[3];
			result.m256i_i32[4] = a.m256i_i32[4] < b.m256i_i32[4];
			result.m256i_i32[5] = a.m256i_i32[5] < b.m256i_i32[5];
			result.m256i_i32[6] = a.m256i_i32[6] < b.m256i_i32[6];
			result.m256i_i32[7] = a.m256i_i32[7] < b.m256i_i32[7];

			return result;
		}

		constexpr __m256d operator<(const __m256d& a, const __m256d& b)
		{
			__m256d result = {};
			result.m256d_f64[0] = a.m256d_f64[0] < b.m256d_f64[0];
			result.m256d_f64[1] = a.m256d_f64[1] < b.m256d_f64[1];
			result.m256d_f64[2] = a.m256d_f64[2] < b.m256d_f64[2];
			result.m256d_f64[3] = a.m256d_f64[3] < b.m256d_f64[3];
			result.m256d_f64[4] = a.m256d_f64[4] < b.m256d_f64[4];
			result.m256d_f64[5] = a.m256d_f64[5] < b.m256d_f64[5];
			result.m256d_f64[6] = a.m256d_f64[6] < b.m256d_f64[6];
			result.m256d_f64[7] = a.m256d_f64[7] < b.m256d_f64[7];

			return result;
		}

		constexpr __m512d operator<(const __m512d& a, const __m512d& b)
		{
			__m512d result = {};
			result.m512d_f64[0] = a.m512d_f64[0] < b.m512d_f64[0];
			result.m512d_f64[1] = a.m512d_f64[1] < b.m512d_f64[1];
			result.m512d_f64[2] = a.m512d_f64[2] < b.m512d_f64[2];
			result.m512d_f64[3] = a.m512d_f64[3] < b.m512d_f64[3];
			result.m512d_f64[4] = a.m512d_f64[4] < b.m512d_f64[4];
			result.m512d_f64[5] = a.m512d_f64[5] < b.m512d_f64[5];
			result.m512d_f64[6] = a.m512d_f64[6] < b.m512d_f64[6];
			result.m512d_f64[7] = a.m512d_f64[7] < b.m512d_f64[7];

			return result;
		}

		/** Less Than Or Equal */

		constexpr __m64 operator<=(const __m64& a, const __m64& b)
		{
			__m64 result = {};
			result.m64_i32[0] = a.m64_i32[0] <= b.m64_i32[0];
			result.m64_i32[1] = a.m64_i32[1] <= b.m64_i32[1];

			return result;
		}

		constexpr __m128 operator<=(const __m128& a, const __m128& b)
		{
			return _mm_cmple_ps(a, b);
		}

		constexpr __m128i operator<=(const __m128i& a, const __m128i& b)
		{
			return _mm_castps_si128(_mm_cmple_ps(_mm_castsi128_ps(a), _mm_castsi128_ps(b)));
		}

		constexpr __m128d operator<=(const __m128d& a, const __m128d& b)
		{
			return _mm_cmple_pd(a, b);
		}

		constexpr __m256 operator<=(const __m256& a, const __m256& b)
		{
			__m256 result = {};
			result.m256_f32[0] = a.m256_f32[0] <= b.m256_f32[0];
			result.m256_f32[1] = a.m256_f32[1] <= b.m256_f32[1];
			result.m256_f32[2] = a.m256_f32[2] <= b.m256_f32[2];
			result.m256_f32[3] = a.m256_f32[3] <= b.m256_f32[3];
			result.m256_f32[4] = a.m256_f32[4] <= b.m256_f32[4];
			result.m256_f32[5] = a.m256_f32[5] <= b.m256_f32[5];
			result.m256_f32[6] = a.m256_f32[6] <= b.m256_f32[6];
			result.m256_f32[7] = a.m256_f32[7] <= b.m256_f32[7];

			return result;
		}

		constexpr __m256i operator<=(const __m256i& a, const __m256i& b)
		{
			__m256i result = {};
			result.m256i_i32[0] = a.m256i_i32[0] <= b.m256i_i32[0];
			result.m256i_i32[1] = a.m256i_i32[1] <= b.m256i_i32[1];
			result.m256i_i32[2] = a.m256i_i32[2] <= b.m256i_i32[2];
			result.m256i_i32[3] = a.m256i_i32[3] <= b.m256i_i32[3];
			result.m256i_i32[4] = a.m256i_i32[4] <= b.m256i_i32[4];
			result.m256i_i32[5] = a.m256i_i32[5] <= b.m256i_i32[5];
			result.m256i_i32[6] = a.m256i_i32[6] <= b.m256i_i32[6];
			result.m256i_i32[7] = a.m256i_i32[7] <= b.m256i_i32[7];

			return result;
		}

		constexpr __m256d operator<=(const __m256d& a, const __m256d& b)
		{
			__m256d result = {};
			result.m256d_f64[0] = a.m256d_f64[0] <= b.m256d_f64[0];
			result.m256d_f64[1] = a.m256d_f64[1] <= b.m256d_f64[1];
			result.m256d_f64[2] = a.m256d_f64[2] <= b.m256d_f64[2];
			result.m256d_f64[3] = a.m256d_f64[3] <= b.m256d_f64[3];
			result.m256d_f64[4] = a.m256d_f64[4] <= b.m256d_f64[4];
			result.m256d_f64[5] = a.m256d_f64[5] <= b.m256d_f64[5];
			result.m256d_f64[6] = a.m256d_f64[6] <= b.m256d_f64[6];
			result.m256d_f64[7] = a.m256d_f64[7] <= b.m256d_f64[7];

			return result;
		}

		constexpr __m512d operator<=(const __m512d& a, const __m512d& b)
		{
			__m512d result = {};
			result.m512d_f64[0] = a.m512d_f64[0] <= b.m512d_f64[0];
			result.m512d_f64[1] = a.m512d_f64[1] <= b.m512d_f64[1];
			result.m512d_f64[2] = a.m512d_f64[2] <= b.m512d_f64[2];
			result.m512d_f64[3] = a.m512d_f64[3] <= b.m512d_f64[3];
			result.m512d_f64[4] = a.m512d_f64[4] <= b.m512d_f64[4];
			result.m512d_f64[5] = a.m512d_f64[5] <= b.m512d_f64[5];
			result.m512d_f64[6] = a.m512d_f64[6] <= b.m512d_f64[6];
			result.m512d_f64[7] = a.m512d_f64[7] <= b.m512d_f64[7];

			return result;
		}

		/** Logical AND */

		constexpr __m64 operator&&(const __m64& a, const __m64& b)
		{
			__m64 result = {};
			result.m64_i32[0] = a.m64_i32[0] && b.m64_i32[0];
			result.m64_i32[1] = a.m64_i32[1] && b.m64_i32[1];

			return result;
		}

		constexpr __m128 operator&&(const __m128& a, const __m128& b)
		{
			return _mm_and_ps(a, b);
		}

		constexpr __m128i operator&&(const __m128i& a, const __m128i& b)
		{
			return _mm_and_si128(a, b);
		}

		constexpr __m128d operator&&(const __m128d& a, const __m128d& b) { return _mm_and_pd(a, b); }

		constexpr __m256 operator&&(const __m256& a, const __m256& b)
		{
			return _mm256_and_ps(a, b);
		}

		constexpr __m256i operator&&(const __m256i& a, const __m256i& b)
		{
			return _mm256_and_si256(a, b);
		}

		constexpr __m256d operator&&(const __m256d& a, const __m256d& b)
		{
			return _mm256_and_pd(a, b);
		}

		constexpr __m512d operator&&(const __m512d& a, const __m512d& b)
		{
			return _mm512_and_pd(a, b);
		}


		/** Logical OR */

		constexpr __m64 operator||(const __m64& a, const __m64& b)
		{
			__m64 result = {};
			result.m64_i32[0] = a.m64_i32[0] || b.m64_i32[0];
			result.m64_i32[1] = a.m64_i32[1] || b.m64_i32[1];

			return result;
		}

		constexpr __m128 operator||(const __m128& a, const __m128& b)
		{
			return _mm_or_ps(a, b);
		}

		constexpr __m128i operator||(const __m128i& a, const __m128i& b)
		{
			return _mm_or_si128(a, b);
		}

		constexpr __m128d operator||(const __m128d& a, const __m128d& b)
		{
			return _mm_or_pd(a, b);
		}

		constexpr __m256 operator||(const __m256& a, const __m256& b)
		{
			return _mm256_or_ps(a, b);
		}

		constexpr __m256i operator||(const __m256i& a, const __m256i& b)
		{
			return _mm256_or_si256(a, b);
		}

		constexpr __m256d operator||(const __m256d& a, const __m256d& b)
		{
			return _mm256_or_pd(a, b);
		}

		constexpr __m512d operator||(const __m512d& a, const __m512d& b)
		{
			return _mm512_or_pd(a, b);
		}


		/** Logical XOR */

		constexpr __m64 operator^(const __m64& a, const __m64& b)
		{
			__m64 result = {};
			result.m64_i32[0] = a.m64_i32[0] ^ b.m64_i32[0];
			result.m64_i32[1] = a.m64_i32[1] ^ b.m64_i32[1];

			return result;
		}

		constexpr __m128 operator^(const __m128& a, const __m128& b)
		{
			return _mm_xor_ps(a, b);
		}

		constexpr __m128i operator^(const __m128i& a, const __m128i& b)
		{
			return _mm_xor_si128(a, b);
		}

		constexpr __m128d operator^(const __m128d& a, const __m128d& b)
		{
			return _mm_xor_pd(a, b);
		}

		constexpr __m256 operator^(const __m256& a, const __m256& b)
		{
			return _mm256_xor_ps(a, b);
		}

		constexpr __m256i operator^(const __m256i& a, const __m256i& b)
		{
			return _mm256_xor_si256(a, b);
		}

		constexpr __m256d operator^(const __m256d& a, const __m256d& b)
		{
			return _mm256_xor_pd(a, b);
		}

		constexpr __m512d operator^(const __m512d& a, const __m512d& b)
		{
			return _mm512_xor_pd(a, b);
		}

		/** NOT */

		constexpr __m64 operator!(const __m64& a)
		{
			__m64 result = {};
			result.m64_f32[0] = !a.m64_f32[0];
			result.m64_f32[1] = !a.m64_f32[1];

			return result;
		}

		constexpr __m128 operator!(const __m128& a)
		{
			return _mm_andnot_ps(a, _mm_set1_ps(1.0f));
		}

		constexpr __m128i operator!(const __m128i& a)
		{
			return _mm_andnot_si128(a, _mm_set1_epi32(1));
		}

		constexpr __m128d operator!(const __m128d& a)
		{
			return _mm_andnot_pd(a, _mm_set1_pd(1.0));
		}

		constexpr __m256 operator!(const __m256& a)
		{
			return _mm256_andnot_ps(a, _mm256_set1_ps(1.0f));
		}

		constexpr __m256i operator!(const __m256i& a)
		{
			return _mm256_andnot_si256(a, _mm256_set1_epi32(1));
		}

		constexpr __m256d operator!(const __m256d& a)
		{
			return _mm256_andnot_pd(a, _mm256_set1_pd(1.0));
		}

		constexpr __m512d operator!(const __m512d& a)
		{
			return _mm512_andnot_pd(a, _mm512_set1_pd(1.0));
		}
	}
}
