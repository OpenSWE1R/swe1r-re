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