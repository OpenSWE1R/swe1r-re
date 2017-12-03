## EnumSessions callback

There seem to be up to 32 sessions

* dword_513870 points at the current session index / count

```C
//----- (00487450) --------------------------------------------------------
signed int __stdcall sub_487450(int a1, int a2, char a3, int a4) {
  if ( a3 & 1 ) {
    return 0;
  }

  if ( (unsigned int)dword_513870 < 32 ) {
    sub_4876D0(a1, 0x5117E8 + dword_513870 * 260);
    dword_513870++;
  }
  return 1;
}
```

# Player info

## Count players

```C
//----- (004871B0) --------------------------------------------------------
int __cdecl sub_4871B0(unsigned int a1)
{
  dword_510250 = 0;
  memset(&word_50FEE0, 0, 0x370u);
  if ( dword_51386C )
    return (*(int (__stdcall **)(LPVOID, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)ppv + 48))(
             ppv,
             0,
             sub_4874A0,
             0,
             0);
  if ( a1 >= dword_513870 )
    return -2147467259;
  return (*(int (__stdcall **)(LPVOID, unsigned int, _DWORD, _DWORD, signed int))(*(_DWORD *)ppv + 48))(
           ppv,
           260 * a1 + 5314536,
           sub_4874A0,
           0,
           128);
}
```

### EnumPlayers callback

There seem to be up to 20 players

* dword_510250 points at the current player index / count

```C
//----- (004874A0) --------------------------------------------------------
signed int __stdcall sub_4874A0(int a1, int a2, int a3, int a4, int a5) {
  void *v5; // edx
  const wchar_t *v6; // eax
  char v9; // [esp+8h] [ebp-400h]

  // Only look at players, not groups
  if ( a2 != 1) {
    return 1;
  } 

  if ((unsigned int)dword_510250 < 20 ) {
    v5 = (void *)( 0x50FEE0 + dword_510250 * 44);
    memset(v5, 0, 0x2Cu);

    v6 = *(const wchar_t **)(a3 + 8);
    if ( v6 ) {
      wcsncpy((wchar_t *)v5, v6, 0x13u);
      word_50FF06[dword_510250 * 22] = 0;
    }

    sub_48C380(&v9, *(_WORD **)(a3 + 8), 1024);
    dword_50FF08[dword_510250 * 11] = a1;

    dword_510250++;
  }
  return 1;
}
```

## Get playercount

```C
//----- (00487340) --------------------------------------------------------
int sub_487340() {
  return dword_510250;
}
```