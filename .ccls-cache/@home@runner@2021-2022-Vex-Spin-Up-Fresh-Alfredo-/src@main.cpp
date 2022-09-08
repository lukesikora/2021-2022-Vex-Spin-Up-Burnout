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
// Drivetrain           drivetrain    4, 5, 6, 7      
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
competition Competition;
float myVariable;

void drawSmileyAt(int x, int y){
  Brain.Screen.drawCircle(x, y, 40, yellow);
  Brain.Screen.drawCircle(x-20, y-10, 10, blue);
  Brain.Screen.drawCircle(x+20, y-10, 10, blue);
  Brain.Screen.drawRectangle(x-20, y+10, 40, 10, red);
}

//**********************************************************************************************
/*#
***example motor control
void onevent_Controller1ButtonX_pressed_0() {
  Motor15.setVelocity(100.0, percent);
  Motor15.spin(forward);
  wait(1.0, seconds);
  Motor15.stop();
  Motor15.setVelocity(70.0, percent);
}
*/
//**********************************************************************************************

int onauton_autonomous_0() {
  //fdjihxjguiesdjhugoesd competetion stuff autonoumous
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
  Drivetrain.setTurnVelocity(50.0, percent); // TURN SPEED
  //Motor15.setVelocity(100.0, percent);
  //Motor18.setVelocity(50.0, percent);
  Drivetrain.setDriveVelocity(75.0, percent);
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
  
  //fun stuff
  Controller1.Screen.print("Pizzahut"); 
  drawSmileyAt(50, 50);
  drawSmileyAt(400, 50);
  drawSmileyAt(50, 200);
  drawSmileyAt(400, 200);


  //setup
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);
  vexcodeInit();

  //register event handlers


}
