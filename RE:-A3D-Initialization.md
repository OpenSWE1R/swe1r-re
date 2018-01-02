# Parse audio config

```C
//----- (00422440) --------------------------------------------------------
signed int __cdecl sub_422440(int a1) {
  char v2; // [esp+Ch] [ebp-100h]

  if ( !dword_4EB450 ) {
    return 1;
  }

  sprintf(&v2, aSSS, aDataConfig, a1, aAudioCfg);
  if ( !sub_4877B0(&v2) ) {
    sub_487900();
    return -1;
  }

  while ( sub_487AE0() ) {

    // Wait for EOF marker
    if ( !strcmp(dword_EC8E84, aEnd) ) {
      break;
    }

    // Parse an audio argument
    if ( !_strcmpi(dword_EC8E84, aAudio) ) {
      if ( !_strcmpi(dword_EC8E8C, aHires) ) {
        dword_4B6D14 = _strcmpi(dword_EC8E90, aOn) == 0;
      } else if ( !_strcmpi(dword_EC8E8C, off_4B74D0) ) {
        dword_4B6D20 = _strcmpi(dword_EC8E90, aOn) == 0;
      } else if ( !_strcmpi(dword_EC8E8C, a3d) ) {
        dword_50D550 = _strcmpi(dword_EC8E90, aOn) == 0;
      } else if ( !_strcmpi(dword_EC8E8C, aDoppler) ) {
        dword_4B6D18 = _strcmpi(dword_EC8E90, aOn) == 0;
      } else if ( !_strcmpi(dword_EC8E8C, aGainmatch) ) {
        dword_4B6D24 = atof(dword_EC8E90);
        sub_484D40(dword_4B6D24);
      } else if ( !_strcmpi(dword_EC8E8C, aVoice) ) {
        dword_4B6D28 = _strcmpi(dword_EC8E90, aOn) == 0;
      } else  if ( !_strcmpi(dword_EC8E8C, aMusic) ) {
        dword_4EB45C = _strcmpi(dword_EC8E90, aOn) == 0;
      }
    }

  }
  sub_487900();

  return 1;
}
```

# Create and initialize A3D

```C
//----- (004848A0) --------------------------------------------------------
signed int sub_4848A0() {

  // Check if we already have a A3D instance
  if ( dword_50D548 ) {
    return 0;
  }

  sub_49E940();

  // Presumably creates A3D instance
  HRESULT v1 = sub_49E970(0, &dword_50D548, 0, 128);
  if ( v1 >= 0 && dword_50D548 ) {
    dword_50D550 = 1;
  } else {
    dword_4C7D80 = 0;
    dword_50D550 = 0;
    if ( v1 < 0 ) {
      dword_50D548 = 0;
      return 0;
    }
  }

  // dword_50D548 is A3d4*
  // dword_50D520 is A3DCAPS_HARDWARE
  dword_50D520.dwSize = 36; // sizeof(A3DCAPS_HARDWARE)
  dword_50D548->GetHardwareCaps(&dword_50D520);
  dword_50D55C = dword_50D520.dwFlags & (A3D_DIRECT_PATH_GENERIC | A3D_DIRECT_PATH_A3D); // Check & 0x28
  dword_50D554 = dword_50D520.dwFlags & A3D_1ST_REFLECTIONS; // Check & 0x2

  int v2 = sub_48C780();
  if ( dword_50D548->SetCooperativeLevel(v2, 1) < 0 ) {
    dword_50D548->Release();
    dword_50D548 = 0;
    return 0;
  }

  dword_50D548->SetCoordinateSystem(0);
  dword_50D548->SetNumFallbackSources(8);
  dword_50D548->GetOutputGain(&unk_50D544);

  sub_484A80(dword_4C7D70);

  if ( dword_50D550 ) {
    if (dword_50D548->QueryInterface(&unk_4AE158, &dword_50D560) < 0 ) {
      dword_4C7D80 = 0;
      dword_50D550 = 0;
      dword_50D560 = 0;
      return 1;
    }
    dword_50D548->SetUnitsPerMeter(3.28f); // Game uses feet as unit (encoded as 0x4051EB85)
    dword_50D548->SetDistanceModelScale(LODWORD(flt_4C7D78));
    dword_50D548->SetDopplerScale(LODWORD(flt_4C7D74));
  }

  return 1;
}
```