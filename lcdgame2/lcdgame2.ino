#include <Wire.h>
#include <LiquidCrystal_I2C.h>

unsigned long myTimer, myTimer2, myTimer3;

LiquidCrystal_I2C lcd(0x27, 20, 4);

int chx = 2;
int chy = 1;
int csx = 0;
int csy = 1;
int czx = 4;
int czy = 0;

int chxz;
int chyz;

int joyValueX;
int joyValueY;

const int X_pin = 0;
const int Y_pin = 1;

byte normal[] = {0x0E, 0x0E, 0x04, 0x0E, 0x15, 0x15, 0x0A, 0x0A};
byte fall[] = {0x0E, 0x0E, 0x15, 0x15, 0x0E, 0x04, 0x0A, 0x0A};
byte runr[] = {0x0E, 0x0E, 0x05, 0x0F, 0x14, 0x16, 0x0A, 0x08};
byte runl[] = {0x0E, 0x0E, 0x14, 0x1E, 0x05, 0x0D, 0x0A, 0x02};
byte enemy[] = {0x06, 0x0E, 0x04, 0x0E, 0x15, 0x04, 0x0A, 0x0A};
byte defence[] = {0x0E, 0x0E, 0x15, 0x1F, 0x15, 0x05, 0x0A, 0x0A};
byte tower[] = {0x1C, 0x14, 0x1C, 0x17, 0x1C, 0x16, 0x1D, 0x17};
byte base[] = {0x1B, 0x0E, 0x1F, 0x15, 0x0E, 0x15, 0x1B, 0x15};

int ammo = 56;

void setup()
{

  lcd.init();
  lcd.init();
  lcd.backlight();
  pinMode(X_pin, INPUT);
  pinMode(Y_pin, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("********************");
  lcd.setCursor(0, 1);
  lcd.print("*   Arduino game!  *");
  lcd.setCursor(0, 2);
  lcd.print("*  By Max Amperus  *");
  lcd.setCursor(0, 3);
  lcd.print("********************");
  delay(3000);
  lcd.init();
}


void loop()
{

  lcd.createChar(0, normal);
  lcd.createChar(1, fall);
  lcd.createChar(2, runr);
  lcd.createChar(3, runl);
  lcd.createChar(4, enemy);
  lcd.createChar(5, defence);
  lcd.createChar(6, tower);
  lcd.createChar(7, base);

  if (millis() - myTimer > 2000) {
    int rx = random(6, 20);
    int ry = random(4);
    int x = rx;
    int y = ry;
    lcd.setCursor(x, y);
    lcd.print((char)4);
    x = x = 1;
    myTimer = millis();
  }
  if (millis() - myTimer2 > 25 && ammo >= 14) {
    if (czx == chx && czy == chy) {
      if (digitalRead(2) == LOW || digitalRead(3) == HIGH) {
        int b = 6;
        do {
          int y = 0;
          b++;
          ammo = ammo - 1;
          lcd.setCursor(b, y);
          lcd.print("-");
          lcd.setCursor(b + 1, y);
          lcd.print("-");
          lcd.setCursor(b + 2, y);
          lcd.print("-");
          lcd.setCursor(b - 1, y);
          lcd.print(" ");

        }
        while (b < 20);
      }
    }
    if (czx == chx && czy + 1 == chy) {
      if (digitalRead(2) == LOW || digitalRead(3) == HIGH) {
        int b = 6;
        do {
          int y = 1;
          b++;
          ammo = ammo - 1;
          lcd.setCursor(b, y);
          lcd.print("-");
          lcd.setCursor(b + 1, y);
          lcd.print("-");
          lcd.setCursor(b + 2, y);
          lcd.print("-");
          lcd.setCursor(b - 1, y);
          lcd.print(" ");

        }
        while (b < 20);
      }
    }
    if (czx == chx && czy + 2 == chy) {
      if (digitalRead(2) == LOW || digitalRead(3) == HIGH) {
        int b = 6;
        do {
          int y = 2;
          b++;
          ammo = ammo - 1;
          lcd.setCursor(b, y);
          lcd.print("-");
          lcd.setCursor(b + 1, y);
          lcd.print("-");
          lcd.setCursor(b + 2, y);
          lcd.print("-");
          lcd.setCursor(b - 1, y);
          lcd.print(" ");

        }
        while (b < 20);
      }
    }
    if (czx == chx && czy + 3 == chy) {
      if (digitalRead(2) == LOW || digitalRead(3) == HIGH) {
        int b = 6;
        do {
          int y = 3;
          b++;
          ammo = ammo - 1;
          lcd.setCursor(b, y);
          lcd.print("-");
          lcd.setCursor(b + 1, y);
          lcd.print("-");
          lcd.setCursor(b + 2, y);
          lcd.print("-");
          lcd.setCursor(b - 1, y);
          lcd.print(" ");

        }
        while (b < 20);
      }
    }
    myTimer2 = millis();
  }

  if (digitalRead(5) == LOW && ammo <= 0 ||digitalRead(4) == HIGH&&ammo < 14) {
    lcd.setCursor(chx, chy);
    lcd.print((char)5);
    lcd.setCursor(chx, chy);
    lcd.print((char)5);
    lcd.setCursor(chx, chy);
    lcd.print((char)5);
    lcd.setCursor(chx, chy);
    lcd.print((char)5);
  }
  if (millis() - myTimer > 1000) {
    if (csx == chx && csy == chy) {
      ammo = ammo + 10;
    }
    if (csx == chx && csy + 1 == chy) {
      ammo = ammo + 10;
    }
    myTimer2 = millis();
  }


  int joyValueX = analogRead(X_pin);
  int joyValueY = analogRead(Y_pin);
  lcd.setCursor(0, 0);
  if (ammo <= 14) {
    lcd.setCursor(0, 0);
    lcd.print("*");
  }
  lcd.print(ammo);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print((char)7);
  lcd.setCursor(0, 2);
  lcd.print((char)7);
  lcd.print(" ");
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print("Ю");
  lcd.print(" ");
  lcd.print(" ");
  lcd.print(" ");
  lcd.setCursor(5, 0);
  lcd.print((char)6);
  lcd.setCursor(5, 1);
  lcd.print((char)6);
  lcd.setCursor(5, 2);
  lcd.print((char)6);
  lcd.setCursor(5, 3);
  lcd.print((char)6);

  if (joyValueX > 420 && joyValueX < 920 && joyValueY > 120 && joyValueY < 920) {
    lcd.setCursor(chx, chy);
    lcd.print((char)0);
  }
  if (chx < 0) {
    chx++;
    lcd.setCursor(1, chy);
  }
  if (chx > 19) {
    chx--;
    lcd.setCursor(19, chy);
  }
  if (chy < 0) {
    chy++;
    lcd.setCursor(chx, 0);
  }
  if (chy > 3) {
    chy--;
    lcd.setCursor(chx, 3);
  }

  if (joyValueX >= 940) {
    chx++;
    chxz = chx - 1;
    lcd.setCursor(chx, chy);
    lcd.print((char)2);
    lcd.setCursor(chxz, chy);
    lcd.print(" ");
  }
  if (joyValueX <= 400) {
    chx--;
    chxz = chx + 1;
    lcd.setCursor(chx, chy);
    lcd.print((char)3);
    lcd.setCursor(chxz, chy);
    lcd.print(" ");
  }
  if (joyValueY <= 100) {
    chy--;
    chyz = chy + 1;
    lcd.setCursor(chx, chy);
    lcd.print((char)3);
    lcd.setCursor(chx, chyz);
    lcd.print(" ");
  }
  if (joyValueY >= 940) {
    chy++;
    chyz = chy - 1;
    lcd.setCursor(chx, chy);
    lcd.print((char)1);
    lcd.setCursor(chx, chyz);
    lcd.print(" ");
  }
}
