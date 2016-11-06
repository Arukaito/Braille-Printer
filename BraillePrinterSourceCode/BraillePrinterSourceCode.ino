#include <Servo.h>
#include <AFMotor.h>

AF_DCMotor m1(1);
AF_DCMotor m2(3);
AF_DCMotor poke(2);
int l = 0;
String in = "Sentence to be converted to braille";
int x = 0; int y = 0;
int lpl = 8; int lpb = 6;
Servo s;
int count = -1;
int arr[][2] = {{0, 0}, {0, 0}, {0, 0}};
int rotDel = 1650;
void setup() {
  s.attach(9);
  s.write(14);
  delay(500);
}

void loop() {
  int t = 0;

  for (int h = 0; h < 6; h++) {
    if (h % 2 == 0) {
      for (; l < in.length(); l += 6) {
        pos1(0, t);
        delay(200);
        brConvert(toLowerCase(in.charAt(l)));
        pos2_even(arr);
        delay(200);
        t++;
      }
      y = 0;
      antiClockRot(rotDel);
      delay(100);
      forward(255, 700);
      antiClockRot(rotDel);
      delay(100);
      if (in.length() % 6 == (h + 1)) {
        forward(255, 800);
        l -= 5;
      }
      else if (in.length() % 6 > (h + 1)) {
        l -= 6;
        l++;
      }
    }
    else {
      for (; l > 0; l -= 6) {
        pos1(0, t);
        delay(200);
        brConvert(toLowerCase(in.charAt(l)));
        pos2_odd(arr);
        delay(200);
        t++;
      }
      y = 0;
      clockRot(rotDel);
      delay(100);
      forward(255, 700);
      clockRot(rotDel);
      delay(100);
      if (in.length() % 6 == (h + 1)) {
        forward(255, 800);
        l -= 5;
      }
      else if (in.length() % 6 > (h + 1)) {
        l++;
      }
    }
  }




  delay(100000000);

}
void pos1(int a, int b) {
  y = b - y;
  forward(255, y * 400);
  delay(2000);

}


void pos2_even(int a[][2]) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      if (a[i][j] == 1) {
        if (j == 1) {
          writeBraille();
          continue;
        }
        else {
          s.write(18);
          delay(100);
          writeBraille();
          s.write(14);
          delay(100);
        }

      }

    }
    forward(255, 100);

  }




}

void pos2_odd(int a[][2]) {

  for (int i = 2; i >= 0; i--) {
    for (int j = 0; j < 2; j++) {
      if (a[i][j] == 1) {
        if (j == 1) {
          writeBraille();
          continue;
        }
        else {
          s.write(18);
          delay(100);
          writeBraille();
          s.write(14);
          delay(100);
        }

      }

    }
    forward(255, 100);

  }
}




void clockRot(int d) {
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m1.setSpeed(255);
  m2.setSpeed(255);
  delay(d);
  m1.setSpeed(0);
  m2.setSpeed(0);
}
void forward(int s, int d) {
  m1.run(FORWARD);
  m2.run(FORWARD);
  m1.setSpeed(s);
  m2.setSpeed(s);
  delay(d);
  m1.setSpeed(0);
  m2.setSpeed(0);
}

void antiClockRot(int d) {
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m1.setSpeed(255);
  m2.setSpeed(255);
  delay(d);
  m1.setSpeed(0);
  m2.setSpeed(0);
}

void writeBraille() {
  poke.run(FORWARD);
  poke.setSpeed(255);
  delay(500);
  m2.setSpeed(0);
  delay(100);
  poke.run(BACKWARD);
  poke.setSpeed(255);
  delay(500);
  poke.setSpeed(0);
  delay(100);
}

void brConvert(char a) {

  switch (a) {
    case 'a':
      {
        int k[][2] = {{1, 0}, {0, 0}, {0, 0}};
        copy(k);
      }
      break;

    case 'b':
      {
        int k[][2] = {{1, 0}, {1, 0}, {0, 0}};
        copy(k);
      }
      break;

    case 'c':
      {
        int k[][2] = {{1, 1}, {0, 0}, {0, 0}};
        copy(k);
      }
      break;

    case 'd':
      {
        int k[][2] = {{1, 1}, {0, 1}, {0, 0}};
        copy(k);
      }
      break;

    case 'e':
      {
        int k[][2] = {{1, 0}, {0, 1}, {0, 0}};
        copy(k);
      }
      break;

    case 'f':
      {
        int k[][2] = {{1, 1}, {1, 0}, {0, 0}};
        copy(k);
      }
      break;

    case 'g':
      {
        int k[][2] = {{1, 1}, {1, 1}, {0, 0}};
        copy(k);
      }
      break;

    case 'h':
      {
        int k[][2] = {{1, 0}, {1, 1}, {0, 0}};
        copy(k);
      }
      break;

    case 'i':
      {
        int k[][2] = {{0, 1}, {1, 0}, {0, 0}};
        copy(k);
      }
      break;

    case 'j':
      {
        int k[][2] = {{0, 1}, {1, 1}, {0, 0}};
        copy(k);
      }
      break;

    case 'k':
      {
        int k[][2] = {{0, 1}, {0, 0}, {1, 0}};
        copy(k);
      }
      break;

    case 'l':
      {
        int k[][2] = {{1, 0}, {1, 0}, {1, 0}};
        copy(k);
      }
      break;

    case 'm':
      {
        int k[][2] = {{1, 1}, {0, 0}, {1, 0}};
        copy(k);
      }
      break;

    case 'n':
      {
        int k[][2] = {{1, 1}, {0, 1}, {1, 0}};
        copy(k);
      }
      break;

    case 'o':
      {
        int k[][2] = {{1, 0}, {0, 1}, {1, 0}};
        copy(k);
      }
      break;

    case 'p':
      {
        int k[][2] = {{1, 1}, {1, 0}, {1, 0}};
        copy(k);
      }
      break;

    case 'q':
      {
        int k[][2] = {{1, 1}, {1, 1}, {1, 0}};
        copy(k);
      }
      break;

    case 'r':
      {
        int k[][2] = {{1, 0}, {1, 1}, {1, 0}};
        copy(k);
      }
      break;

    case 's':
      {
        int k[][2] = {{0, 1}, {1, 0}, {1, 0}};
        copy(k);
      }
      break;

    case 't':
      {
        int k[][2] = {{0, 1}, {1, 1}, {1, 0}};
        copy(k);
      }
      break;

    case 'u':
      {
        int k[][2] = {{1, 0}, {0, 0}, {1, 1}};
        copy(k);
      }
      break;

    case 'v':
      {
        int k[][2] = {{1, 0}, {0, 0}, {0, 0}};
        copy(k);
      }
      break;

    case 'w':
      {
        int k[][2] = {{1, 0}, {0, 0}, {0, 0}};
        copy(k);
      }
      break;

    case 'x':
      {
        int k[][2] = {{1, 0}, {0, 0}, {0, 0}};
        copy(k);
      }
      break;

    case 'y':
      {
        int k[][2] = {{1, 0}, {0, 0}, {0, 0}};
        copy(k);
      }
      break;

    case 'z':
      {
        int k[][2] = {{1, 0}, {0, 0}, {0, 0}};
        copy(k);
      }
      break;
  }

}

void copy(int jj[][2]) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      arr[i][j] = jj[i][j];
}

