int trig = 5;
int echo =6;
float sensor; float tempo; float velocidade; float tempo_seg;
int i;

#include <DHT.h>
float leitura_temperatura;

int pino_dados = A1;

DHT sensor_dht(pino_dados, DHT11);

void setup() {
  // put your setup code here, to run once:
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);
  sensor_dht.begin();
}

void loop() {
  delay(2000);
  Serial.println("começou");
  i = 0;
  while(i<601){
  i++;
  leitura_temperatura = sensor_dht.readTemperature();
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  tempo=pulseIn(echo,HIGH);
  velocidade = 0.4/tempo*1e6;  
  Serial.print(leitura_temperatura);
  Serial.print(";");
  Serial.print(velocidade);
  Serial.println();
  delay(1000);}
  Serial.println("terminou");
  
  
}
