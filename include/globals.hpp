#include <inttypes.h>

//Channel Definitions
#define TOTAL_CHANNELS 4

#define MODE_CHANNEL 1
#define PROGRAM_CHANNEL 2
#define DIMMER_CHANNEL 3
#define STROBE_CHANNEL 4

extern uint8_t GLOBAL_MODE;
extern uint8_t GLOBAL_PROGRAM;
extern uint8_t GLOBAL_DIMMER;
extern uint8_t GLOBAL_STROBE;