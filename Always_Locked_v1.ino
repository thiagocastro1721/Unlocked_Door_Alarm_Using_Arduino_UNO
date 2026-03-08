int chavePin  = 7;
int buzzerPin = 10;

#define NOTE_B4  494
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_FS5 740
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_B5  988

int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4,  NOTE_B4,
  NOTE_E5,  NOTE_E5,  NOTE_E5, NOTE_GS5, NOTE_GS5,
  NOTE_A5,  NOTE_B5,  NOTE_A5, NOTE_A5,  NOTE_A5,
  NOTE_E5,  NOTE_D5,  NOTE_FS5,NOTE_FS5, NOTE_FS5,
  NOTE_E5,  NOTE_E5,  NOTE_FS5,NOTE_E5
};

int durations[] = {
  8, 8, 8, 4, 4,
  4, 4, 5, 8, 8,
  8, 8, 8, 8, 8,
  4, 4, 4, 4, 5,
  8, 8, 8, 8
};

int songLength = sizeof(melody) / sizeof(melody[0]);
unsigned long tempoPress = 0;
bool aguardando = false;

void tocarMusica();

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(chavePin, INPUT_PULLUP);
}

void loop() {
  bool botao = (digitalRead(chavePin) == HIGH);

  if (botao && !aguardando) {
    tempoPress = millis();
    aguardando = true;
  }

  if (!botao) {
    aguardando = false;
    noTone(buzzerPin);
    return;
  }

  if (millis() - tempoPress < 20000UL) {
    return;
  }

  tocarMusica();
}

void tocarMusica() {
  for (int i = 0; i < songLength; i++) {
    if (digitalRead(chavePin) != HIGH) {
      noTone(buzzerPin);
      aguardando = false;
      return;
    }
    int duracaoMs = 1000 / durations[i];
    tone(buzzerPin, melody[i], duracaoMs);
    delay(duracaoMs);
    noTone(buzzerPin);
    delay((int)(duracaoMs * 0.3));
  }
}