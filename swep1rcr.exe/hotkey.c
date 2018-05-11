/* Code related to the menus */

// Research based on patched US version

//----- (00410430) --------------------------------------------------------
// Check if a screenshot should be taken, then take it
void sub_410430() {

  // Check if we hold F12 and it was released at least once,
  // after the last screenshot was taken
  if ( sub_485880(DIK_F12, 0) && (dword_4D79E8 != 0)) {

    // Play a sound to confirm taking the screenshot
    sub_440550(70);

    // Take screenshot
    sub_410480((int)aSnap);

    // Mark F12 as held / pressed
    dword_4D79E8 = 1;

  } else {

    // Mark F12 as released
    dword_4D79E8 = 0;

  }
  return;
}

//----- (004104F0) --------------------------------------------------------
void sub_4104F0() {
  char *v0; // esi
  int v1; // ecx
  const char *v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  bool v5; // zf
  int v6; // edx
  const char *v7; // eax
  _DWORD *v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // eax
  int v12; // [esp+10h] [ebp-24h]
  int v13; // [esp+14h] [ebp-20h]
  int v14; // [esp+18h] [ebp-1Ch]
  int v15; // [esp+1Ch] [ebp-18h]

  //FIXME: What is this?
  if ( dword_4B5C40 ) {
    dword_4B5C40 = 0;
  }

  // Get the number of truguts
  v12 = dword_E35A98[0];

  // F12: Take a screenshot
  //FIXME: Bug in game: F12 is checked in the called function anyway,
  //                    no need to check it here
  if ( sub_485880(DIK_F12, 0) ) {
    sub_410430();
  }

  // NOT [ Ctrl (Left) + C + Y ]
  if ( !sub_485880(DIK_LCONTROL, 0) || !sub_485880(DIK_C, 0) || !sub_485880(DIK_Y, 0) || *(_DWORD *)(dword_50C454 + 8) != 9 )
  {
    // Ctrl (Right) + N + K
    if ( sub_485880(DIK_RCONTROL, 0) && sub_485880(DIK_N, 0) && sub_485880(DIK_K, 0) && *(_DWORD *)(dword_50C454 + 8) == 9 )
    {
      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;

      // Enable Jinn Reeso
      sub_44B530();

      sub_440550(45);
LABEL_145:
      if ( !dword_4D79EC )
        return;
      goto LABEL_146;
    }

    if ( sub_485880(DIK_F1, 0) )
    {
      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;
      dword_EC83D0 = 1667458609; // 'ccf1'
      goto LABEL_145;
    }

    if ( sub_485880(DIK_F2, 0) )
    {
      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;
      dword_EC83D0 = 1667458610; // 'ccf2'
      goto LABEL_145;
    }

    if ( sub_485880(DIK_F3, 0) )
    {
      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;
      dword_EC83D0 = 1667458611; // 'ccf3'
      goto LABEL_145;
    }

    // Reward 1000 Truguts if F4 + Shift (left or right) + 4 are pressed
    if ( sub_485880(DIK_F4, 0) )
    {
      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;
      dword_EC83D0 = 1667458612; // 'ccf4'
      if ( *(_DWORD *)(dword_50C454 + 8) == 7 && (sub_485880(DIK_LSHIFT, 0) || sub_485880(DIK_RSHIFT, 0)) && sub_485880(DIK_4, 0) )
        dword_E35A98[0] += 1000;
      goto LABEL_145;
    }

    // Check for capslock
    if ( sub_485880(DIK_CAPITAL, 0) )
    {
      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;
      v0 = sub_450B30(1248094053, 0);
      if ( v0 )
      {
        sub_440550(70);
        v1 = *((_DWORD *)v0 + 73);
        if ( dword_50CA18 <= 1 )
        {
          *((_DWORD *)v0 + 73) = v1 + 1;
          if ( v1 + 1 > 4 )
            *((_DWORD *)v0 + 73) = 0;
        }
        else
        {
          *((_DWORD *)v0 + 73) = v1 + 1;
          if ( v1 + 1 > 7 )
            *((_DWORD *)v0 + 73) = 4;
        }
      }
      goto LABEL_145;
    }

    // Alt (Right or Left) + H
    //FIXME: What does this do?!
    if ( (sub_485880(DIK_RMENU, 0) || sub_485880(DIK_LMENU, 0)) && sub_485880(DIK_H, 0) )
    {
      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;
      dword_EC83C8 = 1;
      goto LABEL_145;
    }

    if ( dword_50C07C != 2 )
      goto LABEL_66;

    // Control (Left or Right)
    if ( sub_485880(DIK_LCONTROL, 0) || sub_485880(DIK_RCONTROL, 0) )
    {
      // F10
      if ( sub_485880(DIK_F10, 0) )
      {
        if ( dword_4D79EC )
          goto LABEL_146;
        if ( dword_4D5E00 )
          goto LABEL_134;
        dword_50C048 ^= 4u;
        sub_440550(40);
LABEL_65:
        dword_4D79EC = 1;
        goto LABEL_145;
      }
    }
    else
    {

      // Multiply (Numpad) + T
      //FIXME What is this?
      if ( sub_485880(DIK_MULTIPLY, 0) && sub_485880(DIK_T, 0) )
      {
        if ( !dword_4D5E00 )
        {
          if ( dword_4D79EC )
            goto LABEL_146;
          dword_50CB68 ^= 1u;
          sub_440550(44);
          dword_4D79EC = 1;
          goto LABEL_145;
        }
        goto LABEL_66;
      }

      // I + F + L + Y
      //FIXME: What does this do?
      if ( sub_485880(DIK_I, 0) && sub_485880(DIK_F, 0) && sub_485880(DIK_L, 0) && sub_485880(DIK_Y, 0) && !dword_4D5E00 )
      {
        if ( dword_4D79EC )
          goto LABEL_146;
        dword_50C048 ^= 0x2000u;
        sub_440550(43);
        goto LABEL_65;
      }

    }
LABEL_66:

    // Control (Left or Right)
    if ( sub_485880(DIK_LCONTROL, 0) || sub_485880(DIK_RCONTROL, 0) )
    {

      // J
      if ( sub_485880(DIK_J, 0) )
      {
        if ( dword_4D79EC )
          goto LABEL_146;
        dword_4D79EC = 1;
        if ( !dword_4B294C )
        {
          v2 = sub_421360(aMondotextH0035);
          goto LABEL_112;
        }
        if ( dword_4B2944 )
        {
          strcat(&byte_4D78D0, sub_421360(aMondotextH0364));
          dword_4D79D0 = dword_4B2910;
          if ( dword_4B2910 )
            sub_40A120(1);
          dword_4B2910 = 0;
        }
        else
        {
          strcat(&byte_4D78D0, sub_421360(aMondotextH0363));
          dword_4B2910 = dword_4D79D0;
        }
        sub_440550(70);
        dword_4B2944 = dword_4B2944 == 0;
        if ( !dword_4B2940 )
        {
          v3 = sub_414D90(0, 24);
          sub_40B740(0, v3);
        }
        v4 = sub_411810();
        if ( !dword_4B2940 && v4 )
        {
          v5 = *(_DWORD *)(v4 + 28) == 24;
          goto LABEL_104;
        }
        goto LABEL_105;
      }

      // Alt (Left)
      if ( sub_485880(DIK_LMENU, 0) && *(_DWORD *)(dword_50C454 + 8) == 13 )
      {

        // Alt (Right)
        if ( sub_485880(DIK_RMENU, 0) )
        {
          if ( dword_4D79EC )
            goto LABEL_146;
          dword_4D79EC = 1;
          if ( !dword_4D5E00 )
          {
            v6 = dword_E996DC;
            BYTE1(v6) |= 0x40u;
            dword_E996DC = v6;
            *(_BYTE *)(dword_50C454 + 110) = *(_BYTE *)(dword_50C454 + 110) == 0;
            sub_440550(46);
          }
          goto LABEL_145;
        }

        // Control (Right)
        if ( sub_485880(DIK_RCONTROL, 0) )
        {
          if ( dword_4D79EC )
            goto LABEL_146;
          dword_4D79EC = 1;
          if ( !dword_4D5E00 )
          {
            dword_E996DC &= 0xFFFFBFFF;
            *(_BYTE *)(dword_50C454 + 110) = *(_BYTE *)(dword_50C454 + 110) == 0;
            sub_440550(47);
          }
          goto LABEL_145;
        }
      }

      // M
      if ( sub_485880(DIK_M, 0) )
      {
        if ( dword_4D79EC )
          goto LABEL_146;
        dword_4D79EC = 1;
        if ( !dword_4B2950 )
        {
          v2 = sub_421360(aMondotextH0036);
          goto LABEL_112;
        }
        if ( dword_4D6B38 )
          v7 = sub_421360(aMondotextH0366);
        else
          v7 = sub_421360(aMondotextH0365);
        strcat(&byte_4D78D0, v7);
        sub_440550(70);
        dword_4D6B38 = dword_4D6B38 == 0;
        if ( !dword_4B2940 )
        {
          v8 = sub_414D90(0, 25);
          sub_40B740(1, v8);
        }
        v9 = sub_411810();
        if ( !dword_4B2940 && v9 )
        {
          v5 = *(_DWORD *)(v9 + 28) == 25;
LABEL_104:
          if ( v5 )
            goto LABEL_145;
        }
LABEL_105:
        sub_406080((int)aCurrent);
        goto LABEL_145;
      }

      // F
      if ( sub_485880(DIK_F, 0) )
      {
        if ( dword_4D79EC )
          goto LABEL_146;
        dword_4D79EC = 1;
        if ( dword_4B2914 )
        {
          if ( dword_4D765C )
          {
            if ( dword_4B2910 || !dword_4B4938 )
            {
              strcat(&byte_4D78D0, sub_421360(aMondotextH0370));
              sub_40A120(1);
            }
            else
            {
              strcat(&byte_4D78D0, sub_421360(aMondotextH0369));
            }
            sub_440550(70);
            if ( dword_4B2910 || (dword_4B2910 = 1, !dword_4B4938) )
              dword_4B2910 = 0;
            v10 = sub_414D90(0, 27);
            sub_40C100(v10);
            v11 = sub_411810();
            if ( dword_4B2940 || !v11 || *(_DWORD *)(v11 + 28) != 27 )
              sub_40AB80((int)aCurrent);
            goto LABEL_145;
          }
          v2 = sub_421360(aMondotextH0368);
        }
        else
        {
          v2 = sub_421360(aMondotextH0042);
        }
LABEL_112:
        strcat(&byte_4D78D0, v2);
        goto LABEL_145;
      }

      // Q
      if ( sub_485880(DIK_Q, 0) && dword_4D5E00 )
      {
        if ( dword_4D79EC )
          goto LABEL_146;
        dword_4D79EC = 1;
        v13 = 1348564851;
        v14 = -1;
        v15 = 1;
        sub_450C50(1097624609, (int)&v13);
        goto LABEL_145;
      }

      // F11
      if ( sub_485880(DIK_F11, 0) )
      {
        if ( dword_4D79EC )
          goto LABEL_146;
        dword_4D79EC = 1;
        dword_4D79DC = dword_4D79DC == 0;
        goto LABEL_145;
      }
    }

    // F7
    if ( !sub_485880(DIK_F7, 0) )
    {

      // F5 or F6
      if ( sub_485880(DIK_F5, 0) || sub_485880(DIK_F6, 0) )
      {
        if ( dword_4D79EC )
          goto LABEL_146;
        dword_4D79E0 = 1;
        dword_4D79EC = 1;
      }
      // Scroll lock + Home
      //FIXME: What does this do?!
      else if ( sub_485880(DIK_SCROLL, 0) && sub_485880(DIK_HOME, 0) )
      {
        if ( dword_4D79EC )
          goto LABEL_146;
        dword_4D79EC = 1;
        if ( *(_DWORD *)(dword_50C454 + 8) == 9 )
        {
          dword_50C048 ^= 0x40u;
          sub_43D9A0();
        }
      }
      else
      {
        dword_4D79EC = 0;
      }
      goto LABEL_145;
    }
    if ( dword_4D79EC )
      goto LABEL_146;
    sub_440550(70);
    sub_41BDD0();
LABEL_134:
    dword_4D79EC = 1;
    goto LABEL_145;
  }

  if ( !dword_4D79EC )
  {
    dword_4D79EC = 1;

    // Enable Cy Junga
    sub_44B5E0();

    sub_440550(-1);
    goto LABEL_145;
  }

LABEL_146:
  if ( byte_4D78D0 )
  {
    sub_44FCE0((int)&byte_4D78D0, 2.0);
    byte_4D78D0 = 0;
    dword_4D5564 = 1074161254;
  }
  if ( v12 != dword_E35A98[0] )
  {
    if ( dword_EC83CC >= 5000 )
      dword_E35A98[0] = v12;
    else
      dword_EC83CC += 1000;
  }
}

