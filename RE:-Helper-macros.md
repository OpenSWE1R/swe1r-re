These code patterns appear regularily in the source code, so likely they were macros or inline functions at some point.

## Magic values

The game uses 4 byte magic values / tags for various things.
This can be used to generate them.

```C
#define MAGIC(a1, a2, a3, a4) (((a1) << 24) | ((a2) << 16) | ((a3) << 8) | (a4))
```

## Assertions

Assertions in the original code already have a path and line hardcoded, they also have a condition which is checked and a message (which should reflect the condition directly by having it as a string)

```C
#define ASSERT(condition, message, path, line) \
  if ( !(condition) ) { \
    dword_ECC420->unk6((message), (path), (line)); \
  }
```

## Endianess swap

```C
static inline uint16_t swap16(uint16_t v) {
  return (v >> 8) | (v << 8);
}

static inline uint32_t swap32(uint32_t v) {
  return ((v & 0xFF0000 | (v >> 16)) >> 8) | (((v << 16) | v & 0xFF00) << 8);
}
```

## Random numbers

```C
// Returns a random float in range [0.0, 1.0]
// `(double)sub_4816B0() * 4.6566129e-10 * 64.0 - -64.0`
// would become `frand() * 64.0 + 64.0`
static inline float frand() {
  return (float)sub_4816B0() / (float)0x7FFFFFFF;
}

// Returns a random float in range [a, b]
// `(double)sub_4816B0() * 4.6566129e-10 * 64.0 - -64.0`
// would become `frand(64.0, 128.0)`
static inline float frand(float a, float b) {
  return frand() * (b - a) + a;
}
```

## Number clamping

These are similar to the `std::min` and `std::max` functions, but we declare our own because we can't know for certain that the target platform has a proper C++ lib.
We can also ensure proper float behaviour if need be.

```C++
// Returns the larger of 2 values
// `if ( v44 < 0 ) { v44 = 0; }`
// would become `v44 = max(v44, 0);`
template<typename _T>
static inline _T max(_T a, _T b) {
  return (a < b) ? b : a;
}

// Returns the smaller of 2 values
// `if ( v44 > 255 ) { v44 = 255; }`
// would become `v44 = min(v44, 255);`
template<typename _T>
static inline _T min(_T a, _T b) {
  return (a > b) ? b : a;
}

// Clamps a value in range [a, b]
// `if ( v44 < 0 ) { v44 = 0; }   if ( v44 > 255 ) { v44 = 255; }`
// would become `v44 = clamp(v44, 0, 255);`
template<typename _T>
static inline _T clamp(_T x, _T a, _T b) {
  return min(max(x, a), b);
}
```

## Fast inverse

```C
// Thanks to MerryMage for identifiying this function.
// Also see http://bits.stephan-brumme.com/inverse.html
static inline float fast_inverse(float a) {
  uint32_t x = 0x7F000000 - *(uint32_t*)&a;
  return *(float*)&x;
}

// Thanks to wwylele for identifiying this function.
// Also see https://en.wikipedia.org/wiki/Newton%27s_method#Multiplicative_inverses_of_numbers_and_power_series
static inline float inverse(float a) {
  float x_0 = fast_inverse(a);
  return x_0 * (2.0f - a * x_0);
}
```

## Native float rounding

```C
static inline float frndint(float x) {
  //FIXME: This should instead use the x86 FPU `frndint` instruction.
  //       The current implementation is *wrong*.
  //       Consider this a stub
  return roundf(x);
}
```

## Alignment

```C
static inline uintptr_t align_up(uintptr_t address, uintptr_t alignment) {
  // Slightly modified to allow non-POT alignments
  // Originally implemented as `return (address + (alignment - 1)) & ~(alignment - 1);`
  return address + (alignment - address) % alignment;
}
```