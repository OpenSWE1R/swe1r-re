/* Information related to podracer upgrades */

// Research based on patched US version

#include "handling.h"

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
// Calculates the handling data for a podracer after an upgrade
// a1 = Handling data to be modified
// a2 = Upgrade category
// a3 = Upgrade level
// a4 = Upgrade health?! [0.0, 1.0]
void __cdecl sub_4493F0(PodracerHandlingData* a1, int32_t a2, int32_t a3, float a4) {

  switch (a2) {

  case 0:
    if (a3 == 1) {
      a1->AntiSkid = clamp(a4 * 0.05f + a1->AntiSkid, 0.01f, 1.0f);
    }
    if (a3 == 2) {
      a1->AntiSkid = clamp(a4 * 0.10f + a1->AntiSkid, 0.01f, 1.0f);
    }
    if (a3 == 3) {
      a1->AntiSkid = clamp(a4 * 0.15f + a1->AntiSkid, 0.01f, 1.0f);
    }
    if (a3 == 4) {
      a1->AntiSkid = clamp(a4 * 0.20f + a1->AntiSkid, 0.01f, 1.0f);
    }
    if (a3 == 5) {
      a1->AntiSkid = clamp(a4 * 0.25f + a1->AntiSkid, 0.01f, 1.0f);
    }
    break;

  case 1:
    if (a3 == 1) {
      a1->TurnResponse = clamp(a4 * 116.0f + a1->TurnResponse, 50.0f, 1000.0f);
    }
    if (a3 == 2) {
      a1->TurnResponse = clamp(a4 * 232.0f + a1->TurnResponse, 50.0f, 1000.0f);
    }
    if (a3 == 3) {
      a1->TurnResponse = clamp(a4 * 348.0f + a1->TurnResponse, 50.0f, 1000.0f);
    }
    if (a3 == 4) {
      a1->TurnResponse = clamp(a4 * 464.0f + a1->TurnResponse, 50.0f, 1000.0f);
    }
    if (a3 == 5) {
      a1->TurnResponse = clamp(a4 * 578.0f + a1->TurnResponse, 50.0f, 1000.0f);
    }
    break;

  case 2:
    if (a3 == 1) {
      a1->Acceleration = clamp(((1.0f - a4) * 0.14f - -0.86f) * a1->Acceleration, 0.1f, 5.0f);
    }
    if (a3 == 2) {
      a1->Acceleration = clamp(((1.0f - a4) * 0.28f - -0.72f) * a1->Acceleration, 0.1f, 5.0f);
    }
    if (a3 == 3) {
      a1->Acceleration = clamp(((1.0f - a4) * 0.42f - -0.58f) * a1->Acceleration, 0.1f, 5.0f);
    }
    if (a3 == 4) {
      a1->Acceleration = clamp(((1.0f - a4) * 0.56f - -0.44f) * a1->Acceleration, 0.1f, 5.0f);
    }
    if (a3 == 5) {
      a1->Acceleration = clamp(((1.0f - a4) * 0.70f - -0.30f) * a1->Acceleration, 0.1f, 5.0f);
    }
    break;

  case 3:
    if (a3 == 1) {
      a1->MaxSpeed = clamp(a4 * 40.0f + a1->MaxSpeed, 450.0f, 650.0f);
    }
    if (a3 == 2) {
      a1->MaxSpeed = clamp(a4 * 80.0f + a1->MaxSpeed, 450.0f, 650.0f);
    }
    if (a3 == 3) {
      a1->MaxSpeed = clamp(a4 * 120.0f + a1->MaxSpeed, 450.0f, 650.0f);
    }
    if (a3 == 4) {
      a1->MaxSpeed = clamp(a4 * 160.0f + a1->MaxSpeed, 450.0f, 650.0f);
    }
    if (a3 == 5) {
      a1->MaxSpeed = clamp(a4 * 200.0f + a1->MaxSpeed, 450.0f, 650.0f);
    }
    break;

  case 4:
    if (a3 == 1) {
      a1->AirbrakeInv = clamp(((1.0f - a4) * 0.08f - -0.92f) * a1->AirbrakeInv, 1.0f, 1000.0f);
    }
    if (a3 == 2) {
      a1->AirbrakeInv = clamp(((1.0f - a4) * 0.17f - -0.83f) * a1->AirbrakeInv, 1.0f, 1000.0f);
    }
    if (a3 == 3) {
      a1->AirbrakeInv = clamp(((1.0f - a4) * 0.26f - -0.74f) * a1->AirbrakeInv, 1.0f, 1000.0f);
    }
    if (a3 == 4) {
      a1->AirbrakeInv = clamp(((1.0f - a4) * 0.35f - -0.65f) * a1->AirbrakeInv, 1.0f, 1000.0f);
    }
    if (a3 == 5) {
      a1->AirbrakeInv = clamp(((1.0f - a4) * 0.44f - -0.56f) * a1->AirbrakeInv, 1.0f, 1000.0f);
    }
    break;

  case 5:
    if (a3 == 1) {
      a1->CoolRate = clamp(a4 * 1.6f + a1->CoolRate, 1.0f, 20.0f);
    }
    if (a3 == 2) {
      a1->CoolRate = clamp(a4 * 3.2f + a1->CoolRate, 1.0f, 20.0f);
    }
    if (a3 == 3) {
      a1->CoolRate = clamp(a4 * 4.8f + a1->CoolRate, 1.0f, 20.0f);
    }
    if (a3 == 4) {
      a1->CoolRate = clamp(a4 * 6.4f + a1->CoolRate, 1.0f, 20.0f);
    }
    if (a3 == 5) {
      a1->CoolRate = clamp(a4 * 8.0f + a1->CoolRate, 1.0f, 20.0f);
    }
    break;

  case 6:
    if (a3 == 1) {
      a1->RepairRate = clamp(a4 * 0.10f + a1->RepairRate, 0.0f, 1.0f);
    }
    if (a3 == 2) {
      a1->RepairRate = clamp(a4 * 0.20f + a1->RepairRate, 0.0f, 1.0f);
    }
    if (a3 == 3) {
      a1->RepairRate = clamp(a4 * 0.30f + a1->RepairRate, 0.0f, 1.0f);
    }
    if (a3 == 4) {
      a1->RepairRate = clamp(a4 * 0.40f + a1->RepairRate, 0.0f, 1.0f);
    }
    if (a3 == 5) {
      a1->RepairRate = clamp(a4 * 0.45f + a1->RepairRate, 0.0f, 1.0f);
    }
    break;

  default:
    break;
  }
  return;
}

