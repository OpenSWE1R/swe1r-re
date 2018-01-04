These code patterns appear regularily in the source code, so likely they were macros or inline functions at some point.

## Assertions

```C
#define ASSERT(condition, message, path, line) \
  if ( !(condition) ) { \
    dword_ECC420->unk6((message), (path), (line)); \
  }
```

## Endianess swap

```C
static inline uint16_t swap16(uint16_t v) {
  //FIXME
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

```C
// Returns the larger of 2 values
// `if ( v44 < 0 ) { v44 = 0; }`
// would become `v44 = max(v44, 0);`
static inline T max(T a, T b) {
  return (a < b) ? b : a;
}

// Returns the smaller of 2 values
// `if ( v44 > 255 ) { v44 = 255; }`
// would become `v44 = min(v44, 255);`
static inline T min(T a, T b) {
  return (a > b) ? b : a;
}

// Clamps a value in range [a, b]
// `if ( v44 < 0 ) { v44 = 0; }   if ( v44 > 255 ) { v44 = 255; }`
// would become `v44 = clamp(v44, 0, 255);`
static inline T clamp(T x, T a, T b) {
  return min(max(x, a), b);
}
```