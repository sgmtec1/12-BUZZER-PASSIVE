// Open Source
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

#include "pitches.h"
 
int touch = 2; //pino SIG do sensor touch
// notas da melodia
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
 
// duraçao das notas: 4 = um quarto, 8 = um oitavo, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
 
void setup() {
  // declara o pino de sinal do sensor como entrada:
  pinMode(touch,INPUT);
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
   
}
 
void loop() { 
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("NOTAS MUSICAIS");
  
  int botao = digitalRead(touch); // realiza leitura do pino de sinal e armazena na variavel botao
  if(botao == 1){ // se botao for igual a 1, ou seja, pressionado
    for (int thisNote = 0; thisNote < 8; thisNote++) {
 
    // para calcular a duraçao da nota, faz um segundo
    // dividido pelo tempo da nota.
    //para um quarto = 1000 / 4, para um oitavo = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
 
    // para distinguir as notas, seta um tempo minimo entre elas.
    // a duraçao da nota + 30%:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // para a melodia
    noTone(8);
   }
  }
}
