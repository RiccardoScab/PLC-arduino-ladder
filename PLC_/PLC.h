// clicca qui e poi      ctrl+k2 k1 nascondi      ctrl+kj scopri tutto 
//---------------------------- Define TYPE               ----------------------------------- 
    #if i_last   < 8
      typedef uint8_t  ingressi_t;
    #elif i_last < 16
      typedef uint16_t ingressi_t;
    #elif i_last < 32
      typedef uint32_t ingressi_t;
    #else
      typedef uint64_t ingressi_t;
    #endif
    
    #if o_last   < 8
      typedef uint8_t  uscite_t;
    #elif o_last < 16
      typedef uint16_t uscite_t;
    #elif o_last < 32
      typedef uint32_t uscite_t;
    #else
      typedef uint64_t uscite_t;
    #endif
    
    #if r_last   < 8
      typedef uint8_t  rele_t;
    #elif r_last < 16
      typedef uint16_t rele_t;
    #elif r_last < 32
      typedef uint32_t rele_t;
    #else
      typedef uint64_t rele_t;
    #endif
    
    #if t_last   < 8
      typedef uint8_t  timers_t;
    #elif t_last < 16
      typedef uint16_t timers_t;
    #elif t_last < 32
      typedef uint32_t timers_t;
    #else
      typedef uint64_t timers_t;
    #endif
  
    #if f_last   < 8
      typedef uint8_t  timeroff_t;
    #elif f_last < 16
      typedef uint16_t timeroff_t;
    #elif f_last < 32
      typedef uint32_t timeroff_t;
    #else
      typedef uint64_t timeroff_t;
    #endif
  
    #if a_last   < 8
      typedef uint8_t  asincroni_t;
    #elif a_last < 16
      typedef uint16_t asincroni_t;
    #elif a_last < 32
      typedef uint32_t asincroni_t;
    #else
      typedef uint64_t asincroni_t;
    #endif
    
    #if p_last   < 8
      typedef uint8_t asincronp_t;
    #elif p_last < 16
      typedef uint16_t asincronp_t;
    #elif p_last < 32
      typedef uint32_t asincronp_t;
    #else
      typedef uint64_t asincronp_t;
    #endif
    
    #if c_last   < 8
      typedef uint8_t  contatori_t;
    #elif c_last < 16
      typedef uint16_t contatori_t;
    #elif c_last < 32
      typedef uint32_t contatori_t;
    #else
      typedef uint64_t contatori_t;
    #endif
    
   ul     PLC_millis=0,      PLC_micros=0;
//---------------------------- INGRESSI                  ----------------------------------- 
    ingressi_t ia=0,iar=0,iaf=0, ie=0,ier=0,ief=0, itim=0; uc iTD[i_last]={}; f_const uc itime[]={ i_Time };  // tempo antirimbalzo ms
    #define i_pin(x)          ARRAY(x,    i_Pin )               // macroarray con la lista di valori i_Pin
    #define i_negato(x)       ARRAY(x,    i_Negato)             // macroarray con la lista di valori i_Negato

    #define i_readAll         FUN_ARGS(i_read, 1, ENUM0(i_last) ) // i_readall(0,1,2,3...) → i_read(0); i_read(1); ...  
    #define i_read(n)         if(digitalReadFast(i_pin(n))!=i_negato(n)) bitSet(ia,n);// (1)→if(digitalReadFast(i_pin(1))!=i_negato(1)) bitSet(ia,1);→ if(digitalReadFast(5)!=0) bitSet(ia,1);
                                                                //
    #define i_pullup(x)       ARRAY(x,    i_Pullup)             // macroarray con la lista di valori i_Pullup
    #define i_pinmode         i_pinMode(ENUM0(i_last))          // 0,1,2,3,...,i_last
    #define i_mode(n)         pinModeFast(i_pin(n),i_pullup(n)?INPUT_PULLUP:INPUT);   // i_pullup(n)?INPUT_PULLUP:INPUT viene rosolto a compile time pinModeFast(13,INPUT_PULLUP);
    #define i_pinMode(...)    FUN_ARGS(i_mode, 1, __VA_ARGS__)  // i_mode(0); i_mode(1); ...
                                                                //
    #define i_e(n)            bit(ie ,n)                        // ingresso  end debounce 
    #define i_er(n)           bit(ier,n)                        // ingresso  end debounce   fronte di salita /rising
    #define i_ef(n)           bit(ief,n)                        // ingresso  end debounce   fronte di discesa/falling
    #define i_echange(n)      bit(ier,n)||bit(ief,n)            // ingresso  end debounce   fronte di salita /rising
    #define i_a(n)            bit(ia ,n)                        // ingresso  attivo o istantaneo
    #define i_ar(n)           bit(iar,n)                        // ingresso  attivo o istantaneo fronte di salita /rising
    #define i_af(n)           bit(iaf,n)                        // ingresso  attivo o istantaneo fronte di discesa/falling
    #define i_achange(n)      bit(iar,n)||bit(iaf,n)            // ingresso  attivo o istantaneo fronte di salita /rising
    #define i_time(n)         itime[n]                          // tempo antirimbalzo
    #define i_g(...)          macronumargs(i_g , __VA_ARGS__)   // select la macro corretta in base al COUNT_ARGS degli elementi
    #define i_g1(n)           n                                 //
    #define i_g2(n,v)         i_##v(n)                          //
                                                                //
    #define iis(pin,pinmode,isr,isrmode) pinMode(pin,pinmode);attachInterrupt(digitalPinToInterrupt(pin),isr,isrmode);
//---------------------------- USCITE                    ----------------------------------- 
    uscite_t    oset=0,ores=0, oT=0, oO=0, oA=0,oa=0,oar=0,oaf=0,                        oo=0;                                                    // out
    #define o_scriviUscite    FUN_ARGS_ENUM(o_wrt, o_pins )     // o_wrt(0,13) o_wrt(1,14) o_wrt(2,15) ... digitalWriteFast(13, bitRead(oA,0)); digitalWriteFast(14, bitRead(oA,1)); ... 
    #define o_pinmode         FUN_ARGS(pin_OUTPUT, 1, o_pins )  // pin_OUTPUT(0,13) pin_OUTPUT(1,14) ...   pinModeFast(13,OUTPUT); pinModeFast(14,OUTPUT);
    #define o_wrt(num,pin)    digitalWriteFast(pin, bitRead(oA,num)); // se pin è costante espande all'incirca in if ((oA>>num)& 0x01) PORTD|=0x80; else PORTD &= ~0x80; molto veloce 6→8 clock.
    #define pin_OUTPUT(pin)   pinModeFast(pin,OUTPUT);          //
    #define o_a(n)           (bit(oa ,n))                       // out
    #define o_ar(n)          (bit(oar,n))                       // 
    #define o_af(n)          (bit(oaf,n))                       // 
    #define o_achange(n)     (bit(oar,n)||bit(oaf,n))           // 
    #define o_act(n)          bitSet(oA    ,n);                 // 5 clock
    #define o_set(n)          bitSet(oset  ,n);                 // 
    #define o_res(n)          bitSet(ores,n);                   // 
    #define o_tgl(n)          bitSet(oO    ,n);                 // 
    #define o_sta(n,s)        bitWrite(oO  ,n,s);               // 
    #define o_g(...)          macronumargs(o_g_, __VA_ARGS__)   // select la macro corretta in base al COUNT_ARGS degli elementi
    #define o_g_1(n)          n                                 // es: led1() → 2
    #define o_g_2(n,v)        o_##v(n)                          // es: led1(act) → bitSet(oA, 2)
    #define o_g_3(n,v,s)      o_##v(n,s)                        // es: led1(sta,1) → bitWrite(oA,2,1)
                                                                //
                                                                //
                                                                // Comparatori con soglia
//---------------------------- INGRESSI ANALOGICI        ----------------------------------- 
     const  uc aipin[]          ={ ai_Pin };                    // pin analogici
            ui aiv[ailast+1]    ={},                             // letto
               aimedia[ailast+1]={},                             // medio
               aiexp[ailast+1]  ={};                             // filtrato
            uc ain=0;                                            // indice n
                                                                    #define LOWBOUND(r,h) ((r)-(h))       
                                                                    #define UPPBOUND(r,h) ((r)+(h))
                                                                    #define LEVELScnt(a)  COUNT_ARGS(ai_LEVELS_##a(LOWBOUND)) // conta i LEVELS : → COUNT_ARGS(ai_LEVELS_0(LOWBOUND)) → 13     ai_LEVELS_0(LOWBOUND) è una lista di valori 10,20,30,40,50 COUNT_ARGS li conta .
                                                                    #define LB(a)    ai_LEVELS_##a(LOWBOUND)             // lista dei confini inferiori  potenz1_LEVELS(LOWBOUND)
                                                                    #define UB(a)    ai_LEVELS_##a(UPPBOUND)             // lista dei confini superiori
    const   uc aiLevelscnt[]    ={FUN_ARGS_LIST(LEVELScnt,1,ENUM0(ailast))};// applica LEVELScnt a discreti → LEVELScnt(potenz1),LEVELScnt(potenz2) → 13,8
            uc ailevel[ailast+1]={};                             // valore del livello (max 255),
            ui aiIB[ailast+1]   ={};                             // Index Bounds, aiIB[1] posizione inizio dati del potenz2 in aiLB,aiUB
    f_const si aiLB[]           ={FUN_ARGS_LIST(LB,1,ENUM0(ailast))};       // applica listaLB   a discreti → LB(0),LB(1),LB(1) → LEVELS_0(LOWBOUND) → LOWBOUND(0,20),LOWBOUND(78,20)LOWBOUND(156,20),... → -20,58,126,...
    f_const si aiUB[]           ={FUN_ARGS_LIST(UB,1,ENUM0(ailast))};       // applica listaUB   a discreti
                                                                    #undef LB
                                                                    #undef UB
    inline ui ai_val(uc n)       {return aiv[n];}                // valore letto memorizzato 0–1023
    inline ui ai_val(uc n,uc s)  {return aiv[n]*s/1023;}         // valore letto memorizzato scalato in unità fisiche t=temperatura(val,200)
    inline ui ai_media(uc n)     {return aimedia[n];}            // media mobile
    inline ui ai_media(uc n,uc s){return (aimedia[n]*s)/1023;}   // media mobile scalato in unità fisiche
    inline ui ai_exp(uc n)       {return aiexp[n];}              // filtro esponenziale
    inline ui ai_exp(uc n,uc s)  {return (aiexp[n]*s)/1023;}     // filtro esponenziale scalato in unità fisiche
    inline uc ai_level(uc n)     {return ailevel[n];}            //
    inline uc ai_pin(uc n)       {return aipin[n];}              // pin
    #define   ai_g(...)           macronumargs(ai_g, __VA_ARGS__)// select la macro corretta in base al COUNT_ARGS degli elementi
    #define   ai_g1(n)            n                              // 
    #define   ai_g2(n,v)          ai_##v(n)                      // 
    #define   ai_g3(n,v,a)        ai_##v(n,a)                    // 
    #define   ai_g4(n,v,a,b)      ai_##v(n,a,b)                  // 
                                                                 //
                                                                 //
    inline void ai_aggiorna(){
           ui &v=aiv[ain], &m=aimedia[ain], &e=aiexp[ain]; uc& l=ailevel[ain];
           v=analogRead(aipin[ain]);                            // lettura ingresso
           m =(m*3+v)>>2;                                       // media mobile diviso 4
           e+=(v-e)>>2;                                         // filtro exp α=0.25
           const uc max = aiLevelscnt[ain] - 1;                 //
           const ui lb  = f_get(aiLB, aiIB[ain]+l+1);           //
           const ui ub  = f_get(aiUB, aiIB[ain]+l-1);           //
           if(l<max && m>=lb) l++; else if(l>0 && m<=ub) l--;   // calcola il livello
           rollbeat(ain,0,ailast);}                             //

      void ai_IBmake(){for(uc i=0;i<ailast;i++){aiIB[i+1]=aiIB[i]+aiLevelscnt[i];}} // Index Bounds 13,10,10,1 →0,13,23,33
//---------------------------- USCITE  ANALOGICHE        ----------------------------------- 
            uc      aov[aolast]={},                                                   // valore corrente
                aoramp[aolast]={},                                                   // rampa
                aostep[aolast]={};                                                   // passo di incremento
           uc   aon           =0;                                                    // indice lettura
    inline void ao_val (uc n,uc v)          { aov[n]=v;                            } // ultimo valore impostato 0→255   motor1(val,30);   a=motor1(val)
    inline uc   ao_val (uc n)               { return aov[n];                       } //
    inline void ao_set (uc n,uc val)        { analogWrite(aopin[n],val);           } // PWM diretto
    inline void ao_pct (uc n,uc pct)        { analogWrite(aopin[n],(pct*255)/100); } // percentuale 0–100
    inline void ao_ramp(uc n,uc tgt,uc step){ aoramp[n]=tgt; aostep[n]=step;       } // ramp generator
    inline uc   ao_pin (uc n)               { return aopin[n];                     } //
    #define     ao_g(...)                     macronumargs(ao_g , __VA_ARGS__)       // select la macro corretta in base al COUNT_ARGS degli elementi
    #define     ao_g1(n)                      n                                      // 
    #define     ao_g2(n,v)                    ao_##v(n)                              // 
    #define     ao_g3(n,v,a)                  ao_##v(n,a)                            // 
    #define     ao_g4(n,v,a,b)                ao_##v(n,a,b)                          // 
                                                                                        #define v    aov[aon]
                                                                                        #define ramp aoramp[aon]
                                                                                        #define step aostep[aon]
                                                                                        #define pin  aopin[aon]
    inline void ao_aggiorna(){                                                       //
         if(v<ramp) v+=step; else if(v>ramp) v-=step;                                // 
        analogWrite(pin, v); rollbeat(aon,0,aolast); }                               // Aggiorna un’uscita per ciclo
                                                                                        #undef v   
                                                                                        #undef ramp
                                                                                        #undef step
                                                                                        #undef pin
//---------------------------- RELE                      ----------------------------------- 
    rele_t  rset=0,rres=0, rT=0, rO=0, rA=0,ra=0,rar=0,raf=0, ro=0; 
    #define r_a(n)           (bit(ra ,n))                       // rele  a attivato
    #define r_ar(n)          (bit(rar,n))                       // 
    #define r_af(n)          (bit(raf,n))                       // 
    #define r_achange(n)     (bit(rar,n)||bit(raf,n))           // 
    #define r_act(n)          bitSet(rA    ,n);                 // act attiva
    #define r_set(n)          bitSet(rset  ,n);                 // set settaggio
    #define r_res(n)          bitSet(rres,n);                   // res reset
    #define r_tgl(n)          bitSet(rO    ,n);                 // tgl toggle commutazione passo passo
    #define r_g(...)       macronumargs(r_g , __VA_ARGS__)   // select la macro corretta in base al COUNT_ARGS degli elementi
    #define r_g1(n)           n                                 //
    #define r_g2(n,v)         r_##v(n)                          //
                                                                //
                                                                //
                                                                //

//---------------------------- TIMER                     ----------------------------------- 
    timers_t    tset=0,tres=0, tO=0, tA=0,ta=0,tar=0,taf=0, te=0,ter=0; ul tTL[t_last]={}, tEND[t_last]={};
    timers_t    tmicros=bitsToNumRev( t_Micros );

    #define     t_a(n)            (bit(ta ,n))                                       // timer a attivato
    #define     t_ar(n)           (bit(tar,n))                                       // 
    #define     t_af(n)           (bit(taf,n))                                       // 
    #define     t_achange(n)      (bit(tar,n)||bit(taf,n))                           // 
    #define     t_l(n)            (bit(ta,n) & !bit(te,n))                           // tempo lavoro in esecuzione
    #define     t_lr(n)           (bit(tar,n))                                       // 
    #define     t_lf(n)           (bit(ter,n))                                       // 
    #define     t_lchange(n)      (bit(tar,n)||bit(ter,n))                           // 
    #define     t_e(n)            (bit(te ,n))                                       // e end tempo
    #define     t_er(n)           (bit(ter,n))                                       // 
    #define     t_ef(n)           (bit(taf,n))                                       // 
    #define     t_echange(n)      (bit(ter,n)||bit(taf,n))                           // 
    #define     t_res(n)           bitSet(tres,n);                                   //
    #define     t_tl(n)            tTM[n]                                            // tempo impostato                
    #define     t_micros(n)       (bit(tmicros,n))                                   // microsecondi = true   
    #define     t_now(n)          (bit(tmicros,n)?PLC_micros:PLC_millis)             //
    #define     t_g(...)           macronumargs(t_g , __VA_ARGS__)                   // select la macro corretta in base al COUNT_ARGS degli elementi
    #define     t_g1(n)            n                                                 //
    #define     t_g2(n,v)          t_##v(n)                                          //
    #define     t_g3(n,v,t)        t_##v((n), (ul)(t))                               //
    #define     t_time(n,t)        t_Time(n,t);
    #define     t_act(...)         t_Act(__VA_ARGS__);
    #define     t_set(...)         t_Set(__VA_ARGS__);
    #define     t_seto(...)        t_Seto(__VA_ARGS__);
    void        t_Time(uc n,ul t){ ifb(ta) tEND[n]+=t-tTL[n];  tTL[n]=t;          }  // se già avviato modifica scadenza, imposta il tempo t
    inline void t_Act(uc n)      { b1(tA)                                         }  // tempi gia memorizzati con _time , attiva
    inline void t_Act(uc n,ul t) { b1(tA)           ifnb(ta) tTL[n]=t;            }  // se non avviato imposta il tempo , attiva
    inline void t_Set(uc n)      { b1(tset)                                       }  // tempi gia memorizzati con _time , set
    inline void t_Set(uc n,ul t) { b1(tset)         ifnb(ta) tTL[n]=t;            }  // se non avviato imposta il tempo , set
    inline void t_Seto(uc n)     { b1(tset) b1(tO)                                }  // tempi gia memorizzati con _time , Timer set oscillante: si spegne e si riavvia il loop successivo.
    inline void t_Seto(uc n,ul t){ b1(tset) b1(tO)  ifnb(ta) tTL[n]=t;            }  // Timer set oscillante ra riavvia a fine tempo .
           ul   t_tld (uc n)     { return t_l(n)?tEND[n]-t_now(n): tTL[n];        }  // tempo lavoro decrescente countDown
           ul   t_tlc (uc n)     { return t_l(n)?tTL[n]-(tEND[n]-t_now(n)):0;     }  // tempo lavoro crescentee , passato
   

//---------------------------- TIMER ATTIVAZIONE OFF     ----------------------------------- 
    timeroff_t  fset=0,fres=0, fA=0,fa=0,far=0,faf=0, fl=0,flr=0; ul fTL[f_last]={}, fEND[f_last]={};
    timeroff_t  fmicros=bitsToNumRev( f_Micros );

    #define     f_a(n)           (bit(fa ,n))                                  // timer a attivato
    #define     f_ar(n)          (bit(far,n))                                  // 
    #define     f_af(n)          (bit(faf,n))                                  // 
    #define     f_achange(n)     (bit(far,n)||bit(faf,n))                      // 
    #define     f_l(n)           (bit(fl,n))                                   // tempo lavoro in esecuzione
    #define     f_lr(n)          (bit(flr,n))                                  // 
    #define     f_lf(n)          (bit(faf,n))                                  // 
    #define     f_lchange(n)     (bit(flr,n)||bit(faf,n))                      // 
    #define     f_res(n)          bitSet(fres,n)                               //
    #define     f_tset(n)         tTM[n]                                       // tempo impostato                
    #define     f_now(n)         (bit(fmicros,n)?PLC_micros:PLC_millis)        //
    #define     f_g(...)          macronumargs(f_g , __VA_ARGS__)              // select la macro corretta in base al COUNT_ARGS degli elementi
    #define     f_g1(n)           n                                            //
    #define     f_g2(n,v)         f_##v(n)                                     //
    #define     f_g3(n,v,t)       f_##v((n), (ul)(t))                          //
    #define     f_time(n,t)       f_Time(n,t);
    #define     f_act( ...)       f_Act(__VA_ARGS__);
    #define     f_set( ...)       f_Set(__VA_ARGS__);
           void f_Time(uc n,ul t){ifb(fl)   fEND[n]+=t-fTL[n];  fTL[n]=t;   }  // se già avviato modifica scadenza, imposta il tempo t
    inline void f_Act(uc n)      {b1(fA)                                    }  // tempi gia memorizzati con _time , attiva
    inline void f_Act(uc n,ul t) {b1(fA)    ifnb(fa) fTL[n]=t;              }  // se non avviato imposta il tempo , attiva
    inline void f_Set(uc n)      {b1(fset)                                  }  // tempi gia memorizzati con _time , set
    inline void f_Set(uc n,ul t) {b1(fset)  ifnb(fa) fTL[n]=t;              }  // se non avviato imposta il tempo , set
           ul   f_tld(uc n)      {return t_l(n)?tEND[n]-f_now(n): tTL[n];   }  // tempo lavoro decrescente countDown
           ul   f_tlc(uc n)      {return t_l(n)?tTL[n]-(tEND[n]-f_now(n)):0;}  // tempo lavoro crescentee , passato


//---------------------------- TIMER ASINCRONO           ----------------------------------- 
    asincroni_t aset=0,ares=0, aA=0,aa=0,aar=0,aaf=0, al=0,alr=0,alf=0, ap=0,apr=0,apf=0;  ul aTL[a_last]={},aTP[a_last]={},aEND[a_last]={},aPcnt[a_last]={}; // asincrono
    asincroni_t amicros=bitsToNumRev( a_Micros );
    #define a_a(n)                         (bit(aa ,n))                                  // a attivato
    #define a_ar(n)                        (bit(aar,n))                                  // 
    #define a_af(n)                        (bit(aaf,n))                                  // 
    #define a_achange(n)                   (bit(aar,n)||bit(aaf,n))                      // 
    #define a_p(n)                         (bit(ap ,n))                                  // p pausa
    #define a_pr(n)                        (bit(apr,n))                                  // 
    #define a_pf(n)                        (bit(apf,n))                                  // 
    #define a_pchange(n)                   (bit(apr,n)||bit(apf,n))                      // 
    #define a_l(n)                         (bit(al ,n))                                  // l lavoro
    #define a_lr(n)                        (bit(alr,n))                                  // 
    #define a_lf(n)                        (bit(alf,n))                                  // 
    #define a_lchange(n)                   (bit(alr,n)||bit(alf,n))                      // 
    #define a_tl(n)                         aTL[n]                                       // tempo lavoro impostato
    #define a_tp(n)                         aTP[n]                                       // tempo pausa impostato
    #define a_pulses(n)                     aPcnt[n]                                     // contatore impulsi
    #define a_res(n)                        bitSet(ares,n)                               //
    #define a_now(n)                       (bit(amicros,n)?PLC_micros:PLC_millis)        //
    #define a_g1(n)                         n                                            //
    #define a_g2(n,v)                       a_##v(n)                                     //
    #define a_g3(n,v,t1)                    a_##v((n), (ul)(t1), (ul)(t1))               // lo stesso tempo si usa su lavoro e pausa
    #define a_g4(n,v,t1,t2)                 a_##v((n), (ul)(t1), (ul)(t2))               //
    #define a_g(...)                        macronumargs(a_g , __VA_ARGS__)              // select la macro corretta in base al COUNT_ARGS degli elementi
    #define a_time(...)                     a_Time(__VA_ARGS__);
    #define a_act(...)                      a_Act (__VA_ARGS__);
    #define a_set(...)                      a_Set (__VA_ARGS__);
       void a_Time(uc n, ul t1, ul t2)    {ifb(al) aEND[n]+=t1-aTL[n]; aTL[n]=t1;       // se avviato modifica la scadenza
                                           ifb(ap) aEND[n]+=t2-aTP[n]; aTP[n]=t2;    }  //        memorizza i tempi 
    inline void a_Act (uc n)              {                                 b1(aA  ) }  //  attiva   tempi già memorizzati con (time)
           void a_Act (uc n, ul t1,ul t2) {ifnb(aa) {aTL[n]=t1; aTP[n]=t2;} b1(aA  ) }  // se spento memorizza i tempi , attiva .
    inline void a_Set (uc n)              {                                 b1(aset) }  // settaggio tempi già memorizzati con (time) 
           void a_Set (uc n, ul t1,ul t2) {ifnb(aa) {aTL[n]=t1; aTP[n]=t2;  b1(aset) }} // se spento memorizza i tempi , settaggio
           ul   a_tld (uc n)              {return a_l(n)? aEND[n]-a_now(n):aTL[n];   }  // tempo lavoro decrescente countDown
           ul   a_tpd (uc n)              {return a_p(n)? aEND[n]-a_now(n):aTP[n];   }  // tempo pausa  decrescente countDown
           ul   a_tlc (uc n)              {return a_l(n)? aTL[n]-(aEND[n]-a_now(n)):0;} // tempo lavoro crescentee , passato
           ul   a_tpc (uc n)              {return a_p(n)? aTP[n]-(aEND[n]-a_now(n)):0;} // tempo pausa  crescentee , passato
//---------------------------- TIMER ASINCRONO CONTATORE ----------------------------------- 
    asincronp_t pset=0,pres=0, pA=0,pa=0,par=0,paf=0, pE=0,pe=0,per=0,pef=0, pL=0,pl=0,plr=0,plf=0, pP=0,pp=0,ppr=0,ppf=0, pCinc=0; ul pTL[p_last]={},pTP[p_last]={},pEND[p_last]={},pPmax[p_last]={},pPcnt[p_last]={},pCmax[p_last]={},pCcnt[p_last]={}; // asincrono super  (40 bytes)
    asincronp_t pmicros=bitsToNumRev( p_Micros );
    #define p_a(n)                          (bit(pa ,n))                                                               // a attivato
    #define p_ar(n)                         (bit(par,n))                                                               // 
    #define p_af(n)                         (bit(paf,n))                                                               // 
    #define p_achange(n)                    (bit(par,n)||bit(paf,n))                                                   // 
    #define p_p(n)                          (bit(pp ,n))                                                               // p pausa
    #define p_pr(n)                         (bit(ppr,n))                                                               // 
    #define p_pf(n)                         (bit(ppf,n))                                                               // 
    #define p_pchange(n)                    (bit(ppr,n)||bit(ppf,n))                                                   // 
    #define p_l(n)                          (bit(pl ,n))                                                               // l lavoro
    #define p_lr(n)                         (bit(plr,n))                                                               // 
    #define p_lf(n)                         (bit(plf,n))                                                               // 
    #define p_lchange(n)                    (bit(plr,n)||bit(plf,n))                                                   // 
    #define p_Cinc(n)                       (bit(pCinc,n))                                                             // 
    #define p_e(n)                          (bit(pe ,n))                                                               // e end cicli (il timer non si arresta)
    #define p_er(n)                         (bit(per,n))                                                               // 
    #define p_ef(n)                         (bit(pef,n))                                                               // 
    #define p_pulsemax(n)                    pPmax[n]                                                                  // TicTac(pulsemax)=5;  imposta a 5 impulsi      
    #define p_pulses(n)                      pPcnt[n]                                                                  // if(TicTac(pulses)=3) led1(act)
    #define p_cycles(n)                      pCcnt[n]                                                                  // 
    #define p_cyclemax(n)                    pCmax[n]                                                                  // TicTac(cyclemax)=5; imposta a 5 cicli di impulsi
    #define p_tl(n)                          pTL[n]                                                                    // tempo lavoro impostato
    #define p_tp(n)                          pTP[n]                                                                    // tempo pausa  impostato
    #define p_trest(n)                      (pEND[n]-millis())                                                         // tempo restante
    #define p_now(n)                        (bit(pmicros,n)?PLC_micros:PLC_millis)                                     //
    #define p_g(...)                         concatena(p_g,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)                           // select la macro corretta in base al COUNT_ARGS degli elementi
    #define p_g1(n)                          n                                                                         //
    #define p_g2(n,v)                        p_##v(n)                                                                  //
    #define p_g3(n,v,a)                      p_##v((n),(ul)(a),(ul)(a))                                                // lo stesso tempo si usa su lavoro e pausa
    #define p_g4(n,v,a,b)                    p_##v((n),(ul)(a),(ul)(b))                                                //
    #define p_g5(n,v,a,b,c)                  p_##v((n),(ul)(a),(ul)(b),(ul)(c))                                        //
    #define p_g6(n,v,a,b,c,d)                p_##v((n),(ul)(a),(ul)(b),(ul)(c),(ul)(d))                                //
    #define p_time(...)                      p_Time(__VA_ARGS__); 
    #define p_act(...)                       p_Act (__VA_ARGS__);
    #define p_set(...)                       p_Set (__VA_ARGS__); 
    #define p_res(n)                         bitSet(pres,n);                                                            // reset 
   
    void p_Time(uc n, ul t1)               { ifb(pl) pEND[n]+=t1-pTL[n]; pTL[n]=t1;  }                                 // imposta lavoro,se avviato modifica la scadenza
    void p_Time(uc n, ul t1, ul t2)        { ifb(pl) pEND[n]+=t1-pTL[n]; pTL[n]=t1;                                    // imposta lavoro,se avviato modifica la scadenza
                                             ifb(pp) pEND[n]+=t1-pTP[n]; pTP[n]=t2;  }                                 // imposta pausa, se avviato modifica la scadenza
    void p_Time(uc n,ul t1,ul t2,ul p)     { p_Time(n,t1,t2);                pPcnt[n]=p;                             } // imposta tempi e contatori
    void p_Time(uc n,ul t1,ul t2,ul p,ul c){ p_Time(n,t1,t2);                pPcnt[n]=p;    pCcnt[n]=c;              } // imposta tempi e contatori
    void p_Act (uc n)                      {                                                                b1(pA  ) } //  attiva   tempi già memorizzati con (time)
    void p_Act (uc n,ul t1,ul t2)          { ifnb(pa) {pTL[n]=t1; pTP[n]=t2; pPcnt[n]=-1UL; pCcnt[n]=-1UL;} b1(pA  ) } // se spento memorizza i tempi , attiva .
    void p_Act (uc n,ul t1,ul t2,ul p)     { ifnb(pa) {pTL[n]=t1; pTP[n]=t2; pPcnt[n]=p;    pCcnt[n]=-1UL;} b1(pA  ) } // se spento memorizza i tempi , attiva .
    void p_Act (uc n,ul t1,ul t2,ul p,ul c){ ifnb(pa) {pTL[n]=t1; pTP[n]=t2; pPcnt[n]=p;    pCcnt[n]=c;   } b1(pA  ) } // se spento memorizza i tempi , attiva .
    void p_Set (uc n)                      {                                                                b1(pset) } // settaggio tempi già memorizzati con (time) 
    void p_Set (uc n,ul t1,ul t2)          { ifnb(pa) {pTL[n]=t1; pTP[n]=t2; pPcnt[n]=-1UL; pCcnt[n]=-1UL;} b1(pset) } // se spento memorizza i tempi , settaggio
    void p_Set (uc n,ul t1,ul t2,ul p)     { ifnb(pa) {pTL[n]=t1; pTP[n]=t2; pPcnt[n]=p;    pCcnt[n]=-1UL;} b1(pset) } // se spento memorizza i tempi , settaggio
    void p_Set (uc n,ul t1,ul t2,ul p,ul c){ ifnb(pa) {pTL[n]=t1; pTP[n]=t2; pPcnt[n]=p;    pCcnt[n]=c;   } b1(pset) } // se spento memorizza i tempi , settaggio
    ul   p_tld (uc n)                      { return (p_l(n)?         pEND[n]-p_now(n) : pTL[n]); }                     // tempo lavoro decrescente countDown
    ul   p_tpd (uc n)                      { return (p_p(n)?         pEND[n]-p_now(n) : pTP[n]); }                     // tempo pausa  decrescente countDown
    ul   p_tlc (uc n)                      { return (p_l(n)? pTL[n]-(pEND[n]-p_now(n)): 0     ); }                     // tempo lavoro crescentee , passato
    ul   p_tpc (uc n)                      { return (p_p(n)? pTP[n]-(pEND[n]-p_now(n)): 0     ); }                     // tempo pausa  crescentee , passato
//---------------------------- CONTATORE                 ----------------------------------- 
    contatori_t                   cA=0,ca=0,car=0,caf=0, cE=0,ce=0,cer=0,cef=0, cdec,cDec,cinc,cInc; ui cCNT[c_last]={};
    #define c_e(n)               (bit(ce ,n))                      // Contatto ritardato             //Ccc[c], 0  inc precedente
    #define c_er(n)              (bit(cer,n))                      //          SU  passato da 0 a 1  //Ccc[c], 1  dec precedente
    #define c_ef(n)              (bit(cef,n))                      //          GIU passato da 1 a 0
    #define c_echange(n)         (bit(cer,n)||bit(cef,n))          //          SU  passato da 0 a 1  //Ccc[c], 1  dec precedente
    #define c_a(n)               (bit(ca ,n))                      // Contatto istantaneo
    #define c_ar(n)              (bit(car,n))                      //          su  passato da 0 a 1 istantaneo
    #define c_af(n)              (bit(caf,n))                      //          giu passato da 1 a 0 istantaneo
    #define c_achange(n)         (bit(car,n)||bit(caf,n))          //          su  passato da 0 a 1 istantaneo
    #define c_g(...)              macronumargs(c_g,__VA_ARGS__)    //
    #define c_g1(n)               n                                 //
    #define c_g2(n,v)             c_##v(n)                          //
    #define c_g3(n,v, t)          c_##v(n, (unsigned int)(t))       //
    void c_rev(uc n,ui m)       { b1(cDec)                       // CONTATORE ROVESCIO ( quando arriva a 0 attiva C )
          if   (!br(ce))        {                                // se contatto ritardato è attivo non verrà eseguito tutto quello sotto , il contatore_cronometro attende il reset 
             if(!br(ca))        { b1(cA) cCNT[n]=m; }            // se è spento , accendilo e scrivi il valore da contare
             else if(!cCNT[n])    b1(cE)                         // se il contatore_cronometro è arrivato a 0 attiva contatto ritardato 
             else if(!br(cdec))   cCNT[n]--;          }}         // se è passato da 0 a 1 decrementa il contatore_cronometro 
    void c_inc(uc n,ui m)       { b1(cInc)                       // CONTATORE INCREMENTA ( quando arriva a m attiva C )
          if   (!br(ce))        {                                // se contatto ritardato è attivo non verrà eseguito tutto quello sotto , il contatore_cronometro attende il reset 
             if(!br(cinc))      {
              if(!br(ca))       { b1(cA) cCNT[n]=1;   }          // se è spento , accendilo e scrivi 0
              else              { cCNT[n]++;                     // altrimenti se è passato da 0 a 1 incrementa il contatore_cronometro 
               if(cCNT[n]>=m)     b1(cE)            }}}          // altrimenti se cCNT è arrivato a m attiva cE
          else if(!br(cinc))      b0(cE)         }      
    void c_dec(uc n)            { b1(cDec)                       // CONTATORE DECREMENTA
         if    (!br(ce))        {                                // se non è terminato il conteggio
             if(!br(cdec))      {                                // se è passato da 0 a 1
              if(br(ca))        { if(!cCNT[n]) cCNT[n]--; }}}}   // se il contatore_cronometro è attivo e non è a 0 , decrementa . 
    void c_res(uc n)            { b0(cA) cCNT[n]=0;  }           // CONTATORE RESETTA 
   

//---------------------------- CRONOMETRO                ----------------------------------- 
    ul mSTART[m_last]={},  mTIME[m_last]={};
    #define m_res(n)        mTIME[n]=0                       // resetta tempo cronometro a microsecondi
    #define m_start(n)      mSTART[n]=micros()               // avvia
    #define m_stop(n)       mTIME[n]+=micros()-mSTART[n]     //arresta e memorizza tempo  
    #define m_tmtot(n)        (mTIME[n]                   )     //  dopo lo stop→tempo totale contato dall'ultimo reset tra tutti gli start e stop
    #define m_tmtotist(n)     (mTIME[n]+micros()-mSTART[n])     // prima di stop→tempo totale istantaneo, dall'ultimo reset tra tutti gli start e stop
    #define m_tmparist(n)     (micros()-mSTART[n]         )     // prima di stop→tempo parziale istantaneo ,  dall'ultimo start
    #define m_g(...)        macronumargs(m_g,__VA_ARGS__)    // select la macro corretta in base al COUNT_ARGS degli elementi
    #define m_g1(n)            n                                // es: led1() → 2
    #define m_g2(n,v)       m_##v(n)                         // es: led1(act) → bitSet(oA, 2)

//---------------------------- ENCODER                   ----------------------------------- 
    uc e_A=0,e_Ao=0,  e_B=0,e_Bo=0;  int e_cnt[e_last]={};  
    #define e_g(...)    concatena(e_g,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__) 
    #define e_g1(n)     n                                                   
    #define e_g2(n,v)   e_##v(n)                                            
    #define e_a(n)      bitSet(e_A,n);
    #define e_b(n)      bitSet(e_B,n);
    #define e_cont(n)   e_cnt[n]

    void e_loop(){uc Ac,Bc,ABu;
      Ac=(e_A!=e_Ao);   Bc=(e_B!=e_Bo);   ABu=(e_A==e_B);    e_Ao=e_A; e_Bo=e_B; e_A=e_B=0; 
      for_n_to(e_last){ ifb(Ac) {ifb(ABu) e_cnt[n]++; else e_cnt[n]--; }
                        ifb(Bc) {ifb(ABu) e_cnt[n]--; else e_cnt[n]++; }}}

//---------------------------- PLC                       ----------------------------------- 
  void PLC_pinmode(){ i_pinmode;  o_pinmode; ii_pinmode; ai_IBmake();} //

  void PLC_loop()   {                                          //
      PLC_millis=millis();static uc MILLISO=lowByte(PLC_millis);uc Millispas=lowByte(PLC_millis)-MILLISO; MILLISO=lowByte(PLC_millis); // millis passati
      PLC_micros=micros();                                     // millis passati
      // uc MILLIS16 = uint8_t(PLC_millis>>4);                 //
                                                               //
      ingressi_t iA=ia; ia=0; ingressi_t iE=ie;                // memorizza in old
      i_readAll;                                               // legge ingressi in ia
      iar=~iA&ia; iaf=iA&~ia; ingressi_t ichange=iar|iaf;      // istantanei rising, falling, variazione 
      itim|=ichange;                                           // contatto cambiato → set del timing
                                                                  #define scaduto iTD[n]<=Millispas
      for_n_to(i_last) {                                       // IN tempi      
       ifb(ichange)     iTD[n]=f_get(itime,n);                 // contatto cambiato ricarica il tempo in iTD[]
       ifb(itim)       {                                       // se è attivato il timing
        if(scaduto)    { b0(itim)   iTD[n]=0; }                // se fine conteggio disattiva itim=0
        else             iTD[n]-=Millispas;   }}               // se non è a fine conteggio sottrae il tempo passato
                                                                  #undef scaduto
      ie=(ie&itim)|(ia&~itim); ier=~iE&ie;ief=iE&~ie;          // IN   ritardati   ia&~itim r=on quanto tempo scaduto , ie&itim r=off quand tempo scaduto  
                                                                  #define contatti(d,c,C)  d##c##r=~d##c&d##C; d##c##f=d##c&~d##C; d##c=d##C //rising/falling
                                                                  #define contattiR(d,c,C) d##C&=d##a;   contatti(d,c,C)                     //reset + rising/falling
                                                                  #define contact(d,c)     d##c|=d##c##r; d##c##f|=d##af; d##c&=~d##c##f;    //cr accende c, cf e af lo spengono
                                                                  #define p_contacts contact(p,l) contact(p,p) contact(p,e)
                                                                  #define a_contacts contact(a,l) contact(a,p)
      oT^=oO&~oo; oo=oO;                                       // T commuta ad ogni attivazione di oO
      oT&=~ores;                                               // disattivato da reset 
      oset&=~ores;                                             // disattivato da reset
      oT|=oset;                                                // T attivato da set
      oA|=oT;                                                  // I attivato da act o da oT
      o_scriviUscite;                                          // manda oA aa pin OUT
      contatti(o,a,A);                                         // attivo -→ rising/falling 
      oO=ores=oA=0;                                            // azzera 
                                                               // 
      ai_aggiorna();                                           // aggiorna un ingresso per ciclo
      ao_aggiorna();                                           // aggiorna un uscita   per ciclo
                                                               //
      rT^=rO&~ro; ro=rO;                                       // rT viene invertito dal fronte di salita di rO. quando rO=1 e ro=0
      rT&=~rres;                                               // disattivato da reset 
      rset&=~rres;                                             // disattivato da reset 
      rT|=rset;                                                // T attivato da set , disattivato da reset
      rA|=rT;                                                  // rA attivato da act o da rT
      contatti(r,a,A);                                         // attivo -→ rising/falling 
      rO=rA=rres=0;                                            // memorizza e azzera
                                                                  #define scadenzaL tEND[n]=t_now(n)+tTL[n]
                                                                  #define scaduto ((long)(t_now(n)-tEND[n])>=0)
      tO&=~tres;                                               // Reset spegne Oscillante (tosc=1 , restart a fine tempo )
      tset&=~tres;       tA|=tset;                             // reset spegne set anche se evocato prima di set, // act e set attivano A 
      tA&=~(tO&te);      contatti(t,a,A);  tres=tA=ter=0;      // end time e Oscillante disattivano A ... il prossimo ciclo si riattiverà
      for_n_to(t_last) { ifnb(ta)          continue;           // TIME tempi
       ifb(tar)          scadenzaL;                            // 
       if(t_l(n))      { if(scaduto)    b1(ter); }}            // ter istante della scadenza
      te|=ter;           te&=ta;                               // memorizza scadenza. azzera allo spegnimento .
                                                                  #undef  scadenzaL
                                                                  #undef  scaduto
                                                                  #define scadenzaL fEND[n]=f_now(n)+fTL[n]
                                                                  #define scaduto ((long)(f_now(n)-fEND[n])>=0)
                                                               //
      fset&=~fres;               fA|=fset;                     // reset spegne sempre set; act e set attivano A, se è in lavoro non si spegne 
      flr=fl;       fl=fa&~fA;   flr=~flr&fl;                  // memorizza 'l' ; quando il timer non è piu alimentato si attiva 'l'; calcolo 'l' rising .
      far=~fa&fA;   fa|=fA;      fres=fA=faf=0;                // attivazione;  attivato ; azzera variabili.  
      for_n_to(f_last)   {                                     // TIME tempi
       ifb(fl)           {                                     // se è in lavoro
        ifb(flr)           scadenzaL;                          // se si è appena attivato imposta la scadenza 
        if(scaduto)        b0(fa,fl);b1(faf);  }}              // se scaduto mette in end
                                                               #undef  scadenzaL
                                                               #undef  scadenzaP
                                                               #undef  scaduto
                                                               #define scadenzaP aEND[n]=a_now(n)+aTP[n]; b1(apr,alf)
                                                               #define scadenzaL aEND[n]=a_now(n)+aTL[n]; b1(alr,apf)
                                                               #define scaduto ((long)(a_now(n)-aEND[n])>=0)
                                                               #define avvio  aPcnt[n]=0; aEND[n]=a_now(n)+aTL[n]
      aset&=~ares;    aA|=aset;   contatti(a,a,A);             // act e set attivano A , reset lo disattiva sempre anche se evocato prima di set !
      ares=aA=alf=apr=apf=0; al|=aar; alr=aar;                 // a-→ rising/falling, all'accensione si attiva il tempo lavoro ed il suo rising
      for_n_to(a_last)         { 
        ifnb(aa)                             continue;         // se non è attivo salta al prossimo n 
        ifb(aar)               { avvio;      continue;   }     // all'attivazione memorizza la scadenza 1
        ifb(al){ if(scaduto)   { scadenzaP;              }}    // se è in lavoro, se scaduto attiva pausa, disattiva lavoro, imposta scadenza pausa
        else     if(scaduto)   { scadenzaL;  aPcnt[n]++; }}    // se è in pausa , se scaduto attiva lavoro, disattiva pausa, imposta scadenza lavoro // incrementa il contaimpulsi
       a_contacts                                              // cr accende c, cf e af lo spengono
                                                               #undef  avvio
                                                               #undef  scadenzaL
                                                               #undef  scadenzaP
                                                               #undef  scaduto
                                                               #define scadenzaL pEND[n]=p_now(n)+pTL[n]; b1(plr,ppf)
                                                               #define scadenzaP pEND[n]=p_now(n)+pTP[n]; b1(ppr,plf)
                                                               #define scaduto   ((long)(p_now(n)-pEND[n])>=0)
                                                               #define avvia     pPcnt[n]=0; pCcnt[n]=0; pEND[n]=p_now(n)+pTL[n];
                                                               #define endPulses ++pPcnt[n]>pPmax[n]
                                                               #define endCyles  pCmax[n] && (++pCcnt[n]>pCmax[n])  // se Cmax=0 non si contano i cicli e quindi non c'è scadenza del timer
      pset&=~pres;  pA|=pset;                contatti(p,a,A);  // reset spegne set sempre anche se evocato prima di set // act e set atttivano A   
      pres=pA=plf=ppr=ppf=pCinc=per=pef=0;   pl|=par; plr=par; // all'accensione si attiva il tempo lavoro
      for_n_to(p_last)         {                               //
        ifnb(pa)                             continue;         // se non è acceso next n
        ifb(par)               { avvia;      continue;    }    // all'accensione avvia
        ifb(pL){if(scaduto)    { scadenzaP;               }}   // se è in lavoro // se scaduto attiva pausa , disattiva lavoro, imposta scadenza pausa
           else if(scaduto)    { scadenzaL;                    // se pausa scaduta, imposta scadenza lavoro
                 if(endPulses) { pPcnt[n]=0; b1(pCinc)         // se conta impulsi finito, azzeralo, segnala cicli incrementa
                  if(endCyles) { b1(per)                  }}}} // se conta cicli   finito, attiva end ma il timer continua a funzionare.
      p_contacts                                               // cr accende c, cf e af lo spengono
                                                               //
      cinc=cInc;cInc=0;                                        //
      cdec=cDec;cDec=0;                                        //
      contatti(c,a,A);                                         //                
      contattiR(c,e,E);                                        // CONT ritardati     
      }                                                        //
                                                               #undef  avvia
                                                               #undef  scadenzaL
                                                               #undef  scadenzaP
                                                               #undef  scaduto
                                                               #undef  endPulses
                                                               #undef  endCyles 
                                                               #undef  contatti
                                                               #undef  contattiR
                                                               #undef  contact
                                                               #undef  azzera 



// --------------------------- SERIALE                   ----------------------------------- 
 // ----------------------------- BUFFER DI STRINGHE           --------------------------------
  template<uc BUFFER_SIZE, uc MAX_STRINGS>   class CircularStringBuffer {        // classe pensata per invio asincrono alla seriale max 63 bytes , non bloccante .
   static_assert((BUFFER_SIZE & (BUFFER_SIZE - 1)) == 0, "BUFFER_SIZE must be power of 2");
   static_assert((BUFFER_SIZE < 256),                    "BUFFER_SIZE must be less then 256");
   static_assert((MAX_STRINGS & (MAX_STRINGS - 1)) == 0, "MAX_STRINGS must be power of 2");
   static_assert((MAX_STRINGS < BUFFER_SIZE),            "MAX_STRINGS must be less then BUFFER_SIZE");
   char buffer[BUFFER_SIZE] = {};                                                // buffer circolare di stringhe
   uc   bhead=0,  bfree=BUFFER_SIZE;                                             // controlli circolari di buffer
   uc   strings[MAX_STRINGS]={},length[MAX_STRINGS]={};                          // posizione e lunghezza stringhe all'interno del buffer
   uc   stail=0, shead=0, scount=0;                                              // controlli circolari di strings[] e length[] 
   inline void advanceTail(uc v)  {                                 bfree+=v; stail++; stail&=MAX_STRINGS-1; scount--;}
   inline void advanceHead(uc v)  { bhead+=v; bhead&=BUFFER_SIZE-1; bfree-=v; shead++; shead&=MAX_STRINGS-1; scount++;}
   public:                        
   bl push(const char* str,uc str_len) {                                        // str_len sempre minore di 63 (txt buffer) , se si inviano stringhe aggiungere 1 a str_len per il \0 finale .                                      
     if(str_len>63 || scount>=MAX_STRINGS || str_len>bfree )return false;
                       uc first = min(str_len, BUFFER_SIZE-bhead);
                    memcpy(buffer+bhead, str,               first);          // scrive da head alla fine la prima parte
     if(str_len>first) memcpy(buffer,       str+first, str_len-first);          // scrive dall' inizio il resto   (ricircola)
                       strings[shead]=bhead;  length[shead]=str_len;            // memorizza posizione,lunghezza
                       advanceHead(str_len);                return true; 
   }
   bl popToSerial() { if(scount==0)                         return false;
                       uc btail=strings[stail]; uc srt_len=length[stail];       // posizione e lunghezza della stringa in buffer[]
                       uc first=min(srt_len, BUFFER_SIZE-btail);
                       Serial.write( buffer+btail, first);                      // prima parte
     if(srt_len>first) Serial.write( buffer      , srt_len-first);              // parte riavvolta
                       advanceTail(srt_len);                return true;
   }
   void clear() { bhead=0; bfree=BUFFER_SIZE; shead=0; stail=0; scount=0;}
   };
 
 
 
 
 // ----------------------------- BUFFER DI FUNZIONI           --------------------------------
  template<uc BUF_SIZE>  class CircularFunctionBuffer { public:
     static_assert((BUF_SIZE & (BUF_SIZE-1))==0, "BUF_SIZE può essere solo 2,4,8,16,32,64,128,256");
     funcptr<bl> buf[BUF_SIZE]={};                                       // buffer di funzioni
     uc      head=0,tail=0,cnt=0;  
     inline void advanceTail()  { tail++; tail&=BUF_SIZE-1; cnt--;}
     inline void advanceHead()  { head++; head&=BUF_SIZE-1; cnt++;}

     CircularFunctionBuffer() {}
     bl push(funcptr<bl> f){ if(cnt==BUF_SIZE)       return false;      //if(full) return false;   // buffer pieno , non si può scrivere su head perchè coincide con tail .
                          buf[head]=f; advanceHead(); return true;    }
 
     funcptr<bl> pop() {
              if(cnt)  { uc otail=tail; advanceTail(); return buf[otail]; }
              else                                     return nullptr;    } 
 
     funcptr<bl> peek(){ if(cnt) return buf[tail];
                         else    return nullptr;                          }};
 
   
 // ----------------------------- SERIALE                      --------------------------------
  template<uc in_lenMax,uc out_lenMax, uc out_stringMax,uc out_functionsMax>     class Seriale { public:  // classe seriale non bloccante: se si riempie il buffer della stampante 64byte , il programma si sospende . questa classe cerca di evitarlo .
    char          in[in_lenMax+1]={};                                            // +1 per il terminatore '\0' ricorda: bufferin[Bufin_lenMax] è l'ultimo carattere e deve essere = '\0'
    bl            ready=0;
    ul            baud=9600;
    uc            inLen=0,c=0;                                                   // c contatore utilizzato da f() come seriale.c  “step counter” per funzioni asincrone.
    CircularFunctionBuffer<out_functionsMax>       bufout_f;                     // buffer circolare di funzioni
    funcptr<bl>   f=nullptr;                                                     // funzione estratta da bufout_f
    CircularStringBuffer<out_lenMax,out_stringMax> bufout_s;                     // buffer circolare di  strings
    ull           bufout_x=0;                                                    // FIFO memorizza nei bit quale bufout_ leggere ; true→_f, false→_s                                            
    uc            bufout_tail=0, bufout_head=0, bufout_len=0;                    // buffer circolare binario
                                                   #define bufout_head_next      do{bufout_head=(bufout_head+1)&63; bufout_len++;}while(0) 
                                                   #define bufout_tail_next      do{bufout_tail=(bufout_tail+1)&63; bufout_len--;}while(0)
                                                   #define bufout_add_function   do{bitSet(bufout_x,bufout_head);   bufout_head_next;}while(0)
                                                   #define bufout_add_string     do{bitClear(bufout_x,bufout_head); bufout_head_next;}while(0)
    Seriale() {}

    void init(ul velocita){ baud=velocita;
      if(Serial)          { Serial.end(); delay(50);}
      Serial.begin(baud); while(!Serial){ delay(50);}}

    bl print (funcptr<bl> f)               { if(bufout_len>64)                  return 0;    // aggiunge la funzione al  bufout_f
            if(bufout_f.push(f))           { bufout_add_function;return 1;}else return 0; }
    bl print (const char* s,uc length)     { if(bufout_len>=64)                 return 0;    // aggiunge length bytes al buffer_s 
           if(bufout_s.push(s,length))     { bufout_add_string; return 1;} else return 0; }
    bl print (const char* s)               { if(bufout_len>=64)                 return 0;    // aggiunge tutta la stringa al buffer_s 
           if(bufout_s.push(s,strlen(s)+1)){ bufout_add_string; return 1;} else return 0; }  // ...+1 per il carattere \0 finale
    bl print(float v)                      { char b[24]; dtostrf(v,0,2,b); return print(b);}
    bl print(double v ) {
             #if defined(ARDUINO_ARCH_AVR)
                                            {char b[24]; dtostrf(v,0,2,b); return print(b);}
             #else
                                            {char b[32]; snprintf(b,sizeof(b),"%.6f",v); return print(b);}
             #endif
    }
    bl print(char v){char b[8] ; ltoa( v,b,10); return print(b);}
    bl print(sc v)  {char b[8] ; ltoa( v,b,10); return print(b);}
    bl print(uc v)  {char b[8] ; ultoa(v,b,10); return print(b);}
    bl print(si v)  {char b[16]; ltoa( v,b,10); return print(b);}
    bl print(ui v)  {char b[16]; ultoa(v,b,10); return print(b);}
    bl print(sl v)  {char b[24]; ltoa( v,b,10); return print(b);}
    bl print(ul v)  {char b[24]; ultoa(v,b,10); return print(b);}


                                                                                  #define FineStringa ((inChar=='\n')||(inChar=='\r'))
                                                                              inline bool bufout_isfunction(){return bitRead(bufout_x, bufout_tail);}
    void ricevi(){
      if(ready)                          { inLen=0;ready=false;              }     // reset "ready" per nuova lettura
      while(Serial.available()&&!ready)  { char inChar=(char)Serial.read();        // 
       if(FineStringa)                   { in[inLen]='\0'; ready=true;         }   // termina stringa
       else if(inLen<in_lenMax)          { in[inLen++]=inChar;               }}    // aggiunge inChar
    }
    void trasmetti(){
      if(!bufout_len)                      return;                                 // niente da inviare → esci
      if(Serial.availableForWrite()<63)    return;                                 // se non è libero   → esci 
      if(bufout_isfunction())            {                                         // se in buffer out c'è una funzione in coda
       if(!f)                              f=bufout_f.pop();                       // estrae la funzione dal buffer se non l'ha gia fatto
       if(f)                             {                                         // se c'è  
        if(f())                          { f=nullptr;  c=0; bufout_tail_next;  }   // la esegue ,se true è completata, la elimina ,cancella il contatore, avanza la coda del buffer out                         
        else                               c++;                               }}   // non completata incrementa il contatore .c (utilizzato nella funzione f())
      else if(bufout_s.popToSerial())    {                  bufout_tail_next; }    // se stringa inviata ...
    }
    void loop() { ricevi(); trasmetti();  }                                         // 
                                                                                      #undef bufout_tail_next
                                                                                      #undef bufout_add_function
                                                                                      #undef bufout_add_string  
                                                                                      #undef FineStringa
      bl printdata(){ Sp(F("Seriale Ready: "), (Serial ? "si" : "no"), F("   baud="), baud);return 1;}} ;

    seriale_declaration
   //-------------------- funzioni seriale.print con piu elementi (non usare con parametri opzionali: Serial.print(78, BIN)→"1001110")
                                          inline void sp()                                    { }
   template<typename T>                   inline void sp(const T& value)                      { seriale.print(value); }
   template<typename T, typename... Args> inline void sp(const T& first, const Args&... rest) { seriale.print(first); sp(rest...); }

// --------------------------- EXCEL                     ----------------------------------- flash 1716	Ram 44

   #define XL_BOOL       ({ uc b[]={ BITStoBYTES( FUN_ARGS_LIST(XL_Bool, 1, XL_BOOL_DISPOSITIVI) ) };  Sw(b,sizeof(b)); })      // invia dati    ({ }) servono per un blocco complesso in SELECTOR 
   #define XL_Bool(disp) ARGS_FUNS_LIST( COUNT_ARGS(disp##_XL_CONTATTI), disp##_XL_CONTATTI, disp##_XL_DISPOSITIVI )            // ARGS_FUNS_LIST( 2, a,e, start,stop,...) →start(a),start(e),stop(a),stop(e),...

   #define XL_NUM        FUN_ARGS_LIST( XL_Num, 1, XL_NUM_DISPOSITIVI )                                                         // XL_Num(t),XL_Num(a),... 
   #define XL_Num(disp)  Swn<uint32_t>( ARGS_FUNS_LIST( COUNT_ARGS(disp##_XL_VALORI), disp##_XL_VALORI, disp##_XL_DISPOSITIVI));// Swn<uint32_t>( Asin0(tld),Asin0(tpd), Asin1(tld),Asin1(tpd),...),  Swn<uint32_t>( Asin0(tld),Asin0(tpd), Asin1(tld),Asin1(tpd),...) 

  bl XL_TrasmettiBoolean(){           // Trasmetti Booleani () chiamata da seriale ,molto efficente, trasmette in pacchetti di 8 bit 
     SELECTORETURN( seriale.c     ,   //
       Sp(F("{[(b"));             ,   // header apertura trasmissione dati boolean
       XL_BOOL                    ,
       Sp(F("\r\n"));             )   // header chiusura  
     return 1;                    }   // 1 comunica a seriale che la funzione è stata completata

  bl XL_TrasmettiNumeri(){            // Trasmetti unsigned long - Allineamento UL: invii array di uint32_t. Su AVR (little‑endian) l’ordine dei byte è LSB→MSB.
     SELECTORETURN(  seriale.c    ,   //
       Sp(F("{[(u"));             ,   //                                                                              
       XL_NUM                     ,   //
       Sp(F("\r\n"));             )   //
     return true;                 }   //

  inline void XL_loop(){ 
   if(XL_timer(lr)){ SELECTOR( XL_timer(pulses) ,
                      sp(XL_TrasmettiBoolean)         ,
                      sp(XL_TrasmettiNumeri)        ) }} // caricata nel buffer di trasmissione seriale XL_TrasmettiBoolean

// --------------------------- morse_class               ----------------------------------- 
  #define morse_template template<ul pausaparola,ul pausalettera, ul pausa,ul punto,ul linea> 
  #define morse_class       Morse<   pausaparola,   pausalettera,    pausa,   punto,   linea> 
  
  morse_template class Morse { public:
    static flash(sc, code[128]   ); static flash(sc, codelen[128]) ;
    const char* msg=nullptr; uc l; sc lc;                              // letter; lettercode: punto=1, linea=0 , pausaparola=-1
    bl a=0,f=0; uc t;                                                  // attivo, flash; timer;
              Morse(uc timer):t(timer) {}
         void letterRead()         { l=f?f_get(msg,p_cycles(t)):msg[p_cycles(t)]; lc=f_get(code,l); p_pulsemax(t)=f_get(codelen,l)-1; }
    inline ul simboltime()         { return (lc==-1)? pausaparola: (bit(lc,p_pulses(t))? punto:linea); }
    inline ul Pausa()              { return ((p_pulses(t)==p_pulsemax(t))? pausalettera: pausa); }
         void set(const char* Msg,bl flash ){ a=1; f=flash; msg=Msg; p_cyclemax(t)=f?f_strlen(msg)-1:strlen(msg)-1; letterRead(); p_set(t,100,100); }    // attiva il timer
         void reset()              { p_res(t); a=0; }
         void loop(){
           I__ !a                ___ return;
           L__ p_Cinc(t)         ___ letterRead();                     // prossima lettera
           L__ p_lr(t)           ___ p_time(t, simboltime(), Pausa())  // prossimo simbolo espande in: p_Time(5, (lc==-1)? 600: ((lc>>pPcnt[5])&1)? 100:300), (pPcnt[5]==pPmax[5])? 300: 100))  compreso p_Time 30–40 cicli AVR 2.5 microsecondi
           L__ p_e(t)            ___ reset();                          // fine messaggio spegne 
           O__        }  };                            //  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47 8 9 0 1 52 53 54 55 56 57 58 59 60 61 62 63 64 5 66 67 8 9 70 1 72 3 4 5 76 7 8 9 0 1 2 3 4 5 6 7 8 9 90 91 92 93 94 95 96 97 98 99 0 1 02 3 04 5 6 7 08 9 110 1 2 3 4 5 6 7 8 9 0 1 122 23 24 25 26 127
                                                       //                                                                                                 ' '  !   "   #   $   %   &   '   (   )   *   +   ,   -   .   / 0 1 2 3  4  5  6  7  8  9  :  ;  <  =  >  ?  @ A  B  C D E  F G  H I J K  L M N O P Q R S T U V W X Y  Z                    a  b  c d e  f g  h i j k  l m   n o p q r s t u v w x y   z               
  morse_template flash(sc, morse_class::code[128])=   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 22, 36, -1,114, -1,  8, 33,  9, 36, -1, 10, 12, 62, 42,  4,0,1,3,7,15,31,30,28,24,16, 7,42,-1, 2,-1,51,26,1,14,10,6,1,11,4,15,3,1,2,13,0,2,0,9,4,5,7,0,3,7,1,6,2,12,-1,-1,-1,-1,-1,-1,1,14,10,6,1,11,4,15,3,1,2,13,0,  2,0,9,4,5,7,0,3,7,1,6,2, 12,-1,-1,-1,-1, -1};
  morse_template flash(sc, morse_class::codelen[128])={ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  6,  6,  1,  7,  1,  5,  6,  5,  6,  1,  5,  6,  6,  6,  5,5,5,5,5, 5, 5, 5, 5, 5, 5, 6, 6, 1, 5, 1, 6, 6,2, 4, 4,3,1, 4,3, 4,2,4,3, 4,2,2,3,4,4,3,3,1,3,4,3,4,4, 4, 1, 1, 1, 1, 1, 1,2, 4, 4,3,1, 4,3, 4,2,4,3, 4,2,  2,3,4,4,3,3,1,3,4,3,4,4,  4, 1, 1, 1, 1,  1};

  morse_declaration
