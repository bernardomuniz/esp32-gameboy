#include <Arduino_GFX_Library.h>


// 1. Define os pinos do display
#define TFT_MOSI 11
#define TFT_SCLK 12
#define TFT_MISO 13
#define TFT_CS   10
#define TFT_DC   9
#define TFT_RST  14


// 2. Configuração do barramento SPI para o ESP32-S3
Arduino_DataBus *bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCLK, TFT_MOSI, TFT_MISO, HSPI);


// 3. Configuração do Display ILI9341 (240x320)
Arduino_GFX tft = new Arduino_ILI9341(bus, TFT_RST, 1 / rotação /, false / IPS */);


void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nA iniciar display com Arduino_GFX no ESP32-S3...");


  // Inicializa o display
  tft->begin();
  
  // Preenche a tela de preto (usando 0x0000 para preto absoluto)
  tft->fillScreen(0x0000);


  // Escreve um texto de teste (Usando 0xF800 para Vermelho e 0xFFFF para Branco)
  tft->setCursor(10, 50);
  tft->setTextColor(0xF800); // Vermelho em formato RGB565
  tft->setTextSize(3);
  tft->println("ESP32-S3 OK!");


  tft->setCursor(10, 100);
  tft->setTextColor(0xFFFF); // Branco em formato RGB565
  tft->setTextSize(2);
  tft->println("Pronto para o Game Boy!");
  
  Serial.println("Display iniciado com sucesso!");
}


void loop() {
  // Nada aqui
}