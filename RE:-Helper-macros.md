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

// Returns a random float in range [lowest, highest]
// `(double)sub_4816B0() * 4.6566129e-10 * 64.0 - -64.0`
// would become `frand(64.0, 128.0)`
static inline float frand(float lowest, float highest) {
  return frand() * (highest - lowest) + lowest;
}
```