# Packet handler

This handles the following packets:

* 1668575852: ctrl
* 1886151024: plap (player finished a lap)
* 1903520116: quit
* 1886550137: prxy
* 1919249006: rejn
* 1952544110: taun
* 1953655143: trig
* 1819243380: lost
* 1751477356: hell
* 1718185577: fini
* 1399878251: Sprk
* 1718378861: flam

Warning, this rewrite took some assumptions. But it *should* be fine.

```C
//----- (0041E260) --------------------------------------------------------
signed int __cdecl sub_41E260(_DWORD *a1)
{
  int v1; // edi
  signed int v2; // ebp
  int *v3; // esi
  int v4; // eax
  float v5; // ST28_4
  float v6; // ST2C_4
  float v7; // ST14_4
  int v8; // eax
  float v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  char *v13; // ST14_4
  void *v14; // ST0C_4
  const char *v15; // eax
  int v16; // edi
  int v17; // eax
  int v18; // eax
  int v20; // eax
  signed int v21; // eax
  int v22; // [esp+18h] [ebp-118h]
  int v23; // [esp+1Ch] [ebp-114h]
  int v24; // [esp+20h] [ebp-110h]
  int v25; // [esp+24h] [ebp-10Ch]
  int v26; // [esp+28h] [ebp-108h]
  int v27; // [esp+2Ch] [ebp-104h]
  char v28; // [esp+30h] [ebp-100h]

  //FIXME: This refactor assumes that dword_4EB1E8 is not manipulated during this function (or any subs)!
  if (dword_4EB1E8 == 0) {
    return 1;
  }

  v1 = a1[10];
  v2 = a1[11];
  v3 = a1 + 12;

  if (v2 == 1903520116) {
    dword_EA04E0[v1] = 1;
    v18 = 4 * v1;
    dword_EA05C0[v18] = 666;
    dword_EA05C4[v18] = 0;
    dword_EA05C8[v18] = 0;
    dword_EA05CC[v18] = 0;
    if (dword_4EB1C8) {
      sub_41C990(v1);
    }
  } else if (v2 == 1886550137) {
    v3 = a1 + 13;
    dword_4B6714 = dword_4EB3B4;
    v16 = a1[12];
    if ( v16 > 0 ) {
      do {
        v17 = *v3;
        ++v3;
        sub_41C990(v17);
        --v16;
      }
      while ( v16 );
    }
  } else if (v2 == 1919249006) {
    sub_411120(65, 0);
    dword_4EB1EC = 1;
  } else if (v2 == 1952544110) {
    v21 = *v3;
    v3 = a1 + 15;
    sub_427410(v21, a1[13], a1[14], 7976 * v1 + 15337296);
  } else if (v2 == 1953655143) {
    v20 = *v3;
    v3 = a1 + 14;
    sub_47E7E0(v20, a1[13]);
  } else if ( v2 == 1886151024) {
    v12 = *v3;
    v3 = a1 + 14;
    v13 = sub_41BC20(*((float *)a1 + 13));
    v14 = sub_41BCE0(v1);
    v15 = sub_421360(aMondotextH0511);
    sprintf(&v28, v15, v14, v12, v13);
    sub_41C190(&v28);
  } else if (v2 == 1819243380) {
    v11 = *v3;
    v3 = a1 + 13;
    sub_41C990(v11);
  } else if (v2 == 1751477356) {
    v8 = *v3;
    v3 = a1 + 13;
    v9 = dword_E29C44[34 * v8];
    if (v9 != 0.0) {
      *(_DWORD *)(LODWORD(v9) + 100) |= 0x40000u;
    }
    v10 = 4 * v8;
    dword_EA05C0[v10] = 666;
    dword_EA05C4[v10] = 0;
    dword_EA05C8[v10] = 0;
    dword_EA05CC[v10] = 0;
  } else if ( v2 == 1718185577) {
    *(_DWORD *)(dword_E28960 + 136 * v1 + 8) |= 2u;
    dword_EA02C0[v1] = 1;
  } else if (v2 == 1399878251 ) {
    if ( dword_4EB1E0 ) {
      v4 = *v3;
      v5 = *((float *)a1 + 13);
      v6 = *((float *)a1 + 14);
      v25 = a1[15];
      v26 = a1[16];
      v27 = a1[17];
      v22 = a1[18];
      v3 = a1 + 22;
      v23 = a1[19];
      v7 = *((float *)a1 + 21);
      v24 = a1[20];
      sub_477850(LODWORD(dword_E29C44[34 * v4]), v5, v6, (int)&v25, (int)&v22, v7);
    }
  } else if (v2 == 1668575852) {
    dword_4B6714 = -1;
    sub_41C940(dword_4EB1E8);
  } else if (v2 == 1718378861) {
    sub_46BB50(*v3);
  } else {
    return 0;
  }
  return 1;
}
```

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

## Get playername

FIXME: Why is this 88 in size, when player structs are only 44?! This is odd..

```C
//----- (0041BCE0) --------------------------------------------------------
// a1 = playerindex
void *__cdecl sub_41BCE0(int a1)
{
  sub_48C380(&unk_4EAD88, &word_E9F3C4 + 88 * a1, 32);
  return &unk_4EAD88;
}
```