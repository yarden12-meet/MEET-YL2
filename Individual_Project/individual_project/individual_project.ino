void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  int buttonPin = 2;
  
  int binNum [4]; // this array will store the digits of the binary number
  int buttonInput = 0; // will store the button state


  Serial.println("Press the button when you are ready!");
  while (buttonInput!=1) // this loop wil run until the user will push the button
  {
    buttonInput = digitalRead(buttonPin);
  }
  Serial.println("started");
  
  
  //
  // Now the program starts
  //
  
  
  for(int i = 0; i<4; i++) // the proccess of recieving input will repeat 4 times
  {
    delay(2000); // waits 2 seconds before each time the user is asked for input
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
    
    if (buttonInput==1) // if the button was pushed
    {
     Serial.println("pushed");
     binNum[i] = 1;
    }
    else // if the button was not pushed
    {
      Serial.println("not pushed");
      binNum[i] = 0;
    }  
  }
  
  
  Serial.print("Your input number is: ");
  for(int i = 0; i<4; i++) // this loop prints the binary number
  { 
    Serial.print(binNum[i]);
  }
  Serial.println();
  
  double dec = 0; // the decimal number
  for(int i = 0; i<4; i++) // this loop converts the binary number into a decimal number
  {
    dec+=binNum[i]*pow(2,(3-i));
  }
  Serial.println(dec);

}


void loop() 
{

}


