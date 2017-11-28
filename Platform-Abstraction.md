This function seems to set function pointers for platform abstraction

```C
//----- (0048C3D0) --------------------------------------------------------
_DWORD *__cdecl sub_48C3D0(_DWORD *a1)
{
  _DWORD *result; // eax

  result = a1;
  a1[2] = sub_48C570;
  a1[1] = sub_48C570;
  a1[3] = sub_48C570;
  a1[4] = sub_48C570;
  *a1 = 1148846080;
  a1[5] = 0;
  a1[6] = sub_48C4A0;
  a1[7] = 0;
  a1[8] = sub_48D7E0;
  a1[9] = sub_48D9A0;
  a1[10] = sub_48DA80;
  a1[11] = timeGetTime;
  a1[12] = sub_48C5F0;
  a1[13] = sub_48C610;
  a1[14] = sub_48C620;
  a1[15] = sub_48C660;
  a1[16] = sub_48C640;
  a1[17] = feof;
  a1[18] = sub_48C6B0;
  a1[19] = sub_48C6C0;
  a1[20] = sub_48C6E0;
  a1[21] = sub_48C730;
  a1[22] = sub_48C680;
  a1[23] = sub_48C5A0;
  a1[24] = sub_48C5B0;
  a1[25] = sub_48C5C0;
  a1[26] = sub_48C5E0;
  a1[27] = nullsub_1;
  return result;
}
```