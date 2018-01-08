## Open text file for reading

```C
//----- (004877B0) --------------------------------------------------------
// a1 = path
// returns FILE* ?
int __cdecl sub_4877B0(char *a1) {
  return sub_487830(a1, (int)aR);
}
```

### Wrapped function

```C
//----- (00487830) --------------------------------------------------------
int __cdecl sub_487830(char *a1, int a2)
{
  int result; // eax

  if ( dword_529500 )
    sub_487C00();
  if ( !strcmp(a1, aNone) )
  {
    dword_529504 = 0;
    goto LABEL_9;
  }
  dword_529504 = (*(int (__cdecl **)(char *, int))(dword_ECC420 + 48))(a1, a2);
  if ( (unsigned int)dword_529504 > 0 )
  {
LABEL_9:
    dword_EC9E84 = (LPCSTR)(*(int (__cdecl **)(signed int))(dword_ECC420 + 32))(4096);
    strncpy(byte_5143D8, a1, 0x7Fu);
    result = 1;
    byte_514457 = 0;
    dword_5284F8 = 0;
    dword_529500 = 1;
    return result;
  }
  dword_529504 = 0;
  if ( dword_529500 )
    sub_487C90();
  return 0;
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