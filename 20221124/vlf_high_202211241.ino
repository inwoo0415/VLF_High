// C++ code
//

#define F_Sonar 8
#define R_Sonar 10
#define L_Sonar 11



  
  // 차량 사이즈

float robot_width = 200; // robot의 폭
float mazor_width = 500; // 
float mazor_width_tolerance = 40;


  
  float Sonar_sensor(float EP)
{
  float duration = 0.0;
  float distance = 0.0;
  pinMode(EP, OUTPUT);
  digitalWrite(EP, LOW);
  digitalWrite(EP, HIGH);
  delay(10);
  digitalWrite(EP, LOW);
  pinMode(EP, INPUT);
  duration = pulseIn(EP, HIGH);
  distance = (duration*340.0)/2.0/1000.0;
  return distance;
}



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(F_Sonar , OUTPUT);
  pinMode(R_Sonar, OUTPUT);
  pinMode(L_Sonar, OUTPUT);
  Serial.begin(115200);




  

}
void loop()
{
 float measure_width =0;
  float L_distance, F_distance, R_distance;
    L_distance = Sonar_sensor(L_Sonar);
  R_distance = Sonar_sensor(R_Sonar);
    F_distance = Sonar_sensor(F_Sonar);
    Serial.print("L:"); Serial.print(L_distance);
    Serial.print("R:"); Serial.print(R_distance);
    Serial.print("F:"); Serial.print(F_distance);
  



int flag_mazor_1 = 0; //1이면 1번 구간에 내가 위치해 있음.

measure_width = L_distance + robot_width + R_distance;

if((measure_width >=( mazor_width- mazor_width_tolerance)) && (measure_width <=(mazor_width+mazor_width_tolerance)))
{
  if((F_distance > mazor_width) &&((F_distance < mazor_width + 400)))
  {
    flag_mazor_1 = 1;
  }
}
else
{
  flag_mazor_1 = 0;
}

}
