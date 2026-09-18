// RUN: circt-opt %s | FileCheck %s

hw.module @weird(out out: i32) {
  %c1 = hw.constant 1 : i32
  %c2 = foo.bar : i32
  %wire_1 = hw.wire %c1 : i32
  %wire_2 = hw.wire %c2 : i32
  %sum = comb.add bin %wire_1, %wire_2 : i32
  %wire_sum = hw.wire %sum : i32
  hw.output %wire_sum : i32
}
