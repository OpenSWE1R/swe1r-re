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
float *__cdecl sub_492B70(float* a1, const float* a2, const float* a3) {

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
float *__cdecl sub_492D50(float *a1, float *a2)
{
  float *result; // eax
  double v3; // st7
  double v4; // st6
  double v5; // st3
  double v6; // st7
  double v7; // rt1
  double v8; // st3
  double v9; // st6
  float v10; // [esp+8h] [ebp-30h]
  float v11; // [esp+Ch] [ebp-2Ch]
  float v12; // [esp+10h] [ebp-28h]
  float v13; // [esp+14h] [ebp-24h]
  float v14; // [esp+18h] [ebp-20h]
  float v15; // [esp+1Ch] [ebp-1Ch]
  float v16; // [esp+20h] [ebp-18h]
  float v17; // [esp+24h] [ebp-14h]
  float v18; // [esp+28h] [ebp-10h]
  float v19; // [esp+2Ch] [ebp-Ch]
  float v20; // [esp+30h] [ebp-8h]
  float v21; // [esp+34h] [ebp-4h]

  result = a2;
  v3 = a2[1];
  v4 = a2[2];
  qmemcpy(&v10, a1, 0x30u);
  v5 = v3;
  v6 = v12;
  v7 = v5 * v13;
  v8 = v4 * v16;
  v9 = v11;
  *a1 = v7 + v8 + v10 * *a2;
  a1[1] = result[1] * v14 + result[2] * v17 + v9 * *result;
  a1[2] = result[1] * v15 + result[2] * v18 + v6 * *result;
  a1[3] = result[4] * v13 + result[3] * v10 + result[5] * v16;
  a1[4] = result[4] * v14 + result[3] * v11 + result[5] * v17;
  a1[5] = result[4] * v15 + result[3] * v12 + result[5] * v18;
  a1[6] = result[8] * v16 + result[7] * v13 + result[6] * v10;
  a1[7] = result[8] * v17 + result[7] * v14 + result[6] * v11;
  a1[8] = result[8] * v18 + result[7] * v15 + result[6] * v12;
  a1[9] = result[11] * v16 + result[10] * v13 + result[9] * v10 + v19;
  a1[10] = result[11] * v17 + result[10] * v14 + result[9] * v11 + v20;
  a1[11] = result[11] * v18 + result[10] * v15 + result[9] * v12 + v21;
  return result;
}
```

```C
//----- (00492F40) --------------------------------------------------------
// a1 = input & output matrix [12 floats]
// a2 = input matrix [12 floats]
// (Same as sub_492B70(a1, a1, a2) if it allowed overlapping matrices)
float *__cdecl sub_492F40(float* a1, const float* a2) {
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
float *__cdecl sub_493130(float *a1, float *a2)
{
  char v3; // [esp+0h] [ebp-30h]

  sub_492810((float *)&v3, a2);
  return sub_492D50(a1, (float *)&v3);
}

//----- (00493160) --------------------------------------------------------
int __cdecl sub_493160(int a1, float *a2)
{
  int result; // eax

  result = a1;
  *(float *)(a1 + 36) = *a2 + *(float *)(a1 + 36);
  *(float *)(result + 40) = a2[1] + *(float *)(result + 40);
  *(float *)(a1 + 44) = a2[2] + *(float *)(a1 + 44);
  return result;
}

//----- (00493190) --------------------------------------------------------
float *__cdecl sub_493190(float *a1, float *a2, float *a3)
{
  float *result; // eax

  result = a3;
  *a1 = a3[6] * a2[2] + a3[3] * a2[1] + *a2 * *a3;
  a1[1] = result[4] * a2[1] + result[7] * a2[2] + result[1] * *a2;
  a1[2] = a3[5] * a2[1] + a3[8] * a2[2] + a3[2] * *a2;
  return result;
}

//----- (00493200) --------------------------------------------------------
float *__cdecl sub_493200(float *a1, float *a2, float *a3)
{
  float *result; // eax

  result = a3;
  *a1 = a3[3] * a2[1] + a3[6] * a2[2] + *a2 * *a3 + a3[9];
  a1[1] = result[4] * a2[1] + result[7] * a2[2] + result[1] * *a2 + result[10];
  a1[2] = result[5] * a2[1] + a3[8] * a2[2] + a3[2] * *a2 + result[11];
  return result;
}

//----- (00493270) --------------------------------------------------------
float *__cdecl sub_493270(float *a1, float *a2, float *a3, float *a4)
{
  float *result; // eax
  float *v5; // edx
  float *v6; // esi
  float *v7; // ecx
  double v8; // st7
  double v9; // st5
  double v10; // st6

  result = a4;
  if ( a4 )
  {
    result = a1;
    v5 = a3;
    v6 = a4;
    v7 = a2;
    do
    {
      v8 = a1[3] * v7[1];
      v9 = a1[6] * v7[2];
      v10 = *v7;
      v7 += 3;
      *v5 = v8 + v9 + v10 * *a1 + a1[9];
      v5[1] = a1[1] * *(v7 - 3) + a1[4] * *(v7 - 2) + a1[7] * *(v7 - 1) + a1[10];
      v5[2] = a1[2] * *(v7 - 3) + a1[5] * *(v7 - 2) + a1[8] * *(v7 - 1) + a1[11];
      v5 += 3;
      v6 = (float *)((char *)v6 - 1);
    }
    while ( v6 );
  }
  return result;
}
```