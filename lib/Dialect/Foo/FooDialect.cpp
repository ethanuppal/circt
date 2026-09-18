//===- FooDialect.cpp - Implement the Foo dialect ---------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the Foo dialect.
//
//===----------------------------------------------------------------------===//

#include "circt/Dialect/Foo/FooDialect.h"
#include "circt/Dialect/Foo/FooOps.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/DialectImplementation.h"

using namespace circt;
using namespace circt::foo;

//===----------------------------------------------------------------------===//
// Dialect specification.
//===----------------------------------------------------------------------===//

#include "circt/Dialect/Foo/FooDialect.cpp.inc"

namespace {

// We implement the OpAsmDialectInterface so that Foo dialect operations
// automatically interpret the name attribute on operations as their SSA name.
struct FooOpAsmDialectInterface : public OpAsmDialectInterface {
  using OpAsmDialectInterface::OpAsmDialectInterface;

  /// Get a special name to use when printing the given operation. See
  /// OpAsmInterface.td#getAsmResultNames for usage details and documentation.
  void getAsmResultNames(Operation *op, OpAsmSetValueNameFn setNameFn) const {}
};

} // end anonymous namespace

void FooDialect::initialize() {
  // Register operations.
  addOperations<
#define GET_OP_LIST
#include "circt/Dialect/Foo/Foo.cpp.inc"
      >();

  // Register interface implementations.
  addInterfaces<FooOpAsmDialectInterface>();
}


