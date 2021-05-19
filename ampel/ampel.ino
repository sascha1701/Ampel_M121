int Taster=1;
int tasterstatus=0;
int NORD=0;
int SUED=3;
int OST=10;
int WEST=13;
int Motor=12;
int Summer=11;
int FussgaengerAmpel=7;

void setup() //Wir starten mit dem Setup
{
pinMode(Taster, INPUT); // Pin 1 ist ein Eingang.
pinMode(NORD, OUTPUT); // Pin 0 ist ein Ausgang.
pinMode(SUED, OUTPUT); // Pin 3 ist ein Ausgang.
pinMode(OST,OUTPUT); // Pin 10 ist ein Ausgang.
pinMode(WEST,OUTPUT); // Pin 13 ist ein Ausgang.
pinMode(Motor,OUTPUT); // Pin 12 ist ein Ausgang.
pinMode(Summer,OUTPUT); // Pin 11 ist ein Ausgang.
pinMode(FussgaengerAmpel,OUTPUT); // Pin 7 ist ein Ausgang.
}


void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}


void loop() // Das Hauptprogramm beginnt.
{
digitalWrite(GRUN, HIGH); // Schalte die grüne Ampel an Pin7 an. Die Autos sehen also das grüne Signal
digitalWrite(RotFuss, HIGH); // Schalte die rote Fußgängerampel an Pin8 an. Die Autos sehen also das grüne Signal
tasterstatus=digitalRead(Taster);  //Hier wird der Pin4 ausgelesen (Befehl:digitalRead). Das Ergebnis wird unter der Variable „tasterstatus“ mit dem Wert „HIGH“ für 5Volt oder „LOW“ für 0Volt gespeichert.
if (tasterstatus == HIGH) //Verarbeitung: Wenn der Taster gedrückt ist (Das Spannungssignal ist hoch)verarbeitet der Sketch die folgende Schleife
 { //Programmabschnitt der IF-Schleife öffnen.
 delay(2000); // Warte 2000 Millisekunden(2 Sekunden), da es bei einer echten Ampel aus Sicherheitsgründen auch immer eine Weile dauert, bis die Ampel umspringt.
 digitalWrite(GRUN, LOW); // Schalte die grüne LED an Pin7 aus.
 digitalWrite(GELB, HIGH); // Schalte die gelbe LED an Pin6 an.
 delay(1000); // Warte 1000 Millisekunden.
 digitalWrite(GELB, LOW); // Schalte die gelbe LED an Pin6 aus. 
 digitalWrite(ROT, HIGH); // Schalte die rote LED an Pin5 an.
 delay(2000); // Warte 2000 Millisekunden(2 Sekunden), da es bei einer echten Ampel aus Sicherheitsgründen auch immer eine Weile dauert, bis die Ampel umspringt. Die Autofahrer haben jetzt "rot".
 digitalWrite(RotFuss, LOW); // Schalte die rote Fußgängerampel an Pin8 aus.
 digitalWrite(GrunFuss, HIGH); // Schalte die grüne Fußgängerampel an Pin9 an. Die Radfahrer und Fußgänger gehen los.
 delay(5000); // Warte weitere 5000 Millisekunden.
 digitalWrite(RotFuss, HIGH); // Schalte die rote Fußgängerampel an Pin8 ein.
 digitalWrite(GrunFuss, LOW); // Schalte die grüne Fußgängerampel an Pin9 aus. Die Radfahrer und Fußgänger müssen stehen bleiben
 delay(2000); // Warte 2000 Millisekunden(2 Sekunden). Die Autofahrer haben immernoch "rot" und die Fußgänger müssen die Straße räumen.
 digitalWrite(GELB, HIGH); // Schalte zusätzlich für die Autofahrer die gelbe LED an Pin6 an.
 delay(1000); // Warte 1000 Millisekunden.
 digitalWrite(ROT, LOW); // Schalte die rote LED an Pin5 aus.
 digitalWrite(GELB, LOW); // Schalte zusätzlich die gelbe LED an Pin6 aus.
 } //Programmabschnitt des IF-Befehls schließen.
}
// Hier am Ende springt das Programm an den Start des Loop-Teils. Da dort die grüne LED direkt aktiviert wird, muss dies nicht zusätzlich am Ende der Schleife gemacht werden.
