#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
SoftwareSerial btSerial(2,3); //tx=2, rx=3
LiquidCrystal_I2C lcd(0x3F, 16, 2);

const int trig=12;
const int echo=13;
const int piezo = A0;

int howKnock = 0;

void setup()
{
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);
  lcd.begin();
  lcd.backlight();
  lcd.print("Starting System");
}

void loop()
{
  if(Serial.available())
  {
    delay(5);
    if(Serial.available())
    {
      btSerial.write(Serial.read());
    }
  }

  if(btSerial.available())
  {
    delay(5);
    while(btSerial.available())
    {
      Serial.write(btSerial.read());
    }
  }

  /* 초음파 센서를 이용한 거리 측정 */
    digitalWrite(trig, LOW);
    digitalWrite(echo, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    unsigned long duration = pulseIn(echo, HIGH);
    float distance = duration/29.0/2.0;
    Serial.println(distance);
    delay(300);

    
    int isOrder = 0;
    unsigned long currTime,prevTime;
    int knockVal = 0;
    
    /* 40 < distance < 150에 장애물 존재 */
    if(distance < 150 && distance > 40 ){ 
      isOrder = 1;
      btSerial.write(isOrder); // 거리 정보 발신 

      /* LCD에 경고 메시지 출력 */
      lcd.home();
      lcd.clear();
      lcd.print("Warning! ");
      lcd.print("Obstacl");
      lcd.setCursor(0,1);
      lcd.print("es in 150cm");
    }

    /* 40 이내에 장애물 존재 */
    if(distance < 40){
      isOrder = 2;
      btSerial.write(isOrder); // 거리 정보 발신 

      /* LCD에 메시지 출력 */
      lcd.home();
      lcd.clear();
      lcd.print("Stopped. . .");
      lcd.setCursor(0,1);
      lcd.print("SUB: 1-2 SOS: 5");

      /* Knocking System 시작 */
      currTime = millis();
      prevTime = currTime;
      while(currTime - prevTime < 5000) // 5초동안 몇 번 노크했는지 측정
      {
          knockVal = analogRead(piezo);
          if(knockVal > 30) // 30 이상의 노크가 감지되면 노크 수 +1
          {
            howKnock++;
            delay(100);
          }

          currTime = millis();
      }

      btSerial.write(howKnock); // 노크 수 발신

      /* 노크 다섯 번일 때 메시지 출력 */
      if(howKnock == 5)
      {
        lcd.clear();
        lcd.print("Calling 119. . .");
      }
      howKnock = 0;
      
      delay(1800);
    }

    /* 장애물 없으면 주행 모드 */
    if(distance >150){
      isOrder = 0;
      btSerial.write(isOrder); // 거리 정보 발신 

      /* LCD에 메시지 출력 */
      lcd.home();
      lcd.clear();
      lcd.print("Press button");
      lcd.setCursor(0,1);
      lcd.print("If you want stop.");
    }


     
}

