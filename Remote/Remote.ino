//includes the IRremote library for RC5 and RC6
#include <IRremote.h>
IRsend buttonPressed;

int buttonPressedLED = 4;

//our remote will have 6 buttons
int button1 = 5;
int button2 = 6;
int button3 = 7;
int button4 = 8;
int button5 = 9;
int button6 = 10;

void setup() {
  //sets up the LED on the remote that will blink
  //when a button is pressed
  pinMode(buttonPressedLED, OUTPUT);
  digitalWrite(buttonPressedLED, LOW);

  //sets up our buttons to be inputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);

  //sets the serial to the default rate of communication
  //from the HC-05
  Serial.begin(38400);
}

void loop() {
  //makes sure the LED is off if no buttons are pressed
  if(button1 == LOW && button2 == LOW && button3 == LOW && button4 == LOW && button5 == LOW && button6 == LOW){
    digitalWrite(buttonPressedLED, LOW);
  }

  //the HC-05 sends a message over bluetooth to devices that it is connected to.
  //it does this by writing a message to the serial board, which then gets sent over bluetooth.
  //The following code would trigger different actions on a device that is set up with another HC-05
  //The receiving device would simply check incoming messages using Serial.read(); and then execute
  //an action based on which command was sent.
  //This also lights the LED on the tip of the remote, which is meant to provide feedback to the user to confirm that the input was read.
  if(button1 == HIGH){
    digitalWrite(buttonPressedLED, HIGH);
    Serial.write("execute action 1");

    //if bluetooth is unavailabe, different actions can be performed using the IRremote library
    //this command will send an infrared signal that will turn on or off a TV made by Sony
    buttonPressed.sendSony(0xa90, 12);
  }

  if(button2 == HIGH){
    digitalWrite(buttonPressedLED, HIGH);
    Serial.write("execute action 2");
    
    //sends a 0 using IR for Sony TVs
    buttonPressed.sendSony(0x910, 12);
  }
  
  
  if(button3 == HIGH){
    digitalWrite(buttonPressedLED, HIGH);
    Serial.write("execute action 3");

    //sends a 3 using IR for Sony TVs
    buttonPressed.sendSony(0x410, 12);
  }

  
  if(button4 == HIGH){
    digitalWrite(buttonPressedLED, HIGH);
    Serial.write("execute action 4");

    //sends a 7 using IR for Sony TVs
    buttonPressed.sendSony(0x610, 12);
  }

  
  if(button5 == HIGH){
    digitalWrite(buttonPressedLED, HIGH);
    Serial.write("execute action 5");

    //sends a 9 using IR for Sony TVs
    buttonPressed.sendSony(0x110, 12);
  }

  
  if(button6 == HIGH){
    digitalWrite(buttonPressedLED, HIGH);
    Serial.write("execute action 6");

    //activates the sleep function on a Sony TV
    buttonPressed.sendSony(0x5d0, 12);
  }
}
