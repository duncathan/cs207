/*
  Morse

  Blinks an LED outputting morse code according to a text variable.
  Reads alphanumeric characters and punctuation according to ITU-R recommendation. Does not support prosigns.
  Written by Dunc Graham, 2018.01.25

  Modified from Examples/Basics/Blink
*/

String text = "Dunc"; //-.. ..- -. -.-.
int textIndex = 0;

#define WAIT 24
#define LED 9
#define BRIGHTNESS 255

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED as an output.
  pinMode(LED, OUTPUT);
  // put the text into a convenient form
  text.toLowerCase();
  if(!text.endsWith(" ")) {
    text += " "; //guarantee a space at the end of the string to be output
  }
}

// the loop function runs over and over again forever
void loop() {
  morse(text.charAt(textIndex++));
  textIndex %= text.length(); //ensure we loop back and don't overflow the length of the string
}

// outputs morse based on the provided char
void morse(char c) {
  switch(c) {
    case 'a':
      dot(); dash();
      break;
    case 'b':
      dash(); dot(); dot(); dot();
      break;
    case 'c':
      dash(); dot(); dash(); dot();
      break;
    case 'd':
      dash(); dot(); dot();
      break;
    case 'e':
      dot();
      break;
    case 'f':
      dot(); dot(); dash(); dot();
      break;
    case 'g':
      dash(); dash(); dot();
      break;
    case 'h':
      dot(); dot(); dot(); dot();
      break;
    case 'i':
      dot(); dot();
      break;
    case 'j':
      dot(); dash(); dash(); dash();
      break;
    case 'k':
      dash(); dot(); dash();
      break;
    case 'l':
      dot(); dash(); dot(); dot();
      break;
    case 'm':
      dash(); dash();
      break;
    case 'n':
      dash(); dot();
      break;
    case 'o':
      dash(); dash(); dash();
      break;
    case 'p':
      dot(); dash(); dash(); dot();
      break;
    case 'q':
      dash(); dash(); dot(); dash();
      break;
    case 'r':
      dot(); dash(); dot();
      break;
    case 's':
      dot(); dot(); dot();
      break;
    case 't':
      dash();
      break;
    case 'u':
      dot(); dot(); dash();
      break;
    case 'v':
      dot(); dot(); dot(); dash();
      break;
    case 'w':
      dot(); dash(); dash();
      break;
    case 'x':
      dash(); dot(); dot(); dash();
      break;
    case 'y':
      dash(); dot(); dash(); dash();
      break;
    case 'z':
      dash(); dash(); dot(); dot();
      break;
    case '0':
      dot(); dot(); dot(); dot(); dot();
      break;
    case '1':
      dot(); dash(); dash(); dash(); dash(); 
      break;
    case '2':
      dot(); dot(); dash(); dash(); dash();
      break;
    case '3':
      dot(); dot(); dot(); dash(); dash();
      break;
    case '4':
      dot(); dot(); dot(); dot(); dash();
      break;
    case '5':
      dot(); dot(); dot(); dot(); dot();
      break;
    case '6':
      dash(); dot(); dot(); dot(); dot();
      break;
    case '7':
      dash(); dash(); dot(); dot(); dot();
      break;
    case '8':
      dash(); dash(); dash(); dot(); dot();
      break;
    case '9':
      dash(); dash(); dash(); dash(); dot();
      break;
    case '.':
      dot(); dash(); dot(); dash(); dot(); dash();
      break;
    case ',':
      dash(); dash(); dash(); dot(); dot(); dot();
      break;
    case '?':
      dot(); dot(); dash(); dash(); dot(); dot();
      break;
    case '\'':
      dot(); dash(); dash(); dash(); dash(); dot();
      break;
    case '-':
      dash(); dot(); dot(); dot(); dot(); dash();
      break;
    case '/':
      dash(); dot(); dot(); dash(); dot();
      break;
    case '(':
      dash(); dot(); dash(); dash(); dot();
      break;
    case ')':
      dash(); dot(); dash(); dash(); dot(); dash();
      break;
    case '&':
      dot(); dash(); dot(); dot(); dot();
      break;
    case ':':
      dash(); dash(); dash(); dot(); dot(); dot();
      break;
    case '=':
      dash(); dot(); dot(); dot(); dash();
      break;
    case '+':
      dot(); dash(); dot(); dash(); dot();
      break;
    case '"':
      dot(); dash(); dot(); dot(); dash(); dot();
      break;
    case '@':
      dot(); dash(); dash(); dot(); dash(); dot();
      break;
    case ' ':
      delay(WAIT*5); //length between words is wait*5
      break;
  }
  delay(WAIT*2); //length between characters
}

// outputs a dot (length of 1 wait)
void dot() {
  analogWrite(LED, BRIGHTNESS);
  delay(WAIT);
  digitalWrite(LED, LOW);
  delay(WAIT);
}

// outputs a dash (length of 3 wait)
void dash() {
  analogWrite(LED, BRIGHTNESS);
  delay(WAIT*3);
  analogWrite(LED, LOW);
  delay(WAIT);
}

