// RUN: not %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck -strict-whitespace %s

int x[sizeof int];
// CHECK: warning: null character ignored
// CHECK-NEXT: int x[sizeof<U+0000>int];
// CHECK-NEXT:             ^

// CHECK: error: expected parentheses around type name in sizeof expression
// CHECK-NEXT: int x[sizeof<U+0000>int];
// CHECK-NEXT:             ^
// CHECK-NEXT:             (          )
