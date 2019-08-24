#define in1 2
#define in2 3
#define in3 4
#define in4 5

char input;

void forward(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void reverse(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
}

void turnRight(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
}

void immobilize(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    input=Serial.read();
    if(input=='w' || input=='W'){
      forward();
    }
    else if(input=='s' || input=='S'){
      reverse();
    }
    else if(input=='a' || input=='A'){
      turnLeft();
      delay(200);
      immobilize();
    }
    else if(input=='d' || input=='D'){
      turnRight();
      delay(200);
      immobilize();
    }
  /*  else if(input=='Q'){
      turnLeft();
      delay(200);
      forward();
    }
        else if(input=='E'){
      turnRight();
      delay(200);
      forward();
    }
   */ else if(input=='X'){
      immobilize();
    }
  }
 
}
