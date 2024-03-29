// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_AI_EIGENVALUES_MODULE_H
#define EIGEN_AI_EIGENVALUES_MODULE_H

#include "Core.h"

#include "src/Core/util/DisableStupidWarnings.h"

#include "Cholesky.h"
#include "Jacobi.h"
#include "Householder.h"
#include "LU.h"
#include "Geometry.h"

/** \defgroup Eigenvalues_Module Eigenvalues module
  *
  *
  *
  * This module mainly provides various eigenvalue solvers.
  * This module also provides some MatrixBase methods, including:
  *  - MatrixBase::eigenvalues(),
  *  - MatrixBase::operatorNorm()
  *
  * \code
  * #include <Eigen_ai/Eigenvalues.h>
  * \endcode
  */

#include "src/misc/RealSvd2x2.h"
#include "src/Eigenvalues/Tridiagonalization.h"
#include "src/Eigenvalues/RealSchur.h"
#include "src/Eigenvalues/EigenSolver.h"
#include "src/Eigenvalues/SelfAdjointEigenSolver.h"
#include "src/Eigenvalues/GeneralizedSelfAdjointEigenSolver.h"
#include "src/Eigenvalues/HessenbergDecomposition.h"
#include "src/Eigenvalues/ComplexSchur.h"
#include "src/Eigenvalues/ComplexEigenSolver.h"
#include "src/Eigenvalues/RealQZ.h"
#include "src/Eigenvalues/GeneralizedEigenSolver.h"
#include "src/Eigenvalues/MatrixBaseEigenvalues.h"
#ifdef EIGEN_AI_USE_LAPACKE
#include "src/misc/lapacke.h"
#include "src/Eigenvalues/RealSchur_LAPACKE.h"
#include "src/Eigenvalues/ComplexSchur_LAPACKE.h"
#include "src/Eigenvalues/SelfAdjointEigenSolver_LAPACKE.h"
#endif

#include "src/Core/util/ReenableStupidWarnings.h"

#endif // EIGEN_AI_EIGENVALUES_MODULE_H
/* vim: set filetype=cpp et sw=2 ts=2 ai: */
