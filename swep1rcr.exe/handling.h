typedef struct {
  float AntiSkid; // 0
  float TurnResponse; // 4
  float MaxTurnRate; // 8
  float Acceleration; // 12
  float MaxSpeed; // 16
  float AirbrakeInv; // 20
  float DecelInv; // 24
  float BoostThrust; // 28
  float HeatRate; // 32
  float CoolRate; // 36
  float HoverHeight; // 40
  float RepairRate; // 44
  float BumpMass; // 48
  float DmgImmunity; // 52
} PACKED PodracerHandlingData;

// This is the format used for storing information in the binary.
// At load time, IsectRadius is shifted back by 4 additional bytes.
// So it is seperated here so we can re-use PodracerHandlingData.
typedef struct {
  PodracerHandlingData
  float IsectRadius; // 56
} PACKED PodracerHandlingTableData;
