# Parse config

```C
//----- (0040AE40) --------------------------------------------------------
signed int __cdecl sub_40AE40(int a1) {
  signed int result; // eax
  int v2; // eax
  char v3; // [esp+10h] [ebp-100h]

  sprintf(&v3, aSSS, aDataConfig, a1, aForceCfg);
  if ( sub_4877B0(&v3) )
  {
    if ( sub_487AE0() )
    {
      while ( strcmp(dword_EC8E84, aEnd) )
      {
        if ( !_strcmpi(dword_EC8E84, aForcefeedback) )
        {
          if ( _strcmpi(dword_EC8E8C, aStrength) )
          {
            if ( _strcmpi(dword_EC8E8C, aAutocenter) )
            {
              if ( _strcmpi(dword_EC8E8C, aCollisions) )
              {
                if ( _strcmpi(dword_EC8E8C, aDamage) )
                {
                  if ( _strcmpi(dword_EC8E8C, aTerrain) )
                  {
                    if ( _strcmpi(dword_EC8E8C, aPodactions) )
                    {
                      if ( _strcmpi(dword_EC8E8C, aGforces) )
                      {
                        if ( _strcmpi(dword_EC8E8C, aEnginerumble) )
                        {
                          if ( _strcmpi(dword_EC8E8C, aEnabled) )
                          {
                            sub_487900();
                            return 0;
                          }
                          if ( !dword_4B4938
                            || !dword_4B2914
                            || (v2 = _strcmpi(dword_EC8E90, aTrue), dword_4B2910 = 1, v2) )
                          {
                            dword_4B2910 = 0;
                          }
                        }
                        else
                        {
                          dword_EC83FC = _strcmpi(dword_EC8E90, aOn) == 0;
                        }
                      }
                      else
                      {
                        dword_EC83F8 = _strcmpi(dword_EC8E90, aOn) == 0;
                      }
                    }
                    else
                    {
                      dword_EC83F4 = atoi(dword_EC8E90);
                    }
                  }
                  else
                  {
                    dword_EC83F0 = atoi(dword_EC8E90);
                  }
                }
                else
                {
                  dword_EC83EC = atoi(dword_EC8E90);
                }
              }
              else
              {
                dword_EC83E8 = atoi(dword_EC8E90);
              }
            }
            else
            {
              dword_EC83E4 = atoi(dword_EC8E90);
            }
          }
          else
          {
            dword_EC83E0 = atoi(dword_EC8E90);
          }
        }
        if ( !sub_487AE0() )
          break;
      }
    }
    sub_487900();
    sub_40A680();
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