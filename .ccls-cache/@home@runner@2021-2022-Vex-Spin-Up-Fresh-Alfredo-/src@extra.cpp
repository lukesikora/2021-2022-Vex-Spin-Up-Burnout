float myVariable;

// "when started" hat block
int whenStarted1() {
  Motor4.spin(forward);
  Motor5.spin(forward);
  Motor6.spin(reverse);
  Motor7.spin(reverse);
  myVariable = 0.0;
  while (true) {
    if (Controller1.ButtonA.pressing()) {
      if (myVariable == 0.0) {
        myVariable = myVariable + 1.0;
      }
      else {
        myVariable = myVariable + -1.0;
      }
    }
  wait(5, msec);
  }
  return 0;
}

// "when Controller1 Axis3 changed" hat block
void onevent_Controller1Axis3Changed_0() {
  if (myVariable == 0.0) {
    Motor4.setVelocity(Controller1.Axis3.position(), percent);
    Motor5.setVelocity(Controller1.Axis3.position(), percent);
    Motor6.setVelocity(Controller1.Axis3.position(), percent);
    Motor7.setVelocity(Controller1.Axis3.position(), percent);
  }
  else {
    if (Controller1.Axis3.position() > 1.0) {
      Motor4.setVelocity(Controller1.Axis3.position(), percent);
      Motor7.setVelocity(Controller1.Axis3.position(), percent);
    }
    if (Controller1.Axis3.position() < 1.0) {
      Motor5.setVelocity(Controller1.Axis3.position(), percent);
      Motor6.setVelocity(Controller1.Axis3.position(), percent);
    }
  }
}

// "when Controller1 Axis1 changed" hat block
void onevent_Controller1Axis1Changed_0() {
  Motor4.setVelocity(Controller1.Axis1.position(), percent);
  Motor5.setVelocity(Controller1.Axis1.position(), percent);
  Motor6.setVelocity(Controller1.Axis1.position(), percent);
  Motor7.setVelocity(Controller1.Axis1.position(), percent);
}


int main() {
  // register event handlers
  Controller1.Axis3.changed(onevent_Controller1Axis3Changed_0);
  Controller1.Axis1.changed(onevent_Controller1Axis1Changed_0);

  wait(15, msec);
  // post event registration

  // set default print color to black
  printf("\033[30m");

  // wait for rotation sensor to fully initialize
  wait(30, msec);

  whenStarted1();
}