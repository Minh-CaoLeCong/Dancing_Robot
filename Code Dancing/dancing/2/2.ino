#include <Servo.h>

Servo RAnkle; Servo RHip; Servo LAnkle; Servo LHip; //define servo port

int RAnkleCenter = 100, LAnkleCenter = 90, RHipCenter = 95, LHipCenter = 84;
int i,j,pos;

void setup()
{
  Serial.begin(9600);
  RAnkle.attach(6); RHip.attach(9); LAnkle.attach(3); LHip.attach(5);
}
void Position0()
{
  RAnkle.write(0);LAnkle.write(0); RHip.write(0);LHip.write(0);
}
void Position180()
{
  RAnkle.write(180);LAnkle.write(180); RHip.write(180);LHip.write(180);
}
void Center()
{
  RAnkle.write(RAnkleCenter);delay(15); LAnkle.write(LAnkleCenter);delay(15); RHip.write(RHipCenter);delay(15); LHip.write(LHipCenter);delay(15);
}
void Test3s()
{
  delay(100);Center();delay(100);
  for (pos=0;pos<=25;pos+=1)
  {
    RHip.write(RHipCenter-pos);LHip.write(LHipCenter-pos);LAnkle.write(LAnkleCenter+pos);
    delay(15);
  }
  delay(100);Center();delay(100);
  for (pos=0;pos<=25;pos+=1)
  {
    RHip.write(RHipCenter+pos);LHip.write(LHipCenter+pos);RAnkle.write(RAnkleCenter-pos);
    delay(15);
  }
  //delay(500);
}
void Test15s()
{
  delay(35);Center();delay(35);
  for(i=0;i<=1;i++)
  {
    for(pos=0;pos<=25;pos+=1)
    {
      RHip.write(RHipCenter-pos);LHip.write(LHipCenter+pos);
      delay(15);
    }
    delay(35);Center();delay(35);
  }
  for(i=0;i<=2;i++)
  {
    for(pos=0;pos<=20;pos+=1)
    {
      RHip.write(RHipCenter-pos);LHip.write(LHipCenter+pos);
      delay(15);
    }
    delay(35);Center();delay(35);
  }
  //delay(500);
}
void Test17s()
{
  for(pos=0;pos<=35;pos+=1)
  {
    RAnkle.write(RAnkleCenter-pos);LAnkle.write(LAnkleCenter+pos);
    delay(25);
  }
  Center();
}
void Test18s()
{
  for(pos=0;pos<=10;pos+=1)
  {
    LAnkle.write(LAnkleCenter-pos);delay(15);RAnkle.write(RAnkleCenter-10);delay(15);
  }
  RAnkle.write(RAnkleCenter+10);delay(100);
  Center();
}
void Test20s()
{
  for(pos=0;pos<=35;pos+=1)
  {
    RAnkle.write(RAnkleCenter+pos);LAnkle.write(LAnkleCenter+pos);delay(15);
  }
  Center();delay(50);
  for(pos=0;pos<=35;pos+=1)
  {
    RAnkle.write(RAnkleCenter-pos);LAnkle.write(LAnkleCenter-pos);delay(15);
  }
  Center();delay(50);
}
void Test22s()
{
  delay(200);
  Center();
  delay(200);
  RAnkle.write(RAnkleCenter-20);
  LAnkle.write(LAnkleCenter+20);
  delay(500);
  RAnkle.write(RAnkleCenter);
  LAnkle.write(LAnkleCenter);
  delay(500);
  RHip.write(RHipCenter);
  LHip.write(LHipCenter);
}
void Test6()
{
  for(pos=0;pos<=15;pos+=1)
  {
    RAnkle.write(RAnkleCenter-pos);
    LAnkle.write(LAnkleCenter-pos);
    delay(15);
  }
  for(pos=15;pos>=0;pos-=1)
  {
    RAnkle.write(RAnkleCenter-pos);
    LAnkle.write(LAnkleCenter-pos);
    delay(15);
  }
  for(pos=0;pos<=20;pos+=1)
  {
    RAnkle.write(RAnkleCenter+pos);
    LAnkle.write(LAnkleCenter+pos);
    delay(15);
  }
  for(pos=15;pos>=0;pos-=1)
  {
    RAnkle.write(RAnkleCenter+pos);
    LAnkle.write(LAnkleCenter+pos);
    delay(15);
  }
}
void Test5()
{
  for(pos=0;pos<=15;pos+=1)
  {
    RAnkle.write(RAnkleCenter-pos);
    LAnkle.write(LAnkleCenter+pos);
    delay(15);
  }
  for(pos=10;pos>=0;pos-=1)
  {
    RAnkle.write(RAnkleCenter-pos);
    LAnkle.write(LAnkleCenter+pos);
    delay(15);
  }
  for(pos=0;pos<=15;pos+=1)
  {
    RAnkle.write(RAnkleCenter+pos);
    LAnkle.write(LAnkleCenter-pos);
    delay(15);
  }
  for(pos=15;pos>=0;pos-=1)
  {
    RAnkle.write(RAnkleCenter+pos);
    LAnkle.write(LAnkleCenter-pos);
    delay(15);
  }
}
void Test4()
{
  delay(200);
  Center();
  delay(200);
  LAnkle.write(LAnkleCenter+15);
  //delay(100);
  RAnkle.write(RAnkleCenter+15);
  delay(200);
  Center();
  delay(200);
  RAnkle.write(RAnkleCenter-15);
  //delay(100);
  LAnkle.write(LAnkleCenter-15);
  //delay(500);
  delay(200);
  Center();
  delay(200);
  LAnkle.write(LAnkleCenter-15);
  //delay(100);
  RAnkle.write(RAnkleCenter-15);
  delay(200);
  Center();
  delay(200);
  RAnkle.write(RAnkleCenter+15);
  //delay(100);
  LAnkle.write(LAnkleCenter+15);
  //delay(500);
  
}
void Test3()
{
  delay(200);
  Center();
  delay(200);
  RAnkle.write(RAnkleCenter+15);
  delay(200);
  LAnkle.write(LAnkleCenter+15);
  delay(200);
  LAnkle.write(LAnkleCenter-15);
  delay(200);
  Center();
  delay(200);
  LAnkle.write(LAnkleCenter-15);
  delay(200);
  RAnkle.write(RAnkleCenter-15);
  delay(200);
  RAnkle.write(RAnkleCenter+15);
  //delay(500);
}
void Test2()
{
  delay(200);
  Center();
  delay(200);
  RHip.write(RHipCenter-15);
  LHip.write(LHipCenter-15);
  delay(500);
  for (i=0;i<5;i++)// dung while(true)
  {
    RHip.write(RHipCenter+15);
    delay(500);
    LHip.write(LHipCenter+15);
    delay(500);
    LHip.write(LHipCenter-15);
    delay(500);
    RHip.write(RHipCenter-15);
    delay(500);
  }
}
void Test1()
{
  for(i=0;i<=3;i++)
  {
  delay(200);
  Center();
  delay(200);
  LAnkle.write(LAnkleCenter+15);
  delay(200);
  RHip.write(RHipCenter-15);
  LHip.write(LHipCenter-15);
  delay(200);
  LAnkle.write(LAnkleCenter);
  RAnkle.write(RAnkleCenter-15);
  delay(200);
  RHip.write(RHipCenter+15);
  LHip.write(LHipCenter+15);
  //delay(1000);
  }
}
void Test()
{
  delay(200);
  Center();
  delay(200);
  RAnkle.write(RAnkleCenter-10);
  LAnkle.write(LAnkleCenter+10);
  delay(200);
  for (i=0;i<5;i++) // dung while(true)
  {
  RHip.write(RHipCenter-15);
  LHip.write(LHipCenter-15);
  delay(200);
  RHip.write(RHipCenter+15);
  LHip.write(LHipCenter+15);
  delay(200);
  }
}
void Test6a()
{
  for(pos=0;pos<=20;pos+=3)
  {
    RAnkle.write(RAnkleCenter-pos);
    LAnkle.write(LAnkleCenter-pos);
    delay(15);
  }
  for(pos=20;pos>=20;pos-=3)
  {
    RAnkle.write(RAnkleCenter-pos);
    LAnkle.write(LAnkleCenter-pos);
    delay(15);
  }
  for(pos=0;pos<=20;pos+=3)
  {
    RAnkle.write(RAnkleCenter+pos);
    LAnkle.write(LAnkleCenter+pos);
    delay(15);
  }
  for(pos=20;pos>=20;pos-=3)
  {
    RAnkle.write(RAnkleCenter+pos);
    LAnkle.write(LAnkleCenter+pos);
    delay(15);
  }
}
void Test5a()
{
  for(pos=0;pos<=20;pos+=3)
  {
    RAnkle.write(RAnkleCenter-pos);
    LAnkle.write(LAnkleCenter+pos);
    delay(15);
  }
  for(pos=20;pos>=20;pos-=3)
  {
    RAnkle.write(RAnkleCenter-pos);
    LAnkle.write(LAnkleCenter+pos);
    delay(15);
  }
  for(pos=0;pos<=20;pos+=3)
  {
    RAnkle.write(RAnkleCenter+pos);
    LAnkle.write(LAnkleCenter-pos);
    delay(15);
  }
  for(pos=20;pos>=20;pos-=3)
  {
    RAnkle.write(RAnkleCenter+pos);
    LAnkle.write(LAnkleCenter-pos);
    delay(15);
  }
}
void Test4a()
{
  delay(100);
  Center();
  delay(100);
  LAnkle.write(LAnkleCenter+15);
  //delay(100);
  RAnkle.write(RAnkleCenter+15);
  delay(100);
  Center();
  delay(100);
  RAnkle.write(RAnkleCenter-15);
  //delay(100);
  LAnkle.write(LAnkleCenter-15);
  //delay(500);
  delay(100);
  Center();
  delay(100);
  LAnkle.write(LAnkleCenter-15);
  //delay(100);
  RAnkle.write(RAnkleCenter-15);
  delay(100);
  Center();
  delay(100);
  RAnkle.write(RAnkleCenter+15);
  //delay(100);
  LAnkle.write(LAnkleCenter+15);
  //delay(500);
  
}
void Test3a()
{
  delay(100);
  Center();
  delay(100);
  RAnkle.write(RAnkleCenter+15);
  delay(100);
  LAnkle.write(LAnkleCenter+15);
  delay(100);
  LAnkle.write(LAnkleCenter-15);
  delay(100);
  Center();
  delay(100);
  LAnkle.write(LAnkleCenter-15);
  delay(100);
  RAnkle.write(RAnkleCenter-15);
  delay(100);
  RAnkle.write(RAnkleCenter+15);
  //delay(500);
}
void Test2a()
{
  delay(100);
  Center();
  delay(100);
  RHip.write(RHipCenter-15);
  LHip.write(LHipCenter-15);
  delay(200);
  for (i=0;i<3;i+=1)// dung while(true)
  {
    RHip.write(RHipCenter+15);
    delay(100);
    LHip.write(LHipCenter+15);
    delay(100);
    LHip.write(LHipCenter-15);
    delay(100);
    RHip.write(RHipCenter-15);
    delay(100);
  }
}
void Test1a()
{
  for(i=0;i<=3;i++)
  {
  delay(100);
  Center();
  delay(100);
  LAnkle.write(LAnkleCenter+15);
  delay(100);
  RHip.write(RHipCenter-15);
  LHip.write(LHipCenter-15);
  delay(100);
  LAnkle.write(LAnkleCenter);
  RAnkle.write(RAnkleCenter-15);
  delay(100);
  RHip.write(RHipCenter+15);
  LHip.write(LHipCenter+15);
  //delay(1000);
  }
}
void Testa()
{
  delay(100);
  Center();
  delay(100);
  RAnkle.write(RAnkleCenter-10);
  LAnkle.write(LAnkleCenter+10);
  delay(100);
  for (i=0;i<3;i++) // dung while(true)
  {
  RHip.write(RHipCenter-15);
  LHip.write(LHipCenter-15);
  delay(100);
  RHip.write(RHipCenter+15);
  LHip.write(LHipCenter+15);
  delay(100);
  }
}
void one()
{
  RAnkle.write(RAnkleCenter+40);delay(500);
  for(i=0;i<=5;i++)
  {
  for(pos=0;pos<=50;pos+=1)
  {
    LAnkle.write(LAnkleCenter-pos);delay(15);
  }
  for(pos=50;pos>=0;pos-=1)
  {
    LAnkle.write(LAnkleCenter-pos);delay(15);
  }
  for(pos=0;pos<=50;pos+=1)
  {
    LAnkle.write(LAnkleCenter+pos);delay(15);
  }
  for(pos=50;pos>=0;pos-=1)
  {
    LAnkle.write(LAnkleCenter+pos);delay(15);
  }
  }
}
void loop()
{
  Center(); delay(50);
  Test();
  Test1();
  Test2();
  Test3();
  Test4();
  Center(); delay(50);
  Test5();
  Center(); delay(50);
  Test6();
  Center(); delay(20);
  Testa();
  Test1a();
  Test2a();
  Test3a();
  Test4a();
  Center(); delay(20);
  Test5a();
  Center(); delay(20);
  Test6a();
  
}

