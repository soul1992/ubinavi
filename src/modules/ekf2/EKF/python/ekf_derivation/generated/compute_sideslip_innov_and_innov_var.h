// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: compute_sideslip_innov_and_innov_var
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix24_24
 *     R: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     innov: Scalar
 *     innov_var: Scalar
 */
template <typename Scalar>
void ComputeSideslipInnovAndInnovVar(const matrix::Matrix<Scalar, 24, 1>& state,
                                     const matrix::Matrix<Scalar, 24, 24>& P, const Scalar R,
                                     const Scalar epsilon, Scalar* const innov = nullptr,
                                     Scalar* const innov_var = nullptr) {
  // Total ops: 269

  // Input arrays

  // Intermediate terms (39)
  const Scalar _tmp0 = 1 - 2 * std::pow(state(3, 0), Scalar(2));
  const Scalar _tmp1 = _tmp0 - 2 * std::pow(state(2, 0), Scalar(2));
  const Scalar _tmp2 = -state(22, 0) + state(4, 0);
  const Scalar _tmp3 = 2 * state(3, 0);
  const Scalar _tmp4 = _tmp3 * state(0, 0);
  const Scalar _tmp5 = 2 * state(1, 0);
  const Scalar _tmp6 = _tmp5 * state(2, 0);
  const Scalar _tmp7 = _tmp4 + _tmp6;
  const Scalar _tmp8 = -state(23, 0) + state(5, 0);
  const Scalar _tmp9 = 2 * state(2, 0);
  const Scalar _tmp10 = _tmp3 * state(1, 0) - _tmp9 * state(0, 0);
  const Scalar _tmp11 = _tmp1 * _tmp2 + _tmp10 * state(6, 0) + _tmp7 * _tmp8;
  const Scalar _tmp12 =
      _tmp11 + epsilon * (2 * math::min<Scalar>(0, (((_tmp11) > 0) - ((_tmp11) < 0))) + 1);
  const Scalar _tmp13 = Scalar(1.0) / (_tmp12);
  const Scalar _tmp14 = _tmp0 - 2 * std::pow(state(1, 0), Scalar(2));
  const Scalar _tmp15 = -_tmp4 + _tmp6;
  const Scalar _tmp16 = _tmp3 * state(2, 0) + _tmp5 * state(0, 0);
  const Scalar _tmp17 = _tmp14 * _tmp8 + _tmp15 * _tmp2 + _tmp16 * state(6, 0);
  const Scalar _tmp18 = _tmp17 / std::pow(_tmp12, Scalar(2));
  const Scalar _tmp19 = _tmp1 * _tmp18;
  const Scalar _tmp20 = _tmp13 * _tmp15;
  const Scalar _tmp21 = -_tmp19 + _tmp20;
  const Scalar _tmp22 = _tmp3 * state(6, 0);
  const Scalar _tmp23 = 4 * _tmp8;
  const Scalar _tmp24 = 2 * state(0, 0);
  const Scalar _tmp25 = _tmp24 * state(6, 0);
  const Scalar _tmp26 =
      _tmp13 * (_tmp2 * _tmp9 - _tmp23 * state(1, 0) + _tmp25) - _tmp18 * (_tmp22 + _tmp8 * _tmp9);
  const Scalar _tmp27 = -_tmp10 * _tmp18 + _tmp13 * _tmp16;
  const Scalar _tmp28 = 4 * _tmp2;
  const Scalar _tmp29 =
      _tmp13 * (_tmp2 * _tmp5 + _tmp22) - _tmp18 * (-_tmp25 - _tmp28 * state(2, 0) + _tmp5 * _tmp8);
  const Scalar _tmp30 = _tmp9 * state(6, 0);
  const Scalar _tmp31 = _tmp5 * state(6, 0);
  const Scalar _tmp32 = _tmp13 * (-_tmp2 * _tmp3 + _tmp31) - _tmp18 * (_tmp3 * _tmp8 - _tmp30);
  const Scalar _tmp33 = _tmp19 - _tmp20;
  const Scalar _tmp34 = _tmp18 * _tmp7;
  const Scalar _tmp35 = _tmp13 * _tmp14;
  const Scalar _tmp36 = -_tmp34 + _tmp35;
  const Scalar _tmp37 = _tmp34 - _tmp35;
  const Scalar _tmp38 = _tmp13 * (-_tmp2 * _tmp24 - _tmp23 * state(3, 0) + _tmp30) -
                        _tmp18 * (_tmp24 * _tmp8 - _tmp28 * state(3, 0) + _tmp31);

  // Output terms (2)
  if (innov != nullptr) {
    Scalar& _innov = (*innov);

    _innov = _tmp13 * _tmp17;
  }

  if (innov_var != nullptr) {
    Scalar& _innov_var = (*innov_var);

    _innov_var = R +
                 _tmp21 * (P(0, 4) * _tmp32 + P(1, 4) * _tmp26 + P(2, 4) * _tmp29 +
                           P(22, 4) * _tmp33 + P(23, 4) * _tmp37 + P(3, 4) * _tmp38 +
                           P(4, 4) * _tmp21 + P(5, 4) * _tmp36 + P(6, 4) * _tmp27) +
                 _tmp26 * (P(0, 1) * _tmp32 + P(1, 1) * _tmp26 + P(2, 1) * _tmp29 +
                           P(22, 1) * _tmp33 + P(23, 1) * _tmp37 + P(3, 1) * _tmp38 +
                           P(4, 1) * _tmp21 + P(5, 1) * _tmp36 + P(6, 1) * _tmp27) +
                 _tmp27 * (P(0, 6) * _tmp32 + P(1, 6) * _tmp26 + P(2, 6) * _tmp29 +
                           P(22, 6) * _tmp33 + P(23, 6) * _tmp37 + P(3, 6) * _tmp38 +
                           P(4, 6) * _tmp21 + P(5, 6) * _tmp36 + P(6, 6) * _tmp27) +
                 _tmp29 * (P(0, 2) * _tmp32 + P(1, 2) * _tmp26 + P(2, 2) * _tmp29 +
                           P(22, 2) * _tmp33 + P(23, 2) * _tmp37 + P(3, 2) * _tmp38 +
                           P(4, 2) * _tmp21 + P(5, 2) * _tmp36 + P(6, 2) * _tmp27) +
                 _tmp32 * (P(0, 0) * _tmp32 + P(1, 0) * _tmp26 + P(2, 0) * _tmp29 +
                           P(22, 0) * _tmp33 + P(23, 0) * _tmp37 + P(3, 0) * _tmp38 +
                           P(4, 0) * _tmp21 + P(5, 0) * _tmp36 + P(6, 0) * _tmp27) +
                 _tmp33 * (P(0, 22) * _tmp32 + P(1, 22) * _tmp26 + P(2, 22) * _tmp29 +
                           P(22, 22) * _tmp33 + P(23, 22) * _tmp37 + P(3, 22) * _tmp38 +
                           P(4, 22) * _tmp21 + P(5, 22) * _tmp36 + P(6, 22) * _tmp27) +
                 _tmp36 * (P(0, 5) * _tmp32 + P(1, 5) * _tmp26 + P(2, 5) * _tmp29 +
                           P(22, 5) * _tmp33 + P(23, 5) * _tmp37 + P(3, 5) * _tmp38 +
                           P(4, 5) * _tmp21 + P(5, 5) * _tmp36 + P(6, 5) * _tmp27) +
                 _tmp37 * (P(0, 23) * _tmp32 + P(1, 23) * _tmp26 + P(2, 23) * _tmp29 +
                           P(22, 23) * _tmp33 + P(23, 23) * _tmp37 + P(3, 23) * _tmp38 +
                           P(4, 23) * _tmp21 + P(5, 23) * _tmp36 + P(6, 23) * _tmp27) +
                 _tmp38 * (P(0, 3) * _tmp32 + P(1, 3) * _tmp26 + P(2, 3) * _tmp29 +
                           P(22, 3) * _tmp33 + P(23, 3) * _tmp37 + P(3, 3) * _tmp38 +
                           P(4, 3) * _tmp21 + P(5, 3) * _tmp36 + P(6, 3) * _tmp27);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym