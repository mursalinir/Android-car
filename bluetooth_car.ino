/*
This is the control program for the car.
*/
int r_pwm=3, l_pwm=9;
int rig_m_f=4;
int rig_m_b=5;
int lef_m_f=6;
int lef_m_b=7;
int s_v=0;
char data, Speed;

void setup()
{
  Serial.begin(9600);
  pinMode(lef_m_f,OUTPUT);
  pinMode(lef_m_b,OUTPUT);
  pinMode(rig_m_f,OUTPUT);
  pinMode(rig_m_b,OUTPUT);
  pinMode(r_pwm,OUTPUT);
  pinMode(l_pwm,OUTPUT);
  
 }
void loop() {
  if(Serial.available()>0)
  {
    data = Serial.read();
    if(data=='0' || data=='1' || data=='2' || data=='3' || data=='4' || data=='5' || data=='6' || data=='7' || data=='8' || data=='9')
    {
      Speed==data;
      Speed_value();
    }
    if(data == 'F')
    {
      forward();
    }
    if(data=='B')
    {
      backward();
    }
    if(data == 'L')
    {
      l_turn();
    }
    if(data=='R')
    {
      r_turn();
    }
    if(data == 'G')
    {
      f_left();
    }
    if(data=='I')
    {
      f_right();
    }
    if(data == 'H')
    {
      b_left();
    }
    if(data=='J')
    {
      b_right();
    }
    if(data == 'S')
    {
      Stop();
    }
  }
}

void forward()
{
  digitalWrite(lef_m_f,HIGH);
  digitalWrite(lef_m_b,LOW);
  digitalWrite(rig_m_f,HIGH);
  digitalWrite(rig_m_b,LOW);
  digitalWrite(l_pwm,s_v);
  digitalWrite(r_pwm,s_v);
}
void backward()
{
  digitalWrite(lef_m_f,LOW);
  digitalWrite(lef_m_b,HIGH);
  digitalWrite(rig_m_f,LOW);
  digitalWrite(rig_m_b,HIGH);
  digitalWrite(l_pwm,s_v);
  digitalWrite(r_pwm,s_v);
}
void l_turn()
{
  digitalWrite(lef_m_f,LOW);
  digitalWrite(lef_m_b,HIGH);
  digitalWrite(rig_m_f,HIGH);
  digitalWrite(rig_m_b,LOW);
  digitalWrite(l_pwm,s_v);
  digitalWrite(r_pwm,s_v);
}
void r_turn()
{
  digitalWrite(lef_m_f,HIGH);
  digitalWrite(lef_m_b,LOW);
  digitalWrite(rig_m_f,LOW);
  digitalWrite(rig_m_b,HIGH);
  digitalWrite(l_pwm,s_v);
  digitalWrite(r_pwm,s_v);
}
void f_left()
{
  digitalWrite(lef_m_f,LOW);
  digitalWrite(lef_m_b,LOW);
  digitalWrite(rig_m_f,HIGH);
  digitalWrite(rig_m_b,LOW);
  digitalWrite(l_pwm,0);
  digitalWrite(r_pwm,s_v);
}
void f_right()
{
  digitalWrite(lef_m_f,HIGH);
  digitalWrite(lef_m_b,LOW);
  digitalWrite(rig_m_f,LOW);
  digitalWrite(rig_m_b,LOW);
  digitalWrite(l_pwm,s_v);
  digitalWrite(r_pwm,0);
}
void b_left()
{
  digitalWrite(lef_m_f,LOW);
  digitalWrite(lef_m_b,LOW);
  digitalWrite(rig_m_f,LOW);
  digitalWrite(rig_m_b,HIGH);
  digitalWrite(l_pwm,0);
  digitalWrite(r_pwm,s_v);
}
void b_right()
{
  digitalWrite(lef_m_f,LOW);
  digitalWrite(lef_m_b,HIGH);
  digitalWrite(rig_m_f,LOW);
  digitalWrite(rig_m_b,LOW);
  digitalWrite(l_pwm,s_v);
  digitalWrite(r_pwm,0);
}
void Stop()
{
  digitalWrite(lef_m_f,LOW);
  digitalWrite(lef_m_b,LOW);
  digitalWrite(rig_m_f,LOW);
  digitalWrite(rig_m_b,LOW);
  digitalWrite(l_pwm,0);
  digitalWrite(r_pwm,0);
}
void Speed_value()
{
  
  if(Speed=='0')
    s_v=0;
  if(Speed=='1')
    s_v=15;
  if(Speed=='2')
    s_v=30;
  if(Speed=='3')
    s_v=45;
  if(Speed=='4')
    s_v=60;
  if(Speed=='5')
    s_v=75;
  if(Speed=='6')
    s_v=90;
  if(Speed=='7')
    s_v=105;
  if(Speed=='8')
    s_v=120;
  if(Speed=='9')
    s_v=135;   
}

