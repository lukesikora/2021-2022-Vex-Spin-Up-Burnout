using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor Motor15;
extern digital_out DigitalOutB;
extern digital_out DigitalOutC;
extern motor Motor20;
extern digital_out DigitalOutD;
extern motor Motor19;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );