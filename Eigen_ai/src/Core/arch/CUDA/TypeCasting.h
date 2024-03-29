// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// Copyright (C) 2016 Benoit Steiner <benoit.steiner.goog@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_AI_TYPE_CASTING_CUDA_H
#define EIGEN_AI_TYPE_CASTING_CUDA_H

namespace Eigen_ai {

namespace internal {

template<>
struct scalar_cast_op<float, Eigen_ai::half> {
  EIGEN_AI_EMPTY_STRUCT_CTOR(scalar_cast_op)
  typedef Eigen_ai::half result_type;
  EIGEN_AI_DEVICE_FUNC EIGEN_AI_STRONG_INLINE Eigen_ai::half operator() (const float& a) const {
    #if defined(EIGEN_AI_HAS_CUDA_FP16) && defined(__CUDA_ARCH__) && __CUDA_ARCH__ >= 300
      return __float2half(a);
    #else
      return Eigen_ai::half(a);
    #endif
  }
};

template<>
struct functor_traits<scalar_cast_op<float, Eigen_ai::half> >
{ enum { Cost = NumTraits<float>::AddCost, PacketAccess = false }; };


template<>
struct scalar_cast_op<int, Eigen_ai::half> {
  EIGEN_AI_EMPTY_STRUCT_CTOR(scalar_cast_op)
  typedef Eigen_ai::half result_type;
  EIGEN_AI_DEVICE_FUNC EIGEN_AI_STRONG_INLINE Eigen_ai::half operator() (const int& a) const {
    #if defined(EIGEN_AI_HAS_CUDA_FP16) && defined(__CUDA_ARCH__) && __CUDA_ARCH__ >= 300
      return __float2half(static_cast<float>(a));
    #else
      return Eigen_ai::half(static_cast<float>(a));
    #endif
  }
};

template<>
struct functor_traits<scalar_cast_op<int, Eigen_ai::half> >
{ enum { Cost = NumTraits<float>::AddCost, PacketAccess = false }; };


template<>
struct scalar_cast_op<Eigen_ai::half, float> {
  EIGEN_AI_EMPTY_STRUCT_CTOR(scalar_cast_op)
  typedef float result_type;
  EIGEN_AI_DEVICE_FUNC EIGEN_AI_STRONG_INLINE float operator() (const Eigen_ai::half& a) const {
    #if defined(EIGEN_AI_HAS_CUDA_FP16) && defined(__CUDA_ARCH__) && __CUDA_ARCH__ >= 300
      return __half2float(a);
    #else
      return static_cast<float>(a);
    #endif
  }
};

template<>
struct functor_traits<scalar_cast_op<Eigen_ai::half, float> >
{ enum { Cost = NumTraits<float>::AddCost, PacketAccess = false }; };



#if defined(EIGEN_AI_HAS_CUDA_FP16) && defined(__CUDA_ARCH__) && __CUDA_ARCH__ >= 300

template <>
struct type_casting_traits<Eigen_ai::half, float> {
  enum {
    VectorizedCast = 1,
    SrcCoeffRatio = 2,
    TgtCoeffRatio = 1
  };
};

template<> EIGEN_AI_DEVICE_FUNC EIGEN_AI_STRONG_INLINE float4 pcast<half2, float4>(const half2& a, const half2& b) {
  float2 r1 = __half22float2(a);
  float2 r2 = __half22float2(b);
  return make_float4(r1.x, r1.y, r2.x, r2.y);
}

template <>
struct type_casting_traits<float, Eigen_ai::half> {
  enum {
    VectorizedCast = 1,
    SrcCoeffRatio = 1,
    TgtCoeffRatio = 2
  };
};

template<> EIGEN_AI_DEVICE_FUNC EIGEN_AI_STRONG_INLINE half2 pcast<float4, half2>(const float4& a) {
  // Simply discard the second half of the input
  return __floats2half2_rn(a.x, a.y);
}

#elif defined EIGEN_AI_VECTORIZE_AVX512
template <>
struct type_casting_traits<half, float> {
  enum {
    VectorizedCast = 1,
    SrcCoeffRatio = 1,
    TgtCoeffRatio = 1
  };
};

template<> EIGEN_AI_STRONG_INLINE Packet16f pcast<Packet16h, Packet16f>(const Packet16h& a) {
  return half2float(a);
}

template <>
struct type_casting_traits<float, half> {
  enum {
    VectorizedCast = 1,
    SrcCoeffRatio = 1,
    TgtCoeffRatio = 1
  };
};

template<> EIGEN_AI_STRONG_INLINE Packet16h pcast<Packet16f, Packet16h>(const Packet16f& a) {
  return float2half(a);
}

#elif defined EIGEN_AI_VECTORIZE_AVX

template <>
struct type_casting_traits<Eigen_ai::half, float> {
  enum {
    VectorizedCast = 1,
    SrcCoeffRatio = 1,
    TgtCoeffRatio = 1
  };
};

template<> EIGEN_AI_STRONG_INLINE Packet8f pcast<Packet8h, Packet8f>(const Packet8h& a) {
  return half2float(a);
}

template <>
struct type_casting_traits<float, Eigen_ai::half> {
  enum {
    VectorizedCast = 1,
    SrcCoeffRatio = 1,
    TgtCoeffRatio = 1
  };
};

template<> EIGEN_AI_STRONG_INLINE Packet8h pcast<Packet8f, Packet8h>(const Packet8f& a) {
  return float2half(a);
}

// Disable the following code since it's broken on too many platforms / compilers.
//#elif defined(EIGEN_AI_VECTORIZE_SSE) && (!EIGEN_AI_ARCH_x86_64) && (!EIGEN_AI_COMP_MSVC)
#elif 0

template <>
struct type_casting_traits<Eigen_ai::half, float> {
  enum {
    VectorizedCast = 1,
    SrcCoeffRatio = 1,
    TgtCoeffRatio = 1
  };
};

template<> EIGEN_AI_STRONG_INLINE Packet4f pcast<Packet4h, Packet4f>(const Packet4h& a) {
  __int64_t a64 = _mm_cvtm64_si64(a.x);
  Eigen_ai::half h = raw_uint16_to_half(static_cast<unsigned short>(a64));
  float f1 = static_cast<float>(h);
  h = raw_uint16_to_half(static_cast<unsigned short>(a64 >> 16));
  float f2 = static_cast<float>(h);
  h = raw_uint16_to_half(static_cast<unsigned short>(a64 >> 32));
  float f3 = static_cast<float>(h);
  h = raw_uint16_to_half(static_cast<unsigned short>(a64 >> 48));
  float f4 = static_cast<float>(h);
  return _mm_set_ps(f4, f3, f2, f1);
}

template <>
struct type_casting_traits<float, Eigen_ai::half> {
  enum {
    VectorizedCast = 1,
    SrcCoeffRatio = 1,
    TgtCoeffRatio = 1
  };
};

template<> EIGEN_AI_STRONG_INLINE Packet4h pcast<Packet4f, Packet4h>(const Packet4f& a) {
  EIGEN_AI_ALIGN16 float aux[4];
  pstore(aux, a);
  Eigen_ai::half h0(aux[0]);
  Eigen_ai::half h1(aux[1]);
  Eigen_ai::half h2(aux[2]);
  Eigen_ai::half h3(aux[3]);

  Packet4h result;
  result.x = _mm_set_pi16(h3.x, h2.x, h1.x, h0.x);
  return result;
}

#endif

} // end namespace internal

} // end namespace Eigen_ai

#endif // EIGEN_AI_TYPE_CASTING_CUDA_H
