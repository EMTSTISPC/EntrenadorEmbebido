#include <Arduino.h>


//****************
// include the library code:
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//********************

//********************
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 14, en = 13, d4 = 12, d5 = 11, d6 = 10, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte posicion = 0;  //posicion de la pantalla
//*********************




void setup(){
    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);

}
  
void loop(){

//1.1 leer el teclado y mostrarlo en la primer linea de la pantalla. 
/*
  char key = keypad.getKey();

  if (key) {
    lcd.print(key);
  }
*//////////////////////////////////////////////////////////////////////////////////////////////


//1.2 leer el teclado y mostrarlo en la segunda linea de la pantalla. 
/*
  char key = keypad.getKey();
  if (key) {
    lcd.setCursor(0, 1); // Mueve el cursor a la segunda linea de la pantalla.        
    lcd.print(key);
  }
*//////////////////////////////////////////////////////////////////////////////////////////////

//1.3 Leer el teclado y mostrarlo en la ultima columna de la primera fila de la pantalla.
/*
  char key = keypad.getKey();
  if (key) {
    lcd.setCursor(15, 0); // Mueve el cursor a la ultima columna de la primera fila de la pantalla.        
    lcd.print(key);
  }
*//////////////////////////////////////////////////////////////////////////////////////////////

//1.4 Leer el teclado y mostrar en linea las teclas presionadas. 
/*
  char key = keypad.getKey();
  if (key) {
    lcd.print(key);
  }
*//////////////////////////////////////////////////////////////////////////////////////////////


//1.5 Leer el teclado y mostrar en linea las teclas presionadas.
//    al llegar a la ultima columna de la primera fila de la pantalla,
//    mover el cursor a la primera columna de la segunda fila de la pantalla.
  char key = keypad.getKey();
  if (key) {
    lcd.print(key);
    if (posicion == 15) {                  // Donde esta declarada la variable posicion ? porque esto es asi?
      lcd.setCursor(0, 1);
      posicion = 0;                       // Es correcto el funcionamiento de la pantalla en la 2da linea?         
    }
    Serial.println(posicion);
    posicion++;
  }

/**////////////////////////////////////////////////////////////////////////////////////////////// 

}