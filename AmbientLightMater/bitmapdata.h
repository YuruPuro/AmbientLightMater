static uint8_t bitPattern[] = {
  0b00000000 , 0b00000011 , 0b00001100 , 0b00001111 , 0b00110000 ,
  0b00110011 , 0b00111100 , 0b00111111 , 0b11000000 , 0b11000011 ,
  0b11001100 , 0b11001111 , 0b11110000 , 0b11110011 , 0b11111100 ,
  0b11111111 
};

const bool addMap[][7] = {
  true , true , true , true , true , true , false,  // 0
  false, true , true , false, false, false, false,  // 1
  true , true , false, true , true , false, true ,  // 2
  true , true , true , true , false, false, true ,  // 3
  false, true , true , false, false, true , true ,  // 4
  true , false, true , true , false, true , true ,  // 5
  true , false, true , true , true , true , true ,  // 6
  true , true , true , false, false, false, false,  // 7
  true , true , true , true , true , true , true ,  // 8
  true , true , true , true , false, true , true ,  // 9
  false, false, false, false, false, false, true ,  // -
} ;

const int base7SEG_W=16 , base7SEG_H = 32;
const uint8_t base7SEG[] PROGMEM = {
  0xFC,0x02,0x05,0x09,0xF1,0x11,0x11,0x11,0x11,0x11,0xF1,0x09,0x05,0x02,0xFC,0x00,
  0x7F,0x80,0x80,0x40,0x3F,0x20,0x20,0x20,0x20,0x20,0x3F,0x40,0x80,0x80,0x7F,0x00,
  0xFF,0x00,0x00,0x01,0xFE,0x02,0x02,0x02,0x02,0x02,0xFE,0x01,0x00,0x00,0xFF,0x00,
  0x1F,0x20,0x50,0x48,0x47,0x44,0x44,0x44,0x44,0x44,0x47,0x48,0x50,0x20,0x1F,0x00
};

// a
const int SEGa_W=16 , SEGa_H = 32;
const uint8_t SEGa[] PROGMEM = {
  0x00,0x00,0x02,0x06,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x06,0x02,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

// b
const int SEGb_W=16 , SEGb_H = 32;
const uint8_t SEGb[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF8,0xFC,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x7F,0x7F,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

// c
const int SEGc_W=16 , SEGc_H = 32;
const uint8_t SEGc[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFF,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x1F,0x00,0x00,
};

// d
const int SEGd_W=16 , SEGd_H = 32;
const uint8_t SEGd[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x20,0x30,0x38,0x38,0x38,0x38,0x38,0x38,0x38,0x30,0x20,0x00,0x00,0x00,
};

// e
const int SEGe_W=16 , SEGe_H = 32;
const uint8_t SEGe[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x1F,0x0F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

// f
const int SEGf_W=16 , SEGf_H = 32;
const uint8_t SEGf[] PROGMEM = {
  0x00,0xFC,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x7F,0x7F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

// g
const int SEGg_W=16 , SEGg_H = 32;
const uint8_t SEGg[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

// dot
const int SEGdot_W=16 , SEGdot_H = 32;
const uint8_t SEGdot[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x3C,0x7E,0x7E,0x7E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

// coron
const int SEGcoron_W=16 , SEGtcoron_H = 32;
const uint8_t SEGcoron[] PROGMEM = {
0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xE0,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x07,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xE0,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x07,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
} ;

const int ILLUMINACE_W=16 , ILLUMINACE_H = 16;
const uint8_t ILLUMINACE [] PROGMEM = {
  0x40,0x41,0x10,0xC2,0x24,0x10,0x0B,0x08,0x0B,0x10,0x24,0xC2,0x10,0x48,0x40,0x00,
  0x01,0x09,0x04,0x01,0x06,0x78,0x88,0x88,0x88,0x78,0x06,0x01,0x04,0x09,0x01,0x00
} ;

const int font16_W=8 , font16_H = 16;
const uint8_t font8x16 [] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Space 32 
  0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00, // L 44
  0x00,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x31,0x2E,0x0E,0x31,0x20,0x00, // x 88
};
