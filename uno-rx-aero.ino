int m1_X = 5, m1_Y = 6, m2_X = 10, m2_Y =11; 
int CHA=8;
int CHB=9;
int v_CHA;
int v_CHB;

void setup() 
{
 Serial.begin(9600);
 pinMode(m1_X, OUTPUT);
 pinMode(m1_Y, OUTPUT);
 pinMode(m2_X, OUTPUT);
 pinMode(m2_Y, OUTPUT);
}

void loop()
{
  v_CHA = pulseIn(CHA, HIGH, 20000);
  v_CHB = pulseIn(CHB, HIGH, 20000);
  
  Serial.println(v_CHA);
  Serial.println(v_CHB);
  Serial.println("--------");
  
     if(v_CHA >= 1600)
     { 
      digitalWrite(m1_X, HIGH);     //ROTINA ANDAR FRENTE VEL MAX.
      digitalWrite(m2_X, HIGH);
     }

     if(v_CHA <= 1300)
     {
      digitalWrite(m1_Y, HIGH);     //ROTINA ANDAR TRAS VEL MAX.
      digitalWrite(m2_Y, HIGH);
     }
     
     if(v_CHA < 1600 & v_CHA > 1300)
     {
        
      digitalWrite(m1_X, LOW);     //ROTINA PARAR.
      digitalWrite(m2_X, LOW);
      digitalWrite(m1_Y, LOW);     //ROTINA PARAR.
      digitalWrite(m2_Y, LOW); 
     }
     
     if(v_CHB >= 1600)
     { 
      digitalWrite(m1_X, HIGH);     //ROTINA ANDAR TRAS VEL MAX.
      digitalWrite(m2_Y, HIGH);
     }

     if(v_CHB <= 1300)
     {
      digitalWrite(m1_Y, HIGH);     //ROTINA ANDAR FRENTE VEL MAX.
      digitalWrite(m2_X, HIGH);
     } 
}
