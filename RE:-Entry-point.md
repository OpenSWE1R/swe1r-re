```C
//----- (004238D0) --------------------------------------------------------
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
  // Jump into the games main function
  sub_49CD40(hInstance, (int)hPrevInstance, lpCmdLine, nShowCmd, WindowName);
  return 0;
}
```

```C
//----- (0049CD40) --------------------------------------------------------
WPARAM __cdecl sub_49CD40(HINSTANCE hInstance, int a2, char *a3, int a4, LPCSTR lpWindowName) {
  int v5; // edi
  BOOL v6; // eax

  dword_DFAA2C = a4;

  // Create the window
  sub_49CEA0(hInstance, a4, lpWindowName);

  // Set some variable?!
  sub_48C770((int)dword_DFAA28);

  // Set another variable?!
  sub_48C790((int)hInstance);

  // And set another variable..
  sub_48C7B0((int *)&unk_4AF9B0);

  // ?
  InitCommonControls();


  dword_DFAA34 = 2 * GetSystemMetrics(32);
  v5 = GetSystemMetrics(32);
  dword_DFAA38 = GetSystemMetrics(15) + 2 * v5;

  // Initialize game (not an actual call probably?)
  if ( !sub_423CC0((int)GetSystemMetrics, a3) )
    return 0;

  //FIXME: I rewrote this in a weird way. It should still be correct tho
  while ( true ) {
    // Handle all messages
    struct tagMSG Msg; // [esp+10h] [ebp-1Ch]
    while(PeekMessageA(&Msg, 0, 0, 0, 0)) {
      v6 = GetMessageA(&Msg, 0, 0, 0);
      if ( v6 == -1 ) { // There was an error
        return -1;
      }
      if ( v6 == 0) { // Received a WM_QUIT
        return Msg.wParam;
      }
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
    }

    // Do gameloop
    sub_424140();
  }
  
}
```

## Create window

```C
//----- (0049CEA0) --------------------------------------------------------
// hInstance = instance
// a2 = unused?
// lpWindowName = window name
int __cdecl sub_49CEA0(HINSTANCE hInstance, int a2, LPCSTR lpWindowName) {
  int v4; // ST1C_4
  int v5; // eax
  HWND v6; // eax
  WNDCLASSEXA v7; // [esp+Ch] [ebp-30h]

  v7.cbSize = 48;
  v7.hInstance = hInstance;
  v7.lpszClassName = ClassName;
  v7.lpszMenuName = 0;
  v7.lpfnWndProc = sub_49CFD0;
  v7.style = 0;

  v7.hIcon = LoadIconA(hInstance, IconName);
  if (v7.hIcon == 0) {
    v7.hIcon = LoadIconA(0, (LPCSTR)0x7F00);
  }

  v7.hIconSm = LoadIconA(hInstance, IconName);
  if (v7.hIconSm == 0) {
    v7.hIconSm = LoadIconA(0, (LPCSTR)0x7F00);
  }

  v7.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
  v7.cbClsExtra = 0;
  v7.cbWndExtra = 0;
  v7.hbrBackground = (HBRUSH)GetStockObject(4);

  if (!RegisterClassExA(&v7)) {
    return 0;
  }

  // Quit if the game already runs
  if (FindWindowA(ClassName, lpWindowName)) {
    exit_0(-1);
  }

  v4 = GetSystemMetrics(1);
  v5 = GetSystemMetrics(0);

  dword_DFAA28 = CreateWindowExA(8u, ClassName, lpWindowName, 0x90000000, 0, 0, v5, v4, 0, 0, hInstance, 0);
  if (dword_DFAA28 == 0) {
    return 0;
  }

  ShowWindow(dword_DFAA28, 1);
  UpdateWindow(dword_DFAA28);
  return 1;
}
```