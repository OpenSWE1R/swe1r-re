dword_50C044 seems to contain wether debug mode is enabled.
* dword_50C044 = 0: Disabled
* dword_50C044 = -1: Waiting for..
* dword_50C044 = -2: Waiting for..
* dword_50C044 = -3: Waiting for..
* dword_50C044 >= 1: Enabled

dword_E98EB0 seems to contain directional input of some sort. According to TCRF the digipad on N64 had to be rotated counter clockwise. The code to activate the menu at the start of sub_42AE00 seems to suggest this too.

To enable the menu from GDB in OpenSWE1R, use `set *(uint32_t*)Memory(0x50C044) = 1`

dword_50C048 is a bitmask that seems to control what menu options are shown. To show all menu options, use `set *(uint32_t*)Memory(0x50C048) = 0xFFFFFFFF`. This might have unintended sideeffects though.

## Draw normal Pause menu

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

## Draw Pause or Cheats menu

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

# Draw position when debug level >= 2

The position actually seems to come out of the translation of a 3x4 matrix at dword_DFB21C

```C
//----- (00483BE0) --------------------------------------------------------
// a1 = debug level
void __cdecl sub_483BE0(signed int a1)
{
  int v1; // ST10_4
  int v2; // ST0C_4
  int v3; // ST08_4
  const char *v4; // eax
  double v5; // st7
  const char *v6; // eax
  char v7; // [esp+8h] [ebp-40h]

  // Check the debug level
  if ( a1 >= 2 ) {

    // Get X,Y,Z position
    v1 = (signed __int64)*(float *)&dword_DFB254;
    v2 = (signed __int64)*(float *)&dword_DFB250;
    v3 = (signed __int64)*(float *)&dword_DFB24C;

    // Create a string for it
    v4 = sub_421360(aRSposDDD);
    sprintf(&v7, v4, v3, v2, v1);

    // Draw the string
    sub_450590(4, 285, 214, (int)&v7);

    // Unknown check
    v5 = sub_45D390();
    if ( v5 > 0.0 ) {
      // Create a string for it
      v6 = sub_421360(aRScomp5f);
      sprintf(&v7, v6, LODWORD(v5), (_DWORD)(*(unsigned __int64 *)&v5 >> 32));

      // Draw the string
      sub_450590(4, 300, 194, (int)&v7);
    }
  }
}
```