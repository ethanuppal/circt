#ifndef CIRCT_DIALECT_FOO_TD
#define CIRCT_DIALECT_FOO_TD

include "circt/Dialect/Comb/CombDialect.td"
include "circt/Dialect/HW/HWTypes.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/Interfaces/InferIntRangeInterface.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/IR/EnumAttr.td"

class BarOp<string mnemonic> :
      FooOp<mnemonic, []> {
  let arguments = (ins);
  let results = (outs HWIntegerType:$result);

  let assemblyFormat = "functional-type($args, $results)";
}

#endif // CIRCT_DIALECT_FOO_TD
