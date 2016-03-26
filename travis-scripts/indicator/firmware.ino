#define RED_PIN D0
#define GREEN_PIN D1
#define BLUE_PIN D2

void setup() {
  // Configure pins and set defaults
  pinMode(RED_PIN,   OUTPUT);  digitalWrite(RED_PIN,   LOW);
  pinMode(GREEN_PIN, OUTPUT);  digitalWrite(GREEN_PIN, LOW);
  pinMode(BLUE_PIN,  OUTPUT);  digitalWrite(BLUE_PIN,  LOW);

  Spark.function("setcolor", setColor);
}

void loop() { }

void setLeds(int r, int g, int b) {
    analogWrite(RED_PIN,   constrain(r, 0, 255));
    analogWrite(GREEN_PIN, constrain(g, 0, 255));
    analogWrite(BLUE_PIN,  constrain(b, 0, 255));
}

int setColor(String color) {
    if (color.equalsIgnoreCase("off")) {
      setLeds(0, 0, 0);
    } else if (color.equalsIgnoreCase("green")) {
      setLeds(0, 255, 0);
    } else if (color.equalsIgnoreCase("yellow")) {
      setLeds(255, 255, 0);
    } else if (color.equalsIgnoreCase("red")) {
      setLeds(255, 0, 0);
    } else {
      return -1;  //  Unknown color
    }

    return 0;     // Success
}
