#ifndef FOO_TD
#define FOO_TD

include "mlir/IR/OpBase.td"

def FooDialect : Dialect {
  let name = "foo";
  let cppNamespace = "::circt::foo";

  let summary = "Types and operations for the foo dialect";
  let description = [{
    This dialect defines the `foo` dialect, which is utterly useless.
  }];

  let extraClassDeclaration = [{
    /// Register all HW types.
    void registerTypes();
  }];
}

// Base class for the operation in this dialect.
class FooOp<string mnemonic, list<Trait> traits = []> :
    Op<FooDialect, mnemonic, traits>;

include "circt/Dialect/Foo/FooOps.td"

#endif // FOO_TD
