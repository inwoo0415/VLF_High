#define F_Sonar 8 // 전방 초음파 센서 핑을 8번에 연결
#define R_Sonar 10 // 오른쪽 초음파 센서 핑을 10번에 연결
#define L_Sonar 11 // 왼쪽 초음파 센서 핑을 11번에 연결
#define INL_1 2
#define INL_2 3
#define ENL 5

#define INR_1 7
#define INR_2 4
#define ENR 6


float F_distance = 0;
float R_distance = 0;
float L_distance = 0;


/*
float F_Sonar_sensor() // 전방 초음파 센서 실수 값 표현
{
  float duration = 0.0; // 변수(duration) 선언 및 초기화
  float distance = 0.0; // 변수(distance) 선언 및 초기화
  pinMode(F_Sonar, OUTPUT);
  digitalWrite(F_Sonar, LOW); // 전방 초음파 센서 출력 꺼짐
  digitalWrite(F_Sonar, HIGH); // 전방 초음파 센서 출력 켜짐
  delay(10); // 0.01초간 멈춤
  digitalWrite(F_Sonar, LOW); // 전방 초음파 센서 출력 꺼짐
  pinMode(F_Sonar, INPUT); // 전방 초음파 센서 값 입력  
  duration = pulseIn(F_Sonar, HIGH); // 전방 초음파 센서의 전압이 HIGH시점에서 LOW시점까지의 시간  
  distance = (duration * 340.0)/2.0/1000.0; // 전방 초음파 센서의 거리 값  
  return distance; // 거리 값 반환
}

float  R_Sonar_sensor() // 오른쪽 초음파 센서 실수 값 표현
{
  float duration = 0.0; // 변수(duration) 선언 및 초기화
  float distance = 0.0; // 변수(distance) 선언 및 초기화
  pinMode(R_Sonar, OUTPUT);
  digitalWrite(R_Sonar, LOW); // 오른쪽 초음파 센서 출력 꺼짐
  digitalWrite(R_Sonar, HIGH); // 오른쪽 초음파 센서 출력 켜짐
  delay(10); // 0.01초간 멈춤
  digitalWrite(R_Sonar, LOW); // 오른쪾 초음파 센서 출력 꺼짐  
  pinMode(R_Sonar, INPUT);  // 오른쪽 초음파 센서 값 입력
  duration = pulseIn(R_Sonar, HIGH); // 오른쪽 초음파 센서의 전압이 HIGH시점에서 LOW시점까지의 시간  
  distance = (duration * 340.0)/2.0/1000.0;  // 오른쪽 초음파 센서의 거리 값
  return distance;  // 거리 값 반환
}

float  L_Sonar_sensor() // 왼쪽 초음파 센서 실수 값 표현
{
  float duration = 0.0; // 변수(duration) 선언 및 초기화
  float distance = 0.0; // 변수(distance) 선언 및 초기화
  pinMode(L_Sonar, OUTPUT);
  digitalWrite(L_Sonar, LOW); // 왼쪽 초음파 센서 출력 꺼짐
  digitalWrite(L_Sonar, HIGH); // 왼쪽 초음파 센서 출력 켜짐
  delay(10);  // 0.01초간 멈춤
  digitalWrite(L_Sonar, LOW); // 왼쪽 초음파 센서 출력 꺼짐
  pinMode(L_Sonar, INPUT); // 왼쪽 초음파 센서 값 입력
  duration = pulseIn(L_Sonar, HIGH); // 왼쪽 초음파 센서의 전압이 HIGH시점에서 LOW시점까지의 시간
  distance = (duration * 340.0)/2.0/1000.0; // 왼쪽 초음파 센서의 거리 값
  return distance; // 거리 값 반환
}

void GO(int t, int e_speed)
{
  digitalWrite(INL_1,HIGH);
  digitalWrite(INL_2,LOW);
  digitalWrite(INR_1,HIGH);
  digitalWrite(INR_2,LOW);
  analogWrite(ENL, e_speed);
  analogWrite(ENR, e_speed);
  delay(t);
  }

void Back(int t, int e_speed)
{
  digitalWrite(INL_2,HIGH);
  digitalWrite(INL_1,LOW);
  digitalWrite(INR_2,HIGH);
  digitalWrite(INL_1,LOW);
  analogWrite(ENL,e_speed);
  analogWrite(ENR,e_speed);
  delay(t);
  }
 
void Right(int t,int e_speed)
{
  digitalWrite(INL_1,HIGH);
  digitalWrite(INL_2,LOW);
  digitalWrite(INR_2,HIGH);
  digitalWrite(INR_1,LOW);
  analogWrite(ENL,e_speed);
  analogWrite(ENR,e_speed);
  delay(t);
  }
 
void Left(int t,int e_speed)
{
  digitalWrite(INL_2,HIGH);
  digitalWrite(INL_1,LOW);
 
  digitalWrite(INR_1,HIGH);
  digitalWrite(INR_2,LOW);
  analogWrite(ENL,e_speed);
  analogWrite(ENR,e_speed);
  delay(t);
  }  

void Stop(int t)
{
  digitalWrite(INL_1,LOW);
  digitalWrite(INL_2,LOW);
  digitalWrite(INR_2,LOW);
  digitalWrite(INR_1,LOW);
  delay(t);
  }
*/
 

int line_sensor[5] = {0,0,0,0,0}; // 배열을 선언

int read_line_sensor()
{
  int i; // i라는 정수변수를 선언
  int sum = 0;
  int line_index = 0;
  for(i=0;i<5;i++)
  {
    line_sensor[i] =digitalRead(A0+i);
    sum += line_sensor[i];
    Serial.print(line_sensor[i]);
    Serial.print("   ");
  }
    Serial.println("");

    // line_sensor[0]   line_sensor[1]   line_sensor[2]   line_sensor[3]   line_sensor[4]
    //      -4            -3        -2         -1        0       1        2           3          4
    if(sum==1)
    {
      if(line_sensor[0]==1) line_index = -4;
      if(line_sensor[1]==1) line_index = -2;
      if(line_sensor[2]==1) line_index =  0;
      if(line_sensor[3]==1) line_index =  2;
      if(line_sensor[4]==1) line_index =  4;
    }
    if(sum==2)
    {
      if( (line_sensor[0]==1) && (line_sensor[1]==1) ) line_index = -3;
      if( (line_sensor[1]==1) && (line_sensor[2]==1) ) line_index = -1;
      if( (line_sensor[2]==1) && (line_sensor[3]==1) ) line_index =  1;
      if( (line_sensor[3]==1) && (line_sensor[4]==1) ) line_index =  3;
    }
    if(sum==5)
    {
      line_index = -10;  
    }
    if(sum==0)
    {
      line_index = 0;  
    }
Serial.print(line_index);
Serial.println("");
return line_index;

}// 라인 센서 구동 함수


void setup()
{
  // put your setup code here, to run once:
  pinMode(F_Sonar, OUTPUT); // 전방 초음파 센서 출력
  pinMode(R_Sonar, OUTPUT); // 오른쪽 초음파 센서 출력
  pinMode(L_Sonar, OUTPUT); // 왼쪽 초음파 센서 출력
  Serial.begin(115200);
  pinMode(INL_1, OUTPUT);
  pinMode(INL_2, OUTPUT);
  pinMode(INR_1, OUTPUT);
  pinMode(INR_2, OUTPUT);
  analogWrite(ENL, 100);
  analogWrite(ENR, 100);
}

void motor_control(int dir_l,int speed_l,int dir_r,int speed_r)
{
  if(dir_l == 1) // 전진
  {
    analogWrite(ENL , speed_l);
    digitalWrite(INL_1, HIGH);
    digitalWrite(INL_2, LOW);
   
  }
  else if(dir_l == -1) // 후진
  {
    analogWrite(ENL , speed_l);
    digitalWrite(INL_1, LOW);
    digitalWrite(INL_2, HIGH);
  }
  else
  {  analogWrite(ENL , 0);
    digitalWrite(INL_1, LOW);
    digitalWrite(INL_2, LOW);
  }
  if(dir_r == 1) // 전진
  {
    analogWrite(ENR , speed_r );
    digitalWrite(INR_1, HIGH);
    digitalWrite(INR_2, LOW);
  }
  else if(dir_r == -1) // 후진
  {
    analogWrite(ENR , speed_r );
    digitalWrite(INR_1, LOW);
    digitalWrite(INR_2, HIGH);
  }
  else
  {
    analogWrite(ENR , 0);
    digitalWrite(INR_1, LOW);
    digitalWrite(INR_2, LOW);
  }
}



void loop()
{
 
 
  int index;

  index = read_line_sensor();

  switch(index)
  {
    case -10 : // 정지
      motor_control(1,0,1,0);
      break;

    case 0 : // 전진
      motor_control(1,100,1,100);
      break;

    case -1 : // 좌회전
       motor_control( 1,10,1,200);
      break;
    case -2 :  
       motor_control(1,7,1,220);
      break;
    case -3 :
       motor_control(1,5,1,230);
      break;
    case -4 :
       motor_control(-1,250,1,250);
      break;
    case 1 : // 우회전
       motor_control(1,200,1,10);
      break;
    case 2 :
       motor_control(1,220,1,7);
      break;
    case 3 :
       motor_control(1,230,1,5);
      break;
    case 4 :
      motor_control(-1,250,1,250);
      break;              
  }
 
 
/*
F_distance = F_Sonar_sensor();
R_distance = R_Sonar_sensor();
L_distance = L_Sonar_sensor();

Serial.println("F_distance");
Serial.print(F_distance);
Serial.print("mm\n");

Serial.println("R_distance");
Serial.print(R_distance);
Serial.print("mm\n");

Serial.println("L_distance");
Serial.print(L_distance);
Serial.print("mm\n");
 
int time_angle_90 = 980;
int time_angle_180 = 1900;
int e_speed = 80;

if (F_distance <= 250 )
{
 Stop(1000);

  if(R_distance > L_distance)
  {
    Right(time_angle_90, e_speed);
    GO(300, e_speed);
    Stop(500);    
  }
 
  else if(L_distance > R_distance)
  {
    Left(time_angle_90, e_speed);
    GO(300, e_speed);
    Stop(500);    
  }
  else if(L_distance <=250 && R_distance <=250)
  {
    Right(time_angle_180, e_speed);
    Stop(500);
  }
}
 
else
{
 
  Stop(500);
 
  }*/

 
}
