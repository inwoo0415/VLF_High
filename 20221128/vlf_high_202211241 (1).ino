// C++ code
//

#define F_Sonar 8 // 전방 초음파 센서 핑을 8번에 연결
#define R_Sonar 10 // 오른쪽 초음파 센서 핑을 10번에 연결
#define L_Sonar 11 // 왼쪽 초음파 센서 핑을 11번에 연결



 
  // 차량 사이즈

float robot_width = 200; // robot의 폭
float mazor_width = 500; // 도로의 폭
float mazor_width_tolerance = 40; // 도로의 폭의 오차 범위


 
float F_Sonar_sensor() // 전방 초음파 센서 실수 값 표현
{
  float duration = 0.0; // 변수(duration) 선언 및 초기화
  float distance = 0.0; // 변수(distance) 선언 및 초기화
  pinMode(F_Sonar, OUTPUT); // 전방 초음파 센서 출력
  digitalWrite(F_Sonar, LOW); // 전방 초음파 센서 출력 꺼짐
  digitalWrite(F_Sonar, HIGH); // 전방 초음파 센서 출력 켜짐
  delay(10); // 0.01초간 멈춤
  digitalWrite(F_Sonar, LOW); // 전방 초음파 센서 출력 꺼짐
  pinMode(F_Sonar, INPUT);  // 전방 초음파 센서 값 입력
  duration = pulseIn(F_Sonar, HIGH); // 전방 초음파 센서의 전압이 HIGH시점에서 LOW시점까지의 시간
  distance = (duration * 340.0)/2.0/1000.0; // 전방 초음파 센서의 거리 값
  return distance; // 거리 값 반환
}

float L_Sonar_sensor() // 왼쪽 초음파 센서 실수 값 표현
{
  float duration = 0.0; // 변수(duration) 선언 및 초기화
  float distance = 0.0; // 변수(distance) 선언 및 초기화
  pinMode(L_Sonar, OUTPUT); // 왼쪽 초음파 센서 출력
  digitalWrite(L_Sonar, LOW); // 왼쪽 초음파 센서 출력 꺼짐
  digitalWrite(L_Sonar, HIGH); // 왼쪽 초음파 센서 출력 켜짐
  delay(10); // 0.01초간 멈춤
  digitalWrite(L_Sonar, LOW); // 왼쪽 초음파 센서 출력 꺼짐
  pinMode(L_Sonar, INPUT);  // 왼쪽 초음파 센서 값 입력
  duration = pulseIn(L_Sonar, HIGH); // 왼쪽 초음파 센서의 전압이 HIGH시점에서 LOW시점까지의 시간
  distance = (duration * 340.0)/2.0/1000.0; // 왼쪽 초음파 센서의 거리 값
  return distance; // 거리 값 반환
}

float R_Sonar_sensor() // 오른쪽 초음파 센서 실수 값 표현
{
  float duration = 0.0; // 변수(duration) 선언 및 초기화
  float distance = 0.0; // 변수(distance) 선언 및 초기화
  pinMode(R_Sonar, OUTPUT); // 오른쪽 초음파 센서 출력
  digitalWrite(R_Sonar, LOW); // 오른쪽 초음파 센서 출력 꺼짐
  digitalWrite(R_Sonar, HIGH); // 오른쪽 초음파 센서 출력 켜짐
  delay(10); // 0.01초간 멈춤
  digitalWrite(R_Sonar, LOW); // 오른쪾 초음파 센서 출력 꺼짐
  pinMode(R_Sonar, INPUT);  // 오른쪽 초음파 센서 값 입력
  duration = pulseIn(R_Sonar, HIGH); // 오른쪽 초음파 센서의 전압이 HIGH시점에서 LOW시점까지의 시간
  distance = (duration * 340.0)/2.0/1000.0; // 오른쪽 초음파 센서의 거리 값
  return distance; // 거리 값 반환
}


void setup() // 처음 한번만 실행
{
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(F_Sonar , OUTPUT); // 전방 초음파 센서 출력
  pinMode(R_Sonar, OUTPUT); // 오른쪽 초음파 센서 출력
  pinMode(L_Sonar, OUTPUT); // 왼쪽 초음파 센서 출력
  Serial.begin(115200); // 전송속도를 115200 bps로 설정




 

}
void loop() // 계속 반복 실행
{
 float measure_width =0; measure_width // 변수 선언 및 초기화
  float L_distance, F_distance, R_distance; // L_distance, F_distance, R_distance 변수 선언
    L_distance = Sonar_sensor(L_Sonar); // 왼쪽 거리값은 왼쪽 초음파 센서 값
  R_distance = Sonar_sensor(R_Sonar); // 오른쪽 거리값은 오른쪽 초음파 센서 값
    F_distance = Sonar_sensor(F_Sonar); // 전방 거리값은 전방 초음파 센서 값
    Serial.print("L:"); Serial.print(L_distance); // 왼쪽 초음파 센서 출력값 L : 
    Serial.print("R:"); Serial.print(R_distance); // 오른쪽 초음파 센서 출력값 R :
    Serial.print("F:"); Serial.print(F_distance); // 전방 초음파 센서 출력값 F :
 



int flag_mazor_1 = 0; //1이면 1번 구간에 내가 위치해 있음.

measure_width = L_distance + robot_width + R_distance; // measure_width 변수는 왼쪽 초음파 센서의 거리 값 + 차 폭 + 오른쪽 초음파 센서 거리 값 

if((measure_width >=( mazor_width- mazor_width_tolerance)) && (measure_width <=(mazor_width+mazor_width_tolerance))) // measure_width 변수가 도로폭에서 변수를 뺀값과 더한 값 사이에 위치한더면  
{			
  if((F_distance > mazor_width) &&((F_distance < mazor_width + 400))) // 전방 초음파 센서가 인지한 값이 도로의 폭보다 큰 동시에 도로의 폭 + 400을 더한 값보다 작다면
  {
    flag_mazor_1 = 1; // 조건이 성립함
  }
}
else
{
  flag_mazor_1 = 0; // 조건이 성립하지 않으면 반복
}

}