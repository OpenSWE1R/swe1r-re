/* Code related to the input subsystem */

// Research based on patched US version


//----- (00485880) --------------------------------------------------------
int __cdecl sub_485880(int a1, _DWORD *a2)
{
  int result; // eax

  if ( a1 < 0 )
    return 0;
  if ( dword_50FEB4 )
  {
    if ( a2 )
      *a2 += dword_50F668[a1];
    if ( dword_50FEB0 && dword_50E868[a1] )
      dword_50FEB0 = 0;
    result = dword_50E868[a1];
  }
  else
  {
    if ( a2 )
      *a2 = 0;
    result = 0;
  }
  return result;
}
