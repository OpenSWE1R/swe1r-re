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
  signed int v12; // edx
  unsigned int *v13; // ecx
  unsigned int v14; // eax
  int v16; // ebp
  int v17; // edi
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

  uintptr_t a1b = a1;

  if ( a1b == 0) {
    return;
  }

  //FIXME: Did I invert this poorly?
  //FIXME: WTF?! *(uint32_t*)(a1b + 0) is not swapped here yet?!
  v2 = *(uint32_t*)(a1b + 0);
  if ((v2 == 20581) || (v2 == 20582) || (v2 == 53348) || (v2 == 53349) || (v2 == 20580) || (v2 == 12388) || (v2 == 53350)) {
    return;
  }

  *(uint32_t*)(a1b + 0) = swap32(*(uint32_t*)(a1b + 0));
  v3 = *(uint32_t*)(a1b + 0);
  *(uint32_t*)(a1b + 4) = swap32(*(uint32_t*)(a1b + 4));
  *(uint32_t*)(a1b + 8) = swap32(*(uint32_t*)(a1b + 8));

  *((_WORD *)(a1b + 12)) = swap16(*((_WORD *)(a1b + 12)));
  *((_WORD *)(a1b + 14)) = swap16(*((_WORD *)(a1b + 14)));

  *(uint32_t*)(a1b + 16) = swap32(*(uint32_t*)(a1b + 16));

  if ( v3 == 53349) {
    swap32((uint32_t*)(a1b + 28), 12);
    swap32((uint32_t*)(a1b + 76), 3);
  } else if ( v3 == 53350 ) {
    *((_WORD *)(a1b + 28)) = swap16(*((_WORD *)(a1b + 28)));
    *((_WORD *)(a1b + 30)) = swap16(*((_WORD *)(a1b + 30)));
    swap32((uint32_t*)(a1b + 32), 3);
  } else if ( v3 == 53348 ) {
    swap32((uint32_t*)(a1b + 28), 12);
  } else if ( v3 == 20582 ) {
    swap32((uint32_t*)(a1b + 28), 8);
    swap32((uint32_t*)(a1b + 60), 3);
  } else if ( v3 == 20581 ) {
    *(uint32_t*)(a1b + 28) = swap32(*(uint32_t*)(a1b + 28));
  } else if ( v3 == 12388 ) {
    *(uint32_t*)(a1b + 20) = swap32(*(uint32_t*)(a1b + 20));
    swap32((uint32_t*)(a1b + 28), 6);


    for(int32_t v15 = 0; v15 < *(uint32_t*)(a1b + 20); v15++) {

      typedef struct {
        uint32_t unk0; // A pointer of some sorts
        uint32_t unk4; // A pointer of some sorts
        uint32_t unk8[6]; // 8
        uint16_t unk32; // mode 3 = 3*unk32; mode 4 = 4*unk32; mode 5 = Count for unk36
        uint16_t unk34; // Some mode, {3,4,5} are typical values
        uint32_t unk36; // Pointer to uint32_t[], for mode 5, summed up is the count of unk40 (stripsize?)
        uint32_t unk40; // Pointer to uint16_t[] (indices?)
        uint32_t unk44; // Pointer to uint16_t[]
        uint8_t unk48[8];
        uint16_t unk56; // Count for unk44
        uint16_t unk58;
        uint16_t unk60;
        uint16_t unk62;
      } V16;
      v16 = *(_DWORD *)(*(uint32_t*)(a1b + 24) + 4 * v15);
      if ( !v16 ) {
        continue;
      }

      
      // Get item pointer and check if it's in the list already
      typedef struct {
        uint32_t unk0;
        uint16_t unk4;
        uint16_t unk6;
        uint32_t unk8; // A pointer of some sorts
        uint32_t unk12; // A pointer of some sorts
      } V17;
      v17 = *(_DWORD *)(v16 + 0);
      if ( v17 && !sub_4475F0(v17) ) {

        // Add this pointer to the array
        dword_E95300[dword_50C628] = v17;
        dword_50C628 = dword_50C628 + 1;

        *(_DWORD *)(v17 + 0) = swap32(*(_DWORD *)(v17 + 0));
        *(_WORD *)(v17 + 4) = swap16(*(_WORD *)(v17 + 4));
        *(_WORD *)(v17 + 6) = swap16(*(_WORD *)(v17 + 6));

        // Get pointer and check if it's already in list
        v19 = *(_DWORD *)(v17 + 8);
        if ( v19 && !sub_447630(v19) ) {

          // Add pointer to list
          dword_E90980[dword_50C62C] = v19;
          dword_50C62C = dword_50C62C + 1;

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

        // Get pointer and check if it's already in list
        v36 = *(_DWORD *)(v17 + 12);
        if ( v36 && !sub_447670(*(_DWORD *)(v17 + 12)) ) {

          // Add pointer to list
          dword_E68280[dword_50C630] = v36;
          dword_50C630 = dword_50C630 + 1;

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

        // Walk through some list
        typedef struct {
          uint32_t v74[3]; // 0
          uint32_t v77[3]; // 12
          uint32_t unk24; // 24
          uint32_t unk28; // 28
          uint32_t unk32; // 32 not touched?
          uint16_t unk36; // 36
          uint16_t unk38; // 38
          struct _V47* next; // 40
        } V47;
        v47 = *(_DWORD *)(v46 + 60);
        if ( v47 ) {
          do {

            v74 = swap32((v47 + 0), 3);
            v77 = swap32((v47 + 12), 3);
            *(_DWORD *)(v47 + 24) = swap32(*(_DWORD *)(v47 + 24));
            *(_DWORD *)(v47 + 28) = swap32(*(_DWORD *)(v47 + 28));
            //FIXME: Nothing?
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

  // Recursively parse children if this has any ???
  if (*(uint32_t*)(a1b + 0) & 0x4000 ) {
    *(uint32_t*)(a1b + 20) = swap32(*(uint32_t*)(a1b + 20));
    for(int32_t v134 = 0; v134 < *(uint32_t*)(a1b + 20); v134++) {
      sub_4476B0(*(uint32_t*)(*(uint32_t*)(a1b + 24) + 4 * v134));
    }
  }

}
```

# Check if some value (pointer?) is in some array 1

```C
//----- (004475F0) --------------------------------------------------------
// a1 = value to search for
// returns 1 if value was found, 0 otherwise
signed int __cdecl sub_4475F0(int a1) {
  int32_t* v2 = dword_E95300; //FIXME: Might also be &dword_E95300 ?
  for(int32_t v1 = 0; v1 < dword_50C628; v1++) {
    if (v2[v1] == a1) {
      return 1;
    }
  }
  return 0;
}
```

# Check if some value (pointer?) is in some array 2

```C
//----- (00447630) --------------------------------------------------------
// Very similar to 004475F0
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