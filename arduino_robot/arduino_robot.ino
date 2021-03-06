// C++ code
//

int trigSag = A2;
int echoSag = A3;

int trigIleri = A1;
int echoIleri = A0;

long sureSag;
long sureIleri;
long uzaklikSag;
long uzaklikIleri;

// Motor A bağlantıları
int soli = 3;
int solg = 11;
// Motor B bağlantıları
int sagg = 9;
int sagi = 10;


void setup()
{
  // Tüm motor kontrol pinlerini çıkışlara ayarlayın
  pinMode(soli, OUTPUT);
  pinMode(solg, OUTPUT);
  pinMode(sagg, OUTPUT);
  pinMode(sagi, OUTPUT);
  
  pinMode(trigSag, OUTPUT);
  pinMode(echoSag, INPUT);
  
  pinMode(trigIleri, OUTPUT);
  pinMode(echoIleri, INPUT);
  
  Serial.begin(9600);
  
  // Motorları kapatın - Başlangıç durumu
  analogWrite(soli, 0);
  analogWrite(solg, 0);
  analogWrite(sagg, 0);
  analogWrite(sagi, 0);
}

void loop()
{
  if(distanceMeterSag()<=7){
    Serial.println("Calisti");
    forward(101.50,0,0,102);
    stopmove();
  }
  if(distanceMeterSag()>=15){
    turnright(101.50,0,102,0);
    stopmove();
    delay(50);
    }  
}

long distanceMeterSag()
{
    digitalWrite(trigSag, LOW);
    delayMicroseconds(5);
    digitalWrite(trigSag, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigSag, LOW);

    sureSag = pulseIn(echoSag, HIGH);
    uzaklikSag = sureSag / 29.1 / 2;
    delay(15);
    Serial.print("Sag :"); 
    Serial.println(uzaklikSag);
    return uzaklikSag;
}

long distanceMeterIleri()
{
    digitalWrite(trigIleri, LOW);
    delayMicroseconds(5);
    digitalWrite(trigIleri, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigIleri, LOW);

    sureIleri = pulseIn(echoIleri, HIGH);
    uzaklikIleri = sureIleri / 29.1 / 2;
    delay(15);
    Serial.print("Ileri :"); 
    Serial.println(uzaklikIleri);
    return uzaklikIleri;
}


// Bu Fonksiyon İleri harekettir
void forward(int s1, int s2, int s3, int s4){
    analogWrite(soli, s1);
    analogWrite(solg, s2);
    analogWrite(sagg, s3);
    analogWrite(sagi, s4);  
    delay(100);
    stopmove();    
}
void stopmove(){
    analogWrite(soli, 0);
    analogWrite(solg, 0);
    analogWrite(sagg, 0);
    analogWrite(sagi, 0); 
    
}
void turnright(int s1, int s2, int s3, int s4){
    analogWrite(soli, s1);
    analogWrite(solg, s2);
    analogWrite(sagg, s3);
    analogWrite(sagi, s4); 
    delay(270);
    forward(101.50,0,0,102);
    delay(300);
}
