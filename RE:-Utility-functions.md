# Vector normalize

```C
//----- (00492440) --------------------------------------------------------
// a1 = 3 component vector
// Probably returns nothing, if it has to return something, it's the prior vector length [in 80 bit or maybe double precision]
void __cdecl sub_492440(float *a1) {
  float squared_length = a1[0] * a1[0] + a1[1] * a1[1] + a1[2] * a1[2];
  float length = sqrt(squared_length);
  if (length != 0.0) {
    a1[0] = a1[0] * (1.0 / length);
    a1[1] = a1[1] * (1.0 / length);
    a1[2] = a1[2] * (1.0 / length);
  }
}
```

# Collision checking

I have the theory that this is related to collision checking, but I did not verify this yet.

```C
int __cdecl sub_490550(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, float a9);
```

# ChangeAndClamp

This is used in the debug menu

## Integer

```C
//----- (00429D90) --------------------------------------------------------
// a1 = pointer to value to be modified
// a2 = factor a (from user input for example)
// a3 = factor b (constant scaling factor for example)
// a4 = min value
// a5 = max value
// Probably void, but would return a5 otherwise
void __cdecl sub_429D90(int* a1, float a2, float a3, int a4, int a5){
  *a1 = (int)(a3 * a2 + (float)a1);
  if (*a1 < a4) { *a1 = a4; }
  if (*a1 > a5) { *a1 = a5; }
}
```

## Float

```C
//----- (00429D50) --------------------------------------------------------
// a1 = pointer to value to be modified
// a2 = factor a (from user input for example)
// a3 = factor b (constant scaling factor for example)
// a4 = min value
// a5 = max value
void __cdecl sub_429D50(float* a1, float a2, float a3, float a4, float a5) {
  *a1 = a3 * a2 + *a1;
  if (*a1 < a4) { *a1 = a4; } //FIXME: This is different in the decompilation, but I assume the decompiler messed up
  if (*a1 > a5) { *a1 = a5; }
}
```

# Some matrix copy function

This has only one target matrix. It's used inline though, so probably not a matrix stack either.

```C
signed int __cdecl sub_4800C0(int a1)
{
  if ( dword_4C7BE4 < 0 )
    return 0;
  *(float *)a1 = *(float *)&dword_E25960;
  *(_DWORD *)(a1 + 4) = dword_E25964;
  *(_DWORD *)(a1 + 8) = dword_E25968;
  *(_DWORD *)(a1 + 12) = dword_E2596C;
  *(_DWORD *)(a1 + 16) = dword_E25970;
  *(_DWORD *)(a1 + 20) = dword_E25974;
  *(_DWORD *)(a1 + 24) = dword_E25978;
  *(_DWORD *)(a1 + 28) = dword_E2597C;
  *(_DWORD *)(a1 + 32) = dword_E25980;
  *(_DWORD *)(a1 + 36) = dword_E25984;
  *(_DWORD *)(a1 + 40) = dword_E25988;
  *(_DWORD *)(a1 + 44) = dword_E2598C;
  *(_DWORD *)(a1 + 48) = dword_E25990;
  *(_DWORD *)(a1 + 52) = dword_E25994;
  *(_DWORD *)(a1 + 56) = dword_E25998;
  *(_DWORD *)(a1 + 60) = dword_E2599C;
  return 1;
}
```

# Something math related

```
//----- (00480650) --------------------------------------------------------
double __cdecl sub_480650(float a1, float a2)
{
  return 1.0 - a2 * 33.333336 / (a2 * 33.333336 + a1);
}
```

# Square Root wrapper

```C
//----- (00480670) --------------------------------------------------------
double __cdecl sub_480670(float a1)
{
  return (float)sqrt(a1);
}
```

# Matrix functions

## D3DXVec3Transform

(I think this should be D3DXVec3Transform, except for the output value; not 100% sure though)

```C
//----- (00480690) --------------------------------------------------------
// a1 is a 4 component output
// a2 is a 3 component vector
// a3 is a 4x4 matrix
// Probably  void function, but if it returns something, then it's the input matrix. not the output vector(!)
void __cdecl sub_480690(float *a1, float *a2, float *a3) {
  a1[0] = a3[ 8] * a2[2] + a3[4] * a2[1] + a3[0] * a2[0] + a3[12];
  a1[1] = a3[ 9] * a2[2] + a3[5] * a2[1] + a3[1] * a2[0] + a3[13];
  a1[2] = a3[10] * a2[2] + a3[6] * a2[1] + a3[2] * a2[0] + a3[14];
  a1[3] = a3[11] * a2[2] + a3[7] * a2[1] + a3[3] * a2[0] + a3[15];
}
```

# Various transformation functions

```C
//----- (00492B70) --------------------------------------------------------
// a1 = output matrix [12 floats]
// a2 = input matrix [12 floats]
// a3 = input matrix [12 floats]
const float* __cdecl sub_492B70(float* a1, const float* a2, const float* a3) {

  a1[0] = a2[0] * a3[0] + a2[3] * a3[1] + a2[6] * a3[2];
  a1[1] = a2[1] * a3[0] + a2[4] * a3[1] + a2[7] * a3[2];
  a1[2] = a2[2] * a3[0] + a2[5] * a3[1] + a2[8] * a3[2];

  a1[3] = a2[0] * a3[3] + a2[3] * a3[4] + a2[6] * a3[5];
  a1[4] = a2[1] * a3[3] + a2[4] * a3[4] + a2[7] * a3[5];
  a1[5] = a2[2] * a3[3] + a2[5] * a3[4] + a2[8] * a3[5];

  a1[6] = a2[0] * a3[6] + a2[3] * a3[7] + a2[6] * a3[8];
  a1[7] = a2[1] * a3[6] + a2[4] * a3[7] + a2[7] * a3[8];
  a1[8] = a2[2] * a3[6] + a2[5] * a3[7] + a2[8] * a3[8];

  a1[ 9] = a2[0] * a3[9] + a2[3] * a3[10] + a2[6] * a3[11] + a2[ 9];
  a1[10] = a2[1] * a3[9] + a2[4] * a3[10] + a2[7] * a3[11] + a2[10];
  a1[11] = a2[2] * a3[9] + a2[5] * a3[10] + a2[8] * a3[11] + a2[11];

  return a2;
}
```

```C
//----- (00492D50) --------------------------------------------------------
// Transposed matrix multiplication, otherwise like sub_492F40
// a1 = input & output matrix [12 floats]
// a2 = input matrix [12 floats]
const float* __cdecl sub_492D50(float *a1, const float *a2) {
  float tmp[12];
  qmemcpy(tmp, a1, sizeof(tmp));

  a1[0] = a2[0] * tmp[0] + a2[1] * tmp[3] + a2[2] * tmp[6];
  a1[1] = a2[0] * tmp[1] + a2[1] * tmp[4] + a2[2] * tmp[7];
  a1[2] = a2[0] * tmp[2] + a2[1] * tmp[5] + a2[2] * tmp[8];

  a1[3] = a2[3] * tmp[0] + a2[4] * tmp[3] + a2[5] * tmp[6];
  a1[4] = a2[3] * tmp[1] + a2[4] * tmp[4] + a2[5] * tmp[7];
  a1[5] = a2[3] * tmp[2] + a2[4] * tmp[5] + a2[5] * tmp[8];

  a1[6] = a2[6] * tmp[0] + a2[7] * tmp[3] + a2[8] * tmp[6];
  a1[7] = a2[6] * tmp[1] + a2[7] * tmp[4] + a2[8] * tmp[7];
  a1[8] = a2[6] * tmp[2] + a2[7] * tmp[5] + a2[8] * tmp[8];

  a1[ 9] = a2[9] * tmp[0] + a2[10] * tmp[3] + a2[11] * tmp[6] + tmp[ 9];
  a1[10] = a2[9] * tmp[1] + a2[10] * tmp[4] + a2[11] * tmp[7] + tmp[10];
  a1[11] = a2[9] * tmp[2] + a2[10] * tmp[5] + a2[11] * tmp[8] + tmp[11];

  return a2;
}
```

```C
//----- (00492F40) --------------------------------------------------------
// a1 = input & output matrix [12 floats]
// a2 = input matrix [12 floats]
// (Same as sub_492B70(a1, a1, a2) if it allowed overlapping matrices)
const float* __cdecl sub_492F40(float* a1, const float* a2) {
  float tmp[12];
  qmemcpy(tmp, a1, sizeof(tmp));

  a1[0] = a2[0] * tmp[0] + a2[3] * tmp[1] + a2[6] * tmp[2];
  a1[1] = a2[1] * tmp[0] + a2[4] * tmp[1] + a2[7] * tmp[2];
  a1[2] = a2[2] * tmp[0] + a2[5] * tmp[1] + a2[8] * tmp[2];

  a1[3] = a2[0] * tmp[3] + a2[3] * tmp[4] + a2[6] * tmp[5];
  a1[4] = a2[1] * tmp[3] + a2[4] * tmp[4] + a2[7] * tmp[5];
  a1[5] = a2[2] * tmp[3] + a2[5] * tmp[4] + a2[8] * tmp[5];

  a1[6] = a2[0] * tmp[6] + a2[3] * tmp[7] + a2[6] * tmp[8];
  a1[7] = a2[1] * tmp[6] + a2[4] * tmp[7] + a2[7] * tmp[8];
  a1[8] = a2[2] * tmp[6] + a2[5] * tmp[7] + a2[8] * tmp[8];

  a1[ 9] = a2[0] * tmp[9] + a2[3] * tmp[10] + a2[6] * tmp[11] + a2[ 9];
  a1[10] = a2[1] * tmp[9] + a2[4] * tmp[10] + a2[7] * tmp[11] + a2[10];
  a1[11] = a2[2] * tmp[9] + a2[5] * tmp[10] + a2[8] * tmp[11] + a2[11];

  return a2;
}
```

```C
//----- (00493130) --------------------------------------------------------
// a1 = output matrix (12 floats)
// a2 = ?
float* __cdecl sub_493130(float* a1, float* a2) {
  float tmp[12];
  sub_492810(tmp, a2);
  return sub_492D50(a1, tmp);
}
```

```C
//----- (00493160) --------------------------------------------------------
// a1 = 12 component matrix
// a2 = 3 component vector
// Translates a matrix?
float* __cdecl sub_493160(float* a1, const float* a2) {
  a1[ 9] = a2[0] + a1[ 9];
  a1[10] = a2[1] + a1[10];
  a1[11] = a2[2] + a1[11];
  return a1;
}
```

```C
//----- (00493190) --------------------------------------------------------
const float* __cdecl sub_493190(float *a1, const float* a2, const float* a3) {
  a1[0] = a3[0] * a2[0] + a3[3] * a2[1] + a3[6] * a2[2];
  a1[1] = a3[1] * a2[0] + a3[4] * a2[1] + a3[7] * a2[2];
  a1[2] = a3[2] * a2[0] + a3[5] * a2[1] + a3[8] * a2[2];
  return a3;
}
```

```C
//----- (00493200) --------------------------------------------------------
const float* __cdecl sub_493200(float* a1, const float* a2, const float* a3) {
  a1[0] = a3[0] * a2[0] + a3[3] * a2[1] + a3[6] * a2[2] + a3[ 9];
  a1[1] = a3[1] * a2[0] + a3[4] * a2[1] + a3[7] * a2[2] + a3[10];
  a1[2] = a3[2] * a2[0] + a3[5] * a2[1] + a3[8] * a2[2] + a3[11];
  return a3;
}
```

```C
//----- (00493270) --------------------------------------------------------
// a1 = some 12 component matrix
// a2 = n x 3 component input vectors
// a3 = n x 3 component output vectors
// a4 = n [number of vectors to transform]
// Return value is kind of complicated. a1 if a4 is set, otherwise a4.
// Probably just returns void though.
void __cdecl sub_493270(const float *a1, const float *a2, float *a3, int a4) {
  for(int i = 0; i < a4; i++) {
    a3[0] = a1[0] * a2[0] + a1[3] * a2[1] + a1[6] * a2[2] + a1[ 9];
    a3[1] = a1[1] * a2[0] + a1[4] * a2[1] + a1[7] * a2[2] + a1[10];
    a3[2] = a1[2] * a2[0] + a1[5] * a2[1] + a1[8] * a2[2] + a1[11];

    a2 += 3;
    a3 += 3;
  }
}
```