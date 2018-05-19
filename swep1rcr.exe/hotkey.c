/* Code related to the hotkeys */

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
// Do check for hotkeys
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

  if ( sub_485880(DIK_LCONTROL, 0) && sub_485880(DIK_C, 0) && sub_485880(DIK_Y, 0) && *(_DWORD *)(dword_50C454 + 8) == 9 )) {

    // Ctrl (Left) + C + Y
    //FIXME: What's the other condition?

    if ( dword_4D79EC )
      goto LABEL_146:
    dword_4D79EC = 1;

    // Enable Cy Junga
    sub_44B5E0();

    sub_440550(-1);
  } else if ( sub_485880(DIK_RCONTROL, 0) && sub_485880(DIK_N, 0) && sub_485880(DIK_K, 0) && *(_DWORD *)(dword_50C454 + 8) == 9 ) {

    // Ctrl (Right) + N + K
    //FIXME: What's the other condition?

    if ( dword_4D79EC )
      goto LABEL_146;
    dword_4D79EC = 1;

    // Enable Jinn Reeso
    sub_44B530();

    sub_440550(45);
  } else if ( sub_485880(DIK_F1, 0) ) {
    if ( dword_4D79EC )
      goto LABEL_146;
    dword_4D79EC = 1;

    dword_EC83D0 = 1667458609; // 'ccf1'
  } else if ( sub_485880(DIK_F2, 0) ) {
    if ( dword_4D79EC )
      goto LABEL_146;
    dword_4D79EC = 1;

    dword_EC83D0 = 1667458610; // 'ccf2'
  } else if ( sub_485880(DIK_F3, 0) ) {
    if ( dword_4D79EC )
      goto LABEL_146;
    dword_4D79EC = 1;

    dword_EC83D0 = 1667458611; // 'ccf3'
  } else if ( sub_485880(DIK_F4, 0) ) {

    // F4

    if ( dword_4D79EC )
      goto LABEL_146;
    dword_4D79EC = 1;

    dword_EC83D0 = 1667458612; // 'ccf4'
    if ( *(_DWORD *)(dword_50C454 + 8) == 7 && (sub_485880(DIK_LSHIFT, 0) || sub_485880(DIK_RSHIFT, 0)) && sub_485880(DIK_4, 0) ) {

      //FIXME: What's the other condition?
      // Shift (left or right) + 4

      // Reward 1000 Truguts
      dword_E35A98[0] += 1000;
    }

  } else if ( sub_485880(DIK_CAPITAL, 0) ) {

    // Check for capslock

    if ( dword_4D79EC )
      goto LABEL_146;
    dword_4D79EC = 1;

    v0 = sub_450B30(1248094053, 0); // 'Jdge'
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

  } else if ( (sub_485880(DIK_RMENU, 0) || sub_485880(DIK_LMENU, 0)) && sub_485880(DIK_H, 0) ) {

    // Alt (Right or Left) + H

    if ( dword_4D79EC )
      goto LABEL_146;
    dword_4D79EC = 1;

    //FIXME: What does this do?!
    dword_EC83C8 = 1;
  } else if ( dword_50C07C == 2 ) {

    // We are in the pause menu??? (or in a race???)
    //FIXME: Not sure

    if ( sub_485880(DIK_LCONTROL, 0) || sub_485880(DIK_RCONTROL, 0) ) {

      // Control (Left or Right)

      if ( sub_485880(DIK_F10, 0) ) {

        // F10

        if ( dword_4D79EC )
          goto LABEL_146;

        //FIXME: What does this do?
        if ( !dword_4D5E00 ) {
          dword_50C048 ^= 4u;
          sub_440550(40);
        }

        dword_4D79EC = 1;
      }

    } else if ( sub_485880(DIK_MULTIPLY, 0) && sub_485880(DIK_T, 0) ) {

      // Multiply (Numpad) + T

      //FIXME: What does this do?
      if ( !dword_4D5E00 ) {
        if ( dword_4D79EC )
          goto LABEL_146;

        // Make the game very fast?!
        dword_50CB68 ^= 1u;
        sub_440550(44);

        dword_4D79EC = 1;
      }
    } else if ( sub_485880(DIK_I, 0) && sub_485880(DIK_F, 0) && sub_485880(DIK_L, 0) && sub_485880(DIK_Y, 0)) {

      // I + F + L + Y

        //FIXME: What does this do?
      if (!dword_4D5E00 ) {
        if ( dword_4D79EC )
          goto LABEL_146;

        //FIXME: What does this do?
        dword_50C048 ^= 0x2000u;
        sub_440550(43);

        dword_4D79EC = 1;
      }
    }

  } else if ( sub_485880(DIK_LCONTROL, 0) || sub_485880(DIK_RCONTROL, 0) ) {

    // Control (Left or Right)

    if ( sub_485880(DIK_J, 0) ) {

      // J

      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;

      if ( !dword_4B294C ) {

        v2 = sub_421360(aMondotextH0035);
        strcat(&byte_4D78D0, v2);

      } else {

        if ( dword_4B2944 ) {
          strcat(&byte_4D78D0, sub_421360(aMondotextH0364));
          dword_4D79D0 = dword_4B2910;
          if ( dword_4B2910 )
            sub_40A120(1);
          dword_4B2910 = 0;
        } else {
          strcat(&byte_4D78D0, sub_421360(aMondotextH0363));
          dword_4B2910 = dword_4D79D0;
        }
        sub_440550(70);
        dword_4B2944 = dword_4B2944 == 0;
        if ( !dword_4B2940 ) {
          v3 = sub_414D90(0, 24);
          sub_40B740(0, v3);
        }

        v4 = sub_411810();
        if ( dword_4B2940 || !v4 || (*(_DWORD *)(v4 + 28) != 24)) {
          sub_406080((int)aCurrent);
        }

      }
    } else if ( sub_485880(DIK_LMENU, 0) && *(_DWORD *)(dword_50C454 + 8) == 13 ) {

      // Alt (Left)
      //FIXME: What's the other condition?

      if ( sub_485880(DIK_RMENU, 0) ) {

        // Alt (Right)

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
      } else if ( sub_485880(DIK_RCONTROL, 0) ) {

        // Control (Right)

        if ( dword_4D79EC )
          goto LABEL_146;
        dword_4D79EC = 1;
        if ( !dword_4D5E00 )
        {
          dword_E996DC &= 0xFFFFBFFF;
          *(_BYTE *)(dword_50C454 + 110) = *(_BYTE *)(dword_50C454 + 110) == 0;
          sub_440550(47);
        }
      }
    } else if ( sub_485880(DIK_M, 0) ) {

      // M

      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;

      if (!dword_4B2950 ) {
        v2 = sub_421360(aMondotextH0036);
        strcat(&byte_4D78D0, v2);
      } else {

        if ( dword_4D6B38 ) {
          v7 = sub_421360(aMondotextH0366);
        } else {
          v7 = sub_421360(aMondotextH0365);
        }

        strcat(&byte_4D78D0, v7);
        sub_440550(70);
        dword_4D6B38 = dword_4D6B38 == 0;
        if ( !dword_4B2940 ) {
          v8 = sub_414D90(0, 25);
          sub_40B740(1, v8);
        }

        v9 = sub_411810();
        if ( dword_4B2940 || !v9 || ( *(_DWORD *)(v9 + 28) != 25 )) {
          sub_406080((int)aCurrent);
        }

      }

    } else if ( sub_485880(DIK_F, 0) ) {

      // F

      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;

      if ( !dword_4B2914 ) {
        v2 = sub_421360(aMondotextH0042); // No device detected
        strcat(&byte_4D78D0, v2);
      } else if ( !dword_4D765C ) {
        v2 = sub_421360(aMondotextH0368); // No force-effects loaded
        strcat(&byte_4D78D0, v2);
      } else {

        if ( dword_4B2910 || !dword_4B4938 ) {
          strcat(&byte_4D78D0, sub_421360(aMondotextH0370));
          sub_40A120(1);
        } else {
          strcat(&byte_4D78D0, sub_421360(aMondotextH0369));
        }

        sub_440550(70);
        if ( dword_4B2910 || (dword_4B2910 = 1, !dword_4B4938) ) {
          dword_4B2910 = 0;
        }

        //FIXME: sub_414D90 is ran conditionally for mice and joysticks - why not here?
        //FIXME: Bug in RE or game?
        v10 = sub_414D90(0, 27);
        sub_40C100(v10);

        v11 = sub_411810();
        if ( dword_4B2940 || !v11 || *(_DWORD *)(v11 + 28) != 27 ) {
          sub_40AB80((int)aCurrent);
        }

      }

    } else if ( sub_485880(DIK_Q, 0) && dword_4D5E00 ) {

      // Q (only in network mode)

      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;

      // Send packet to network
      uint32_t packet[3]; // [esp+14h] [ebp-20h]
      packet[0] = 1348564851; // 'Paws'
      packet[1] = -1;
      packet[2] = 1;
      sub_450C50(1097624609, packet); // 'All!'

    } else if ( sub_485880(DIK_F11, 0) ) {

      // F11

      if ( dword_4D79EC )
        goto LABEL_146;
      dword_4D79EC = 1;
      dword_4D79DC = dword_4D79DC == 0;
    }

  } else if ( sub_485880(DIK_F7, 0) ) {

    // F7

    if ( dword_4D79EC )
      goto LABEL_146;
    sub_440550(70);
    sub_41BDD0();
    dword_4D79EC = 1;
  } else if ( sub_485880(DIK_F5, 0) || sub_485880(DIK_F6, 0) ) {

    // F5 or F6

    if ( dword_4D79EC )
      goto LABEL_146;
    dword_4D79E0 = 1;
    dword_4D79EC = 1;
  } else if ( sub_485880(DIK_SCROLL, 0) && sub_485880(DIK_HOME, 0) ) {

    // Scroll lock + Home

    if ( dword_4D79EC )
      goto LABEL_146;
    dword_4D79EC = 1;

    if ( *(_DWORD *)(dword_50C454 + 8) == 9 ) {
      dword_50C048 ^= 0x40u;

      // Unlock all tracks and podracers
      sub_43D9A0();
    }

  } else {
    dword_4D79EC = 0;
  }

  if ( !dword_4D79EC ) {
    return;
  }

LABEL_146:
  if ( byte_4D78D0 ) {
    sub_44FCE0((int)&byte_4D78D0, 2.0f);
    byte_4D78D0 = 0;
    dword_4D5564 = 2.1f;
  }

  // Check if the cache value of truguts was changed
  // (Happens when pressing Shift + F4 + 4)
  if ( v12 != dword_E35A98[0] ) {

    //FIXME: What is dword_EC83CC ?
    if ( dword_EC83CC >= 5000 ) {
      dword_E35A98[0] = v12;
    } else {
      dword_EC83CC += 1000;
    }

  }

  return;
}

