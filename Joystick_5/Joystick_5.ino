int click1 = 5;
int y1 = A0;
int x1 = A1;
int click2 = 2;
int x2 = A3;
int y2 = A4;
int up = 1000;
int down = 10;
int key;
int key2;
  int aux = 0;
  int aux2 = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(click2, INPUT);
  pinMode(x1, INPUT);
  pinMode(y1, INPUT);
  pinMode(click2, INPUT);
  pinMode(x2, INPUT);
  pinMode(y2, INPUT);
  
  Serial.begin(9600);

}

void loop() {

  int xval1 = analogRead(x1);
  int yval1 = analogRead(y1);
  int xval2 = analogRead(x2);
  int yval2 = analogRead(y2);
  int clickval = digitalRead(click2);
  //Serial.println(clickval);
  
  //delay(100);
  if(xval1<up && xval1>down && yval1<up && yval1>down) key = 0;
  if(xval2<up && xval2>down && yval2<up && yval2>down) key2 = 10;

  if(xval1>up) {
    
    if(yval1>up) key = 5;
    else if(yval1<down) key = 6;
    else key = 1;
    
    }

  if(xval1<down){
    
    if(yval1>up) key = 8;
    else if(yval1<down) key = 7;
    else key = 2;
    
    }
   if(yval1>up) {
    
    if(xval1>up) key = 1;
    else if(xval1<down) key = 8;
    else key = 3;
    
    }

  if(yval1<down){
    
    if(xval1>up) key = 6;
    else if(xval1<down) key = 7;
    else key = 4;
    
    }

    //JOYSTICK #2
    if(xval2>up) {
    
    if(yval2>up) key2 = 15;
    else if(yval2<down) key2 = 16;
    else key2 = 11;
    
    }

  if(xval2<down){
    
    if(yval2>up) key2 = 18;
    else if(yval2<down) key2 = 17;
    else key2 = 12;
    
    }
   if(yval2>up) {
    
    if(xval2>up) key2 = 11;
    else if(xval2<down) key2 = 18;
    else key2 = 13;
    
    }

  if(yval2<down){
    
    if(xval2>up) key2 = 16;
    else if(xval2<down) key2 = 17;
    else key2 = 14;
    
    }

  if(aux != key) {
    
    Serial.write(key);
    
    
    }
    
  if(aux2 != key2) {
    
    Serial.write(key2);
    
    }
    
    aux=key;
    aux2=key2;
   //sPrint(key, key2);

}

void sPrint(int k, int k2){
    Serial.print(k);
    Serial.print(" ");
    Serial.println(k2);
  }
/*

void goUpRight(int x, int y){
  Serial.write(5);
  int i=0;
  while(i==0){
    x = analogRead(x1);
    y = analogRead(y1);
    if(x<up || y<up){Serial.write(0); break;}
    }
    return;
  }
 void goDownRight(int x, int y){
  Serial.write(6);
  int i=0;
  while(i==0){
    x = analogRead(x1);
    y = analogRead(y1);
    if(x<up || y>down){Serial.write(0); break;}
    }
    return;
  }
  void goDownLeft(int x, int y){
  Serial.write(7);
  int i=0;
  while(i==0){
    x = analogRead(x1);
    y = analogRead(y1);
    if(x>down || y>down) {Serial.write(0); break;}
    }
    return;
  }
  void goUpLeft(int x, int y){
  Serial.write(8);
  int i=0;
  while(i==0){
    x = analogRead(x1);
    y = analogRead(y1);
    if(x > down || y < up) {Serial.write(0); break;}
    }
    return;
  }
  void goRight(int x){
  Serial.write(1);
  int i=0;
  while(i==0){
    x = analogRead(x1);
    int y = analogRead(y1);
    if(x<up) {Serial.write(0); break;}
    if(y>up){Serial.write(0); break;}
    if(y<down){Serial.write(0); break;}
    }
    return;
  }
  void goLeft(int x){
  Serial.write(2);
  int i=0;
  while(i==0){
    int x = analogRead(x1);
    int y = analogRead(y1);
    if(x>down) {Serial.write(0); break;}
    if(y>up) {Serial.write(0); break;}
    if(y<down) {Serial.write(0); break;}
    }
    return;
  }
  void goUp(int y){
  Serial.write(3);
  int i=0;
  while(i==0){
    y = analogRead(y1);
    int x = analogRead(x1);
    if(y<up) {Serial.write(0); break;}
    if(x>up){Serial.write(0); Serial.write(5); break;}
    }
    return;
  }
  void goDown(int y){
  Serial.write(4);
  int i=0;
  while(i==0){
    int y = analogRead(y1);
    if(y>down) {Serial.write(0); break;}
    }
    return;
  }

//JOYSTCIK #2 FUNCTIONS

void goUpRight2(int x, int y){
  Serial.write(15);
  int i=0;
  while(i==0){
    x = analogRead(x2);
    y = analogRead(y2);
    if(x<up || y<up){Serial.write(10); break;}
    }
    return;
  }
 void goDownRight2(int x, int y){
  Serial.write(16);
  int i=0;
  while(i==0){
    x = analogRead(x2);
    y = analogRead(y2);
    if(x<up || y>down){Serial.write(10); break;}
    }
    return;
  }
  void goDownLeft2(int x, int y){
  Serial.write(17);
  int i=0;
  while(i==0){
    x = analogRead(x2);
    y = analogRead(y2);
    if(x>down || y>down) {Serial.write(10); break;}
    }
    return;
  }
  void goUpLeft2(int x, int y){
  Serial.write(18);
  int i=0;
  while(i==0){
    x = analogRead(x2);
    y = analogRead(y2);
    if(x > down || y < up) {Serial.write(10); break;}
    }
    return;
  }
  void goRight2(int x){
  Serial.write(11);
  int i=0;
  while(i==0){
    x = analogRead(x2);
    int y = analogRead(y2);
    if(x<up) {Serial.write(10); break;}
    if(y>up){Serial.write(10); break;}
    if(y<down){Serial.write(10); break;}
    }
    return;
  }
  void goLeft2(int x){
  Serial.write(12);
  int i=0;
  while(i==0){
    int x = analogRead(x2);
    int y = analogRead(y2);
    if(x>down) {Serial.write(10); break;}
    if(y>up) {Serial.write(10); break;}
    if(y<down) {Serial.write(10); break;}
    }
    return;
  }
  void goUp2(int y){
  Serial.write(13);
  int i=0;
  while(i==0){
    y = analogRead(y2);
    int x = analogRead(x2);
    if(y<up) {Serial.write(10); break;}
    if(x>up){Serial.write(10); Serial.write(5); break;}
    }
    return;
  }
  void goDown2(int y){
  Serial.write(14);
  int i=0;
  while(i==0){
    int y = analogRead(y2);
    if(y>down) {Serial.write(10); break;}
    }
    return;
  }
*/
