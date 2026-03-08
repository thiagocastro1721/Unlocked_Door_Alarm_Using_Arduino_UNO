int chavePin = 7; // Atribui o pino 7 a variável chavePin
int buzzerPin = 10; //Atribui o pino 10 a variável buzzerPin
int estadochave = 0;//Variável responsável por armazenar o estado da chave (ligado/deligado)


void setup()
{
  pinMode(buzzerPin , OUTPUT); // buzzerPin (pino 8) definido como saída
  pinMode (chavePin , INPUT); // chavePin (pino 10) definido como entrada
}

void loop()
{
  estadochave = digitalRead (chavePin); //Armazena o valor digital de chavePin em estadochave
  if ( estadochave == HIGH ) { //Se estadochave for igual a nível alto (HIGH)
    digitalWrite(buzzerPin , HIGH); //Define buzzerPin como HIGH, ligando o buzzer
    delay(100);//Período em que o buzzer fica ligado
     }
  else { //Senão (se estadochave for igual a nível baixo)
    digitalWrite (buzzerPin , LOW ); //Define buzzerPin como LOW, mantendo o buzzer desligado
  	delay(100);//Período em que o buzzer fica desligado
  }

}