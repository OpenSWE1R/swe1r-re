/* Code related to the input subsystem */

// Research based on patched US version


//----- (00485880) --------------------------------------------------------
// Check the keyboard state for a specific key
// a1 = DirectInput DIK_* (keycode)
// a2 = Optional pointer to output value to which the state will be added
int __cdecl sub_485880(int32_t a1, uint32_t *a2) {

  // Don't allow a negative key index to be queried
  if ( a1 < 0 ) {
    return 0;
  }

  // Early out if the keyboard is disabled?
  if ( !dword_50FEB4 ) {
    if ( a2 != NULL ) {
      *a2 = 0;
    }
    return 0;
  }

  // Add the state to the optional output value
  if ( a2 != NULL ) {
    *a2 += dword_50F668[a1];
  }

  //FIXME: Unknown
  if ( dword_50FEB0 && dword_50E868[a1] ) {
    dword_50FEB0 = 0;
  }

  // Return the current state
  return dword_50E868[a1];
}
