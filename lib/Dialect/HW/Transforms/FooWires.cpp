#include "circt/Dialect/HW/HWOps.h"
#include "circt/Dialect/HW/HWPasses.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"
#include "llvm/ADT/TypeSwitch.h"

namespace circt {
namespace hw {
#define GEN_PASS_DEF_FOOWIRES
#include "circt/Dialect/HW/Passes.h.inc"
} // namespace hw
} // namespace circt

using namespace circt;
using namespace hw;

namespace {
struct FooWiresPass : public circt::hw::impl::FooWiresBase<FooWiresPass> {
  void runOnOperation() override;
};
} // namespace

void FooWiresPass::runOnOperation() {
  size_t nWires = 0; // Counts the number of wires modified
  getOperation().walk(
      [&](hw::WireOp wire) { // Walk over every wire in the module
        wire.setName("foo_" + std::to_string(nWires++)); // Rename said wire
      });
}
