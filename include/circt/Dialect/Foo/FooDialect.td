#ifndef CIRCT_DIALECT_FOO_FOODIALECT_TD
#define CIRCT_DIALECT_FOO_FOODIALECT_TD

include "circt/Dialect/HW/HWTypes.td"
include "mlir/IR/OpBase.td"

def FooDialect : Dialect {
  let name = "foo";
  let cppNamespace = "::circt::foo";

  let summary = "Types and operations for the foo dialect";
  let description = [{
    This dialect defines the `foo` dialect, which is utterly useless.
  }];

}


// Base class for the operation in this dialect.
class FooOp<string mnemonic, list<Trait> traits = []> :
    Op<FooDialect, mnemonic, traits>;

class BarOp: FooOp<"bar", []> {
  //let arguments = (ins);
  //let results = (outs HWIntegerType:$result);
  let arguments = (ins APIntAttr:$value);
  let results = (outs HWIntegerType:$result);
  let hasCustomAssemblyFormat = 1;

  let builders = [
    /// Build a ConstantOp from an APInt, infering the result type from the
    /// width of the APInt.
    OpBuilder<(ins "const APInt &":$value)>,

    /// This builder allows construction of small signed integers like 0, 1, -1
    /// matching a specified MLIR IntegerType.  This shouldn't be used for
    /// general constant folding because it only works with values that can be
    /// expressed in an int64_t.  Use APInt's instead.
    OpBuilder<(ins "Type":$type, "int64_t":$value)>,

    /// Build a ConstantOp from a prebuilt attribute.
    OpBuilder<(ins "IntegerAttr":$value)>
  ];
}


#endif
