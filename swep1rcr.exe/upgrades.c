/* Information related to podracer upgrades */

// Research based on patched US version


typedef struct {
  uint8_t index; // absolute index to identify part?
  uint8_t level; // level / quality?
  uint8_t unk1; // ?
  uint8_t category; // what kind of part it is?
  int32_t price;
  int32_t model; // model index
  char* title;
} PartData;

PartData data_4C1CB8[7 * 6]; // 7 categories x 6 levels



//----- (004493F0) --------------------------------------------------------
// Calculates the handling statistics for a podracer after an upgrade
// a1 = Output value
// a2 = Upgrade category
// a3 = Upgrade level
// a4 = Upgrade health?! [0.0, 1.0]
void __cdecl sub_4493F0(int a1, int a2, int a3, float a4) {

  switch (a2) {

  case 0:
    if (a3 == 1) {
      *(float*)a1 = clamp(a4 * 0.05f + *(float*)a1, 0.01f, 1.0f);
    }
    if (a3 == 2) {
      *(float*)a1 = clamp(a4 * 0.10f + *(float*)a1, 0.01f, 1.0f);
    }
    if (a3 == 3) {
      *(float*)a1 = clamp(a4 * 0.15f + *(float*)a1, 0.01f, 1.0f);
    }
    if (a3 == 4) {
      *(float*)a1 = clamp(a4 * 0.20f + *(float*)a1, 0.01f, 1.0f);
    }
    if (a3 == 5) {
      *(float*)a1 = clamp(a4 * 0.25f + *(float*)a1, 0.01f, 1.0f);
    }
    break;

  case 1:
    if (a3 == 1) {
      *(float*)(a1 + 4) = clamp(a4 * 116.0f + *(float*)(a1 + 4), 50.0f, 1000.0f);
    }
    if (a3 == 2) {
      *(float*)(a1 + 4) = clamp(a4 * 232.0f + *(float*)(a1 + 4), 50.0f, 1000.0f);
    }
    if (a3 == 3) {
      *(float*)(a1 + 4) = clamp(a4 * 348.0f + *(float*)(a1 + 4), 50.0f, 1000.0f);
    }
    if (a3 == 4) {
      *(float*)(a1 + 4) = clamp(a4 * 464.0f + *(float*)(a1 + 4), 50.0f, 1000.0f);
    }
    if (a3 == 5) {
      *(float*)(a1 + 4) = clamp(a4 * 578.0f + *(float*)(a1 + 4), 50.0f, 1000.0f);
    }
    break;

  case 2:
    if (a3 == 1) {
      *(float*)(a1 + 12) = clamp(((1.0f - a4) * 0.14f - -0.86f) * *(float*)(a1 + 12), 0.1f, 5.0f);
    }
    if (a3 == 2) {
      *(float*)(a1 + 12) = clamp(((1.0f - a4) * 0.28f - -0.72f) * *(float*)(a1 + 12), 0.1f, 5.0f);
    }
    if (a3 == 3) {
      *(float*)(a1 + 12) = clamp(((1.0f - a4) * 0.42f - -0.58f) * *(float*)(a1 + 12), 0.1f, 5.0f);
    }
    if (a3 == 4) {
      *(float*)(a1 + 12) = clamp(((1.0f - a4) * 0.56f - -0.44f) * *(float*)(a1 + 12), 0.1f, 5.0f);
    }
    if (a3 == 5) {
      *(float*)(a1 + 12) = clamp(((1.0f - a4) * 0.70f - -0.30f) * *(float*)(a1 + 12), 0.1f, 5.0f);
    }
    break;

  case 3:
    if (a3 == 1) {
      *(float*)(a1 + 16) = clamp(a4 * 40.0f + *(float*)(a1 + 16), 450.0f, 650.0f);
    }
    if (a3 == 2) {
      *(float*)(a1 + 16) = clamp(a4 * 80.0f + *(float*)(a1 + 16), 450.0f, 650.0f);
    }
    if (a3 == 3) {
      *(float*)(a1 + 16) = clamp(a4 * 120.0f + *(float*)(a1 + 16), 450.0f, 650.0f);
    }
    if (a3 == 4) {
      *(float*)(a1 + 16) = clamp(a4 * 160.0f + *(float*)(a1 + 16), 450.0f, 650.0f);
    }
    if (a3 == 5) {
      *(float*)(a1 + 16) = clamp(a4 * 200.0f + *(float*)(a1 + 16), 450.0f, 650.0f);
    }
    break;

  case 4:
    if (a3 == 1) {
      *(float*)(a1 + 20) = clamp(((1.0f - a4) * 0.08f - -0.92f) * *(float*)(a1 + 20), 1.0f, 1000.0f);
    }
    if (a3 == 2) {
      *(float*)(a1 + 20) = clamp(((1.0f - a4) * 0.17f - -0.83f) * *(float*)(a1 + 20), 1.0f, 1000.0f);
    }
    if (a3 == 3) {
      *(float*)(a1 + 20) = clamp(((1.0f - a4) * 0.26f - -0.74f) * *(float*)(a1 + 20), 1.0f, 1000.0f);
    }
    if (a3 == 4) {
      *(float*)(a1 + 20) = clamp(((1.0f - a4) * 0.35f - -0.65f) * *(float*)(a1 + 20), 1.0f, 1000.0f);
    }
    if (a3 == 5) {
      *(float*)(a1 + 20) = clamp(((1.0f - a4) * 0.44f - -0.56f) * *(float*)(a1 + 20), 1.0f, 1000.0f);
    }
    break;

  case 5:
    if (a3 == 1) {
      *(float*)(a1 + 36) = clamp(a4 * 1.6f + *(float*)(a1 + 36), 1.0f, 20.0f);
    }
    if (a3 == 2) {
      *(float*)(a1 + 36) = clamp(a4 * 3.2f + *(float*)(a1 + 36), 1.0f, 20.0f);
    }
    if (a3 == 3) {
      *(float*)(a1 + 36) = clamp(a4 * 4.8f + *(float*)(a1 + 36), 1.0f, 20.0f);
    }
    if (a3 == 4) {
      *(float*)(a1 + 36) = clamp(a4 * 6.4f + *(float*)(a1 + 36), 1.0f, 20.0f);
    }
    if (a3 == 5) {
      *(float*)(a1 + 36) = clamp(a4 * 8.0f + *(float*)(a1 + 36), 1.0f, 20.0f);
    }
    break;

  case 6:
    if (a3 == 1) {
      *(float*)(a1 + 44) = clamp(a4 * 0.10f + *(float*)(a1 + 44), 0.0f, 1.0f);
    }
    if (a3 == 2) {
      *(float*)(a1 + 44) = clamp(a4 * 0.20f + *(float*)(a1 + 44), 0.0f, 1.0f);
    }
    if (a3 == 3) {
      *(float*)(a1 + 44) = clamp(a4 * 0.30f + *(float*)(a1 + 44), 0.0f, 1.0f);
    }
    if (a3 == 4) {
      *(float*)(a1 + 44) = clamp(a4 * 0.40f + *(float*)(a1 + 44), 0.0f, 1.0f);
    }
    if (a3 == 5) {
      *(float*)(a1 + 44) = clamp(a4 * 0.45f + *(float*)(a1 + 44), 0.0f, 1.0f);
    }
    break;

  default:
    break;
  }
  return;
}

