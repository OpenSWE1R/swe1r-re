/* Functions to work with textures */

// Research based on patched US version

//----- (0048A9E0) --------------------------------------------------------
// Getting texture dimensions for texture-upload.
// The size is restricted by the GPU capabilities.
// a1 = in_width
// a2 = in_height
// a3 = &out_width
// a4 = &out_height
void sub_48A9E0(unsigned int a1, unsigned int a2, unsigned int *a3, unsigned int *a4) {
  unsigned int min_width = *(_DWORD *)(dword_52E618 + 32);
  unsigned int max_width = *(_DWORD *)(dword_52E618 + 40);

  unsigned int width;
  if (a1 < min_width) {
    width = min_width;
  } else if (a1 > max_width) {
    width = max_width;
  } else {
    width = a1;
  }

  unsigned int min_height = *(_DWORD *)(dword_52E618 + 36);
  unsigned int max_height = *(_DWORD *)(dword_52E618 + 44);

  unsigned int height;
  if (a2 < min_height) {
    height = min_height;
  } else if (a2 > max_height) {
    height = max_height
  } else {
    height = a2;
  }

  // Check for square textures
  unsigned int must_be_square = *(_DWORD *)(dword_52E618 + 28);
  if (must_be_square) {
    // Make sure that `width` is the maximum, either `width` or `height`
    if (height > width ) {
      width = height;
    }
    *a3 = width;
    *a4 = width;
  } else {
    *a3 = width;
    *a4 = height;
  }
}


//----- (0048A5E0) --------------------------------------------------------
// Loading texture / Create DirectDraw surfaces and fill with data
// a1 = ?
// a2 = texture object
// a3 = number of mipmaps
// a4 = number of bytes per pixel?
int __cdecl sub_48A5E0(_DWORD *a1, _DWORD *a2, unsigned int a3, int a4)
{
  int result; // eax
  _DWORD **v5; // ebx
  unsigned int *v6; // ebp
  unsigned int v7; // edx
  int v8; // eax
  unsigned int v10; // ebp
  unsigned int v11; // esi
  signed int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // [esp+8Ch] [ebp-1C4h]
  int v16; // [esp+90h] [ebp-1C0h]
  int v17; // [esp+94h] [ebp-1BCh]
  int v18; // [esp+98h] [ebp-1B8h]
  int v19; // [esp+9Ch] [ebp-1B4h]
  signed int (__cdecl *v20)(_DWORD *, unsigned int, int); // [esp+A0h] [ebp-1B0h]
  int v21; // [esp+A4h] [ebp-1ACh]
  int v22; // [esp+A8h] [ebp-1A8h]
  int v23; // [esp+ACh] [ebp-1A4h]
  int v24; // [esp+B0h] [ebp-1A0h]
  unsigned int v25; // [esp+B4h] [ebp-19Ch]
  unsigned int *v26; // [esp+B8h] [ebp-198h]
  char v27; // [esp+BCh] [ebp-194h]
  unsigned int v32; // [esp+F4h] [ebp-15Ch]
  char v33; // [esp+124h] [ebp-12Ch]
  int (*v34)(); // [esp+144h] [ebp-10Ch]
  int v35; // [esp+158h] [ebp-F8h]
  unsigned int v36; // [esp+160h] [ebp-F0h]
  int v37; // [esp+164h] [ebp-ECh]
  int v38; // [esp+168h] [ebp-E8h]
  int v39; // [esp+17Ch] [ebp-D4h]

  memset(a1, 0, 0x94u);
  result = dword_52E61C;
  v15 = 0;
  v16 = 0;
  if ( !dword_52E61C )
    return result;

  v5 = (_DWORD **)a2;
  v6 = (unsigned int *)*a2;
  v26 = v6;

  // Get texture dimensions
  sub_48A9E0(v6[3], v6[4], (unsigned int *)&v19, (unsigned int *)&v18);

  //  width * height * bits_per_pixel / 8
  v25 = v19 * v18 * v6[9] >> 3;

  if ( dword_52E614 ) {
    v7 = a3;
  } else {
    v7 = 1;
    a3 = 1;
  }

  // Get proper format for number of bytes per pixel?!
  if ( a4 == 1 )
  {
    v8 = dword_52D568;
  }
  else if ( a4 == 2 )
  {
    v8 = dword_52D560;
  }
  else
  {
    v8 = dword_52D564;
  }
  qmemcpy(&v27, (char *)&unk_52D5B0 + 96 * v8, 0x20u);

  DDSURFACEDESC2 v28;
  // int v28; // [esp+DCh] [ebp-174h] + 0
  // int v29; // [esp+E0h] [ebp-170h] + 4
  // int v30; // [esp+E4h] [ebp-16Ch] + 8
  // unsigned int v31; // [esp+E8h] [ebp-168h] + 12
  memset(&v28, 0, 0x7Cu);
  v28.size = 124;
  v28.dwFlags = 0x1007 // v29 = 4103;
  v28.dwWidth = v6[3]; // v31 = v6[3];
  v28.dwHeight = v6[4]; // v30 = v6[4];
  v10 = 0;
  v15 = 0;

  v34 = 0x1800; // this will be ddsCaps.dwCaps
  qmemcpy(&v33, &v27, 0x20u);

  if ( v7 > 1 )
  {
    v29 = 135175;
    v34 = sub_401808;
    v32 = v7;
  }
  if ( dword_52E638->CreateSurface(&v28, &v15, 0) || v15->QueryInterface(&unk_4AF328, &v17) )
  {
    goto LABEL_43;
  }
  v11 = a3;
  if ( a3 )
  {
    do
    {
      memset(&v35, 0, 0x7Cu);
      v35 = 124;
      if (v15->Lock(0, &v35, 1, 0))
        goto LABEL_43;
      v12 = (*v5)[8];
      if ( v12 && v12 > 0 && v12 <= 2 )
      {
        sub_488370(*v5);
        v13 = 0;
        // Check if height is != 0
        if ( v36 )
        {
          // Copy line `v13`
          do {
            qmemcpy((void *)(v39 + v13 * v38), (const void *)((*v5)[22] + v13 * (*v5)[6]), 2 * v37);
            ++v13;
          } while ( v13 < v36 );
          v11 = a3;
        }
        sub_4883C0(*v5);
      }
      if (v15->Unlock(0))
        goto LABEL_43;
      if ( v10 < v11 - 1 )
      {
        v21 = 0;
        v22 = 0;
        v23 = 0;
        v20 = sub_401000;
        if (v15->GetAttachedSurface(&v20, &v15))
        {
          goto LABEL_43;
        }
      }
      ++v10;
      ++v5;
    }
    while ( v10 < v11 );
  }

  // Do some size checking
  if ( v19 == v26[3] && v18 == v26[4] )
    goto LABEL_39;

  DDSURFACEDESC2 v40;
  //char v40; // [esp+1D4h] [ebp-7Ch] // + 0
  //int v41; // [esp+1DCh] [ebp-74h] // + 8
  //int v42; // [esp+1E0h] [ebp-70h] // + 12
  qmemcpy(&v40, &v28, 0x7Cu);

  v40.dwWidth = v19; // v42 = v19;
  v40.dwHeight = v18; // v41 = v18;

  if ( !dword_52E638->CreateSurface(&v40, &v16, 0) && !(v16->QueryInterface((&unk_4AF328, &v24) )
  {
    v14 = 0;
    if ( a3 )
    {
      while ( !v16->Blt(0, v15, 0, 0x1000000, 0) )
      {
        if ( v14 < a3 - 1 )
        {
          v20 = sub_401000;
          v21 = 0;
          v22 = 0;
          v23 = 0;
          if (v16->GetAttachedSurface(&v20, &v16) )
          {
            break;
          }
        }
        if ( ++v14 >= a3 )
          goto LABEL_36;
      }
      goto LABEL_43;
    }
LABEL_36:
    if ( v16 )
      v16->Release();
      v17->Release();
    qmemcpy(&v28, &v40, 0x7Cu);
    v17 = v24;
LABEL_39:
    if ( v15 )
      v15->Release();
    result = (int)a1;
    a1[31] = v17;
    qmemcpy(a1, &v28, 0x7Cu);
    a1[33] = v25;
    return result;
  }
LABEL_43:
  result = v15;
  if ( v15 )
    result = v15->Release();
  return result;
}

//----- (00431DF0) --------------------------------------------------------
// Color inversion?
// (not actually a function?)
// a3 = must be anything but "invcol"
// Probably returns void
int __usercall sub_431DF0@<eax>(int a1@<ebx>, int a2@<ebp>, char *a3) {
  int result; // eax
  int v6; // eax
  int v7; // ebp
  int v8; // edi
  uint32_t v10; // [esp+20h] [ebp-80h]
  uint32_t v11; // [esp+28h] [ebp-78h]

  result = strncmp(a3, aInvcol, 5u);
  if (result) {
    sprintf(a3, aInvcol);

    something = *(_DWORD *)(*((_DWORD *)a3 + 36) + 124); // or something like this..

    v10 = 0;  // v11?
    something->QueryInterface(&unk_4AF208, &v11); //FIXME: Used to say `.., &v10, a, b); ?!

    DDSURFACEDESC2 v12;
    //  int v12; // [esp+2Ch] [ebp-74h]    0 dwSize
    //  char v13; // [esp+30h] [ebp-70h]   4 dwFlags
    //  int v14; // [esp+34h] [ebp-6Ch]    8 dwHeight
    //  int v15; // [esp+38h] [ebp-68h]   12 dwWidth
    //  int v16; // [esp+3Ch] [ebp-64h]   16 lPitch or dwLinearSize
    //  __int16 *v17; // [esp+50h] [ebp-50h] 36 lpSurface

    memset(&v12, 0, 0x7Cu);
    v12.dwSize = 124;
    v11->Lock(0, &v12, 1, 0);

    uint16_t* v4 = v12.lpSurface;

    // Calculate pitch if it doesn't exist
    if ( v12.dwFlags & DDSD_PITCH ) {
      v6 = v12.lPitch / 2;
    } else {
      v6 = v11; //FIXME: This is probably bad?!
    }

    // Loop over rows in image
    for(v7 = 0; v7 < v12.dwHeight; v7++) {
      // Loop over pixels in row
      for(v8 = 0; v8 < v12.dwWidth; v8++) {
        // Sample pixel
        uint16_t pixel = *v4;
        // Invert color but keep alpha
        //FIXME: this is a bug? inverting 0x0FFF will also overwrite alpha. Figure out if this is a bug in RE or the game.
        *v4++ = (pixel & 0xF000) | ~(pixel & 0xFFF);
      }
      // Advance to next row (v6 = pitch?, v5 = rowlength)
      v4 += v6 - v12.dwWidth;
    }
    result = v11->Unlock(0);
  }
  return result;
}












//----- (00447370) --------------------------------------------------------
// Loads texture from textureblock
// a1 = 3 Pointers into offset table (a, b, c)
// a2 = receives data read from a
// a3 = receives data read from b (optional, might be garbage!)
int __cdecl sub_447370(const uint32_t* a1, uint32_t* a2, uint32_t* a3) {
  uint8_t* v7; // esi

  // Get length of texture data, assuming a1[1] is 0
  int32_t v4 = a1[2] - a1[0];

  // Check if there is enough room left in the buffer
  if ((v4 + 128) > sub_445BF0()) {
    *a3 = 0;
    *a2 = 0;
    dword_50C610 = 1;
    return a2;
  }

  // If a1[1] is not 0, then we need to fixup the texture size
  if ( a1[1] ) {
    v4 = a1[1] - a1[0];
  }

  // Get the current buffer offset and align it to the next 64 byte boundary
  v7 = align_up(sub_445B40(), 64);

  // Read texturedata from modelblock at a1[0] to v7
  sub_42D640(3, a1[0], v7, v4);
  *a2 = v7;

  // Load the optional texture chunk
  if (a1[1]) {

    // Calculate length of optional texture chunk
    v4 = a1[2] - a1[1];

    // Allocate space in the buffer for the optional chunk
    v7 = align_up(v7 + v4, 64);

  // Read optional texturedata from modelblock at a1[1] to v7
    sub_42D640(3, a1[1], v7, v4);
    *a3 = v7;
  }
  //FIXME: Shouldn't there be an `else` case which sets `*a3 = 0` ?!
  //       Bug in original game code?

  // Set buffer offset
  return sub_445B20(v7 + v4);
}

















//----- (00445EE0) --------------------------------------------------------
// Process textue data
// Typically called like `sub_445EE0(3, 0, 64, 128, 64, 128, v1, &v11, 1, 0);`
// a1 = Unknown, maybe textureblock index?
// a2 = Unknown, often zero?
// a3 = NPOT width
// a4 = NPOT height
// a5 = POT width
// a6 = POT Height
// a7 = Pointer to texture data, also used as output: Receives pointer to material?
// a8 = Pointer to optional texture data
// a9 = Unknown, always 0 or 1
// a10 = Unknown, flags? only bit 0x10 and 0x01 are used
int __cdecl sub_445EE0(int a1, int a2, int a3, int a4, int a5, int a6, char **a7, int *a8, char a9, char a10) {
  int v11; // ebx
  char *v12; // ebp
  char *v13; // edi
  int v16; // eax
  _WORD *v18; // edx
  char *v19; // esi
  int v20; // edi
  int v21; // ecx
  int v22; // ebp
  int i; // edi
  __int16 v24; // cx
  int v25; // ebx
  unsigned int v26; // ecx
  _WORD *v27; // edi
  int v29; // ebx
  int v30; // ecx
  _WORD *v31; // ebp
  __int16 *v32; // edx
  int v33; // ebp
  _WORD *v34; // ecx
  int v35; // esi
  __int16 v36; // bp
  __int16 *v37; // ecx
  int v38; // esi
  __int16 v39; // bx
  int v40; // ebp
  int k; // ecx
  __int16 v42; // ax
  int v43; // ebx
  unsigned int v44; // ecx
  _WORD *v45; // edi
  int v46; // ecx
  int v47; // edi
  int v48; // ebp
  unsigned int v49; // ecx
  char v50; // al
  unsigned int v51; // ecx
  _WORD *v52; // edi
  int v53; // ecx
  int v54; // ebp
  int v55; // ecx
  int v56; // edi
  unsigned int v57; // eax
  unsigned int v58; // ebx
  int v59; // ebx
  unsigned int v60; // ecx
  _WORD *v61; // edi
  int v62; // ecx
  int j; // edi
  unsigned __int16 v64; // cx
  int v65; // eax
  int v66; // ebp
  unsigned int v67; // ecx
  _WORD *v68; // edi
  int v69; // ecx
  int v70; // ebp
  int v71; // edi
  int v72; // eax
  unsigned __int16 v73; // cx
  int v74; // ebp
  unsigned int v75; // ecx
  _WORD *v76; // edi
  int v77; // ecx
  int v78; // ebp
  int v79; // ecx
  int v80; // edi
  unsigned int v81; // eax
  int v82; // ecx
  int v83; // ebx
  int v84; // esi
  int v85; // edi
  int v86; // ecx
  int v87; // ebp
  int v88; // esi
  int v89; // edi
  __int16 v90; // ax
  unsigned __int16 v91; // cx
  int v92; // esi
  unsigned int v93; // ecx
  _WORD *v94; // edi
  int v95; // ecx
  int v96; // ecx
  int v97; // esi
  unsigned int v98; // eax
  int v99; // ecx
  int v100; // ecx
  int v101; // edi
  int v102; // eax
  int v103; // ebp
  int v104; // ebx
  int v105; // ecx
  int v106; // esi
  int v107; // edi
  unsigned int v108; // ecx
  unsigned int v109; // eax
  int v110; // esi
  unsigned int v111; // ecx
  _WORD *v112; // edi
  int v113; // ecx
  char *v114; // [esp+Ch] [ebp-100h]
  int v115; // [esp+Ch] [ebp-100h]
  int v116; // [esp+Ch] [ebp-100h]
  int v117; // [esp+Ch] [ebp-100h]
  int v118; // [esp+Ch] [ebp-100h]
  int v119; // [esp+Ch] [ebp-100h]
  int v120; // [esp+Ch] [ebp-100h]
  int v121; // [esp+Ch] [ebp-100h]
  int v122; // [esp+Ch] [ebp-100h]
  int v123; // [esp+10h] [ebp-FCh]
  int v124; // [esp+10h] [ebp-FCh]
  char *v125; // [esp+14h] [ebp-F8h]
  char v126; // [esp+1Ah] [ebp-F2h]
  char v127; // [esp+1Bh] [ebp-F1h]
  int v128; // [esp+1Ch] [ebp-F0h]
  _WORD *v129; // [esp+20h] [ebp-ECh]
  int v130; // [esp+24h] [ebp-E8h]
  int *v131; // [esp+28h] [ebp-E4h]
  char v132; // [esp+2Ch] [ebp-E0h]

  // Read the 2 texture pointers
  v12 = *a7;
  v11 = *a8;

  // Clear the 2 texture pointers
  // They will be reused as outputs
  *a7 = 0;
  *a8 = 0;

  if ( !v12 ) {
    return a8;
  }

  //FIXME: Unknown
  v127 = 0;
  v126 = 0;

  // Load default material?
  v13 = sub_48E680(aDataDefaultMat);

  // Unknown
  v131 = (int *)v13;
  sub_408FB0((unsigned int)v12, (int)v13);
  *a7 = v13;
  v125 = &v132;


  // If a10 bit 0x10 is set, double the width
  v128 = a3;
  if ( a10 & 0x10 ) {
    v127 = 1;
    v128 = 2 * a3;
    if ( 2 * a3 > a5 )
      a5 = sub_445C90(2 * a3);
  }

  // If a10 bit 0x01 is set, double the height
  v130 = a4;
  if ( a10 & 1 ) {
    v126 = 1;
    v130 = 2 * a4;
    if ( 2 * a4 > a6 )
      a6 = sub_445C90(2 * a4);
  }

  //FIXME: Unknown, but probably allocates space for texture data?
  v129 = (_WORD *)sub_408E60((unsigned int)v12, 2 * a5 * a6);

  // Unknown, something to do with material
  sprintf(v13, aRovermatic);

  // Unknown, something to do with material
  *(float *)(v13 + 10) = (double)v128 / (double)a5;
  *(float *)(v13 + 14) = (double)v130 / (double)a6;

  // Unknown
  *((_DWORD *)v13 + 16) = 0;

  // Set up material information?
  //FIXME: What is this condition?
  if ( (a1 != 0 || a2 != 3) &&
       (a1 != 5 || a2 != 1 && a2 != 3) &&
       (a1 != 4) &&
       (a1 != 3 || a2 != 0) ) {
    *((_DWORD *)v13 + 19) = 5;
    *((_DWORD *)v13 + 20) = 5;
    *((_DWORD *)v13 + 21) = 5;
    *((_DWORD *)v13 + 17) = 2;
    *((_DWORD *)v13 + 18) = 16;
    *((_DWORD *)v13 + 28) = 1;
    *((_DWORD *)v13 + 22) = 11;
    *((_DWORD *)v13 + 23) = 6;
    *((_DWORD *)v13 + 24) = 1;
    *((_DWORD *)v13 + 29) = 0;
    *((_DWORD *)v13 + 25) = 3;
    *((_DWORD *)v13 + 26) = 3;
    *((_DWORD *)v13 + 27) = 3;
    *((_DWORD *)v13 + 30) = 7;
    *((_DWORD *)v13 + 31) = 1;
  } else {
    *((_DWORD *)v13 + 18) = 16;
    *((_DWORD *)v13 + 19) = 4;
    *((_DWORD *)v13 + 20) = 4;
    *((_DWORD *)v13 + 17) = 2;
    *((_DWORD *)v13 + 21) = 4;
    *((_DWORD *)v13 + 28) = 4;
    *((_DWORD *)v13 + 22) = 12;
    *((_DWORD *)v13 + 23) = 8;
    *((_DWORD *)v13 + 24) = 4;
    *((_DWORD *)v13 + 29) = 0;
    *((_DWORD *)v13 + 25) = 4;
    *((_DWORD *)v13 + 26) = 4;
    *((_DWORD *)v13 + 27) = 4;
    *((_DWORD *)v13 + 30) = 4;
    *((_DWORD *)v13 + 31) = 2;
  }

  v16 = a5;
  v114 = v12;

  // Move texture dimensions to material?
  v131[32] = a5;
  v131[33] = a6;

  //FIXME: Unknown
  v131[34] = 1;
  v131[35] = 0;

  //FIXME: Fill some data block
  *((_DWORD *)v125 + 0) = 0;
  *((_DWORD *)v125 + 1) = 0;
  *((_DWORD *)v125 + 2) = 0;
  *((_DWORD *)v125 + 3) = a5;
  *((_DWORD *)v125 + 4) = a6;
  *((_DWORD *)v125 + 5) = 2 * a5 * a6;
  *((_DWORD *)v125 + 6) = 2 * a5;
  *((_DWORD *)v125 + 7) = a5;
  qmemcpy(v125 + 32, (int)(v13 + 68), 0x38u);
  *((_DWORD *)v125 + 22) = v129;
  *((_DWORD *)v125 + 23) = 0;

  v19 = v12;
  v18 = v129;

  if ( a1 == 4 && a2 == 0 ) {
    v20 = a4;
    v21 = 0;

    // Check height
    if ( a4 <= 0 ) {
      goto LABEL_31;
    }

    //FIXME: v24 should be set to zero here, because the last value in ecx
    //       was v21, which has been set to 0.

    v22 = a4;
    v124 = a4;
    do {

      i = 0;
      while(i < a3) {
        v18[0] = ((unsigned int)(unsigned __int8)*v19 >> 4) | 16 * (((unsigned int)(unsigned __int8)*v19 >> 4) | 16 * (((unsigned int)(unsigned __int8)*v19 >> 4) | 16 * (((unsigned __int8)*v19 >> 4) & 0xF)));
        v24 = *v19++ & 0xF;
        v18[1] = v24 | 16 * (v24 | 16 * (v24 | 16 * (v24 & 0xF)));
        v18 += 2;

        i += 2;
      }

      v16 = a5;

      if ( i < a5 ) {
        v25 = a5 - i;
        v26 = (unsigned int)(a5 - i) >> 1;
        memset(v18, 0, 4 * v26);
        v27 = &v18[2 * v26];
        v18 += v25;

        if ( v25 & 1 ) {
          *v27 = 0;
          ++v27;
        }

      }

      --v22;
    }
    while ( v22 );

    goto LABEL_30;
  }


  v21 = a1;
  if ( a1 != 3 || a2 != 0) {
    if ( a1 != 4 || a2 != 1 ) {
      

      if ( a1 == 2 ) {

        if ( a2 == 0 ) {
          v20 = a4;
          v21 = 0;
          if ( a4 > 0 )
          {
            v118 = a4;
            v124 = a4;
            do
            {
              for ( j = 0; j < a3; j += 2 )
              {
                v18 += 2;
                LOBYTE(v64) = *(_WORD *)(v11 + 2 * ((unsigned int)(unsigned __int8)*v19 >> 4)) >> 8;
                HIBYTE(v64) = *(_WORD *)(v11 + 2 * ((unsigned int)(unsigned __int8)*v19 >> 4));
                *(v18 - 2) = (v64 << 15) | (v64 >> 1);
                v65 = *v19++ & 0xF;
                LOBYTE(v64) = *(_WORD *)(v11 + 2 * v65) >> 8;
                HIBYTE(v64) = *(_WORD *)(v11 + 2 * v65);
                *(v18 - 1) = (v64 << 15) | (v64 >> 1);
              }
              v16 = a5;
              if ( j < a5 )
              {
                v66 = a5 - j;
                v67 = (unsigned int)(a5 - j) >> 1;
                memset(v18, 0, 4 * v67);
                v68 = &v18[2 * v67];
                v69 = v66 & 1;
                v18 += v66;
                while ( v69 )
                {
                  *v68 = 0;
                  ++v68;
                  --v69;
                }
                v16 = a5;
              }
              --v118;
            }
            while ( v118 );
            goto LABEL_30;
          }
          goto LABEL_31;
        }

        if ( a2 == 1 )
        {
          v20 = a4;
          v21 = 0;
          if ( a4 > 0 )
          {
            v119 = a4;
            v124 = a4;
            do
            {
              v70 = a3;
              v71 = 0;
              if ( a3 > 0 )
              {
                v71 = a3;
                do
                {
                  v72 = (unsigned __int8)*v19++;
                  ++v18;
                  LOBYTE(v73) = *(_WORD *)(v11 + 2 * v72) >> 8;
                  HIBYTE(v73) = *(_WORD *)(v11 + 2 * v72);
                  --v70;
                  *(v18 - 1) = (v73 << 15) | (v73 >> 1);
                }
                while ( v70 );
              }
              v16 = a5;
              if ( v71 < a5 )
              {
                v74 = a5 - v71;
                v75 = (unsigned int)(a5 - v71) >> 1;
                memset(v18, 0, 4 * v75);
                v76 = &v18[2 * v75];
                v77 = v74 & 1;
                v18 += v74;
                while ( v77 )
                {
                  *v76 = 0;
                  ++v76;
                  --v77;
                }
                v16 = a5;
              }
              --v119;
            }
            while ( v119 );
            goto LABEL_30;
          }
          goto LABEL_31;
        }
      }

      if ( a1 == 5 )
      {
        if ( a2 == 1 )
        {
          v20 = a4;
          v21 = 0;
          if ( a4 > 0 )
          {
            v78 = a4;
            v124 = a4;
            do
            {
              v79 = a3;
              v80 = 0;
              if ( a3 > 0 )
              {
                v80 = a3;
                do
                {
                  ++v18;
                  v81 = ((unsigned int)(unsigned __int8)*v19++ >> 4 << 12) | 0xFFF;
                  *(v18 - 1) = v81;
                  --v79;
                }
                while ( v79 );
              }
              v16 = a5;
              if ( v80 < a5 )
              {
                v82 = a5 - v80;
                do
                {
                  *v18 = *(v18 - 1);
                  ++v18;
                  --v82;
                }
                while ( v82 );
              }
              --v78;
            }
            while ( v78 );
            goto LABEL_30;
          }
          goto LABEL_31;
        }

        if ( a2 == 2 )
        {
          v20 = a4;
          v21 = 0;
          if ( a4 > 0 )
          {
            v83 = a4;
            v124 = a4;
            do
            {
              v84 = a3;
              v85 = 0;
              if ( a3 > 0 )
              {
                v85 = a3;
                do
                {
                  ++v18;
                  --v84;
                  *(v18 - 1) = *(_WORD *)v114 | 0x8000;
                  v114 += 2;
                }
                while ( v84 );
              }
              v16 = a5;
              if ( v85 < a5 )
              {
                v86 = a5 - v85;
                do
                {
                  *v18 = *(v18 - 1);
                  ++v18;
                  --v86;
                }
                while ( v86 );
              }
              --v83;
            }
            while ( v83 );
            goto LABEL_30;
          }
          goto LABEL_31;
        }
      }

      if ( a1 != 0 || a2 != 2 ) {

        if ( a1 == 5 ) {
          if ( a2 == 3 ) {
            v20 = a4;
            v21 = 0;
            if ( a4 > 0 )
            {
              v120 = a4;
              v124 = a4;
              do
              {
                v96 = a3;
                v97 = 0;
                if ( a3 > 0 )
                {
                  v97 = a3;
                  do
                  {
                    v98 = *(_DWORD *)v12;
                    v12 += 4;
                    ++v18;
                    --v96;
                    *(v18 - 1) = ((unsigned __int8)v98 >> 4) | 16
                                                             * (((unsigned __int16)v98 >> 12) | 16
                                                                                              * ((v98 >> 20) & 0xF | 16 * (v98 >> 28)));
                  }
                  while ( v96 );
                }
                v16 = a5;
                if ( v97 < a5 )
                {
                  v99 = a5 - v97;
                  do
                  {
                    *v18 = *(v18 - 1);
                    ++v18;
                    --v99;
                  }
                  while ( v99 );
                }
                --v120;
              }
              while ( v120 );
              goto LABEL_30;
            }
            goto LABEL_31;
          }

          if ( a2 == 7 ) {
            v20 = a4;
            v21 = 0;
            if ( a4 > 0 )
            {
              v121 = a4;
              v124 = a4;
              do
              {
                v100 = a3;
                v101 = 0;
                if ( a3 > 0 )
                {
                  v101 = a3;
                  do
                  {
                    v102 = *(_DWORD *)v19;
                    ++v18;
                    v103 = *(_DWORD *)v19;
                    v104 = (*(_DWORD *)v19 >> 19) | 0xFFE0;
                    v19 += 3;
                    --v100;
                    *(v18 - 1) = ((unsigned __int8)v102 >> 3) | 32 * (((unsigned __int16)v103 >> 11) | 32 * v104);
                  }
                  while ( v100 );
                }
                v16 = a5;
                if ( v101 < a5 )
                {
                  v105 = a5 - v101;
                  do
                  {
                    *v18 = *(v18 - 1);
                    ++v18;
                    --v105;
                  }
                  while ( v105 );
                }
                --v121;
              }
              while ( v121 );
              goto LABEL_30;
            }
            goto LABEL_31;
          }
        }

        if ( a1 != 0 || a2 != 3 ) {
          v21 = v123;
          v20 = a4;
        } else {
          v20 = a4;
          if ( a4 > 0 )
          {
            v122 = a4;
            v124 = a4;
            do
            {
              v106 = a3;
              v107 = 0;
              if ( a3 > 0 )
              {
                v107 = a3;
                do
                {
                  v108 = *(_DWORD *)v12;
                  v12 += 4;
                  ++v18;
                  v109 = ((v108 & 0xFF0000 | (v108 >> 16)) >> 8) | (((v108 << 16) | v108 & 0xFF00) << 8);
                  --v106;
                  *(v18 - 1) = ((unsigned __int16)v109 >> 12) | 16
                                                              * ((v109 >> 20) & 0xF | 16
                                                                                    * ((v109 >> 28) | 16 * (v109 >> 4)));
                }
                while ( v106 );
              }
              v16 = a5;
              if ( v107 < a5 )
              {
                v110 = a5 - v107;
                v111 = (unsigned int)(a5 - v107) >> 1;
                memset(v18, 0, 4 * v111);
                v112 = &v18[2 * v111];
                v113 = v110 & 1;
                v18 += v110;
                while ( v113 )
                {
                  *v112 = 0;
                  ++v112;
                  --v113;
                }
                v16 = a5;
              }
              --v122;
            }
            while ( v122 );
            goto LABEL_30;
          }
        }


        goto LABEL_31;
      }

      v20 = a4;
      if ( a4 > 0 )
      {
        v87 = a4;
        v124 = a4;
        do
        {
          v88 = a3;
          v89 = 0;
          if ( a3 > 0 )
          {
            v89 = a3;
            do
            {
              ++v18;
              v90 = *(_WORD *)v114;
              v114 += 2;
              LOBYTE(v91) = HIBYTE(v90);
              HIBYTE(v91) = v90;
              --v88;
              *(v18 - 1) = (v91 << 15) | (v91 >> 1);
            }
            while ( v88 );
          }
          v16 = a5;
          if ( v89 < a5 )
          {
            v92 = a5 - v89;
            v93 = (unsigned int)(a5 - v89) >> 1;
            memset(v18, 0, 4 * v93);
            v94 = &v18[2 * v93];
            v95 = v92 & 1;
            v18 += v92;
            while ( v95 )
            {
              *v94 = 0;
              ++v94;
              --v95;
            }
            v16 = a5;
          }
          --v87;
        }
        while ( v87 );
        goto LABEL_30;
      }
    }
    else if ( a9 == 1 )
    {
      v20 = a4;
      v21 = 0;
      if ( a4 > 0 )
      {
        v117 = a4;
        v124 = a4;
        do
        {
          v47 = a3;
          v48 = 0;
          if ( a3 > 0 )
          {
            v48 = a3;
            do
            {
              ++v18;
              v49 = (unsigned int)(unsigned __int8)*v19 >> 4;
              v50 = (unsigned __int8)*v19++ >> 4;
              --v47;
              *(v18 - 1) = v49 | 16 * (v49 | 16 * (v49 | 16 * (v50 & 0xF)));
            }
            while ( v47 );
          }
          v16 = a5;
          if ( v48 < a5 )
          {
            v51 = (unsigned int)(a5 - v48) >> 1;
            memset(v18, 0, 4 * v51);
            v52 = &v18[2 * v51];
            v53 = ((_BYTE)a5 - (_BYTE)v48) & 1;
            v18 += a5 - v48;
            while ( v53 )
            {
              *v52 = 0;
              ++v52;
              --v53;
            }
            v16 = a5;
          }
          --v117;
        }
        while ( v117 );
        goto LABEL_30;
      }
    }
    else
    {
      v20 = a4;
      v21 = 0;
      if ( a4 > 0 )
      {
        v54 = a4;
        v124 = a4;
        do
        {
          v55 = a3;
          v56 = 0;
          if ( a3 > 0 )
          {
            v56 = a3;
            do
            {
              ++v18;
              v57 = (unsigned int)(unsigned __int8)*v19 >> 4;
              v58 = (unsigned int)(unsigned __int8)*v19++ >> 4;
              --v55;
              *(v18 - 1) = v57 | 16 * (v57 | 16 * (v58 | 0xFFF0));
            }
            while ( v55 );
          }
          v16 = a5;
          if ( v56 < a5 )
          {
            v59 = a5 - v56;
            v60 = (unsigned int)(a5 - v56) >> 1;
            memset(v18, 0, 4 * v60);
            v61 = &v18[2 * v60];
            v62 = v59 & 1;
            v18 += v59;
            while ( v62 )
            {
              *v61 = 0;
              ++v61;
              --v62;
            }
            v16 = a5;
          }
          --v54;
        }
        while ( v54 );
        goto LABEL_30;
      }
    }
  }
  else
  {
    v20 = a4;
    v21 = 0;
    if ( a4 > 0 )
    {
      v40 = a4;
      v124 = a4;
      do
      {
        for ( k = 0; k < a3; k += 2 )
        {
          v18 += 2;
          *(v18 - 2) = ((unsigned __int8)(*v19 & 0xF0) << 8) | 0xFFF;
          v42 = ((*v19++ & 0xF) << 12) | 0xFFF;
          *(v18 - 1) = v42;
        }
        v16 = a5;
        if ( k < a5 )
        {
          v43 = a5 - k;
          v44 = (unsigned int)(a5 - k) >> 1;
          memset(v18, 0, 4 * v44);
          v45 = &v18[2 * v44];
          v46 = v43 & 1;
          v18 += v43;
          while ( v46 )
          {
            *v45 = 0;
            ++v45;
            --v46;
          }
          v16 = a5;
        }
        --v40;
      }
      while ( v40 );
LABEL_30:
      v20 = a4;
      v21 = v124;
      goto LABEL_31;
    }
  }

LABEL_31:
  v29 = a3;

  //FIXME: for-loop from 0 to `a6 - v21` ?
  if ( v21 < a6 ) {
    v115 = a6 - v21;
    do {

      // FIXME: for-loop from 0 to `v16` ?
      if ( v16 > 0 ) {
        v30 = v16;
        do {
          *v18 = v18[-a3];
          ++v18;

          --v30;
        }
        while ( v30 );
      }

      --v115;
    }
    while ( v115 );
  }

  if ( v127 )
  {
    v32 = v129;
    v33 = v128;
    v34 = &v129[v128 - 1];
    if ( v20 <= 0 )
      goto LABEL_50;
    v116 = v20;
    do
    {
      if ( v29 > 0 )
      {
        v35 = v29;
        do
        {
          v36 = *v32;
          ++v32;
          *v34 = v36;
          --v34;
          --v35;
        }
        while ( v35 );
        v33 = v128;
      }
      v34 += v16 + v29;
      v32 += v16 - v29;
      --v116;
    }
    while ( v116 );
  }
  else
  {
    v33 = v128;
  }
  v32 = v129;
LABEL_50:
  if ( v126 )
  {
    v37 = &v32[v16 * (v130 - 1)];
    if ( v20 > 0 )
    {
      do
      {
        if ( v33 > 0 )
        {
          v38 = v33;
          do
          {
            v39 = *v32;
            ++v32;
            *v37 = v39;
            ++v37;
            --v38;
          }
          while ( v38 );
        }
        v37 -= v33 + v16;
        --v20;
        v32 += v16 - v33;
      }
      while ( v20 );
    }
  }
  sub_48AA40(v131[36]);
  return sub_48A5E0((_DWORD *)v131[36], &v125, 1u, v131[31]);
}


























//----- (00445C90) --------------------------------------------------------
// Calculate texture POT width or height from non-POT size
// Results smaller than 16 will be raised to 16
int __cdecl sub_445C90(int32_t a1) {

  // Find leading 1 bit
  int32_t bit = 0x40000000;
  for(int32_t i = 0; i < 31; i++) {
    int32_t hit = a1 & bit;
    bit >>= 1;
    if (hit) {
      break;
    }
  }

  // Get bit which has hit
  // In case none (`input = 0`) or the the last bit hit (`input = 1`) we will
  // get 0 here
  int32_t result = bit << 1;

  // If we are lower than the input, we take the next higher POT
  // For example: input = 0, bit = 0, result = 0 => ok: 0
  //              input = 1, bit = 0, result = 0 => too small, after shift: 0
  //              input = 2, bit = 1, result = 2 => ok: 2
  //              input = 3, bit = 1, result = 2 => too small; after shift: 4
  //              input = 4, bit = 2, result = 4 => too small; after shift: 8
  //              input = 5, bit = 2, result = 4 => too small; after shift: 8
  //              input = 6, bit = 2, result = 4 => too small; after shift: 8
  //              input = 7, bit = 2, result = 4 => too small; after shift: 8
  //              input = 8, bit = 4, result = 8 => ok: 8
  //              ...
  if ( result < a1 ) {
    result <<= 1;
  }

  // Result must be at least 16
  if (result < 16) {
    result = 16;
  }
  return result;
}




//----- (00446C20) --------------------------------------------------------
// Loads the pixel data for a texture chunk for a model
// a1 = Pointer to pointer to mandatory texture data [part of some model structure?]
// a2 = Pointer to pointer to optional texture data [part of some model structure?]
typedef struct {
  uint8_t unk_pad0[3]; // +0
  uint8_t unk3; // +3
} A1Unk; // SWR_MODEL_Section5_b
typedef struct {
  uint8_t unk_pad_neg56[12]; // -56 (-14*4) // 0x0
  uint8_t unk_neg44; // -44 (-14*4 + 12) // 0xC
  uint8_t unk_neg43; // -43 (-14*4 + 13) // 0xD
  uint8_t unk_pad_neg42[2]; // -42 // 0xE
  uint16_t unk_neg40; // -40 // 0x10
  uint16_t unk_neg38; // -38 // 0x12
  uint8_t unk_pad_neg36[8]; // -36 // 0x14
  A1Unk* unk_neg28; // -28 (-14*4 + 28) //  0x1C
  uint8_t unk_pad_neg24[24]; // -24 // 0x20
  void* texture_data; // 0 [a1 points here] // 0x38
  void* optional_texture_data; // 4 [a2 should point here] // 0x3C
} A1; // Model structure, SWR_MODEL_Section5 
char *__cdecl sub_446C20(uint32_t* _a1, uint32_t* _a2) {

  //FIXME: Do some upcast of the a1 and a2 arguments here
  A1* a1 = UPCAST(_a1, A1,texture_data);

  uint16_t v4 = swap16(a1->unk_neg40);

  if (a1->unk_neg28) {
    uint16_t v3 = swap16(a1->unk_neg38);

    // Get width and height?
    int v6 = sub_445C90(v4);
    int v7 = sub_445C90(v3);

    // Process texture data
    sub_445EE0(
      a1->unk_neg44, // ?
      a1->unk_neg43, // ?
      v4, // Width shift factor?
      v3, // Height shift factor?
      v6, // Width
      v7, // Height
      _a1, // Texture data
      _a2, // Optional texture data
      1, // ?
      a1->unk_neg28->unk3); // ?
  }

  //FIXME: Broken RE? I doubt they just write a random pixel in the texture data..
  //FIXME: Actually.. I think a1->texture_data might point to something else when returning from sub_445EE0
  uint32_t* result = a1->texture_data;
  *(uint32_t *)((uintptr_t)a1->texture_data + 10) = &a1->unk_neg56[0];

  return result;
}











//----- (00447490) --------------------------------------------------------
// Called from the model loader to (presumably) load a texture
// a1 = ???
// a2 = texture index
// a3 = Output: Pointer to mandatory texture data
// a4 = Output: Pointer to optional texture data
void __usercall sub_447490(int a1@<ebp>, int a2, uint32_t* a3, uint32_t* a4) {
  uint32_t v8[3]; // [esp+Ch] [ebp-Ch]

  // Check texture index boundaries
  if ( a2 < 0 || a2 >= dword_E9823C ) {
    *a3 = 0;
    *a4 = 0;
    return;
  }

  // Load texture from cache
  uint32_t* v4 = dword_E93860[a2];
  if (v4) {
    *a3 = v4[0]; // Pointer to mandatory data
    *a4 = v4[1]; // Pointer to optional data
    return;
  }

  // Read texture offset table
  sub_42D640(3, 8 * a2 + 4, v8, 3 * 4);
  for(int32_t v6 = 0; v6 < 3; v6++) {
    v8[v6] = swap32(v8[v6]);
  }

  // Read texture data from file offsets
  // This sets a3 and a4
  sub_447370(v8, a3, a4);

  // Load texture pixel data for this texture chunk
  sub_446C20(a3, a4);

  // Add texture to cache
  dword_E93860[a2] = a3;

  // Keep track of some special textures?
  if ( a2 == 1257 ) {
    dword_50C620 = a3[0];
  } else if ( a2 == 1258 ) {
    dword_50C624 = a3[0];
  } else if ( a2 == 936 ) {
    dword_50C618 = a3[0];
  } else if ( a2 == 352 ) {
    dword_50C61C = a3[0];
  } else if ( a2 == 118 ) {
    sub_431DF0(a4, a1, a3[0]);
  }

  return;
}
