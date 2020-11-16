#include <inttypes.h>

//Channel Definitions
#define TOTAL_CHANNELS 5

#define MODE_CHANNEL 1
#define PROGRAM_CHANNEL 2
#define DIMMER_CHANNEL 3
#define STROBE_CHANNEL 4

#ifndef dmxController_h
#define dmxController_h

class dmxController {
    public:
        void init();
        void setMatrix(uint8_t mode, uint8_t program, uint8_t dimmer, uint8_t strobe);
};

#endif