# Prepare force feedback state

```C
//----- (0040A680) --------------------------------------------------------
int sub_40A680() {
  int result; // eax

  memset(&unk_EC8400, 0, 0x150u);
  if ( dword_EC83E0 )
  {
    if ( dword_EC83E0 == 1 )
    {
      dword_4B493C = 1058642330;
    }
    else
    {
      dword_4B493C = 1061997773;
      if ( dword_EC83E0 != 2 )
        dword_4B493C = 1065353216;
    }
  }
  else
  {
    dword_4B493C = -1082130432;
  }
  if ( dword_EC83E4 )
  {
    if ( dword_EC83E4 == 1 )
    {
      flt_EC84D0 = 0.60000002;
    }
    else
    {
      flt_EC84D0 = 0.80000001;
      if ( dword_EC83E4 != 2 )
        flt_EC84D0 = 1.0;
    }
  }
  else
  {
    flt_EC84D0 = -1.0;
  }
  flt_EC8404[0] = -1.0;
  if ( dword_EC83F8 )
    flt_EC8404[0] = 1.0;
  dword_EC8518 = -1082130432;
  if ( dword_EC83FC )
    dword_EC8518 = 1065353216;
  if ( dword_EC83E8 )
  {
    if ( dword_EC83E8 == 1 )
    {
      dword_EC84E8 = 1058642330;
    }
    else
    {
      dword_EC84E8 = 1061997773;
      if ( dword_EC83E8 != 2 )
        dword_EC84E8 = 1065353216;
    }
  }
  else
  {
    dword_EC84E8 = -1082130432;
  }
  if ( dword_EC83E8 )
  {
    if ( dword_EC83E8 == 1 )
    {
      dword_EC84F4 = 1058642330;
    }
    else
    {
      dword_EC84F4 = 1061997773;
      if ( dword_EC83E8 != 2 )
        dword_EC84F4 = 1065353216;
    }
  }
  else
  {
    dword_EC84F4 = -1082130432;
  }
  if ( dword_EC83F4 )
  {
    if ( dword_EC83F4 == 1 )
    {
      dword_EC8434 = 1058642330;
    }
    else
    {
      dword_EC8434 = 1061997773;
      if ( dword_EC83F4 != 2 )
        dword_EC8434 = 1065353216;
    }
  }
  else
  {
    dword_EC8434 = -1082130432;
  }
  if ( dword_EC83F4 )
  {
    if ( dword_EC83F4 == 1 )
    {
      dword_EC8440 = 1058642330;
    }
    else
    {
      dword_EC8440 = 1061997773;
      if ( dword_EC83F4 != 2 )
        dword_EC8440 = 1065353216;
    }
  }
  else
  {
    dword_EC8440 = -1082130432;
  }
  if ( dword_EC83F4 )
  {
    if ( dword_EC83F4 == 1 )
    {
      dword_EC8458 = 1058642330;
    }
    else
    {
      dword_EC8458 = 1061997773;
      if ( dword_EC83F4 != 2 )
        dword_EC8458 = 1065353216;
    }
  }
  else
  {
    dword_EC8458 = -1082130432;
  }
  if ( dword_EC83F4 )
  {
    if ( dword_EC83F4 == 1 )
    {
      dword_EC8464 = 1058642330;
    }
    else
    {
      dword_EC8464 = 1061997773;
      if ( dword_EC83F4 != 2 )
        dword_EC8464 = 1065353216;
    }
  }
  else
  {
    dword_EC8464 = -1082130432;
  }
  if ( dword_EC83F4 )
  {
    if ( dword_EC83F4 == 1 )
    {
      dword_EC847C = 1058642330;
    }
    else
    {
      dword_EC847C = 1061997773;
      if ( dword_EC83F4 != 2 )
        dword_EC847C = 1065353216;
    }
  }
  else
  {
    dword_EC847C = -1082130432;
  }
  if ( dword_EC83F4 )
  {
    if ( dword_EC83F4 == 1 )
    {
      dword_EC8488 = 1058642330;
    }
    else
    {
      dword_EC8488 = 1061997773;
      if ( dword_EC83F4 != 2 )
        dword_EC8488 = 1065353216;
    }
  }
  else
  {
    dword_EC8488 = -1082130432;
  }
  if ( dword_EC83F4 )
  {
    if ( dword_EC83F4 == 1 )
    {
      dword_EC841C = 1058642330;
    }
    else
    {
      dword_EC841C = 1061997773;
      if ( dword_EC83F4 != 2 )
        dword_EC841C = 1065353216;
    }
  }
  else
  {
    dword_EC841C = -1082130432;
  }
  if ( dword_EC83F4 )
  {
    if ( dword_EC83F4 == 1 )
    {
      dword_EC844C = 1058642330;
    }
    else
    {
      dword_EC844C = 1061997773;
      if ( dword_EC83F4 != 2 )
        dword_EC844C = 1065353216;
    }
  }
  else
  {
    dword_EC844C = -1082130432;
  }
  if ( dword_EC83F0 )
  {
    if ( dword_EC83F0 == 1 )
    {
      dword_EC8470 = 1058642330;
    }
    else
    {
      dword_EC8470 = 1061997773;
      if ( dword_EC83F0 != 2 )
        dword_EC8470 = 1065353216;
    }
  }
  else
  {
    dword_EC8470 = -1082130432;
  }
  result = dword_EC83EC;
  if ( dword_EC83EC )
  {
    if ( dword_EC83EC == 1 )
    {
      dword_EC850C = 1058642330;
    }
    else
    {
      dword_EC850C = 1061997773;
      if ( dword_EC83EC != 2 )
        dword_EC850C = 1065353216;
    }
  }
  else
  {
    dword_EC850C = -1082130432;
  }
  if ( dword_EC83EC )
  {
    if ( dword_EC83EC == 1 )
    {
      dword_EC8548 = 1058642330;
    }
    else
    {
      dword_EC8548 = 1061997773;
      if ( dword_EC83EC != 2 )
        dword_EC8548 = 1065353216;
    }
  }
  else
  {
    dword_EC8548 = -1082130432;
  }
  if ( dword_EC83EC )
  {
    if ( dword_EC83EC == 1 )
    {
      dword_EC8410 = 1058642330;
    }
    else
    {
      dword_EC8410 = 1061997773;
      if ( dword_EC83EC != 2 )
        dword_EC8410 = 1065353216;
    }
  }
  else
  {
    dword_EC8410 = -1082130432;
  }
  if ( dword_EC83EC )
  {
    if ( dword_EC83EC == 1 )
    {
      dword_EC8500 = 1058642330;
    }
    else
    {
      dword_EC8500 = 1061997773;
      if ( dword_EC83EC != 2 )
        dword_EC8500 = 1065353216;
    }
  }
  else
  {
    dword_EC8500 = -1082130432;
  }
  if ( dword_EC83EC )
  {
    if ( dword_EC83EC == 1 )
    {
      dword_EC853C = 1058642330;
    }
    else
    {
      dword_EC853C = 1061997773;
      if ( dword_EC83EC != 2 )
        dword_EC853C = 1065353216;
    }
  }
  else
  {
    dword_EC853C = -1082130432;
  }
  dword_EC84A0 = 1065353216;
  dword_EC8494 = 1065353216;
  dword_EC8428 = 1065353216;
  dword_EC84DC = 1065353216;
  dword_EC8524 = 1065353216;
  dword_EC8530 = 1065353216;
  dword_EC84AC = 1065353216;
  dword_EC84B8 = 1065353216;
  dword_EC84C4 = 1065353216;
  return result;
}
```