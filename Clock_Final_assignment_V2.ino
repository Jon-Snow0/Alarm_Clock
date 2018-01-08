int clock1[] = {2, 3, 4, 5, 6, 7, 8};
//int clock2[] = {22, 23, 24, 25, 26, 27, 28};
//int clock3[] = {30, 31, 32, 33, 34, 35, 36};
//int clock4[] = {38, 39, 40, 41, 42, 43, 44};
//int clock5[] = {46, 47, 48, 49, 50, 51, 52};
//int clock6[] = {A0, A1, A2, A3, A4, A5, A6};//DELETE

int clocks[6][7] = {{2, 3, 4, 5, 6, 7, 8}, {22, 23, 24, 25, 26, 27, 28}, {30, 31, 32, 33, 34, 35, 36}, {38, 39, 40, 41, 42, 43, 44}, {46, 47, 48, 49, 50, 51, 52}, {A0, A1, A2, A3, A4, A5, A6}};

int currentTime[6];

int second01 = 0;
int second10 = 0;
int minute01 = 0;
int minute10 = 0;
int hour01 = 0;
int hour10 = 0;

int alarmTime0001 = 0;
int alarmTime0010 = 0;
int alarmTime0100 = 0;
int alarmTime1000 = 0;

int alarmButton = 9;
int minuteButton = 10;
int hourButton = 11;

int buzzerPin = 12;

int snooze;
int minuteCounter;
int hourCounter;

boolean minutePlus = false;
boolean hourPlus = false;

boolean alarmSet = false;
boolean alarmOn = false;
boolean clockOn = false;
boolean buzzerTrigger = false;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(clock1[i], OUTPUT);
    pinMode(clock2[i], OUTPUT);
    pinMode(clock3[i], OUTPUT);
    pinMode(clock4[i], OUTPUT);
    pinMode(clock5[i], OUTPUT);
    pinMode(clock6[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);

  pinMode(alarmButton, INPUT);
  pinMode(minuteButton, INPUT);
  pinMode(hourButton, INPUT);
  Serial.begin(9600);
}
void alarm() {
  if (snooze == 1 && alarmOn == false) {
    alarmSet = true;
    alarmOn = true;
  }
  if (alarmTime0001 == minute01 && alarmTime0010 == minute10 && alarmTime0100 == hour01 && alarmTime1000 == hour10 && alarmOn == true) {
    buzzerTrigger = true;
  }
  if (buzzerTrigger == true) {
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    delay(1000);
    if (snooze == 1) {
      buzzerTrigger = false;
      alarmOn = false;
    }
  }
}
void timeTrack() {
  if (second01 == 10) {
    second01 = -1;
    second10++;
  }
  if (second10 == 6) {
    second10 = 0;
    minute01++;
  }
  if (minute01 == 10) {
    minute01 = 0;
    minute10++;
  }
  if (minute10 == 6) {
    minute10 = 0;
    hour01++;
  }
  if (hour01 == 10) {
    hour01 = 0;
    hour10++;
  }
  if (hour10 == 2 && hour01 == 5) {
    hour01 = 1;
    hour10 = 0;
  }
  if (clockOn == true) {
    second01++;
    delay(1000);
  }
}
void displays() {
  for (int i = 0; i < 6; i++) {
    if (currentTime[i] == 0) {
      zero(clocks[i]);
    } else if (currentTime[i] == 1) {
      one(clocks[i]);
    } else if (currentTime[i] == 2) {
      two(clocks[i]);
    } else if (currentTime[i] == 3) {
      three(clocks[i]);
    } else if (currentTime[i] == 4) {
      four(clocks[i]);
    } else if (currentTime[i] == 5) {
      five(clocks[i]);
    } else if (currentTime[i] == 6) {
      six(clocks[i]);
    } else if (currentTime[i] == 7) {
      seven(clocks[i]);
    } else if (currentTime[i] == 8) {
      eight(clocks[i]);
    } else if (currentTime[i] == 9) {
      nine(clocks[i]);
    }
  }
}
void buttonInputs() {
  if (digitalRead(minuteButton) == HIGH) {
    minute01++;
    delay(500);
  }
  if (digitalRead(hourButton) == HIGH) {
    hour01++;
    delay(500);
  }
  void zero(int i []) {
    digitalWrite(i[2], HIGH);
    digitalWrite(i[3], HIGH);
    digitalWrite(i[6], HIGH);
    digitalWrite(i[5], HIGH);
    digitalWrite(i[4], HIGH);
    digitalWrite(i[1], HIGH);
    digitalWrite(i[0], LOW);
  }
  void one(int i []) {
    digitalWrite(i[2], LOW);
    digitalWrite(i[3], HIGH);
    digitalWrite(i[6], HIGH);
    digitalWrite(i[5], LOW);
    digitalWrite(i[4], LOW);
    digitalWrite(i[1], LOW);
    digitalWrite(i[0], LOW);
  }
  void two(int i []) {
    digitalWrite(i[2], HIGH);
    digitalWrite(i[3], HIGH);
    digitalWrite(i[6], LOW);
    digitalWrite(i[5], HIGH);
    digitalWrite(i[4], HIGH);
    digitalWrite(i[1], LOW);
    digitalWrite(i[0], HIGH);
  }
  void three(int i []) {
    digitalWrite(i[2], HIGH);
    digitalWrite(i[3], HIGH);
    digitalWrite(i[6], HIGH);
    digitalWrite(i[5], HIGH);
    digitalWrite(i[4], LOW);
    digitalWrite(i[1], LOW);
    digitalWrite(i[0], HIGH);
  }
  void four(int i []) {
    digitalWrite(i[2], LOW);
    digitalWrite(i[3], HIGH);
    digitalWrite(i[6], HIGH);
    digitalWrite(i[5], LOW);
    digitalWrite(i[4], LOW);
    digitalWrite(i[1], HIGH);
    digitalWrite(i[0], HIGH);
  }
  void five(int i []) {
    digitalWrite(i[2], HIGH);
    digitalWrite(i[3], LOW);
    digitalWrite(i[6], HIGH);
    digitalWrite(i[5], HIGH);
    digitalWrite(i[4], LOW);
    digitalWrite(i[1], HIGH);
    digitalWrite(i[0], HIGH);
  }
  void six(int i []) {
    digitalWrite(i[2], HIGH);
    digitalWrite(i[3], LOW);
    digitalWrite(i[6], HIGH);
    digitalWrite(i[5], HIGH);
    digitalWrite(i[4], HIGH);
    digitalWrite(i[1], HIGH);
    digitalWrite(i[0], HIGH);
  }
  void seven(int i []) {
    digitalWrite(i[2], HIGH);
    digitalWrite(i[3], HIGH);
    digitalWrite(i[6], HIGH);
    digitalWrite(i[5], LOW);
    digitalWrite(i[4], LOW);
    digitalWrite(i[1], LOW);
    digitalWrite(i[0], LOW);
  }
  void eight(int i []) {
    digitalWrite(i[2], HIGH);
    digitalWrite(i[3], HIGH);
    digitalWrite(i[6], HIGH);
    digitalWrite(i[5], HIGH);
    digitalWrite(i[4], HIGH);
    digitalWrite(i[1], HIGH);
    digitalWrite(i[0], HIGH);
  }
  void nine(int i []) {
    digitalWrite(i[2], HIGH);
    digitalWrite(i[3], HIGH);
    digitalWrite(i[6], HIGH);
    digitalWrite(i[5], HIGH);
    digitalWrite(i[4], LOW);
    digitalWrite(i[1], HIGH);
    digitalWrite(i[0], HIGH);
  }
  void clearSeg(int i []) {
    digitalWrite(i[2], LOW);
    digitalWrite(i[3], LOW);
    digitalWrite(i[6], LOW);
    digitalWrite(i[5], LOW);
    digitalWrite(i[4], LOW);
    digitalWrite(i[1], LOW);
    digitalWrite(i[0], LOW);
  }
  void loop() {
    snooze = digitalRead(alarmButton);
    delay(1000);

    alarm();
    timeTrack();
    displays();
    buttonInputs();

    if (alarmSet == false) {
      currentTime[0] = hour10;
      currentTime[1] = hour01;
      currentTime[2] = minute10;
      currentTime[3] = minute01;
      currentTime[4] = second10;
      currentTime[5] = second01;
    } else if (alarmSet == true) {
      currentTime[0] = alarmTime1000;
      currentTime[1] = alarmTime0100;
      currentTime[2] = alarmTime0010;
      currentTime[3] = alarmTime0001;
      currentTime[4] = 0;
      currentTime[5] = 0;
    }
  }

