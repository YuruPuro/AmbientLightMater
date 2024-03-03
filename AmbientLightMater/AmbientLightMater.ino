/*
 * Ambient Light Sensor BH1750
 */
#include "DISP7SEG.h"
DISP7SEG disp ; // SSD1306表示クラスのインスタンス

#define BH1750_ADDR 0x23  // Ambient Light Sensor BH1750のI2Cアドレス
#define BH1750_MODE 0x10  // Continuously H-resolution mode

/**
 * Ambient Light Sensor BH1750 から照度を読み取る
 */
uint16_t readAmbienLight( ) {
  uint16_t sensorData ;
  
  // -- SEND COMMAND --
  Wire.beginTransmission(BH1750_ADDR);
  Wire.write(BH1750_MODE);
  Wire.endTransmission();
  delay (180) ;

  // -- Result --
  Wire.requestFrom(BH1750_ADDR, 2);
  while(Wire.available() < 2);
  sensorData = Wire.read();
  sensorData = sensorData << 8 | Wire.read();
  sensorData = sensorData / 1.2 ;
  return sensorData ;
}

/**
 * 
 */
void setup() {
  Wire.begin();
  disp.init() ;

  // --- 初期表示 88888Lx
  disp.disp7SEG(0,2,13) ;
  disp.disp7SEG(24,0,12) ;
  disp.disp7SEG(40,0,12) ;
  disp.disp7SEG(56,0,12) ;
  disp.disp7SEG(72,0,12) ;
  disp.disp7SEG(88,0,12) ;
  disp.dispFont16(112,4,'L') ;
  disp.dispFont16(120,4,'x') ;
  delay(1000) ;
}

/**
 * 照度表示
 */
void loop() {
  // --- 明るさ
  uint16_t sensorData = readAmbienLight( ) ;
  // --- 表示用データに変換
  uint8_t diapData[5] ;
  for (int i=0;i<5;i++) {
    diapData[i] = sensorData % 10 ;
    sensorData /= 10 ;
  }
  // --- 照度表示
  disp.disp7SEG(24,0,diapData[4]) ;
  disp.disp7SEG(40,0,diapData[3]) ;
  disp.disp7SEG(56,0,diapData[2]) ;
  disp.disp7SEG(72,0,diapData[1]) ;
  disp.disp7SEG(88,0,diapData[0]) ;

  delay(1000) ;
}
