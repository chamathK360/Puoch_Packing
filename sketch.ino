#define gripper_acctuator 9
#define pouch_opening 8
#define sucktion 7
#define gripper_move 6

#define step 11
#define dir 10

#define CCW HIGH
#define ACW LOW

void setup() {
  // put your setup code here, to run once:
  pinMode(gripper_acctuator, OUTPUT);
  pinMode(pouch_opening, OUTPUT);
  pinMode(sucktion, OUTPUT);
  pinMode(gripper_move, OUTPUT);

  //stepper motor config
  pinMode(step, OUTPUT);
  pinMode(dir, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(gripper_acctuator_funtion(HIGH, 1500) == HIGH){
    pouch_opening_funtion(HIGH,800);
    gripper_move_funtion(HIGH,1000);
    gripper_acctuator_funtion(LOW, 1000);
    gripper_move_funtion(LOW,1000);
    pouch_opening_funtion(LOW,100);
  }

  stepper_move(CCW,60,5);

}

bool gripper_acctuator_funtion(bool level, int time) {
  digitalWrite(gripper_acctuator, level);
  delay(time);
  if (level == HIGH) {
    return 1;
  } else if (level == LOW) {
    return 0;
  }
}

bool gripper_move_funtion(bool level, int time) {
  digitalWrite(gripper_move, level);
  delay(time);
  if (level == HIGH) {
    return 1;
  } else if (level == LOW) {
    return 0;
  }
}

bool pouch_opening_funtion(bool level, int time) {
  digitalWrite(sucktion, level);
  delay(100);
  digitalWrite(pouch_opening, level);
  delay(time);
  if (level == HIGH) {
    return 1;
  } else if (level == LOW) {
    return 0;
  }
}

bool stepper_move(bool direction , int angle , int speed){
  digitalWrite(dir,direction);
  angle = angle * 200/360;
  for(int i = 0 ; i <= round(angle) ; i++){
    digitalWrite(step,HIGH);
    delay(speed);
    digitalWrite(step,LOW);
    delay(speed);
  }
  
}