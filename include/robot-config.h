using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Motor18;
extern motor Motor17;
extern motor Motor4;
extern motor Motor5;
extern motor Motor6;
extern motor Motor7;
extern encoder EncoderA;
extern digital_out DigitalOutC;
extern motor Motor14;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );