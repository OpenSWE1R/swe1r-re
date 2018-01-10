# Unknown

```C
//----- (00484140) --------------------------------------------------------
char *__cdecl sub_484140(char *a1, int a2, int a3)
{
  char *result; // eax
  char *v4; // esi
  int v5; // eax

  result = dword_ECC420->unk8(140);
  if (result == 0) {
    return result;
  }

  v4 = result;
  memset(result, 0x00, 0x8Cu);
  v5 = a3;
  if ( a2 < 0 ) {
    goto LABEL_9;
  }
  if ( a2 <= 2 ) {
    sub_4846E0(v4 + 8, 128, a1, asc_4C7D54);
    goto LABEL_9;
  }
  if ( a2 != 3 ) {
LABEL_9:
    *(_DWORD *)v4 = a2;
    return v4;
  }
  if ( *(_BYTE *)a3 == 46 ) {
    v5 = a3 + 1;
  }
  sprintf(OutputString, aS, v5);
  sub_4846E0(v4 + 8, 128, a1, OutputString);
  *(_DWORD *)v4 = 3;
  return v4;
}
```

# Close filesearch ?

```C
//----- (004841E0) --------------------------------------------------------
// a1 = some file search handle?
// Probably returns nothing
void __cdecl sub_4841E0(uint32_t* a1) {
  if (a1 == 0) {
    return;
  }

  if ( a1[1] ) {
    findclose(a1[34]); // +136
  }

  //FIXME: This check feels redundant?
  if ( a1 ) {
    dword_ECC420->unk9(a1);
  }

  return;
}
```

# Start or continue filesearch

```
typdef struct {
  char path[256]; // unusure
  uint32_t unk;
  uint32_t is_subdirectory; // +260 Value 0x10 if this is a subdirectory, otherwise 0
  uint32_t time_write; // + 264 Time of the last write to file. This time is stored in UTC format.
} A2;

//----- (00484220) --------------------------------------------------------
BOOL __cdecl sub_484220(const char *a1, int a2) {
  BOOL result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // esi
  char v6; // dl
  time_t v7; // ecx
  struct _finddata_t v8; // [esp+Ch] [ebp-118h]

  if (a1 == 0) {
    return 0;
  }

  v3 = *((_DWORD *)a1 + 1);
  *((_DWORD *)a1 + 1) = v3 + 1;

  if ( v3 ) {
    v4 = _findnext(*((_DWORD *)a1 + 34), &v8);
  } else {
    v4 = _findfirst(a1 + 8, &v8);
    *((_DWORD *)a1 + 34) = v4;
  }

  if ( v4 == -1 ) {
    return 0;
  }

  v5 = *(_DWORD *)a1;
  v6 = v8.attrib;
  result = !*(_DWORD *)a1 || v5 == 3 || v5 == 1 && !(v8.attrib & 0x10) || v5 == 2 && v8.attrib & 0x10;
  if ( result )
  {
    strcpy((char *)a2, v8.name);
    v7 = v8.time_write;
    *(_DWORD *)(a2 + 260) = v6 & _A_SUBDIR;
    *(_DWORD *)(a2 + 264) = v7;
    result = 1;
  }
  return result;
}
```

# Create directory

```C
//----- (00484310) --------------------------------------------------------
BOOL __cdecl sub_484310(LPCSTR lpPathName) {
  return CreateDirectoryA(lpPathName, 0);
}
```

# Delete file

```C
//----- (00484320) --------------------------------------------------------
BOOL __cdecl sub_484320(LPCSTR lpFileName) {
  return DeleteFileA(lpFileName);
}
```

# Delete directory

```C
//----- (00484330) --------------------------------------------------------
BOOL __cdecl sub_484330(LPCSTR lpPathName) {
  signed int v1; // ebp
  int v2; // eax
  HANDLE hFindFile; // [esp+10h] [ebp-248h]
  CHAR FileName; // [esp+14h] [ebp-244h]
  struct _WIN32_FIND_DATAA FindFileData; // [esp+118h] [ebp-140h]

  strcpy(&FileName, lpPathName);
  v1 = 1;
  strcat(&FileName, asc_4C7D60);
  hFindFile = FindFirstFileA(&FileName, &FindFileData);
  if ( hFindFile == (HANDLE)-1 )
    return 0;
  do
  {
    if ( FindFileData.dwFileAttributes != 16 )
    {
      strcpy(&FileName, lpPathName);
      strcat(&FileName, (const char *)&unk_4B3B48);
      strcat(&FileName, FindFileData.cFileName);
      v2 = DeleteFileA(&FileName);
      goto LABEL_7;
    }
    if ( strcmp(FindFileData.cFileName, (const char *)&word_4B3B2C) && strcmp(FindFileData.cFileName, asc_4B4F44) )
    {
      strcpy(&FileName, lpPathName);
      strcat(&FileName, (const char *)&unk_4B3B48);
      strcat(&FileName, FindFileData.cFileName);
      v2 = sub_484330(&FileName);
LABEL_7:
      v1 = v2;
    }
  }
  while ( FindNextFileA(hFindFile, &FindFileData) && v1 == 1 );
  FindClose(hFindFile);
  if ( v1 )
    return RemoveDirectoryA(lpPathName);
  return v1;
}
```

# Get pointer to filename in path string

```C
//----- (004845B0) --------------------------------------------------------
// a1 = path, seperated using backslashes
// Returns filename, or full path if no backslash was found
char *__cdecl sub_4845B0(char *a1) {
  char v2; // cl

  char* result = strrchr(a1, '\\');
  if (result == NULL) {
    return a1;
  }

  // This scans forward until we are not on a backslash anymore.
  // This is probably useless, because strrchr already kind-of did this for us..
  // So basically this does `result++` once.
  while (*result == '\\') {
    result++;
  }

  return result;
}
```

# Get pointer to file extension in path string

```C
//----- (004845E0) --------------------------------------------------------
// a1 = path, seperated using backslashes
// Returns extension or NULL if no extension found
char* __cdecl sub_4845E0(char* a1) {
  char* filename = sub_4845B0(a1);
  char* extension = strrchr(v1, '.');
  if (extension == NULL) {
    return NULL;
  }
  return extension + 1;
}
```