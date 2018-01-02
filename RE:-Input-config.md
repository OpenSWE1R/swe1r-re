# Write config

```C
//----- (00406080) --------------------------------------------------------
signed int __cdecl sub_406080(int a1)
{
  signed int result; // eax
  signed int v2; // ebx
  char *v3; // esi
  int v4; // ebp
  int v5; // edi
  char v6; // bl
  CHAR *v7; // eax
  char *v8; // eax
  CHAR *v9; // eax
  char *v10; // eax
  CHAR *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  int v15; // esi
  int *v16; // edi
  CHAR *v17; // eax
  char *v18; // eax
  signed int v19; // [esp+1Ch] [ebp-194h]
  char *v20; // [esp+20h] [ebp-190h]
  signed int v21; // [esp+24h] [ebp-18Ch]
  int v22; // [esp+28h] [ebp-188h]
  int *v23; // [esp+2Ch] [ebp-184h]
  char v24; // [esp+30h] [ebp-180h]
  char v25; // [esp+50h] [ebp-160h]
  char v26; // [esp+70h] [ebp-140h]
  char v27; // [esp+90h] [ebp-120h]
  char v28; // [esp+B0h] [ebp-100h]

  sprintf(&v28, aSSSS, aDataConfig, a1, a1, aControlMap);
  if ( sub_4877D0(&v28) )
  {
    v2 = 0;
    v19 = 0;
    while ( 1 )
    {
      if ( v2 )
      {
        if ( v2 == 1 )
        {
          v20 = byte_4D6518;
          v21 = 3;
          v23 = dword_EC8790;
          v22 = dword_4D6B38;
          sprintf(&v25, aMouse);
        }
        else if ( v2 == 2 )
        {
          v20 = byte_4D6828;
          v21 = 0;
          v22 = dword_4B2948;
          sprintf(&v25, aKeyboard);
        }
      }
      else
      {
        v20 = byte_4D5FC0;
        v21 = 6;
        v23 = dword_EC8880;
        v22 = dword_4B2944;
        sprintf(&v25, aJoystick);
      }
      sub_4879F0(aSMappings, &v25);
      v3 = v20;
      if ( *v20 != -1 )
        break;
LABEL_28:
      sub_4879F0(asc_4B3D48);
      v15 = 0;
      if ( v21 > 0 )
      {
        v16 = v23;
        do
        {
          if ( *v16 )
          {
            v17 = sub_407B00(v15, &unk_4B2AF0);
            v18 = sub_421470(v17);
            sprintf(&v24, aAxisS, v18);
            sub_4879F0(a28s28sflipAxis, &v25, &v24);
          }
          ++v15;
          ++v16;
        }
        while ( v15 < v21 );
      }
      if ( v2 < 2 && dword_EC8780[v2] != 1065353216 )
      {
        sprintf(&v24, aSensitivity02f, (_QWORD)dword_EC8780[v2]);
        sub_4879F0(a28s28s, &v25, &v24);
      }
      if ( !v2 && dword_EC876C != *(float *)&dword_4B297C )
      {
        sprintf(&v24, aDeadzone02f, dword_EC876C);
        sub_4879F0(a28s28s, &v25, &v24);
      }
      if ( v22 )
        sprintf(&v24, aEnabledTrue);
      else
        sprintf(&v24, aEnabledFalse);
      sub_4879F0(a28s28s, &v25, &v24);
      v19 = ++v2;
      if ( v2 >= 3 )
      {
        sub_4879A0(aEnd_0);
        sub_487960();
        return 1;
      }
    }
    while ( 1 )
    {
      v4 = *((_DWORD *)v3 + 2);
      v5 = *((_DWORD *)v3 + 1);
      v6 = *v3;
      v3 += 12;
      sprintf(&v26, &Class);
      if ( v6 & 8 && v19 != 2 )
      {
        v7 = sub_407B00(v5, &unk_4B2B28);
        v8 = sub_421470(v7);
        sprintf(&v24, aButtonS, v8);
      }
      else if ( v6 & 8 && v19 == 2 )
      {
        v9 = sub_407B00(v5, &unk_4B2BD0);
        v10 = sub_421470(v9);
        sprintf(&v24, aKeyS, v10);
      }
      else if ( v6 & 4 )
      {
        v11 = sub_407B00(v5, &unk_4B2AF0);
        v12 = sub_421470(v11);
        sprintf(&v24, aAxisS, v12);
        if ( v6 & 0x10 )
        {
          sprintf(&v26, aAxisRangePosit);
        }
        else if ( v6 & 0x20 )
        {
          sprintf(&v26, aAxisRangeNegat);
        }
      }
      if ( !(v6 & 8) )
        v6 &= 0xCFu;
      v13 = sub_407D90(v4, v6 & 0xF3);
      v14 = sub_421470(v13);
      if ( v14 )
      {
        sprintf(&v27, aFunctionS, v14);
        if ( sub_4879F0(a28s28s28s28s, &v25, &v24, &v27, &v26) )
          break;
      }
      if ( *v3 == -1 )
      {
        v2 = v19;
        goto LABEL_28;
      }
    }
    sub_487960();
    result = 0;
  }
  else
  {
    sub_487960();
    result = -1;
  }
  return result;
}
```

# Read config

```C
//----- (00406470) --------------------------------------------------------
signed int __cdecl sub_406470(int a1, const char *a2, int a3)
{
  signed int result; // eax
  int v4; // ebx
  signed int v5; // edi
  char *v6; // ebp
  unsigned int v7; // ebx
  const char **v8; // esi
  const char *v9; // ST10_4
  BOOL v10; // eax
  char *v11; // ecx
  int v12; // eax
  _DWORD *v13; // esi
  int v14; // [esp+10h] [ebp-130h]
  int v15; // [esp+14h] [ebp-12Ch]
  int v16; // [esp+18h] [ebp-128h]
  char *v17; // [esp+1Ch] [ebp-124h]
  char v18[4]; // [esp+20h] [ebp-120h]
  int v19; // [esp+2Ch] [ebp-114h]
  int v20; // [esp+30h] [ebp-110h]
  int v21; // [esp+34h] [ebp-10Ch]
  int v22; // [esp+38h] [ebp-108h]
  int v23; // [esp+3Ch] [ebp-104h]
  char v24; // [esp+40h] [ebp-100h]

  strcpy(v18, "control.map");
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  if ( a3 )
  {
    if ( !strcmp(a2, aWheel) )
    {
      sprintf(v18, aWheelMap);
    }
    else if ( strlen(a2) != 0 )
    {
      sprintf(v18, aS_0, a2);
    }
    sprintf(&v24, aSSS_0, &unk_E9F300, aDataConfigDefa, v18);
  }
  else
  {
    sprintf(&v24, aSSSS, aDataConfig, a2, a2, aControlMap);
  }
  if ( sub_4877B0(&v24) )
  {
    v4 = a1;
    if ( a1 < 0 || !a1 )
      memset(dword_EC8880, 0, 0x18u);
    if ( a1 < 0 || a1 == 1 )
    {
      dword_EC8790[0] = 0;
      dword_EC8794 = 0;
      dword_EC8798 = 0;
    }
    sub_407800(a1);
    if ( sub_487AE0() )
    {
      v5 = (signed int)v17;
      v6 = v17;
      while ( strcmp(dword_EC8E84, aEnd) )
      {
        v7 = 0;
        LOBYTE(v14) = 0;
        v15 = 0;
        v16 = -1;
        if ( dword_EC8E80 )
        {
          v8 = (const char **)&dword_EC8E84;
          while ( 1 )
          {
            if ( _strcmpi(*v8, aJoystick) )
            {
              if ( _strcmpi(*v8, aMouse) )
              {
                if ( _strcmpi(*v8, aKeyboard) )
                {
                  if ( _strcmpi(*v8, aAxis) )
                  {
                    if ( _strcmpi(*v8, aButton) )
                    {
                      if ( _strcmpi(*v8, off_4B3E68) )
                      {
                        if ( _strcmpi(*v8, aFunction) )
                        {
                          if ( _strcmpi(*v8, aAxisRange) )
                          {
                            if ( a1 >= 0 && a1 != v5 || _strcmpi(*v8, aFlipAxis) )
                            {
                              if ( _strcmpi(*v8, aSensitivity) )
                              {
                                if ( _strcmpi(*v8, aDeadzone) )
                                {
                                  if ( !_strcmpi(*v8, aEnabled) )
                                  {
                                    v10 = _strcmpi(v8[1], aTrue) == 0;
                                    if ( v5 )
                                    {
                                      if ( v5 == 1 )
                                      {
                                        if ( !v10 || (dword_4D6B38 = 1, !dword_4B2950) )
                                          dword_4D6B38 = 0;
                                      }
                                    }
                                    else
                                    {
                                      dword_4B2944 = v10 && dword_4B294C;
                                    }
                                  }
                                }
                                else if ( !v5 )
                                {
                                  dword_EC876C = atof(v8[1]);
                                }
                              }
                              else
                              {
                                *(float *)&dword_EC8780[v5] = atof(v8[1]);
                              }
                            }
                            else if ( v5 )
                            {
                              if ( v5 != 1 )
                                break;
                              dword_EC8790[v15] = 1;
                            }
                            else
                            {
                              dword_EC8880[v15] = 1;
                            }
                          }
                          else if ( _strcmpi(v8[1], aPositive) )
                          {
                            if ( _strcmpi(v8[1], aNegative) )
                              break;
                            LOBYTE(v14) = v14 | 0x20;
                          }
                          else
                          {
                            LOBYTE(v14) = v14 | 0x10;
                          }
                        }
                        else if ( !sub_407CD0((int)&v14, v8[1], 0) )
                        {
                          break;
                        }
                      }
                      else
                      {
                        LOBYTE(v14) = v14 | 8;
                        v15 = sub_407A90(v8[1], &unk_4B2BD0);
                      }
                    }
                    else
                    {
                      v9 = v8[1];
                      LOBYTE(v14) = v14 | 8;
                      v15 = sub_407A90(v9, &unk_4B2B28);
                    }
                  }
                  else
                  {
                    LOBYTE(v14) = v14 | 4;
                    v15 = sub_407A90(v8[1], &unk_4B2AF0);
                  }
                }
                else
                {
                  v5 = 2;
                  v6 = byte_4D6828;
                }
              }
              else
              {
                v5 = 1;
                v6 = byte_4D6518;
              }
            }
            else
            {
              v5 = 0;
              v6 = byte_4D5FC0;
            }
            if ( v15 < 0 )
              break;
            ++v7;
            v8 += 2;
            if ( v7 >= dword_EC8E80 )
              goto LABEL_65;
          }
          sub_407800(a1);
          sub_487900();
          return 0;
        }
LABEL_65:
        if ( (a1 < 0 || a1 == v5) && v16 > -1 )
        {
          v11 = &v6[12 * dword_4D5E20[v5]];
          *(_DWORD *)v11 = v14;
          *((_DWORD *)v11 + 1) = v15;
          *((_DWORD *)v11 + 2) = v16;
          ++dword_4D5E20[v5];
        }
        v4 = a1;
        if ( !sub_487AE0() )
          break;
      }
    }
    if ( v4 >= 0 && v4 != 2 )
    {
      v12 = dword_4D5E28;
    }
    else
    {
      LOBYTE(v14) = 10;
      v12 = dword_4D5E28 + 1;
      v13 = (_DWORD *)(12 * dword_4D5E28++ + 5072936);
      *v13 = v14;
      v13[1] = 1;
      v13[2] = 10;
    }
    if ( v4 < 0 || !v4 )
      byte_4D5FC0[12 * dword_4D5E20[0]] = -1;
    if ( v4 < 0 || v4 == 1 )
      byte_4D6518[12 * dword_4D5E24] = -1;
    if ( v4 < 0 || v4 == 2 )
      byte_4D6828[12 * v12] = -1;
    sub_487900();
    result = 1;
  }
  else
  {
    sub_487900();
    result = -1;
  }
  return result;
}
```