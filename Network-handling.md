## EnumSessions callback

There seem to be up to 32 sessions

* dword_513870 points at the current session index / count

```C
//----- (00487450) --------------------------------------------------------
signed int __stdcall sub_487450(int a1, int a2, char a3, int a4) {
  if ( a3 & 1 ) {
    return 0;
  }

  if ( (unsigned int)dword_513870 < 32 ) {
    sub_4876D0(a1, 0x5117E8 + dword_513870 * 260);
    dword_513870++;
  }
  return 1;
}
```