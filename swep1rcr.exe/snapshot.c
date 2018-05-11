/* Code related to the snapshot / screenshot feature */

// Research based on patched US version

//----- (00410480) --------------------------------------------------------
signed int __cdecl sub_410480(int a1)
{
  int v1; // ecx
  FILE *v2; // eax
  char v5; // [esp+8h] [ebp-50h]

  // Search for a free screenshot index
  do {

    // Get index for this screenshot and construct filename
    int v1 = dword_4D79E4++;
    sprintf(&v5, aS03dBmp, a1, v1);

    // Try to open the file (for read access)
    v2 = fopen(&v5, aRb);

    // If we were unable to open it, assume that it doesn't exist.
    // This means we have found a free index, so we can leave the loop
    if (v2 == NULL) {
      break;
    }

    // If we opened the file successfully, close it
    fclose(v2);

  } while ( v2 );

  // Take the actual screenshot now
  return sub_489D20((int)&v5);
}
