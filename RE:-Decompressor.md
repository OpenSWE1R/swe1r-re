# Decompressor?

This is used from the model loader for "Comp" chunks

```C
//----- (0042D520) --------------------------------------------------------
_BYTE *__cdecl sub_42D520(const uint8_t* a1, uint8_t* a2) {
  char *v2; // edx
  uint8_t* result; // eax
  uint8_t* v4; // ebp
  int v5; // esi
  char v8; // cl
  int v9; // ebx
  int v10; // ecx
  int v11; // ecx
  int v12; // ebx
  int v14; // edi
  char v16; // dl
  bool v17; // sf
  unsigned __int8 v18; // of
  int v20; // [esp+14h] [ebp-8h]
  int16_t v23; // [esp+24h] [ebp+8h]

  v2 = a1;
  result = a2;
  v4 = &a1[-0x1000];
  v5 = 1;
  do {
    next_input_byte:

    // Read input byte
    v20 = *v2++;

    // Loop over input bits
    v23 = 0;
    while(v20 & (1 << v23)) {

      // Copy input to output byte
      *result++ = *v2;
      v4[v5] = *v2;
      v2++;

      // Advance address in page
      v5 = (v5 + 1) & 0xFFF;

      // Continue with next bit
LABEL_11:
      v23++;
      v18 = __OFSUB__(v23, 8);
      v17 = v23 < 8;
      if ( !(v17 ^ v18) ) {
        goto next_input_byte;
      }
    }

    // If this is not a byte copy, get more parameters
    v9 = *v2++; // 4 msb = number of ..; 4 lsb = source page (0x100 bytes) in input
    v10 = *v2++; // byte offset within input page

    v11 = ((v9 & 0xF) * 0x100) + v10; // Get offset to source byte
    v12 = (v9 >> 4) & 0xF; // Get number of bytes to copy

    // If source offset is 0, then this is the end of the stream
    if (v11 == 0) {
      break;
    }

    for(int32_t v14 = 0; v14 <= (v12 + 1); v14++) {
      v16 = v4[(v14 + v11) & 0xFFF];
      *result++ = v16;
      v4[v5] = v16;
      v5 = (v5 + 1) & 0xFFF;
      v14++
    }
    // Continue with next input bit
    goto LABEL_11;

  }
  return result;
}
```