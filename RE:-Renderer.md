# Create projection-matrix

*(left unused with XYZRHW?!)*

This works very similar to https://msdn.microsoft.com/en-us/library/windows/desktop/bb205350(v=vs.85).aspx , just that the aspect ratio is applied in the X axis instead of Y axis.

```C
//----- (0048B260) --------------------------------------------------------
// a1 = fovY
// a2 = aspectRatio
// a3 = znear
// a4 = zfar
int __cdecl sub_48B260(float a1, float a2, float a3, float a4) {
  // zrange
  float v11 = a4 - a3;
  if ( fabs(v11) < 0.009999999776482582 )
    return 0x80070057;

  // First part of cotangent
  float v7 = sin(a1 * 0.5);
  if ( fabs(v7) < 0.009999999776482582 )
    return 0x80070057;

  // Get cot(fovY/2)
  float v8 = cos(a1 * 0.5) / v7;

  // Prepare the matrix
  float m[4*4]; // v12
  memset(m, 0x00, sizeof(m));
  m[0] = a2 * v8; // xScale = aspectRatio * cot(fovY/2)
  m[5] = v8; // yScale = cot(fovY/2)
  m[10] = a4 / v11; // zf/(zf-zn)
  m[11] = 1.0;
  m[14] = -(m[10] * a3); // -zn*zf/(zf-zn) 

  // Set D3D projection matrix
  return (*(int (__stdcall **)(int, signed int, float *))(*(_DWORD *)dword_52E644 + 100))(dword_52E644, 3, m);
}
```

# Prepare for draw

`sub_492FF0` in demo

```C
//----- (0048DF30) --------------------------------------------------------
unsigned int __cdecl sub_48DF30(unsigned int a1, float *a2) {
  unsigned int result; // eax
  float *v3; // esi
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // edi
  unsigned int v15; // ecx
  __int16 v16; // dx
  unsigned int v17; // ebx
  int v18; // edx
  double v21; // st7
  float v22; // ST2C_4
  bool v25; // zf
  double v26; // st7
  float v27; // eax
  float v28; // edx
  float v29; // ST4C_4
  signed int v32; // edx
  float v33; // ST4C_4
  float v37; // ST4C_4
  float v41; // ST4C_4
  int v44; // edx
  unsigned int v45; // edx
  float v46; // ST44_4
  char v49; // dl
  float v50; // ST44_4
  signed int v53; // edi
  float v54; // ST44_4
  unsigned int v57; // eax
  int v58; // edi
  signed __int16 v59; // dx
  _WORD *v60; // eax
  int v61; // eax
  unsigned int v62; // ebx
  int v63; // [esp+0h] [ebp-68h]
  int v64; // [esp+4h] [ebp-64h]
  int v65; // [esp+10h] [ebp-58h]
  int v66; // [esp+14h] [ebp-54h]
  __int16 v67; // [esp+18h] [ebp-50h]
  unsigned int v68; // [esp+1Ch] [ebp-4Ch]
  signed __int16 v69; // [esp+1Ch] [ebp-4Ch]
  int v71; // [esp+20h] [ebp-48h]
  signed int v72; // [esp+24h] [ebp-44h]
  int v73; // [esp+2Ch] [ebp-3Ch]
  signed __int16 v74; // [esp+2Ch] [ebp-3Ch]
  int v75; // [esp+30h] [ebp-38h]
  int v76; // [esp+30h] [ebp-38h]
  int v77; // [esp+34h] [ebp-34h]
  int v78; // [esp+38h] [ebp-30h]
  int v79; // [esp+3Ch] [ebp-2Ch]
  unsigned int v80; // [esp+40h] [ebp-28h]
  int v81; // [esp+44h] [ebp-24h]
  int v82; // [esp+48h] [ebp-20h]
  int v83; // [esp+4Ch] [ebp-1Ch]
  float v84; // [esp+50h] [ebp-18h]
  float v85; // [esp+54h] [ebp-14h]
  float v86; // [esp+58h] [ebp-10h]
  int v87; // [esp+5Ch] [ebp-Ch]
  int v88; // [esp+60h] [ebp-8h]
  int v89; // [esp+64h] [ebp-4h]
  int v90; // [esp+74h] [ebp+Ch]

  // Setup D3D projection matrix
  sub_48B260(
    *(float *)(dword_DF7F2C + 56),
    *(float *)(dword_DF7F2C + 64),
    *(float *)(*(_DWORD *)(dword_DF7F2C + 72) + 4),
    *(float *)(*(_DWORD *)(dword_DF7F2C + 72) + 8));

  sub_49EA00();
  result = a1;
  v3 = a2;
  for(int v80 = 0; v80 < a1; v80++) {
    uint32_t v4 = *v3;
    v90 = 19;
    v66 = v4;
    v64 = v4 & 2;

    if (v4 & 2) {
      v90 = 531;
    }
    if (v4 & 4) {
      BYTE1(v90) |= 8u;
    }
    if (v4 & 8) {
      BYTE1(v90) |= 0x10u;
    }
    if (!(v4 & 0x10)) {
      v90 |= 0x80;
    }
    if (v4 & 0x20) {
      BYTE1(v90) |= 0x20u;
    }
    if (BYTE1(v4) & 3) {
      BYTE1(v90) |= 0x80u;
    }

    v10 = *((_DWORD *)v3 + 7);
    v63 = *((_DWORD *)v3 + 7);
    if ( v10 ) {
      v11 = *(_DWORD *)(v10 + 124);
      if ( v11 ) {
        v12 = v90;
        BYTE1(v12) |= 4u;
        v90 = v12;
      }
      v13 = *(_DWORD *)(v10 + 144);
      sub_48E5F0(*(_DWORD **)(v10 + 144), v11);
      v65 = *(_DWORD *)(v13 + 128);
    } else {
      v65 = 0;
    }

    v14 = 0;
    v15 = 0;
    v83 = 0;
    dword_A530D0 = 0;
    dword_5430C0 = *(_DWORD *)(*(_DWORD *)(dword_DF7F2C + 72) + 4);
    do {
      v68 = *((_DWORD *)v3 + 2);
      dword_5430C4 = *((_DWORD *)v3 + 4);
      dword_AF30DC = *((_DWORD *)v3 + 6);
      v16 = v15;
      v67 = v15;
      v72 = *((_DWORD *)v3 + 1);
      if ( v72 >= dword_ECC424 ) {
        v72 = dword_ECC424;
      }
      
      v73 = 0;
      v75 = 0;



      for(v17 = 0; v17 < v68; v17++) {
        v18 = v75 + dword_5430C4;
        float* v19 = dword_AF30DC + v73;

        // Generate output address (v15 = vertex index, 32 = stride)
        struct {
          float x; // 0
          float y; // 4
          float z; // 8
          float rhw; // 12
          uint32_t color1; // 16
          uint32_t color2; // 20
          float u; // 24
          float v; // 28
        }* v20 = &unk_B6B0E8[v15]; // unk_B6B0E8 is of the outputvertex type too

        // Copy X and Y
        v20->x = *(_DWORD *)(v75 + dword_5430C4);
        v20->y = *(_DWORD *)(v18 + 4);

        // Generate RHW
        if ( *(float *)(v18 + 8) == 0.0 ) {
          v21 = 0.0;
        } else {
          v21 = (2.0 - *(float *)(v18 + 8) * COERCE_FLOAT(2130706432 - *(_DWORD *)(v18 + 8)))
              * COERCE_FLOAT(2130706432 - *(_DWORD *)(v18 + 8));
        }

        // Copy Z and RHW
        if ( *(float *)(v18 + 8) == *(float *)&dword_5430C0 ) {
          v20->z = 0.0;
        } else {
          v20->z = 1.0 - v21 * *(float *)&dword_5430C0;
        }
        v20->rhw = v21;

        // Probably something to do with colors or alpha blending
        if ( v66 & 0x200 ) {
          if ( *(float *)(v18 + 8) > (double)*(float *)&flt_EC8578 ) {
            if ( *(float *)(v18 + 8) < (double)*(float *)&flt_EC857C ) {
              v22 = (1.0 - (*(float *)(v18 + 8) - *(float *)&flt_EC8578) * flt_EC8574) * 255.0;
              v79 = (signed int)_frndint(v22);
              v20->color2 = (v79 << 24) | 0xFFFFFF;
            } else {
              v20->color2 = 0x00FFFFFF;
            }
          } else{
            v20->color2 = 0xFFFFFFFF;
          }
        }

        if ( v72 <= 0 ) {
          v84 = 1.0;
          v85 = 1.0;
          v86 = 1.0;
          v26 = *(float *)(dword_AF30DC + 12);
          goto LABEL_44;
        } else if ( v72 == 3 ) {
          v25 = *((float*)v3 + 12) == 1.0f;
          v86 = v19[0] + v3[9];
          v85 = v19[1] + v3[10];
          v84 = v19[2] + v3[11];
          v26 = v19[3];
          if ( !v25 ) {
            v26 = v26 + v3[12];
          }
        } else {
          v86 = v19[0];
          v27 = v19[1];
          v28 = v19[2];
          v26 = v19[3];
          v85 = v27;
          v84 = v28;
        }

        v86 = MIN(v86, 1.0);
        v85 = MIN(v85, 1.0);
        v84 = MIN(v84, 1.0);
        v26 = MIN(v26, 1.0);

        // Convert some colors from float to integer
        if ( v64 ) {
          v29 = v26 * 255.0;
          v89 = (signed int)_frndint(v29);

          v33 = v86 * 255.0;
          v88 = (signed int)_frndint(v33);

          v37 = v85 * 255.0;
          v82 = _frndint(v37);

          v41 = v84 * 255.0;
          v78 = (signed int)_frndint(v41);

          // This was originally: v45 = ((v40 | ((v36 | (v32 << 8)) << 8)) << 8) | (signed int)_ST7;
          v45 = (v89 << 24) | (v88 << 16) | (v82 << 8) | v78;
        }  else {
          v46 = v86 * 255.0;
          v87 = _frndint(v46);

          v50 = v85 * 255.0;
          v81 = (signed int)_frndint(v50);

          v54 = v84 * 255.0;
          v77 = (signed int) _frndint(v54);

          // Originally: v45 = (signed int)_ST7 | ((v53 | ((*(_DWORD *)&v49 | 0xFFFFFF00) << 8)) << 8);
          v45 = (0xFF << 24) | (v87 << 16) | (v81 << 8) | v77;
        }
        v20->color1 = v45;

        // Copy UV
        v20->u = *(float *)(*((_DWORD *)v3 + 5) + 8 * v17) + v3[14];
        v20->v = *(float *)(*((_DWORD *)v3 + 5) + 8 * v17 + 4) + v3[15];

        v75 += 12;
        v73 += 16;

        // Generate next index
        v15 = ++dword_A530D0;
      }

      v16 = v67;
      v14 = v83;

      v57 = *((_DWORD *)v3 + 2);
      if ( v57 <= 3 ) {
        // Emit indices for triangle
        word_AF30E8[v14] = v16;
        word_AF30EA[v14] = v16 + 1;
        word_AF30EC[v14] = v16 + 2;
        v14 += 3;
        v83 = v14;
      } else {
        int v58 = v57 - 2;
        v59 = 0;
        v74 = 1;
        v69 = v57 - 1;

        v60 = (_WORD *)(2 * v83 + 0xAF30E8);
        v83 += v58 + 2 * v71;

        int v76 = 0;
        for(v76 = 0; v76 < v71; v76++) {
          v60[0] = v67 + v59;
          v60[1] = v67 + v74;
          v60[2] = v67 + v69;
          v60 += 3;
          if (!((_BYTE)v76 & 1) {
            v59 = v74++;
          } else {
            v59 = v69--;
          }
        }
        v14 = v83;
      }
      v61 = *((_DWORD *)v3 + 18);
      v3 += 16;
      v62 = v80 + 1;
    } while ( v61 + v14 + 2 * v61 - 6 < (unsigned int)dword_52E624
         && v62 < a1
         && v63 == *((_DWORD *)v3 + 7)
         && v66 == *(_DWORD *)v3 );

    // Do the drawing
    sub_48A350(v65, v90, (int)&unk_B6B0E8, v15, (int)word_AF30E8, v14);
    result = a1;
  }
  return result;
}
```

# Draw function

```C
//----- (0048A350) --------------------------------------------------------
// a1 = texture
// a2 = renderstates
// a3 = vertex pointer
// a4 = vertex count
// a5 = index pointer
// a6 = index count
void __cdecl sub_48A350(int a1, int a2, int a3, unsigned int a4, int a5, int a6) {
  // Check if we are below the maximum vertex count
  //FIXME: Not 100% sure
  if ( a4 <= dword_52E624 ) {

    // Prepare renderstates
    sub_48A450(a2);

    // Check if the planned texture is already set, if not, set it
    if ( a1 != dword_52E628 ) {
      //FIXME: This feels like a bug, either in the game or my RE..
      if (!dword_52E644->SetTexture(0, a1)) {
        // Update the current texture
        dword_52E628 = a1;
      }
    }

    // Draw the data
    dword_52E644->DrawIndexedPrimitive(4, 452, a3, a4, a5, a6, 24);
  }
}
```

## Prepare renderstates

```C
//----- (0048A450) --------------------------------------------------------
// a1 = the renderstates to set
void __cdecl sub_48A450(int a1) {

  // Don't worry if all states are already set correctly
  if ( dword_52E610 == a1 ) {
    return;
  }

  if ((dword_52E610 ^ a1) & 0x600 ) {
    if ( a1 & 0x400 ) {
      dword_52E644->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 1);
      dword_52E644->SetRenderState(D3DRENDERSTATE_TEXTUREMAPBLEND, D3DTBLEND_MODULATEALPHA);
    } else {
      if ( a1 & 0x200 ) {
        dword_52E644->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 1);
        dword_52E644->SetRenderState(D3DRENDERSTATE_TEXTUREMAPBLEND, D3DTBLEND_MODULATE);
      } else {
        dword_52E644->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 0);
      }
    }
  }

  if ((dword_52E610 ^ a1) & 0x2000) {
    if ( a1 & 0x2000 ) {
      dword_52E644->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, 0);
    } else {
      dword_52E644->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, 1);
    }
  }

  if ((dword_52E610 ^ a1) & 0x800) {
    if ( a1 & 0x800 ) {
      dword_52E644->SetTextureStageState(0, D3DTSS_ADDRESSU, D3DTADDRESS_CLAMP);
    } else {
      dword_52E644->SetTextureStageState(0, D3DTSS_ADDRESSU, D3DTADDRESS_WRAP);
    }
  }

  if ((dword_52E610 ^ a1) & 0x1000) {
    if ( a1 & 0x1000 ) {
      dword_52E644->SetTextureStageState(0, D3DTSS_ADDRESSV, D3DTADDRESS_CLAMP);
    } else {
      dword_52E644->SetTextureStageState(0, D3DTSS_ADDRESSV, D3DTADDRESS_WRAP);
    }
  }

  if ((dword_52E610 ^ a1) & 0x8000) != 0 ) {
    if ( a1 & 0x8000 && dword_4C98B0 ) {
      dword_52E644->SetRenderState(D3DRENDERSTATE_FOGENABLE, 1);
    } else {
      dword_52E644->SetRenderState(D3DRENDERSTATE_FOGENABLE, 0);
    }
  }

  if ((dword_52E610 ^ a1) & 0x80) != 0) {
    dword_52E610 = a1;
    if ((sub_48B1B0(dword_52E614) != 0)) {
      return;
    }
  }

  // Update the internal state tracker
  dword_52E610 = a1

  return;
}
```