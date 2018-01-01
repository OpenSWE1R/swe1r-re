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
  dword_50D520 = 36;

  // dword_50D548 is A3d4*
  // dword_50D520 is A3DCAPS_HARDWARE
  dword_50D548->GetHardwareCaps(&dword_50D520);
  dword_50D55C = dword_50D520->dwFlags & (A3D_DIRECT_PATH_GENERIC | A3D_DIRECT_PATH_A3D); // Check & 0x28
  dword_50D554 = dword_50D520->dwFlags & A3D_1ST_REFLECTIONS; // Check & 0x2

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
    dword_50D548->SetUnitsPerMeter(3.28f); // 0x4051EB85
    dword_50D548->SetDistanceModelScale(LODWORD(flt_4C7D78));
    dword_50D548->SetDopplerScale(LODWORD(flt_4C7D74));
  }
  return 1;
}
```