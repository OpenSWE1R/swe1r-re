# GetHardwareCaps

```C
//----- (004848A0) --------------------------------------------------------
signed int sub_4848A0()
{
  HRESULT v1; // eax
  int v2; // eax

  if ( dword_50D548 )
    return 0;
  sub_49E940();
  v1 = sub_49E970(0, (int)&dword_50D548, 0, 128);
  if ( v1 >= 0 && dword_50D548 )
  {
    dword_50D550 = 1;
  }
  else
  {
    dword_4C7D80 = 0;
    dword_50D550 = 0;
    if ( v1 < 0 )
    {
      dword_50D548 = 0;
      return 0;
    }
  }
  dword_50D520 = 36;
  (*(void (__stdcall **)(int, int *))(*(_DWORD *)dword_50D548 + 44))(dword_50D548, &dword_50D520);
  dword_50D55C = dword_50D524 & 0x28;
  dword_50D554 = dword_50D524 & 2;
  v2 = sub_48C780();
  if ( (*(int (__stdcall **)(int, int, signed int))(*(_DWORD *)dword_50D548 + 76))(dword_50D548, v2, 1) < 0 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_50D548 + 8))(dword_50D548);
    dword_50D548 = 0;
    return 0;
  }
  (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)dword_50D548 + 92))(dword_50D548, 0);
  (*(void (__stdcall **)(int, signed int))(*(_DWORD *)dword_50D548 + 108))(dword_50D548, 8);
  (*(void (__stdcall **)(int, void *))(*(_DWORD *)dword_50D548 + 104))(dword_50D548, &unk_50D544);
  sub_484A80(dword_4C7D70);
  if ( dword_50D550 )
  {
    if ( (**(int (__stdcall ***)(int, void *, int *))dword_50D548)(dword_50D548, &unk_4AE158, &dword_50D560) < 0 )
    {
      dword_4C7D80 = 0;
      dword_50D550 = 0;
      dword_50D560 = 0;
      return 1;
    }
    (*(void (__stdcall **)(int, signed int))(*(_DWORD *)dword_50D548 + 128))(dword_50D548, 1079110533);
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)dword_50D548 + 144))(dword_50D548, LODWORD(flt_4C7D78));
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)dword_50D548 + 136))(dword_50D548, LODWORD(flt_4C7D74));
  }
  return 1;
}
```