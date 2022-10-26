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
// Motor18              motor         18              
// Motor17              motor         17              
// Motor4               motor         4               
// Motor5               motor         5               
// Motor6               motor         6               
// Motor7               motor         7               
// EncoderA             encoder       A, B            
// Motor19              motor         19              
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
  Motor4.spin(reverse);
  Motor7.spin(reverse);
  Motor6.spin(reverse);
  Motor5.spin(reverse);
  Motor5.setVelocity((-0.5 * Controller1.Axis1.position()), percent);
  Motor6.setVelocity((-0.5 * Controller1.Axis1.position()), percent);
  Motor4.setVelocity(0.5 * Controller1.Axis1.position(), percent);
  Motor7.setVelocity(0.5 * Controller1.Axis1.position(), percent);
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
  Motor18.spin(reverse);
}

// "when Controller1 ButtonR2 pressed" hat block
void onevent_Controller1ButtonR2_pressed_0() {
  Motor18.stop();
}

//**********************************************************************************************

// "when Controller1 ButtonA pressed" hat block
void onevent_Controller1ButtonA_pressed_0() {
  Motor19.setVelocity(20, percent);
  Motor19.spinFor(reverse, 240.0, degrees, true);
  Motor19.spinFor(forward, 240.0, degrees, true);
  Motor19.stop();
}


//**********************************************************************************************

int onauton_autonomous_0() {
  // anfuiahfiuaehg autonomous
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
  Motor18.setVelocity(9999.0, percent);
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
//**********************************************************************************************

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vex::competition::bStopTasksBetweenModes = false;
  
  //fun smile faces
  //drawSmileyAt(50, 50);
  //drawSmileyAt(400, 50);
  //drawSmileyAt(50, 200);
  //drawSmileyAt(400, 200);

  //print car
  //porsche();
  name();

  //setup
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);
  vexcodeInit();
  
 
 // setting up speeds
  Motor18.setVelocity(9999, percent);
  Motor17.setVelocity(9999.0, percent);
  Motor19.setVelocity(20.0, percent);

  //register event handlers
  Controller1.Axis3.changed(onevent_Controller1Axis3Changed_0);
  Controller1.Axis1.changed(onevent_Controller1Axis1Changed_0);

  //Controls
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);
  
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonL2_pressed_0);
  
  Controller1.ButtonA.pressed(onevent_Controller1ButtonA_pressed_0);

  //print to screen the velocity
  Motor19.spinFor(forward, 240.0, degrees, true);
  EncoderA.setRotation(0.0, degrees);
  while (true) {
  Controller1.Screen.print(static_cast<float>(EncoderA.velocity(rpm)));
  wait(0.25, seconds);
  Controller1.Screen.clearLine(1);
  Controller1.Screen.setCursor(Controller1.Screen.row(), 1);
  wait(5, msec);
  }
}
