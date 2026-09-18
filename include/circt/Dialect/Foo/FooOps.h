//===- CombOps.h - Declare Comb dialect operations --------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the operation classes for the Comb dialect.
//
//===----------------------------------------------------------------------===//

#ifndef CIRCT_DIALECT_FOO_FOOOPS_H
#define CIRCT_DIALECT_FOO_FOOOPS_H

#include "circt/Dialect/Comb/CombDialect.h"
#include "circt/Dialect/HW/HWOps.h"
#include "circt/Dialect/HW/HWTypes.h"
#include "circt/Support/LLVM.h"
#include "mlir/Bytecode/BytecodeOpInterface.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/Matchers.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/Interfaces/FunctionInterfaces.h"
#include "mlir/Interfaces/InferIntRangeInterface.h"
#include "mlir/Interfaces/InferTypeOpInterface.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"
#include "mlir/Transforms/DialectConversion.h"


#define GET_OP_CLASSES
#include "circt/Dialect/Foo/Foo.h.inc"

namespace circt {
namespace foo {



} // namespace foo
} // namespace circt

#endif // CIRCT_DIALECT_FOO_FOOOPS_H
