/* Information related to podracer upgrades */

// Research based on patched US version


typedef struct {
  uint8_t index; // absolute index to identify part?
  uint8_t level; // level / quality?
  uint8_t unk1; // ?
  uint8_t category; // what kind of part it is?
  int32_t price;
  int32_t model; // model index
  char* title;
} PartData;

PartData data_4C1CB8[7 * 6]; // 7 categories x 6 levels



//----- (004493F0) --------------------------------------------------------
// Calculates the handling statistics for a podracer after an upgrade
// a1 = Output value
// a2 = Upgrade category
// a3 = Upgrade level
// a4 = Upgrade health?! [0.0, 1.0]
void __cdecl sub_4493F0(int a1, int a2, int a3, float a4) {
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c3
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  unsigned __int8 v17; // c0
  unsigned __int8 v18; // c3
  unsigned __int8 v20; // c0
  unsigned __int8 v21; // c3
  unsigned __int8 v23; // c0
  unsigned __int8 v24; // c3
  unsigned __int8 v26; // c0
  unsigned __int8 v27; // c3
  unsigned __int8 v29; // c0
  unsigned __int8 v30; // c3
  unsigned __int8 v32; // c0
  unsigned __int8 v33; // c3
  unsigned __int8 v35; // c0
  unsigned __int8 v36; // c3
  unsigned __int8 v38; // c0
  unsigned __int8 v39; // c3
  unsigned __int8 v41; // c0
  unsigned __int8 v42; // c3
  unsigned __int8 v44; // c0
  unsigned __int8 v45; // c3
  unsigned __int8 v47; // c0
  unsigned __int8 v48; // c3
  unsigned __int8 v50; // c0
  unsigned __int8 v51; // c3
  unsigned __int8 v53; // c0
  unsigned __int8 v54; // c3
  unsigned __int8 v56; // c0
  unsigned __int8 v57; // c3
  unsigned __int8 v59; // c0
  unsigned __int8 v60; // c3
  unsigned __int8 v62; // c0
  unsigned __int8 v63; // c3
  unsigned __int8 v65; // c0
  unsigned __int8 v66; // c3
  unsigned __int8 v68; // c0
  unsigned __int8 v69; // c3
  unsigned __int8 v71; // c0
  unsigned __int8 v72; // c3
  unsigned __int8 v74; // c0
  unsigned __int8 v75; // c3
  unsigned __int8 v77; // c0
  unsigned __int8 v78; // c3
  unsigned __int8 v80; // c0
  unsigned __int8 v81; // c3
  unsigned __int8 v83; // c0
  unsigned __int8 v84; // c3
  unsigned __int8 v86; // c0
  unsigned __int8 v87; // c3
  unsigned __int8 v89; // c0
  unsigned __int8 v90; // c3
  unsigned __int8 v92; // c0
  unsigned __int8 v93; // c3
  unsigned __int8 v95; // c0
  unsigned __int8 v96; // c3
  unsigned __int8 v98; // c0
  unsigned __int8 v99; // c3
  unsigned __int8 v101; // c0
  unsigned __int8 v102; // c3
  unsigned __int8 v104; // c0
  unsigned __int8 v105; // c3
  unsigned __int8 v107; // c0
  unsigned __int8 v108; // c3

  switch ( a2 ) {
    case 0:
      if ( a3 == 1 )
      {
        *(float*)a1 = a4 * 0.05f + *(float*)a1;
        if ( *(float*)a1 > 1.0f )
          *(float*)a1 = 1.0f;
        if ( *(float*)a1 < 0.01f )
          *(float*)a1 = 0.01f
      }
      if ( a3 == 2 )
      {
        *(float*)a1 = a4 * 0.1f + *(float*)a1;
        if ( !(v8 | v9) )
          *(float*)a1 = 1.0f;
        if ( *(float*)a1 < 0.01f )
          *(float*)a1 = 0.01f
      }
      if ( a3 == 3 )
      {
        *(float*)a1 = a4 * 0.15f + *(float*)a1;
        if ( !(v11 | v12) )
          *(float*)a1 = 1.0f;
        if ( *(float*)a1 < 0.01f )
          *(float*)a1 = 0.01f
      }
      if ( a3 == 4 )
      {
        *(float*)a1 = a4 * 0.2f + *(float*)a1;
        if ( !(v14 | v15) )
          *(float*)a1 = 1.0f;
        if ( *(float*)a1 < 0.01f )
          *(float*)a1 = 0.01f
      }
      if ( a3 == 5 )
      {
        *(float*)a1 = a4 * 0.25f + *(float*)a1;
        if ( !(v17 | v18) )
          *(float*)a1 = 1.0f;
        if ( *(float*)a1 < 0.01f )
          *(float*)a1 = 0.01f
      }
      break;
    case 1:
      if ( a3 == 1 )
      {
        *(float*)(a1 + 4) = a4 * 116.0f + *(float*)(a1 + 4);
        if ( !(v20 | v21) )
          *(float*)(a1 + 4) = 1000.0f;
        if ( *(float*)(a1 + 4) < 50.0f)
          *(float*)(a1 + 4) = 50.0f;
      }
      if ( a3 == 2 )
      {
        *(float*)(a1 + 4) = a4 * 232.0f + *(float*)(a1 + 4);
        if ( !(v23 | v24) )
          *(float*)(a1 + 4) = 1000.0f;
        if ( *(float*)(a1 + 4) < 50.0f )
          *(float*)(a1 + 4) = 50.0f;
      }
      if ( a3 == 3 )
      {
        *(float*)(a1 + 4) = a4 * 348.0f + *(float*)(a1 + 4);
        if ( !(v26 | v27) )
          *(float*)(a1 + 4) = 1000.0f;
        if ( *(float*)(a1 + 4) < 50.0f )
          *(float*)(a1 + 4) = 50.0f;
      }
      if ( a3 == 4 )
      {
        *(float*)(a1 + 4) = a4 * 464.0f + *(float*)(a1 + 4);
        if ( !(v29 | v30) )
          *(float*)(a1 + 4) = 1000.0f;
        if ( *(float*)(a1 + 4) < 50.0f )
          *(float*)(a1 + 4) = 50.0f;
      }
      if ( a3 == 5 )
      {
        *(float*)(a1 + 4) = a4 * 578.0f + *(float*)(a1 + 4);
        if ( !(v32 | v33) )
          *(float*)(a1 + 4) = 1000.0f;
        if ( *(float*)(a1 + 4) < 50.0f )
          *(float*)(a1 + 4) = 50.0f;
      }
      break;
    case 2:
      if ( a3 == 1 )
      {
        *(float*)(a1 + 12) = ((1.0 - a4) * 0.14f - -0.86f) * *(float*)(a1 + 12);
        if ( !(v35 | v36) )
          *(float*)(a1 + 12) = 5.0f;
        if ( *(float*)(a1 + 12) < 0.1 )
          *(float*)(a1 + 12) = 0.1f;
      }
      if ( a3 == 2 )
      {
        *(float*)(a1 + 12) = ((1.0 - a4) * 0.28f - -0.72f) * *(float*)(a1 + 12);
        if ( !(v38 | v39) )
          *(float*)(a1 + 12) = 5.0f;
        if ( *(float*)(a1 + 12) < 0.1 )
          *(float*)(a1 + 12) = 0.1f;
      }
      if ( a3 == 3 )
      {
        *(float*)(a1 + 12) = ((1.0 - a4) * 0.42f - -0.58f) * *(float*)(a1 + 12);
        if ( !(v41 | v42) )
          *(float*)(a1 + 12) = 5.0f;
        if ( *(float*)(a1 + 12) < 0.1 )
          *(float*)(a1 + 12) = 0.1f;
      }
      if ( a3 == 4 )
      {
        *(float*)(a1 + 12) = ((1.0 - a4) * 0.56f - -0.44f) * *(float*)(a1 + 12);
        if ( !(v44 | v45) )
          *(float*)(a1 + 12) = 5.0f;
        if ( *(float*)(a1 + 12) < 0.1 )
          *(float*)(a1 + 12) = 0.1f;
      }
      if ( a3 == 5 )
      {
        *(float*)(a1 + 12) = ((1.0 - a4) * 0.7f - -0.3f) * *(float*)(a1 + 12);
        if ( !(v47 | v48) )
          *(float*)(a1 + 12) = 5.0f;
        if ( *(float*)(a1 + 12) < 0.1 )
          *(float*)(a1 + 12) = 0.1f;
      }
      break;
    case 3:
      if ( a3 == 1 )
      {
        *(float*)(a1 + 16) = a4 * 40.0f + *(float*)(a1 + 16);
        if ( !(v50 | v51) )
          *(float*)(a1 + 16) = 650.0f;
        if ( *(float*)(a1 + 16) < 450.0f)
          *(float*)(a1 + 16) = 450.0f;
      }
      if ( a3 == 2 )
      {
        *(float*)(a1 + 16) = a4 * 80.0f + *(float*)(a1 + 16);
        if ( !(v53 | v54) )
          *(float*)(a1 + 16) = 650.0f;
        if ( *(float*)(a1 + 16) < 450.0f)
          *(float*)(a1 + 16) = 450.0f;
      }
      if ( a3 == 3 )
      {
        *(float*)(a1 + 16) = a4 * 120.0f + *(float*)(a1 + 16);
        if ( !(v56 | v57) )
          *(float*)(a1 + 16) = 650.0f;
        if ( *(float*)(a1 + 16) < 450.0f)
          *(float*)(a1 + 16) = 450.0f;
      }
      if ( a3 == 4 )
      {
        *(float*)(a1 + 16) = a4 * 160.0f + *(float*)(a1 + 16);
        if ( !(v59 | v60) )
          *(float*)(a1 + 16) = 650.0f;
        if ( *(float*)(a1 + 16) < 450.0f)
          *(float*)(a1 + 16) = 450.0f;
      }
      if ( a3 == 5 )
      {
        *(float*)(a1 + 16) = a4 * 200.0f + *(float*)(a1 + 16);
        if ( !(v62 | v63) )
          *(float*)(a1 + 16) = 650.0f;
        if ( *(float*)(a1 + 16) < 450.0f)
          *(float*)(a1 + 16) = 450.0f;
      }
      break;
    case 4:
      if ( a3 == 1 )
      {
        *(float*)(a1 + 20) = ((1.0 - a4) * 0.08f - -0.92f) * *(float*)(a1 + 20);
        if ( !(v65 | v66) )
          *(float*)(a1 + 20) = 1000.0f;
        if ( *(float*)(a1 + 20) < 1.0f)
          *(float*)(a1 + 20) = 1.0f;
      }
      if ( a3 == 2 )
      {
        *(float*)(a1 + 20) = ((1.0 - a4) * 0.17f - -0.83f) * *(float*)(a1 + 20);
        if ( !(v68 | v69) )
          *(float*)(a1 + 20) = 1000.0f;
        if ( *(float*)(a1 + 20) < 1.0f)
          *(float*)(a1 + 20) = 1.0f;
      }
      if ( a3 == 3 )
      {
        *(float*)(a1 + 20) = ((1.0 - a4) * 0.26f - -0.74f) * *(float*)(a1 + 20);
        if ( !(v71 | v72) )
          *(float*)(a1 + 20) = 1000.0f;
        if ( *(float*)(a1 + 20) < 1.0f)
          *(float*)(a1 + 20) = 1.0f;
      }
      if ( a3 == 4 )
      {
        *(float*)(a1 + 20) = ((1.0 - a4) * 0.35f - -0.65f) * *(float*)(a1 + 20);
        if ( !(v74 | v75) )
          *(float*)(a1 + 20) = 1000.0f;
        if ( *(float*)(a1 + 20) < 1.0f)
          *(float*)(a1 + 20) = 1.0f;
      }
      if ( a3 == 5 )
      {
        *(float*)(a1 + 20) = ((1.0 - a4) * 0.44f - -0.56f) * *(float*)(a1 + 20);
        if ( !(v77 | v78) )
          *(float*)(a1 + 20) = 1000.0f;
        if ( *(float*)(a1 + 20) < 1.0f)
          *(float*)(a1 + 20) = 1.0f;
      }
      break;
    case 5:
      if ( a3 == 1 )
      {
        *(float*)(a1 + 36) = a4 * 1.6f + *(float*)(a1 + 36);
        if ( !(v80 | v81) )
          *(float*)(a1 + 36) = 20.0f;
        if ( *(float*)(a1 + 36) < 1.0f)
          *(float*)(a1 + 36) = 1.0f;
      }
      if ( a3 == 2 )
      {
        *(float*)(a1 + 36) = a4 * 3.2f + *(float*)(a1 + 36);
        if ( !(v83 | v84) )
          *(float*)(a1 + 36) = 20.0f;
        if ( *(float*)(a1 + 36) < 1.0f)
          *(float*)(a1 + 36) = 1.0f;
      }
      if ( a3 == 3 )
      {
        *(float*)(a1 + 36) = a4 * 4.8f + *(float*)(a1 + 36);
        if ( !(v86 | v87) )
          *(float*)(a1 + 36) = 20.0f;
        if ( *(float*)(a1 + 36) < 1.0f)
          *(float*)(a1 + 36) = 1.0f;
      }
      if ( a3 == 4 )
      {
        *(float*)(a1 + 36) = a4 * 6.4f + *(float*)(a1 + 36);
        if ( !(v89 | v90) )
          *(float*)(a1 + 36) = 20.0f;
        if ( *(float*)(a1 + 36) < 1.0f)
          *(float*)(a1 + 36) = 1.0f;
      }
      if ( a3 == 5 )
      {
        *(float*)(a1 + 36) = a4 * 8.0f + *(float*)(a1 + 36);
        if ( !(v92 | v93) )
          *(float*)(a1 + 36) = 20.0f;
        if ( *(float*)(a1 + 36) < 1.0f)
          *(float*)(a1 + 36) = 1.0f;
      }
      break;
    case 6:
      if ( a3 == 1 )
      {
        *(float*)(a1 + 44) = a4 * 0.1f + *(float*)(a1 + 44);
        if ( !(v95 | v96) )
          *(float*)(a1 + 44) = 1.0f;
        if ( *(float*)(a1 + 44) < 0.0f)
          *(float*)(a1 + 44) = 0.0f;
      }
      if ( a3 == 2 )
      {
        *(float*)(a1 + 44) = a4 * 0.2f + *(float*)(a1 + 44);
        if ( !(v98 | v99) )
          *(float*)(a1 + 44) = 1.0f;
        if ( *(float*)(a1 + 44) < 0.0f)
          *(float*)(a1 + 44) = 0.0f;
      }
      if ( a3 == 3 )
      {
        *(float*)(a1 + 44) = a4 * 0.3f + *(float*)(a1 + 44);
        if ( !(v101 | v102) )
          *(float*)(a1 + 44) = 1.0f;
        if ( *(float*)(a1 + 44) < 0.0f)
          *(float*)(a1 + 44) = 0.0f;
      }
      if ( a3 == 4 )
      {
        *(float*)(a1 + 44) = a4 * 0.4f + *(float*)(a1 + 44);
        if ( !(v104 | v105) )
          *(float*)(a1 + 44) = 1.0f;
        if ( *(float*)(a1 + 44) < 0.0f)
          *(float*)(a1 + 44) = 0.0f;
      }
      if ( a3 == 5 )
      {
        *(float*)(a1 + 44) = a4 * 0.45f + *(float*)(a1 + 44);
        if ( !(v107 | v108) )
          *(float*)(a1 + 44) = 1.0f;
        if ( *(float*)(a1 + 44) < 0.0f)
          *(float*)(a1 + 44) = 0.0f;
      }
      break;
    default:
      break;
  }
  return;
}

