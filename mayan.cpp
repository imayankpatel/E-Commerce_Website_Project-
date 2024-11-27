int val = 1;
int lastVal = 0;
int pos = 0;
void setup() {
pinMode(8, INPUT); //Rotary Encoder pin CLK
pinMode(7, INPUT); //Rotary encoder pin DT
pinMode(13,OUTPUT);
Serial.begin(9600);
}
void loop() {
//read rotary encoder
lastVal = val; //set lastVal to the old value
val = digitalRead(7); //set val to the new value read from the rotary
encoder
if (val == 1 && lastVal == 0) { //if the new value and the old value
are different the knob was turned
if (digitalRead(8) == 1) { //if the CLK channel is HIGH we have turned
the knob clockwise.
pos++; //Increase the "position" variable for the output value
measurement
analogWrite(13,pos);
CW_Click(); //call our function, where our code is executed down below
the loop
}
else { //If the CLK channel is LOW then we turned the knob counterclockwise
pos--; //Decrease pos counter
analogWrite(13,pos);
CCW_Click(); //Execute counter-clockwise click function so our event
can fire.
}
pos_Update(pos); //Regardless of the direction, call the pos_Update
function with the pos value.
//this way we can trigger our events regardless of whether we need a
value or a direction.
}
}
//Custom Functions
void CW_Click() { //Triggered when the control is rotated clockwise
Serial.println("Clockwise Rotation trigger");
}
void CCW_Click() { //Triggered when the control is rotated counter
clockwise
Serial.println("Counter-Clockwise Rotation trigger");
}
void pos_Update(int pos) { //Triggered every time the value changes,
regardless of direction.
Serial.print("Position Update: ");
Serial.println(pos);
}