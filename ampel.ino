#include <timer.h>
#include <timerManager.h>

Timer timer;

int rot = LOW;
int gelb = LOW;
int gruen = LOW;
int count = 0;

void setup() {

  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  timer.setInterval(1000);
  timer.setCallback(ampel);
  timer.start();
}

void ampel() {

  digitalWrite(10, rot);
  digitalWrite(9, gelb);
  digitalWrite(8, gruen);

  count++;

  if (count == 2) {

    setPhase1();
  }

  if (count == 5) {

    setPhase2();
  }

  if (count == 7) {

    setPhase3();
  }

  if (count == 8) {

    setPhase4();
    count = 0;
  }
}

void setPhase1() {

  rot = HIGH;
  gelb = LOW;
  gruen = LOW;
}

void setPhase2() {

  rot = HIGH;
  gelb = HIGH;
  gruen = LOW;
}

void setPhase3() {

  rot = LOW;
  gelb = LOW;
  gruen = HIGH;
}

void setPhase4() {

  rot = LOW;
  gelb = HIGH;
  gruen = LOW;
}

void loop() {

  timer.update();
}