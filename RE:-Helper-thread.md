# Thread mainloop

```C
//----- (00423330) --------------------------------------------------------
void __stdcall __noreturn StartAddress(LPVOID lpThreadParameter) {
  while(1) {
    WaitForSingleObject(hHandle, 0xFFFFFFFF);
    sub_4234C0();
  }
}
```

# Thread loop function

```C
//----- (004234C0) --------------------------------------------------------
signed int sub_4234C0()
{
  signed int result; // eax
  int v1; // esi
  unsigned int v2; // [esp+8h] [ebp-4h]

  result = dword_4EB418;
  if ( dword_4EB418 )
  {
    if ( !dword_4EB40C )
    {
      if ( !dword_4EB408 )
        return result;
      (*(void (__cdecl **)(int, _DWORD, _DWORD))(dword_ECC420 + 76))(dword_4EB404, *(_DWORD *)(dword_4EB418 + 60), 0);
      dword_4EB40C = *(_DWORD *)(dword_4EB418 + 40);
    }
    v1 = dword_4EB414;
    if ( !dword_4EB414 )
      (*(void (__cdecl **)(char *, char *, signed int))(dword_ECC420 + 24))(aPbuffer, aDDevelQa5PcGno_5, 1774);
    (*(void (__stdcall **)(int, unsigned int *))(*(_DWORD *)v1 + 76))(v1, &v2);
    result = sub_4233A0(dword_4EB418, v2 < 0x15888 ? 0x15888 : 0, (void *)0x15888);
    dword_4EB40C -= result;
  }
  return result;
}
```

