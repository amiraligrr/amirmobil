
//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//   // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//   delay(15);                       // waits 15ms for the servo to reach the position
// }
//for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//  myservo.write(pos);              // tell servo to go to position in variable 'pos'
//  delay(15);                       // waits 15ms for the servo to reach the position
//  }





#include <Servo.h>
Servo myservo;
Servo myservo2;
int led;
int pos = 0;
int a = 51;
int b = 102;
int c = 153;
int d = 204;
int e = 255;
int in1 = 3;
int in2 = 4;
int en1 = 5;
int in3 = 6;
int in4 = 7;
int en2 = 8;
int y = A0;
int x = A1;


void setup() {
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  Serial.begin(9600);
  myservo.attach(10);
  myservo2.attach(9);
  pinMode(13, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(A3, OUTPUT);
  led = 0;
  digitalWrite(12, 0);
  digitalWrite(11, 0);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(A4, 1);
}

void loop() {
  //srr();
  r();
  l();
  mobadel();
  led_control();
}














































































































void led_control() {
  if (digitalRead(A4) == 0 and led == 0) {
    digitalWrite(12, 1);
    delay(500);
    digitalWrite(12, 0);
    digitalWrite(11, 1);
    delay(500);
    digitalWrite(11, 0);
    delay(500);
    digitalWrite(11, 1);
    digitalWrite(12, 1);
    led = 1;
    delay(50);
  } else {
    if (digitalRead(A4) == 0 and led == 1) {
      digitalWrite(12, 0);
      digitalWrite(11, 0);
      led = 0;
      delay(1000);
    }
  }
}



































void mobadel() {
  if (digitalRead(A5) == 1) {
    for (pos = 180; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
      myservo.write(pos);
      myservo2.write(pos);  // tell servo to go to position in variable 'pos'
      delay(15);
      digitalWrite(13, 1);
    }
  }

  else {


    if (digitalRead(A5) == 0) {
      digitalWrite(13, 0);
      for (pos = 0; pos <= 0; pos += 1) {  // goes from 0 degrees to 180 degrees
        myservo.write(pos);
        myservo2.write(pos);  // tell servo to go to position in variable 'pos'
        delay(15);
      }
    }
  }
}


























































void la() {
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
void lg() {
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void rg() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
}
void srr() {
  Serial.println(analogRead(A1));
  Serial.println(analogRead(A0));
  Serial.println("________________________");
  delay(500);
}
void ra() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
}















































void r() {
  if (analogRead(y) > 900) {
    Serial.println("r - g L(e)");
    rg();
    analogWrite(en1, e);
  } else {
    if (analogRead(y) < 900 && analogRead(y) > 800) {
      Serial.println("r - g L(d)");
      rg();
      analogWrite(en1, d);
    } else {
      if (analogRead(y) < 800 && analogRead(y) > 700) {
        Serial.println("r - g L(c)");
        rg();
        analogWrite(en1, c);
      } else {
        if (analogRead(y) < 700 && analogRead(y) > 550) {
          Serial.println("r - g L(b)");
          rg();
          analogWrite(en1, b);
        } else {
          if (analogRead(y) < 550 && analogRead(y) > 540) {
            Serial.println("r - g L(a)");
            rg();
            analogWrite(en1, a);
          } else {
            if (analogRead(y) < 540 && analogRead(y) > 485 && analogRead(x) < 540 && analogRead(x) > 485) {
              Serial.println("r _ g&a (stop)");
              analogWrite(en1, 0);
              digitalWrite(in1, 0);
              digitalWrite(in2, 0);
            } else {

              ////////////////////////////////////////////////////////////////////// r _ a
              if (analogRead(y) < 97) {
                Serial.println("r - a L(e)");
                ra();
                analogWrite(en1, e);
              } else {
                if (analogRead(y) < 194 && analogRead(y) > 97) {
                  Serial.println("r - a L(d)");
                  ra();
                  analogWrite(en1, d);
                } else {
                  if (analogRead(y) < 291 && analogRead(y) > 194) {
                    Serial.println("r - a L(c)");
                    ra();
                    analogWrite(en1, c);
                  } else {
                    if (analogRead(y) < 388 && analogRead(y) > 291) {
                      Serial.println("r - a L(b)");
                      ra();
                      analogWrite(en1, b);
                    } else {
                      if (analogRead(y) < 485 && analogRead(y) > 388) {
                        Serial.println("r - a L(a)");
                        ra();
                        analogWrite(en1, a);
                      } else {
                        if (analogRead(y) < 540 && analogRead(y) > 485 && analogRead(x) < 540 && analogRead(x) > 485) {
                          Serial.println("r _ a (stop)");
                          analogWrite(en1, 0);
                          digitalWrite(in1, 0);
                          digitalWrite(in2, 0);
                        } else {
                          /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                          if (analogRead(x) > 900) {
                            Serial.println("r - g L(e)");
                            rg();
                            analogWrite(en1, e);
                          } else {
                            if (analogRead(x) < 900 && analogRead(x) > 800) {
                              Serial.println("r - g L(d)");
                              rg();
                              analogWrite(en1, d);
                            } else {
                              if (analogRead(x) < 800 && analogRead(x) > 700) {
                                Serial.println("r - g L(c)");
                                rg();
                                analogWrite(en1, c);
                              } else {
                                if (analogRead(x) < 700 && analogRead(x) > 550) {
                                  Serial.println("r - g L(b)");
                                  rg();
                                  analogWrite(en1, b);
                                } else {
                                  if (analogRead(x) < 550 && analogRead(x) > 540) {
                                    Serial.println("r - g L(a)");
                                    rg();
                                    analogWrite(en1, a);
                                  } else {
                                    if (analogRead(x) < 540 && analogRead(x) > 485 && analogRead(y) < 540 && analogRead(y) > 485) {
                                      Serial.println("r _ g&a (stop)");
                                      analogWrite(en1, 0);
                                      digitalWrite(in1, 0);
                                      digitalWrite(in2, 0);
                                    } else {

                                      ////////////////////////////////////////////////////////////////////// r _ a
                                      if (analogRead(x) < 97) {
                                        Serial.println("r - a L(e)");
                                        ra();
                                        analogWrite(en1, e);
                                      } else {
                                        if (analogRead(x) < 194 && analogRead(x) > 97) {
                                          Serial.println("r - a L(d)");
                                          ra();
                                          analogWrite(en1, d);
                                        } else {
                                          if (analogRead(x) < 291 && analogRead(x) > 194) {
                                            Serial.println("r - a L(c)");
                                            ra();
                                            analogWrite(en1, c);
                                          } else {
                                            if (analogRead(x) < 388 && analogRead(x) > 291) {
                                              Serial.println("r - a L(b)");
                                              ra();
                                              analogWrite(en1, b);
                                            } else {
                                              if (analogRead(x) < 485 && analogRead(x) > 388) {
                                                Serial.println("r - a L(a)");
                                                ra();
                                                analogWrite(en1, a);
                                              } else {

                                                /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void l() {
  if (analogRead(y) > 900) {
    Serial.println("l - g L(e)");
    la();
    analogWrite(en2, e);
  } else {
    if (analogRead(y) < 900 && analogRead(y) > 800) {
      Serial.println("l - g L(d)");
      la();
      analogWrite(en2, d);
    } else {
      if (analogRead(y) < 800 && analogRead(y) > 700) {
        Serial.println("l - g L(c)");
        la();
        analogWrite(en2, c);
      } else {
        if (analogRead(y) < 700 && analogRead(y) > 550) {
          Serial.println("l - g L(b)");
          la();
          analogWrite(en2, b);
        } else {
          if (analogRead(y) < 550 && analogRead(y) > 540) {
            Serial.println("r - g L(a)");
            la();
            analogWrite(en2, a);
          } else {
            if (analogRead(y) < 540 && analogRead(y) > 485 && analogRead(x) < 540 && analogRead(x) > 485) {
              Serial.println("l _ g&a (stop)");
              analogWrite(en2, 0);
              digitalWrite(in1, 0);
              digitalWrite(in2, 0);
            } else {

              ////////////////////////////////////////////////////////////////////// r _ a
              if (analogRead(y) < 97) {
                Serial.println("l - a L(e)");
                lg();
                analogWrite(en2, e);
              } else {
                if (analogRead(y) < 194 && analogRead(y) > 97) {
                  Serial.println("l - a L(d)");
                  lg();
                  analogWrite(en2, d);
                } else {
                  if (analogRead(y) < 291 && analogRead(y) > 194) {
                    Serial.println("l - a L(c)");
                    lg();
                    analogWrite(en2, c);
                  } else {
                    if (analogRead(y) < 388 && analogRead(y) > 291) {
                      Serial.println("l - a L(b)");
                      lg();
                      analogWrite(en2, b);
                    } else {
                      if (analogRead(y) < 485 && analogRead(y) > 388) {
                        Serial.println("l - a L(a)");
                        lg();
                        analogWrite(en2, a);
                      } else {
                        if (analogRead(y) < 540 && analogRead(y) > 485 && analogRead(x) < 540 && analogRead(x) > 485) {
                          Serial.println("l _ a (stop)");
                          analogWrite(en2, 0);
                          digitalWrite(in1, 0);
                          digitalWrite(in2, 0);
                        } else {
                          /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                          if (analogRead(x) > 900) {
                            Serial.println("l - g L(e)");
                            lg();
                            analogWrite(en2, e);
                          } else {
                            if (analogRead(x) < 900 && analogRead(x) > 800) {
                              Serial.println("l - g L(d)");
                              lg();
                              analogWrite(en2, d);
                            } else {
                              if (analogRead(x) < 800 && analogRead(x) > 700) {
                                Serial.println("l - g L(c)");
                                lg();
                                analogWrite(en2, c);
                              } else {
                                if (analogRead(x) < 700 && analogRead(x) > 550) {
                                  Serial.println("l - g L(b)");
                                  lg();
                                  analogWrite(en1, b);
                                } else {
                                  if (analogRead(x) < 550 && analogRead(x) > 540) {
                                    Serial.println("l - g L(a)");
                                    lg();
                                    analogWrite(en2, a);
                                  } else {
                                    if (analogRead(x) < 540 && analogRead(x) > 485 && analogRead(y) < 540 && analogRead(y) > 485) {
                                      Serial.println("l _ g&a (stop)");
                                      analogWrite(en2, 0);
                                      digitalWrite(in3, 0);
                                      digitalWrite(in4, 0);
                                    } else {

                                      ////////////////////////////////////////////////////////////////////// r _ a
                                      if (analogRead(x) < 97) {
                                        Serial.println("l - a L(e)");
                                        la();
                                        analogWrite(en2, e);
                                      } else {
                                        if (analogRead(x) < 194 && analogRead(x) > 97) {
                                          Serial.println("l - a L(d)");
                                          la();
                                          analogWrite(en2, d);
                                        } else {
                                          if (analogRead(x) < 291 && analogRead(x) > 194) {
                                            Serial.println("l - a L(c)");
                                            la();
                                            analogWrite(en2, c);
                                          } else {
                                            if (analogRead(x) < 388 && analogRead(x) > 291) {
                                              Serial.println("l - a L(b)");
                                              la();
                                              analogWrite(en2, b);
                                            } else {
                                              if (analogRead(x) < 485 && analogRead(x) > 388) {
                                                Serial.println("l - a L(a)");
                                                la();
                                                analogWrite(en2, a);
                                              } else {

                                                /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
