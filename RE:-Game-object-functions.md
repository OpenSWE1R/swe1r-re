# Get game object

This is at least used for podracers. To get the podracer stats, this is called with "Test" as first argument.
I've also seen "cMan", "Jdge", "Elmo" and "Trig" for other parts. There are probably other magics too

* `sub_450B00(1416784231);` counts the number of podracers. The first argument is always a 4 byte magic string.
* `sub_450B30(1416784231, a2);` gets the pointer to podracer a2, first argument uses same style as the other function.
* `sub_450AA0(1666015598, a2);` gets the pointer to an object? first argument uses same style as the other function.

# Debug menu to print podracer stats

```C
//----- (00429DC0) --------------------------------------------------------
int __cdecl sub_429DC0(int a1, char *a2, int a3, int a4, int a5) {
  int v5; // esi
  const char *v6; // ST0C_4
  const char *v7; // eax
  int result; // eax
  double v9; // st7

  *(_BYTE *)a3 = 0;

  // Get the current selected podracer pointer
  v5 = sub_450AA0(1415934836, dword_50C050);
  if ( !v5 )
    return 0;

  *(_DWORD *)a4 = -10000;
  switch ( a1 ) {
    case 0:
      v6 = sub_421360(*(const char **)(*(_DWORD *)(*(_DWORD *)(v5 + 7792) + 24) + 24));
      v7 = sub_421360(*(const char **)(*(_DWORD *)(*(_DWORD *)(v5 + 7792) + 24) + 20));
      sprintf(a2, aNameSS, v7, v6);
      result = 1;
      *(_DWORD *)a5 = -943501440;
      break;
    case 1:
      sprintf(a2, aAntiSkid);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 108);
      result = 1;
      break;
    case 2:
      sprintf(a2, aTurnResponse);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 112);
      result = 1;
      break;
    case 3:
      sprintf(a2, aMaxTurnRate);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 116);
      result = 1;
      break;
    case 4:
      sprintf(a2, aAcceleration);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 120);
      result = 1;
      break;
    case 5:
      sprintf(a2, aMaxSpeed);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 124);
      result = 1;
      break;
    case 6:
      sprintf(a2, aAirbrakeInv);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 128);
      result = 1;
      break;
    case 7:
      sprintf(a2, aDecelInv);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 132);
      result = 1;
      break;
    case 8:
      sprintf(a2, aBoostThrust);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 136);
      result = 1;
      break;
    case 9:
      sprintf(a2, aHeatRate);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 140);
      result = 1;
      break;
    case 10:
      sprintf(a2, aCoolRate);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 144);
      result = 1;
      break;
    case 11:
      sprintf(a2, aHoverHeight);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 148);
      result = 1;
      break;
    case 12:
      sprintf(a2, aRepairRate);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 152);
      result = 1;
      break;
    case 13:
      sprintf(a2, aBumpMass);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 156);
      result = 1;
      break;
    case 14:
      sprintf(a2, aDmgImmunity);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 160);
      result = 1;
      break;
    case 15:
      sprintf(a2, aIsectRadius);
      *(_DWORD *)a5 = *(_DWORD *)(v5 + 168);
      result = 1;
      break;
    case 16:
      sprintf(a2, aAiLookAhead);
      v9 = sub_480670(*(float *)(v5 + 264));
      result = 1;
      *(float *)a5 = v9;
      break;
    default:
      sprintf(a2, aUnimplemented);
      *(_DWORD *)a5 = 0;
      return 0;
  }
  return result;
}
```

## Podracer struct

FIXME: Name
```
v6 = sub_421360(*(const char **)(*(_DWORD *)(*(_DWORD *)(v5 + 7792) + 24) + 24)); // prename?
v7 = sub_421360(*(const char **)(*(_DWORD *)(*(_DWORD *)(v5 + 7792) + 24) + 20)); // lastname?
sprintf(a2, aNameSS, v7, v6);
```

```C
struct {
uint8_t unk[108];
float AntiSkid; // 108
float TurnResponse; // 112
float MaxTurnRate; // 116
float Acceleration; // 120
float MaxSpeed; // 124
float AirbrakeInv; // 128
float DecelInv; // 132
float BoostThrust; // 136
float HeatRate; // 140
float CoolRate; // 144
float HoverHeight; // 148
float RepairRate; // 152
float BumpMass // 156
float DmgImmunity // 160
float unknown; // 164
float IsectRadius; // 168
float AiLookAhead // 264 (displayed as sqrt(AiLookAhead) in menu)

... FIXME

struct {
  uint8_t unk[24];
  struct { // 24
    uint8_t unk[20];
    const char* prename; // 20
    const char* lastname; // 24
  }* name_second_ptr;
}* name_first_ptr; // 7792

}
```

# Object lookup

```C
//----- (00450AA0) --------------------------------------------------------
int __cdecl sub_450AA0(int a1, int a2) {
  char **v2; // edi
  char *v3; // ecx
  signed int v4; // esi
  int result; // eax
  int v6; // edx

  // Access object table (this might actually be a list of lists?)
  v2 = off_4BFEC0;

  while ( 1 ) {
    v3 = *v2++;

    // If there is no object, we have reached the end of the object list
    if ( !v3 ) {
      return 0;
    }

    // Check if this is the object type we are looking for
    if ( *(_DWORD *)v3 != a1 ) {
      continue;
    }

    v4 = *((_DWORD *)v3 + 2);
    result = *((_DWORD *)v3 + 4);

    //FIXME: Turn this into a for-loop
    v6 = 0;
    if ( v4 > 0 ) {
      while( *(_WORD *)(result + 6) & 0x100 || *(signed __int16 *)(result + 4) != a2 ) {
        result += *((_DWORD *)v3 + 3);
        if ( (signed __int16)++v6 >= v4 ) {
          break;
        }
      }
    }

  }

  return result;
}
```