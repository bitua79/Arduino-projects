#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int button_pin = 13, led1_pin = 6, led2_pin = 7, led3_pin = 9;
int dinoPos, treePos, birdPos, gameSpeed, health = 3, temp, score = 0;
unsigned long startTime;
unsigned long currentTime, elapsedTime;

byte dino[] = {
  B00000,
  B00111,
  B00111,
  B00111,
  B10100,
  B11111,
  B01010,
  B01010
};

byte tree[] = {
  B00100,
  B10100,
  B10101,
  B10101,
  B10101,
  B10111,
  B11100,
  B00100
};

byte bird[] = {
  B00000,
  B00001,
  B11010,
  B01111,
  B00000,
  B00000,
  B00000,
  B00000
};

void start()
{
  dinoPos = 1; treePos = random(16, 25);
  temp = treePos;
  while(temp - treePos <= 2 && treePos - temp <= 2) temp = random(16, 25);
  birdPos = temp;
  gameSpeed = 200;
}

void setup() 
{
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  lcd.begin(16,2);
  lcd.createChar(1, dino);
  lcd.createChar(2, tree);
  lcd.createChar(3, bird);
  randomSeed(analogRead(0));
  start();
  startTime = millis();
}

void led()
{
  if(health == 3)
  {
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, HIGH);
    digitalWrite(led3_pin, HIGH);
  }
  else if(health == 2)
  {
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, HIGH);
    digitalWrite(led3_pin, LOW);
  }
  else if(health == 1)
  {
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, LOW);  
  }
  else
  {
    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);
    digitalWrite(led3_pin, LOW);  
  }
}

void loop()
{
  currentTime = millis();
  elapsedTime = (currentTime - startTime) / 1000;
  score = int(elapsedTime / 5);

  // if dino hits bird
  if(dinoPos == 0 && birdPos == 0)
  {
    health--;
    if(health > 0)
    {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("oops a Bird!");
      lcd.setCursor(3, 1);
      lcd.print("Health : ");
      lcd.print(health);  
      led();    
      delay(5000);
      start();
    }
    else // health is zero
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("game Over!");
      lcd.setCursor(0, 1);
      lcd.print("Final Score : ");
      lcd.print(score);
      led();
      delay(5000);
      // restart the game
      start(); health = 3; score = 0; startTime = millis();
    }
  }
  // if dino hits tree
  else if(dinoPos == 1 && treePos == 0)
  {
    health--;
    if(health > 0)
    {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("oops a Tree!");
      lcd.setCursor(3, 1);
      lcd.print("Health : ");
      lcd.print(health);   
      led();   
      delay(5000);
      start();
    }
    else // health is zero
    {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("game Over!");
      lcd.setCursor(0, 1);
      lcd.print("Final Score : ");
      lcd.print(score);
      led();
      delay(5000);
      // restart the game
      start(); health = 3; score = 0; startTime = millis();
    }
  }
  lcd.clear();

  // write score
  lcd.setCursor(14, 0);
  lcd.print(score);

  // write dino
  if(digitalRead(button_pin) == HIGH) dinoPos = 0; else dinoPos = 1;
  lcd.setCursor(0, dinoPos); lcd.write(1);

  // write tree
  lcd.setCursor(treePos, 1);
  if(treePos < 16) lcd.write(2);
  treePos--;
  if(treePos < 0) 
  {
    temp = birdPos;
    while(temp - birdPos <= 2 && birdPos - temp <= 2) temp = random(16, 25);
    treePos = temp;
  }

  // write bird
  lcd.setCursor(birdPos, 0);
  if(birdPos < 14) lcd.write(3);
  birdPos--;
  if(birdPos < 0)
  {
    temp = treePos;
    while(temp - treePos <= 2 && treePos - temp <= 2) temp = random(16, 25);
    birdPos = temp;
  }

  // controll the speed of game
  delay(gameSpeed);
  gameSpeed = (1000 / (elapsedTime + 10)) + 60;
}
