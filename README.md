# Projeto Integrador II - ESP32 e Display LCD
- Autores: Bernardo Souza Muniz e Ygor Vinícius Martins
- Disciplina: Projeto Integrador II

## Sobre
Este repositório é dedidacado para a documentação do trabalho desenvolvido durante a disicipina de Projeto Integrador II.


## Conexões entre GPIOs 

### **1\. Conexões do Display (ILI9341 SPI) com a ESP32-S3**

| **Pino Display**  | **Pino ESP32-S3 GPIO** |
| --------------- | --------------------- |
| **VCC**         | **3.3V**              |
| **GND**         | **GND**               |                                           
| **MOSI / SDA**  | **GPIO 12**           |               
| **SCK / SCLK**  | **GPIO 48**           |
| **DC / RS**     | **GPIO 47**           |                                       
| **RST / RESET** | **GPIO 3**            |
| **LED / BL**    | **GPIO 39**           |
| **CS**          | **GND**               |

###

### **2\. Conexões do MicroSD Card com a com a ESP32-S3**

| **Pino SD Card**  | **Pino ESP32-S3 GPIO** | 
| ---------------- | --------------------- | 
| **SD_CS**        | **GPIO 10**           | 
| **SD_MOSI**      | **GPIO 11**           | 
| **SD_SCK / CLK** | **GPIO 13**           | 
| **SD_MISO**      | **GPIO 9**            |

### **3\. Conexão dos menus de Ação e Menu**


| **Nome do botão**| **Função**        | **Pino ESP32-S3 GPIO** | **Outra perna** |
| --------------- | ------------------ | --------------------- | ------------- |
| **Botão A**     | Confirmar / Ação A | **GPIO 15**           | **GND**       |
| **Botão B**     | Voltar/ AÇÃO B     | **GPIO 5**            | **GND**       |
| **Select**      | Selecionar         | **GPIO 16**           | **GND**       |
| **Start**       | Começar            | **GPIO 17**           | **GND**       |
| **Menu**        | Acessar menu do Reto-GO      | **GPIO 8**  | **GND**       |


##