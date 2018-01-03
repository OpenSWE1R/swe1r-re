# Savegam format

```C
// This data follows the 4 byte magic in the savegames (from player/data/*.sav)
// They come from 0xE364B4 in memory
typedef struct {
  char profileName[32]; // size?
  uint8_t unk[18];
  // 50 bytes
} Savedata;
```

# Write savedata

```C
//----- (004219D0) --------------------------------------------------------
// a1 = profile name (example: "anakin.sav")
// Returns TRUE on sucess
BOOL __cdecl sub_4219D0(int a1) {

  // Copy playerdata which will be written to the savegame
  uint8_t v6[0x50];
  qmemcpy(v6, byte_E364B4, 0x50u);

  //FIXME: Unknown?
  if ( dword_4B6C90 < 0 ) {
    return 0;
  }

  // Generate a string which holds the target path
  char v7[256];
  sprintf(v7, aSS_0, PathName, a1);
  sub_484600(v7, (int)&off_4B4F7C);

  // Open file for writing
  FILE* v3 = fopen(v7, aWb);
  if ( !v3 ) {
    return 0;
  }

  // Declare an error flag
  int32_t v1 = 0;

  // Write version (?) magic
  uint32_t v5 = 0x00010003;
  if ( !sub_4A0160(&v5, 1u, 4u, v3) ) {
    v1 = 1;
  }

  // Write actual data
  if ( !sub_4A0160(v6, 1u, 0x50u, v3) ) {
    v1 = 1;
  }

  // Close file again
  fclose(v3);

  // Return if we had success
  return v1 == 0;
}
```