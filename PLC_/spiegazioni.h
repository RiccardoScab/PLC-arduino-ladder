/*   CTRL K1
glossario breve: -----------------------------------------------------------
  Contatti ----------------------------------
  a        attivo
  l        fase lavoro
  p        fase pausa
  e        end tempo/conteggio
  -r       rising                   ar attivazione   er istante end
  -f       falling                  af spegnimento   ef il dispositivo si spegne o si riavvia
  -change  rising or falling        cambia stato
  
  act      attivazione
  set      set
  seto     set oscillante (timer)
  res      reset
  tgl      toggle : passo passo, accende spegne .
  
  time,t1,t2      imposta tempi
  time,t1,t2,p,c  imposta tempi e contatori
  tl       tempo lavoro impostato
  tld                   decresente
  tlc                   crescente
  tp       tempo pausa
  tpd                   decrescente
  tpc                   crescente
  
  pulsemax legge/scrive impulsi max      
  pulses   legge        conta impulsi
  cycles   legge        conta cicli
  cyclemax legge/scrive cicli di impulsi max
  
  m        microsecondi
  
  I__      Inizio linea
  L__      Linea
  _N_      not (la Linea superiore è falsa) altra condizione
  _n_      not, altri comandi sulla stessa linea  L__ marcia(e) ___ led1(act); _n_ led2(act);
  O__      OUT linea
  ___      azione
  __       serie
  ||       parallelo
  
  SELECTOR(      val, azione0, azione1,...,azionen)   val (0→n), azione= singolo statement / ({ multistatements }) break;     (esce dal selector  )
  SELECTORETURN( val, azione0, azione1,...,azionen)   val (0→n), azione= singolo statement / ({ multistatements }) return 0;  (esce dalla funzione)   
    
  ARG_FUNS(act, led1,led2)     led1(act); led2(act);                          ARG_FUNS( ARG, FUN1,....FUNn )→FUN1(ARG);...;FUNn(ARG);
  Act(led1,led2,tim1)          led1(act); led2(act); tim1(act);
  Set(led1,led2,tim1)          led1(set); ...
  Res(led1,led2,tim1)          led1(res); ...

  FUNS_1ARG_LIST(a,   led1,led2)  led1(a),led2(a)                             LFUNS_1ARG(ARG1,  FUN1,...FUNn)→FUN1(ARG1),...,FUNn(ARG1)
  FUNS_3ARG_LIST(a,l,p, tic,tac)  tic(a),tic(l),tic(p), tac(a),tac(l),tac(p)  LFUNS_2ARG(A1,A2, FUN1,...FUNn)→FUN1(1),FUN1(A2),...,FUNn(A1),FUNn(A2) usato per la trasmissione ad excel

  BITStoBYTES                  uint8_t a[]={BITStoBYTES(1,1,led1(a),1,1,0,0,tim1(l),0,1,0,1,1,0,0,0,0,1,1,1,1)} impacchetta fino a 256 bits in 32 bytes  (usato nella trasmissione ad excel)
  bitsToNumRev(...)            uint8_t a=bitsToNumRev(1,0,0,1,1) → 0b1101 = 13  ora può essere letto con bitRead(a,1)→0   impacchetta fino a 64 bits in un numero invertendoli , il primo è il meno significativo (usato per impostare micros)

  rollbeat(pulses,from,to)                 incrementa pulses, quando supera to torna a from                   
  rollbeat(pulses,from,to, cycles,From,To) incrementa pulses, quando supera to torna a from ed incrementa cycle che se supera To torna a From                    

  ARRAY(2,  5,8,11,...)       11      2 è l'indice 0_based e puo essere solo NUMERICO !!!!!!!
                              #define ARR(x) ARRAY(x, a,b,c,...)   
  ARR(1)                      b       b è una variabile e sarà valutata a run time      
                              #define ARR(x) ARRAY(x, "ciao","sono","io",...)   
  ARR(0)                      "ciao"
                              #define pin(x) ARRAY(x, 14,16,25,...)   
  pin(0)                      14
  pin(2)                      25
  pin(n)                      ERRORE NON valido , n non esplicito pin() è una macro e si deve espandere completamente

 ALTRE MACRO FUNZIONI :----------------------------------------------------------------------------------------------------------------------------------
  FUN_ARGS(     F, 1, a,b,c)   F(a)       F(b)   F(c) 
  FUN_ARGS(     F, 2, a,b,c,d) F(a,b)     F(c,d)  
  FUN_ARGS(     F, 3, a,...)   F(a,b,c)   F(d,e,f)  
  FUN_ARGS(     F, 4, a,...)   F(a,b,c,d) F(e,f,g,h) 
  FUN_ARGS_ENUM(F,    a,b,c)   F(0,a)     F(1,b) F(1,c)  (usato in SELECTOR)
  FUN_ARGS_LIST(F, 1, a,b,c)   F(a),      F(b),  F(c)    
  FUN_ARGS_LIST(F, 2, a,b,c,d) F(a,b),    F(c,d)  
  FUN_ARGS_LIST(F, 3, a,...)   F(a,b,c),  F(d,e,f)  
  FUN_ARGS_LIST(F, 4, a,...)   F(a,b,c,d),F(e,f,g,h) 

  ENUM(4)                     1,2,3,4          lista di progressivi max 256 
  RIPETI_(2+,3)               2+2+2 → 6       RIPETI_(variabile++;,4)  variabile++; variabile++; variabile++; variabile++;  
  IS_ZERO(n)                  (0)→   1 (n)→0
  ZERO_NULL(n)                (0)→NULL (n)→n

  COUNT_ARGS(a,b,c)           3                conta gli argomenti
  COUNT_ARGS0(a,b,c)          2                0_based             COUNT_ARGS0() → n

  #define macro(x,...)        concatena(  macro,COUNT_ARGS(__VA_ARGS__)  )( r,__VA_ARGS__ )
  macro(r,a,b,c)              macro3(r,a,b,c)
  macro(r)                    macro1(r)

  TENS(25)                      2  decine    TENS(256)  25
  UNITS(25)                     5  unità     UNITS(256)  6
  SEGMENT16(16)                 1
  SEGMENT15(15)                 1
  REST16(16)                    0





glossario dispositivi :------------------------------------------------------
  L__ marcia1(a)   ___       ingresso attivo istantaneo    
  L__        (ar)  ___       ingresso attivo su / rising   
  L__        (af)  ___       ingresso giù / falling        
  L__        (e)   ___       ingresso end timer debouncing 
  L__        (er)  ___       ingresso end timer rising     
  L__        (ef)  ___       ingresso end timer falling    
  
  led0(act);              attiva uscita               
      (set);              setta uscita                
      (res);              resetta uscita              
      (tgl);              toggle uscita               
  L__   (a))       ___       uscita attiva istantanea 
  L__   (ar))      ___       uscita attiva rising     
  
  RELE1(act);             attiva rele      
       (set);             setta rele       
       (res);             resetta rele     
       (tgl);             toggle rele      
  L__    (ar)      ___       in accensione                
  L__    (a)       ___       attivo                
  L__    (af)      ___       in spegnimento               
  
  TIMER2(...)         timer semplice
       time, t        imposta il tempo t ,se già avviato modifica scadenza
       act            attiva
       set            set
       seto           Timer set oscillante: si spegne e si riavvia il loop successivo.
       act , t        attiva impostando il tempo
       set , t        set    impostando il tempo
       seto, t        Timer set oscillante ra riavvia a fine tempo .impostando il tempo
       a              attivo  
       l              in lavoro (conteggio)     
       e              end tempo     
       m              legge 1 micros, 0 millis
       m,1            scrive 1 micros, 0 millis
       tl  =10        imposta tempo lavoro
    a= tl             leggi tempo lavoro impostato
       tld ==10       tempo lavoro decrescente countDown
       tlc ==10       tempo lavoro crescentee , passato     a = modal(T0(tlc),0,t,1,4)
                     
  
  TicTac (...)         timer asincrono oscillante
        time,t1,t2     imposta il tempo t ,se già avviato modifica scadenza
        act ,          attiva     tempi già memorizzati con (time)
        set ,          settaggio  
        act ,t1,t2     attiva     memorizza i tempi
        set ,t1,t2     settaggio  memorizza i tempi
        a              attivo  istantaneo    
        l              primo   tempo lavoro 
        p              secondo tempo pausa  
        tld  ==10      tempo lavoro decrescente countDown
        tpd  ==10      tempo pausa  decrescente countDown
        tlc  ==10      tempo lavoro crescentee , passato
        tpc  ==10      tempo pausa  crescentee , passato
        m              legge  1 micros, 0 millis
        m,1            scrive 1 micros, 0 millis
        tl     =100    imposta tempo lavoro (prossimo ciclo)
        tl     ==100   tempo lavoro impostato
        tp     =100    imposta tempo pausa
        tp     ==100   tempo pausa  impostato
        pulses ==5     TicTac(acnt)=0; quando arriva a 5 azzera contatore impulsi
  
  LampLed (...)              timer asincono oscillante con contaimpulsi e conta cicli
      time,t1,t2,p,c         imposta tempi lavoro/pausa, contatori impulsi/cicli
      act ,t1,t2,p,c         attiva  tempi e contatori opzionali se gia impistati
      set ,t1,t2,p,c         settaggio                 opzionali se gia impistati 
      res                    reset
      a                      attivo  istantaneo    
      l                      primo   tempo lavoro 
      p                      secondo tempo pausa  
      Cinc                   incremento di cycles e reset di pulses
      e                      conta cicli finito ma il timer continua a funzionare
      pulsemax   =5          legge/scrive impulsi max  (da 0 a 5 = 6 impulsi poi torna a 0)      
      cyclemax   =2          legge/scrive cicli di impulsi max (da 0 a 2 = 3 cicli poi end) =-1UL per il massimo COUNT_ARGS di cicli
      pulses     ==3         legge  conta impulsi      (3 impulsi eseguiti)   NB. possono essere modificati LampLed(pulses) = 4;
      cycles     ==2         legge  conta cicli        (2 cicli eseguiti)     NB. possono essere modificati LampLed(cycles) = 0; utile per azzerarlo .se conta cicli.   finito, attiva end, il timer continua a funzionare.
      m                      legge  1 micros, 0 millis
      m,1                    scrive 1 micros, 0 millis
      tl         =10         legge/scrive tempo lavoro impostato
      tp         =30         legge/scrive tempo pausa  impostato
   a= trest                  legge tempo restante
   a= tld                    legge tempo lavoro decrescente countDown
   a= tlc                    legge tempo lavoro crescentee , passato
   a= tpd                    legge tempo pausa  decrescente countDown
   a= tpc                    legge tempo pausa  crescentee , passato
  
      e                      Contatto ritardato             //Ccc[c], 0  inc precedente
      er                              SU  passato da 0 a 1  //Ccc[c], 1  dec precedente
      ef                              GIU passato da 1 a 0
      a                      Contatto istantaneo
      ar                              su  passato da 0 a 1 istantaneo
      af                              giu passato da 1 a 0 istantaneo

 
   | Comando                      | Uso tipico                      | Descrizione               |
   | ---------------------------- | ------------------------------- | ----------------------    |
   | flash(a)       (ar,af)       |                                 |  attivo (rising,falling)  |
   | flash(l)       (lr,lf)       |                                 |  in lavoro                |
   | flash(p)       (pr,pf)       |                                 |  in pausa                 |
   | flash(i_timed)                    |                                 |  COUNT_ARGS i_timed                |
   | flash(pulsemax)              |  flash(pulsemax)++              |  impulsi massimi          |
   | flash(pulses)                |  da 0 a pulsemax                |  impulsi fatti            |
   | flash(cycles)                |  da 0 a cyclemax                |  cicli   fatti            |
   | flash(cyclemax)              | flash(cyclemax)+=5              |  cicli   massimi          |
   | flash(tlavoro)               | flash(tlavoro)=500              |  tempo lavoro 1°          |
   | flash(tpausa)                | flash(tpausa) +=200             |  tempo pausa  2°          |
   | flash(res)                   |                                 |  reset                    |
   | flash(act,200,300,5,2)       | attiva 2 cicli di 5 impulsi , 200 lavoro, 300 pausa         |
   
   
   
   
   | Comando      | Uso tipico             | Descrizione                   |
   | ------------ | ---------------------- | ----------------------------- |
   | `C0(inc,10)` | incrementa contatore 0 | attiva cE quando raggiunge 10 |
   | `C0(dec,10)` | decrementa contatore 0 | attiva cE quando arriva a 0   |
   | `C0(rev,10)` | contatore rovescio     | conta giù fino a 0            |
   | `C0(res)`    | reset contatore        | azzera contatore              |
   | `C1..C2`     | analoghi               | per altri contatori           |
   
   

   morse_template flash(int8_t, morse_class::code[128]) = {   //ASCII 128    1 = punto, 0 = linea leggendo dal meno significativo bit(0) procedendo verso sx per asciiLen
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,   // 0–31: non stampabili
    // 32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47 
    // ' '  !   "   #   $   %   &   '   (   )   *   +   ,   -   .   / 
       -1, 22, 36, -1,114, -1,  8, 33,  9, 36, -1, 10, 12, 62, 42,  4,
    0,1,3,7,15,31,30,28,24,16,    // 48–57: '0'–'9'
    //58   59   60   61   62   63   64 
    // :    ;    <    =    >    ?    @ 
       7,  42,  -1,   2,  -1,  51,  26,
    1,14,10,6,1,11,4,15,3,1,2,13,0,2,0,9,4,5,7,0,3,7,1,6,2,12,        // 65–90: 'A'–'Z'
    -1,-1,-1,-1,-1,-1,                                                // 91–96
    1,14,10,6,1,11,4,15,3,1,2,13,0,2,0,9,4,5,7,0,3,7,1,6,2,12,        // 97–122: 'a'–'z' (alias)
    -1,-1,-1,-1,-1                                           };       // 123–127
   morse_template flash(int8_t, morse_class::codelen[128])={
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0–31: non stampabili
    // 32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47 
    // ' '  !   "   #   $   %   &   '   (   )   *   +   ,   -   .   / 
        1,  6,  6,  1,  7,  1,  5,  6,  5,  6,  1,  5,  6,  6,  6,  5,
    5,5,5,5,5,5,5,5,5,5,                                               //  48–57: '0'–'9'
    //58   59   60   61   62   63   64 
    // :    ;    <    =    >    ?    @ 
       6,   6,   1,   5,   1,   6,   6,
    2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4,               // 65–90: 'A'–'Z'
    1,1,1,1,1,1,                                                       // 91–96
    2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4,               // 97–122: 'a'–'z' (alias)
    1,1,1,1,1                                          };              // 123–127

  




🗺️ Mappa globale delle variabili
📥 Ingressi
ia       = ingressi istantanei letti da digitalRead
iA       = stato precedente (per riconoscere fronti)
iar      = rising edge (fronte salita istantaneo)
iaf      = falling edge (fronte discesa istantaneo)
i_change = variazione ingresso (XOR tra vecchio e nuovo)
itim     = flag per timing sugli ingressi
ie       = ingressi ritardati
iE       = stato precedente ingressi ritardati
ier, ief = fronti su ingressi ritardati
iTD[]    = array di contatori per ritardi singoli per ogni ingresso

📤 Uscite
o_A      = uscite attuali
oa       = uscite precedenti
oar      = rising edge uscita
oaf      = falling edge uscita
o_O      = latch (uscite da attivare)
o_t      = toggle (uscite che commutano)
o_s, o_r = set/reset diretto uscite
oo       = stato oscillatore

⏱️ Timer
t_A          = attivazione timer (input)
tT           = set timer
tosc         = oscillazione timer
tE           = ritardati timer
te, ter, tef = stato timer e fronti
tar, taf     = fronti attivazione timer
tTM[]        = array di valori di conteggio (t_last timer gestibili)
tfase        = stato temporale generale

🔀 Relè
r_A           = ingresso relè
r_O           = latch relè
r_t           = toggle relè
r_s, r_r = set/reset relè
ra, rar, raf = stato + fronti

🔂 Asincroni (bistabili a due tempi)
a_A           = ingresso acquisito
aT           = toggle asincrono
aL           = primo tempo attivazione
aP           = secondo tempo
aa, aar, aaf = stato + fronti ingresso
al, alr, alf = stato + fronti primo tempo
ap, apr, apf = stato + fronti secondo tempo
aTL[], aTP[] = durate tempi
aEND[]       = scadenze calcolate in millis()
aPcnt[]       = contatore cicli asincrono
a_s, a_r = set/reset asincrono
3

🔢 Contatori
c_A           = ingresso contatore
cE           = ritardato contatore
ca, car, caf = stato + fronti ingresso
ce, cer, cef = stato + fronti uscita
cInc, cDec   = flag incremento/decremento
cCNT[]        = array valori contatori
cinc, cdec   = valore corrente incremento/decremento

⏳ Gestione tempi di ciclo
PLC_millis          = millis attuali
Millis, MillisO = lowByte di millis() corrente e precedente
Millispas       = millisecondi passati dall’ultimo ciclo

🔄 Funzionamento del ciclo PLC_loop()
Lettura ingressi  : i_readAll() → scrive i valori istantanei in ia.
Rilevazione fronti: calcola iar, iaf, i_change.
Gestione uscite   : toggle, set/reset, latch → scrive nei pin con o_scriviUscite().
Gestione relè     : logica identica alle uscite.
Gestione timer    : countdown con millis(), gestione oscillanti, fronti di start/stop1.
Gestione asincroni: sequenza t1 → t2 con alternanza e contatore cicli.
Gestione contatori: incrementali, decrementali, rovesci, con reset.
Aggiornamento stati old/new: variabili oa, iA, iE, ra, ta, aa, al, ap, ce ecc.

👉 un kernel PLC_loop minimale:
tutto è gestito per bitmask (32 segnali max),
c’è il supporto a fronti, ritardi, contatori, timer oscillanti,
il ciclo PLC_loop() è equivalente allo scan cycle di un vero PLC_loop industriale.


Arduino Mega :
Pin        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 41 42 43 44 45 46 47 48 49 50 51 52 53 A0 A1 A2 A3 A4 A5 A6 A7 A8 A9 A10 A11 A12 A13 A14 A15
DIGITAL    D D D D D D D D D D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D  D   D   D   D   D   D   D   pinMode(pin, OUTPUT) pinMode(pin, INPUT_PULL_UP) 20-40 Kohm
ANALOG                                                                                                                                A  A  A  A  A  A  A  A  A  A   A   A   A   A   A   A   analogRead(pin) 0→1023 0→5 VOLTS TRA AREF e An
PWM            P P P P P P P P  P  P  P  P                                                              P  P  P                                                                              analogWrite(pin, 127): Sets the duty cycle to approximately 50%.
Interrupt      I I                                      I  I  I  I                                                                                                                           attachInterrupt(interrupt, ISR, mode) mode=(LOW, RISING, FALLING, or CHANGE). 
ON BOARD LED                             L
porte      S S                              S  S  S  S  S  S  S  S                                                         S  S  S  S 

SERIAL TX=1 RX=0, SERIAL2 TX=18 RX=19, SERIAL2 TX=16 RX=17, SERIAL2 TX=14 RX=15  
SPI: Pin 50 (MISO), 51 (MOSI), 52 (SCK), 53 (SS)
I2C: Pin 20 (SDA) e 21 (SCL)

⚡Alimentazione
VIN: Alimentazione esterna (6–20V) = JACK
Uscite per alimentare moduli esterni
       5V     MAX 500mA  
       3.3V   MAX 50mA  

GND: Terra (ce ne sono diversi)

🧠 Pin Speciali
RESET: Per resettare il microcontrollore
AREF: Riferimento per tensione analogica
IOREF: stands for Input/Output Reference Voltage. 
ICSP: Per la programmazione diretta del chip

https://lastminuteengineers.com/arduino-mega-pinout/








📚 ---------------------------------------------Tabella delle funzioni <cstring> -----------------------------------------------------------------------------------------------------------------------------------
Funzione	Parametri	                                   Descrizione
strlen	       const char* str	                             Restituisce la lunghezza della stringa (esclude il terminatore \0)
strcpy	       char* dest, const char* src	                 Copia src in dest                                                    strcpy(dest, "Ciao mondo");  copia da src a dest uc per uc fin a che trova in src \0 compreso . dest deve avere almeno la sizeof src 
strncpy	char* dest, const char* src, size_t n	              Copia al massimo n caratteri da src a dest                           strncpy(dest+2, "Ciao mondo", 4); dest[2+4] = '\0';  copia dal 3°carattere di dest 4 uc di src . è necessario aggiungere \0 alla fine    
strcat	       char* dest, const char* src	                 Aggiunge src alla fine di dest
strncat	char* dest, const char* src, size_t n	              Aggiunge al massimo n caratteri di src a dest
strcmp	       const char* str1, const char* str2	           Confronta due stringhe (ritorna 0 se uguali)
strncmp	const char* str1, const char* str2, size_t n	        Confronta al massimo n caratteri
strchr	       const char* str, int ch	                    Restituisce un puntatore alla prima occorrenza di ch in str
strrchr	const char* str, int ch	                             Restituisce un puntatore all’ultima occorrenza di ch in str
strstr	       const char* haystack, const char* needle	     Cerca needle dentro haystack
strcpy_s	char* dest, size_t destsz, const char* src	        Versione sicura di strcpy (non sempre disponibile su Arduino)
strtok	       char* str, const char* delimiters	           Divide la stringa in token usando i delimitatori
memcpy	       void* dest, const void* src, size_t n	        Copia n bytes da src a dest      (dest=src COUNT_ARGS bytes)
memmove	void* dest, const void* src, size_t n	              Come memcpy, ma gestisce sovrapposizioni
memcmp	       const void* ptr1, const void* ptr2, size_t n  Confronta n uc tra due blocchi di memoria
memchr	       const void* ptr, int value, size_t n	        Cerca value nei primi n uc di ptr
memset	       void* ptr, int value, size_t n	              Imposta i primi n uc di ptr al valore value

#define STRING_COPY(dst, src, size) snprintf((dst), (size<=sizeof(dst))?(size):sizeof(dst), "%s", (src))        //STRING_COPY(bufferin, "Ciao Riccardo", sizeof(bufferin));
#define STRING_COPY(dst, src, size) strncpy((dst), (src), (size)); dst[sizeof(dst)-1]="\0";]    //STRING_COPY(bufferin, "Ciao Riccardo", sizeof(bufferin));
#define STRING_EQUALS(a, b)         (strcmp((a), (b)) == 0) 
#define STRING_CLEAR(buf)           ((buf)[0] = '\0')
#define STRING_IS_EMPTY(s)          ((s)[0] == '\0') 
#define INIT_BUFFER(buf, val)       strncpy((buf), (val), sizeof(buf)); (buf)[sizeof(buf)-1] = '\0'
 
ASCII :  !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^L__`abcdefghijklmnopqrstuvwxyz{|}~ ¡¢£¤¥¦§¨©ª«¬®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ
UTF-8 encoded,simbolo da 1 a 4 byte.
https://symbl.cc/en/unicode-table/#enclosed-alphanumerics
✅ Stato e controllo        - ✅❌⚠️🔒🔓⏳🔄🔁🔂🆗🆕
🔋 Energia e potenza        - ⚡🔋🔌🔆🌡️🪫
📡 Connessione e rete       - 📶📡🛰️🌐🔗
🧭 Navigazione e direzione  - ⬆️⬇️⬅️➡️🔙🔚🧭
🛠️ Strumenti e manutenzione - ⚙️🔧🔩🧰🛠️🧱🧲🧪🧬🧮🧼🪛
🚨 Sicurezza e allarme      - 🧯🚨🛑📛
📂 File e flusso dati       - 📂📁📤📥🗂️🗃️🗄️
📊 Analisi e misurazione    - 📊📈📉
🟢 Stato operativo          - 🟢🔴🟡🔵⚫⚪
🪜 Hardware e materiali     - 🪜🪙🪪🪬🪨🪵🪶🪺🪻🪼🪿
🫀 Diagnostica biologica    - 🫀🫁
♻️ Accessibilità e riciclo  - ♻️♿

④ ⑳
https://www.unicode.org/charts/
arrows:   ←   ↑   →   ↓   ↔   ↕   ↖   ↗   ↘   ↙   ↚   ↛   ↜   ↝   ↞   ↟   ↠   ↡   ↢   ↣   ↤   ↥   ↦   ↧   ↨   ↩   ↪   ↫   ↬   ↭   ↮   ↯   ↰   ↱   ↲   ↳   ↴   ↵   ↶   ↷   ↸   ↹   ↺   ↻   ↼   ↽   ↾   ↿   ⇀   ⇁   ⇂   ⇃   ⇄   ⇅   ⇆   ⇇   ⇈   ⇉   ⇊   ⇋   ⇌   ⇍   ⇎   ⇏   ⇐   ⇑   ⇒   ⇓   ⇔   ⇕   ⇖   ⇗   ⇘   ⇙   ⇚   ⇛   ⇜   ⇝   ⇞   ⇟   ⇠   ⇡   ⇢   ⇣   ⇤   ⇥   ⇫   ⇬   ⇭   ⇮   ⇯   ⇰   ⇱   ⇲   ⇴   ⇵   ⇶   ⇷   ⇸   ⇹   ⇺   ⇻   ⇼   ⇽   ⇾   ⇿ ⟰  ⟱  ⟲  ⟳  ⟴  ⟵  ⟶  ⟷  ⟸  ⟹  ⟺  ⟻  ⟼  ⟽  ⟾  ⟿  
*/

/* -------------------------------------------------------------------------------------------------------------------------------------------
#ifndef F_PRECOMPILATORE_MAGICO_H
#define F_PRECOMPILATORE_MAGICO_H

// 📅 Informazioni di compilazione
#define INFO_LINEA     __LINE__        // Numeroargs di riga corrente
#define INFO_FILE      __FILE__        // Nome del file corrente
#define INFO_DATA      __DATE__        // Data di compilazione (stringa)
#define INFO_ORA       __TIME__        // Ora di compilazione (stringa)
#define INFO_FUNZIONE  __func__        // Nome della funzione corrente (C99/C++)
#define INFO_CPLUSPLUS __cplusplus     // Versione del linguaggio C++ (es. 201103L)

// 🔢 Contatore globale crescente
#define ID_UNIVOCO     __COUNTER__     // Ogni espansione restituisce un intero crescente

// 🧠 Concatenazione forzata
#define CONCATENA(a,b) a##b
#define ESPANDI_CONCATENA(a,b) CONCATENA(a,b)

// 🔍 Conta argomenti variadici
#define NUMERO_ARGOMENTI(...) NUMERO_IMPL(__VA_ARGS__,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define NUMERO_IMPL(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,N,...) N

// 🧩 Overload di macro
#define SCEGLI_MACRO(NOME, ...) NOME(__VA_ARGS__)
#define STAMPA1(a) Serial.print(a)
#define STAMPA2(a,b) Serial.print(a); Serial.print(b)
#define STAMPA3(a,b,c) Serial.print(a); Serial.print(b); Serial.print(c)
#define STAMPA(...) SCEGLI_MACRO(STAMPA##NUMERO_ARGOMENTI(__VA_ARGS__), __VA_ARGS__)

// 🧙‍♂️ Generazione di nomi unici
#define NOME_UNICO(base) ESPANDI_CONCATENA(base, __COUNTER__)

// 🔁 Loop statico (ripetizione)
#define RIPETI3(x) x; x; x;
#define RIPETI5(x) x; x; x; x; x;
#define RIPETI10(x) x; x; x; x; x; x; x; x; x; x;

// 🧮 Contatore locale (base fissata)
#define CREA_BASE_CONTATORE(nome) enum { nome = __COUNTER__ }
#define CONTATORE_LOCALE(base) (__COUNTER__ - base - 1)

// ✨ Espansione ritmica (+1+1+1...)
#define cont0 +1
#define cont1 cont0+1
#define cont2 cont1+1
#define cont3 cont2+1
#define cont4 cont3+1
#define cont5 cont4+1
#define cont6 cont5+1
#define cont7 cont6+1
#define cont8 cont7+1
#define cont9 cont8+1
#define cont10 cont9+1
#define cont(n) ESPANDI_CONCATENA(cont, n)

// 📚 Macro didattiche per enum sequenziali
#define ENUM_PROGRESSIVO(nome, ...) enum nome { __VA_ARGS__ }
#define ENUM_AUTO(nome, ...) enum nome { __VA_ARGS__, nome##_NUM = NUMERO_ARGOMENTI(__VA_ARGS__) }

// 🧬 Macro per generare codice ripetuto con indice
#define CODICE_CON_INDICE(i) Serial.print("Indice: "); Serial.print(i);
#define RIPETI_INDICI_3 CODICE_CON_INDICE(0) CODICE_CON_INDICE(1) CODICE_CON_INDICE(2)

#endif // F_PRECOMPILATORE_MAGICO_H



*/                          
/*
Serial.print() su Arduino invia dati sulla porta seriale come testo ASCII leggibile, convertendo numeri, caratteri e stringhe in sequenze di byte che rappresentano i caratteri corrispondenti.




Conversione di stringhe C in numeri
                                                                     
atoi(str)                 int       n = atoi("123");                  
atol(str)                 long      n = atol("123");                 
atoll(str)                long long n = atoll("123");                
atof(str)                 double    d = atof("45.67");                
strtol(str, &end, base)   long      n = strtol("123abc",   &end, 10); 
strtoll(str, &end, base)  long long n = strtoll("123abc",  &end, 10); 
strtod(str, &end)         double    d = strtod("45.67xyz", &end);     

    char str1[] = "123";
    char str2[] = "45.67xyz";

    int    n1 = atoi(str1);    // converte in int                      int: 123
    double d1 = atof(str2);    // converte in double (ignora "xyz")    double: 45.67

    char* end;
    long n2   = strtol(str1, &end, 10);   // base 10                   long: 123
    double d2 = strtod(str2, &end);       // converte fino a "45.67"   double: 45.67   end="xyz"
*/



/*
 Sp(F("a"));                                // 10   0 
 static uc i=0;                             // 22   1  insieme a if(++i>4) i=0;
 Sp(sarray(i));                             // 78  10  ram utilizzata per buffer 10 byte di .print
 Sp(sarray(i));                             // 40   0  buffer .print riutilizzato
 static ul larray[]={1000,1500,2000,400,10};//  0   0  se non static deve ricrearsi ogni loop
 Sp(larray[i]);                             // 46  20  arr inizializzato
 static f_const ul farray[]={1000,1500,2000,400,10};
 Sp(f_get(farray+i));                       // 50   0  
 if(++i>4) i=0;                             // 
*/



/*  

- Vai su GitHub: https://github.com/boostorg/preprocessor (github.com in Bing)
- Scarica solo la cartella: boost/preprocessor/
- Copiala dentro una tua libreria Arduino, ad esempio: Documents/Arduino/libraries/BoostPP/
- Dentro BoostPP/ crea un file BoostPP.h che include #pragma once #include "boost/preprocessor.hpp"
- Nel tuo sketch Arduino: #include <BoostPP.h>  //#include <boost/preprocessor/repetition/repeat.hpp>
   //------------------------------------------------------------------------------------------




   #define ENUM(n)  concatena(ENUM_,n)
   #define ENUM_0           // vuoto 
   #define ENUM_1   1
   #define ENUM_2   1,2
   #define ENUM_3   1,2,3
   #define ENUM_4   1,2,3,4
   #... continua

   #define ENUM0(n) concatena(ENUM0_,n)   
   #define ENUM0_0  0 
   #define ENUM0_1  0,1 
   #define ENUM0_2  0,1,2 
   #define ENUM0_3  0,ENUM_3 
   #define ENUM0_4  0,ENUM_4 
   #... continua

   #define ARRAY(        ...) ARRAy(__VA_ARGS__)                    // ARRAY puo contenere qualsiasi argomento
   #define ARRAy(  x, ...) concatena(ARRAy,TENS(x))(x,__VA_ARGS__)
   #define ARRAy0( x, ...) concatena(ARRay, x)(__VA_ARGS__)
   #define ARRay0(    a, ...) a
   #define ARRay1(    a,b, ...) b
   #define ARRay2(    a,b,c, ...) c
   #... continua
 
// ----------------------------- FUN_ARGS                      ----------------------------------- FUN_ARGS(F,r,a)→F(r);F(a);  FUN_ARGS(pippo,a,b,c) → pippo(a);pippo(b);pippo(c); espande fn con tutti gli argomenti 
   #define FUN_ARGS(    _,...) concatena(FUN_ARGS,  SEGMENT16_( __VA_ARGS__))(_,__VA_ARGS__)  
   #define FUNF0(   _,...) concatena(FUNF0_,COUNT_ARGS(__VA_ARGS__))(_,__VA_ARGS__)
   #define FUNF0_1( _, a)                                   _(a) 
   #define FUNF0_2( _, a,b)                                 _(a) _(b)  
   #define FUNF0_3( _, a,b,c)                               _(a) _(b) _(c) 
   #... continua







Cosa devi fare lì dentro
- Apri cmd o PowerShell
- Incolla la riga del compilatore :
Compilazione dello sketch in corso...
"C:\Users\s-ric\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR "-IC:\Users\s-ric\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.7\cores\arduino" "-IC:\Users\s-ric\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.7\variants\standard" "-Ic:\Users\s-ric\Documents\Arduino\libraries\digitalWriteFast" "C:\Users\s-ric\AppData\Local\arduino\sketches\677B2CA78C115E6B4B858E4471D4F438\sketch\PLCmega2.ino.cpp" -o "C:\Users\s-ric\AppData\Local\arduino\sketches\677B2CA78C115E6B4B858E4471D4F438\sketch\PLCmega2.ino.cpp.o"
- Modificala togli -c, togli -o ..., aggiungi -E -P -CC
"C:\Users\s-ric\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR "-IC:\Users\s-ric\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.7\cores\arduino" "-IC:\Users\s-ric\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.7\variants\standard" "-Ic:\Users\s-ric\Documents\Arduino\libraries\digitalWriteFast" "C:\Users\s-ric\AppData\Local\arduino\sketches\677B2CA78C115E6B4B858E4471D4F438\sketch\PLCmega2.ino.cpp" -E -P
- Premi invio
E il terminale ti stamperà l’espansione delle macro.












// ============================================================
//  INFRASTRUTTURA BOOST-STYLE (DEFER / OBSTRUCT / EVAL)
// ============================================================

#define EMPTY()
#define DEFER(id) id EMPTY()
#define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()

#define CAT(a,b) CAT_I(a,b)
#define CAT_I(a,b) a##b

#define EXPAND(...) __VA_ARGS__

// --- EVAL: forza più passate di espansione ---
#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) __VA_ARGS__

// ============================================================
//  BOOLEANI E IF
// ============================================================

#define PROBE(x) x,1
#define CHECK(...) CHECK_N(__VA_ARGS__,0)
#define CHECK_N(x,n,...) n

#define NOT(x) CHECK(CAT(NOT_,x))
#define NOT_0 PROBE(~)

#define BOOL(x) NOT(NOT(x))

#define IF(c) CAT(IF_,c)
#define IF_0(t,f) f
#define IF_1(t,f) t

// ============================================================
//  HAS_ARGS — rileva se ci sono ancora argomenti
// ============================================================

#define FIRST(a, ...) a
#define HAS_ARGS_IMPL(...) BOOL(FIRST(__VA_ARGS__))
#define HAS_ARGS(...) HAS_ARGS_IMPL(__VA_ARGS__ ,0)

// ============================================================
//  MOTORE RICORSIVO A TRIPLE
// ============================================================

// API pubblica
#define FUN_3ARGS_LIST(F, ...) \
    EVAL(FUN_3ARGS_LIST_I(OBSTRUCT(), F, __VA_ARGS__))

// Caso generale: almeno una tripletta
#define FUN_3ARGS_LIST_I(_, F, a,b,c, ...)                                   \
    F(a,b,c)                                                                 \
    IF(HAS_ARGS(__VA_ARGS__))(                                               \
        OBSTRUCT()(, FUN_3ARGS_LIST_I(_, F, __VA_ARGS__)) ,                  \
        /* else: fine */                                                     \
    )









*/

