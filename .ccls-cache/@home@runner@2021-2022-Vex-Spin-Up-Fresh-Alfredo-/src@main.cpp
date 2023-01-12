/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lsikora25                                        */
/*    Created:      Thu Sep 08 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor17              motor         17              
// Motor4               motor         4               
// Motor5               motor         5               
// Motor6               motor         6               
// Motor7               motor         7               
// DigitalOutC          digital_out   C               
// Motor14              motor         14              
// Motor15              motor         15              
// DigitalOutB          digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
competition Competition;
int Brain_precision = 0, Console_precision = 0, Controller1_precision = 0;
float myVariable;


void drawSmileyAt(int x, int y){
  Brain.Screen.drawCircle(x, y, 40, yellow);
  Brain.Screen.drawCircle(x-20, y-10, 10, blue);
  Brain.Screen.drawCircle(x+20, y-10, 10, blue);
  Brain.Screen.drawRectangle(x-20, y+10, 40, 10, red);
}

void burnout() {
  Brain.Screen.setFont(mono15);
  Brain.Screen.newLine();
  Brain.Screen.print("Pizza;\x0AWord");
}

void porsche() {
  Brain.Screen.setFont(mono15);
  Brain.Screen.newLine();
  Brain.Screen.print("              ____----------- _____");
  Brain.Screen.newLine();
  Brain.Screen.print("\\~~~~~~~~~~/~_--~~~------~~~~~     \\");
  Brain.Screen.newLine();
  Brain.Screen.print(" `---`\\  _-~      |                   \\");
  Brain.Screen.newLine();
  Brain.Screen.print("   _-~  <_         |                     \\[]");
  Brain.Screen.newLine();
  Brain.Screen.print(" / ___     ~~--[""] |      ________-------'_");
  Brain.Screen.newLine();
  Brain.Screen.print("> /~` \\    |-.   `\\~~.~~~~~                _ ~ - _");
  Brain.Screen.newLine();
  Brain.Screen.print(" ~|  ||\\%  |       |    ~  ._                ~ _   ~ ._");
  Brain.Screen.newLine();
  Brain.Screen.print("   `_//|_%  \\      |          ~  .              ~-_    /\\");
  Brain.Screen.newLine();
  Brain.Screen.print("          `--__     |    _-____  /\\               ~-_ \\/.");
  Brain.Screen.newLine();
  Brain.Screen.print("               ~--_ /  ,/ -~-_ \\ \\/          _______---~/ ");
  Brain.Screen.newLine();
  Brain.Screen.print("                   ~~-/._<   \\ \\`~~~~~~~~~~~~~     ##--~/");
  Brain.Screen.newLine();
  Brain.Screen.print("                         \\    ) |`------##---~~~~-~  ) )");
  Brain.Screen.newLine();
  Brain.Screen.print("                          ~-_/_/                  ~~ ~~");

}

void name() {
  Brain.Screen.setFont(mono20);
  Brain.Screen.newLine();
  Brain.Screen.print("______                              _  ");
  Brain.Screen.newLine();
  Brain.Screen.print("| ___ \\                            | |  ");
  Brain.Screen.newLine();
  Brain.Screen.print("| |_/ /_   _ _ __ _ __   ___  _   _| |_ ");
  Brain.Screen.newLine();
  Brain.Screen.print("| ___ \\ | | | '__| '_ \\ / _ \\| | | | __|");
  Brain.Screen.newLine();
  Brain.Screen.print("| |_/ / |_| | |  | | | | (_) | |_| | |_ ");
  Brain.Screen.newLine();
  Brain.Screen.print("\\____/ \\__,_|_|  |_| |_|\\___/ \\__,_|\\__|");
  Brain.Screen.newLine();
  Brain.Screen.print("_____________________________________________");
  Brain.Screen.newLine();
  Brain.Screen.print("_____________________________________________");

}
//**********************************************************************************************

//DRIVING SETTINGS
// "when Controller1 Axis3 changed" hat block
void onevent_Controller1Axis3Changed_0() {
  Motor4.spin(forward);
  Motor7.spin(forward);
  Motor6.spin(reverse);
  Motor5.spin(reverse);
  Motor5.setVelocity(Controller1.Axis3.position(), percent);
  Motor6.setVelocity(Controller1.Axis3.position(), percent);
  Motor4.setVelocity(Controller1.Axis3.position(), percent);
  Motor7.setVelocity(Controller1.Axis3.position(), percent);
}

// "when Controller1 Axis1 changed" hat block
void onevent_Controller1Axis1Changed_0() {
  /*
  Motor4.spin(reverse);
  Motor7.spin(reverse);
  Motor6.spin(reverse);
  Motor5.spin(reverse);
  */
  Motor5.setVelocity((-0.75 * Controller1.Axis3.position()), percent);
  Motor6.setVelocity((-0.75 * Controller1.Axis1.position()), percent);
  Motor4.setVelocity(0.75 * Controller1.Axis1.position(), percent);
  Motor7.setVelocity(0.75 * Controller1.Axis3.position(), percent);
}

//**********************************************************************************************
// "when Controller1 ButtonL1 pressed" hat block
void onevent_Controller1ButtonL1_pressed_0() {
  Motor17.spin(forward);
}

// "when Controller1 ButtonL2 pressed" hat block
void onevent_Controller1ButtonL2_pressed_0() {
  Motor17.stop();
}

//**********************************************************************************************
// "when Controller1 ButtonR1 pressed" hat block
void onevent_Controller1ButtonR1_pressed_0() {
  Motor15.spin(forward);
}

// "when Controller1 ButtonR2 pressed" hat block
void onevent_Controller1ButtonR2_pressed_0() {
  Motor15.stop();
}

void onevent_Controller1ButtonA_pressed_0() {
  DigitalOutC.set(false);
  wait(2.0, seconds);
  DigitalOutC.set(true);
}


//**********************************************************************************************

void onevent_Controller1ButtonDown_pressed_0() {
  wait(2.0, seconds);
  if (Controller1.ButtonDown.pressing()) {
    DigitalOutB.set(false);
  }
}
void onevent_Controller1ButtonDown_released_0() {
  
}

  //PHENENEMUATICSSSS
// "when Controller1 ButtonUp pressed" hat block
void onevent_Controller1ButtonUp_pressed_0() {
  DigitalOutC.set(true);
  wait(0.5, seconds);
  DigitalOutC.set(false);
}
/*
void onevent_Controller1ButtonDown_pressed_0() {
  DigitalOutC.set(true);
}
*/
//**********************************************************************************************

void secForward(){
  wait(10, seconds);
}
void secSide(){
  wait(10, seconds);
}
void velocityy(){
  Motor4.setVelocity(20, percent);
  Motor7.setVelocity(20, percent);
  Motor6.setVelocity(20, percent);
  Motor5.setVelocity(20, percent);
}
void stopp() {
  Motor4.stop();
  Motor7.stop();
  Motor6.stop();
  Motor5.stop();
}
void driveUp() {
  velocityy();
  
  Motor4.spin(forward);
  Motor7.spin(forward);
  Motor6.spin(forward);
  Motor5.spin(forward);
  secForward();

  stopp();
}
void driveBack() {
  velocityy();
  
  Motor4.spin(reverse);
  Motor7.spin(reverse);
  Motor6.spin(reverse);
  Motor5.spin(reverse);
  secForward();

  stopp();
}
void driveLeft() {
  velocityy();
  
  Motor4.spin(forward);
  Motor7.spin(forward);
  Motor6.spin(reverse);
  Motor5.spin(reverse);
  secSide();

  stopp();
}
void driveRight() {
  velocityy();
  
  Motor4.spin(reverse);
  Motor7.spin(reverse);
  Motor6.spin(forward);
  Motor5.spin(forward);
  secSide();

  stopp();
}
void rol() {
  Motor17.spinFor(forward, 150.0, degrees, true);
}
void shoot() {
  //Motor15.spin();

}
int onauton_autonomous_0() {
  driveUp();
  driveLeft();
  rol();
  driveLeft();
  driveLeft();
  return 0;
}

//**********************************************************************************************

//AUTONOMOUS SETUP
void VEXcode_auton_task() {
  // Start the auton control tasks....
  vex::task auto0(onauton_autonomous_0);
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  auto0.stop();
  return;
}

//DRIVER CONTROLLED
int ondriver_drivercontrol_0() {
  Motor15.setVelocity(9999.0, percent);
  Motor17.setVelocity(9999.0, percent);
  return 0;
}

//DRIVER CONTROL SETUP
void VEXcode_driver_task() {
  // Start the driver control tasks....
  vex::task drive0(ondriver_drivercontrol_0);
  
  task rc_auto_loop_task_Controller1();
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
  return;
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vex::competition::bStopTasksBetweenModes = false;
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);
  vexcodeInit();

  //fun smile faces
  //drawSmileyAt(50, 50);
  //drawSmileyAt(400, 50);
  //drawSmileyAt(50, 200);
  //drawSmileyAt(400, 200);

  porsche();
  //name();

 // setting up speeds
  Motor15.setVelocity(9999, percent);
  Motor17.setVelocity(9999.0, percent);
  DigitalOutC.set(false);
  DigitalOutB.set(true);
  //register event handlers
  Controller1.Axis3.changed(onevent_Controller1Axis3Changed_0);
  Controller1.Axis1.changed(onevent_Controller1Axis1Changed_0);

  //Controls
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonR2_pressed_0);
  
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonL2_pressed_0);
  
  Controller1.ButtonDown.pressed(onevent_Controller1ButtonDown_pressed_0);
  Controller1.ButtonDown.released(onevent_Controller1ButtonDown_released_0);
  Controller1.ButtonUp.pressed(onevent_Controller1ButtonUp_pressed_0);

  Controller1.ButtonA.pressed(onevent_Controller1ButtonA_pressed_0);

}
