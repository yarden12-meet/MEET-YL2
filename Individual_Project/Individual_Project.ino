void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  int buttonPin = 2;
  
  int binNum [4]; // this array will store the binary number
  int buttonInput = 0; // will store the button state
  
  
  
Serial.println("Press the button when you are ready!");
while (buttonInput!=1) // this loop wil run until the user will push the button
{
  buttonInput = digitalRead(buttonPin);
}

  Serial.println("started");
  // Serial.println(pow(2,3));
  
  for(int i = 0; i<4; i++) // the proccess of recieving input will repeat 4 times
  {
    delay(2000);
    
   
    
    
    
    
    Serial.print("Your input --->");
    
    for(long j = 0; j<200000; j++) // this loop is intended to give the user enough time to push the button
    {
        buttonInput = digitalRead(buttonPin); // reads the state of the button
    
        if (buttonInput == 1) // if the button is pushed the loop breaks
        {
          break;
        }
    }
    
    // now buttonInput is 1 if the button was pushed, and 0 otherwise
    
    if (buttonInput==1)
    {
     Serial.println("pushed");
     binNum[i] = 1;
    }
    else
    {
      Serial.println("not pushed");
      binNum[i] = 0;
    }
    
    
    
  }
  
  Serial.print("Your input number is: ");
  for(int i = 0; i<4; i++)
  { 
    Serial.print(binNum[i]);
  }
  Serial.println();
  
//  int dec = 0; // the decimal number
//  for(int i = 0; i<4; i++)
//  { 
//    dec+=binNum[i]*pow(2,(3-i));
//  }
//  
//  Serial.print(dec);

}


void loop() 
{

}


