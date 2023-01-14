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
// DigitalOutC          digital_out   C               
// Motor15              motor         15              
// DigitalOutB          digital_out   B               
// Motor14              motor         14              
// Motor10              motor         10              
// Drivetrain           drivetrain    4, 5, 6, 7      
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <iostream>
#include <bits/stdc++.h>

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
/*void onevent_Controller1Axis3Changed_0() {
  Motor4.spin(forward);
  Motor5.spin(reverse);
  Motor5.setVelocity(Controller1.Axis3.position(), percent);
  Motor6.setVelocity(Controller1.Axis3.position(), percent);
  Motor4.setVelocity(Controller1.Axis3.position(), percent);
  Motor7.setVelocity(Controller1.Axis3.position(), percent);
  std::cout << "Axis 3" << std::endl;
  std::cout << Controller1.Axis3.position() << std::endl;
  std::cout << "Axis 4" << std::endl;
  std::cout << Controller1.Axis4.position() << std::endl;
}

// "when Controller1 Axis1 changed" hat block
void onevent_Controller1Axis1Changed_0() {
  Motor7.spin(forward);
  Motor6.spin(reverse);
  Motor6.setVelocity(-1.5 * (Controller1.Axis1.position() + Controller1.Axis3.position()), percent);
  Motor7.setVelocity(1.5 * (Controller1.Axis1.position() + Controller1.Axis3.position()), percent);
}*/

//**********************************************************************************************
// "when Controller1 ButtonL1 pressed" hat block
void onevent_Controller1ButtonL1_pressed_0() {
  Motor17.spin(forward);
}

// "when Controller1 ButtonL2 pressed" hat block
void onevent_Controller1ButtonL2_pressed_0() {
  Motor17.spin(reverse);
}
void onevent_Controller1ButtonL2_released_0() {
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

/*void movement() {
  while (true) {
  int hypot = sqrt(Controller1.Axis3.position()^2 + Controller1.Axis4.position()^2);
  int angle = atan2(Controller1.Axis3.position(), Controller1.Axis4.position()) * 180/M_PI;
  Motor5.setPosition(angle, degrees);
  Motor4.setPosition(angle, degrees);
  Motor6.setPosition(angle, degrees);
  Motor7.setPosition(angle, degrees);
  
  Motor4.setVelocity(hypot, percent);
  Motor5.setVelocity(hypot, percent);
  Motor6.setVelocity(hypot, percent);
  Motor7.setVelocity(hypot, percent);
  }
    }
*/
//**********************************************************************************************

void onevent_Controller1ButtonDown_pressed_0() {
  wait(2.0, seconds);
  if (Controller1.ButtonDown.pressing()) {
    DigitalOutB.set(true);
  }
}


  //PHENENEMUATICSSSS
// "when Controller1 ButtonUp pressed" hat block
void onevent_Controller1ButtonUp_pressed_0() {
  DigitalOutC.set(true);
  wait(0.75, seconds);
  DigitalOutC.set(false);
}


//**********************************************************************************************
/*
void secForward(){
  wait(1, seconds);
}
void secSide(){
  wait(0.6, seconds);
}
void velocityy(){
  Motor4.setVelocity(70, percent);
  Motor7.setVelocity(70, percent);
  Motor6.setVelocity(70, percent);
  Motor5.setVelocity(70, percent);
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
void driveUpLil() {
  velocityy();
  
  Motor4.spin(forward);
  Motor7.spin(forward);
  Motor6.spin(forward);
  Motor5.spin(forward);
  wait(0.2, seconds);
  
  stopp();
}
void driveBackLil() {
  velocityy();
  
  Motor4.spin(reverse);
  Motor7.spin(reverse);
  Motor6.spin(reverse);
  Motor5.spin(reverse);
  wait(0.5, seconds);

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
void driveLeftLil() {
  velocityy();
  
  Motor4.spin(forward);
  Motor7.spin(forward);
  Motor6.spin(reverse);
  Motor5.spin(reverse);
  wait(0.1, seconds);

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
void driveRightLil() {
  velocityy();
  
  Motor4.spin(reverse);
  Motor7.spin(reverse);
  Motor6.spin(forward);
  Motor5.spin(forward);
  wait(0.25, seconds);

  stopp();
}
void rol() {
Motor17.setVelocity(80, percent);
Motor17.spinFor(forward, -300.0, degrees, true);
}
void shoot() {
  Motor15.spin(forward);
}
void stopShoot() {
  Motor15.stop();
}
void neu() {  
  DigitalOutC.set(true);
  wait(0.75, seconds);
  DigitalOutC.set(false);
} 

int onauton_autonomous_0() { //on
  DigitalOutC.set(false);
  DigitalOutB.set(false);
  Motor17.spin(forward);
  driveUpLil();
  wait(1, seconds);
  Motor17.stop();
  wait(1, seconds);
  driveBack();
  wait(1, seconds);
  driveLeft();
  wait(0.5, seconds);
  driveBack();
  wait(1, seconds);
  shoot();
  for (int i = 0; i < 4; i++) {
    wait(4, seconds);
    neu();
  }
  stopShoot();
  return 0;
}
*/
/*
int onauton_autonomous_0() { //outside
  DigitalOutC.set(false);
  DigitalOutB.set(false);
  driveBack();
  driveLeft();


  driveUpLil();
  wait(1, seconds);
  rol();
  wait(2, seconds);
  driveLeft();
  wait(1, seconds);
  shoot();
  for (int i = 0; i < 4; i++) {
    wait(4, seconds);
    neu();
  }
  stopShoot();
  return 0;
}
*/
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
  DigitalOutB.set(false);
  //register event handlers
  //Controller1.Axis3.changed(onevent_Controller1Axis3Changed_0);
  //Controller1.Axis4.changed(onevent_Controller1Axis1Changed_0);

  //Controls
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonR2_pressed_0);
  
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonL2_pressed_0);
  Controller1.ButtonR2.released(onevent_Controller1ButtonL2_released_0);
   
  Controller1.ButtonUp.pressed(onevent_Controller1ButtonUp_pressed_0);
  Controller1.ButtonDown.pressed(onevent_Controller1ButtonDown_pressed_0);
  movement();
}


/*
CHECKLIST
1. Check controller battery and battery percentage

2. Make sure every port is working

3. Have good amount of air pumped

4. Have auton set correct side

5. Make sure string shooter is working

*/