/* Code related to the snapshot / screenshot feature */

// Research based on patched US version

//----- (00410480) --------------------------------------------------------
signed int __cdecl sub_410480(int a1)
{
  int v1; // ecx
  FILE *v2; // eax
  FILE *v3; // esi
  char v5; // [esp+8h] [ebp-50h]

  do
  {
    v1 = dword_4D79E4++;
    sprintf(&v5, aS03dBmp, a1, v1);
    v2 = fopen(&v5, aRb);
    v3 = v2;
    if ( !v2 )
      break;
    fclose(v2);
  }
  while ( v3 );
  return sub_489D20((int)&v5);
}
