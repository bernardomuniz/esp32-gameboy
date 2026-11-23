#include <Arduino_GFX_Library.h>
#include <SD.h>
#include <SPI.h>


// 1. Define os pinos do display (MANTIDOS EXATAMENTE OS SEUS)
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


// Define pinos totalmente separados para o Cartão SD (MANTIDOS EXATAMENTE OS SEUS):
const int SD_CS = 41;
const int SD_MOSI = 40;
const int SD_MISO = 39;
const int SD_SCK = 42;


// Instância SPI dedicada para o barramento do SD no ESP32-S3
SPIClass sdSPI(HSPI);


int i = 0;


void setup() {
  Serial.begin(115200);
  delay(1000);


  // --- TELA TFT ---
  Serial.println("\nA iniciar display com Arduino_GFX no ESP32-S3...");


  // Inicializa o display
  tft->begin();
  tft->fillScreen(0x0000); // Fundo preto


  tft->setCursor(10, 30);
  tft->setTextColor(0xF800); // Vermelho
  tft->setTextSize(3);
  tft->println("ESP32-S3 OK!");


  tft->setCursor(10, 70);
  tft->setTextColor(0xFFFF); // Branco
  tft->setTextSize(2);
  tft->println("Pronto para o Game Boy!");
  
  Serial.println("Display iniciado com sucesso!");


  // --- SD ---
  sdSPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);


  tft->setCursor(10, 110);
  if (!SD.begin(SD_CS, sdSPI)) {
    Serial.println("Falha ao iniciar o Cartão SD!");
    tft->setTextColor(0xF800); // Vermelho
    tft->println("SD: Falha ao iniciar!");
    return;
  }
  
  Serial.println("Cartão SD inicializado com sucesso!");
  tft->setTextColor(0x07E0); // Verde
  tft->println("SD: OK!");
}


void loop() {
  i++;


  // ESCRITA NO SD
  File arq_w = SD.open("/teste.txt", FILE_WRITE);
  if (arq_w) {
    arq_w.println(i);
    arq_w.close();
  }


  delay(2000);


  // LEITURA DO SD
  File arq_r = SD.open("/teste.txt", FILE_READ);
  if (arq_r) {
    // Limpa a área inferior do display para mostrar a leitura do SD
    tft->fillRect(0, 150, 240, 170, 0x0000); 
    tft->setCursor(10, 150);
    tft->setTextColor(0xFFFF); // Branco
    tft->setTextSize(2);
    tft->print("Lendo SD: ");


    while (arq_r.available()) {
      char c = arq_r.read();
      Serial.write(c);   // Envia para o Monitor Serial
      tft->print(c);     // Escreve na tela do TFT
    }
    arq_r.close();
  }


  delay(2000);
}