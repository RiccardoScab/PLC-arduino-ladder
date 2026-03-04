// clicca qui e poi      ctrl+k2 k1 nascondi    L   ctrl+kj scopri tutto    //------------------------------------------------------------------------------------------
//------------------------------ INGRESSI                     --------------------------------
  #define emergenza(...)    i_g(  0 ,##__VA_ARGS__ )   // emergenza(a)  -→ i_a(0)  -→ bitread(ia,0)  -→ (ia >> 0) & 0x01
  #define   marcia1(...)    i_g(  1 ,##__VA_ARGS__ )   // si usa :  if(marcia1(e ))  verrà compilato : if(bitRead(ie ,0))
  #define   marcia2(...)    i_g(  2 ,##__VA_ARGS__ )   //
  #define     stop1(...)    i_g(  3 ,##__VA_ARGS__ )   // si usa :  if(  stop1(ar))  verrà compilato : if(bitRead(iar,3))  legge il bit 3 di iar
  #define     stop2(...)    i_g(  4 ,##__VA_ARGS__ )   //
  #define  termico1(...)    i_g(  5 ,##__VA_ARGS__ )   // ,##__VA_ARGS__  concatena , con __VA_ARGS__ . Se __VA_ARGS__ è vuoto la virgola non verrà riportata
  #define  termico2(...)    i_g(  6 ,##__VA_ARGS__ )   // 
  #define       IN7(...)    i_g(  7 ,##__VA_ARGS__ )   //
  #define       IN8(...)    i_g(  8 ,##__VA_ARGS__ )   //
  #define       IN9(...)    i_g(  9 ,##__VA_ARGS__ )   //
  #define      IN10(...)    i_g( 10 ,##__VA_ARGS__ )   //
  #define     i_last             10                    // numero ultimo ingresso      
                  // 0   1   2   3   4   5   6   7   8   9  10        
  #define i_Pin      4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14
  #define i_Negato   1,  0,  0,  0,  1,  1,  1,  0,  0,  1,  0
  #define i_Pullup   1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  1
  #define i_Time    20, 20, 20, 20, 20, 20, 20,  3,  3, 10, 10     // tempo antirimbalzo ms

  #define i_XL_CONTATTI a,e
  #define i_XL_VALORI
  #define i_XL_DISPOSITIVI emergenza,marcia1,marcia2,stop1,stop2,termico1,termico2,IN7,IN8,IN9,IN10

//------------------------------ USCITE                       --------------------------------
  #define       led0(...)   o_g(  0 ,##__VA_ARGS__ )   // usare cosi : if(led1(a))   led2(act)   
  #define       led1(...)   o_g(  1 ,##__VA_ARGS__ )   //              if(led1(ar))  led2(set) led3(res)
  #define       led2(...)   o_g(  2 ,##__VA_ARGS__ )   //              if(led1(af))  led2(res) led3(set)
  #define       led3(...)   o_g(  3 ,##__VA_ARGS__ )   // led3() → 3
  #define       led4(...)   o_g(  4 ,##__VA_ARGS__ )   //
  #define       led5(...)   o_g(  5 ,##__VA_ARGS__ )   //
  #define   ledstop1(...)   o_g(  0 ,##__VA_ARGS__ )   // ventilatori
  #define   ledstop2(...)   o_g(  1 ,##__VA_ARGS__ )   // ventilatori
  #define vent1star1(...)   o_g(  2 ,##__VA_ARGS__ )   // ventilatori
  #define vent1star2(...)   o_g(  3 ,##__VA_ARGS__ )   // ventilatori
  #define vent1delta(...)   o_g(  4 ,##__VA_ARGS__ )   // ventilatori
  #define vent2star1(...)   o_g(  5 ,##__VA_ARGS__ )   // ventilatori
  #define vent2star2(...)   o_g(  6 ,##__VA_ARGS__ )   // ventilatori
  #define vent2delta(...)   o_g(  7 ,##__VA_ARGS__ )   // ventilatori
  #define     rosso1(...)   o_g(  0 ,##__VA_ARGS__ )   // semaforo   
  #define     verde1(...)   o_g(  1 ,##__VA_ARGS__ )   // semaforo   
  #define    giallo1(...)   o_g(  2 ,##__VA_ARGS__ )   // semaforo   
  #define     rosso2(...)   o_g(  3 ,##__VA_ARGS__ )   // semaforo   
  #define     verde2(...)   o_g(  4 ,##__VA_ARGS__ )   // semaforo   
  #define    giallo2(...)   o_g(  5 ,##__VA_ARGS__ )   // semaforo   
  #define o_last                  7                    // COUNT_ARGS ultima uscita
  //              0  1  2  3  4  5  6  7
  #define o_pins 13,14,15,16,17,18,19,20

  #define o_XL_CONTATTI a
  #define o_XL_VALORI
  #define o_XL_DISPOSITIVI led0,led1,led2,led3,led4,ledstop1,ledstop2,vent1star1,vent1star2,vent1delta,vent2star1,vent2star2,vent2delta,rosso1,verde1,giallo1,rosso2,verde2,giallo2

//------------------------------ INGRESSI ANALOGICI           --------------------------------
   //------------------------------------------------------------------------------------------
  #define    potenz1(...)       ai_g(  0 ,##__VA_ARGS__ )   // usare cosi :    0→1023
  #define    potenz2(...)       ai_g(  1 ,##__VA_ARGS__ )   // usare cosi :    
  #define    temperatura(...)   ai_g(  2 ,##__VA_ARGS__ )   // usare cosi :    
  #define    ailast                    2                    // COUNT_ARGS ultimo ingresso analogico
                  //  0   1   2   3   4   5   6   7   8   9  10
  #define    ai_Pin  A0, A1, A2                        // pin analogici

  // tutti gli ingressi analogici devono essere mappati (soglia,tolleranza)
  #define ai_LEVELS_0(M)   \
           M(     0,  20), \
           M(  1*78,  20), \
           M(  2*78,  20), \
           M(  3*78,  20), \
           M(  4*78,  20), \
           M(  5*78,  20), \
           M(  6*78,  20), \
           M(  7*78,  20), \
           M(  8*78,  20), \
           M(  9*78,  20), \
           M( 10*78,  20), \
           M( 11*78,  20), \
           M( 12*78,  20)    
  #define ai_LEVELS_1(M)   \
           M(     0,  30), \
           M( 1*127,  30), \
           M( 2*127,  30), \
           M( 3*127,  30), \
           M( 4*127,  30), \
           M( 5*127,  30), \
           M( 6*127,  30), \
           M( 7*127,  30)    
  #define ai_LEVELS_2(M)   \
           M(     0, 100), \
           M(  1023, 100) // 1 a 923, 0 a 100
           //soglia,tolleranza

   //------------------------------------------------------------------------------------------
//------------------------------ USCITE  ANALOGICHE           --------------------------------
   //------------------------------------------------------------------------------------------
   #define  motor1(...)   ao_g(  0 ,##__VA_ARGS__ )   // usare cosi :    
   #define  motor2(...)   ao_g(  1 ,##__VA_ARGS__ )   // usare cosi :    
   #define  motor3(...)   ao_g(  2 ,##__VA_ARGS__ )   // usare cosi :    
   #define  motor4(...)   ao_g(  3 ,##__VA_ARGS__ )   // usare cosi :    
   #define  aolast               3                    // COUNT_ARGS ultimo out analogico
                    //   0   1   2   3   4   5   6   7   8   9  10
   const uc aopin[]  =  {3,  5,  6,  9};                  // pin PWM , motore4 è sul pin 9
          
   //------------------------------------------------------------------------------------------
//------------------------------ INGRESSI INTERRUPT           --------------------------------
   //------------------------------------------------------------------------------------------
                      //  pin    pin mode     isr  isr mode
  #define ii_pinmode iis(  2, INPUT_PULLUP,  isr2,  CHANGE ) \
                     iis(  3, INPUT_PULLUP,  isr3,  CHANGE )     // Mega256 pin 18,19,20,21
  volatile sl encodercnt=0;
  void isr2() { encodercnt+= digitalReadFast(2)==digitalReadFast(3) ? -1:  1; }
  void isr3() { encodercnt+= digitalReadFast(2)==digitalReadFast(3) ?  1: -1; }

   //------------------------------------------------------------------------------------------
//------------------------------ RELE                         --------------------------------              
   //------------------------------------------------------------------------------------------
  #define R0(...)           r_g(  0 ,##__VA_ARGS__ )   // 
  #define R1(...)           r_g(  1 ,##__VA_ARGS__ )   // 
  #define R2(...)           r_g(  2 ,##__VA_ARGS__ )   // 
  #define R3(...)           r_g(  3 ,##__VA_ARGS__ )   // 
  #define R4(...)           r_g(  4 ,##__VA_ARGS__ )   // 
  #define R5(...)           r_g(  5 ,##__VA_ARGS__ )   // 
  #define R6(...)           r_g(  6 ,##__VA_ARGS__ )   // 
  #define morseAct(...)     r_g(  7 ,##__VA_ARGS__ )   // 
  #define r_last                  7                    // COUNT_ARGS ultimo rele

  #define r_XL_CONTATTI a
  #define r_XL_VALORI
  #define r_XL_DISPOSITIVI R0,R1,R2,R3,R4,R5,R6,morseAct

   //------------------------------------------------------------------------------------------
//------------------------------ TIMER                        --------------------------------tempo massimo 2^31 millisecondi (2.147.483.648  596 ore)---------------------------------------------TIMER
  #define T0(     ...)      t_g(  0 ,##__VA_ARGS__ )  // T0(act,100) → tg(0,act,100) GET_MACRO(act,100,T_2,T_1)(0,act,100) → t_2(0,act,100) → t_act(0,100) 
  #define T1(     ...)      t_g(  1 ,##__VA_ARGS__ )  //                    
  #define tvent1( ...)      t_g(  2 ,##__VA_ARGS__ )  // tvent2r(set,100) → tg(2,set,100) GET_MACRO(set,100,T_2,T_1)(2,set,100) → t_2(2,set,100) → t_set(2,100)
  #define tvent2( ...)      t_g(  3 ,##__VA_ARGS__ )  //    
  #define tvent1r(...)      t_g(  4 ,##__VA_ARGS__ )  // 
  #define tvent2r(...)      t_g(  5 ,##__VA_ARGS__ )  //
  #define Tluce(  ...)      t_g(  6 ,##__VA_ARGS__ )  //
  #define tmarcia(...)      t_g(  7 ,##__VA_ARGS__ )  // tmarcia(res)     → tg(4,res,100) GET_MACRO(res,100,T_2,T_1)(4,res)     → t_1(4,res)     → t_res(4)
  #define tmorse(...)       t_g(  2 ,##__VA_ARGS__ )  // tmarcia(res)     → tg(4,res,100) GET_MACRO(res,100,T_2,T_1)(4,res)     → t_1(4,res)     → t_res(4)
  #define tpunto(...)       t_g(  3 ,##__VA_ARGS__ )  // tmarcia(res)     → tg(4,res,100) GET_MACRO(res,100,T_2,T_1)(4,res)     → t_1(4,res)     → t_res(4)
  #define tlinea(...)       t_g(  4 ,##__VA_ARGS__ )  // tmarcia(res)     → tg(4,res,100) GET_MACRO(res,100,T_2,T_1)(4,res)     → t_1(4,res)     → t_res(4)
  #define tpausa(...)       t_g(  5 ,##__VA_ARGS__ )  // tmarcia(res)     → tg(4,res,100) GET_MACRO(res,100,T_2,T_1)(4,res)     → t_1(4,res)     → t_res(4)
  #define t_last                  7                   // COUNT_ARGS ultimo timer
          //        0,1,2,3,4,5,6,7
  #define t_Micros  0,1,0,0,0,0,0,0                    // 1 = microsecondi, 0= millisecondi

  #define t_XL_CONTATTI a,l,e
  #define t_XL_VALORI   tld
  #define t_XL_DISPOSITIVI T0,T1,tvent1,tvent2,tvent1r,tvent2r,Tluce,tmarcia

//------------------------------ TIMER ATTIVAZIONE OFF        --------------------------------
   //------------------------------------------------------------------------------------------
  #define toff1(...)           f_g(  0 ,##__VA_ARGS__ )  //  
  #define toff2(...)           f_g(  1 ,##__VA_ARGS__ )  //  
  #define f_last                     1                   // COUNT_ARGS ultimo timer
           //       0,1
  #define f_Micros  0,0                        // 1 = microsecondi, 0= millisecondi

  #define f_XL_CONTATTI a,l
  #define f_XL_VALORI   tld
  #define f_XL_DISPOSITIVI toff1,toff2

   //------------------------------------------------------------------------------------------
//------------------------------ TIMER ASINCRONO              --------------------------------
   //------------------------------------------------------------------------------------------
   #define Asin0(...)      a_g(  0 ,##__VA_ARGS__ )   //
   #define Asin1(...)      a_g(  1 ,##__VA_ARGS__ )   // Asin0(act,300,100) → a_g(0,act,300,100) → a_GET_MACRO(__VA_ARGS__,a_3,a_2,a_1)(n, __VA_ARGS__)                  
   #define Asin2(...)      a_g(  2 ,##__VA_ARGS__ )   //
   #define alamp(...)      a_g(  3 ,##__VA_ARGS__ )   //
   #define tictac(...)     a_g(  4 ,##__VA_ARGS__ )   //
   #define a_last                4                    // scrivi qui l'ultimo numero
           //        0,1,2,3,4
   #define a_Micros  0,0,0,0,0                        // 1 = microsecondi, 0= millisecondi

   #define a_XL_CONTATTI a,l,p
   #define a_XL_VALORI   tld,tpd
   #define a_XL_DISPOSITIVI Asin0,Asin1,Asin2,alamp,tictac
   //------------------------------------------------------------------------------------------
//------------------------------ TIMER ASINCRONO CONTATORE    --------------------------------contaimpulsi e contacicli : (pulsemax)=2⟶(pulses)=0,1,2,0,... (cyclemax)=1⟶(cycles)=0,1,0,...  (cyclemax)=0⟶(cycles)=0,1,2,3,...
   //------------------------------------------------------------------------------------------
  #define lampled(  ...)     p_g(  0 ,##__VA_ARGS__ )  //  tempo massimo 2^31 millisecondi (2.147.483.648  596 ore)
  #define lampled2( ...)     p_g(  1 ,##__VA_ARGS__ )  //  lampled(act,tempolavoro,tempopausa,impulsiMax,cicliMax)  cicliMax=0 nessun conteggio cicli                 
  #define Asinp2(   ...)     p_g(  2 ,##__VA_ARGS__ )  //  
  #define XL_timer( ...)     p_g(  3 ,##__VA_ARGS__ )  //  Utilizzato da XL_ intervallo trasmissione dati a Excel; XL_timer(set,50,50,1,0) XL_timer(pulses)==0:invia boolean, XL_timer(pulses)==1 invia ULong
  #define Tsemaforo(...)     p_g(  4 ,##__VA_ARGS__ )  //  Utilizzato da XL_ intervallo trasmissione dati a Excel; XL_timer(set,50,50,1,0) XL_timer(pulses)==0:invia boolean, XL_timer(pulses)==1 invia ULong
  #define morseTim1(...)     p_g(  5 ,##__VA_ARGS__ )  //  Utilizzato da XL_ intervallo trasmissione dati a Excel; XL_timer(set,50,50,1,0) XL_timer(pulses)==0:invia boolean, XL_timer(pulses)==1 invia ULong
  #define morseTim2(...)     p_g(  6 ,##__VA_ARGS__ )  //  Utilizzato da XL_ intervallo trasmissione dati a Excel; XL_timer(set,50,50,1,0) XL_timer(pulses)==0:invia boolean, XL_timer(pulses)==1 invia ULong
  #define p_last                   6                   //  scrivi qui l'ultimo COUNT_ARGS
          //        0,1,2,3,4,5
  #define p_Micros  0,0,0,0,0,0                        // 1 = microsecondi, 0= millisecondi

   #define p_XL_CONTATTI a, l, p
   #define p_XL_VALORI   tld, tpd, pulses, cycles
   #define p_XL_DISPOSITIVI lampled, lampled2, Asinp2, XL_timer, Tsemaforo

   //------------------------------------------------------------------------------------------
//------------------------------ CONTATORE                    --------------------------------              
   //------------------------------------------------------------------------------------------
  #define contaloops(...)   c_g(  0 ,##__VA_ARGS__ )   // 
  #define C1(...)           c_g(  1 ,##__VA_ARGS__ )   // 
  #define C2(...)           c_g(  2 ,##__VA_ARGS__ )   // 
  #define C3(...)           c_g(  3 ,##__VA_ARGS__ )   // 
  #define C4(...)           c_g(  4 ,##__VA_ARGS__ )   // 
  #define C5(...)           c_g(  5 ,##__VA_ARGS__ )   // 
  #define C6(...)           c_g(  6 ,##__VA_ARGS__ )   // 
  #define C7(...)           c_g(  7 ,##__VA_ARGS__ )   // 
  #define c_last                  7                    // scrivi qui COUNT_ARGS ultimo contatore_cronometro

   //------------------------------------------------------------------------------------------
//------------------------------ CRONOMETRO                   --------------------------------              
   //------------------------------------------------------------------------------------------
  #define crono(...)     m_g(  0 ,##__VA_ARGS__ )   // crono(reset);crono(start);crono(stop);crono(start);a=crono(time);crono(stop);b=crono(stoptime)
                                                    // leggere time solo tra start e stop.  stoptime fermo allo stop precedente
  #define m_last                  0                    

//------------------------------ ENCODER                   ----------------------------------- 
    #define encoder1(...)    e_g(0 ,##__VA_ARGS__)
    #define encoder2(...)    e_g(1 ,##__VA_ARGS__)
    #define e_last               1                    // Limite massimo 7

//------------------------------ TRASMISSIONE EXCEL           --------------------------------

   #define XL_BOOL_DISPOSITIVI o, i, r, t, a, p  // iniziali dei dispositivi di cui trasmettere i valori booleani o CONTATTI

   #define XL_NUM_DISPOSITIVI  t, a, p           // iniziali dei dispositivi di cui trasmettere i valori UNSIGNED LONG


