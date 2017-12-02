# Draw function

```C
//----- (0048A350) --------------------------------------------------------
// a1 = texture
// a2 = renderstates
// a3 = vertex pointer
// a4 = vertex count
// a5 = index pointer
// a6 = index count
void __cdecl sub_48A350(int a1, int a2, int a3, unsigned int a4, int a5, int a6) {
  // Check if we are below the maximum vertex count
  //FIXME: Not 100% sure
  if ( a4 <= dword_52E624 ) {

    // Prepare renderstates
    sub_48A450(a2);

    // Check if the planned texture is already set, if not, set it
    if ( a1 != dword_52E628 ) {
      //FIXME: This feels like a bug, either in the game or my RE..
      if (!dword_52E644->SetTexture(0, a1)) {
        // Update the current texture
        dword_52E628 = a1;
      }
    }

    // Draw the data
    dword_52E644->DrawIndexedPrimitive(4, 452, a3, a4, a5, a6, 24);
  }
}
```