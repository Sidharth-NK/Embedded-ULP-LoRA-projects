int pinOut = 5;
int pinA = 8; 
int pinB = 9;
void setup()
{
pinMode(pinOut, OUTPUT);
pinMode(pinA, INPUT);
pinMode(pinB, INPUT);


}
void loop()
{
boolean pinAState = digitalRead(pinA);
boolean pinBState = digitalRead(pinB);

boolean pinOutState;

// and
// pinOutState =pinAState & pinBState;

// or
// pinOutState = pinAState | pinBState;

// not
// pinOutState = !pinAState;

// xor
// pinOutState = pinAState ^ pinBState;

// nand
// pinOutState =!(pinAState & pinBState);

// nor
// pinOutState = !(pinAState | pinBState);



digitalWrite(pinOut, pinOutState);
}
