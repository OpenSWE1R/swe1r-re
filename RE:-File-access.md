## Open text file for reading

```C
//----- (004877B0) --------------------------------------------------------
// a1 = path
// returns FILE* ?
int __cdecl sub_4877B0(char *a1) {
  return sub_487830(a1, aR);
}
```

### Wrapped function

```C
//----- (00487830) --------------------------------------------------------
// a1 = path
// a2 = open mode ("r")
int __cdecl sub_487830(char *a1, char* a2) {

  if ( dword_529500 ) {
    sub_487C00();
  }

  if ( !strcmp(a1, aNone) ) {
    dword_529504 = 0;
  } else {
    dword_529504 = dword_ECC420->unk12(a1, a2);
    if ( (unsigned int)dword_529504 <= 0 ) {
      dword_529504 = 0;
      if ( dword_529500 ) {
        sub_487C90();
      }
      return 0;
    }
  }

  dword_EC9E84 = dword_ECC420->unk8(4096);
  strncpy(byte_5143D8, a1, 0x7Fu);
  byte_514457 = 0;
  dword_5284F8 = 0;
  dword_529500 = 1;
  return 1;
}
```

#### Push to some stack?

```C
//----- (00487C00) --------------------------------------------------------
void sub_487C00() {
  strcpy(&byte_513938[128 * dword_52950C], byte_5143D8);
  dword_514388[dword_52950C] = dword_5284F8;
  dword_5284F8 = 0;
  dword_514338[dword_52950C] = (int)dword_EC9E84;
  dword_5284A8[dword_52950C] = dword_529504;
  dword_529504 = 0;
  qmemcpy((void *)(0x514458 + 4100 * dword_52950C), &dword_EC8E80, 4100);
  dword_52950C++;
  return;
}
```

#### Pop from some stack

```C
//----- (00487C90) --------------------------------------------------------
void sub_487C90() {
  if ( (unsigned int)dword_52950C >= 1 ) {
    dword_52950C--;
    strcpy(byte_5143D8, &byte_513938[128 * dword_52950C]);
    dword_529504 = dword_5284A8[dword_52950C];
    dword_5284F8 = dword_514388[dword_52950C];
    dword_EC9E84 = (LPCSTR)dword_514338[dword_52950C];
    qmemcpy(&dword_EC8E80, (const void *)(0x514458 + 4100 * dword_52950C), 4100);
  }
}
```

## Parse line

```C
//----- (00487AE0) --------------------------------------------------------
// True while not eof?
signed int sub_487AE0() {
  while( sub_487B20() ){
    if ( sub_487A50(dword_EC9E84) ) {
      break;
    }
    if ( dword_EC8E80 ) {
      return 1;
    }
  }
  return 0;
}
```

## Close

```C
//----- (00487900) --------------------------------------------------------
void sub_487900() {
  if ( dword_529500 == 0) {
    return;
  }

  // If a file was opened, close it and reset handle to 0
  if ( dword_529504 != 0) {
    dword_ECC420->unk13(dword_529504); // fclose
    dword_529504 = 0;
  }

  dword_ECC420->unk9(dword_EC9E84); // something like free

  if ( dword_52950C ) {
    sub_487C90();
  } else {
    dword_529500 = 0;
  }
}
```