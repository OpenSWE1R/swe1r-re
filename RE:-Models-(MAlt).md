## Parse MAlt

Short little function... NOT!

```C
//----- (004476B0) --------------------------------------------------------
void __cdecl sub_4476B0(signed int *a1) {
  int v2; // ecx
  signed int v3; // eax
  int v4; // edx
  unsigned int v5; // esi
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // ecx
  int v9; // edx
  unsigned int v10; // esi
  unsigned int v11; // ecx
  signed int v12; // edx
  unsigned int *v13; // ecx
  unsigned int v14; // eax
  int v15; // eax
  int v16; // ebp
  int v17; // edi
  int v18; // eax
  int v19; // esi
  __int16 v20; // dx
  __int16 v21; // cx
  int v22; // eax
  __int16 v23; // dx
  __int16 v24; // cx
  __int16 *v25; // eax
  signed int v26; // edx
  __int16 v27; // cx
  __int16 v28; // bx
  __int16 v29; // dx
  __int16 v30; // ax
  __int16 v31; // cx
  __int16 v32; // ax
  __int16 v33; // ax
  __int16 v34; // ax
  __int16 v35; // ax
  int v36; // esi
  int v37; // eax
  unsigned int *v38; // ecx
  __int16 v39; // dx
  signed int v40; // edx
  unsigned int v41; // eax
  unsigned int *v42; // ecx
  signed int v43; // edx
  unsigned int v44; // eax
  int v46; // eax
  int v47; // esi
  __int16 v48; // dx
  unsigned int v49; // ecx
  int v50; // edx
  unsigned int v51; // edi
  unsigned int v52; // ecx
  int v53; // edx
  unsigned int v54; // edi
  unsigned int v55; // ecx
  int v56; // edx
  unsigned int v57; // edi
  unsigned int v58; // ecx
  int v59; // edx
  unsigned int v60; // edi
  unsigned int v61; // ecx
  int v62; // edx
  unsigned int v63; // edi
  unsigned int v64; // ecx
  int v65; // edx
  unsigned int v66; // edi
  unsigned int v67; // ecx
  int v68; // edx
  unsigned int v69; // edi
  unsigned int v70; // ecx
  int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // ecx
  unsigned int *v74; // ecx
  signed int v75; // edx
  unsigned int v76; // eax
  unsigned int *v77; // ecx
  signed int v78; // edx
  unsigned int v79; // eax
  __int16 v80; // cx
  __int16 v81; // dx
  unsigned int *v82; // ecx
  signed int v83; // edx
  unsigned int v84; // eax
  __int16 v85; // cx
  __int16 v86; // ax
  __int16 v87; // cx
  __int16 v88; // ax
  __int16 v89; // dx
  int v90; // ecx
  signed int v91; // ecx
  unsigned int *v92; // edx
  __int16 v94; // cx
  int v95; // eax
  int v96; // edx
  int *v97; // ecx
  int v98; // edi
  _WORD *v99; // edi
  __int16 v100; // dx
  __int16 v101; // cx
  __int16 v102; // cx
  int v103; // eax
  int v104; // edx
  __int16 v105; // cx
  _WORD *v106; // esi
  __int16 v107; // dx
  __int16 v108; // ax
  __int16 v109; // cx
  __int16 v110; // ax
  unsigned int *v111; // ecx
  signed int v112; // edx
  unsigned int v113; // eax
  unsigned int *v114; // ecx
  signed int v115; // edx
  unsigned int v116; // eax
  unsigned int *v117; // ecx
  signed int v118; // edx
  unsigned int v119; // eax
  __int16 v121; // cx
  __int16 v122; // ax
  __int16 v123; // dx
  unsigned int *v124; // ecx
  signed int v125; // edx
  unsigned int v126; // eax
  unsigned int *v127; // ecx
  signed int v128; // edx
  unsigned int v129; // eax
  unsigned int *v130; // ecx
  signed int v131; // edx
  unsigned int v132; // eax
  int v133; // eax
  unsigned int v135; // edx
  bool v136; // zf
  bool v137; // sf

  if ( a1 == 0) {
    return;
  }

  //FIXME: Did I invert this poorly?
  //FIXME: WTF?! a1[0] is not swapped here yet?!
  v2 = a1[0];
  if ((v2 == 20581) || (v2 == 20582) || (v2 == 53348) || (v2 == 53349) || (v2 == 20580) || (v2 == 12388) || (v2 == 53350)) {
    return;
  }

  v4 = (a1[1] << 16) | a1[1] & 0xFF00;
  v5 = (unsigned int)a1[1] >> 16;
  v6 = a1[1] & 0xFF0000;
  v7 = v6 | v5;
  a1[1] = (v7 >> 8) | (v4 << 8);

  a1[0] = swap32(a1[0]);
  v3 = a1[0];

  v8 = a1[2];
  v9 = (v8 << 16) | (unsigned __int16)(v8 & 0xFF00);
  v10 = v8 & 0xFF0000 | (v8 >> 16);
  a1[2] = (v10 >> 8) | (v9 << 8);

  LOWORD(v8) = *((_WORD *)a1 + 6);
  LOBYTE(v9) = BYTE1(v8);
  BYTE1(v9) = v8;
  *((_WORD *)a1 + 6) = v9;

  LOWORD(v8) = *((_WORD *)a1 + 7);
  LOBYTE(v9) = BYTE1(v8);
  BYTE1(v9) = v8;
  *((_WORD *)a1 + 7) = v9;

  a1[4] = swap32(a1[4]);
  v11 = a1[4];

  if ( v3 == 53349) {
    v127 = (unsigned int *)(a1 + 7);
    v127 = swap32(v127, 12);
    v130 = (unsigned int *)(a1 + 19);
    v130 = swap32(v130, 3);
  } else if ( v3 == 53350 ) {
    *((_WORD *)a1 + 14) = swap16(*((_WORD *)a1 + 14));
    *((_WORD *)a1 + 15) = swap16(*((_WORD *)a1 + 15));

    v124 = (unsigned int *)(a1 + 8);
    v124 = swap32(v124, 3);
  } else if ( v3 == 53348 ) {
    v117 = (unsigned int *)(a1 + 7);
    v117 = swap32(v117, 12);
  } else if ( v3 == 20582 ) {
    v111 = (unsigned int *)(a1 + 7);
    v111 = swap32(v111, 8);
    v114 = (unsigned int *)(a1 + 15);
    v114 = swap32(v114, 3);
  } else if ( v3 == 20581 ) {
    a1[7] = swap32(a1[7]);
  } else if ( v3 == 12388 ) {
    a1[5] = swap32(a1[5]);
    v13 = (unsigned int *)(a1 + 7);
    v13 = swap32(v13, 6);


    for(v15 = 0; v15 < a1[5]; v15++) {

      v16 = *(_DWORD *)(a1[6] + 4 * v15);
      if ( v16 ) {
        v17 = *(_DWORD *)v16;
        if ( *(_DWORD *)v16 && !sub_4475F0(*(_DWORD *)v16) ) {
          v18 = dword_50C628;
          dword_E95300[dword_50C628] = v17;
          dword_50C628 = v18 + 1;

          *(_DWORD *)(v17 + 0) = swap32(*(_DWORD *)(v17 + 0));
          *(_WORD *)(v17 + 4) = swap16(*(_WORD *)(v17 + 4));
          *(_WORD *)(v17 + 6) = swap16(*(_WORD *)(v17 + 6));

          v19 = *(_DWORD *)(v17 + 8);

          if ( v19 && !sub_447630(v19) ) {
            v22 = dword_50C62C;
            dword_E90980[dword_50C62C] = v19;
            dword_50C62C = v22 + 1;

            *(_DWORD *)(v19 + 0) = swap32(*(_DWORD *)(v19 + 0));
            *(_WORD *)(v19 + 4) = swap16(*(_WORD *)(v19 + 4));
            *(_WORD *)(v19 + 6) = swap16(*(_WORD *)(v19 + 6));
            swap16((__int16 *)(v19 + 8), 2);
            *(_WORD *)(v19 + 16) = swap16(*(_WORD *)(v19 + 16));
            *(_WORD *)(v19 + 18) = swap16(*(_WORD *)(v19 + 18));
            *(_WORD *)(v19 + 20) = swap16(*(_WORD *)(v19 + 20));
            *(_WORD *)(v19 + 22) = swap16(*(_WORD *)(v19 + 22));
            *(_WORD *)(v19 + 24) = swap16(*(_WORD *)(v19 + 24));
            *(_WORD *)(v19 + 26) = swap16(*(_WORD *)(v19 + 26));

          }

          v36 = *(_DWORD *)(v17 + 12);
          if ( v36 && !sub_447670(*(_DWORD *)(v17 + 12)) ) {
            v37 = dword_50C630;
            dword_E68280[dword_50C630] = v36;
            dword_50C630 = v37 + 1;

            *(_DWORD *)(v36 + 0) = swap32(*(_DWORD *)(v36 + 0));
            *(_WORD *)(v36 + 4) = swap16(*(_WORD *)(v36 + 4));
            swap32((unsigned int *)(v36 + 6), 2);
            swap32((unsigned int *)(v36 + 14), 2);
            *(_DWORD *)(v36 + 24) = swap32(*(_DWORD *)(v36 + 24);
            *(_DWORD *)(v36 + 28) = swap32(*(_DWORD *)(v36 + 28));

          }
        }

        v46 = *(_DWORD *)(v16 + 4);
        if ( v46 ) {
          v47 = *(_DWORD *)(v46 + 60);

          *(_WORD *)(v46 + 0) = swap16(*(_WORD *)(v46 + 0));
          //FIXME: Nothing here?
          *(_WORD *)(v46 + 6) = swap16(*(_WORD *)(v46 + 6));
          *(_WORD *)(v46 + 8) = swap16(*(_WORD *)(v46 + 8));
          *(_WORD *)(v46 + 10) = swap16( *(_WORD *)(v46 + 10));
          //FIXME: Nothing here?
          *(_DWORD *)(v46 + 20) = swap32(*(_DWORD *)(v46 + 20));
          *(_DWORD *)(v46 + 24) = swap32(*(_DWORD *)(v46 + 24));
          *(_DWORD *)(v46 + 28) = swap32(*(_DWORD *)(v46 + 28));
          *(_DWORD *)(v46 + 32) = swap32(*(_DWORD *)(v46 + 32));
          *(_DWORD *)(v46 + 36) = swap32(*(_DWORD *)(v46 + 36));
          *(_DWORD *)(v46 + 40) = swap32(*(_DWORD *)(v46 + 40));
          *(_DWORD *)(v46 + 44) = swap32(*(_DWORD *)(v46 + 44));
          *(_WORD *)(v46 + 48) = swap16(*(_WORD *)(v46 + 48));
          *(_WORD *)(v46 + 50) = swap16(*(_WORD *)(v46 + 50));
          *(_DWORD *)(v46 + 52) = swap32(*(_DWORD *)(v46 + 52));
          *(_DWORD *)(v46 + 56) = swap32(*(_DWORD *)(v46 + 56));

          if ( v47 ) {
            do {

              v74 = swap32((v47 + 0), 3);
              v77 = swap32((v47 + 12), 3);
              *(_DWORD *)(v47 + 24) = swap32(*(_DWORD *)(v47 + 24));
              *(_DWORD *)(v47 + 28) = swap32(*(_DWORD *)(v47 + 28));
              *(_WORD *)(v47 + 36) = swap16(*(_WORD *)(v47 + 36))
              *(_WORD *)(v47 + 38) = swap16(*(_WORD *)(v47 + 38));

              v47 = *(_DWORD *)(v47 + 40);
            } while ( v47 );
          }
        }

        swap32((unsigned int *)(v16 + 8), 6);
        *(_WORD *)(v16 + 32) = swap16(*(_WORD *)(v16 + 32);
        *(_WORD *)(v16 + 34) = swap16(*(_WORD *)(v16 + 34));

        v90 = *(_DWORD *)(v16 + 36);
        if ( v90 ) {
          swap32(v90, *(_WORD *)(v16 + 32));
        }

        // Accumulate something?
        if ( *(_DWORD *)(v16 + 44) && *(_DWORD *)(v16 + 40) ) {
          v94 = *(_WORD *)(v16 + 34);
          v95 = 0;
          switch ( v94 ) {
            case 3:
              v95 = 3 * *(signed __int16 *)(v16 + 32);
              break;
            case 4:
              v95 = 4 * *(signed __int16 *)(v16 + 32);
              break;
            case 5:
              v97 = *(int **)(v16 + 36);
              for(v96 = 0; v96 < *(signed __int16 *)(v16 + 32); v96++) {
                v95 += v97[v96] + 2;
              }
              break;
            default:
              // Another noble error handler!
              while (1);
          }

          v99 = (_WORD *)(*(_DWORD *)(v16 + 40));
          swap16(v99, v95);

        }

        *(_WORD *)(v16 + 56) = swap16(*(_WORD *)(v16 + 56));

        if ( !dword_E6B168 ) {
          v104 = *(_DWORD *)(v16 + 44);
          if (v104) {
            swap16((_WORD *)v104, *(_WORD *)(v16 + 56));
          }
        }

        *(_WORD *)(v16 + 58) = swap16(*(_WORD *)(v16 + 58));
        *(_WORD *)(v16 + 60) = swap16(*(_WORD *)(v16 + 60));
        *(_WORD *)(v16 + 62) = swap16(*(_WORD *)(v16 + 62));

      }

    }
  }

  // Recursively parse children if this has any ???
  if ( a1[0] & 0x4000 ) {
    a1[5] = swap32(a1[5]);
    for(int32_t v134 = 0; v134 < a1[5]; v134++) {
      sub_4476B0(*(_DWORD *)(a1[6] + 4 * v134));
    }
  }

}
```

# Check if some value (pointer?) is in some array

```C
//----- (00447630) --------------------------------------------------------
// a1 = value to search for
// returns 1 if value was found, 0 otherwise
signed int __cdecl sub_447630(int a1) {
  // Note: The check / loop has been inverted
  int32_t* v2 = dword_E90980; //FIXME: Might also be &dword_E90980 ?
  for(int32_t v1 = 0; v1 < dword_50C62C; v1++) {
    if (v2[v1] == a1) {
      return 1;
    }
  }
  return 0;
}
```

```