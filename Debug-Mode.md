dword_50C044 seems to contain wether debug mode is enabled.
* dword_50C044 = 0: Disabled
* dword_50C044 = -1: Waiting for..
* dword_50C044 = -2: Waiting for..
* dword_50C044 = -3: Waiting for..
* dword_50C044 >= 1: Enabled

dword_E98EB0 seems to contain directional input of some sort. According to TCRF the digipad on N64 had to be rotated counter clockwise. The code to activate the menu at the start of sub_42AE00 seems to suggest this too.

## Pause menu

```C

//----- (0042A840) --------------------------------------------------------
int __cdecl sub_42A840(int a1, char *a2, int a3, int a4, int a5)
{
  const char *v5; // eax
  const char *v6; // eax
  int result; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax

  *(_BYTE *)a3 = 0;
  *(_DWORD *)a4 = -10000;
  *(_DWORD *)a5 = -971227136;
  switch ( a1 )
  {
    case 0:
      v5 = sub_421360(aScreentext535C);
      sprintf(a2, v5);
      if ( !dword_50C064 )
        goto LABEL_13;
      v6 = sub_421360(aScreentext366A);
      sprintf(a2, aCS, v6);
      result = 1;
      break;
    case 1:
      v10 = sub_421360(aScreentext536C);
      sprintf(a2, v10);
      if ( !dword_50C064 )
        goto LABEL_13;
      v11 = sub_421360(aScreentext367Y);
      sprintf(a2, aCS, v11);
      result = 1;
      break;
    case 2:
      v8 = sub_421360(aScreentext657C);
      sprintf(a2, v8);
      if ( !dword_50C064 )
        goto LABEL_13;
      v9 = sub_421360(aScreentext368N);
      sprintf(a2, aCS, v9);
      result = 1;
      break;
    case 3:
      v12 = sub_421360(aScreentext658C);
      sprintf(a2, v12);
      if ( dword_50C064 )
        sprintf(a2, &Class);
LABEL_13:
      result = 1;
      break;
    case 4:
      if ( dword_50C044 < 1 )
      {
        sprintf(a2, aUnimplemented);
        result = 0;
      }
      else
      {
        sprintf(a2, aCgameCheats);
        result = 1;
      }
      break;
    default:
      sprintf(a2, aUnimplemented);
      result = 0;
      break;
  }
  return result;
}
```

## Draw cheats menu

```C
//----- (0042AC70) --------------------------------------------------------
int __cdecl sub_42AC70(int a1, char *a2, int a3, int a4, int a5)
{
  switch ( dword_50C07C )
  {
    case 0: // Draws the generic cheats
      return sub_42A580(a1, a2, a3, a4, a5);
    case 1: // Draws menu to edit pods
      return sub_429DC0(a1, a2, a3, a4, a5);
    case 2: // Draws normal pause menu
      return sub_42A840(a1, a2, a3, a4, a5);
  }
  return a5;
}
```