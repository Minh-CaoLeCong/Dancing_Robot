#include <Servo.h>

Servo RShoulder; Servo RUpperarm; Servo RForearm; Servo LShoulder; Servo LUpperarm; Servo LForearm;//define servo port

int RShoulderC=70, LShoulderC=75, RUArmC=60, LUArmC=90, RFArmC=80, LFArmC=90;
int i,j,pos;
const int sampleWindow = 7; // lấy mẫu 50ms (50 mS = 20Hz)
unsigned int sample;
float k=0;
float tong=0;
int m=0;
void setup()
{
  Serial.begin(9600);
  RShoulder.attach(3); RUpperarm.attach(5); RForearm.attach(6); LShoulder.attach(9); LUpperarm.attach(10); LForearm.attach(11);
}
void cbat() 
{
  for(int i=0;i<20;i++){
   unsigned long startMillis= millis();  
   unsigned int peakToPeak = 0;   
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(A0);
      if (sample < 1024)  
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // lưu lại giá trị max
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // lưu lại giá trị min
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  //chuyển sang volts
   
   tong=tong+volts;
  }
  k=tong/20;
tong=0;
}
void Center()
{
  RShoulder.write(RShoulderC);delay(15);RUpperarm.write(RUArmC);delay(15);RForearm.write(RFArmC);delay(15);LShoulder.write(LShoulderC);delay(15);LUpperarm.write(LUArmC);delay(15);LForearm.write(LFArmC);delay(15);
}
void Hello2()
{
  RShoulder.write(180);delay(100);
  RUpperarm.write(180);delay(100);
  RForearm.write(0);delay(100);
  LShoulder.write(180);delay(100);
  LUpperarm.write(180);delay(100);
  LForearm.write(180);delay(100);
}
void wave72()
{
  for(i=0;i<=3;i++)
  {
  for(pos=0;pos<=30;pos+=3)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    delay(30);
  }
  for(pos=30;pos>=0;pos-=3)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    delay(30);
  }
  for(pos=0;pos<=40;pos+=3)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    delay(30);
  }
  for(pos=40;pos>=0;pos-=3)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    delay(30);
  }
  }
  Center(); delay(100);
}
void wave62()
{
  for(i=0;i<=3;i++)
  {
  for(pos=0;pos<=50;pos+=3)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(30);
  }
  for(pos=50;pos>=0;pos-=3)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(30);
  }
  for(pos=0;pos<=50;pos+=3)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(30);
  }
  for(pos=50;pos>=0;pos-=3)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(30);
  }
  }
  Center(); delay(100);
}
void wave52()
{
  for(i=0;i<3;i++)
  {
  for(pos=0;pos<=90;pos+=3)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(30);
  }
  for(pos=90;pos>=0;pos-=3)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(30);
  }
  for(pos=0;pos<=90;pos+=3)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(30);
  }
  for(pos=90;pos>=0;pos-=3)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(30);
  }
  //Center(); delay(15);
  }
  Center(); delay(100);
}
void wave42()
{
  for(i=0;i<3;i++)
  {
  for(pos=0;pos<=90;pos+=3)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    delay(30);
  }
  for(pos=90;pos>=0;pos-=3)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    delay(30);
  }
  for(pos=0;pos<=90;pos+=3)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    delay(30);
  }
  for(pos=90;pos>=0;pos-=3)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    delay(30);
  }
  //Center(); delay(15);
  }
  Center(); delay(100);
}
void wave32()
{
  RShoulder.write(100);delay(15);
  LShoulder.write(0);delay(15);
  LUpperarm.write(180);delay(15);
  RUpperarm.write(160);delay(15);
  for(i=0;i<5;i++)
  {
  for(pos=0;pos<=50;pos+=3)
  {
    RShoulder.write(100+pos);
    LShoulder.write(0+pos);
    delay(30);
  }
  for(pos=50;pos>=0;pos-=3)
  {
    RShoulder.write(100+pos);
    LShoulder.write(0+pos);
    delay(30);
  }
  
  }
  Center(); delay(100);
}
void wave22()
{
  for(pos=0;pos<=80;pos+=3)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC-pos);
    delay(30);
  }
  for(pos=80;pos>=0;pos-=3)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC-pos);
    delay(30);
  }
  for(pos=0;pos<=80;pos+=3)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC+pos);
    delay(30);
  }
  for(pos=80;pos>=0;pos-=3)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC+pos);
    delay(30);
  }
  Center(); delay(100);
}

void wave12()
{
  Center(); delay(100);
  for(pos=0;pos<=20;pos+=3)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    delay(30);
  }
  for(pos=20;pos>=0;pos-=3)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    delay(30);
  }
}
void Hello1()
{
  RShoulder.write(180);delay(500);
  RUpperarm.write(180);delay(500);
  RForearm.write(0);delay(500);
  LShoulder.write(180);delay(500);
  LUpperarm.write(180);delay(500);
  LForearm.write(180);delay(500);
}
void wave71()
{
  for(i=0;i<=3;i++)
  {
  for(pos=0;pos<=30;pos+=2)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    delay(20);
  }
  for(pos=30;pos>=0;pos-=2)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    delay(20);
  }
  for(pos=0;pos<=40;pos+=2)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    delay(20);
  }
  for(pos=40;pos>=0;pos-=2)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    delay(20);
  }
  }
  Center(); delay(500);
}
void wave61()
{
  for(i=0;i<=3;i++)
  {
  for(pos=0;pos<=50;pos+=2)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(20);
  }
  for(pos=50;pos>=0;pos-=2)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(20);
  }
  for(pos=0;pos<=50;pos+=2)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(20);
  }
  for(pos=50;pos>=0;pos-=2)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(20);
  }
  }
  Center(); delay(500);
}
void wave51()
{
  for(i=0;i<3;i++)
  {
  for(pos=0;pos<=90;pos+=2)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(20);
  }
  for(pos=90;pos>=0;pos-=2)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(20);
  }
  for(pos=0;pos<=90;pos+=2)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(20);
  }
  for(pos=90;pos>=0;pos-=2)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(20);
  }
  //Center(); delay(15);
  }
  Center(); delay(500);
}
void wave41()
{
  for(i=0;i<3;i++)
  {
  for(pos=0;pos<=90;pos+=2)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    delay(20);
  }
  for(pos=90;pos>=0;pos-=2)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    delay(20);
  }
  for(pos=0;pos<=90;pos+=2)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    delay(20);
  }
  for(pos=90;pos>=0;pos-=2)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    delay(20);
  }
  //Center(); delay(15);
  }
  Center(); delay(500);
}
void wave31()
{
  RShoulder.write(100);delay(100);
  LShoulder.write(0);delay(100);
  LUpperarm.write(180);delay(100);
  RUpperarm.write(160);delay(100);
  for(i=0;i<3;i++)
  {
  for(pos=0;pos<=50;pos+=2)
  {
    RShoulder.write(100+pos);
    LShoulder.write(0+pos);
    delay(20);
  }
  for(pos=50;pos>=0;pos-=2)
  {
    RShoulder.write(100+pos);
    LShoulder.write(0+pos);
    delay(20);
  }
  
  }
  Center(); delay(500);
}
void wave21()
{
  for(pos=0;pos<=80;pos+=2)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC-pos);
    delay(20);
  }
  for(pos=80;pos>=0;pos-=2)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC-pos);
    delay(20);
  }
  for(pos=0;pos<=80;pos+=2)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC+pos);
    delay(20);
  }
  for(pos=80;pos>=0;pos-=2)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC+pos);
    delay(20);
  }
  Center(); delay(500);
}

void wave11()
{
  Center(); delay(500);
  for(pos=0;pos<=20;pos+=2)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    delay(20);
  }
  for(pos=20;pos>=0;pos-=2)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    delay(20);
  }
}
void Hello()
{
  RShoulder.write(180);delay(1000);
  RUpperarm.write(180);delay(1000);
  RForearm.write(0);delay(1000);
  LShoulder.write(180);delay(1000);
  LUpperarm.write(180);delay(1000);
  LForearm.write(180);delay(1000);
}
void wave7()
{
  for(i=0;i<=3;i++)
  {
  for(pos=0;pos<=30;pos+=1)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    delay(15);
  }
  for(pos=30;pos>=0;pos-=1)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    delay(15);
  }
  for(pos=0;pos<=40;pos+=1)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    delay(15);
  }
  for(pos=40;pos>=0;pos-=1)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    delay(15);
  }
  }
  Center(); delay(1000);
}
void wave6()
{
  for(i=0;i<=3;i++)
  {
  for(pos=0;pos<=50;pos+=1)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(15);
  }
  for(pos=50;pos>=0;pos-=1)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(15);
  }
  for(pos=0;pos<=50;pos+=1)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(15);
  }
  for(pos=50;pos>=0;pos-=1)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(15);
  }
  }
  Center(); delay(1000);
}
void wave5()
{
  for(i=0;i<3;i++)
  {
  for(pos=0;pos<=90;pos+=3)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(15);
  }
  for(pos=90;pos>=0;pos-=3)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    RShoulder.write(RShoulderC+pos);
    LShoulder.write(LShoulderC+pos);
    delay(15);
  }
  for(pos=0;pos<=90;pos+=3)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(15);
  }
  for(pos=90;pos>=0;pos-=3)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    RShoulder.write(RShoulderC-pos);
    LShoulder.write(LShoulderC-pos);
    delay(15);
  }
  //Center(); delay(15);
  }
  Center(); delay(1000);
}
void wave4()
{
  for(i=0;i<3;i++)
  {
  for(pos=0;pos<=90;pos+=1)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    delay(15);
  }
  for(pos=90;pos>=0;pos-=1)
  {
    RUpperarm.write(RUArmC-pos);
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC-pos);
    RForearm.write(RFArmC-pos);
    delay(15);
  }
  for(pos=0;pos<=90;pos+=1)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    delay(15);
  }
  for(pos=90;pos>=0;pos-=1)
  {
    RUpperarm.write(RUArmC+pos);
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC+pos);
    RForearm.write(RFArmC+pos);
    delay(15);
  }
  //Center(); delay(15);
  }
  Center(); delay(1000);
}
void wave3()
{
  RShoulder.write(100);delay(500);
  LShoulder.write(0);delay(500);
  LUpperarm.write(180);delay(500);
  RUpperarm.write(160);delay(500);
  for(i=0;i<3;i++)
  {
  for(pos=0;pos<=50;pos+=1)
  {
    RShoulder.write(100+pos);
    LShoulder.write(0+pos);
    delay(15);
  }
  for(pos=50;pos>=0;pos-=1)
  {
    RShoulder.write(100+pos);
    LShoulder.write(0+pos);
    delay(15);
  }
  
  }
  Center(); delay(1000);
}
void wave2()
{
  for(pos=0;pos<=80;pos+=1)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC-pos);
    delay(15);
  }
  for(pos=80;pos>=0;pos-=1)
  {
    LUpperarm.write(LUArmC-pos); LForearm.write(LFArmC-pos);
    RUpperarm.write(RUArmC+pos); RForearm.write(RFArmC-pos);
    delay(15);
  }
  for(pos=0;pos<=80;pos+=1)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC+pos);
    delay(15);
  }
  for(pos=80;pos>=0;pos-=1)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC+pos);
    RUpperarm.write(RUArmC-pos); RForearm.write(RFArmC+pos);
    delay(15);
  }
  Center(); delay(1000);
}

void wave1()
{
  Center(); delay(1000);
  for(pos=0;pos<=20;pos++)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    delay(15);
  }
  for(pos=20;pos>=0;pos--)
  {
    LUpperarm.write(LUArmC+pos); LForearm.write(LFArmC-pos);
    delay(15);
  }
}
void down()
{
  for(pos=0;pos<=90;pos+=5)
  {
    LUpperarm.write(LUArmC+pos);
    RUpperarm.write(RUArmC+pos);
    delay(15);
  }
}
void one()
{
  RUpperarm.write(RUArmC-20);
  delay(5000);//delay voi gui ki tu
  Serial.write('1'); delay(1000);
  for(i=0;i<5;i++)
  {
  for(pos=0;pos<=90;pos+=3)
  {
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC-pos);
    delay(15);
  }
  for(pos=90;pos>=0;pos-=3)
  {
    LUpperarm.write(LUArmC-pos);
    LForearm.write(LFArmC-pos);
    delay(15);
  }
  for(pos=0;pos<=90;pos+=3)
  {
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC+pos);
    delay(15);
  }
  for(pos=90;pos>=0;pos-=3)
  {
    LUpperarm.write(LUArmC+pos);
    LForearm.write(LFArmC+pos);
    delay(15);
  }
  }
}
void loop()
{
  Center(); delay(1000);
  Hello();
  Center(); delay(1000);
  wave7();
  wave6();
  wave5();
  wave4();
  wave3();
  Center(); delay(1000);
  wave2();
  wave1();
  Center(); delay(500);
  Hello1();
  Center(); delay(500);
  wave71();
  wave61();
  wave51();
  wave41();
  wave31();
  Center(); delay(500);
  wave21();
  wave11();
  Center(); delay(100);
  Hello2();
  Center(); delay(100);
  wave72();
  wave62();
  wave52();
  wave42();
  wave32();
  Center(); delay(100);
  wave22();
  wave12();
  //while(true);
  
}

