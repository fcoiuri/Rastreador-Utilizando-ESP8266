//Início das bibliotecas utilizadas pelo WiFi Location
#ifdef ARDUINO_ARCH_SAMD
#include <WiFi101.h>
#elif defined ARDUINO_ARCH_ESP8266
#include <ESP8266WiFi.h>
#elif defined ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#error Wrong platform
#endif
#include <WifiLocation.h>
//Fim das bibliotecas utilizadas pelo WiFi Location
#include <time.h> //Biblioteca para a atualização do horário
#include <FirebaseArduino.h> //Biblioteca para a escrita de dados no BD

const char* googleApiKey = "INSERIR CHAVE AQUI"; //inserir API do Google Maps
const char* ssid = "NOME DA REDE"; //Nome da Rede WiFi
const char* passwd = "SENHA DA REDE";  //Senha da Rede WiFi

#define FIREBASE_HOST "HOST DO FIREBASE" //Host do Firebase
#define FIREBASE_AUTH "SENHA DO FIREBASE" //Key do Firebase

WifiLocation location(googleApiKey); //Chave inserida ao construtor da classe WiFiLocation

int timezone = -3 * -3600; //fuso horário da localidade
int dst = 0; //Horário de Verão

void setup() {
  Serial.begin(115200); //Configurando a taxa de comunicação para 115200 bps
#ifdef ARDUINO_ARCH_ESP8266 //Configura para usar esp8266
  WiFi.mode(WIFI_STA);
#endif
  WiFi.begin(ssid, passwd); //Inicia a configuração na rede WiFi
  while (WiFi.status() != WL_CONNECTED) { //Enquanto a conexão não tiver sucesso
    Serial.print("Conectando a rede WiFi: ");
    Serial.println(ssid);
    Serial.print("Status = ");
    Serial.println(WiFi.status());
    delay(500); //Aguarda 0,5 segundos e tenta novamente
  }
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov"); //Função para configurar o tempo
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); ////Inicia o Firebase
}

void enviarFirebase(float longi, float lati, String tempo) { //Passado como parâmetro a longitude, latitude e tempo
  if (longi == 0 && lati == 0) { //Caso receba longitude e latitude zerados não é enviado para o Firebase
    Serial.println("Não computado");
  }
  else { //Caso receba valores verdadeiros, são enviados para o Firebase
    Firebase.setFloat("Usuario1/longitude", +longi); //Armazenada a longitude no servidor
    Firebase.setFloat("Usuario1/latitude", +lati); //Armazenada a latitude no servidor
    Firebase.setString("Usuario1/ultima_atualizacao", String(tempo)); //Armazenada o tempo no servidor
    if (Firebase.failed()) { //Caso haja algum erro na conexão com o Firebase esta função é ativada
      Serial.print("Falhou");
      Serial.println(Firebase.error());
      return;
    }
    delay(1000); //Atraso de 1 segundo a cada envio de dados
  }
}

int cont = 5; //Contador definido para reiniciar a placa
void loop() {
  location_t loc = location.getGeoFromWiFi(); //Chamada da função WiFiLocation
  time_t now = time(nullptr); //Criação de váriavel para armazenar horário
  struct tm* p_tm = localtime(&now); //Criação de struct para armazenar horário
  int mes = p_tm->tm_mon + 1; //Define a váriavel mês para receber +1
  int ano = p_tm->tm_year + 1900; //Define a váriavel ano para receber +1900
  Serial.println("Solicitando Localização");
  Serial.println(location.getSurroundingWiFiJson()); //JSON com localização retornado
  Serial.println("Latitude: " + String(loc.lat, 7)); //Exibe informação da latitude no Monitor Serial
  Serial.println("Longitude: " + String(loc.lon, 7)); //Exibe informação da longitude no Monitor Serial
  Serial.println("Precisão: " + String(loc.accuracy)); //Exibe informação da precisão no Monitor Serial
  float longi = loc.lon; //Váriavel longi recebe os valores da longitude recebidos
  float lati = loc.lat; //Váriavel lati recebe os valores da longitude recebidos
  String tempo = String(p_tm->tm_mday) + String("/") + String(mes) + String("/") + String(ano) + String(" ") + String(p_tm->tm_hour)
  + String(":") + String(p_tm->tm_min) + String(":") + String(p_tm->tm_sec);
  //Váriavel tempo recebe os valores do horário no padrão DD/MM/AAAA HH:mm:SS
  Serial.println(tempo); //Exibe informação do horário no Monitor Serial
  Serial.println(cont); //Exibe valor atual do contador no Monitor Serial
  enviarFirebase(longi, lati, tempo); //Envia os dados da latidude, longitude e tempo para a função enviarFirebase
  if (cont == 0) { //Caso o contador chegue a 0 a placa é reiniciada
    Serial.println("Reiniciar");
    ESP.restart();
  }
  cont--; //Decrementa o contador
  delay(10000); //Atraso de 10 segundos
}
