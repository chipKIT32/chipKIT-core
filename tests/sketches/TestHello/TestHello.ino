int loop_count = 0;
int speed = 100;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  //loop_count = loop_count + 1;
  loop_count++;
  
  //100 times at each speed
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(speed);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(speed);              // wait for a second
  
  Serial.print("loop_count: ");
  Serial.print(loop_count);
  Serial.print(" speed: ");
  Serial.println(speed);

}
