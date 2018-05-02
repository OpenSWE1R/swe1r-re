/* Vector math */

// Research based on demo version

typedef struct {
  float x;
  float y;
} Vec2; // custom-name

typedef struct {
  float x;
  float y;
  float z;
} Vec3; // custom-name

typedef struct {
  float f[4 * 4];
} Mat4; // custom-name

// [Preceeded by some rotation-related functions]

//----- (00431760) --------------------------------------------------------
// Add Vec2 vectors
float *__cdecl sub_431760(float *a1, float *a2, float *a3) {
  a1[0] = a2[0] + a3[0];
  a1[1] = a2[1] + a3[1];
  return a3;
}

//----- (00431780) --------------------------------------------------------
// Scale Vec2
int __cdecl sub_431780(float* a1, float a2, float* a3) {
  a1[0] = a3[0] * a2;
  a1[1] = a3[1] * a2;
  return a3;
}

//----- (004317A0) --------------------------------------------------------
// Vec2 MAD (using scalar multiplication)
float* __cdecl sub_4317A0(float* a1, float* a2, float a3, float* a4) {
  a1[0] = a4[0] * a3 + a2[0];
  a1[1] = a4[1] * a3 + a2[1];
  return a4;
}

//----- (004317D0) --------------------------------------------------------
// Get Vec2 length
double __cdecl sub_4317D0(float *a1) {
  float v1 = a1[0] * a1[0] +
             a1[1] * a1[1];
  return sub_485690(v1);
}

//----- (00431800) --------------------------------------------------------
// Normalize Vec2
double __cdecl sub_431800(float *a1) {
  double result = sub_4317D0(a1);
  if (result >= 0.0001f) {
    a1[0] = a1[0] / result;
    a1[1] = a1[1] / result;
  }
  return result;
}

//----- (00431830) --------------------------------------------------------
// Set Vec3
float* __cdecl sub_431830(float* a1, float a2, float a3, float a4) {
  a1[0] = a2;
  a1[1] = a3;
  a1[2] = a4;
  return a1;
}

//----- (00431850) --------------------------------------------------------
// Copy Vec3
float __cdecl sub_431850(float* a1, const float* a2) {
  a1[0] = a2[0];
  a1[1] = a2[1];
  a1[2] = a2[2];
  return a2[2];
}

//----- (00431870) --------------------------------------------------------
// Compare Vec3
BOOL __cdecl sub_431870(const float* a1, const float* a2) {
  return (a1[0] == a2[0]) &&
         (a1[1] == a2[1]) &&
         (a1[2] == a2[2]);
}

//----- (004318B0) --------------------------------------------------------
// Add Vec3
const float *__cdecl sub_4318B0(float *a1, const float *a2, const float *a3) {
  a1[0] = a2[0] + a3[0];
  a1[1] = a2[1] + a3[1];
  a1[2] = a2[2] + a3[2];
  return a3;
}

//----- (004318E0) --------------------------------------------------------
// Subtract Vec3
float *__cdecl sub_4318E0(float *a1, const float *a2, const float *a3) {
  a1[0] = a2[0] - a3[0];
  a1[1] = a2[1] - a3[1];
  a1[2] = a2[2] - a3[2];
  return a2;
}

//----- (00431910) --------------------------------------------------------
// Get squared length of Vec3
double __cdecl sub_431910(const float* a1, const float* a2) {
  return  a2[0] * a1[0] +
          a1[1] * a2[1] +
          a1[2] * a2[2];
}

//----- (00431940) --------------------------------------------------------
double __cdecl sub_431940(const float* a1) {
  float v1 = a1[0] * a1[0] + 
             a1[1] * a1[1] +
             a1[2] * a1[2];
  return sub_485690(v1);
}

//----- (00431990) --------------------------------------------------------
// Get squared distance between Vec3
double __cdecl sub_431990(const float *a1, const float *a2) {
  double dx = a1[0] - a2[0];
  double dy = a1[1] - a2[1];
  double dz = a1[2] - a2[2];
  return dx * dx + dy * dy + dz * dz;
}

//----- (004319D0) --------------------------------------------------------
// Get distance between Vec3
double __cdecl sub_4319D0(float *a1, float *a2) {
  double dx = a2[0] - a1[0];
  double dy = a2[1] - a1[1];
  double dz = a2[2] - a1[2];
  double v7 = dx * dx + dy * dy + dz * dz;
  return sub_485690(v7);
}

//----- (00431A30) --------------------------------------------------------
// Normalize Vec3
double __cdecl sub_431A30(float *a1) {
  double result = sub_431940(a1);
  if (result >= 0.0001f) {
    a1[0] = a1[0] / result;
    a1[1] = a1[1] / result;
    a1[2] = a1[2] / result;
  }
  return result;
}

//----- (00431A70) --------------------------------------------------------
// Cross-Product of Vec3
float *__cdecl sub_431A70(float *a1, const float *a2, const float *a3) {
  a1[0] = a2[1] * a3[2] - a2[2] * a3[1];
  a1[1] = a2[2] * a3[0] - a2[0] * a3[2];
  a1[2] = a2[0] * a3[1] - a2[1] * a3[0];
  return a1;
}

//----- (00431AD0) --------------------------------------------------------
// Scale Vec3
const float* __cdecl sub_431AD0(float* a1, float a2, const float* a3) {
  a1[0] = a3[0] * a2;
  a1[1] = a3[1] * a2;
  a1[2] = a3[2] * a2;
  return a3;
}

//----- (00431B00) --------------------------------------------------------
// Scale one Vec3 and add another one
const float* __cdecl sub_431B00(float* a1, const float* a2, float a3, const float* a4) {
  a1[0] = a4[0] * a3 + a2[0];
  a1[1] = a4[1] * a3 + a2[1];
  a1[2] = a4[2] * a3 + a2[2];
  return a4;
}

//----- (00431B40) --------------------------------------------------------
// Scale 2 independent Vec3 and add them together
const float* __cdecl sub_431B40(float* a1, float a2, const float* a3, float a4, const float* a5) {
  a1[0] = a3[0] * a2 + a5[0] * a4;
  a1[1] = a3[1] * a2 + a5[1] * a4;
  a1[2] = a3[2] * a2 + a5[2] * a4;
  return a3;
}

//----- (00431B90) --------------------------------------------------------
// Set given row (column?) of Mat4 from Vec3 ?!
float* __cdecl sub_431B90(float* a1, int a2, const float* a3) {
  float* result = &a1[a2 * 4 + 0];
  result[0] = a3[0];
  result[1] = a3[1];
  result[2] = a3[2];
  return result;
}

//----- (00431BC0) --------------------------------------------------------
// Get given row (column?) of Mat4 to Vec3 ?!
float __cdecl sub_431BC0(const float* a1, int a2, float* a3) {
  float* v3 = &a1[a2 * 4 + 0];
  a3[0] = v3[0];
  a3[1] = v3[1];
  a3[2] = v3[2];
  return v3[2];
}

//----- (00431BF0) --------------------------------------------------------
// Copy Mat4 ?!
float* __cdecl sub_431BF0(float* a1, const float* a2) {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      a1[i * 4 + j] = a2[i * 4 + j];
    }
  }
  return a1;
}

//----- (00431C20) --------------------------------------------------------
float *__cdecl sub_431C20(float *a1, float *a2, float *a3)
{
  float v3; // ST48_4
  float v4; // ST4C_4
  double v5; // st6
  float v6; // ST50_4
  float v7; // ST54_4
  double v8; // st3
  float v9; // ST58_4
  float v10; // ST5C_4
  float v11; // ST44_4
  float v12; // ST60_4
  float v13; // ST00_4
  float v14; // ST64_4
  float v15; // ST68_4
  float v16; // ST6C_4
  float v17; // ST70_4
  float v18; // ST04_4
  float v19; // ST74_4
  float v20; // ST10_4
  float v21; // ST78_4
  float v22; // ST14_4
  float v23; // ST08_4
  float v24; // ST20_4
  float v25; // ST18_4
  float v26; // ST7C_4
  float v27; // ST24_4
  float v28; // ST28_4
  float v29; // ST0C_4
  double v30; // rt2
  double v31; // st4
  float v32; // ST1C_4
  float v33; // ST38_4
  float v34; // ST2C_4
  float v35; // ST34_4
  float v36; // ST3C_4
  float *result; // eax
  double v38; // st7

  v3 = a2[2];
  v4 = a2[3];
  v5 = a3[1];
  v6 = a2[4];
  v7 = a2[5];
  v8 = *a2;
  v9 = a2[6];
  v10 = a2[7];
  v11 = a2[1];
  v12 = a2[8];
  v13 = *a3;
  v14 = a2[9];
  v15 = a2[10];
  v16 = a2[11];
  v17 = a2[12];
  v18 = a3[1];
  v19 = a2[13];
  v20 = a3[4];
  v21 = a2[14];
  v22 = a3[5];
  v23 = a3[2];
  v24 = a3[8];
  v25 = a3[6];
  v26 = a2[15];
  v27 = a3[9];
  v28 = a3[10];
  v29 = a3[3];
  v30 = v27;
  v31 = a3[12];
  v32 = a3[7];
  v33 = a3[14];
  v34 = a3[11];
  v35 = a3[13];
  v36 = a3[15];
  result = a1;
  v38 = v22 * v11;
  *a1 = v13 * v8 + v20 * v11 + v24 * v3 + v31 * v4;
  a1[1] = v5 * v8 + v38 + v30 * v3 + v35 * v4;
  a1[2] = v23 * v8 + v25 * v11 + v28 * v3 + v33 * v4;
  a1[3] = v29 * v8 + v32 * v11 + v34 * v3 + v36 * v4;
  a1[4] = v13 * v6 + v20 * v7 + v24 * v9 + v31 * v10;
  a1[5] = v18 * v6 + v22 * v7 + v27 * v9 + v35 * v10;
  a1[6] = v23 * v6 + v25 * v7 + v28 * v9 + v33 * v10;
  a1[7] = v29 * v6 + v32 * v7 + v34 * v9 + v36 * v10;
  a1[8] = v13 * v12 + v20 * v14 + v24 * v15 + v31 * v16;
  a1[9] = v18 * v12 + v22 * v14 + v27 * v15 + v35 * v16;
  a1[10] = v23 * v12 + v25 * v14 + v28 * v15 + v33 * v16;
  a1[11] = v29 * v12 + v32 * v14 + v34 * v15 + v36 * v16;
  a1[12] = v13 * v17 + v20 * v19 + v24 * v21 + v31 * v26;
  a1[13] = v18 * v17 + v22 * v19 + v27 * v21 + v35 * v26;
  a1[14] = v23 * v17 + v25 * v19 + v28 * v21 + v33 * v26;
  a1[15] = v29 * v17 + v32 * v19 + v34 * v21 + v36 * v26;
  return result;
}

//----- (00432030) --------------------------------------------------------
float *__cdecl sub_432030(float *a1, float *a2)
{
  float *result; // eax
  double v3; // st7
  double v4; // st6
  float v5; // ST30_4
  float v6; // ST00_4
  double v7; // st5
  float v8; // ST14_4
  float v9; // ST24_4
  float v10; // edx
  float v11; // ST18_4
  float v12; // ST34_4
  float v13; // ST04_4
  double v14; // st4
  float v15; // ST28_4
  float v16; // edx
  float v17; // ST0C_4
  float v18; // ST38_4
  float v19; // ST08_4
  float v20; // ST1C_4
  float v21; // ST2C_4
  float v22; // edx

  result = a2;
  v3 = a1[4];
  v4 = a1[8];
  v5 = a1[12];
  v6 = *a1;
  v7 = a1[13];
  v8 = a1[5];
  v9 = a1[9];
  v10 = a1[6];
  *a1 = v3 * a2[1] + v4 * a2[2] + v5 * a2[3] + *a2 * v6;
  v11 = v10;
  v12 = v7;
  v13 = a1[1];
  v14 = a1[14];
  v15 = a1[10];
  v16 = a1[3];
  a1[1] = v8 * a2[1] + v9 * a2[2] + v7 * a2[3] + *a2 * v13;
  v17 = v16;
  v18 = v14;
  v19 = a1[2];
  v20 = a1[7];
  v21 = a1[11];
  v22 = a1[15];
  a1[2] = v11 * a2[1] + v15 * a2[2] + v14 * a2[3] + *a2 * v19;
  a1[3] = v20 * a2[1] + v21 * result[2] + v22 * result[3] + *result * v17;
  a1[4] = v3 * result[5] + v5 * result[7] + v6 * result[4] + v4 * result[6];
  a1[5] = v8 * result[5] + v12 * result[7] + v13 * result[4] + v9 * a2[6];
  a1[6] = v11 * result[5] + v18 * result[7] + v19 * result[4] + v15 * result[6];
  a1[7] = v20 * result[5] + v22 * result[7] + v17 * result[4] + v21 * result[6];
  a1[8] = v4 * result[10] + v3 * result[9] + v5 * result[11] + v6 * a2[8];
  a1[9] = v9 * result[10] + v8 * result[9] + v12 * result[11] + v13 * result[8];
  a1[10] = v15 * result[10] + v11 * result[9] + v18 * result[11] + v19 * result[8];
  a1[11] = v21 * result[10] + v20 * result[9] + v22 * a2[11] + v17 * a2[8];
  a1[12] = v3 * result[13] + v5 * result[15] + v6 * a2[12] + v4 * a2[14];
  a1[13] = v8 * result[13] + v12 * result[15] + v13 * result[12] + v9 * result[14];
  a1[14] = v11 * result[13] + v18 * result[15] + v19 * result[12] + v15 * a2[14];
  a1[15] = v20 * a2[13] + v22 * a2[15] + v17 * a2[12] + v21 * a2[14];
  return result;
}

//----- (004323C0) --------------------------------------------------------
int __cdecl sub_4323C0(int a1, float *a2)
{
  float *v2; // ecx
  double v3; // st7
  int result; // eax
  float v5; // edx
  double v6; // st4
  double v7; // rt2
  double v8; // st5
  float v9; // ST00_4
  double v10; // st6
  double v11; // st7
  double v12; // st7
  double v13; // st2
  double v14; // st7
  float v15; // [esp+8h] [ebp+4h]
  float v16; // [esp+8h] [ebp+4h]
  float v17; // [esp+8h] [ebp+4h]
  float v18; // [esp+Ch] [ebp+8h]
  float v19; // [esp+Ch] [ebp+8h]
  float v20; // [esp+Ch] [ebp+8h]

  v2 = a2;
  v3 = a2[4] * a2[4] + a2[5] * a2[5] + a2[6] * a2[6];
  result = a1;
  v5 = a2[1];
  v6 = a2[4] / v3;
  v15 = a2[9];
  v7 = v15;
  v8 = a2[8] * a2[8];
  v18 = a2[10];
  v9 = *v2;
  v10 = v2[2] * v2[2];
  *(float *)(result + 4) = v6;
  v16 = v8 + v7 * v15 + v18 * v18;
  *(float *)(result + 8) = v2[8] / v16;
  *(float *)(result + 24) = v2[9] / v16;
  v19 = v5 * v5 + v10 + v9 * v9;
  *(float *)(result + 16) = v2[1] / v19;
  *(float *)(result + 32) = v2[2] / v19;
  *(float *)(result + 36) = v2[6] / v3;
  *(float *)result = *v2 / v19;
  *(float *)(result + 20) = v2[5] / v3;
  v11 = v2[10] / v16;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 28) = 0;
  *(_DWORD *)(result + 44) = 0;
  *(_DWORD *)(result + 60) = 1065353216;
  *(float *)(result + 40) = v11;
  v12 = v2[14];
  v20 = v2[12];
  v17 = v2[13];
  v13 = v12 * *(float *)(result + 36);
  *(float *)(result + 48) = -(v17 * *(float *)(result + 16) + v12 * *(float *)(result + 32) + *(float *)result * v20);
  v14 = -(v17 * *(float *)(result + 24) + v20 * *(float *)(result + 8) + v12 * *(float *)(result + 40));
  *(float *)(result + 52) = -(v13 + v20 * *(float *)(result + 4) + v17 * *(float *)(result + 20));
  *(float *)(result + 56) = v14;
  return result;
}

// [More matrix functions follow]
