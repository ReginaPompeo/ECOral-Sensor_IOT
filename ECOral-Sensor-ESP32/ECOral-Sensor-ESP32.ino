#include <WiFi.h>
#include <ThingerESP32.h>
#include <DHT.h>

#define DHTPIN 17
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Insira as credenciais do dispositivo configurado na plataforma
#define USERNAME "ReginaPompeo"
#define DEVICE_ID "ECOral"
#define DEVICE_CREDENTIAL "ECOral12345"

// Insira as credenciais da sua rede WiFi
#define SSID "ReginaP"
#define SSID_PASSWORD "Gina0509"

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

float temp, ph, condutividade, turbidez, h2o, nivel, numeroRandom;

void setup() {
  Serial.begin(115200);
  dht.begin();
  thing.add_wifi(SSID, SSID_PASSWORD);
  randomSeed(analogRead(0)); // Inicializa o gerador de números aleatórios com um valor aleatório
}

void loop() {
  temp = random(-5000, 5001) / 50.0; // Valor aleatório para temperatura entre -50.00 e 50.00
  ph = random(0, 1401) / 14.0; // Valor aleatório para pH entre 0.00 e 14.00
  condutividade = random(30000, 70001) / 1000.0; // Valor aleatório para condutividade entre 30,000 e 70,000
  turbidez = random(0, 601) / 60.0; // Valor aleatório para turbidez entre 0.0 e 60.0
  h2o = random(0, 101) / 10.0; // Valor aleatório para H2O entre 0.0 e 10.0
  nivel = random(0, 101); // Valor aleatório para nível entre 0 e 100
  numeroRandom = random(0, 101); // Valor aleatório para numeroRandom entre 0 e 100

  thing["Grupo"] >> outputValue("ECOral - Sensor de poluição da água");

  // Textos explicativos sobre fatores de poluição na água
  thing["Text Temperatura"] >> outputValue("A temperatura da água é crucial para a vida marinha...");
  thing["Text PH"] >> outputValue("O pH da água é uma medida que indica a acidez ou alcalinidade da mesma...");
  thing["Text Condutividade Elétrica"] >> outputValue("A condutividade elétrica da água é a capacidade dela de conduzir eletricidade...");
  thing["Text Turbidez"] >> outputValue("Turbidez refere-se à medida da quantidade de partículas suspensas na água...");
  thing["Text H2O"] >> outputValue("O oxigênio dissolvido na água é essencial para a sobrevivência da vida aquática...");
  thing["Text Nível da Água"] >> outputValue("Monitorar o nível da água é crucial para manter sua qualidade...");

  // Dados de exemplo das variáveis
  thing["Dados exemplares 1 - Temperatura"] >> outputValue("Água não poluída: Geralmente entre 10°C e 25°C");
  thing["Dados exemplares 2 - Temperatura"] >> outputValue("Água poluída: Aproximadamente 30°C");
  thing["Dados exemplares 1 - PH"] >> outputValue("Água não poluída: Geralmente 8.0 a 8.5 pH");
  thing["Dados exemplares 2 - PH"] >> outputValue("Água poluída: Geralmente 7.0 a 8.0 pH");
  thing["Dados exemplares 1 - Condutividade elétrica"] >> outputValue("Água não poluída: Aproximadamente entre 50 µS/cm a 55 µS/cm.");
  thing["Dados exemplares 2 - Condutividade elétrica"] >> outputValue(" Água poluída: Aproximadamente >55 µS/cm.");
  thing["Dados exemplares 1 - Turbidez"] >> outputValue("Água não poluída: Aproximadamente < 20 NTU");
  thing["Dados exemplares 2 - Turbidez"] >> outputValue(" Água poluída: Geralmente entre 20 a 100 NTU");
  thing["Dados exemplares 1 - H2O"] >> outputValue("Água não poluída: Aproximadamente > 6 mg/L");
  thing["Dados exemplares 2 - H2O"] >> outputValue(" Água poluída: Aproximadamente < 2 mg/L");

  // Valores Determinados
  thing["Temperatura"] >> outputValue(temp);
  thing["PH"] >> outputValue(ph);
  thing["Condutividade elétrica"] >> outputValue(condutividade);
  thing["Turbidez"] >> outputValue(turbidez);
  thing["H2O"] >> outputValue(h2o);
  thing["Nível da água"] >> outputValue(nivel);
  thing["Randomico"] >> outputValue(numeroRandom);

  Serial.print("Temperatura: ");
  Serial.println(temp);
  Serial.print("PH: ");
  Serial.println(ph);
  Serial.print("Condutividade elétrica: ");
  Serial.println(condutividade);
  Serial.print("Turbidez: ");
  Serial.println(turbidez);
  Serial.print("H2O: ");
  Serial.println(h2o);
  Serial.print("Nível da água: ");
  Serial.println(nivel);
  Serial.print("Random: ");
  Serial.println(numeroRandom);

  thing.handle();
  delay(150);
}
