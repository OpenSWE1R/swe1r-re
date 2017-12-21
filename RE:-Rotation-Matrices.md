These get their own article because github wikis are not too good to edit and [[RE: Utility functions]] is fairly long already

---

* dword_4C98E8 = 32 bit float sin() LUT with 4096 entries
* dword_4CD8E8 = 32 bit float tan() LUT with 4096 entries
* dword_4BD8E8 = 32 bit float ???  LUT with 4096 entries  [min. offset 0x3000 in array?!] => 0x4C98E8
* flt_4C58E8 = 32 bit float ???  LUT with 4096 entries [min. offset 0x1000 in array?!] => 0x4C98E8
* flt_4C18E8 = 32 bit float ???  LUT with 4096 entries [min. offset 0x2000 in array?!] => 0x4C98E8

---

```C
//----- (0048C830) --------------------------------------------------------
double __cdecl sub_48C830(float a1)
{
  double v1; // st7
  float v2; // ST00_4
  float v4; // ST00_4
  float v5; // [esp+10h] [ebp-8h]
  float v6; // [esp+14h] [ebp-4h]

  if ( a1 >= 0.0 )
  {
    if ( a1 < 360.0 )
      return a1;
    v4 = a1 / 360.0;
    v5 = a1 - sub_48C8F0(v4) * 360.0;
  }
  else
  {
    v1 = -a1;
    v6 = v1;
    if ( v1 >= 360.0 )
    {
      v2 = v6 / 360.0;
      v5 = 360.0 - (v6 - sub_48C8F0(v2) * 360.0);
    }
    else
    {
      v5 = 360.0 - v6;
    }
  }
  if ( v5 == 360.0 )
    v5 = 0.0;
  return v5;
}
```

```C
//----- (0048C8F0) --------------------------------------------------------
double __cdecl sub_48C8F0(float a1)
{
  _ST7 = a1;
  __asm { frndint }
  return (float)_ST7;
}
```

```C
//----- (0048C910) --------------------------------------------------------
double __cdecl sub_48C910(float a1)
{
  double v1; // st7
  float v3; // [esp+0h] [ebp-4h]

  v1 = sub_48C830(a1);
  v3 = v1;
  if ( v1 > 180.0 )
    v3 = -(360.0 - v3);
  return v3;
}
```

```C
//----- (0048C950) --------------------------------------------------------
int __cdecl sub_48C950(float a1, int a2, int a3)
{
  double v3; // st7
  float v4; // ST1C_4
  int v5; // eax
  int result; // eax
  float v7; // ST24_4
  float v8; // ST24_4
  double v9; // st7
  float v10; // ST34_4
  float v11; // ST24_4
  double v12; // st7
  float v13; // ST34_4
  float v14; // ST24_4
  BOOL v15; // [esp+10h] [ebp-24h]
  BOOL v16; // [esp+10h] [ebp-24h]
  BOOL v17; // [esp+10h] [ebp-24h]
  float v18; // [esp+14h] [ebp-20h]
  signed int v19; // [esp+1Ch] [ebp-18h]
  float v20; // [esp+20h] [ebp-14h]
  int v21; // [esp+24h] [ebp-10h]
  int v22; // [esp+28h] [ebp-Ch]
  float v23; // [esp+2Ch] [ebp-8h]
  int v24; // [esp+30h] [ebp-4h]
  float v25; // [esp+30h] [ebp-4h]
  float v26; // [esp+30h] [ebp-4h]
  float v27; // [esp+30h] [ebp-4h]
  float v28; // [esp+30h] [ebp-4h]
  int v29; // [esp+30h] [ebp-4h]

  v3 = sub_48C830(a1);
  v23 = v3;
  if ( v3 >= 90.0 )
  {
    if ( v23 >= 180.0 )
    {
      if ( v23 >= 270.0 )
        v19 = 3;
      else
        v19 = 2;
    }
    else
    {
      v19 = 1;
    }
  }
  else
  {
    v19 = 0;
  }
  v4 = v23 * 45.511112;
  v18 = v4 - sub_48C8F0(v4);
  v5 = sub_48CD30(v4);
  v21 = v5;
  result = v5 + 1;
  v22 = result;
  switch ( v19 )
  {
    case 0:
      v15 = result >= 0x1000;
      if ( result >= 0x1000 )
        v24 = SLODWORD(dword_4C98E8[0xFFF - (result - 0x1000)]); // sin
      else
        v24 = SLODWORD(dword_4C98E8[result]); // sin
      *(float *)a2 = (*(float *)&v24 - dword_4C98E8[v21]) * v18 + dword_4C98E8[v21]; // sin + sin
      result = LODWORD(dword_4C98E8[0xFFF - v21]); // sin
      if ( v15 ) {
        v25 = -flt_4C58E8[v22];
      } else {
        result = LODWORD(dword_4C98E8[0xFFF - v22]); // sin
        v25 = dword_4C98E8[0xFFF - v22]; // sin
      }
      *(float *)a3 = (v25 - dword_4C98E8[0xFFF - v21]) * v18 + dword_4C98E8[0xFFF - v21]; // sin + sin
      break;
    case 1:
      v16 = result >= 0x2000;
      if ( result >= 0x2000 ) {
        v26 = -flt_4C18E8[result];
      } else {
        v26 = dword_4C98E8[0xFFF - (result - 0x1000)]; // sin
      }
      result = a2;
      v7 = dword_4C98E8[0xFFF - (v21 - 0x1000)]; // sin
      *(float *)a2 = (v26 - v7) * v18 + v7;
      if ( v16 ) {
        result = 0xFFF - (v22 - 0x2000);
        v9 = -dword_4C98E8[result]; // sin
      } else {
        v9 = -flt_4C58E8[v22];
      }
      v10 = v9;
      v8 = -flt_4C58E8[v21];
      *(float *)a3 = (v10 - v8) * v18 + v8;
      break;
    case 2:
      v17 = result >= 0x3000;
      if ( result >= 0x3000 )
        v12 = -dword_4C98E8[0xFFF - (result - 0x3000)]; // sin
      else
        v12 = -flt_4C18E8[result];
      v13 = v12;
      v11 = -flt_4C18E8[v21];
      *(float *)a2 = (v13 - v11) * v18 + v11;
      result = 0xFFF - (v21 - 0x2000);
      v20 = -dword_4C98E8[result]; // sin
      if ( v17 ) {
        v27 = *(float *)&dword_4BD8E8[v22];
      } else {
        result = v22 - 0x2000;
        v27 = -dword_4C98E8[0xFFF - (v22 - 0x2000)]; // sin
      }
      *(float *)a3 = (v27 - v20) * v18 + v20;
      break;
    case 3:
      if ( result >= 0x4000 )
        v28 = dword_4B98E8[result];
      else
        v28 = -dword_4C98E8[0xFFF - (result - 0x3000)]; // sin
      v14 = -dword_4C98E8[0xFFF - (v21 - 0x3000)]; // sin
      *(float *)a2 = (v28 - v14) * v18 + v14;
      if ( result >= 0x4000 ) {
        result -= 0x4000;
        v29 = SLODWORD(dword_4C98E8[0xFFF - (v22 - 0x4000)]); // sin
      } else {
        v29 = dword_4BD8E8[result];
      }
      *(float *)a3 = (*(float *)&v29 - *(float *)&dword_4BD8E8[v21]) * v18 + *(float *)&dword_4BD8E8[v21];
      break;
    default:
      return result;
  }
  return result;
}
```