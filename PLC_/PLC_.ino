#define seriale_declaration Seriale<32,128,16,16> seriale;                    //  in_lenMax, out_lenMax, out_stringMax, out_functionsMax (2,4,8,16,32,64,128,256)  I parametri template sono costanti di inizializzazione vengono compilate e non usano ram
#define morse_declaration   Morse<600,300,100,100,300> morse1(morseTim1()),   /* pausaparola, pausalettera, pausa, punto, linea, timer */ \
                                                       morse2(morseTim2());   /* pausaparola, pausalettera, pausa, punto, linea, timer */
//#include <stdlib.h>           // ltoa, ultoa, dtostrf  (gia inclusa in arduino.h ???)
#include <digitalWriteFast.h>   // ottimizza la velocità IO compatibilità "Arduino Uno, Nano etc. Arduino Leonardo Arduino Mega Arduino with ATmega644 or Atmega644P chip Arduino with ATmega4809 chip Arduino with ATtiny chip" nelle altre board decade ai comandi classici digitaWrite Read Mode
#include"PLCbaseFunctions.h"    //
#include"Dispositivi.h"         //
#include"PLC.h"                 //
#include"funzioniPersonali.h"   //

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------SETUP
void setup() {                  
 seriale.init(115200);                      //  1600+180 uc
 PLC_pinmode();                             //  assegna i pin come definito in PLC.h ingressi e uscite
 XL_timer(set,50,50,1,0);                   //  scandisce la trasmissione seriale a excel ( se troppo breve la seriale non invia tutto )
 Sp(F("hello world"));                      //  invia direttamente alla seriale
 sp(menuPrint);                             //  invia in modo asincrono e non bloccante la funzione menuPrint()
 cronostart=micros();                       //
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------LOOP

void loop() {
 PLC_loop(); seriale.loop(); XL_loop(); morse1.loop(); morse2.loop(); e_loop();      //loops
 funzioneSelezionata();                    // selezionata in menuSelect
 if(seriale.ready) selectMenu();           // se .in è pronto → menu selezione
 Esempi_di_prova();
 timers();
 sequenze();
 semaforo();
 ventilatori3();
 morse_fun();
 encoder();

 if(++cronocont>1000){ Sp(F("tempo medio ciclo "),(micros()-cronostart)/cronocont,F(" micros")); cronocont=0; cronostart=micros(); }
 }











     





 
  
