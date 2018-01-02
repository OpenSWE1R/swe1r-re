```C
//----- (00408880) --------------------------------------------------------
signed int __cdecl sub_408880(int a1)
{
  signed int result; // eax
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char v8; // [esp+0h] [ebp-140h]
  char v9; // [esp+20h] [ebp-120h]
  char v10; // [esp+40h] [ebp-100h]

  sprintf(&v10, aSSS, aDataConfig, a1, aVideoCfg);
  if ( sub_4877D0(&v10) )
  {
    sprintf(&v9, aVideo);
    if ( sub_4879F0(aSSettings, &v9) )
      goto LABEL_30;
    v2 = aOn;
    if ( !dword_EC86A0 )
      v2 = (char *)&off_4B4808;
    sprintf(&v8, aReflectionsS, v2);
    if ( sub_4879F0(a28s28s, &v9, &v8) )
      goto LABEL_30;
    v3 = aOn;
    if ( !dword_EC86A4 )
      v3 = (char *)&off_4B4808;
    sprintf(&v8, aZeffectsS, v3);
    if ( sub_4879F0(a28s28s, &v9, &v8) )
      goto LABEL_30;
    v4 = aOn;
    if ( !dword_EC86A8 )
      v4 = (char *)&off_4B4808;
    sprintf(&v8, aDynamicLightin_0, v4);
    if ( sub_4879F0(a28s28s, &v9, &v8) )
      goto LABEL_30;
    v5 = aOn;
    if ( !dword_EC86AC )
      v5 = (char *)&off_4B4808;
    sprintf(&v8, aVsyncS, v5);
    if ( sub_4879F0(a28s28s, &v9, &v8) )
      goto LABEL_30;
    v6 = aOn;
    if ( !dword_EC86B0 )
      v6 = (char *)&off_4B4808;
    sprintf(&v8, aLensflareS, v6);
    if ( sub_4879F0(a28s28s, &v9, &v8) )
      goto LABEL_30;
    v7 = aOn;
    if ( !dword_EC86B4 )
      v7 = (char *)&off_4B4808;
    sprintf(&v8, aEngineexhaustS, v7);
    if ( sub_4879F0(a28s28s, &v9, &v8)
      || (sprintf(&v8, aTextureResI, dword_EC86B8), sub_4879F0(a28s28s, &v9, &v8))
      || (sprintf(&v8, aModelDetailI, dword_EC86BC), sub_4879F0(a28s28s, &v9, &v8))
      || (sprintf(&v8, aDrawdistanceI, dword_EC86C0), sub_4879F0(a28s28s, &v9, &v8))
      || sub_4879A0(aEnd_0) )
    {
LABEL_30:
      sub_487960();
      result = 0;
    }
    else
    {
      sub_487960();
      result = 1;
    }
  }
  else
  {
    sub_487960();
    result = -1;
  }
  return result;
}
```