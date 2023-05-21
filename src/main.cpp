#include <cassert>
#include <cstdint>
#include <arm_neon.h>
#include <iostream>

template <typename T>
void init(T& a) {
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
    a[i] = i;
  }
}

template <typename T>
void assert_and_print(const T& b) {
  for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
    assert(b[i] == i);
    std::cout << "b[" << i << "] = " << (int)b[i] << std::endl;
  }
  std::cout << std::endl;
}

// (Uint8, 16)
void uint8x16_test() {
  std::cout << __func__ << std::endl;
  constexpr std::size_t kN = 16;

  uint8_t a[kN] = {};
  init(a);

  uint8x16_t va = vld1q_u8(a);

  uint8_t b[kN] = {};
  vst1q_u8(b, va);

  assert_and_print(b);
}

// (Uint8, 32)
void uint8x16x2_test() {
  std::cout << __func__ << std::endl;
  constexpr std::size_t kN = 32;

  uint8_t a[kN] = {};
  init(a);

  uint8x16x2_t va = vld2q_u8(a);

  uint8_t b[kN] = {};
  vst2q_u8(b, va);

  assert_and_print(b);
}

// (Uint32, 4)
void uint32x4_test() {
  std::cout << __func__ << std::endl;
  constexpr std::size_t kN = 4;

  uint32_t a[kN] = {};
  init(a);

  uint32x4_t va = vld1q_u32(a);

  uint32_t b[kN] = {};
  vst1q_u32(b, va);

  assert_and_print(b);
}

// (Uint32, 8)
void uint32x4x2_test() {
  std::cout << __func__ << std::endl;
  constexpr std::size_t kN = 8;

  uint32_t a[kN] = {};
  init(a);

  uint32x4x2_t va = vld2q_u32(a);

  uint32_t b[kN] = {};
  vst2q_u32(b, va);

  assert_and_print(b);
}

int main(int argc, char** argv) {
  uint8x16_test();
  uint8x16x2_test();
  uint32x4_test();
  uint32x4x2_test();
}
