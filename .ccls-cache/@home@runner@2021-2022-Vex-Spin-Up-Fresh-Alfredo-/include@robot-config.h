using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Motor17;
extern motor Motor4;
extern motor Motor5;
extern motor Motor6;
extern motor Motor7;
extern digital_out DigitalOutC;
extern motor Motor14;
extern motor Motor15;
extern digital_out DigitalOutB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );