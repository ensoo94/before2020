#include <SoftwareSerial.h>
#include <Servo.h>
Servo myServo;

SoftwareSerial BTSerial(2, 3);
const int REDled = 6;
const int YELled = 5;
const int GREENled = 4;
const int speakerPin = 9;
const int switchPin = 11;

int onOff = 1;
int switchState = 0;
int prevState = 0;
int tempo=200;

/* Knocking System */
void StopFunc(int howKnock)
{ 
    /* 노크 1번 : 보조 바퀴 On */
    if(howKnock == 1)
    {
      myServo.write(90);
    }
    /* 노크 2번 : 보조 바퀴 On */
    if(howKnock == 2 )
    {
      myServo.write(0);
    }
    /* 노크 3번 : 소리로 도움 요청, 119 전화 */
    if(howKnock == 5)
    {
      for(int i = 0; i<9; i++)
      {
        tone(speakerPin, 494, 100);
        delay(100);
        tone(speakerPin, 294, 100);
        delay(100);
      }
    }
}


void setup()
{
  Serial.begin(9600);
  myServo.attach(10);
  pinMode(REDled, OUTPUT);
  pinMode(YELled, OUTPUT);
  pinMode(GREENled, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  myServo.write(0);
  BTSerial.begin(9600);
}

void loop()
{
  int isOrder, whatOrder;

  /* On/Off 상태 읽기 */
  switchState = digitalRead(switchPin);
  delay(10);
  
  /* 버튼을 눌렀을 때 */
  if(switchState != prevState)
  {
    onOff = onOff*(-1);
  }

  /* On 상태 */
  if(onOff == -1)
  {  
    isOrder = BTSerial.read(); // 거리 정보 수신

    /* 150cm 이내에 장애물 없을 경우 초록불 */
    if(isOrder == 0){
      digitalWrite(REDled, LOW);
      digitalWrite(GREENled, HIGH);
      digitalWrite(YELled, LOW);
    }

    /* 40cm - 150cm 이내에 장애물 있을 경우 노란불과 경고음 */
    if(isOrder == 1){
      digitalWrite(REDled, LOW);
      digitalWrite(GREENled, LOW);
      digitalWrite(YELled, HIGH);
      delay(10);
      tone(speakerPin, 262, tempo);
      delay(100);
    }

    /* 40cm 이내에 장애물 있을 경우 빨간불과 Knocking System 시작 */
    if(isOrder == 2){
      digitalWrite(REDled, HIGH);
      digitalWrite(GREENled, LOW);
      digitalWrite(YELled, LOW);
      delay(10);
      
      int howKnock;
      delay(5200); // 노크 입력 시간 대기
      howKnock = BTSerial.read(); // 노크 수 수신
      StopFunc(howKnock); // Knokcing system
    }
  }

  /* Off 상태 : 모든 불 끄기, 거리 정보 수신하지 않음 */
  else{
    digitalWrite(REDled, LOW);
    digitalWrite(GREENled, LOW);
    digitalWrite(YELled, LOW);
    delay(10);
  }
}

