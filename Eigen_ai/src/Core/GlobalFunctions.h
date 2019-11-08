// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// Copyright (C) 2010-2016 Gael Guennebaud <gael.guennebaud@inria.fr>
// Copyright (C) 2010 Benoit Jacob <jacob.benoit.1@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_AI_GLOBAL_FUNCTIONS_H
#define EIGEN_AI_GLOBAL_FUNCTIONS_H

#ifdef EIGEN_AI_PARSED_BY_DOXYGEN

#define EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(NAME,FUNCTOR,DOC_OP,DOC_DETAILS) \
  /** \returns an expression of the coefficient-wise DOC_OP of \a x

    DOC_DETAILS

    \sa <a href="group__CoeffwiseMathFunctions.html#cwisetable_##NAME">Math functions</a>, class CwiseUnaryOp
    */ \
  template<typename Derived> \
  inline const Eigen_ai::CwiseUnaryOp<Eigen_ai::internal::FUNCTOR<typename Derived::Scalar>, const Derived> \
  NAME(const Eigen_ai::ArrayBase<Derived>& x);

#else

#define EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(NAME,FUNCTOR,DOC_OP,DOC_DETAILS) \
  template<typename Derived> \
  inline const Eigen_ai::CwiseUnaryOp<Eigen_ai::internal::FUNCTOR<typename Derived::Scalar>, const Derived> \
  (NAME)(const Eigen_ai::ArrayBase<Derived>& x) { \
    return Eigen_ai::CwiseUnaryOp<Eigen_ai::internal::FUNCTOR<typename Derived::Scalar>, const Derived>(x.derived()); \
  }

#endif // EIGEN_AI_PARSED_BY_DOXYGEN

#define EIGEN_AI_ARRAY_DECLARE_GLOBAL_EIGEN_AI_UNARY(NAME,FUNCTOR) \
  \
  template<typename Derived> \
  struct NAME##_retval<ArrayBase<Derived> > \
  { \
    typedef const Eigen_ai::CwiseUnaryOp<Eigen_ai::internal::FUNCTOR<typename Derived::Scalar>, const Derived> type; \
  }; \
  template<typename Derived> \
  struct NAME##_impl<ArrayBase<Derived> > \
  { \
    static inline typename NAME##_retval<ArrayBase<Derived> >::type run(const Eigen_ai::ArrayBase<Derived>& x) \
    { \
      return typename NAME##_retval<ArrayBase<Derived> >::type(x.derived()); \
    } \
  };

namespace Eigen_ai
{
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(real,scalar_real_op,real part,\sa ArrayBase::real)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(imag,scalar_imag_op,imaginary part,\sa ArrayBase::imag)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(conj,scalar_conjugate_op,complex conjugate,\sa ArrayBase::conjugate)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(inverse,scalar_inverse_op,inverse,\sa ArrayBase::inverse)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(sin,scalar_sin_op,sine,\sa ArrayBase::sin)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(cos,scalar_cos_op,cosine,\sa ArrayBase::cos)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(tan,scalar_tan_op,tangent,\sa ArrayBase::tan)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(atan,scalar_atan_op,arc-tangent,\sa ArrayBase::atan)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(asin,scalar_asin_op,arc-sine,\sa ArrayBase::asin)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(acos,scalar_acos_op,arc-consine,\sa ArrayBase::acos)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(sinh,scalar_sinh_op,hyperbolic sine,\sa ArrayBase::sinh)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(cosh,scalar_cosh_op,hyperbolic cosine,\sa ArrayBase::cosh)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(tanh,scalar_tanh_op,hyperbolic tangent,\sa ArrayBase::tanh)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(lgamma,scalar_lgamma_op,natural logarithm of the gamma function,\sa ArrayBase::lgamma)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(digamma,scalar_digamma_op,derivative of lgamma,\sa ArrayBase::digamma)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(erf,scalar_erf_op,error function,\sa ArrayBase::erf)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(erfc,scalar_erfc_op,complement error function,\sa ArrayBase::erfc)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(exp,scalar_exp_op,exponential,\sa ArrayBase::exp)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(log,scalar_log_op,natural logarithm,\sa Eigen_ai::log10 DOXCOMMA ArrayBase::log)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(log1p,scalar_log1p_op,natural logarithm of 1 plus the value,\sa ArrayBase::log1p)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(log10,scalar_log10_op,base 10 logarithm,\sa Eigen_ai::log DOXCOMMA ArrayBase::log)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(abs,scalar_abs_op,absolute value,\sa ArrayBase::abs DOXCOMMA MatrixBase::cwiseAbs)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(abs2,scalar_abs2_op,squared absolute value,\sa ArrayBase::abs2 DOXCOMMA MatrixBase::cwiseAbs2)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(arg,scalar_arg_op,complex argument,\sa ArrayBase::arg)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(sqrt,scalar_sqrt_op,square root,\sa ArrayBase::sqrt DOXCOMMA MatrixBase::cwiseSqrt)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(rsqrt,scalar_rsqrt_op,reciprocal square root,\sa ArrayBase::rsqrt)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(square,scalar_square_op,square (power 2),\sa Eigen_ai::abs2 DOXCOMMA Eigen_ai::pow DOXCOMMA ArrayBase::square)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(cube,scalar_cube_op,cube (power 3),\sa Eigen_ai::pow DOXCOMMA ArrayBase::cube)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(round,scalar_round_op,nearest integer,\sa Eigen_ai::floor DOXCOMMA Eigen_ai::ceil DOXCOMMA ArrayBase::round)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(floor,scalar_floor_op,nearest integer not greater than the giben value,\sa Eigen_ai::ceil DOXCOMMA ArrayBase::floor)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(ceil,scalar_ceil_op,nearest integer not less than the giben value,\sa Eigen_ai::floor DOXCOMMA ArrayBase::ceil)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(isnan,scalar_isnan_op,not-a-number test,\sa Eigen_ai::isinf DOXCOMMA Eigen_ai::isfinite DOXCOMMA ArrayBase::isnan)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(isinf,scalar_isinf_op,infinite value test,\sa Eigen_ai::isnan DOXCOMMA Eigen_ai::isfinite DOXCOMMA ArrayBase::isinf)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(isfinite,scalar_isfinite_op,finite value test,\sa Eigen_ai::isinf DOXCOMMA Eigen_ai::isnan DOXCOMMA ArrayBase::isfinite)
  EIGEN_AI_ARRAY_DECLARE_GLOBAL_UNARY(sign,scalar_sign_op,sign (or 0),\sa ArrayBase::sign)
  
  /** \returns an expression of the coefficient-wise power of \a x to the given constant \a exponent.
    *
    * \tparam ScalarExponent is the scalar type of \a exponent. It must be compatible with the scalar type of the given expression (\c Derived::Scalar).
    *
    * \sa ArrayBase::pow()
    *
    * \relates ArrayBase
    */
#ifdef EIGEN_AI_PARSED_BY_DOXYGEN
  template<typename Derived,typename ScalarExponent>
  inline const CwiseBinaryOp<internal::scalar_pow_op<Derived::Scalar,ScalarExponent>,Derived,Constant<ScalarExponent> >
  pow(const Eigen_ai::ArrayBase<Derived>& x, const ScalarExponent& exponent);
#else
  template<typename Derived,typename ScalarExponent>
  inline typename internal::enable_if<   !(internal::is_same<typename Derived::Scalar,ScalarExponent>::value) && EIGEN_AI_SCALAR_BINARY_SUPPORTED(pow,typename Derived::Scalar,ScalarExponent),
          const EIGEN_AI_EXPR_BINARYOP_SCALAR_RETURN_TYPE(Derived,ScalarExponent,pow) >::type
  pow(const Eigen_ai::ArrayBase<Derived>& x, const ScalarExponent& exponent) {
    return x.derived().pow(exponent);
  }

  template<typename Derived>
  inline const EIGEN_AI_EXPR_BINARYOP_SCALAR_RETURN_TYPE(Derived,typename Derived::Scalar,pow)
  pow(const Eigen_ai::ArrayBase<Derived>& x, const typename Derived::Scalar& exponent) {
    return x.derived().pow(exponent);
  }
#endif

  /** \returns an expression of the coefficient-wise power of \a x to the given array of \a exponents.
    *
    * This function computes the coefficient-wise power.
    *
    * Example: \include Cwise_array_power_array.cpp
    * Output: \verbinclude Cwise_array_power_array.out
    * 
    * \sa ArrayBase::pow()
    *
    * \relates ArrayBase
    */
  template<typename Derived,typename ExponentDerived>
  inline const Eigen_ai::CwiseBinaryOp<Eigen_ai::internal::scalar_pow_op<typename Derived::Scalar, typename ExponentDerived::Scalar>, const Derived, const ExponentDerived>
  pow(const Eigen_ai::ArrayBase<Derived>& x, const Eigen_ai::ArrayBase<ExponentDerived>& exponents) 
  {
    return Eigen_ai::CwiseBinaryOp<Eigen_ai::internal::scalar_pow_op<typename Derived::Scalar, typename ExponentDerived::Scalar>, const Derived, const ExponentDerived>(
      x.derived(),
      exponents.derived()
    );
  }
  
  /** \returns an expression of the coefficient-wise power of the scalar \a x to the given array of \a exponents.
    *
    * This function computes the coefficient-wise power between a scalar and an array of exponents.
    *
    * \tparam Scalar is the scalar type of \a x. It must be compatible with the scalar type of the given array expression (\c Derived::Scalar).
    *
    * Example: \include Cwise_scalar_power_array.cpp
    * Output: \verbinclude Cwise_scalar_power_array.out
    * 
    * \sa ArrayBase::pow()
    *
    * \relates ArrayBase
    */
#ifdef EIGEN_AI_PARSED_BY_DOXYGEN
  template<typename Scalar,typename Derived>
  inline const CwiseBinaryOp<internal::scalar_pow_op<Scalar,Derived::Scalar>,Constant<Scalar>,Derived>
  pow(const Scalar& x,const Eigen_ai::ArrayBase<Derived>& x);
#else
  template<typename Scalar, typename Derived>
  inline typename internal::enable_if<   !(internal::is_same<typename Derived::Scalar,Scalar>::value) && EIGEN_AI_SCALAR_BINARY_SUPPORTED(pow,Scalar,typename Derived::Scalar),
          const EIGEN_AI_SCALAR_BINARYOP_EXPR_RETURN_TYPE(Scalar,Derived,pow) >::type
  pow(const Scalar& x, const Eigen_ai::ArrayBase<Derived>& exponents)
  {
    return EIGEN_AI_SCALAR_BINARYOP_EXPR_RETURN_TYPE(Scalar,Derived,pow)(
            typename internal::plain_constant_type<Derived,Scalar>::type(exponents.rows(), exponents.cols(), x), exponents.derived() );
  }

  template<typename Derived>
  inline const EIGEN_AI_SCALAR_BINARYOP_EXPR_RETURN_TYPE(typename Derived::Scalar,Derived,pow)
  pow(const typename Derived::Scalar& x, const Eigen_ai::ArrayBase<Derived>& exponents)
  {
    return EIGEN_AI_SCALAR_BINARYOP_EXPR_RETURN_TYPE(typename Derived::Scalar,Derived,pow)(
      typename internal::plain_constant_type<Derived,typename Derived::Scalar>::type(exponents.rows(), exponents.cols(), x), exponents.derived() );
  }
#endif


  namespace internal
  {
    EIGEN_AI_ARRAY_DECLARE_GLOBAL_EIGEN_AI_UNARY(real,scalar_real_op)
    EIGEN_AI_ARRAY_DECLARE_GLOBAL_EIGEN_AI_UNARY(imag,scalar_imag_op)
    EIGEN_AI_ARRAY_DECLARE_GLOBAL_EIGEN_AI_UNARY(abs2,scalar_abs2_op)
  }
}

// TODO: cleanly disable those functions that are not supported on Array (numext::real_ref, internal::random, internal::isApprox...)

#endif // EIGEN_AI_GLOBAL_FUNCTIONS_H
