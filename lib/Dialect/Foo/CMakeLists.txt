add_circt_dialect_library(CIRCTFoo
  FooDialect.cpp
  FooOps.cpp

  LINK_COMPONENTS
  Core
  Support

  LINK_LIBS PUBLIC
  CIRCTSupport
  CIRCTComb
  CIRCTSV
  CIRCTHW
  CIRCTFSM
  MLIRArithDialect
  MLIRIR
  MLIRMemRefDialect
  MLIRTransforms
  )

# add_subdirectory(Export)
# add_subdirectory(Transforms)
