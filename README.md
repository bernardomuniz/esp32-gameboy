# Projeto Integrador II - ESP32 e Display LCD
- Autores: Bernardo Souza Muniz e Ygor Vinícius Martins
- Disciplina: Projeto Integrador II

## Sobre
Este repositório é dedidacado para a documentação do trabalho desenvolvido durante a disicipina de Projeto Integrador II.

## Recursos

- **Emulação Multi-sistema:** Suporte para NES, Game Boy, Game Boy Color, Game Gear, Master System, MSX e mais através do Retro-Go.
- **Interface Digital Simplificada:** 9 botões com sinal ativo em nível baixo (`LOW`) e *pull-up* interno ativo.
- **Fácil Montagem:** Referência única de GND para todos os botões tácteis (Common Ground Rail).
- **Sem Resistores Externos:** Aproveita a infraestrutura de hardware do próprio ESP32-S3.

---

## Componentes de Hardware

| Componente | Especificação / Modelo |
| :--- | :--- |
| **Microcontrolador** | YD-ESP32-S3 (Dual-Core LX7, 44 Pinos / 22+22) |
| **Display** | TFT LCD ILI9341 (320x240 pixels, Interface SPI) |
| **Controles** | 9x Push Buttons (Chaves tácteis de 4 pinos) |
| **Protoboard / PCB** | Protoboard com canal central ou Perfboard universal |
| **Alimentação** | Cabo USB-C / Fonte de alimentação 5V |
