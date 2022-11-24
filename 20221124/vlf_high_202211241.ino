// C++ code
//

#define F_Sonar 8
#define R_Sonar 10
#define L_Sonar 11


  
  // 차량 사이즈

float robot_width = 200; // robot의 폭
float mazor_width = 500;
float mazor_width_tolerance = 40;



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(F_Sonar , OUTPUT);
  pinMode(R_Sonar, OUTPUT);
  pinMode(L_Sonar, OUTPUT);
  Serial.begin(115200);
  
  float F_Sonar_sensor()
{
  float duraton = 0.0;
  float distance = 0.0;
  pinMode(F_Sonar, OUTPUT);
  digitalWrite(F_Sonar, LOW);
  digitalWrite(F_Sonar, HIGH);
  delay(10);
  digitalWrite(F_Sonar, LOW);
  pinMode(F_Sonar, INPUT);
  duration = pulsein(F_Sonar, HIGH);
  distance = (duration*340.0)/2.0/1000.0;
  return distance
}
float R_Sonar_sensor()
{
  float duraton = 0.0;
  float distance = 0.0;
  pinMode(R_Sonar, OUTPUT);
  digitalWrite(R_Sonar, LOW);
  digitalWrite(R_Sonar, HIGH);
  delay(10);
  digitalWrite(R_Sonar, LOW);
  pinMode(R_Sonar, INPUT);
  duration = pulsein(R_Sonar, HIGH);
  distance = (duration*340.0)/2.0/1000.0;
  return distance
}
float L_Sonar_sensor()
{
  float duraton = 0.0;
  float distance = 0.0;
  pinMode(L_Sonar, OUTPUT);
  digitalWrite(L_Sonar, LOW);
  digitalWrite(L_Sonar, HIGH);
  delay(10);
  digitalWrit(L_Sonar, LOW);
  pinMode(L_Sonar, INPUT);
  duration = pulsein(L_Sonar, HIGH);
  distance = (duration*340.0)/2.0/1000.0;
  return distance
}

  
}

void loop()
{
	float L_distance, F_distance, R_distance;
  	L_distance = L_Sonar_sensor();
	R_distance = R_Sonar_sensor();
  	F_distance = F_Sonar_sensor();
  	Serial.print("L:"); Serial.print(L_distance);
  	Serial.print("R:"); Serial.print(R_distance);
  	Serial.print("F:"); Serial.print(F_distance);
  



int flag_mazor_1 = 0; //1이면 1번 구간에 내가 위치해 있음.

measure_width = L_distance + robot_width + R_distance;

if(measure_width >=( mazor_width- mazor_width_tolerance)) && (measure_width <=(mazor_width+mazor_width_tolerance)))
{
  if(F_distance > mazor_width) &&((F_distance < mazor_width + 400))
  {
    flag_mazor_1 = 1;
  }
}
else
{
  flag_mazor_1 = 0;
}
  	
  
}

