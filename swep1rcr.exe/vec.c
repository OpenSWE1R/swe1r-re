/* Vector math */

// Research based on demo version

// [Preceeded by some rotation-related functions]

//----- (00431760) --------------------------------------------------------
float *__cdecl sub_431760(float *a1, float *a2, float *a3)
{
  float *result; // eax

  result = a3;
  *a1 = *a3 + *a2;
  a1[1] = a2[1] + a3[1];
  return result;
}

//----- (00431780) --------------------------------------------------------
int __cdecl sub_431780(int a1, float a2, int a3)
{
  int result; // eax

  result = a3;
  *(float *)a1 = *(float *)a3 * a2;
  *(float *)(a1 + 4) = *(float *)(a3 + 4) * a2;
  return result;
}

//----- (004317A0) --------------------------------------------------------
int __cdecl sub_4317A0(int a1, int a2, float a3, int a4)
{
  int result; // eax

  result = a4;
  *(float *)a1 = *(float *)a4 * a3 + *(float *)a2;
  *(float *)(a1 + 4) = *(float *)(a4 + 4) * a3 + *(float *)(a2 + 4);
  return result;
}

//----- (004317D0) --------------------------------------------------------
void __cdecl sub_4317D0(float *a1)
{
  float v1; // ST00_4

  v1 = a1[1] * a1[1] + *a1 * *a1;
  sub_485690(v1);
}

//----- (00431800) --------------------------------------------------------
double __cdecl sub_431800(float *a1)
{
  double result; // st7

  result = sub_4317D0(a1);
  if ( result >= 0.000099999997 )
  {
    *a1 = *a1 / result;
    a1[1] = a1[1] / result;
  }
  return result;
}
// 4317D0: using guessed type double __cdecl sub_4317D0(_DWORD);

//----- (00431830) --------------------------------------------------------
int __cdecl sub_431830(int a1, float a2, int a3, int a4)
{
  int result; // eax

  result = a1;
  *(float *)a1 = a2;
  *(_DWORD *)(a1 + 4) = a3;
  *(_DWORD *)(a1 + 8) = a4;
  return result;
}

//----- (00431850) --------------------------------------------------------
int __cdecl sub_431850(_DWORD *a1, _DWORD *a2)
{
  int result; // eax

  *a1 = *a2;
  a1[1] = a2[1];
  result = a2[2];
  a1[2] = result;
  return result;
}

//----- (00431870) --------------------------------------------------------
BOOL __cdecl sub_431870(float *a1, float *a2)
{
  return *a1 == *a2 && a1[1] == a2[1] && a1[2] == a2[2];
}

//----- (004318B0) --------------------------------------------------------
float *__cdecl sub_4318B0(float *a1, float *a2, float *a3)
{
  float *result; // eax

  result = a3;
  *a1 = *a3 + *a2;
  a1[1] = a3[1] + a2[1];
  a1[2] = a2[2] + a3[2];
  return result;
}

//----- (004318E0) --------------------------------------------------------
float *__cdecl sub_4318E0(float *a1, float *a2, float *a3)
{
  float *result; // eax

  result = a2;
  *a1 = *a2 - *a3;
  a1[1] = a2[1] - a3[1];
  a1[2] = a2[2] - a3[2];
  return result;
}

//----- (00431910) --------------------------------------------------------
double __cdecl sub_431910(float *a1, float *a2)
{
  return a1[1] * a2[1] + a1[2] * a2[2] + *a2 * *a1;
}

//----- (00431940) --------------------------------------------------------
void __cdecl sub_431940(float *a1)
{
  float v1; // ST00_4

  v1 = a1[1] * a1[1] + a1[2] * a1[2] + *a1 * *a1;
  sub_485690(v1);
}

//----- (00431990) --------------------------------------------------------
double __cdecl sub_431990(float *a1, float *a2)
{
  double v2; // st6
  double v3; // st5
  double v4; // st7
  float v6; // [esp+4h] [ebp+4h]
  float v7; // [esp+8h] [ebp+8h]

  v2 = a1[1] - a2[1];
  v3 = *a1 - *a2;
  v4 = a1[2] - a2[2];
  v6 = v3;
  v7 = v2;
  return v3 * v6 + v2 * v7 + v4 * v4;
}

//----- (004319D0) --------------------------------------------------------
void __cdecl sub_4319D0(float *a1, float *a2)
{
  double v2; // st6
  double v3; // st5
  double v4; // st7
  float v5; // ST04_4
  float v6; // ST08_4
  float v7; // ST00_4

  v2 = a2[1] - a1[1];
  v3 = *a2 - *a1;
  v4 = a2[2] - a1[2];
  v5 = v3;
  v6 = v2;
  v7 = v3 * v5 + v2 * v6 + v4 * v4;
  sub_485690(v7);
}

//----- (00431A30) --------------------------------------------------------
double __cdecl sub_431A30(float *a1)
{
  double result; // st7

  result = sub_431940(a1);
  if ( result >= 0.000099999997 )
  {
    *a1 = *a1 / result;
    a1[1] = a1[1] / result;
    a1[2] = a1[2] / result;
  }
  return result;
}
// 431940: using guessed type double __cdecl sub_431940(_DWORD);

//----- (00431A70) --------------------------------------------------------
float *__cdecl sub_431A70(float *a1, float *a2, float *a3)
{
  double v3; // st7
  float v4; // ST08_4
  float *result; // eax
  double v6; // st6

  v3 = a2[1] * a3[2];
  v4 = *a2 * a3[1] - *a3 * a2[1];
  result = a1;
  v6 = a3[1] * a2[2];
  a1[1] = *a3 * a2[2] - *a2 * a3[2];
  a1[2] = v4;
  *a1 = v3 - v6;
  return result;
}

//----- (00431AD0) --------------------------------------------------------
int __cdecl sub_431AD0(int a1, float a2, int a3)
{
  int result; // eax

  result = a3;
  *(float *)a1 = *(float *)a3 * a2;
  *(float *)(a1 + 4) = *(float *)(a3 + 4) * a2;
  *(float *)(a1 + 8) = *(float *)(a3 + 8) * a2;
  return result;
}

//----- (00431B00) --------------------------------------------------------
int __cdecl sub_431B00(int a1, int a2, float a3, int a4)
{
  int result; // eax

  result = a4;
  *(float *)a1 = *(float *)a4 * a3 + *(float *)a2;
  *(float *)(a1 + 4) = *(float *)(a4 + 4) * a3 + *(float *)(a2 + 4);
  *(float *)(a1 + 8) = *(float *)(a4 + 8) * a3 + *(float *)(a2 + 8);
  return result;
}

//----- (00431B40) --------------------------------------------------------
int __cdecl sub_431B40(int a1, float a2, int a3, float a4, int a5)
{
  int result; // eax

  result = a3;
  *(float *)a1 = *(float *)a3 * a2 + *(float *)a5 * a4;
  *(float *)(a1 + 4) = *(float *)(a3 + 4) * a2 + *(float *)(a5 + 4) * a4;
  *(float *)(a1 + 8) = *(float *)(a3 + 8) * a2 + *(float *)(a5 + 8) * a4;
  return result;
}

//----- (00431B90) --------------------------------------------------------
_DWORD *__cdecl sub_431B90(int a1, int a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = (_DWORD *)(a1 + 16 * a2);
  *result = *a3;
  result[1] = a3[1];
  result[2] = a3[2];
  return result;
}

//----- (00431BC0) --------------------------------------------------------
int __cdecl sub_431BC0(int a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  int result; // eax

  v3 = (_DWORD *)(a1 + 16 * a2);
  *a3 = *v3;
  a3[1] = v3[1];
  result = v3[2];
  a3[2] = result;
  return result;
}

//----- (00431BF0) --------------------------------------------------------
_DWORD *__cdecl sub_431BF0(_DWORD *a1, int a2)
{
  _DWORD *result; // eax
  signed int v3; // ebx
  signed int v4; // edx

  result = a1;
  v3 = 4;
  do
  {
    v4 = 4;
    do
    {
      *result = *(_DWORD *)((char *)result + a2 - (_DWORD)a1);
      ++result;
      --v4;
    }
    while ( v4 );
    --v3;
  }
  while ( v3 );
  return result;
}

// [More matrix functions follow]
