int ForcaM1 = 10; // ForcaM Motor 1
int PoM1 = 11; // Polaridade Motor 1
//int ForcaM2 = 9; // ForcaM Motor 2  
//int PoM2 = 8; // Polaridade Motor 2
int ledStatus = 13;

int InicialM1 = 0;
//int InicialM2 = 0;

int i = 25;     
boolean goUp = true ; // Sentido da rotação

void setup()
{
  pinMode(ForcaM1, OUTPUT); 
  pinMode(PoM1, OUTPUT); 
  pinMode(ledStatus, OUTPUT);
 // pinMode(ForcaM2, OUTPUT);   
 // pinMode(PoM2, OUTPUT);   

  digitalWrite(PoM1, HIGH) ;   
 // digitalWrite(PoM2, LOW) ;

 // analogWrite(ForcaM1, InicialM1); 
 // analogWrite(ForcaM2, InicialM2); 
}

void loop()
{
  
  digitalWrite(PoM1, HIGH) ;  
  digitalWrite(ledStatus, LOW);
   
  for(int i = 0; i < 100; i++)
  {
    analogWrite(ForcaM1, i); 
  }
       
  delay(2000);
       
  digitalWrite(PoM1, LOW) ;
     
  for(int i = 0; i < 100; i++)
  {
    analogWrite(ForcaM1, i); 
  }
       
  delay(2000);
         
             
/*
  if ((InicialM1  < 250) && (goUp))
  {
    InicialM1 = InicialM1 + i;
//    InicialM2 = InicialM2 + i;      
  }
  else
  {
    goUp = false;            
    InicialM1 = InicialM1 - i;       
  //  InicialM2 = InicialM2 - i;  
    
    if ((InicialM1 > 75) && (InicialM1< 255))
    {
      analogWrite(ForcaM1, InicialM1);  
    //  analogWrite(ForcaM2, InicialM2);
    }  
  }
  */
  digitalWrite(ledStatus, HIGH);

  
}

