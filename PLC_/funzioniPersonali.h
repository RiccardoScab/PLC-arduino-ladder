// clicca qui e poi      ctrl k1 o K2 nascondi       ctrl kj scopri tutto 

// --------------------DEFINISCI LE VARIABILI GLOBALI QUI ---------------------
  ul cronostart;    ui cronocont=0;                                        // cronometro 
  sl encoder2cont=0; bl encoder2change=0;
  f_const uc sarray2[]={50,100,120,250,200,led1()};     // f_get(sarray2,n);

  funcptr<void> funzioneSelezionata=funzionevuota;


// --------------------SEQUENZE              ---------------------
  inline void lampeggianotutti(){ tictac(act,100,100);  I__ tictac(l) ___ Act(led0,led1,led2,led3,led4); O__  }

  void sequenza1(uc n){ SELECTOR(n    ,           // non utilizza memoria Ram come un array ed è piu flessibile. // lo switch è veloce come il goto
       Act(led0,     led2          )  ,           // SELECTOR parte da n=0 e accetta fino a 20 codici, n=19
       Act(     led1,     led3     )  ,           // 
       Act(          led2,     led4)  ,           // oa|=(1ULL<<led2); oa|=(1ULL<<led4); -> oa|=20
       Act(     led1,led2,led3     )  ,           // 
       Act(led0,led1,led2,led3,led4)  ) }         // queste macro vengono espanse completamente , nessun utilizzo di ram , il compilatore ottimizza in una singola scrittura nella variabile oa|=31 -> massima velocità
  void sequenza2(uc n){ SELECTOR(n    ,           //            
       led0(act);                     ,           // 
       led1(act);                     ,           // 
       led2(act);                     ,           // 
       led3(act);                     ,           // 
       lampeggianotutti();            ) }         // 

// ------------------- CLASSE STELLA TRIANGOLO ------------------contiene la logica per realizzare l'avviamento stella triangolo
  class motore_stellatriangolo { public:
      uc timer,timer2,stella1,stella2,delta;ul time,time2; bl arresto=0,marcia=0;
      motore_stellatriangolo(uc timer,ul time,uc timer2,ul time2,uc stella1,uc stella2,uc delta):timer(timer),timer2(timer2),stella1(stella1),stella2(stella2),delta(delta),time(time),time2(time2) {}
  void act() {
        I__ !arresto && (marcia || t_a(timer)) ___ t_act(timer,time);                 
        L__ t_l(timer)                         ___ o_act(stella1); o_act(stella2);  
        L__ t_e(timer)                         ___ t_act(timer2,time2);              
        L__ t_e(timer) __ t_e(timer2)          ___ o_act(delta);                  
        O__ }
  bl a(){ return t_a(timer); }
  bl l(){ return t_e(timer); }
  };

// ------------------- TEST BOOLEANI SEMPLICI  --------------------------
 void Esempi_di_prova(){

 I__  marcia1(e) || stop1(e)                     ___ led0(act) _n_ led1(act)                       // led1 si attiva se i due pulsanti sono premuti, led2 quando nessuno è premuto. stop1 è NC e negato , quando è premuto = 1
 L__ !stop2(e) __ ( marcia2(e) || led2(a) )      ___ led2(act)                                     // marcia1 arresto classico
 L__ stop1(e)                                    ___ Res(led3,led4)                                // spegni reset vince sempre sul set e sul act
 L__ marcia1(er)                                 ___ led3(set)  led4(tgl)                          // accendi  // accendi spegni
 O__ 

 }
// ------------------- TIMERS                --------------------------
 void timers(){ static bool init=1;
 I__ marcia1(er) || marcia1(ef) || T0(l)         ___ T0(act,1000) led0(act)                        // alla pressione e al rilascio di marcia1 il led si accende per 1 secondo
 
 L__ marcia1(e)                                  ___ toff1(act,1000)                               // timer off alla disattivazione entra in lavoro per 1 secondo 
 L__ toff1(a)                                    ___ led1(act)                                     // si accende con marcia e si spegne dopo 1 secondo dal suo rilascio
 L__ toff1(l)                                    ___ led2(act)                                     // si accende per un secondo dal riascio di marcia

 L__ marcia1(er)                                 ___ T1(seto,100)                                  // lo setta in versione oscillante
 L__ T1(lr)                                      ___ led3(tgl)                                     // led3 lampeggia
 L__ marcia1(ef)                                 ___ Res(T1,led3)                                  // al rilascio di marcia1 spegne tutto

 L__ marcia1(e)                                  ___ Asin0(act,200,300)                            // l per 200ms p per 300ms
 L__ Asin0(l)                                    ___ led4(act)                                     // il led lampeggia
                                                                                                   #define leds led0(act),led1(act),led2(act)
 L__ marcia2(er)                                 ___ Res(T0,toff1,T1,Asin0,led0,led1,led2,led3,led4) // resetta tutto azione drastica, non si usa normalemnte.
 L__ marcia2(e)                                  ___ lampled(act,100,100,4,2)                      // 3 cicli di 5 impulsi ...
 L__ lampled(l)                                  ___ SELECTOR(lampled(cycles),leds)                // i cycles (0->2) sceglie il led da accendere 
 O__ 
 init=0; }
                                                                                                   #undef leds
// ------------------- SEQUENZE              --------------------------
 void sequenze(){
 #define LedAllFlash tictac(act,100,100)                               \
                     I__ tictac(l) ___ Act(led0,led1,led2,led3,led4) O__
 
 #define Led_seq1 ({ LedAllFlash                    }), /*riga complessa va chiusa tra le parentesi ({...}) */\
                  ({ Act(led0,     led2           ) }),        \
                  ({ Act(     led1,     led3      ) }),        \
                  ({ Act(          led2,     led4 ) }),        \
                  ({ Act(     led1,led2,led3      ) }),        \
                  ({ Act(led0,led1,led2,led3,led4 ) })          // queste macro vengono espanse completamente , nessun utilizzo di ram
 
 #define Led_seq2 Act(led0                     ),               /*riga semplice non servono le ({...}) */   \
                  Act(     led1                ), \
                  Act(          led2           ), \
                  Act(               led3      ), \
                  Act(                   led4  ), \
                  lampeggianotutti();
 
 I__ marcia1(e)                    ___ lampled(act,600,1,5,1)                        // attiva asincono con contatori 6 impulsi 2 cicli
     I__ lampled(l)                ___ SELECTOR( lampled(cycles)           ,         // 0 , 1
                                        SELECTOR(lampled(pulses), Led_seq1),         // cycles==0  → Led_seq1               
                                        SELECTOR(lampled(pulses), Led_seq2))         // cycles==1  → seg2
 O__ O__                                                                             //
                                                                                     #undef Led_seq1
                                                                                     #undef Led_seq2
                                                                                     #undef LedAllFlash
 I__ marcia2(e)                   ___  lampled(act,600,1,4,1)                        // attiva asincono con contatori 5 impulsi 2 cicli
     I__ lampled(l)               ___ SELECTOR( lampled(cycles)==0       ,           // lampeggia 4 x 2 volte
                                               sequenza1(lampled(pulses)),           //
                                               sequenza2(lampled(pulses)))           //
 O__ O__
 }

// ------------------- ENCODER               --------------------------
  void encoder(){                      // ideale per encoder meccanico lento con antirimbalzo 3 ms
  I__ IN7(e)                       ___ encoder1(a)
  L__ IN8(e)                       ___ encoder1(b)
  L__ IN9(er)                      ___ encoder1(cont)=0;
  L__ encoder1(cont)==200          ___ sp("alto");
  L__ encoder1(cont)==100          ___ sp("basso");
  O__ }
// ------------------- SEMAFORO              --------------------------
   void semaforo(){
    I__ !Tsemaforo(a)                 ___ Tsemaforo(set,1000,1,5,-1)
                                                                           #define T(a) Tsemaforo(time,a,1)
    L__ Tsemaforo(lr)                 ___ SELECTOR(Tsemaforo(pulses) ,   // tabella tempi
                                           FUN_ARGS_LIST(T,1,  1000  ,   // 0 rosso1  rosso2
                                                              20000  ,   // 1 verde1  rosso2 pedo1
                                                               5000  ,   // 2 giallo1 rosso2 pedo1 lampeggia
                                                               1000  ,   // 3 rosso1  rosso2
                                                              30000  ,   // 4 rosso1  verde2
                                                               5000  ))  // 5 rosso1  giallo2
    L__ Tsemaforo(lr)                 ___ SELECTOR(Tsemaforo(pulses) ,   // tabella tempi
                                                          T(   1000 ),   // 0 rosso1  rosso2
                                                          T(  20000 ),   // 1 verde1  rosso2 pedo1
                                                          T(   5000 ),   // 2 giallo1 rosso2 pedo1 lampeggia
                                                          T(   1000 ),   // 3 rosso1  rosso2
                                                          T(  30000 ),   // 4 rosso1  verde2
                                                          T(   5000 ))   // 5 rosso1  giallo2
                                                                           #undef T
    L__ Tsemaforo(a)                  ___ SELECTOR( Tsemaforo(pulses) ,  // 
                                          FUN_ARGS_LIST(Act,2,           //
                                                    rosso1,  rosso2  ,   // 0 Act(rosso1,rosso2) ,
                                                    verde1,  rosso2  ,   // 1
                                                   giallo1,  rosso2  ,   // 2
                                                    rosso1,  rosso2  ,   // 3
                                                    rosso1,  verde2  ,   // 4
                                                    rosso1, giallo2  ))  // 5
    L__ Tsemaforo(a)                  ___ SELECTOR( Tsemaforo(pulses),   // 
                                               Act( rosso1,  rosso2 ),   // 0 Act(rosso1,rosso2) ,
                                               Act( verde1,  rosso2 ),   // 1
                                               Act(giallo1,  rosso2 ),   // 2
                                               Act( rosso1,  rosso2 ),   // 3
                                               Act( rosso1,  verde2 ),   // 4
                                               Act( rosso1, giallo2 ))   // 5
    O__ 
   }
// ------------------- 2 VENTILATORI  classe --------------------------
  motore_stellatriangolo 
   vent1(tvent1(),2000, tvent1r(),300, vent1star1(),vent1star2(),vent1delta()),  // timer,tempo, time2,tempo2, rele star1, rele star2, rele delta
   vent2(tvent2(),1500, tvent2r(),300, vent2star1(),vent2star2(),vent2delta());
  
  void ventilatori1(){
       vent1.arresto = emergenza(e) || termico1(e) || stop1(e);    // tutti NC e negati quando uno viene premuto arresto = true
       vent1.marcia  = (marcia1(e)  __ !vent2.a()) || tmarcia(er); // ventilatore2 avviato inibisce la marcia, marcia automatica quando vent2 è avviato
       vent1.act();                                                // applica la logia stella triangolo
       vent2.arresto = emergenza(e) || termico2(e) || stop2(e);
       vent2.marcia = (marcia2(e)   __ !vent1.a()) || tmarcia(er);
       vent2.act();
      I__ vent1.l() || vent2.l()     ___ tmarcia(act,1000)        // il ventilatore 2 parte un secondo dopo il primo ( tenendo premuto stop non si avvia )
      L__ vent1.arresto              ___ ledstop1(act)      
      L__ vent2.arresto              ___ ledstop2(act) 
      O__     
            }
// ------------------- 2 VENTILATORI  ladder --------------------------
  void ventilatori2(){ bl arresto,marcia;                                                       //  
   arresto = emergenza(e) || termico1(e) || stop1(e);                                           // tutti NC e negati
   marcia  = (marcia1(er) __ !tvent2(a)) || tmarcia(er);                                          // tutti NO
   I__ arresto                                      ___ ledstop1(act)                           
   _N_ marcia || tvent1(a)                          ___ tvent1(act,3000)                        // ventilatore 1
       I__ tvent1(l)                                ___ Act(vent1star1,vent1star2)     
       L__ tvent1(e)                                ___ tvent1r(act,200)                     
           I__ tvent1r(e)                           ___ vent1delta(act)                         // avviamento completato provvedere interblocco meccanico o elettrico con vent1star2
   O__ O__ O__
   arresto = emergenza(e) __ termico2(e) __ stop2(e);                                            //
   marcia  = (marcia2(er) __ !tvent1(a)) || tmarcia(er) ;                                          // 
   I__ arresto                                      ___ ledstop2(act)                            //
   _N_ marcia || tvent2(a)                          ___ tvent2(act,3000)                         // ventilatore 2
       I__ tvent2(l)                                ___ Act(vent2star1,vent2star2)               //
       L__ tvent2(e)                                ___ tvent2r(act,200)                         // permette lo sgancio dei contatti
           I__ tvent2r(e)                           ___ vent2delta(act)                          //
       O__ O__                                                                                   //
   L__ vent1delta(a)||vent2delta(a)                 ___ tmarcia(act,2000)                        // il secondo ventilatore parte 2 sec dopo il primo
   O__
       } 
 

// ------------------- 2 VENTILATORI  SET RESET ----------il piu veloce e semplice
  void ventilatori3(){                                                                          //
    I__  emergenza(e) || termico1(e) || stop1(e)     ___ Res(tvent1,tvent1r)  ledstop1(act)    // tutti NC e negati, il reset prevale sempre sul set
    _N_  (marcia1(er) __ !tvent2(a)) || tmarcia(er)    ___ tvent1(set,3000)                       // tutti NO
    _N_  tvent1(l)                                   ___ Act(vent1star1,vent1star2)             //
    _N_  tvent1(e)                                   ___ tvent1r(act,300)                       // ritardo scambio stella triangolo
         I__ tvent1r(e)                              ___ vent1delta(act)                        //
         O__                                                                                    //
    L__  emergenza(e) || termico2(e)  || stop2(e)    ___ Res(tvent2,tvent2r) ledstop2(act)     // il reset prevale sempre sul set
    _N_  (marcia2(er) __ !tvent1(a)) || tmarcia(er)    ___ tvent2(set,3000)                       //
    _N_  tvent2(l)                                   ___ Act(vent2star1,vent2star2)             //
    _N_  tvent2(er)                                  ___ tvent2r(set,300)                       // ritardo scambio stella triangolo
         I__ tvent2r(e)                              ___ vent2delta(act)                        //
         O__                                                                                    //
    L__ vent1delta(a) || vent2delta(a)               ___ tmarcia(act,2000)                      //
    O__                       
   }
// ------------------- morse                    ----------
 flash(char, morse_ciao[])  ={ "ciao" };
 flash(char, morse_hello[]) ={ "hello world" };
 flash(char, morse_numeri[])={ "0 1 2 3 4 5 6 7 8 9" };
 void morse_fun(){
  I__ marcia1(er)        ___ morse1.set(morse_numeri,1); // ..,1) il messaggio è in Flash;  ..,0 è in Ram
  L__ marcia2(er)        ___ morse2.set(morse_hello,1);
  L__ marcia1(ef)        ___ morse1.reset();
  L__ marcia2(ef)        ___ morse2.reset();
  L__ morseTim1(l)       ___ led1(act);
  L__ morseTim2(l)       ___ led2(act);
  O__           }

//-------------------- menu                     ----------
                                                             #define PRINT(v)  {Sp(F(v)); return 1;}
 bl menu_s()      PRINT("-------- Serial In String : "       )   //
 bl menu_0()      PRINT("0     . menù PLCclassIst"           )   // 24
 bl menu_1()      PRINT("1     . timerCiclici"               )   // 20
 bl menu_2()      PRINT("2     . timerEcontatori"            )   // 23
 bl menu_3()      PRINT("3     . provaMorse"                 )   // 18
 bl menu_4()      PRINT("4     . MorseMultipli"              )   // 21
 bl menu_5()      PRINT("5     . lampeggi"                   )   // 16
 bl menu_6()      PRINT("6     . prova il cronometro"        )   // 27
 bl menu_7()      PRINT("7     . lampeggi"                   )   // 16
 bl menu_8()      PRINT("8     . Trasmetti ad Excel:"        )   // 27
 bl menu_T100()   PRINT("/T100 . Tciclo invio excel"         )   // 26
 bl menu_B96()    PRINT("/B96  . riavvia seriale 9600 baud"  )   // 33
 bl menu_B11()    PRINT("/B11  . riavvia seriale 115200 baud")   // 35
                                                             #undef PRINT
 bl menuPrint() { 
  SELECTORETURN(seriale.c  ,
             menu_s()           ; ,
             seriale.printdata(); ,
             menu_0()           ; ,
             menu_1()           ; ,
             menu_2()           ; ,
             menu_3()           ; ,
             menu_4()           ; ,
             menu_5()           ; ,
             menu_6()           ; ,
             menu_7()           ; ,
             menu_8()           ; ,
             menu_T100()        ; ,
             menu_B96()         ; ,
             menu_B11()         ; )
                        return 1; }               // fine trasmissione

 bool seriale9600()  { Sp(F(" riavvio seriale a 9600 baud"));   seriale.init(9600);  return 1;} // in questo modo ,la seriale riavvia dopo aver inviato tutto
 bool seriale115200(){ Sp(F(" riavvio seriale a 115200 baud")); seriale.init(115200);return 1;}

                                                      #define  If(a,b)       if(strcmp(seriale.in,a)==0){ b }    // Gestione input:strcmp e strncmp sono case‑sensitive. Se vuoi maggiore robustezza, valuta strcasecmp.
                                                      #define eIf(a,b)  else If(a,b)
                                                      #define   s(a,b)  seriale.print(menu_##a); funzioneSelezionata=b;
 void selectMenu(){
    seriale.print(menu_s); seriale.print(seriale.in);
      If( "0",  sp(menuPrint); )
 //   eIf( "1",  s(1, timerCiclici    )) 
 //   eIf( "2",  s(2, timerEcontatori )) 
 //   eIf( "3",  s(3, provaMorse      )) 
 //   eIf( "4",  s(4, MorseMultipli   )) 
 //   eIf( "5",  s(5, lampeggi        )) 
 //   eIf( "6",  s(6, provacrono      )) 
 //   eIf( "7",  s(7, lampeggi        )) 
 //   eIf( "8",  XL.tgl;   XL.stampadati(); )  // attiva disattiva
    eIf("/B96", sp(seriale9600  ); )           //
    eIf("/B11", sp(seriale115200); )           //
    else if(strncmp(seriale.in, "/T",2)==0){ ul t=atol(seriale.in+2); XL_timer(time,t,t); } // converte in long ed imposta il timer di trasmissione
 }
                                                        #undef If
                                                        #undef eIf
                                                        #undef   s
