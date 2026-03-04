// clicca qui e poi      ctrl+k2 k1 ascondi       ctrl1+kj scopkri tutto 
// ----- GENERALI                  -----------
   #ifndef _NOP // required for some non Arduino cores
   #define _NOP() do { __asm__ volatile ("nop"); } while (0)
   #endif

   #define I__ if(           // start
   #define L__ } if(         // line
   #define _N_ } else if(    // not line (la L__ superiore è falsa)
   #define _n_  } else {     // se non, altri comandi sulla stessa linea  L__ marcia(e) ___ led1(act); _n_ led2(act);
   #define O__ }             // exit
   #define ___  ){           // azione
   #define __ &&             // _ linea della serie    || linee del parallelo

   using bl  = bool;
   using ul  = unsigned long;
   using ull = unsigned long long;
   using sl  = long;
   using ui  = unsigned int;
   using si  = int;
   using uc  = unsigned char;
   using sc  = signed char;

   template<typename ritorno, typename... Args> 
   using funcptr = ritorno(*)(Args...);             //funcptr<ui,ui,ui> s=somma; if(s(a,b)==10)... ( ui somma(ui a,ui b){return a+b;} ) 
   void funzionevuota(){}
   
   #define sizearr(a) sizeof(a)/sizeof(a[0])
   #define for_n_to(v) for(uc n=0;n<=v;n++)         // for generico su n max 255

                        template<typename T,typename U,typename V,typename X,typename Y,typename Z> 
   inline bool rollbeat(T& pulses,U from,V to,X& cycles,Y From, Z To){ if(pulses++>to){ pulses=from; if(cycles++>To) cycles=From; return true; } return false;}
                        template<typename T, typename U, typename V>           // Versione sovraccaricata: solo pulses
   inline bool rollbeat(T& pulses, U from, V to) {if(pulses++>to){ pulses=from; return true; } return false;}

   #define Concatena( a,b)   a##b               // concatena il nome e il COUNT_ARGS degli argomenti
   #define concatena( a,b)   Concatena(a, b)    // forza ad espandere correttamente macro complesse
   #define Concatena3(a,b,c) a##b##c            // concatena il nome e il COUNT_ARGS degli argomenti
   #define concatena3(a,b,c) Concatena3(a,b,c)  // forza ad espandere correttamente macro complesse

   #define EXPAND(...) __VA_ARGS__         // forza l'espansione
   #define expand(x)   x                   // forza l'espansione
   
// ----- CONTA ARGOMENTI MACRO     -----------
   #define _ARG_N(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,_49,_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,_60,_61,_62,_63,_64,_65,_66,_67,_68,_69,_70,_71,_72,_73,_74,_75,_76,_77,_78,_79,_80,_81,_82,_83,_84,_85,_86,_87,_88,_89,_90,_91,_92,_93,_94,_95,_96,_97,_98,_99,_100,_101,_102,_103,_104,_105,_106,_107,_108,_109,_110,_111,_112,_113,_114,_115,_116,_117,_118,_119,_120,_121,_122,_123,_124,_125,_126,_127,_128,_129,_130,_131,_132,_133,_134,_135,_136,_137,_138,_139,_140,_141,_142,_143,_144,_145,_146,_147,_148,_149,_150,_151,_152,_153,_154,_155,_156,_157,_158,_159,_160,_161,_162,_163,_164,_165,_166,_167,_168,_169,_170,_171,_172,_173,_174,_175,_176,_177,_178,_179,_180,_181,_182,_183,_184,_185,_186,_187,_188,_189,_190,_191,_192,_193,_194,_195,_196,_197,_198,_199,_200,_201,_202,_203,_204,_205,_206,_207,_208,_209,_210,_211,_212,_213,_214,_215,_216,_217,_218,_219,_220,_221,_222,_223,_224,_225,_226,_227,_228,_229,_230,_231,_232,_233,_234,_235,_236,_237,_238,_239,_240,_241,_242,_243,_244,_245,_246,_247,_248,_249,_250,_251,_252,_253,_254,_255,_256,N,...) N
   #define COUNT_ARGS(...) _ARG_N(__VA_ARGS__,256,255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

   #define _ARG_N0(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,_49,_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,_60,_61,_62,_63,_64,_65,_66,_67,_68,_69,_70,_71,_72,_73,_74,_75,_76,_77,_78,_79,_80,_81,_82,_83,_84,_85,_86,_87,_88,_89,_90,_91,_92,_93,_94,_95,_96,_97,_98,_99,_100,_101,_102,_103,_104,_105,_106,_107,_108,_109,_110,_111,_112,_113,_114,_115,_116,_117,_118,_119,_120,_121,_122,_123,_124,_125,_126,_127,_128,_129,_130,_131,_132,_133,_134,_135,_136,_137,_138,_139,_140,_141,_142,_143,_144,_145,_146,_147,_148,_149,_150,_151,_152,_153,_154,_155,_156,_157,_158,_159,_160,_161,_162,_163,_164,_165,_166,_167,_168,_169,_170,_171,_172,_173,_174,_175,_176,_177,_178,_179,_180,_181,_182,_183,_184,_185,_186,_187,_188,_189,_190,_191,_192,_193,_194,_195,_196,_197,_198,_199,_200,_201,_202,_203,_204,_205,_206,_207,_208,_209,_210,_211,_212,_213,_214,_215,_216,_217,_218,_219,_220,_221,_222,_223,_224,_225,_226,_227,_228,_229,_230,_231,_232,_233,_234,_235,_236,_237,_238,_239,_240,_241,_242,_243,_244,_245,_246,_247,_248,_249,_250,_251,_252,_253,_254,_255,N,...) N
   #define COUNT_ARGS0(...) _ARG_N0(__VA_ARGS__,255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,n)

   #define macronumargs(macro, ...)  concatena(macro, COUNT_ARGS(__VA_ARGS__)) (__VA_ARGS__)  // restituisce macronumargs(argomenti) ES: macronumargs(pippo, 10,20) → pippo2(10,20) 
   #define macronumargs2(macro, ...) concatena(macro, COUNT_ARGS(__VA_ARGS__)) (__VA_ARGS__)  // macronumargs2 si usa quando macronumargs  verrebbe invocata due volte nello stesso contesto di espansione.
   #define macronumargs3(macro, ...) concatena(macro, COUNT_ARGS(__VA_ARGS__)) (__VA_ARGS__)  // macronumargs3 si usa quando macronumargs2 verrebbe invocata tre volte nello stesso contesto di espansione.

// ----- INC(a)                    --(12)→13
   #define INC(a) INC_##a
   #define INC_0    1
   #define INC_1    2
   #define INC_2    3
   #define INC_3    4
   #define INC_4    5
   #define INC_5    6
   #define INC_6    7
   #define INC_7    8
   #define INC_8    9
   #define INC_9    10
   #define INC_10   11
   #define INC_11   12
   #define INC_12   13
   #define INC_13   14
   #define INC_14   15
   #define INC_15   16
   #define INC_16   17
   #define INC_17   18
   #define INC_18   19
   #define INC_19   20
   #define INC_20   21
   #define INC_21   22
   #define INC_22   23
   #define INC_23   24
   #define INC_24   25
   #define INC_25   26
   #define INC_26   27
   #define INC_27   28
   #define INC_28   29
   #define INC_29   30
   #define INC_30   31
   #define INC_31   32
   #define INC_32   33
   #define INC_33   34
   #define INC_34   35
   #define INC_35   36
   #define INC_36   37
   #define INC_37   38
   #define INC_38   39
   #define INC_39   40
   #define INC_40   41
   #define INC_41   42
   #define INC_42   43
   #define INC_43   44
   #define INC_44   45
   #define INC_45   46
   #define INC_46   47
   #define INC_47   48
   #define INC_48   49
   #define INC_49   50
   #define INC_50   51
   #define INC_51   52
   #define INC_52   53
   #define INC_53   54
   #define INC_54   55
   #define INC_55   56
   #define INC_56   57
   #define INC_57   58
   #define INC_58   59
   #define INC_59   60
   #define INC_60   61
   #define INC_61   62
   #define INC_62   63
   #define INC_63   64
   #define INC_64   65
   #define INC_65   66
   #define INC_66   67
   #define INC_67   68
   #define INC_68   69
   #define INC_69   70
   #define INC_70   71
   #define INC_71   72
   #define INC_72   73
   #define INC_73   74
   #define INC_74   75
   #define INC_75   76
   #define INC_76   77
   #define INC_77   78
   #define INC_78   79
   #define INC_79   80
   #define INC_80   81
   #define INC_81   82
   #define INC_82   83
   #define INC_83   84
   #define INC_84   85
   #define INC_85   86
   #define INC_86   87
   #define INC_87   88
   #define INC_88   89
   #define INC_89   90
   #define INC_90   91
   #define INC_91   92
   #define INC_92   93
   #define INC_93   94
   #define INC_94   95
   #define INC_95   96
   #define INC_96   97
   #define INC_97   98
   #define INC_98   99
   #define INC_99  100
   #define INC_100 101
   #define INC_101 102
   #define INC_102 103
   #define INC_103 104
   #define INC_104 105
   #define INC_105 106
   #define INC_106 107
   #define INC_107 108
   #define INC_108 109
   #define INC_109 110
   #define INC_110 111
   #define INC_111 112
   #define INC_112 113
   #define INC_113 114
   #define INC_114 115
   #define INC_115 116
   #define INC_116 117
   #define INC_117 118
   #define INC_118 119
   #define INC_119 120
   #define INC_120 121
   #define INC_121 122
   #define INC_122 123
   #define INC_123 124
   #define INC_124 125
   #define INC_125 126
   #define INC_126 127
   #define INC_127 128
   #define INC_128 129
   #define INC_129 130
   #define INC_130 131
   #define INC_131 132
   #define INC_132 133
   #define INC_133 134
   #define INC_134 135
   #define INC_135 136
   #define INC_136 137
   #define INC_137 138
   #define INC_138 139
   #define INC_139 140
   #define INC_140 141
   #define INC_141 142
   #define INC_142 143
   #define INC_143 144
   #define INC_144 145
   #define INC_145 146
   #define INC_146 147
   #define INC_147 148
   #define INC_148 149
   #define INC_149 150
   #define INC_150 151
   #define INC_151 152
   #define INC_152 153
   #define INC_153 154
   #define INC_154 155
   #define INC_155 156
   #define INC_156 157
   #define INC_157 158
   #define INC_158 159
   #define INC_159 160
   #define INC_160 161
   #define INC_161 162
   #define INC_162 163
   #define INC_163 164
   #define INC_164 165
   #define INC_165 166
   #define INC_166 167
   #define INC_167 168
   #define INC_168 169
   #define INC_169 170
   #define INC_170 171
   #define INC_171 172
   #define INC_172 173
   #define INC_173 174
   #define INC_174 175
   #define INC_175 176
   #define INC_176 177
   #define INC_177 178
   #define INC_178 179
   #define INC_179 180
   #define INC_180 181
   #define INC_181 182
   #define INC_182 183
   #define INC_183 184
   #define INC_184 185
   #define INC_185 186
   #define INC_186 187
   #define INC_187 188
   #define INC_188 189
   #define INC_189 190
   #define INC_190 191
   #define INC_191 192
   #define INC_192 193
   #define INC_193 194
   #define INC_194 195
   #define INC_195 196
   #define INC_196 197
   #define INC_197 198
   #define INC_198 199
   #define INC_199 200
   #define INC_200 201
   #define INC_201 202
   #define INC_202 203
   #define INC_203 204
   #define INC_204 205
   #define INC_205 206
   #define INC_206 207
   #define INC_207 208
   #define INC_208 209
   #define INC_209 210
   #define INC_210 211
   #define INC_211 212
   #define INC_212 213
   #define INC_213 214
   #define INC_214 215
   #define INC_215 216
   #define INC_216 217
   #define INC_217 218
   #define INC_218 219
   #define INC_219 220
   #define INC_220 221
   #define INC_221 222
   #define INC_222 223
   #define INC_223 224
   #define INC_224 225
   #define INC_225 226
   #define INC_226 227
   #define INC_227 228
   #define INC_228 229
   #define INC_229 230
   #define INC_230 231
   #define INC_231 232
   #define INC_232 233
   #define INC_233 234
   #define INC_234 235
   #define INC_235 236
   #define INC_236 237
   #define INC_237 238
   #define INC_238 239
   #define INC_239 240
   #define INC_240 241
   #define INC_241 242
   #define INC_242 243
   #define INC_243 244
   #define INC_244 245
   #define INC_245 246
   #define INC_246 247
   #define INC_247 248
   #define INC_248 249
   #define INC_249 250
   #define INC_250 251
   #define INC_251 252
   #define INC_252 253
   #define INC_253 254
   #define INC_254 255
   #define INC_255 256
   #define INC_256 257
   #define INC_257 258
   #define INC_258 259
   #define INC_259 260
   #define INC_260 261
   #define INC_261 262
   #define INC_262 263
   #define INC_263 264
   #define INC_264 265
   #define INC_265 266
   #define INC_266 267
   #define INC_267 268
   #define INC_268 269
   #define INC_269 270
   #define INC_270 271
   #define INC_271 272
   #define INC_272 273
   #define INC_273 274
   #define INC_274 275
   #define INC_275 276
   #define INC_276 277
   #define INC_277 278
   #define INC_278 279
   #define INC_279 280
   #define INC_280 281
   #define INC_281 282
   #define INC_282 283
   #define INC_283 284
   #define INC_284 285
   #define INC_285 286
   #define INC_286 287
   #define INC_287 288
   #define INC_288 289
   #define INC_289 290
   #define INC_290 291
   #define INC_291 292
   #define INC_292 293
   #define INC_293 294
   #define INC_294 295
   #define INC_295 296
   #define INC_296 297
   #define INC_297 298
   #define INC_298 299
   #define INC_299 300
   #define INC_300 301
   #define INC_301 302
   #define INC_302 303
   #define INC_303 304
   #define INC_304 305
   #define INC_305 306
   #define INC_306 307
   #define INC_307 308
   #define INC_308 309
   #define INC_309 310
   #define INC_310 311
   #define INC_311 312
   #define INC_312 313
   #define INC_313 314
   #define INC_314 315
   #define INC_315 316
   #define INC_316 317
   #define INC_317 318
   #define INC_318 319
   #define INC_319 320
   #define INC_320 321
   #define INC_321 322
   #define INC_322 323
   #define INC_323 324
   #define INC_324 325
   #define INC_325 326
   #define INC_326 327
   #define INC_327 328
   #define INC_328 329
   #define INC_329 330
   #define INC_330 331
   #define INC_331 332
   #define INC_332 333
   #define INC_333 334
   #define INC_334 335
   #define INC_335 336
   #define INC_336 337
   #define INC_337 338
   #define INC_338 339
   #define INC_339 340
   #define INC_340 341
   #define INC_341 342
   #define INC_342 343
   #define INC_343 344
   #define INC_344 345
   #define INC_345 346
   #define INC_346 347
   #define INC_347 348
   #define INC_348 349
   #define INC_349 350
   #define INC_350 351
   #define INC_351 352
   #define INC_352 353
   #define INC_353 354
   #define INC_354 355
   #define INC_355 356
   #define INC_356 357
   #define INC_357 358
   #define INC_358 359
   #define INC_359 360
   #define INC_360 361
   #define INC_361 362
   #define INC_362 363
   #define INC_363 364
   #define INC_364 365
   #define INC_365 366
   #define INC_366 367
   #define INC_367 368
   #define INC_368 369
   #define INC_369 370
   #define INC_370 371
   #define INC_371 372
   #define INC_372 373
   #define INC_373 374
   #define INC_374 375
   #define INC_375 376
   #define INC_376 377
   #define INC_377 378
   #define INC_378 379
   #define INC_379 380
   #define INC_380 381
   #define INC_381 382
   #define INC_382 383
   #define INC_383 384
   #define INC_384 385
   #define INC_385 386
   #define INC_386 387
   #define INC_387 388
   #define INC_388 389
   #define INC_389 390
   #define INC_390 391
   #define INC_391 392
   #define INC_392 393
   #define INC_393 394
   #define INC_394 395
   #define INC_395 396
   #define INC_396 397
   #define INC_397 398
   #define INC_398 399
   #define INC_399 400
   #define INC_400 401
   #define INC_401 402
   #define INC_402 403
   #define INC_403 404
   #define INC_404 405
   #define INC_405 406
   #define INC_406 407
   #define INC_407 408
   #define INC_408 409
   #define INC_409 410
   #define INC_410 411
   #define INC_411 412
   #define INC_412 413
   #define INC_413 414
   #define INC_414 415
   #define INC_415 416
   #define INC_416 417
   #define INC_417 418
   #define INC_418 419
   #define INC_419 420
   #define INC_420 421
   #define INC_421 422
   #define INC_422 423
   #define INC_423 424
   #define INC_424 425
   #define INC_425 426
   #define INC_426 427
   #define INC_427 428
   #define INC_428 429
   #define INC_429 430
   #define INC_430 431
   #define INC_431 432
   #define INC_432 433
   #define INC_433 434
   #define INC_434 435
   #define INC_435 436
   #define INC_436 437
   #define INC_437 438
   #define INC_438 439
   #define INC_439 438
   #define INC_440 439  //
   #define INC_441 440
   #define INC_442 441
   #define INC_443 442
   #define INC_444 443
   #define INC_445 444
   #define INC_446 445
   #define INC_447 446
   #define INC_448 447
   #define INC_449 448
   #define INC_450 449
   #define INC_451 450
   #define INC_452 451
   #define INC_453 452
   #define INC_454 453
   #define INC_455 454
   #define INC_456 455
   #define INC_457 456
   #define INC_458 457
   #define INC_459 458
   #define INC_460 459
   #define INC_461 460
   #define INC_462 461
   #define INC_463 462
   #define INC_464 463
   #define INC_465 464
   #define INC_466 465
   #define INC_467 466
   #define INC_468 467
   #define INC_469 468
   #define INC_470 469
   #define INC_471 470
   #define INC_472 471
   #define INC_473 472
   #define INC_474 473
   #define INC_475 474
   #define INC_476 475
   #define INC_477 476
   #define INC_478 477
   #define INC_479 478
   #define INC_480 479
   #define INC_481 480
   #define INC_482 481
   #define INC_483 482
   #define INC_484 483
   #define INC_485 484
   #define INC_486 485
   #define INC_487 486
   #define INC_488 487
   #define INC_489 488
   #define INC_490 489
   #define INC_491 490
   #define INC_492 491
   #define INC_493 492
   #define INC_494 493
   #define INC_495 494
   #define INC_496 495
   #define INC_497 496
   #define INC_498 497
   #define INC_499 498   //
   #define INC_500 499
   #define INC_501 500
   #define INC_502 501
   #define INC_503 502
   #define INC_504 503
   #define INC_505 504
   #define INC_506 505
   #define INC_507 506
   #define INC_508 507
   #define INC_509 508
   #define INC_510 509
   #define INC_511 510
   #define INC_512 511
   #define INC_513 512
   #define INC_514 513
   #define INC_515 514
   #define INC_516 515
   #define INC_517 516
   #define INC_518 517
   #define INC_519 518
   #define INC_520 519
   #define INC_521 520
   #define INC_522 521
   #define INC_523 522
   #define INC_524 523
   #define INC_525 524
   #define INC_526 525
   #define INC_527 526
   #define INC_528 527
   #define INC_529 528
   #define INC_530 529
   #define INC_531 530
   #define INC_532 531
   #define INC_533 532
   #define INC_534 533
   #define INC_535 534
   #define INC_536 535
   #define INC_537 536
   #define INC_538 537
   #define INC_539 538
   #define INC_540 539
   #define INC_541 540
   #define INC_542 541
   #define INC_543 542
   #define INC_544 543
   #define INC_545 544
   #define INC_546 545
   #define INC_547 546
   #define INC_548 547
   #define INC_549 548
   #define INC_550 549
   #define INC_551 550
   #define INC_552 551
   #define INC_553 552
   #define INC_554 553
   #define INC_555 554
   #define INC_556 555
   #define INC_557 556
   #define INC_558 557
   #define INC_559 558
   #define INC_560 559
   #define INC_561 560
   #define INC_562 561
   #define INC_563 562
   #define INC_564 563
   #define INC_565 564
   #define INC_566 565
   #define INC_567 566
   #define INC_568 567
   #define INC_569 568
   #define INC_570 569
   #define INC_571 570
   #define INC_572 571
   #define INC_573 572
   #define INC_574 573
   #define INC_575 574
   #define INC_576 575
   #define INC_577 576
   #define INC_578 577
   #define INC_579 578
   #define INC_580 579
   #define INC_581 580
   #define INC_582 581
   #define INC_583 582
   #define INC_584 583
   #define INC_585 584
   #define INC_586 585
   #define INC_587 586
   #define INC_588 587
   #define INC_589 588
   #define INC_590 589
   #define INC_591 590
   #define INC_592 591
   #define INC_593 592
   #define INC_594 593
   #define INC_595 594
   #define INC_596 595
   #define INC_597 596
   #define INC_598 597
   #define INC_599 598


// ----- ZERO_NULL(a)              --(0)→NULL (n)→n
  #define ZERO_NULL(a)  concatena(ZERO_NULL,IS_ZERO(a))      //
  #define ZERO_NULL0(a) a
  #define ZERO_NULL1(a)   

// ----- IS_ZERO(n)                --(0)→1    (4)→0   
  #define IS_ZERO(n) IS_ZERO_##n
  #define IS_ZERO_0   1
  #define IS_ZERO_1   0
  #define IS_ZERO_2   0
  #define IS_ZERO_3   0
  #define IS_ZERO_4   0
  #define IS_ZERO_5   0
  #define IS_ZERO_6   0
  #define IS_ZERO_7   0
  #define IS_ZERO_8   0
  #define IS_ZERO_9   0
  #define IS_ZERO_10  0
  #define IS_ZERO_11  0
  #define IS_ZERO_12  0
  #define IS_ZERO_13  0
  #define IS_ZERO_14  0
  #define IS_ZERO_15  0
  #define IS_ZERO_16  0
  #define IS_ZERO_17  0
  #define IS_ZERO_18  0
  #define IS_ZERO_19  0
  #define IS_ZERO_20  0
  #define IS_ZERO_21  0
  #define IS_ZERO_22  0
  #define IS_ZERO_23  0
  #define IS_ZERO_24  0
  #define IS_ZERO_25  0
  #define IS_ZERO_26  0
  #define IS_ZERO_27  0
  #define IS_ZERO_28  0
  #define IS_ZERO_29  0
  #define IS_ZERO_30  0
  #define IS_ZERO_31  0
  #define IS_ZERO_32  0
  #define IS_ZERO_33  0
  #define IS_ZERO_34  0
  #define IS_ZERO_35  0
  #define IS_ZERO_36  0
  #define IS_ZERO_37  0
  #define IS_ZERO_38  0
  #define IS_ZERO_39  0
  #define IS_ZERO_40  0
  #define IS_ZERO_41  0
  #define IS_ZERO_42  0
  #define IS_ZERO_43  0
  #define IS_ZERO_44  0
  #define IS_ZERO_45  0
  #define IS_ZERO_46  0
  #define IS_ZERO_47  0
  #define IS_ZERO_48  0
  #define IS_ZERO_49  0
  #define IS_ZERO_50  0
  #define IS_ZERO_51  0
  #define IS_ZERO_52  0
  #define IS_ZERO_53  0
  #define IS_ZERO_54  0
  #define IS_ZERO_55  0
  #define IS_ZERO_56  0
  #define IS_ZERO_57  0
  #define IS_ZERO_58  0
  #define IS_ZERO_59  0
  #define IS_ZERO_60  0
  #define IS_ZERO_61  0
  #define IS_ZERO_62  0
  #define IS_ZERO_63  0
  #define IS_ZERO_64  0
  #define IS_ZERO_65  0
  #define IS_ZERO_66  0
  #define IS_ZERO_67  0
  #define IS_ZERO_68  0
  #define IS_ZERO_69  0
  #define IS_ZERO_70  0
  #define IS_ZERO_71  0
  #define IS_ZERO_72  0
  #define IS_ZERO_73  0
  #define IS_ZERO_74  0
  #define IS_ZERO_75  0
  #define IS_ZERO_76  0
  #define IS_ZERO_77  0
  #define IS_ZERO_78  0
  #define IS_ZERO_79  0
  #define IS_ZERO_80  0
  #define IS_ZERO_81  0
  #define IS_ZERO_82  0
  #define IS_ZERO_83  0
  #define IS_ZERO_84  0
  #define IS_ZERO_85  0
  #define IS_ZERO_86  0
  #define IS_ZERO_87  0
  #define IS_ZERO_88  0
  #define IS_ZERO_89  0
  #define IS_ZERO_90  0
  #define IS_ZERO_91  0
  #define IS_ZERO_92  0
  #define IS_ZERO_93  0
  #define IS_ZERO_94  0
  #define IS_ZERO_95  0
  #define IS_ZERO_96  0
  #define IS_ZERO_97  0
  #define IS_ZERO_98  0
  #define IS_ZERO_99  0
  #define IS_ZERO_100 0
  #define IS_ZERO_101 0
  #define IS_ZERO_102 0
  #define IS_ZERO_103 0
  #define IS_ZERO_104 0
  #define IS_ZERO_105 0
  #define IS_ZERO_106 0
  #define IS_ZERO_107 0
  #define IS_ZERO_108 0
  #define IS_ZERO_109 0
  #define IS_ZERO_110 0
  #define IS_ZERO_111 0
  #define IS_ZERO_112 0
  #define IS_ZERO_113 0
  #define IS_ZERO_114 0
  #define IS_ZERO_115 0
  #define IS_ZERO_116 0
  #define IS_ZERO_117 0
  #define IS_ZERO_118 0
  #define IS_ZERO_119 0
  #define IS_ZERO_120 0
  #define IS_ZERO_121 0
  #define IS_ZERO_122 0
  #define IS_ZERO_123 0
  #define IS_ZERO_124 0
  #define IS_ZERO_125 0
  #define IS_ZERO_126 0
  #define IS_ZERO_127 0
  #define IS_ZERO_128 0
  #define IS_ZERO_129 0
  #define IS_ZERO_130 0
  #define IS_ZERO_131 0
  #define IS_ZERO_132 0
  #define IS_ZERO_133 0
  #define IS_ZERO_134 0
  #define IS_ZERO_135 0
  #define IS_ZERO_136 0
  #define IS_ZERO_137 0
  #define IS_ZERO_138 0
  #define IS_ZERO_139 0
  #define IS_ZERO_140 0
  #define IS_ZERO_141 0
  #define IS_ZERO_142 0
  #define IS_ZERO_143 0
  #define IS_ZERO_144 0
  #define IS_ZERO_145 0
  #define IS_ZERO_146 0
  #define IS_ZERO_147 0
  #define IS_ZERO_148 0
  #define IS_ZERO_149 0
  #define IS_ZERO_150 0
  #define IS_ZERO_151 0
  #define IS_ZERO_152 0
  #define IS_ZERO_153 0
  #define IS_ZERO_154 0
  #define IS_ZERO_155 0
  #define IS_ZERO_156 0
  #define IS_ZERO_157 0
  #define IS_ZERO_158 0
  #define IS_ZERO_159 0
  #define IS_ZERO_160 0
  #define IS_ZERO_161 0
  #define IS_ZERO_162 0
  #define IS_ZERO_163 0
  #define IS_ZERO_164 0
  #define IS_ZERO_165 0
  #define IS_ZERO_166 0
  #define IS_ZERO_167 0
  #define IS_ZERO_168 0
  #define IS_ZERO_169 0
  #define IS_ZERO_170 0
  #define IS_ZERO_171 0
  #define IS_ZERO_172 0
  #define IS_ZERO_173 0
  #define IS_ZERO_174 0
  #define IS_ZERO_175 0
  #define IS_ZERO_176 0
  #define IS_ZERO_177 0
  #define IS_ZERO_178 0
  #define IS_ZERO_179 0
  #define IS_ZERO_180 0
  #define IS_ZERO_181 0
  #define IS_ZERO_182 0
  #define IS_ZERO_183 0
  #define IS_ZERO_184 0
  #define IS_ZERO_185 0
  #define IS_ZERO_186 0
  #define IS_ZERO_187 0
  #define IS_ZERO_188 0
  #define IS_ZERO_189 0
  #define IS_ZERO_190 0
  #define IS_ZERO_191 0
  #define IS_ZERO_192 0
  #define IS_ZERO_193 0
  #define IS_ZERO_194 0
  #define IS_ZERO_195 0
  #define IS_ZERO_196 0
  #define IS_ZERO_197 0
  #define IS_ZERO_198 0
  #define IS_ZERO_199 0
  #define IS_ZERO_200 0
  #define IS_ZERO_201 0
  #define IS_ZERO_202 0
  #define IS_ZERO_203 0
  #define IS_ZERO_204 0
  #define IS_ZERO_205 0
  #define IS_ZERO_206 0
  #define IS_ZERO_207 0
  #define IS_ZERO_208 0
  #define IS_ZERO_209 0
  #define IS_ZERO_210 0
  #define IS_ZERO_211 0
  #define IS_ZERO_212 0
  #define IS_ZERO_213 0
  #define IS_ZERO_214 0
  #define IS_ZERO_215 0
  #define IS_ZERO_216 0
  #define IS_ZERO_217 0
  #define IS_ZERO_218 0
  #define IS_ZERO_219 0
  #define IS_ZERO_220 0
  #define IS_ZERO_221 0
  #define IS_ZERO_222 0
  #define IS_ZERO_223 0
  #define IS_ZERO_224 0
  #define IS_ZERO_225 0
  #define IS_ZERO_226 0
  #define IS_ZERO_227 0
  #define IS_ZERO_228 0
  #define IS_ZERO_229 0
  #define IS_ZERO_230 0
  #define IS_ZERO_231 0
  #define IS_ZERO_232 0
  #define IS_ZERO_233 0
  #define IS_ZERO_234 0
  #define IS_ZERO_235 0
  #define IS_ZERO_236 0
  #define IS_ZERO_237 0
  #define IS_ZERO_238 0
  #define IS_ZERO_239 0
  #define IS_ZERO_240 0
  #define IS_ZERO_241 0
  #define IS_ZERO_242 0
  #define IS_ZERO_243 0
  #define IS_ZERO_244 0
  #define IS_ZERO_245 0
  #define IS_ZERO_246 0
  #define IS_ZERO_247 0
  #define IS_ZERO_248 0
  #define IS_ZERO_249 0
  #define IS_ZERO_250 0
  #define IS_ZERO_251 0
  #define IS_ZERO_252 0
  #define IS_ZERO_253 0
  #define IS_ZERO_254 0
  #define IS_ZERO_255 0
  #define IS_ZERO_256 0
// ----- ENUM                      --(4)→1,2,3,4  
   #define ENUM0(n)   concatena(ENUM0_,IS_ZERO(n)) (n)
   #define ENUM0_1(n) 0          /* caso n = 0 */
   #define ENUM0_0(n) 0, ENUM(n) /* caso n > 0 */

   #define ENUM(n)    concatena(ENUM_,n)
   #define ENUM_0   
   #define ENUM_1   1
   #define ENUM_2   1,2
   #define ENUM_3   1,2,3
   #define ENUM_4   1,2,3,4
   #define ENUM_5   1,2,3,4,5
   #define ENUM_6   1,2,3,4,5,6
   #define ENUM_7   1,2,3,4,5,6,7
   #define ENUM_8   1,2,3,4,5,6,7,8
   #define ENUM_9   1,2,3,4,5,6,7,8,9
   #define ENUM_10  1,2,3,4,5,6,7,8,9,10
   #define ENUM_11  1,2,3,4,5,6,7,8,9,10,11
   #define ENUM_12  1,2,3,4,5,6,7,8,9,10,11,12
   #define ENUM_13  1,2,3,4,5,6,7,8,9,10,11,12,13
   #define ENUM_14  1,2,3,4,5,6,7,8,9,10,11,12,13,14
   #define ENUM_15  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
   #define ENUM_16  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
   #define ENUM_17  ENUM_16,17
   #define ENUM_18  ENUM_16,17,18
   #define ENUM_19  ENUM_16,17,18,19
   #define ENUM_20  ENUM_16,17,18,19,20
   #define ENUM_21  ENUM_16,17,18,19,20,21
   #define ENUM_22  ENUM_16,17,18,19,20,21,22
   #define ENUM_23  ENUM_16,17,18,19,20,21,22,23
   #define ENUM_24  ENUM_16,17,18,19,20,21,22,23,24
   #define ENUM_25  ENUM_16,17,18,19,20,21,22,23,24,25
   #define ENUM_26  ENUM_16,17,18,19,20,21,22,23,24,25,26
   #define ENUM_27  ENUM_16,17,18,19,20,21,22,23,24,25,26,27
   #define ENUM_28  ENUM_16,17,18,19,20,21,22,23,24,25,26,27,28
   #define ENUM_29  ENUM_16,17,18,19,20,21,22,23,24,25,26,27,28,29
   #define ENUM_30  ENUM_16,17,18,19,20,21,22,23,24,25,26,27,28,29,30
   #define ENUM_31  ENUM_16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31
   #define ENUM_32  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32
   #define ENUM_33  ENUM_32,33
   #define ENUM_34  ENUM_32,33,34
   #define ENUM_35  ENUM_32,33,34,35
   #define ENUM_36  ENUM_32,33,34,35,36
   #define ENUM_37  ENUM_32,33,34,35,36,37
   #define ENUM_38  ENUM_32,33,34,35,36,37,38
   #define ENUM_39  ENUM_32,33,34,35,36,37,38,39
   #define ENUM_40  ENUM_32,33,34,35,36,37,38,39,40
   #define ENUM_41  ENUM_32,33,34,35,36,37,38,39,40,41
   #define ENUM_42  ENUM_32,33,34,35,36,37,38,39,40,41,42
   #define ENUM_43  ENUM_32,33,34,35,36,37,38,39,40,41,42,43
   #define ENUM_44  ENUM_32,33,34,35,36,37,38,39,40,41,42,43,44
   #define ENUM_45  ENUM_32,33,34,35,36,37,38,39,40,41,42,43,44,45
   #define ENUM_46  ENUM_32,33,34,35,36,37,38,39,40,41,42,43,44,45,46
   #define ENUM_47  ENUM_32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47
   #define ENUM_48  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48
   #define ENUM_49  ENUM_48,49
   #define ENUM_50  ENUM_48,49,50
   #define ENUM_51  ENUM_48,49,50,51
   #define ENUM_52  ENUM_48,49,50,51,52
   #define ENUM_53  ENUM_48,49,50,51,52,53
   #define ENUM_54  ENUM_48,49,50,51,52,53,54
   #define ENUM_55  ENUM_48,49,50,51,52,53,54,55
   #define ENUM_56  ENUM_48,49,50,51,52,53,54,55,56
   #define ENUM_57  ENUM_48,49,50,51,52,53,54,55,56,57
   #define ENUM_58  ENUM_48,49,50,51,52,53,54,55,56,57,58
   #define ENUM_59  ENUM_48,49,50,51,52,53,54,55,56,57,58,59
   #define ENUM_60  ENUM_48,49,50,51,52,53,54,55,56,57,58,59,60
   #define ENUM_61  ENUM_48,49,50,51,52,53,54,55,56,57,58,59,60,61
   #define ENUM_62  ENUM_48,49,50,51,52,53,54,55,56,57,58,59,60,61,62
   #define ENUM_63  ENUM_48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63
   #define ENUM_64  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64
   #define ENUM_65  ENUM_64,65
   #define ENUM_66  ENUM_64,65,66
   #define ENUM_67  ENUM_64,65,66,67
   #define ENUM_68  ENUM_64,65,66,67,68
   #define ENUM_69  ENUM_64,65,66,67,68,69
   #define ENUM_70  ENUM_64,65,66,67,68,69,70
   #define ENUM_71  ENUM_64,65,66,67,68,69,70,71
   #define ENUM_72  ENUM_64,65,66,67,68,69,70,71,72
   #define ENUM_73  ENUM_64,65,66,67,68,69,70,71,72,73
   #define ENUM_74  ENUM_64,65,66,67,68,69,70,71,72,73,74
   #define ENUM_75  ENUM_64,65,66,67,68,69,70,71,72,73,74,75
   #define ENUM_76  ENUM_64,65,66,67,68,69,70,71,72,73,74,75,76
   #define ENUM_77  ENUM_64,65,66,67,68,69,70,71,72,73,74,75,76,77
   #define ENUM_78  ENUM_64,65,66,67,68,69,70,71,72,73,74,75,76,77,78
   #define ENUM_79  ENUM_64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79
   #define ENUM_80  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80
   #define ENUM_81  ENUM_80,81
   #define ENUM_82  ENUM_80,81,82
   #define ENUM_83  ENUM_80,81,82,83
   #define ENUM_84  ENUM_80,81,82,83,84
   #define ENUM_85  ENUM_80,81,82,83,84,85
   #define ENUM_86  ENUM_80,81,82,83,84,85,86
   #define ENUM_87  ENUM_80,81,82,83,84,85,86,87
   #define ENUM_88  ENUM_80,81,82,83,84,85,86,87,88
   #define ENUM_89  ENUM_80,81,82,83,84,85,86,87,88,89
   #define ENUM_90  ENUM_80,81,82,83,84,85,86,87,88,89,90
   #define ENUM_91  ENUM_80,81,82,83,84,85,86,87,88,89,90,91
   #define ENUM_92  ENUM_80,81,82,83,84,85,86,87,88,89,90,91,92
   #define ENUM_93  ENUM_80,81,82,83,84,85,86,87,88,89,90,91,92,93
   #define ENUM_94  ENUM_80,81,82,83,84,85,86,87,88,89,90,91,92,93,94
   #define ENUM_95  ENUM_80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95
   #define ENUM_96  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96
   #define ENUM_97  ENUM_96,97
   #define ENUM_98  ENUM_96,97,98
   #define ENUM_99  ENUM_96,97,98,99
   #define ENUM_100 ENUM_96,97,98,99,100
   #define ENUM_101 ENUM_96,97,98,99,100,101
   #define ENUM_102 ENUM_96,97,98,99,100,101,102
   #define ENUM_103 ENUM_96,97,98,99,100,101,102,103
   #define ENUM_104 ENUM_96,97,98,99,100,101,102,103,104
   #define ENUM_105 ENUM_96,97,98,99,100,101,102,103,104,105
   #define ENUM_106 ENUM_96,97,98,99,100,101,102,103,104,105,106
   #define ENUM_107 ENUM_96,97,98,99,100,101,102,103,104,105,106,107
   #define ENUM_108 ENUM_96,97,98,99,100,101,102,103,104,105,106,107,108
   #define ENUM_109 ENUM_96,97,98,99,100,101,102,103,104,105,106,107,108,109
   #define ENUM_110 ENUM_96,97,98,99,100,101,102,103,104,105,106,107,108,109,110
   #define ENUM_111 ENUM_96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111
   #define ENUM_112 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112
   #define ENUM_113 ENUM_112,113
   #define ENUM_114 ENUM_112,113,114
   #define ENUM_115 ENUM_112,113,114,115
   #define ENUM_116 ENUM_112,113,114,115,116
   #define ENUM_117 ENUM_112,113,114,115,116,117
   #define ENUM_118 ENUM_112,113,114,115,116,117,118
   #define ENUM_119 ENUM_112,113,114,115,116,117,118,119
   #define ENUM_120 ENUM_112,113,114,115,116,117,118,119,120
   #define ENUM_121 ENUM_112,113,114,115,116,117,118,119,120,121
   #define ENUM_122 ENUM_112,113,114,115,116,117,118,119,120,121,122
   #define ENUM_123 ENUM_112,113,114,115,116,117,118,119,120,121,122,123
   #define ENUM_124 ENUM_112,113,114,115,116,117,118,119,120,121,122,123,124
   #define ENUM_125 ENUM_112,113,114,115,116,117,118,119,120,121,122,123,124,125
   #define ENUM_126 ENUM_112,113,114,115,116,117,118,119,120,121,122,123,124,125,126
   #define ENUM_127 ENUM_112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127
   #define ENUM_128 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128
   #define ENUM_129 ENUM_128,129
   #define ENUM_130 ENUM_128,129,130
   #define ENUM_131 ENUM_128,129,130,131
   #define ENUM_132 ENUM_128,129,130,131,132
   #define ENUM_133 ENUM_128,129,130,131,132,133
   #define ENUM_134 ENUM_128,129,130,131,132,133,134
   #define ENUM_135 ENUM_128,129,130,131,132,133,134,135
   #define ENUM_136 ENUM_128,129,130,131,132,133,134,135,136
   #define ENUM_137 ENUM_128,129,130,131,132,133,134,135,136,137
   #define ENUM_138 ENUM_128,129,130,131,132,133,134,135,136,137,138
   #define ENUM_139 ENUM_128,129,130,131,132,133,134,135,136,137,138,139
   #define ENUM_140 ENUM_128,129,130,131,132,133,134,135,136,137,138,139,140
   #define ENUM_141 ENUM_128,129,130,131,132,133,134,135,136,137,138,139,140,141
   #define ENUM_142 ENUM_128,129,130,131,132,133,134,135,136,137,138,139,140,141,142
   #define ENUM_143 ENUM_128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143
   #define ENUM_144 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144
   #define ENUM_145 ENUM_144,145
   #define ENUM_146 ENUM_144,145,146
   #define ENUM_147 ENUM_144,145,146,147
   #define ENUM_148 ENUM_144,145,146,147,148
   #define ENUM_149 ENUM_144,145,146,147,148,149
   #define ENUM_150 ENUM_144,145,146,147,148,149,150
   #define ENUM_151 ENUM_144,145,146,147,148,149,150,151
   #define ENUM_152 ENUM_144,145,146,147,148,149,150,151,152
   #define ENUM_153 ENUM_144,145,146,147,148,149,150,151,152,153
   #define ENUM_154 ENUM_144,145,146,147,148,149,150,151,152,153,154
   #define ENUM_155 ENUM_144,145,146,147,148,149,150,151,152,153,154,155
   #define ENUM_156 ENUM_144,145,146,147,148,149,150,151,152,153,154,155,156
   #define ENUM_157 ENUM_144,145,146,147,148,149,150,151,152,153,154,155,156,157
   #define ENUM_158 ENUM_144,145,146,147,148,149,150,151,152,153,154,155,156,157,158
   #define ENUM_159 ENUM_144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159
   #define ENUM_160 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160
   #define ENUM_161 ENUM_160,161
   #define ENUM_162 ENUM_160,161,162
   #define ENUM_163 ENUM_160,161,162,163
   #define ENUM_164 ENUM_160,161,162,163,164
   #define ENUM_165 ENUM_160,161,162,163,164,165
   #define ENUM_166 ENUM_160,161,162,163,164,165,166
   #define ENUM_167 ENUM_160,161,162,163,164,165,166,167
   #define ENUM_168 ENUM_160,161,162,163,164,165,166,167,168
   #define ENUM_169 ENUM_160,161,162,163,164,165,166,167,168,169
   #define ENUM_170 ENUM_160,161,162,163,164,165,166,167,168,169,170
   #define ENUM_171 ENUM_160,161,162,163,164,165,166,167,168,169,170,171
   #define ENUM_172 ENUM_160,161,162,163,164,165,166,167,168,169,170,171,172
   #define ENUM_173 ENUM_160,161,162,163,164,165,166,167,168,169,170,171,172,173
   #define ENUM_174 ENUM_160,161,162,163,164,165,166,167,168,169,170,171,172,173,174
   #define ENUM_175 ENUM_160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175
   #define ENUM_176 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176
   #define ENUM_177 ENUM_176,177
   #define ENUM_178 ENUM_176,177,178
   #define ENUM_179 ENUM_176,177,178,179
   #define ENUM_180 ENUM_176,177,178,179,180
   #define ENUM_181 ENUM_176,177,178,179,180,181
   #define ENUM_182 ENUM_176,177,178,179,180,181,182
   #define ENUM_183 ENUM_176,177,178,179,180,181,182,183
   #define ENUM_184 ENUM_176,177,178,179,180,181,182,183,184
   #define ENUM_185 ENUM_176,177,178,179,180,181,182,183,184,185
   #define ENUM_186 ENUM_176,177,178,179,180,181,182,183,184,185,186
   #define ENUM_187 ENUM_176,177,178,179,180,181,182,183,184,185,186,187
   #define ENUM_188 ENUM_176,177,178,179,180,181,182,183,184,185,186,187,188
   #define ENUM_189 ENUM_176,177,178,179,180,181,182,183,184,185,186,187,188,189
   #define ENUM_190 ENUM_176,177,178,179,180,181,182,183,184,185,186,187,188,189,190
   #define ENUM_191 ENUM_176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191
   #define ENUM_192 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192
   #define ENUM_193 ENUM_192,193
   #define ENUM_194 ENUM_192,193,194
   #define ENUM_195 ENUM_192,193,194,195
   #define ENUM_196 ENUM_192,193,194,195,196
   #define ENUM_197 ENUM_192,193,194,195,196,197
   #define ENUM_198 ENUM_192,193,194,195,196,197,198
   #define ENUM_199 ENUM_192,193,194,195,196,197,198,199
   #define ENUM_200 ENUM_192,193,194,195,196,197,198,199,200
   #define ENUM_201 ENUM_192,193,194,195,196,197,198,199,200,201
   #define ENUM_202 ENUM_192,193,194,195,196,197,198,199,200,201,202
   #define ENUM_203 ENUM_192,193,194,195,196,197,198,199,200,201,202,203
   #define ENUM_204 ENUM_192,193,194,195,196,197,198,199,200,201,202,203,204
   #define ENUM_205 ENUM_192,193,194,195,196,197,198,199,200,201,202,203,204,205
   #define ENUM_206 ENUM_192,193,194,195,196,197,198,199,200,201,202,203,204,205,206
   #define ENUM_207 ENUM_192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207
   #define ENUM_208 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208
   #define ENUM_209 ENUM_208,209
   #define ENUM_210 ENUM_208,209,210
   #define ENUM_211 ENUM_208,209,210,211
   #define ENUM_212 ENUM_208,209,210,211,212
   #define ENUM_213 ENUM_208,209,210,211,212,213
   #define ENUM_214 ENUM_208,209,210,211,212,213,214
   #define ENUM_215 ENUM_208,209,210,211,212,213,214,215
   #define ENUM_216 ENUM_208,209,210,211,212,213,214,215,216
   #define ENUM_217 ENUM_208,209,210,211,212,213,214,215,216,217
   #define ENUM_218 ENUM_208,209,210,211,212,213,214,215,216,217,218
   #define ENUM_219 ENUM_208,209,210,211,212,213,214,215,216,217,218,219
   #define ENUM_220 ENUM_208,209,210,211,212,213,214,215,216,217,218,219,220
   #define ENUM_221 ENUM_208,209,210,211,212,213,214,215,216,217,218,219,220,221
   #define ENUM_222 ENUM_208,209,210,211,212,213,214,215,216,217,218,219,220,221,222
   #define ENUM_223 ENUM_208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223
   #define ENUM_224 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224
   #define ENUM_225 ENUM_224,225
   #define ENUM_226 ENUM_224,225,226
   #define ENUM_227 ENUM_224,225,226,227
   #define ENUM_228 ENUM_224,225,226,227,228
   #define ENUM_229 ENUM_224,225,226,227,228,229
   #define ENUM_230 ENUM_224,225,226,227,228,229,230
   #define ENUM_231 ENUM_224,225,226,227,228,229,230,231
   #define ENUM_232 ENUM_224,225,226,227,228,229,230,231,232
   #define ENUM_233 ENUM_224,225,226,227,228,229,230,231,232,233
   #define ENUM_234 ENUM_224,225,226,227,228,229,230,231,232,233,234
   #define ENUM_235 ENUM_224,225,226,227,228,229,230,231,232,233,234,235
   #define ENUM_236 ENUM_224,225,226,227,228,229,230,231,232,233,234,235,236
   #define ENUM_237 ENUM_224,225,226,227,228,229,230,231,232,233,234,235,236,237
   #define ENUM_238 ENUM_224,225,226,227,228,229,230,231,232,233,234,235,236,237,238
   #define ENUM_239 ENUM_224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239
   #define ENUM_240 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240
   #define ENUM_241 ENUM_240,241
   #define ENUM_242 ENUM_240,241,242
   #define ENUM_243 ENUM_240,241,242,243
   #define ENUM_244 ENUM_240,241,242,243,244
   #define ENUM_245 ENUM_240,241,242,243,244,245
   #define ENUM_246 ENUM_240,241,242,243,244,245,246
   #define ENUM_247 ENUM_240,241,242,243,244,245,246,247
   #define ENUM_248 ENUM_240,241,242,243,244,245,246,247,248
   #define ENUM_249 ENUM_240,241,242,243,244,245,246,247,248,249
   #define ENUM_250 ENUM_240,241,242,243,244,245,246,247,248,249,250
   #define ENUM_251 ENUM_240,241,242,243,244,245,246,247,248,249,250,251
   #define ENUM_252 ENUM_240,241,242,243,244,245,246,247,248,249,250,251,252
   #define ENUM_253 ENUM_240,241,242,243,244,245,246,247,248,249,250,251,252,253
   #define ENUM_254 ENUM_240,241,242,243,244,245,246,247,248,249,250,251,252,253,254
   #define ENUM_255 ENUM_240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
   #define ENUM_256 ENUM_240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256




// ----- TENS(n)    TENS_A(...)    --(26)→2  _A(a1,a2,...,a26)→2 
   #define TENS_A(...) TENS(COUNT_ARGS(__VA_ARGS__)) 
   #define TENS(n)    concatena(TENS_,n)
   #define TENS_0   0
   #define TENS_1   0
   #define TENS_2   0
   #define TENS_3   0
   #define TENS_4   0
   #define TENS_5   0
   #define TENS_6   0
   #define TENS_7   0
   #define TENS_8   0
   #define TENS_9   0
   #define TENS_10  1
   #define TENS_11  1
   #define TENS_12  1
   #define TENS_13  1
   #define TENS_14  1
   #define TENS_15  1
   #define TENS_16  1
   #define TENS_17  1
   #define TENS_18  1
   #define TENS_19  1
   #define TENS_20  2
   #define TENS_21  2
   #define TENS_22  2
   #define TENS_23  2
   #define TENS_24  2
   #define TENS_25  2
   #define TENS_26  2
   #define TENS_27  2
   #define TENS_28  2
   #define TENS_29  2
   #define TENS_30  3
   #define TENS_31  3
   #define TENS_32  3
   #define TENS_33  3
   #define TENS_34  3
   #define TENS_35  3
   #define TENS_36  3
   #define TENS_37  3
   #define TENS_38  3
   #define TENS_39  3
   #define TENS_40  4
   #define TENS_41  4
   #define TENS_42  4
   #define TENS_43  4
   #define TENS_44  4
   #define TENS_45  4
   #define TENS_46  4
   #define TENS_47  4
   #define TENS_48  4
   #define TENS_49  4
   #define TENS_50  5
   #define TENS_51  5
   #define TENS_52  5
   #define TENS_53  5
   #define TENS_54  5
   #define TENS_55  5
   #define TENS_56  5
   #define TENS_57  5
   #define TENS_58  5
   #define TENS_59  5
   #define TENS_60  6
   #define TENS_61  6
   #define TENS_62  6
   #define TENS_63  6
   #define TENS_64  6
   #define TENS_65  6
   #define TENS_66  6
   #define TENS_67  6
   #define TENS_68  6
   #define TENS_69  6
   #define TENS_70  7
   #define TENS_71  7
   #define TENS_72  7
   #define TENS_73  7
   #define TENS_74  7
   #define TENS_75  7
   #define TENS_76  7
   #define TENS_77  7
   #define TENS_78  7
   #define TENS_79  7
   #define TENS_80  8
   #define TENS_81  8
   #define TENS_82  8
   #define TENS_83  8
   #define TENS_84  8
   #define TENS_85  8
   #define TENS_86  8
   #define TENS_87  8
   #define TENS_88  8
   #define TENS_89  8
   #define TENS_90  9
   #define TENS_91  9
   #define TENS_92  9
   #define TENS_93  9
   #define TENS_94  9
   #define TENS_95  9
   #define TENS_96  9
   #define TENS_97  9
   #define TENS_98  9
   #define TENS_99  9
   #define TENS_100 10
   #define TENS_101 10
   #define TENS_102 10
   #define TENS_103 10
   #define TENS_104 10
   #define TENS_105 10
   #define TENS_106 10
   #define TENS_107 10
   #define TENS_108 10
   #define TENS_109 10
   #define TENS_110 11
   #define TENS_111 11
   #define TENS_112 11
   #define TENS_113 11
   #define TENS_114 11
   #define TENS_115 11
   #define TENS_116 11
   #define TENS_117 11
   #define TENS_118 11
   #define TENS_119 11
   #define TENS_120 12
   #define TENS_121 12
   #define TENS_122 12
   #define TENS_123 12
   #define TENS_124 12
   #define TENS_125 12
   #define TENS_126 12
   #define TENS_127 12
   #define TENS_128 12
   #define TENS_129 12
   #define TENS_130 13
   #define TENS_131 13
   #define TENS_132 13
   #define TENS_133 13
   #define TENS_134 13
   #define TENS_135 13
   #define TENS_136 13
   #define TENS_137 13
   #define TENS_138 13
   #define TENS_139 13
   #define TENS_140 14
   #define TENS_141 14
   #define TENS_142 14
   #define TENS_143 14
   #define TENS_144 14
   #define TENS_145 14
   #define TENS_146 14
   #define TENS_147 14
   #define TENS_148 14
   #define TENS_149 14
   #define TENS_150 15
   #define TENS_151 15
   #define TENS_152 15
   #define TENS_153 15
   #define TENS_154 15
   #define TENS_155 15
   #define TENS_156 15
   #define TENS_157 15
   #define TENS_158 15
   #define TENS_159 15
   #define TENS_160 16
   #define TENS_161 16
   #define TENS_162 16
   #define TENS_163 16
   #define TENS_164 16
   #define TENS_165 16
   #define TENS_166 16
   #define TENS_167 16
   #define TENS_168 16
   #define TENS_169 16
   #define TENS_170 17
   #define TENS_171 17
   #define TENS_172 17
   #define TENS_173 17
   #define TENS_174 17
   #define TENS_175 17
   #define TENS_176 17
   #define TENS_177 17
   #define TENS_178 17
   #define TENS_179 17
   #define TENS_180 18
   #define TENS_181 18
   #define TENS_182 18
   #define TENS_183 18
   #define TENS_184 18
   #define TENS_185 18
   #define TENS_186 18
   #define TENS_187 18
   #define TENS_188 18
   #define TENS_189 18
   #define TENS_190 19
   #define TENS_191 19
   #define TENS_192 19
   #define TENS_193 19
   #define TENS_194 19
   #define TENS_195 19
   #define TENS_196 19
   #define TENS_197 19
   #define TENS_198 19
   #define TENS_199 19
   #define TENS_200 20
   #define TENS_201 20
   #define TENS_202 20
   #define TENS_203 20
   #define TENS_204 20
   #define TENS_205 20
   #define TENS_206 20
   #define TENS_207 20
   #define TENS_208 20
   #define TENS_209 20
   #define TENS_210 21
   #define TENS_211 21
   #define TENS_212 21
   #define TENS_213 21
   #define TENS_214 21
   #define TENS_215 21
   #define TENS_216 21
   #define TENS_217 21
   #define TENS_218 21
   #define TENS_219 21
   #define TENS_220 22
   #define TENS_221 22
   #define TENS_222 22
   #define TENS_223 22
   #define TENS_224 22
   #define TENS_225 22
   #define TENS_226 22
   #define TENS_227 22
   #define TENS_228 22
   #define TENS_229 22
   #define TENS_230 23
   #define TENS_231 23
   #define TENS_232 23
   #define TENS_233 23
   #define TENS_234 23
   #define TENS_235 23
   #define TENS_236 23
   #define TENS_237 23
   #define TENS_238 23
   #define TENS_239 23
   #define TENS_240 24
   #define TENS_241 24
   #define TENS_242 24
   #define TENS_243 24
   #define TENS_244 24
   #define TENS_245 24
   #define TENS_246 24
   #define TENS_247 24
   #define TENS_248 24
   #define TENS_249 24
   #define TENS_250 25
   #define TENS_251 25
   #define TENS_252 25
   #define TENS_253 25
   #define TENS_254 25
   #define TENS_255 25
   #define TENS_256 25
// ----- UNITS(n)   UNITS_A(...)   --(26)→6  _A(a1,a2,...,a26)→6 
   #define UNITS_A(...) UNITS(COUNT_ARGS(__VA_ARGS__))
   #define UNITS(n)  concatena(UNITS_,n)
   #define UNITS_0   0 
   #define UNITS_1   1 
   #define UNITS_2   2 
   #define UNITS_3   3 
   #define UNITS_4   4 
   #define UNITS_5   5 
   #define UNITS_6   6 
   #define UNITS_7   7 
   #define UNITS_8   8 
   #define UNITS_9   9 
   #define UNITS_10  0
   #define UNITS_11  1 
   #define UNITS_12  2 
   #define UNITS_13  3 
   #define UNITS_14  4 
   #define UNITS_15  5 
   #define UNITS_16  6 
   #define UNITS_17  7 
   #define UNITS_18  8 
   #define UNITS_19  9 
   #define UNITS_20  0
   #define UNITS_21  1 
   #define UNITS_22  2 
   #define UNITS_23  3 
   #define UNITS_24  4 
   #define UNITS_25  5 
   #define UNITS_26  6 
   #define UNITS_27  7 
   #define UNITS_28  8 
   #define UNITS_29  9 
   #define UNITS_30  0
   #define UNITS_31  1 
   #define UNITS_32  2 
   #define UNITS_33  3 
   #define UNITS_34  4 
   #define UNITS_35  5 
   #define UNITS_36  6 
   #define UNITS_37  7 
   #define UNITS_38  8 
   #define UNITS_39  9 
   #define UNITS_40  0
   #define UNITS_41  1 
   #define UNITS_42  2 
   #define UNITS_43  3 
   #define UNITS_44  4 
   #define UNITS_45  5 
   #define UNITS_46  6 
   #define UNITS_47  7 
   #define UNITS_48  8 
   #define UNITS_49  9 
   #define UNITS_50  0
   #define UNITS_51  1 
   #define UNITS_52  2 
   #define UNITS_53  3 
   #define UNITS_54  4 
   #define UNITS_55  5 
   #define UNITS_56  6 
   #define UNITS_57  7 
   #define UNITS_58  8 
   #define UNITS_59  9 
   #define UNITS_60  0
   #define UNITS_61  1 
   #define UNITS_62  2 
   #define UNITS_63  3 
   #define UNITS_64  4 
   #define UNITS_65  5 
   #define UNITS_66  6 
   #define UNITS_67  7 
   #define UNITS_68  8 
   #define UNITS_69  9 
   #define UNITS_70  0
   #define UNITS_71  1 
   #define UNITS_72  2 
   #define UNITS_73  3 
   #define UNITS_74  4 
   #define UNITS_75  5 
   #define UNITS_76  6 
   #define UNITS_77  7 
   #define UNITS_78  8 
   #define UNITS_79  9 
   #define UNITS_80  0
   #define UNITS_81  1 
   #define UNITS_82  2 
   #define UNITS_83  3 
   #define UNITS_84  4 
   #define UNITS_85  5 
   #define UNITS_86  6 
   #define UNITS_87  7 
   #define UNITS_88  8 
   #define UNITS_89  9 
   #define UNITS_90  0
   #define UNITS_91  1 
   #define UNITS_92  2 
   #define UNITS_93  3 
   #define UNITS_94  4 
   #define UNITS_95  5 
   #define UNITS_96  6 
   #define UNITS_97  7 
   #define UNITS_98  8 
   #define UNITS_99  9 
   #define UNITS_100 0
   #define UNITS_101 1 
   #define UNITS_102 2 
   #define UNITS_103 3 
   #define UNITS_104 4 
   #define UNITS_105 5 
   #define UNITS_106 6 
   #define UNITS_107 7 
   #define UNITS_108 8 
   #define UNITS_109 9 
   #define UNITS_110 0
   #define UNITS_111 1 
   #define UNITS_112 2 
   #define UNITS_113 3 
   #define UNITS_114 4 
   #define UNITS_115 5 
   #define UNITS_116 6 
   #define UNITS_117 7 
   #define UNITS_118 8 
   #define UNITS_119 9 
   #define UNITS_120 0
   #define UNITS_121 1 
   #define UNITS_122 2 
   #define UNITS_123 3 
   #define UNITS_124 4 
   #define UNITS_125 5 
   #define UNITS_126 6 
   #define UNITS_127 7 
   #define UNITS_128 8 
   #define UNITS_129 9 
   #define UNITS_130 0
   #define UNITS_131 1 
   #define UNITS_132 2 
   #define UNITS_133 3 
   #define UNITS_134 4 
   #define UNITS_135 5 
   #define UNITS_136 6 
   #define UNITS_137 7 
   #define UNITS_138 8 
   #define UNITS_139 9 
   #define UNITS_140 0
   #define UNITS_141 1 
   #define UNITS_142 2 
   #define UNITS_143 3 
   #define UNITS_144 4 
   #define UNITS_145 5 
   #define UNITS_146 6 
   #define UNITS_147 7 
   #define UNITS_148 8 
   #define UNITS_149 9 
   #define UNITS_150 0
   #define UNITS_151 1 
   #define UNITS_152 2 
   #define UNITS_153 3 
   #define UNITS_154 4 
   #define UNITS_155 5 
   #define UNITS_156 6 
   #define UNITS_157 7 
   #define UNITS_158 8 
   #define UNITS_159 9 
   #define UNITS_160 0
   #define UNITS_161 1 
   #define UNITS_162 2 
   #define UNITS_163 3 
   #define UNITS_164 4 
   #define UNITS_165 5 
   #define UNITS_166 6 
   #define UNITS_167 7 
   #define UNITS_168 8 
   #define UNITS_169 9 
   #define UNITS_170 0
   #define UNITS_171 1 
   #define UNITS_172 2 
   #define UNITS_173 3 
   #define UNITS_174 4 
   #define UNITS_175 5 
   #define UNITS_176 6 
   #define UNITS_177 7 
   #define UNITS_178 8 
   #define UNITS_179 9 
   #define UNITS_180 0
   #define UNITS_181 1 
   #define UNITS_182 2 
   #define UNITS_183 3 
   #define UNITS_184 4 
   #define UNITS_185 5 
   #define UNITS_186 6 
   #define UNITS_187 7 
   #define UNITS_188 8 
   #define UNITS_189 9 
   #define UNITS_190 0
   #define UNITS_191 1 
   #define UNITS_192 2 
   #define UNITS_193 3 
   #define UNITS_194 4 
   #define UNITS_195 5 
   #define UNITS_196 6 
   #define UNITS_197 7 
   #define UNITS_198 8 
   #define UNITS_199 9 
   #define UNITS_200 0
   #define UNITS_201 1 
   #define UNITS_202 2 
   #define UNITS_203 3 
   #define UNITS_204 4 
   #define UNITS_205 5 
   #define UNITS_206 6 
   #define UNITS_207 7 
   #define UNITS_208 8 
   #define UNITS_209 9 
   #define UNITS_210 0
   #define UNITS_211 1 
   #define UNITS_212 2 
   #define UNITS_213 3 
   #define UNITS_214 4 
   #define UNITS_215 5 
   #define UNITS_216 6 
   #define UNITS_217 7 
   #define UNITS_218 8 
   #define UNITS_219 9 
   #define UNITS_220 0
   #define UNITS_221 1 
   #define UNITS_222 2 
   #define UNITS_223 3 
   #define UNITS_224 4 
   #define UNITS_225 5 
   #define UNITS_226 6 
   #define UNITS_227 7 
   #define UNITS_228 8 
   #define UNITS_229 9 
   #define UNITS_230 0
   #define UNITS_231 1 
   #define UNITS_232 2 
   #define UNITS_233 3 
   #define UNITS_234 4 
   #define UNITS_235 5 
   #define UNITS_236 6 
   #define UNITS_237 7 
   #define UNITS_238 8 
   #define UNITS_239 9 
   #define UNITS_240 0
   #define UNITS_241 1 
   #define UNITS_242 2 
   #define UNITS_243 3 
   #define UNITS_244 4 
   #define UNITS_245 5 
   #define UNITS_246 6 
   #define UNITS_247 7 
   #define UNITS_248 8 
   #define UNITS_249 9 
   #define UNITS_250 0
   #define UNITS_251 1
   #define UNITS_252 2
   #define UNITS_253 3
   #define UNITS_254 4
   #define UNITS_255 5
   #define UNITS_256 6

// ----- SEGMENT16  SEGMENT16_     --(15)→0   (16)→1  _(a0,a1,...,a16)→1 (17°) 
   #define SEGMENT16_(...) SEGMENT16(COUNT_ARGS0(__VA_ARGS__))  // conta gli argomenti e li segmenta per 16 partendo da 0
   #define SEGMENT16(n)    concatena(SEGMENT16_,n)
   #define SEGMENT16_n    0
   #define SEGMENT16_0    0
   #define SEGMENT16_1    0
   #define SEGMENT16_2    0
   #define SEGMENT16_3    0
   #define SEGMENT16_4    0
   #define SEGMENT16_5    0
   #define SEGMENT16_6    0
   #define SEGMENT16_7    0
   #define SEGMENT16_8    0
   #define SEGMENT16_9    0
   #define SEGMENT16_10   0
   #define SEGMENT16_11   0
   #define SEGMENT16_12   0
   #define SEGMENT16_13   0
   #define SEGMENT16_14   0
   #define SEGMENT16_15   0
   #define SEGMENT16_16   1
   #define SEGMENT16_17   1
   #define SEGMENT16_18   1
   #define SEGMENT16_19   1
   #define SEGMENT16_20   1
   #define SEGMENT16_21   1
   #define SEGMENT16_22   1
   #define SEGMENT16_23   1
   #define SEGMENT16_24   1
   #define SEGMENT16_25   1
   #define SEGMENT16_26   1
   #define SEGMENT16_27   1
   #define SEGMENT16_28   1
   #define SEGMENT16_29   1
   #define SEGMENT16_30   1
   #define SEGMENT16_31   1
   #define SEGMENT16_32   2
   #define SEGMENT16_33   2
   #define SEGMENT16_34   2
   #define SEGMENT16_35   2
   #define SEGMENT16_36   2
   #define SEGMENT16_37   2
   #define SEGMENT16_38   2
   #define SEGMENT16_39   2
   #define SEGMENT16_40   2
   #define SEGMENT16_41   2
   #define SEGMENT16_42   2
   #define SEGMENT16_43   2
   #define SEGMENT16_44   2
   #define SEGMENT16_45   2
   #define SEGMENT16_46   2
   #define SEGMENT16_47   2
   #define SEGMENT16_48   3
   #define SEGMENT16_49   3
   #define SEGMENT16_50   3
   #define SEGMENT16_51   3
   #define SEGMENT16_52   3
   #define SEGMENT16_53   3
   #define SEGMENT16_54   3
   #define SEGMENT16_55   3
   #define SEGMENT16_56   3
   #define SEGMENT16_57   3
   #define SEGMENT16_58   3
   #define SEGMENT16_59   3
   #define SEGMENT16_60   3
   #define SEGMENT16_61   3
   #define SEGMENT16_62   3
   #define SEGMENT16_63   3
   #define SEGMENT16_64   4
   #define SEGMENT16_65   4
   #define SEGMENT16_66   4
   #define SEGMENT16_67   4
   #define SEGMENT16_68   4
   #define SEGMENT16_69   4
   #define SEGMENT16_70   4
   #define SEGMENT16_71   4
   #define SEGMENT16_72   4
   #define SEGMENT16_73   4
   #define SEGMENT16_74   4
   #define SEGMENT16_75   4
   #define SEGMENT16_76   4
   #define SEGMENT16_77   4
   #define SEGMENT16_78   4
   #define SEGMENT16_79   4
   #define SEGMENT16_80   5
   #define SEGMENT16_81   5
   #define SEGMENT16_82   5
   #define SEGMENT16_83   5
   #define SEGMENT16_84   5
   #define SEGMENT16_85   5
   #define SEGMENT16_86   5
   #define SEGMENT16_87   5
   #define SEGMENT16_88   5
   #define SEGMENT16_89   5
   #define SEGMENT16_90   5
   #define SEGMENT16_91   5
   #define SEGMENT16_92   5
   #define SEGMENT16_93   5
   #define SEGMENT16_94   5
   #define SEGMENT16_95   5
   #define SEGMENT16_96   6
   #define SEGMENT16_97   6
   #define SEGMENT16_98   6
   #define SEGMENT16_99   6
   #define SEGMENT16_100  6
   #define SEGMENT16_101  6
   #define SEGMENT16_102  6
   #define SEGMENT16_103  6
   #define SEGMENT16_104  6
   #define SEGMENT16_105  6
   #define SEGMENT16_106  6
   #define SEGMENT16_107  6
   #define SEGMENT16_108  6
   #define SEGMENT16_109  6
   #define SEGMENT16_110  6
   #define SEGMENT16_111  6
   #define SEGMENT16_112  7
   #define SEGMENT16_113  7
   #define SEGMENT16_114  7
   #define SEGMENT16_115  7
   #define SEGMENT16_116  7
   #define SEGMENT16_117  7
   #define SEGMENT16_118  7
   #define SEGMENT16_119  7
   #define SEGMENT16_120  7
   #define SEGMENT16_121  7
   #define SEGMENT16_122  7
   #define SEGMENT16_123  7
   #define SEGMENT16_124  7
   #define SEGMENT16_125  7
   #define SEGMENT16_126  7
   #define SEGMENT16_127  7
   #define SEGMENT16_128  8
   #define SEGMENT16_129  8
   #define SEGMENT16_130  8
   #define SEGMENT16_131  8
   #define SEGMENT16_132  8
   #define SEGMENT16_133  8
   #define SEGMENT16_134  8
   #define SEGMENT16_135  8
   #define SEGMENT16_136  8
   #define SEGMENT16_137  8
   #define SEGMENT16_138  8
   #define SEGMENT16_139  8
   #define SEGMENT16_140  8
   #define SEGMENT16_141  8
   #define SEGMENT16_142  8
   #define SEGMENT16_143  8
   #define SEGMENT16_144  9
   #define SEGMENT16_145  9
   #define SEGMENT16_146  9
   #define SEGMENT16_147  9
   #define SEGMENT16_148  9
   #define SEGMENT16_149  9
   #define SEGMENT16_150  9
   #define SEGMENT16_151  9
   #define SEGMENT16_152  9
   #define SEGMENT16_153  9
   #define SEGMENT16_154  9
   #define SEGMENT16_155  9
   #define SEGMENT16_156  9
   #define SEGMENT16_157  9
   #define SEGMENT16_158  9
   #define SEGMENT16_159  9
   #define SEGMENT16_160 10
   #define SEGMENT16_161 10
   #define SEGMENT16_162 10
   #define SEGMENT16_163 10
   #define SEGMENT16_164 10
   #define SEGMENT16_165 10
   #define SEGMENT16_166 10
   #define SEGMENT16_167 10
   #define SEGMENT16_168 10
   #define SEGMENT16_169 10
   #define SEGMENT16_170 10
   #define SEGMENT16_171 10
   #define SEGMENT16_172 10
   #define SEGMENT16_173 10
   #define SEGMENT16_174 10
   #define SEGMENT16_175 10
   #define SEGMENT16_176 11
   #define SEGMENT16_177 11
   #define SEGMENT16_178 11
   #define SEGMENT16_179 11
   #define SEGMENT16_180 11
   #define SEGMENT16_181 11
   #define SEGMENT16_182 11
   #define SEGMENT16_183 11
   #define SEGMENT16_184 11
   #define SEGMENT16_185 11
   #define SEGMENT16_186 11
   #define SEGMENT16_187 11
   #define SEGMENT16_188 11
   #define SEGMENT16_189 11
   #define SEGMENT16_190 11
   #define SEGMENT16_191 11
   #define SEGMENT16_192 12
   #define SEGMENT16_193 12
   #define SEGMENT16_194 12
   #define SEGMENT16_195 12
   #define SEGMENT16_196 12
   #define SEGMENT16_197 12
   #define SEGMENT16_198 12
   #define SEGMENT16_199 12
   #define SEGMENT16_200 12
   #define SEGMENT16_201 12
   #define SEGMENT16_202 12
   #define SEGMENT16_203 12
   #define SEGMENT16_204 12
   #define SEGMENT16_205 12
   #define SEGMENT16_206 12
   #define SEGMENT16_207 12
   #define SEGMENT16_208 13
   #define SEGMENT16_209 13
   #define SEGMENT16_210 13
   #define SEGMENT16_211 13
   #define SEGMENT16_212 13
   #define SEGMENT16_213 13
   #define SEGMENT16_214 13
   #define SEGMENT16_215 13
   #define SEGMENT16_216 13
   #define SEGMENT16_217 13
   #define SEGMENT16_218 13
   #define SEGMENT16_219 13
   #define SEGMENT16_220 13
   #define SEGMENT16_221 13
   #define SEGMENT16_222 13
   #define SEGMENT16_223 13
   #define SEGMENT16_224 14
   #define SEGMENT16_225 14
   #define SEGMENT16_226 14
   #define SEGMENT16_227 14
   #define SEGMENT16_228 14
   #define SEGMENT16_229 14
   #define SEGMENT16_230 14
   #define SEGMENT16_231 14
   #define SEGMENT16_232 14
   #define SEGMENT16_233 14
   #define SEGMENT16_234 14
   #define SEGMENT16_235 14
   #define SEGMENT16_236 14
   #define SEGMENT16_237 14
   #define SEGMENT16_238 14
   #define SEGMENT16_239 14
   #define SEGMENT16_240 15
   #define SEGMENT16_241 15
   #define SEGMENT16_242 15
   #define SEGMENT16_243 15
   #define SEGMENT16_244 15
   #define SEGMENT16_245 15
   #define SEGMENT16_246 15
   #define SEGMENT16_247 15
   #define SEGMENT16_248 15
   #define SEGMENT16_249 15
   #define SEGMENT16_250 15
   #define SEGMENT16_251 15
   #define SEGMENT16_252 15
   #define SEGMENT16_253 15
   #define SEGMENT16_254 15
   #define SEGMENT16_255 15
   #define SEGMENT16_256 16

// ----- SEGMENT15  SEGMENT15_     --(15)→0   (15)→1  _(a0,a1,...,a16)→2 (17°) 
   #define SEGMENT15_(...) SEGMENT15(COUNT_ARGS0(__VA_ARGS__))  // conta gli argomenti e li segmenta per 15 partendo da 0
   #define SEGMENT15(n)    concatena(SEGMENT15_,n)
   #define SEGMENT15_n    0
   #define SEGMENT15_0    0
   #define SEGMENT15_1    0
   #define SEGMENT15_2    0
   #define SEGMENT15_3    0
   #define SEGMENT15_4    0
   #define SEGMENT15_5    0
   #define SEGMENT15_6    0
   #define SEGMENT15_7    0
   #define SEGMENT15_8    0
   #define SEGMENT15_9    0
   #define SEGMENT15_10   0
   #define SEGMENT15_11   0
   #define SEGMENT15_12   0
   #define SEGMENT15_13   0
   #define SEGMENT15_14   0
   #define SEGMENT15_15   1
   #define SEGMENT15_16   1
   #define SEGMENT15_17   1
   #define SEGMENT15_18   1
   #define SEGMENT15_19   1
   #define SEGMENT15_20   1
   #define SEGMENT15_21   1
   #define SEGMENT15_22   1
   #define SEGMENT15_23   1
   #define SEGMENT15_24   1
   #define SEGMENT15_25   1
   #define SEGMENT15_26   1
   #define SEGMENT15_27   1
   #define SEGMENT15_28   1
   #define SEGMENT15_29   1
   #define SEGMENT15_30   2
   #define SEGMENT15_31   2
   #define SEGMENT15_32   2
   #define SEGMENT15_33   2
   #define SEGMENT15_34   2
   #define SEGMENT15_35   2
   #define SEGMENT15_36   2
   #define SEGMENT15_37   2
   #define SEGMENT15_38   2
   #define SEGMENT15_39   2
   #define SEGMENT15_40   2
   #define SEGMENT15_41   2
   #define SEGMENT15_42   2
   #define SEGMENT15_43   2
   #define SEGMENT15_44   2
   #define SEGMENT15_45   3
   #define SEGMENT15_46   3
   #define SEGMENT15_47   3
   #define SEGMENT15_48   3
   #define SEGMENT15_49   3
   #define SEGMENT15_50   3
   #define SEGMENT15_51   3
   #define SEGMENT15_52   3
   #define SEGMENT15_53   3
   #define SEGMENT15_54   3
   #define SEGMENT15_55   3
   #define SEGMENT15_56   3
   #define SEGMENT15_57   3
   #define SEGMENT15_58   3
   #define SEGMENT15_59   3
   #define SEGMENT15_60   4
   #define SEGMENT15_61   4
   #define SEGMENT15_62   4
   #define SEGMENT15_63   4
   #define SEGMENT15_64   4
   #define SEGMENT15_65   4
   #define SEGMENT15_66   4
   #define SEGMENT15_67   4
   #define SEGMENT15_68   4
   #define SEGMENT15_69   4
   #define SEGMENT15_70   4
   #define SEGMENT15_71   4
   #define SEGMENT15_72   4
   #define SEGMENT15_73   4
   #define SEGMENT15_74   4
   #define SEGMENT15_75   5
   #define SEGMENT15_76   5
   #define SEGMENT15_77   5
   #define SEGMENT15_78   5
   #define SEGMENT15_79   5
   #define SEGMENT15_80   5
   #define SEGMENT15_81   5
   #define SEGMENT15_82   5
   #define SEGMENT15_83   5
   #define SEGMENT15_84   5
   #define SEGMENT15_85   5
   #define SEGMENT15_86   5
   #define SEGMENT15_87   5
   #define SEGMENT15_88   5
   #define SEGMENT15_89   5
   #define SEGMENT15_90   6
   #define SEGMENT15_91   6
   #define SEGMENT15_92   6
   #define SEGMENT15_93   6
   #define SEGMENT15_94   6
   #define SEGMENT15_95   6
   #define SEGMENT15_96   6
   #define SEGMENT15_97   6
   #define SEGMENT15_98   6
   #define SEGMENT15_99   6
   #define SEGMENT15_100  6
   #define SEGMENT15_101  6
   #define SEGMENT15_102  6
   #define SEGMENT15_103  6
   #define SEGMENT15_104  6
   #define SEGMENT15_105  7
   #define SEGMENT15_106  7
   #define SEGMENT15_107  7
   #define SEGMENT15_108  7
   #define SEGMENT15_109  7
   #define SEGMENT15_110  7
   #define SEGMENT15_111  7
   #define SEGMENT15_112  7
   #define SEGMENT15_113  7
   #define SEGMENT15_114  7
   #define SEGMENT15_115  7
   #define SEGMENT15_116  7
   #define SEGMENT15_117  7
   #define SEGMENT15_118  7
   #define SEGMENT15_119  7
   #define SEGMENT15_120  8
   #define SEGMENT15_121  8
   #define SEGMENT15_122  8
   #define SEGMENT15_123  8
   #define SEGMENT15_124  8
   #define SEGMENT15_125  8
   #define SEGMENT15_126  8
   #define SEGMENT15_127  8
   #define SEGMENT15_128  8
   #define SEGMENT15_129  8
   #define SEGMENT15_130  8
   #define SEGMENT15_131  8
   #define SEGMENT15_132  8
   #define SEGMENT15_133  8
   #define SEGMENT15_134  8
   #define SEGMENT15_135  9
   #define SEGMENT15_136  9
   #define SEGMENT15_137  9
   #define SEGMENT15_138  9
   #define SEGMENT15_139  9
   #define SEGMENT15_140  9
   #define SEGMENT15_141  9
   #define SEGMENT15_142  9
   #define SEGMENT15_143  9
   #define SEGMENT15_144  9
   #define SEGMENT15_145  9
   #define SEGMENT15_146  9
   #define SEGMENT15_147  9
   #define SEGMENT15_148  9
   #define SEGMENT15_149  9
   #define SEGMENT15_150 10
   #define SEGMENT15_151 10
   #define SEGMENT15_152 10
   #define SEGMENT15_153 10
   #define SEGMENT15_154 10
   #define SEGMENT15_155 10
   #define SEGMENT15_156 10
   #define SEGMENT15_157 10
   #define SEGMENT15_158 10
   #define SEGMENT15_159 10
   #define SEGMENT15_160 10
   #define SEGMENT15_161 10
   #define SEGMENT15_162 10
   #define SEGMENT15_163 10
   #define SEGMENT15_164 10
   #define SEGMENT15_165 11
   #define SEGMENT15_166 11
   #define SEGMENT15_167 11
   #define SEGMENT15_168 11
   #define SEGMENT15_169 11
   #define SEGMENT15_170 11
   #define SEGMENT15_171 11
   #define SEGMENT15_172 11
   #define SEGMENT15_173 11
   #define SEGMENT15_174 11
   #define SEGMENT15_175 11
   #define SEGMENT15_176 11
   #define SEGMENT15_177 11
   #define SEGMENT15_178 11
   #define SEGMENT15_179 11
   #define SEGMENT15_180 12
   #define SEGMENT15_181 12
   #define SEGMENT15_182 12
   #define SEGMENT15_183 12
   #define SEGMENT15_184 12
   #define SEGMENT15_185 12
   #define SEGMENT15_186 12
   #define SEGMENT15_187 12
   #define SEGMENT15_188 12
   #define SEGMENT15_189 12
   #define SEGMENT15_190 12
   #define SEGMENT15_191 12
   #define SEGMENT15_192 12
   #define SEGMENT15_193 12
   #define SEGMENT15_194 12
   #define SEGMENT15_195 13
   #define SEGMENT15_196 13
   #define SEGMENT15_197 13
   #define SEGMENT15_198 13
   #define SEGMENT15_199 13
   #define SEGMENT15_200 13
   #define SEGMENT15_201 13
   #define SEGMENT15_202 13
   #define SEGMENT15_203 13
   #define SEGMENT15_204 13
   #define SEGMENT15_205 13
   #define SEGMENT15_206 13
   #define SEGMENT15_207 12
   #define SEGMENT15_208 13
   #define SEGMENT15_209 13
   #define SEGMENT15_210 14
   #define SEGMENT15_211 14
   #define SEGMENT15_212 14
   #define SEGMENT15_213 14
   #define SEGMENT15_214 14
   #define SEGMENT15_215 14
   #define SEGMENT15_216 14
   #define SEGMENT15_217 14
   #define SEGMENT15_218 14
   #define SEGMENT15_219 14
   #define SEGMENT15_220 14
   #define SEGMENT15_221 14
   #define SEGMENT15_222 14
   #define SEGMENT15_223 13
   #define SEGMENT15_224 14
   #define SEGMENT15_225 15
   #define SEGMENT15_226 15
   #define SEGMENT15_227 15
   #define SEGMENT15_228 15
   #define SEGMENT15_229 15
   #define SEGMENT15_230 15
   #define SEGMENT15_231 15
   #define SEGMENT15_232 15
   #define SEGMENT15_233 15
   #define SEGMENT15_234 15
   #define SEGMENT15_235 15
   #define SEGMENT15_236 15
   #define SEGMENT15_237 15
   #define SEGMENT15_238 15
   #define SEGMENT15_239 15
   #define SEGMENT15_240 16
   #define SEGMENT15_241 16
   #define SEGMENT15_242 16
   #define SEGMENT15_243 16
   #define SEGMENT15_244 16
   #define SEGMENT15_245 16
   #define SEGMENT15_246 16
   #define SEGMENT15_247 16
   #define SEGMENT15_248 16
   #define SEGMENT15_249 16
   #define SEGMENT15_250 16
   #define SEGMENT15_251 16
   #define SEGMENT15_252 16
   #define SEGMENT15_253 16
   #define SEGMENT15_254 16
   #define SEGMENT15_255 17
   #define SEGMENT15_256 17
// ----- REST16     REST16_        --(18)→2           _(a1,a2,...,a18)→2 
   #define REST16_(...) REST16(COUNT_ARGS(__VA_ARGS__))  // conta gli argomenti e li segmenta per 16 partendo da 0
   #define REST16(n)    concatena(REST16_,n)
   #define REST16_0   0 
   #define REST16_1   1 
   #define REST16_2   2 
   #define REST16_3   3 
   #define REST16_4   4 
   #define REST16_5   5 
   #define REST16_6   6 
   #define REST16_7   7 
   #define REST16_8   8 
   #define REST16_9   9 
   #define REST16_10  10
   #define REST16_11  11
   #define REST16_12  12
   #define REST16_13  13
   #define REST16_14  14
   #define REST16_15  15
   #define REST16_16  0
   #define REST16_17  1 
   #define REST16_18  2 
   #define REST16_19  3 
   #define REST16_20  4 
   #define REST16_21  5 
   #define REST16_22  6 
   #define REST16_23  7 
   #define REST16_24  8 
   #define REST16_25  9 
   #define REST16_26  10
   #define REST16_27  11
   #define REST16_28  12
   #define REST16_29  13
   #define REST16_30  14
   #define REST16_31  15
   #define REST16_32  0
   #define REST16_33  1 
   #define REST16_34  2 
   #define REST16_35  3 
   #define REST16_36  4 
   #define REST16_37  5 
   #define REST16_38  6 
   #define REST16_39  7 
   #define REST16_40  8 
   #define REST16_41  9 
   #define REST16_42  10
   #define REST16_43  11
   #define REST16_44  12
   #define REST16_45  13
   #define REST16_46  14
   #define REST16_47  15
   #define REST16_48  0
   #define REST16_49  1 
   #define REST16_50  2 
   #define REST16_51  3 
   #define REST16_52  4 
   #define REST16_53  5 
   #define REST16_54  6 
   #define REST16_55  7 
   #define REST16_56  8 
   #define REST16_57  9 
   #define REST16_58  10
   #define REST16_59  11
   #define REST16_60  12
   #define REST16_61  13
   #define REST16_62  14
   #define REST16_63  15
   #define REST16_64  0
   #define REST16_65  1 
   #define REST16_66  2 
   #define REST16_67  3 
   #define REST16_68  4 
   #define REST16_69  5 
   #define REST16_70  6 
   #define REST16_71  7 
   #define REST16_72  8 
   #define REST16_73  9 
   #define REST16_74  10
   #define REST16_75  11
   #define REST16_76  12
   #define REST16_77  13
   #define REST16_78  14
   #define REST16_79  15
   #define REST16_80  0
   #define REST16_81  1 
   #define REST16_82  2 
   #define REST16_83  3 
   #define REST16_84  4 
   #define REST16_85  5 
   #define REST16_86  6 
   #define REST16_87  7 
   #define REST16_88  8 
   #define REST16_89  9 
   #define REST16_90  10
   #define REST16_91  11
   #define REST16_92  12
   #define REST16_93  13
   #define REST16_94  14
   #define REST16_95  15
   #define REST16_96  0
   #define REST16_97  1 
   #define REST16_98  2 
   #define REST16_99  3 
   #define REST16_100 4 
   #define REST16_101 5 
   #define REST16_102 6 
   #define REST16_103 7 
   #define REST16_104 8 
   #define REST16_105 9 
   #define REST16_106 10
   #define REST16_107 11
   #define REST16_108 12
   #define REST16_109 13
   #define REST16_110 14
   #define REST16_111 15
   #define REST16_112 0
   #define REST16_113 1 
   #define REST16_114 2 
   #define REST16_115 3 
   #define REST16_116 4 
   #define REST16_117 5 
   #define REST16_118 6 
   #define REST16_119 7 
   #define REST16_120 8 
   #define REST16_121 9 
   #define REST16_122 10
   #define REST16_123 11
   #define REST16_124 12
   #define REST16_125 13
   #define REST16_126 14
   #define REST16_127 15
   #define REST16_128 0
   #define REST16_129 1 
   #define REST16_130 2 
   #define REST16_131 3 
   #define REST16_132 4 
   #define REST16_133 5 
   #define REST16_134 6 
   #define REST16_135 7 
   #define REST16_136 8 
   #define REST16_137 9 
   #define REST16_138 10
   #define REST16_139 11
   #define REST16_140 12
   #define REST16_141 13
   #define REST16_142 14
   #define REST16_143 15
   #define REST16_144 0
   #define REST16_145 1 
   #define REST16_146 2 
   #define REST16_147 3 
   #define REST16_148 4 
   #define REST16_149 5 
   #define REST16_150 6 
   #define REST16_151 7 
   #define REST16_152 8 
   #define REST16_153 9 
   #define REST16_154 10
   #define REST16_155 11
   #define REST16_156 12
   #define REST16_157 13
   #define REST16_158 14
   #define REST16_159 15
   #define REST16_160 0
   #define REST16_161 1 
   #define REST16_162 2 
   #define REST16_163 3 
   #define REST16_164 4 
   #define REST16_165 5 
   #define REST16_166 6 
   #define REST16_167 7 
   #define REST16_168 8 
   #define REST16_169 9 
   #define REST16_170 10
   #define REST16_171 11
   #define REST16_172 12
   #define REST16_173 13
   #define REST16_174 14
   #define REST16_175 15
   #define REST16_176 0
   #define REST16_177 1 
   #define REST16_178 2 
   #define REST16_179 3 
   #define REST16_180 4 
   #define REST16_181 5 
   #define REST16_182 6 
   #define REST16_183 7 
   #define REST16_184 8 
   #define REST16_185 9 
   #define REST16_186 10
   #define REST16_187 11
   #define REST16_188 12
   #define REST16_189 13
   #define REST16_190 14
   #define REST16_191 15
   #define REST16_192 0
   #define REST16_193 1 
   #define REST16_194 2 
   #define REST16_195 3 
   #define REST16_196 4 
   #define REST16_197 5 
   #define REST16_198 6 
   #define REST16_199 7 
   #define REST16_200 8 
   #define REST16_201 9 
   #define REST16_202 10
   #define REST16_203 11
   #define REST16_204 12
   #define REST16_205 13
   #define REST16_206 14
   #define REST16_207 15
   #define REST16_208 0
   #define REST16_209 1 
   #define REST16_210 2 
   #define REST16_211 3 
   #define REST16_212 4 
   #define REST16_213 5 
   #define REST16_214 6 
   #define REST16_215 7 
   #define REST16_216 8 
   #define REST16_217 9 
   #define REST16_218 10
   #define REST16_219 11
   #define REST16_220 12
   #define REST16_221 13
   #define REST16_222 14
   #define REST16_223 15
   #define REST16_224 0
   #define REST16_225 1 
   #define REST16_226 2 
   #define REST16_227 3 
   #define REST16_228 4 
   #define REST16_229 5 
   #define REST16_230 6 
   #define REST16_231 7 
   #define REST16_232 8 
   #define REST16_233 9 
   #define REST16_234 10
   #define REST16_235 11
   #define REST16_236 12
   #define REST16_237 13
   #define REST16_238 14
   #define REST16_239 15
   #define REST16_240 0
   #define REST16_241 1 
   #define REST16_242 2 
   #define REST16_243 3 
   #define REST16_244 4 
   #define REST16_245 5 
   #define REST16_246 6 
   #define REST16_247 7 
   #define REST16_248 8 
   #define REST16_249 9 
   #define REST16_250 10
   #define REST16_251 11
   #define REST16_252 12
   #define REST16_253 13
   #define REST16_254 14
   #define REST16_255 15
   #define REST16_256 0

// ----- RIPETI_                   --(2+,3)→ 2+2+2→ 6 
   #define RIPETI_(    M,n) concatena(RIPETI_, SEGMENT16(n))(M,n)
   #define RIPETI_0(   M,n) concatena(RIPETI_0_,  REST16(n))(M)
   #define RIPETI_0_1( M)   M
   #define RIPETI_0_2( M)   M M 
   #define RIPETI_0_3( M)   M M M
   #define RIPETI_0_4( M)   M M M M
   #define RIPETI_0_5( M)   M M M M M 
   #define RIPETI_0_6( M)   M M M M M M 
   #define RIPETI_0_7( M)   M M M M M M M
   #define RIPETI_0_8( M)   M M M M M M M M
   #define RIPETI_0_9( M)   M M M M M M M M M 
   #define RIPETI_0_10(M)   M M M M M M M M M M 
   #define RIPETI_0_11(M)   M M M M M M M M M M M
   #define RIPETI_0_12(M)   M M M M M M M M M M M M
   #define RIPETI_0_13(M)   M M M M M M M M M M M M M
   #define RIPETI_0_14(M)   M M M M M M M M M M M M M M 
   #define RIPETI_0_15(M)   M M M M M M M M M M M M M M M
   #define RIPETI_0_16(M)   M M M M M M M M M M M M M M M M
   #define RIPETI_1( M,n)   RIPETI_0_16(M) RIPETI_0( M,n) 
   #define RIPETI_2( M,n)   RIPETI_0_16(M) RIPETI_1( M,n) 
   #define RIPETI_3( M,n)   RIPETI_0_16(M) RIPETI_2( M,n) 
   #define RIPETI_4( M,n)   RIPETI_0_16(M) RIPETI_3( M,n) 
   #define RIPETI_5( M,n)   RIPETI_0_16(M) RIPETI_4( M,n) 
   #define RIPETI_6( M,n)   RIPETI_0_16(M) RIPETI_5( M,n) 
   #define RIPETI_7( M,n)   RIPETI_0_16(M) RIPETI_6( M,n) 
   #define RIPETI_8( M,n)   RIPETI_0_16(M) RIPETI_7( M,n) 
   #define RIPETI_9( M,n)   RIPETI_0_16(M) RIPETI_8( M,n) 
   #define RIPETI_10(M,n)   RIPETI_0_16(M) RIPETI_9( M,n) 
   #define RIPETI_11(M,n)   RIPETI_0_16(M) RIPETI_10(M,n) 
   #define RIPETI_12(M,n)   RIPETI_0_16(M) RIPETI_11(M,n) 
   #define RIPETI_13(M,n)   RIPETI_0_16(M) RIPETI_12(M,n) 
   #define RIPETI_14(M,n)   RIPETI_0_16(M) RIPETI_13(M,n) 
   #define RIPETI_15(M,n)   RIPETI_0_16(M) RIPETI_14(M,n) 







// ----- FUN_ARGS                  --(pippo, 1, a,b,c)→ pippo(a) pippo(b) pippo(c)   (F, 2,a,...)→ F(a,b)      F(c,d)

   #define FUN_ARGS(F,n,...) concatena3(FUN_,n,ARGS)(F,__VA_ARGS__)  

 // ----- FUN_ARGS1                 --(pippo, a,b, c,d)         → pippo(a,b)     pippo(c,d)
   #define FUN_1ARGS(F,...)       concatena(FUN_1ARGS,  SEGMENT16_(__VA_ARGS__))(F,__VA_ARGS__)  
   #define FUN_1ARGS(    F,...)   concatena(FUN_1ARGS,  SEGMENT16_(__VA_ARGS__))(F,__VA_ARGS__)  
   #define FUN_1ARGS0(   F,...)   concatena(FUN_1ARGS0_,COUNT_ARGS(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_1ARGS0_0( F )                                      
   #define FUN_1ARGS0_1( F, a)                                   F(a) 
   #define FUN_1ARGS0_2( F, a,b)                                 F(a) F(b)  
   #define FUN_1ARGS0_3( F, a,b,c)                               F(a) F(b) F(c) 
   #define FUN_1ARGS0_4( F, a,b,c,d)                             F(a) F(b) F(c) F(d) 
   #define FUN_1ARGS0_5( F, a,b,c,d,e)                           F(a) F(b) F(c) F(d) F(e)  
   #define FUN_1ARGS0_6( F, a,b,c,d,e,f)                         F(a) F(b) F(c) F(d) F(e) F(f)  
   #define FUN_1ARGS0_7( F, a,b,c,d,e,f,g)                       F(a) F(b) F(c) F(d) F(e) F(f) F(g)  
   #define FUN_1ARGS0_8( F, a,b,c,d,e,f,g,h)                     F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h)  
   #define FUN_1ARGS0_9( F, a,b,c,d,e,f,g,h,i)                   F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h) F(i)  
   #define FUN_1ARGS0_10(F, a,b,c,d,e,f,g,h,i,j)                 F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h) F(i) F(j)  
   #define FUN_1ARGS0_11(F, a,b,c,d,e,f,g,h,i,j,k)               F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h) F(i) F(j) F(k) 
   #define FUN_1ARGS0_12(F, a,b,c,d,e,f,g,h,i,j,k,l)             F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h) F(i) F(j) F(k) F(l) 
   #define FUN_1ARGS0_13(F, a,b,c,d,e,f,g,h,i,j,k,l,m)           F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h) F(i) F(j) F(k) F(l) F(m) 
   #define FUN_1ARGS0_14(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n)         F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h) F(i) F(j) F(k) F(l) F(m) F(n) 
   #define FUN_1ARGS0_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)       F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h) F(i) F(j) F(k) F(l) F(m) F(n) F(o) 
   #define FUN_1ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)     F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h) F(i) F(j) F(k) F(l) F(m) F(n) F(o) F(p)
   #define FUN_1ARGS1(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_1ARGS0(F,__VA_ARGS__)  // 32
   #define FUN_1ARGS2(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_1ARGS1(F,__VA_ARGS__)  // 48
   #define FUN_1ARGS3(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_1ARGS2(F,__VA_ARGS__)  // 64
   #define FUN_1ARGS4(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_1ARGS3(F,__VA_ARGS__)  // 80
   #define FUN_1ARGS5(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_1ARGS4(F,__VA_ARGS__)  // 96
   #define FUN_1ARGS6(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_1ARGS5(F,__VA_ARGS__)  //112
   #define FUN_1ARGS7(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_1ARGS6(F,__VA_ARGS__)  //128

 // ----- FUN_ARGS2                 --(pippo, a,b, c,d)         → pippo(a,b)     pippo(c,d)
   #define FUN_2ARGS(    F,...) concatena(FUN_2ARGS,  SEGMENT16_(__VA_ARGS__))(F,__VA_ARGS__)  
   #define FUN_2ARGS0(   F,...) concatena(FUN_2ARGS0_,COUNT_ARGS(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_2ARGS0_0( F )                                 
   #define FUN_2ARGS0_2( F, a,b)                                 F(a,b)  
   #define FUN_2ARGS0_4( F, a,b,c,d)                             F(a,b) F(c,d) 
   #define FUN_2ARGS0_6( F, a,b,c,d,e,f)                         F(a,b) F(c,d) F(e,f)  
   #define FUN_2ARGS0_8( F, a,b,c,d,e,f,g,h)                     F(a,b) F(c,d) F(e,f) F(g,h)  
   #define FUN_2ARGS0_10(F, a,b,c,d,e,f,g,h,i,j)                 F(a,b) F(c,d) F(e,f) F(g,h) F(i,j)  
   #define FUN_2ARGS0_12(F, a,b,c,d,e,f,g,h,i,j,k,l)             F(a,b) F(c,d) F(e,f) F(g,h) F(i,j) F(k,l) 
   #define FUN_2ARGS0_14(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n)         F(a,b) F(c,d) F(e,f) F(g,h) F(i,j) F(k,l) F(m,n) 
   #define FUN_2ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)     F(a,b) F(c,d) F(e,f) F(g,h) F(i,j) F(k,l) F(m,n) F(o,p)
   #define FUN_2ARGS1(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_2ARGS0(F,__VA_ARGS__)  // 32
   #define FUN_2ARGS2(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_2ARGS1(F,__VA_ARGS__)  // 48
   #define FUN_2ARGS3(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_2ARGS2(F,__VA_ARGS__)  // 64
   #define FUN_2ARGS4(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_2ARGS3(F,__VA_ARGS__)  // 80
   #define FUN_2ARGS5(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_2ARGS4(F,__VA_ARGS__)  // 96
   #define FUN_2ARGS6(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_2ARGS5(F,__VA_ARGS__)  //112
   #define FUN_2ARGS7(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_2ARGS6(F,__VA_ARGS__)  //128

 // ----- FUN_ARGS3                 --(pippo, a,b,c, d,e,f)     → pippo(a,b,c)   pippo(d,e,f)
   #define FUN_3ARGS(    F,...) concatena(FUN_3ARGS  ,SEGMENT16_(__VA_ARGS__))(F,__VA_ARGS__)  
   #define FUN_3ARGS0(   F,...) concatena(FUN_3ARGS0_,COUNT_ARGS(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_3ARGS0_0( F )                                     
   #define FUN_3ARGS0_3( F, a,b,c)                               F(a,b,c) 
   #define FUN_3ARGS0_6( F, a,b,c,d,e,f)                         F(a,b,c) F(d,e,f)  
   #define FUN_3ARGS0_9( F, a,b,c,d,e,f,g,h,i)                   F(a,b,c) F(d,e,f) F(g,h,i)  
   #define FUN_3ARGS0_12(F, a,b,c,d,e,f,g,h,i,j,k,l)             F(a,b,c) F(d,e,f) F(g,h,i) F(j,k,l) 
   #define FUN_3ARGS0_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)       F(a,b,c) F(d,e,f) F(g,h,i) F(j,k,l) F(m,n,o) 
   #define FUN_3ARGS1(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS0_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) FUN_3ARGS0(F,__VA_ARGS__)  // 32
   #define FUN_3ARGS2(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS0_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) FUN_3ARGS1(F,__VA_ARGS__)  // 48
   #define FUN_3ARGS3(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS0_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) FUN_3ARGS2(F,__VA_ARGS__)  // 64
   #define FUN_3ARGS4(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS0_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) FUN_3ARGS3(F,__VA_ARGS__)  // 80
   #define FUN_3ARGS5(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS0_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) FUN_3ARGS4(F,__VA_ARGS__)  // 96
   #define FUN_3ARGS6(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS0_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) FUN_3ARGS5(F,__VA_ARGS__)  //112
   #define FUN_3ARGS7(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS0_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) FUN_3ARGS6(F,__VA_ARGS__)  //128
 // ----- FUN_ARGS4                 --(pippo, a,b,c,d, e,f,g,h) → pippo(a,b,c,d) pippo(e,f,g,h)
   #define FUN_4ARGS(    F,...) concatena(FUN_4ARGS  ,SEGMENT16_(__VA_ARGS__))(F,__VA_ARGS__)  
   #define FUN_4ARGS0(   F,...) concatena(FUN_4ARGS0_,COUNT_ARGS(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_4ARGS0_0( F )                                       
   #define FUN_4ARGS0_4( F, a,b,c,d)                               F(a,b,c,d) 
   #define FUN_4ARGS0_8( F, a,b,c,d,e,f,g,h)                       F(a,b,c,d) F(e,f,g,h)  
   #define FUN_4ARGS0_12(F, a,b,c,d,e,f,g,h,i,j,k,l)               F(a,b,c,d) F(e,f,g,h) F(i,j,k,l) 
   #define FUN_4ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)       F(a,b,c,d) F(e,f,g,h) F(i,j,k,l) F(m,n,o,p) 
   #define FUN_4ARGS1(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...)   FUN_4ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_4ARGS0(F,__VA_ARGS__)  // 32
   #define FUN_4ARGS2(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...)   FUN_4ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_4ARGS1(F,__VA_ARGS__)  // 48
   #define FUN_4ARGS3(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...)   FUN_4ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_4ARGS2(F,__VA_ARGS__)  // 64
   #define FUN_4ARGS4(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...)   FUN_4ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_4ARGS3(F,__VA_ARGS__)  // 80
   #define FUN_4ARGS5(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...)   FUN_4ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_4ARGS4(F,__VA_ARGS__)  // 96
   #define FUN_4ARGS6(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...)   FUN_4ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_4ARGS5(F,__VA_ARGS__)  //112
   #define FUN_4ARGS7(   F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...)   FUN_4ARGS0_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) FUN_4ARGS6(F,__VA_ARGS__)  //128

// ----- FUN_ARGS_LIST             --(pippo, 1,a,b)   → pippo(a),pippo(b)            (F, 4,a,...)→ F(a,b,c,d), F(e,f,g,h) 

   #define FUN_ARGS_LIST(    F,n,...) concatena3(FUN_,n,ARGS_LIST)(F,__VA_ARGS__)  

  // ----- FUN_1ARGS_LIST          --(pippo, a,b)              → pippo(a),      pippo(b)
   #define FUN_1ARGS_LIST(    F,...) concatena(FUN_1ARGS_LIST  ,SEGMENT16_(__VA_ARGS__))(F,__VA_ARGS__)  
   #define FUN_1ARGS_LIST0(   F,...) concatena(FUN_1ARGS_LIST0_,COUNT_ARGS(__VA_ARGS__))(F,__VA_ARGS__)                   
   #define FUN_1ARGS_LIST0_1( F,a)                                   F(a) 
   #define FUN_1ARGS_LIST0_2( F,a,b)                                 F(a),F(b)
   #define FUN_1ARGS_LIST0_3( F,a,b,c)                               F(a),F(b),F(c)
   #define FUN_1ARGS_LIST0_4( F,a,b,c,d)                             F(a),F(b),F(c),F(d)
   #define FUN_1ARGS_LIST0_5( F,a,b,c,d,e)                           F(a),F(b),F(c),F(d),F(e)
   #define FUN_1ARGS_LIST0_6( F,a,b,c,d,e,f)                         F(a),F(b),F(c),F(d),F(e),F(f)
   #define FUN_1ARGS_LIST0_7( F,a,b,c,d,e,f,g)                       F(a),F(b),F(c),F(d),F(e),F(f),F(g)
   #define FUN_1ARGS_LIST0_8( F,a,b,c,d,e,f,g,h)                     F(a),F(b),F(c),F(d),F(e),F(f),F(g),F(h)
   #define FUN_1ARGS_LIST0_9( F,a,b,c,d,e,f,g,h,i)                   F(a),F(b),F(c),F(d),F(e),F(f),F(g),F(h),F(i)
   #define FUN_1ARGS_LIST0_10(F,a,b,c,d,e,f,g,h,i,j)                 F(a),F(b),F(c),F(d),F(e),F(f),F(g),F(h),F(i),F(j)
   #define FUN_1ARGS_LIST0_11(F,a,b,c,d,e,f,g,h,i,j,k)               F(a),F(b),F(c),F(d),F(e),F(f),F(g),F(h),F(i),F(j),F(k)
   #define FUN_1ARGS_LIST0_12(F,a,b,c,d,e,f,g,h,i,j,k,l)             F(a),F(b),F(c),F(d),F(e),F(f),F(g),F(h),F(i),F(j),F(k),F(l)
   #define FUN_1ARGS_LIST0_13(F,a,b,c,d,e,f,g,h,i,j,k,l,m)           F(a),F(b),F(c),F(d),F(e),F(f),F(g),F(h),F(i),F(j),F(k),F(l),F(m)
   #define FUN_1ARGS_LIST0_14(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n)         F(a),F(b),F(c),F(d),F(e),F(f),F(g),F(h),F(i),F(j),F(k),F(l),F(m),F(n)
   #define FUN_1ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)       F(a),F(b),F(c),F(d),F(e),F(f),F(g),F(h),F(i),F(j),F(k),F(l),F(m),F(n),F(o)
   #define FUN_1ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)     F(a),F(b),F(c),F(d),F(e),F(f),F(g),F(h),F(i),F(j),F(k),F(l),F(m),F(n),F(o),F(p)
   #define FUN_1ARGS_LIST1(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_1ARGS_LIST0(F,__VA_ARGS__)  // 32
   #define FUN_1ARGS_LIST2(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_1ARGS_LIST1(F,__VA_ARGS__)  // 48
   #define FUN_1ARGS_LIST3(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_1ARGS_LIST2(F,__VA_ARGS__)  // 64
   #define FUN_1ARGS_LIST4(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_1ARGS_LIST3(F,__VA_ARGS__)  // 80
   #define FUN_1ARGS_LIST5(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_1ARGS_LIST4(F,__VA_ARGS__)  // 96
   #define FUN_1ARGS_LIST6(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_1ARGS_LIST5(F,__VA_ARGS__)  //112
   #define FUN_1ARGS_LIST7(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_1ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_1ARGS_LIST6(F,__VA_ARGS__)  //128

  // ----- FUN_2ARGS_LIST          --(pippo, a,b, c,d) → pippo(a,b), pippo(c,d)     
   #define FUN_2ARGS_LIST(    F,...) concatena(FUN_2ARGS_LIST  ,SEGMENT16_(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_2ARGS_LIST0(   F,...) concatena(FUN_2ARGS_LIST0_,COUNT_ARGS(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_2ARGS_LIST0_2( F,a,b)                                 F(a,b)
   #define FUN_2ARGS_LIST0_4( F,a,b,c,d)                             F(a,b),F(c,d)
   #define FUN_2ARGS_LIST0_6( F,a,b,c,d,e,f)                         F(a,b),F(c,d),F(e,f)
   #define FUN_2ARGS_LIST0_8( F,a,b,c,d,e,f,g,h)                     F(a,b),F(c,d),F(e,f),F(g,h)
   #define FUN_2ARGS_LIST0_10(F,a,b,c,d,e,f,g,h,i,j)                 F(a,b),F(c,d),F(e,f),F(g,h),F(i,j)
   #define FUN_2ARGS_LIST0_12(F,a,b,c,d,e,f,g,h,i,j,k,l)             F(a,b),F(c,d),F(e,f),F(g,h),F(i,j),F(k,l)
   #define FUN_2ARGS_LIST0_14(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n)         F(a,b),F(c,d),F(e,f),F(g,h),F(i,j),F(k,l),F(m,n)
   #define FUN_2ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)     F(a,b),F(c,d),F(e,f),F(g,h),F(i,j),F(k,l),F(m,n),F(o,p)
   #define FUN_2ARGS_LIST1(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_2ARGS_LIST0(F,__VA_ARGS__)  // 32
   #define FUN_2ARGS_LIST2(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_2ARGS_LIST1(F,__VA_ARGS__)  // 48
   #define FUN_2ARGS_LIST3(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_2ARGS_LIST2(F,__VA_ARGS__)  // 64
   #define FUN_2ARGS_LIST4(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_2ARGS_LIST3(F,__VA_ARGS__)  // 80
   #define FUN_2ARGS_LIST5(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_2ARGS_LIST4(F,__VA_ARGS__)  // 96
   #define FUN_2ARGS_LIST6(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_2ARGS_LIST5(F,__VA_ARGS__)  //112
   #define FUN_2ARGS_LIST7(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_2ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_2ARGS_LIST6(F,__VA_ARGS__)  //128

  // ----- FUN_3ARGS_LIST          --(pippo, a,b,c, d,e,f) → pippo(a,b,c), pippo(d,e,f)
   #define FUN_3ARGS_LIST(    F,...) concatena(FUN_3ARGS_LIST  ,SEGMENT15_(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_3ARGS_LIST0(   F,...) concatena(FUN_3ARGS_LIST0_,COUNT_ARGS(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_3ARGS_LIST0_3( F,a,b,c)                               F(a,b,c)
   #define FUN_3ARGS_LIST0_6( F,a,b,c,d,e,f)                         F(a,b,c),F(d,e,f)
   #define FUN_3ARGS_LIST0_9( F,a,b,c,d,e,f,g,h,i)                   F(a,b,c),F(d,e,f),F(g,h,i)
   #define FUN_3ARGS_LIST0_12(F,a,b,c,d,e,f,g,h,i,j,k,l)             F(a,b,c),F(d,e,f),F(g,h,i),F(j,k,l)
   #define FUN_3ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)       F(a,b,c),F(d,e,f),F(g,h,i),F(j,k,l),F(m,n,o)
   #define FUN_3ARGS_LIST1(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o),FUN_3ARGS_LIST0(F,__VA_ARGS__)  // 30
   #define FUN_3ARGS_LIST2(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o),FUN_3ARGS_LIST1(F,__VA_ARGS__)  // 45
   #define FUN_3ARGS_LIST3(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o),FUN_3ARGS_LIST2(F,__VA_ARGS__)  // 60
   #define FUN_3ARGS_LIST4(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o),FUN_3ARGS_LIST3(F,__VA_ARGS__)  // 75
   #define FUN_3ARGS_LIST5(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o),FUN_3ARGS_LIST4(F,__VA_ARGS__)  // 90
   #define FUN_3ARGS_LIST6(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o),FUN_3ARGS_LIST5(F,__VA_ARGS__)  //105
   #define FUN_3ARGS_LIST7(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o),FUN_3ARGS_LIST6(F,__VA_ARGS__)  //120
   #define FUN_3ARGS_LIST8(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,...)   FUN_3ARGS_LIST0_15(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o),FUN_3ARGS_LIST7(F,__VA_ARGS__)  //135


  // ----- FUN_4ARGS_LIST          --(pippo, a,b,c,d,e,f,g,h) → pippo(a,b,c,d) , pippo(e,f,g,h)
   #define FUN_4ARGS_LIST(    F,...) concatena(FUN_4ARGS_LIST  ,SEGMENT16_(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_4ARGS_LIST0(   F,...) concatena(FUN_4ARGS_LIST0_,COUNT_ARGS(__VA_ARGS__))(F,__VA_ARGS__)
   #define FUN_4ARGS_LIST0_4( F,a,b,c,d)                             F(a,b,c,d)
   #define FUN_4ARGS_LIST0_8( F,a,b,c,d,e,f,g,h)                     F(a,b,c,d),F(e,f,g,h)
   #define FUN_4ARGS_LIST0_12(F,a,b,c,d,e,f,g,h,i,j,k,l)             F(a,b,c,d),F(e,f,g,h),F(i,j,k,l)
   #define FUN_4ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)     F(a,b,c,d),F(e,f,g,h),F(i,j,k,l),F(m,n,o,p)
   #define FUN_4ARGS_LIST1(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_4ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_4ARGS_LIST0(F,__VA_ARGS__)  // 32
   #define FUN_4ARGS_LIST2(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_4ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_4ARGS_LIST1(F,__VA_ARGS__)  // 48
   #define FUN_4ARGS_LIST3(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_4ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_4ARGS_LIST2(F,__VA_ARGS__)  // 64
   #define FUN_4ARGS_LIST4(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_4ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_4ARGS_LIST3(F,__VA_ARGS__)  // 80
   #define FUN_4ARGS_LIST5(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_4ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_4ARGS_LIST4(F,__VA_ARGS__)  // 96
   #define FUN_4ARGS_LIST6(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_4ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_4ARGS_LIST5(F,__VA_ARGS__)  //112
   #define FUN_4ARGS_LIST7(   F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) FUN_4ARGS_LIST0_16(F,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),FUN_4ARGS_LIST6(F,__VA_ARGS__)  //128




// ----- FUN_ARGS_ENUM             --(pippo, a,b,c)   → pippo(0,a) pippo(1,b) pippo(2,c)
   #define FUN_ARGS_ENUM(   F,...)       FUN_ARGS_enum(F,__VA_ARGS__)
   #define FUN_ARGS_enum(   F,...)       concatena(FUN_ARGS_ENUM, TENS_A(__VA_ARGS__) )(F,0,__VA_ARGS__)
   #define FUN_ARGS_ENUM0(  F, N, ...)   concatena(FUN_ARGS_ENUM_,COUNT_ARGS(__VA_ARGS__))(F,N,__VA_ARGS__)
   #define FUN_ARGS_ENUM_0( F, N)                                                                                                                                            // 
   #define FUN_ARGS_ENUM_1( F, N, a)                       F(0,a)                                                                // 
   #define FUN_ARGS_ENUM_2( F, N, a,b)                     F(0,a) F(1,b)                                                         //
   #define FUN_ARGS_ENUM_3( F, N, a,b,c)                   F(0,a) F(1,b) F(2,c)                                                  //
   #define FUN_ARGS_ENUM_4( F, N, a,b,c,d)                 F(0,a) F(1,b) F(2,c) F(3,d)                                           //
   #define FUN_ARGS_ENUM_5( F, N, a,b,c,d,e)               F(0,a) F(1,b) F(2,c) F(3,d) F(4,e)                                    //
   #define FUN_ARGS_ENUM_6( F, N, a,b,c,d,e,f)             F(0,a) F(1,b) F(2,c) F(3,d) F(4,e) F(5,f)                             //
   #define FUN_ARGS_ENUM_7( F, N, a,b,c,d,e,f,g)           F(0,a) F(1,b) F(2,c) F(3,d) F(4,e) F(5,f) F(6,g)                      //
   #define FUN_ARGS_ENUM_8( F, N, a,b,c,d,e,f,g,h)         F(0,a) F(1,b) F(2,c) F(3,d) F(4,e) F(5,f) F(6,g) F(7,h)               //    
   #define FUN_ARGS_ENUM_9( F, N, a,b,c,d,e,f,g,h,i)       F(0,a) F(1,b) F(2,c) F(3,d) F(4,e) F(5,f) F(6,g) F(7,h) F(8,i)        //  
   #define FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j)     F(0,a) F(1,b) F(2,c) F(3,d) F(4,e) F(5,f) F(6,g) F(7,h) F(8,i) F(9,j) //  
   #define FUN_ARGS_enum0(  F, N, ...)      concatena(FUN_ARGS_enum_,COUNT_ARGS(__VA_ARGS__))(F,N,__VA_ARGS__)
   #define FUN_ARGS_enum_0( F, N )                                                                                                                                            // 
   #define FUN_ARGS_enum_1( F, N, a)                       F(N##0,a)                                                                                           // 
   #define FUN_ARGS_enum_2( F, N, a,b)                     F(N##0,a) F(N##1,b)                                                                                 //
   #define FUN_ARGS_enum_3( F, N, a,b,c)                   F(N##0,a) F(N##1,b) F(N##2,c)                                                                       //
   #define FUN_ARGS_enum_4( F, N, a,b,c,d)                 F(N##0,a) F(N##1,b) F(N##2,c) F(N##3,d)                                                             //
   #define FUN_ARGS_enum_5( F, N, a,b,c,d,e)               F(N##0,a) F(N##1,b) F(N##2,c) F(N##3,d) F(N##4,e)                                                   //
   #define FUN_ARGS_enum_6( F, N, a,b,c,d,e,f)             F(N##0,a) F(N##1,b) F(N##2,c) F(N##3,d) F(N##4,e) F(N##5,f)                                         //
   #define FUN_ARGS_enum_7( F, N, a,b,c,d,e,f,g)           F(N##0,a) F(N##1,b) F(N##2,c) F(N##3,d) F(N##4,e) F(N##5,f) F(N##6,g)                               //
   #define FUN_ARGS_enum_8( F, N, a,b,c,d,e,f,g,h)         F(N##0,a) F(N##1,b) F(N##2,c) F(N##3,d) F(N##4,e) F(N##5,f) F(N##6,g) F(N##7,h)                     //    
   #define FUN_ARGS_enum_9( F, N, a,b,c,d,e,f,g,h,i)       F(N##0,a) F(N##1,b) F(N##2,c) F(N##3,d) F(N##4,e) F(N##5,f) F(N##6,g) F(N##7,h) F(N##8,i)           //  
   #define FUN_ARGS_enum_10(F, N, a,b,c,d,e,f,g,h,i,j)     F(N##0,a) F(N##1,b) F(N##2,c) F(N##3,d) F(N##4,e) F(N##5,f) F(N##6,g) F(N##7,h) F(N##8,i) F(N##9,j) //  
   #define FUN_ARGS_ENUM1(  F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_enum0( F, INC(N) , __VA_ARGS__)  // 10
   #define FUN_ARGS_ENUM2(  F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM1( F, INC(N) , __VA_ARGS__)  // 20 
   #define FUN_ARGS_ENUM3(  F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM2( F, INC(N) , __VA_ARGS__)  // 30   
   #define FUN_ARGS_ENUM4(  F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM3( F, INC(N) , __VA_ARGS__)  // 40   
   #define FUN_ARGS_ENUM5(  F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM4( F, INC(N) , __VA_ARGS__)  // 50   
   #define FUN_ARGS_ENUM6(  F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM5( F, INC(N) , __VA_ARGS__)  // 60   
   #define FUN_ARGS_ENUM7(  F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM6( F, INC(N) , __VA_ARGS__)  // 70
   #define FUN_ARGS_ENUM8(  F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM7( F, INC(N) , __VA_ARGS__)  // 80
   #define FUN_ARGS_ENUM9(  F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM8( F, INC(N) , __VA_ARGS__)  // 90
   #define FUN_ARGS_ENUM10( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM9( F, INC(N) , __VA_ARGS__)  // 100
   #define FUN_ARGS_ENUM11( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM10(F, INC(N) , __VA_ARGS__)  // 110
   #define FUN_ARGS_ENUM12( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM11(F, INC(N) , __VA_ARGS__)  // 120
   #define FUN_ARGS_ENUM13( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM12(F, INC(N) , __VA_ARGS__)  // 130
   #define FUN_ARGS_ENUM14( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM13(F, INC(N) , __VA_ARGS__)  // 140
   #define FUN_ARGS_ENUM15( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM14(F, INC(N) , __VA_ARGS__)  // 150
   #define FUN_ARGS_ENUM16( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM15(F, INC(N) , __VA_ARGS__)  // 160
   #define FUN_ARGS_ENUM17( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM16(F, INC(N) , __VA_ARGS__)  // 170
   #define FUN_ARGS_ENUM18( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM17(F, INC(N) , __VA_ARGS__)  // 180
   #define FUN_ARGS_ENUM19( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM18(F, INC(N) , __VA_ARGS__)  // 190
   #define FUN_ARGS_ENUM20( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM19(F, INC(N) , __VA_ARGS__)  // 200
   #define FUN_ARGS_ENUM21( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM20(F, INC(N) , __VA_ARGS__)  // 210
   #define FUN_ARGS_ENUM22( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM21(F, INC(N) , __VA_ARGS__)  // 220
   #define FUN_ARGS_ENUM23( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM22(F, INC(N) , __VA_ARGS__)  // 230
   #define FUN_ARGS_ENUM24( F, N, a,b,c,d,e,f,g,h,i,j,...) FUN_ARGS_ENUM_10(F, N, a,b,c,d,e,f,g,h,i,j) FUN_ARGS_ENUM23(F, INC(N) , __VA_ARGS__)  // 240

// ----- ARG_FUNS    Act Set Res   --(act, led1,led2) → led1(act); led2(act);    Act(led1,led2,tim1)→ led1(act);led2(act);tim1(act);
  #define ARG_FUNS(   F, ...)  ARG_FUNS0(F  , __VA_ARGS__)                     // ARG_FUNS(act,led1,led2,led3) ARG_FUNS(set,led1,led2,led3)
  #define Act(           ...)  ARG_FUNS0(act, __VA_ARGS__)                     // Act(led1,led2,led3) molto efficente, il compilatore ottimizza tutto in una sola scrittura nella variabile oA
  #define Set(           ...)  ARG_FUNS0(set, __VA_ARGS__)                     //
  #define Res(           ...)  ARG_FUNS0(res, __VA_ARGS__)                     //
  #define Tgl(           ...)  ARG_FUNS0(tgl, __VA_ARGS__)                     //
  #define ARG_FUNS0(  F, ...)  concatena(ARG_FUNS_,COUNT_ARGS(__VA_ARGS__))(F,__VA_ARGS__)       // uso  macronumargs2 perchè macronumargs è già usata da led1(act);
  #define ARG_FUNS_0( F )                                                              //
  #define ARG_FUNS_1( F, a)                               a(F);                        //
  #define ARG_FUNS_2( F, a,b)                             a(F);b(F);                   //
  #define ARG_FUNS_3( F, a,b,c)                           a(F);b(F);c(F);              // led1(act);led2(act);led3(act); → bitSet(oA,1);bitSet(oA,2);bitSet(oA,3);
  #define ARG_FUNS_4( F, a,b,c,d)                         a(F);b(F);c(F);d(F);         //
  #define ARG_FUNS_5( F, a,b,c,d,e)                       a(F);b(F);c(F);d(F);e(F);
  #define ARG_FUNS_6( F, a,b,c,d,e,f)                     a(F);b(F);c(F);d(F);e(F);f(F);
  #define ARG_FUNS_7( F, a,b,c,d,e,f,g)                   a(F);b(F);c(F);d(F);e(F);f(F);g(F);
  #define ARG_FUNS_8( F, a,b,c,d,e,f,g,h)                 a(F);b(F);c(F);d(F);e(F);f(F);g(F);h(F);
  #define ARG_FUNS_9( F, a,b,c,d,e,f,g,h,i)               a(F);b(F);c(F);d(F);e(F);f(F);g(F);h(F);i(F);
  #define ARG_FUNS_10(F, a,b,c,d,e,f,g,h,i,j)             a(F);b(F);c(F);d(F);e(F);f(F);g(F);h(F);i(F);j(F);
  #define ARG_FUNS_11(F, a,b,c,d,e,f,g,h,i,j,k)           a(F);b(F);c(F);d(F);e(F);f(F);g(F);h(F);i(F);j(F);k(F);
  #define ARG_FUNS_12(F, a,b,c,d,e,f,g,h,i,j,k,l)         a(F);b(F);c(F);d(F);e(F);f(F);g(F);h(F);i(F);j(F);k(F);l(F);
  #define ARG_FUNS_13(F, a,b,c,d,e,f,g,h,i,j,k,l,m)       a(F);b(F);c(F);d(F);e(F);f(F);g(F);h(F);i(F);j(F);k(F);l(F);m(F);
  #define ARG_FUNS_14(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n)     a(F);b(F);c(F);d(F);e(F);f(F);g(F);h(F);i(F);j(F);k(F);l(F);m(F);n(F);
  #define ARG_FUNS_15(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)   a(F);b(F);c(F);d(F);e(F);f(F);g(F);h(F);i(F);j(F);k(F);l(F);m(F);n(F);o(F);
  #define ARG_FUNS_16(F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) a(F);b(F);c(F);d(F);e(F);f(F);g(F);h(F);i(F);j(F);k(F);l(F);m(F);n(F);o(F);p(F);


// ----- ARGS_FUNS_LIST            --(1, a, led1,led2)→ led1(a),led2(a)          (6, a,l,p,ar,lr,pr, tictac,asin1)  tictac(a),tictac(l),tictac(p),tictac(ar),tictac(lr),tictac(pr), asin(a),asin(l),asin(p),asin(ar),asin(lr),asin(pr)
  #define ARGS_FUNS_LIST(  ...)           ARGS_FUNS_LISt(__VA_ARGS__)
  #define ARGS_FUNS_LISt(n,...)           concatena3(ARG,n,_FUNS_LIST)(__VA_ARGS__)

  #define ARG1_FUNS_LIST(      ...)       ARG1_FUNS_list(__VA_ARGS__)
  #define ARG1_FUNS_list(   A, ...)       concatena(ARG1_FUNS_LIST, SEGMENT16_(__VA_ARGS__))(A,__VA_ARGS__)
  #define ARG1_FUNS_LIST0(  A, ...)       concatena(ARG1_FUNS_LIST_,COUNT_ARGS(__VA_ARGS__))(A,__VA_ARGS__) 
  #define ARG1_FUNS_LIST_0( A)
  #define ARG1_FUNS_LIST_1( A, a)                                   a(A)
  #define ARG1_FUNS_LIST_2( A, a,b)                                 a(A),b(A)
  #define ARG1_FUNS_LIST_3( A, a,b,c)                               a(A),b(A),c(A)
  #define ARG1_FUNS_LIST_4( A, a,b,c,d)                             a(A),b(A),c(A),d(A)  
  #define ARG1_FUNS_LIST_5( A, a,b,c,d,e)                           a(A),b(A),c(A),d(A),e(A)
  #define ARG1_FUNS_LIST_6( A, a,b,c,d,e,f)                         a(A),b(A),c(A),d(A),e(A),f(A)
  #define ARG1_FUNS_LIST_7( A, a,b,c,d,e,f,g)                       a(A),b(A),c(A),d(A),e(A),f(A),g(A)
  #define ARG1_FUNS_LIST_8( A, a,b,c,d,e,f,g,h)                     a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A)
  #define ARG1_FUNS_LIST_9( A, a,b,c,d,e,f,g,h,i)                   a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A)
  #define ARG1_FUNS_LIST_10(A, a,b,c,d,e,f,g,h,i,j)                 a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A)
  #define ARG1_FUNS_LIST_11(A, a,b,c,d,e,f,g,h,i,j,k)               a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A)
  #define ARG1_FUNS_LIST_12(A, a,b,c,d,e,f,g,h,i,j,k,l)             a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A),l(A)
  #define ARG1_FUNS_LIST_13(A, a,b,c,d,e,f,g,h,i,j,k,l,m)           a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A),l(A),m(A)
  #define ARG1_FUNS_LIST_14(A, a,b,c,d,e,f,g,h,i,j,k,l,m,n)         a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A),l(A),m(A),n(A)
  #define ARG1_FUNS_LIST_15(A, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)       a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A),l(A),m(A),n(A),o(A)
  #define ARG1_FUNS_LIST_16(A, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)     a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A),l(A),m(A),n(A),o(A),p(A)
  #define ARG1_FUNS_LIST1(  A, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A),l(A),m(A),n(A),o(A),p(A), ARG1_FUNS_LIST0(A, __VA_ARGS__)  // 32
  #define ARG1_FUNS_LIST2(  A, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A),l(A),m(A),n(A),o(A),p(A), ARG1_FUNS_LIST1(A, __VA_ARGS__)  // 48
  #define ARG1_FUNS_LIST3(  A, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A),l(A),m(A),n(A),o(A),p(A), ARG1_FUNS_LIST2(A, __VA_ARGS__)  // 64
  #define ARG1_FUNS_LIST4(  A, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) a(A),b(A),c(A),d(A),e(A),f(A),g(A),h(A),i(A),j(A),k(A),l(A),m(A),n(A),o(A),p(A), ARG1_FUNS_LIST3(A, __VA_ARGS__)  // 64

  #define ARG2_FUNS_LIST(        ...)     ARG2_FUNS_list(__VA_ARGS__)
  #define ARG2_FUNS_list(   A,B, ...)     concatena(ARG2_FUNS_LIST, SEGMENT16_(__VA_ARGS__))(A,B,__VA_ARGS__)
  #define ARG2_FUNS_LIST0(  A,B, ...)     concatena(ARG2_FUNS_LIST_,COUNT_ARGS(__VA_ARGS__))(A,B,__VA_ARGS__) 
  #define ARG2_FUNS_LIST_0( A,B)                               
  #define ARG2_FUNS_LIST_1( A,B, a)                               a(A),a(B)
  #define ARG2_FUNS_LIST_2( A,B, a,b)                             a(A),a(B), b(A),b(B)
  #define ARG2_FUNS_LIST_3( A,B, a,b,c)                           a(A),a(B), b(A),b(B), c(A),c(B)
  #define ARG2_FUNS_LIST_4( A,B, a,b,c,d)                         a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B)  
  #define ARG2_FUNS_LIST_5( A,B, a,b,c,d,e)                       a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B)
  #define ARG2_FUNS_LIST_6( A,B, a,b,c,d,e,f)                     a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B)
  #define ARG2_FUNS_LIST_7( A,B, a,b,c,d,e,f,g)                   a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B)
  #define ARG2_FUNS_LIST_8( A,B, a,b,c,d,e,f,g,h)                 a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B), h(A),h(B)
  #define ARG2_FUNS_LIST_9( A,B, a,b,c,d,e,f,g,h,i)               a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B), h(A),h(B), i(A),i(B)
  #define ARG2_FUNS_LIST_10(A,B, a,b,c,d,e,f,g,h,i,j)             a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B), h(A),h(B), i(A),i(B), j(A),j(B)
  #define ARG2_FUNS_LIST_11(A,B, a,b,c,d,e,f,g,h,i,j,k)           a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B), h(A),h(B), i(A),i(B), j(A),j(B), k(A),k(B)
  #define ARG2_FUNS_LIST_12(A,B, a,b,c,d,e,f,g,h,i,j,k,l)         a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B), h(A),h(B), i(A),i(B), j(A),j(B), k(A),k(B), l(A),l(B)
  #define ARG2_FUNS_LIST_13(A,B, a,b,c,d,e,f,g,h,i,j,k,l,m)       a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B), h(A),h(B), i(A),i(B), j(A),j(B), k(A),k(B), l(A),l(B), m(A),m(B)
  #define ARG2_FUNS_LIST_14(A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n)     a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B), h(A),h(B), i(A),i(B), j(A),j(B), k(A),k(B), l(A),l(B), m(A),m(B), n(A),n(B)
  #define ARG2_FUNS_LIST_15(A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)   a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B), h(A),h(B), i(A),i(B), j(A),j(B), k(A),k(B), l(A),l(B), m(A),m(B), n(A),n(B), o(A),o(B)
  #define ARG2_FUNS_LIST_16(A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) a(A),a(B), b(A),b(B), c(A),c(B), d(A),d(B), e(A),e(B), f(A),f(B), g(A),g(B), h(A),h(B), i(A),i(B), j(A),j(B), k(A),k(B), l(A),l(B), m(A),m(B), n(A),n(B), o(A),o(B), p(A),p(B)
  #define ARG2_FUNS_LIST1(  A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG2_FUNS_LIST_16(A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),  ARG2_FUNS_LIST0(A,B __VA_ARGS__)
  #define ARG2_FUNS_LIST2(  A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG2_FUNS_LIST_16(A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),  ARG2_FUNS_LIST1(A,B __VA_ARGS__)
  #define ARG2_FUNS_LIST3(  A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG2_FUNS_LIST_16(A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),  ARG2_FUNS_LIST2(A,B __VA_ARGS__)
  #define ARG2_FUNS_LIST4(  A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG2_FUNS_LIST_16(A,B, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),  ARG2_FUNS_LIST3(A,B __VA_ARGS__)

  #define ARG3_FUNS_LIST(          ...)      ARG3_FUNS_list(__VA_ARGS__)
  #define ARG3_FUNS_list(   A,B,C, ...)      concatena(ARG3_FUNS_LIST, SEGMENT16_(__VA_ARGS__))(A,B,C, __VA_ARGS__)
  #define ARG3_FUNS_LIST0(  A,B,C, ...)      concatena(ARG3_FUNS_LIST_,COUNT_ARGS(__VA_ARGS__))(A,B,C, __VA_ARGS__)
  #define ARG3_FUNS_LIST_1( A,B,C, a)                               a(A),a(B),a(C)
  #define ARG3_FUNS_LIST_2( A,B,C, a,b)                             a(A),a(B),a(C), b(A),b(B),b(C)
  #define ARG3_FUNS_LIST_3( A,B,C, a,b,c)                           a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C)
  #define ARG3_FUNS_LIST_4( A,B,C, a,b,c,d)                         a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C)
  #define ARG3_FUNS_LIST_5( A,B,C, a,b,c,d,e)                       a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C)
  #define ARG3_FUNS_LIST_6( A,B,C, a,b,c,d,e,f)                     a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C)
  #define ARG3_FUNS_LIST_7( A,B,C, a,b,c,d,e,f,g)                   a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C)
  #define ARG3_FUNS_LIST_8( A,B,C, a,b,c,d,e,f,g,h)                 a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C), h(A),h(B),h(C)
  #define ARG3_FUNS_LIST_9( A,B,C, a,b,c,d,e,f,g,h,i)               a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C), h(A),h(B),h(C), i(A),i(B),i(C)
  #define ARG3_FUNS_LIST_10(A,B,C, a,b,c,d,e,f,g,h,i,j)             a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C), h(A),h(B),h(C), i(A),i(B),i(C), j(A),j(B),j(C)
  #define ARG3_FUNS_LIST_11(A,B,C, a,b,c,d,e,f,g,h,i,j,k)           a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C), h(A),h(B),h(C), i(A),i(B),i(C), j(A),j(B),j(C), k(A),k(B),k(C)
  #define ARG3_FUNS_LIST_12(A,B,C, a,b,c,d,e,f,g,h,i,j,k,l)         a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C), h(A),h(B),h(C), i(A),i(B),i(C), j(A),j(B),j(C), k(A),k(B),k(C), l(A),l(B),l(C)
  #define ARG3_FUNS_LIST_13(A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m)       a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C), h(A),h(B),h(C), i(A),i(B),i(C), j(A),j(B),j(C), k(A),k(B),k(C), l(A),l(B),l(C), m(A),m(B),m(C)
  #define ARG3_FUNS_LIST_14(A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n)     a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C), h(A),h(B),h(C), i(A),i(B),i(C), j(A),j(B),j(C), k(A),k(B),k(C), l(A),l(B),l(C), m(A),m(B),m(C), n(A),n(B),n(C)
  #define ARG3_FUNS_LIST_15(A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)   a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C), h(A),h(B),h(C), i(A),i(B),i(C), j(A),j(B),j(C), k(A),k(B),k(C), l(A),l(B),l(C), m(A),m(B),m(C), n(A),n(B),n(C), o(A),o(B),o(C)
  #define ARG3_FUNS_LIST_16(A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) a(A),a(B),a(C), b(A),b(B),b(C), c(A),c(B),c(C), d(A),d(B),d(C), e(A),e(B),e(C), f(A),f(B),f(C), g(A),g(B),g(C), h(A),h(B),h(C), i(A),i(B),i(C), j(A),j(B),j(C), k(A),k(B),k(C), l(A),l(B),l(C), m(A),m(B),m(C), n(A),n(B),n(C), o(A),o(B),o(C), p(A),p(B),p(C)
  #define ARG3_FUNS_LIST1(  A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG3_FUNS_LIST_16(A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),  ARG3_FUNS_LIST0(A,B,C, __VA_ARGS__)
  #define ARG3_FUNS_LIST2(  A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG3_FUNS_LIST_16(A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),  ARG3_FUNS_LIST1(A,B,C, __VA_ARGS__)
  #define ARG3_FUNS_LIST3(  A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG3_FUNS_LIST_16(A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),  ARG3_FUNS_LIST2(A,B,C, __VA_ARGS__)
  #define ARG3_FUNS_LIST4(  A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG3_FUNS_LIST_16(A,B,C, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p),  ARG3_FUNS_LIST3(A,B,C, __VA_ARGS__)

  #define ARG4_FUNS_LIST(           ...)      ARG4_FUNS_list(__VA_ARGS__)
  #define ARG4_FUNS_list(   A,B,C,D,...)      concatena(ARG4_FUNS_LIST, SEGMENT16_(__VA_ARGS__))(A,B,C,D, __VA_ARGS__)
  #define ARG4_FUNS_LIST0(  A,B,C,D,...)      concatena(ARG4_FUNS_LIST_,COUNT_ARGS(__VA_ARGS__))(A,B,C,D, __VA_ARGS__) 
  #define ARG4_FUNS_LIST_1( A,B,C,D, a)                               a(A),a(B),a(C),a(D)
  #define ARG4_FUNS_LIST_2( A,B,C,D, a,b)                             a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D)
  #define ARG4_FUNS_LIST_3( A,B,C,D, a,b,c)                           a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D)
  #define ARG4_FUNS_LIST_4( A,B,C,D, a,b,c,d)                         a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D)
  #define ARG4_FUNS_LIST_5( A,B,C,D, a,b,c,d,e)                       a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D)
  #define ARG4_FUNS_LIST_6( A,B,C,D, a,b,c,d,e,f)                     a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D)
  #define ARG4_FUNS_LIST_7( A,B,C,D, a,b,c,d,e,f,g)                   a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D)
  #define ARG4_FUNS_LIST_8( A,B,C,D, a,b,c,d,e,f,g,h)                 a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D), h(A),h(B),h(C),h(D)
  #define ARG4_FUNS_LIST_9( A,B,C,D, a,b,c,d,e,f,g,h,i)               a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D), h(A),h(B),h(C),h(D), i(A),i(B),i(C),i(D)
  #define ARG4_FUNS_LIST_10(A,B,C,D, a,b,c,d,e,f,g,h,i,j)             a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D), h(A),h(B),h(C),h(D), i(A),i(B),i(C),i(D), j(A),j(B),j(C),j(D)
  #define ARG4_FUNS_LIST_11(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k)           a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D), h(A),h(B),h(C),h(D), i(A),i(B),i(C),i(D), j(A),j(B),j(C),j(D), k(A),k(B),k(C),k(D)
  #define ARG4_FUNS_LIST_12(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l)         a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D), h(A),h(B),h(C),h(D), i(A),i(B),i(C),i(D), j(A),j(B),j(C),j(D), k(A),k(B),k(C),k(D), l(A),l(B),l(C),l(D)
  #define ARG4_FUNS_LIST_13(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m)       a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D), h(A),h(B),h(C),h(D), i(A),i(B),i(C),i(D), j(A),j(B),j(C),j(D), k(A),k(B),k(C),k(D), l(A),l(B),l(C),l(D), m(A),m(B),m(C),m(D)
  #define ARG4_FUNS_LIST_14(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n)     a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D), h(A),h(B),h(C),h(D), i(A),i(B),i(C),i(D), j(A),j(B),j(C),j(D), k(A),k(B),k(C),k(D), l(A),l(B),l(C),l(D), m(A),m(B),m(C),m(D), n(A),n(B),n(C),n(D)
  #define ARG4_FUNS_LIST_15(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)   a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D), h(A),h(B),h(C),h(D), i(A),i(B),i(C),i(D), j(A),j(B),j(C),j(D), k(A),k(B),k(C),k(D), l(A),l(B),l(C),l(D), m(A),m(B),m(C),m(D), n(A),n(B),n(C),n(D), o(A),o(B),o(C),o(D)
  #define ARG4_FUNS_LIST_16(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) a(A),a(B),a(C),a(D), b(A),b(B),b(C),b(D), c(A),c(B),c(C),c(D), d(A),d(B),d(C),d(D), e(A),e(B),e(C),e(D), f(A),f(B),f(C),f(D), g(A),g(B),g(C),g(D), h(A),h(B),h(C),h(D), i(A),i(B),i(C),i(D), j(A),j(B),j(C),j(D), k(A),k(B),k(C),k(D), l(A),l(B),l(C),l(D), m(A),m(B),m(C),m(D), n(A),n(B),n(C),n(D), o(A),o(B),o(C),o(D), p(A),p(B),p(C),p(D)
  #define ARG4_FUNS_LIST1(  A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG4_FUNS_LIST_16(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG4_FUNS_LIST0(A,B,C,D, __VA_ARGS__)
  #define ARG4_FUNS_LIST2(  A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG4_FUNS_LIST_16(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG4_FUNS_LIST1(A,B,C,D, __VA_ARGS__)
  #define ARG4_FUNS_LIST3(  A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG4_FUNS_LIST_16(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG4_FUNS_LIST2(A,B,C,D, __VA_ARGS__)
  #define ARG4_FUNS_LIST4(  A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG4_FUNS_LIST_16(A,B,C,D, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG4_FUNS_LIST3(A,B,C,D, __VA_ARGS__)

  #define ARG5_FUNS_LIST(             ...)      ARG5_FUNS_list(__VA_ARGS__)
  #define ARG5_FUNS_list(   A,B,C,D,E,...)      concatena(ARG5_FUNS_LIST, SEGMENT16_(__VA_ARGS__))(A,B,C,D,E, __VA_ARGS__)
  #define ARG5_FUNS_LIST0(  A,B,C,D,E,...)      concatena(ARG5_FUNS_LIST_,COUNT_ARGS(__VA_ARGS__))(A,B,C,D,E, __VA_ARGS__) 
  #define ARG5_FUNS_LIST_1( A,B,C,D,E, a)                               a(A),a(B),a(C),a(D),a(E)
  #define ARG5_FUNS_LIST_2( A,B,C,D,E, a,b)                             a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E)
  #define ARG5_FUNS_LIST_3( A,B,C,D,E, a,b,c)                           a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E)
  #define ARG5_FUNS_LIST_4( A,B,C,D,E, a,b,c,d)                         a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E)
  #define ARG5_FUNS_LIST_5( A,B,C,D,E, a,b,c,d,e)                       a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E)
  #define ARG5_FUNS_LIST_6( A,B,C,D,E, a,b,c,d,e,f)                     a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E)
  #define ARG5_FUNS_LIST_7( A,B,C,D,E, a,b,c,d,e,f,g)                   a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E)
  #define ARG5_FUNS_LIST_8( A,B,C,D,E, a,b,c,d,e,f,g,h)                 a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E), h(A),h(B),h(C),h(D),h(E)
  #define ARG5_FUNS_LIST_9( A,B,C,D,E, a,b,c,d,e,f,g,h,i)               a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E), h(A),h(B),h(C),h(D),h(E), i(A),i(B),i(C),i(D),i(E)
  #define ARG5_FUNS_LIST_10(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j)             a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E), h(A),h(B),h(C),h(D),h(E), i(A),i(B),i(C),i(D),i(E), j(A),j(B),j(C),j(D),j(E)
  #define ARG5_FUNS_LIST_11(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k)           a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E), h(A),h(B),h(C),h(D),h(E), i(A),i(B),i(C),i(D),i(E), j(A),j(B),j(C),j(D),j(E), k(A),k(B),k(C),k(D),k(E)
  #define ARG5_FUNS_LIST_12(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l)         a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E), h(A),h(B),h(C),h(D),h(E), i(A),i(B),i(C),i(D),i(E), j(A),j(B),j(C),j(D),j(E), k(A),k(B),k(C),k(D),k(E), l(A),l(B),l(C),l(D),l(E)
  #define ARG5_FUNS_LIST_13(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m)       a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E), h(A),h(B),h(C),h(D),h(E), i(A),i(B),i(C),i(D),i(E), j(A),j(B),j(C),j(D),j(E), k(A),k(B),k(C),k(D),k(E), l(A),l(B),l(C),l(D),l(E), m(A),m(B),m(C),m(D),m(E)
  #define ARG5_FUNS_LIST_14(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n)     a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E), h(A),h(B),h(C),h(D),h(E), i(A),i(B),i(C),i(D),i(E), j(A),j(B),j(C),j(D),j(E), k(A),k(B),k(C),k(D),k(E), l(A),l(B),l(C),l(D),l(E), m(A),m(B),m(C),m(D),m(E), n(A),n(B),n(C),n(D),n(E)
  #define ARG5_FUNS_LIST_15(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)   a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E), h(A),h(B),h(C),h(D),h(E), i(A),i(B),i(C),i(D),i(E), j(A),j(B),j(C),j(D),j(E), k(A),k(B),k(C),k(D),k(E), l(A),l(B),l(C),l(D),l(E), m(A),m(B),m(C),m(D),m(E), n(A),n(B),n(C),n(D),n(E), o(A),o(B),o(C),o(D),o(E)
  #define ARG5_FUNS_LIST_16(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) a(A),a(B),a(C),a(D),a(E), b(A),b(B),b(C),b(D),b(E), c(A),c(B),c(C),c(D),c(E), d(A),d(B),d(C),d(D),d(E), e(A),e(B),e(C),e(D),e(E), f(A),f(B),f(C),f(D),f(E), g(A),g(B),g(C),g(D),g(E), h(A),h(B),h(C),h(D),h(E), i(A),i(B),i(C),i(D),i(E), j(A),j(B),j(C),j(D),j(E), k(A),k(B),k(C),k(D),k(E), l(A),l(B),l(C),l(D),l(E), m(A),m(B),m(C),m(D),m(E), n(A),n(B),n(C),n(D),n(E), o(A),o(B),o(C),o(D),o(E), p(A),p(B),p(C),p(D),p(E)
  #define ARG5_FUNS_LIST1(  A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG5_FUNS_LIST_16(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG5_FUNS_LIST0(A,B,C,D,E, __VA_ARGS__)
  #define ARG5_FUNS_LIST2(  A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG5_FUNS_LIST_16(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG5_FUNS_LIST1(A,B,C,D,E, __VA_ARGS__)
  #define ARG5_FUNS_LIST3(  A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG5_FUNS_LIST_16(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG5_FUNS_LIST2(A,B,C,D,E, __VA_ARGS__)
  #define ARG5_FUNS_LIST4(  A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG5_FUNS_LIST_16(A,B,C,D,E, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG5_FUNS_LIST3(A,B,C,D,E, __VA_ARGS__)

  #define ARG6_FUNS_LIST(              ...)      ARG6_FUNS_list(__VA_ARGS__)
  #define ARG6_FUNS_list(   A,B,C,D,E,F,...)      concatena(ARG6_FUNS_LIST, SEGMENT16_(__VA_ARGS__))(A,B,C,D,E,F, __VA_ARGS__)
  #define ARG6_FUNS_LIST0(  A,B,C,D,E,F,...)      concatena(ARG6_FUNS_LIST_,COUNT_ARGS(__VA_ARGS__))(A,B,C,D,E,F, __VA_ARGS__) 
  #define ARG6_FUNS_LIST_1( A,B,C,D,E,F, a)                               a(A),a(B),a(C),a(D),a(E),a(F)
  #define ARG6_FUNS_LIST_2( A,B,C,D,E,F, a,b)                             a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F)
  #define ARG6_FUNS_LIST_3( A,B,C,D,E,F, a,b,c)                           a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F)
  #define ARG6_FUNS_LIST_4( A,B,C,D,E,F, a,b,c,d)                         a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F)
  #define ARG6_FUNS_LIST_5( A,B,C,D,E,F, a,b,c,d,e)                       a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F)
  #define ARG6_FUNS_LIST_6( A,B,C,D,E,F, a,b,c,d,e,f)                     a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F)
  #define ARG6_FUNS_LIST_7( A,B,C,D,E,F, a,b,c,d,e,f,g)                   a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F)
  #define ARG6_FUNS_LIST_8( A,B,C,D,E,F, a,b,c,d,e,f,g,h)                 a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F), h(A),h(B),h(C),h(D),h(E),h(F)
  #define ARG6_FUNS_LIST_9( A,B,C,D,E,F, a,b,c,d,e,f,g,h,i)               a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F), h(A),h(B),h(C),h(D),h(E),h(F), i(A),i(B),i(C),i(D),i(E),i(F)
  #define ARG6_FUNS_LIST_10(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j)             a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F), h(A),h(B),h(C),h(D),h(E),h(F), i(A),i(B),i(C),i(D),i(E),i(F), j(A),j(B),j(C),j(D),j(E),j(F)
  #define ARG6_FUNS_LIST_11(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k)           a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F), h(A),h(B),h(C),h(D),h(E),h(F), i(A),i(B),i(C),i(D),i(E),i(F), j(A),j(B),j(C),j(D),j(E),j(F), k(A),k(B),k(C),k(D),k(E),k(F)
  #define ARG6_FUNS_LIST_12(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l)         a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F), h(A),h(B),h(C),h(D),h(E),h(F), i(A),i(B),i(C),i(D),i(E),i(F), j(A),j(B),j(C),j(D),j(E),j(F), k(A),k(B),k(C),k(D),k(E),k(F), l(A),l(B),l(C),l(D),l(E),l(F)
  #define ARG6_FUNS_LIST_13(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m)       a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F), h(A),h(B),h(C),h(D),h(E),h(F), i(A),i(B),i(C),i(D),i(E),i(F), j(A),j(B),j(C),j(D),j(E),j(F), k(A),k(B),k(C),k(D),k(E),k(F), l(A),l(B),l(C),l(D),l(E),l(F), m(A),m(B),m(C),m(D),m(E),m(F)
  #define ARG6_FUNS_LIST_14(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n)     a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F), h(A),h(B),h(C),h(D),h(E),h(F), i(A),i(B),i(C),i(D),i(E),i(F), j(A),j(B),j(C),j(D),j(E),j(F), k(A),k(B),k(C),k(D),k(E),k(F), l(A),l(B),l(C),l(D),l(E),l(F), m(A),m(B),m(C),m(D),m(E),m(F), n(A),n(B),n(C),n(D),n(E),n(F)
  #define ARG6_FUNS_LIST_15(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)   a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F), h(A),h(B),h(C),h(D),h(E),h(F), i(A),i(B),i(C),i(D),i(E),i(F), j(A),j(B),j(C),j(D),j(E),j(F), k(A),k(B),k(C),k(D),k(E),k(F), l(A),l(B),l(C),l(D),l(E),l(F), m(A),m(B),m(C),m(D),m(E),m(F), n(A),n(B),n(C),n(D),n(E),n(F), o(A),o(B),o(C),o(D),o(E),o(F)
  #define ARG6_FUNS_LIST_16(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) a(A),a(B),a(C),a(D),a(E),a(F), b(A),b(B),b(C),b(D),b(E),b(F), c(A),c(B),c(C),c(D),c(E),c(F), d(A),d(B),d(C),d(D),d(E),d(F), e(A),e(B),e(C),e(D),e(E),e(F), f(A),f(B),f(C),f(D),f(E),f(F), g(A),g(B),g(C),g(D),g(E),g(F), h(A),h(B),h(C),h(D),h(E),h(F), i(A),i(B),i(C),i(D),i(E),i(F), j(A),j(B),j(C),j(D),j(E),j(F), k(A),k(B),k(C),k(D),k(E),k(F), l(A),l(B),l(C),l(D),l(E),l(F), m(A),m(B),m(C),m(D),m(E),m(F), n(A),n(B),n(C),n(D),n(E),n(F), o(A),o(B),o(C),o(D),o(E),o(F), p(A),p(B),p(C),p(D),p(E),p(F)
  #define ARG6_FUNS_LIST1(  A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG6_FUNS_LIST_16(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG6_FUNS_LIST0(A,B,C,D,E,F, __VA_ARGS__)
  #define ARG6_FUNS_LIST2(  A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG6_FUNS_LIST_16(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG6_FUNS_LIST1(A,B,C,D,E,F, __VA_ARGS__)
  #define ARG6_FUNS_LIST3(  A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG6_FUNS_LIST_16(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG6_FUNS_LIST2(A,B,C,D,E,F, __VA_ARGS__)
  #define ARG6_FUNS_LIST4(  A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) ARG6_FUNS_LIST_16(A,B,C,D,E,F, a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p), ARG6_FUNS_LIST3(A,B,C,D,E,F, __VA_ARGS__)


// ----- SELECTOR                  --(v, fun1,fun2,...) switch(v) case 0:{fun1;break;} case 2:{fun2;break;} case...        per fun complesse usare ({ funn })
  #define SELECTOR(v, ...)        switch(v){ SELECTOR_C(__VA_ARGS__) }
  #define SELECTOR_C(...)                    SELECTOR_c(__VA_ARGS__)
  #define SELECTOR_c(...)         FUN_ARGS_ENUM( SELECTOR_, __VA_ARGS__)  //spettacolare  SELECTOR_(0,ARG0); SELECTOR_(1,ARG1); ... ; SELECTOR_(n,ARGn); →case 0:{ARG0; break;}; case 1:{ARG1; break;}; ... ; case n:{ARGn; break;}
  #define SELECTOR_(i, body)      case i:  { body; break; }               //
// ----- SELECTORETURN             --(v, fun1,fun2,...) switch(v) case 0:{fun1;return 0;} case 2:{fun2;return 0;} case...  per fun complesse usare ({ funn })
  #define SELECTORETURN(v, ...)  switch(v){ SELECTORETURn(__VA_ARGS__) }
  #define SELECTORETURn(   ...)             SELECTORETUrn(__VA_ARGS__)
  #define SELECTORETUrn(  ...)   FUN_ARGS_ENUM( SELECTORETurn, __VA_ARGS__)
  #define SELECTORETurn(i, body) case i:  { body;  return 0; }
// ----- ARRAY                     --simula un array ma senza usare memoria , utile se l'indice è costante altrimenti espande l'intera funzione , in questo caso meglio array in flash , vedi sotto funzioni f_
   #define ARRAY(        ...) ARRAy(__VA_ARGS__)                                           // ARRAY puo contenere qualsiasi argomento
   #define ARRAy(  x, ...) concatena(ARRAy,TENS(x))(x,__VA_ARGS__)
   #define ARRAy0( x, ...) concatena(ARRay, x)(__VA_ARGS__)
   #define ARRay0(    a, ...) a
   #define ARRay1(    a,b, ...) b
   #define ARRay2(    a,b,c, ...) c
   #define ARRay3(    a,b,c,d, ...) d
   #define ARRay4(    a,b,c,d,e, ...) e
   #define ARRay5(    a,b,c,d,e,f, ...) f
   #define ARRay6(    a,b,c,d,e,f,g, ...) g
   #define ARRay7(    a,b,c,d,e,f,g,h, ...) h
   #define ARRay8(    a,b,c,d,e,f,g,h,i, ...) i
   #define ARRay9(    a,b,c,d,e,f,g,h,i,j, ...) j
   #define ARRAy1( x, a,b,c,d,e,f,g,h,i,j,...) concatena(ARRay, UNITS(x))(__VA_ARGS__)
   #define ARRAy2( x, a,b,c,d,e,f,g,h,i,j,...) ARRAy1( x,__VA_ARGS__)
   #define ARRAy3( x, a,b,c,d,e,f,g,h,i,j,...) ARRAy2( x,__VA_ARGS__)
   #define ARRAy4( x, a,b,c,d,e,f,g,h,i,j,...) ARRAy3( x,__VA_ARGS__)
   #define ARRAy5( x, a,b,c,d,e,f,g,h,i,j,...) ARRAy4( x,__VA_ARGS__)
   #define ARRAy6( x, a,b,c,d,e,f,g,h,i,j,...) ARRAy5( x,__VA_ARGS__)
   #define ARRAy7( x, a,b,c,d,e,f,g,h,i,j,...) ARRAy6( x,__VA_ARGS__)
   #define ARRAy8( x, a,b,c,d,e,f,g,h,i,j,...) ARRAy7( x,__VA_ARGS__)
   #define ARRAy9( x, a,b,c,d,e,f,g,h,i,j,...) ARRAy8( x,__VA_ARGS__)
   #define ARRAy10(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy9( x,__VA_ARGS__)
   #define ARRAy11(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy10(x,__VA_ARGS__)
   #define ARRAy12(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy11(x,__VA_ARGS__)
   #define ARRAy13(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy12(x,__VA_ARGS__)
   #define ARRAy14(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy13(x,__VA_ARGS__)
   #define ARRAy15(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy14(x,__VA_ARGS__)
   #define ARRAy16(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy15(x,__VA_ARGS__)
   #define ARRAy17(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy16(x,__VA_ARGS__)
   #define ARRAy18(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy17(x,__VA_ARGS__)
   #define ARRAy19(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy18(x,__VA_ARGS__)
   #define ARRAy20(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy19(x,__VA_ARGS__)
   #define ARRAy21(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy20(x,__VA_ARGS__)
   #define ARRAy22(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy21(x,__VA_ARGS__)
   #define ARRAy23(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy22(x,__VA_ARGS__)
   #define ARRAy24(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy23(x,__VA_ARGS__)
   #define ARRAy25(x, a,b,c,d,e,f,g,h,i,j,...) ARRAy24(x,__VA_ARGS__)

   // vedi esempi ...


// ----- BITStoBYTES               --(1,0,0,1) 0b00001001 impacchetta fino a 256 bits in 32 bytes  uint8_t a[]={BITStoBYTES(1,1,led1(a),1,1,0,0,tim1(l),0,1,0,1,1,0,0,0,0,1,1,1,1)}

   #define BITStoBYTES(...) BITStoBytes(__VA_ARGS__)                                           // permette l'espansione degli argomenti
   #define BITStoBytes(...) concatena(Bitstobytes,SEGMENT16_(__VA_ARGS__))(__VA_ARGS__)        // SEGMENT16_ restituisce il pack da espandere
                                                                                               //
   #define Bitstobytes0(   ...) concatena(Bitstobytes_,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)          // 
   #define Bitstobytes_0                                                                              // puo generare virgole pendenti ... verificare                                                                                                                  //
   #define Bitstobytes_1(  a)                                   (uc)(((a&1)<<0)                                                                             )                                                                                                //
   #define Bitstobytes_2(  a,b)                                 (uc)(((a&1)<<0)|((b&1)<<1)                                                                  )                                                                                                //
   #define Bitstobytes_3(  a,b,c)                               (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)                                                       )                                                                                                //
   #define Bitstobytes_4(  a,b,c,d)                             (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)                                            )                                                                                                //
   #define Bitstobytes_5(  a,b,c,d,e)                           (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)                                 )                                                                                                //
   #define Bitstobytes_6(  a,b,c,d,e,f)                         (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)                      )                                                                                                //
   #define Bitstobytes_7(  a,b,c,d,e,f,g)                       (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)           )                                                                                                //
   #define Bitstobytes_8(  a,b,c,d,e,f,g,h)                     (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7))                                                                                                //
   #define Bitstobytes_9(  a,b,c,d,e,f,g,h,A)                   (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)                                                                             ) //
   #define Bitstobytes_10( a,b,c,d,e,f,g,h,A,B)                 (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)                                                                  ) //
   #define Bitstobytes_11( a,b,c,d,e,f,g,h,A,B,C)               (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)                                                       ) //
   #define Bitstobytes_12( a,b,c,d,e,f,g,h,A,B,C,D)             (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)                                            ) //
   #define Bitstobytes_13( a,b,c,d,e,f,g,h,A,B,C,D,E)           (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)|((E&1)<<4)                                 ) //
   #define Bitstobytes_14( a,b,c,d,e,f,g,h,A,B,C,D,E,F)         (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)|((E&1)<<4)|((F&1)<<5)                      ) //
   #define Bitstobytes_15( a,b,c,d,e,f,g,h,A,B,C,D,E,F,G)       (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)|((E&1)<<4)|((F&1)<<5)|((G&1)<<6)           ) //
   #define Bitstobytes_16( a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H)     (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)|((E&1)<<4)|((F&1)<<5)|((G&1)<<6)|((H&1)<<7)) //

   #define Bitstobytes0(   ...) concatena(Bitstobytes_,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)          // 
   #define Bitstobytes0_0                                                                              // puo generare virgole pendenti ... verificare                                                                                                                  //
   #define Bitstobytes0_1(  a)                                   (uc)(((a&1)<<0)                                                                             )                                                                                                //
   #define Bitstobytes0_2(  a,b)                                 (uc)(((a&1)<<0)|((b&1)<<1)                                                                  )                                                                                                //
   #define Bitstobytes0_3(  a,b,c)                               (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)                                                       )                                                                                                //
   #define Bitstobytes0_4(  a,b,c,d)                             (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)                                            )                                                                                                //
   #define Bitstobytes0_5(  a,b,c,d,e)                           (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)                                 )                                                                                                //
   #define Bitstobytes0_6(  a,b,c,d,e,f)                         (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)                      )                                                                                                //
   #define Bitstobytes0_7(  a,b,c,d,e,f,g)                       (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)           )                                                                                                //
   #define Bitstobytes0_8(  a,b,c,d,e,f,g,h)                     (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7))                                                                                                //
   #define Bitstobytes0_9(  a,b,c,d,e,f,g,h,A)                   (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)                                                                             ) //
   #define Bitstobytes0_10( a,b,c,d,e,f,g,h,A,B)                 (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)                                                                  ) //
   #define Bitstobytes0_11( a,b,c,d,e,f,g,h,A,B,C)               (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)                                                       ) //
   #define Bitstobytes0_12( a,b,c,d,e,f,g,h,A,B,C,D)             (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)                                            ) //
   #define Bitstobytes0_13( a,b,c,d,e,f,g,h,A,B,C,D,E)           (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)|((E&1)<<4)                                 ) //
   #define Bitstobytes0_14( a,b,c,d,e,f,g,h,A,B,C,D,E,F)         (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)|((E&1)<<4)|((F&1)<<5)                      ) //
   #define Bitstobytes0_15( a,b,c,d,e,f,g,h,A,B,C,D,E,F,G)       (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)|((E&1)<<4)|((F&1)<<5)|((G&1)<<6)           ) //
   #define Bitstobytes0_16( a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H)     (uc)(((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)), (uc)(((A&1)<<0)|((B&1)<<1)|((C&1)<<2)|((D&1)<<3)|((E&1)<<4)|((F&1)<<5)|((G&1)<<6)|((H&1)<<7)) //

   #define Bitstobytes1(   a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes0( __VA_ARGS__) 
   #define Bitstobytes2(   a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes1( __VA_ARGS__) 
   #define Bitstobytes3(   a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes2( __VA_ARGS__) 
   #define Bitstobytes4(   a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes3( __VA_ARGS__) 
   #define Bitstobytes5(   a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes4( __VA_ARGS__) 
   #define Bitstobytes6(   a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes5( __VA_ARGS__) 
   #define Bitstobytes7(   a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes6( __VA_ARGS__) 
   #define Bitstobytes8(   a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes7( __VA_ARGS__) 
   #define Bitstobytes9(   a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes8( __VA_ARGS__) 
   #define Bitstobytes10(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes9( __VA_ARGS__) 
   #define Bitstobytes11(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes10(__VA_ARGS__) 
   #define Bitstobytes12(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes11(__VA_ARGS__) 
   #define Bitstobytes13(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes12(__VA_ARGS__) 
   #define Bitstobytes14(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes13(__VA_ARGS__) 
   #define Bitstobytes15(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes14(__VA_ARGS__) // 256
   #define Bitstobytes16(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes15(__VA_ARGS__) // 272
   #define Bitstobytes17(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes16(__VA_ARGS__) // 288
   #define Bitstobytes18(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes17(__VA_ARGS__) // 304
   #define Bitstobytes19(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes18(__VA_ARGS__) // 320
   #define Bitstobytes20(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes19(__VA_ARGS__) // 336
   #define Bitstobytes21(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes20(__VA_ARGS__) // 352
   #define Bitstobytes22(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes21(__VA_ARGS__) // 368
   #define Bitstobytes23(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes22(__VA_ARGS__) // 384
   #define Bitstobytes24(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes23(__VA_ARGS__) // 400
   #define Bitstobytes25(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes24(__VA_ARGS__) // 416
   #define Bitstobytes26(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes25(__VA_ARGS__) // 432
   #define Bitstobytes27(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes26(__VA_ARGS__) // 448
   #define Bitstobytes28(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes27(__VA_ARGS__) // 464
   #define Bitstobytes29(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes28(__VA_ARGS__) // 496
   #define Bitstobytes30(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes29(__VA_ARGS__) // 512
   #define Bitstobytes31(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes30(__VA_ARGS__) // 528
   #define Bitstobytes32(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes31(__VA_ARGS__) // 544
   #define Bitstobytes33(  a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,...) Bitstobytes_16(a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H), Bitstobytes32(__VA_ARGS__) // 560
  
// ----- bitsSet                   --bitsSet(var, 0, 4, ...) var=xxx1xxx1  modifica fino a 64bit
   #define ActOuts( ...) bitsSet(oA,__VA_ARGS__)           // ActOuts(led1,led3)  molto piu veloce di Act(led12,led2) in teoria ma le ottimizzazioni del compilatore lo rendono equivalente ...
   #define bitsSet(var,...) var = var | concatena(BITSSET, SEGMENT16_(__VA_ARGS__))(__VA_ARGS__)
   #define BITSSET0(   ...)  concatena(BITSSEt,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)
   #define BITSSEt0
   #define BITSSEt1(  a                              ) (1<<a)
   #define BITSSEt2(  a,b                            ) (1<<a)|(1<<b)
   #define BITSSEt3(  a,b,c                          ) (1<<a)|(1<<b)|(1<<c)
   #define BITSSEt4(  a,b,c,d                        ) (1<<a)|(1<<b)|(1<<c)|(1<<d)
   #define BITSSEt5(  a,b,c,d,e                      ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)
   #define BITSSEt6(  a,b,c,d,e,f                    ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)
   #define BITSSEt7(  a,b,c,d,e,f,g                  ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)
   #define BITSSEt8(  a,b,c,d,e,f,g,h                ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)|(1<<h)
   #define BITSSEt9(  a,b,c,d,e,f,g,h,i              ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)|(1<<h)|(1<<i)
   #define BITSSEt10( a,b,c,d,e,f,g,h,i,j            ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)|(1<<h)|(1<<i)|(1<<j)
   #define BITSSEt11( a,b,c,d,e,f,g,h,i,j,k          ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)|(1<<h)|(1<<i)|(1<<j)|(1<<k)
   #define BITSSEt12( a,b,c,d,e,f,g,h,i,j,k,l        ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)|(1<<h)|(1<<i)|(1<<j)|(1<<k)|(1<<l)
   #define BITSSEt13( a,b,c,d,e,f,g,h,i,j,k,l,m      ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)|(1<<h)|(1<<i)|(1<<j)|(1<<k)|(1<<l)|(1<<m)
   #define BITSSEt14( a,b,c,d,e,f,g,h,i,j,k,l,m,n    ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)|(1<<h)|(1<<i)|(1<<j)|(1<<k)|(1<<l)|(1<<m)|(1<<n)
   #define BITSSEt15( a,b,c,d,e,f,g,h,i,j,k,l,m,n,o  ) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)|(1<<h)|(1<<i)|(1<<j)|(1<<k)|(1<<l)|(1<<m)|(1<<n)|(1<<o)
   #define BITSSEt16( a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) (1<<a)|(1<<b)|(1<<c)|(1<<d)|(1<<)|(1<<f)|(1<<g)|(1<<h)|(1<<i)|(1<<j)|(1<<k)|(1<<l)|(1<<m)|(1<<n)|(1<<o)|(1<<p)
   #define BITSSET1(  a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) BITSSEt16( a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)| BITSSET0(__VA_ARGS__) // 32
   #define BITSSET2(  a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) BITSSEt16( a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)| BITSSET1(__VA_ARGS__) // 48
   #define BITSSET3(  a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,...) BITSSEt16( a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)| BITSSET2(__VA_ARGS__) // 64


// ----- bitsWrite                 --bitsWrite(var, 0,1, 4,0, ...) var=xxx0xxx1  modifica fino a 64bit
   #define bitsWrite(  var,...) (var)=((var) & ~( MASK(__VA_ARGS__) ) | ( VALUE(__VA_ARGS__) ) )

   #define MASK( ...) concatena(MASK, SEGMENT16_(__VA_ARGS__))(__VA_ARGS__)
   #define MASK0(...) concatena(MASk,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)
   #define MASk2(  a,A)                                         (1<<A)
   #define MASk4(  a,A, b,B)                                    (1<<A)|(1<<B)
   #define MASk6(  a,A, b,B, c,C)                               (1<<A)|(1<<B)|(1<<C)
   #define MASk8(  a,A, b,B, c,C, d,D)                          (1<<A)|(1<<B)|(1<<C)|(1<<D)                                          
   #define MASk10( a,A, b,B, c,C, d,D, e,E)                     (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)
   #define MASk12( a,A, b,B, c,C, d,D, e,E, f,F)                (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)
   #define MASk14( a,A, b,B, c,C, d,D, e,E, f,F, g,G)           (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G)
   #define MASk16( a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H)      (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G)|(1<<H)
   #define MASK1(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H, ...) (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G)|(1<<H)| MASK0(__VA_ARGS__) // 16
   #define MASK2(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H, ...) (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G)|(1<<H)| MASK1(__VA_ARGS__) // 24
   #define MASK3(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H, ...) (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G)|(1<<H)| MASK2(__VA_ARGS__) // 32
   #define MASK4(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H, ...) (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G)|(1<<H)| MASK3(__VA_ARGS__) // 40
   #define MASK5(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H, ...) (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G)|(1<<H)| MASK4(__VA_ARGS__) // 48
   #define MASK6(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H, ...) (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G)|(1<<H)| MASK5(__VA_ARGS__) // 56
   #define MASK7(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H, ...) (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G)|(1<<H)| MASK6(__VA_ARGS__) // 64

   #define VALUE( ...) concatena(VALUE, SEGMENT16_(__VA_ARGS__))(__VA_ARGS__)
   #define VALUE0(...) concatena(VALUe,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)
   #define VALUe0   
   #define VALUe2(  a,A)                                        (a<<A)
   #define VALUe4(  a,A, b,B)                                   (a<<A)|(b<<B)
   #define VALUe6(  a,A, b,B, c,C)                              (a<<A)|(b<<B)|(c<<C)
   #define VALUe8(  a,A, b,B, c,C, d,D)                         (a<<A)|(b<<B)|(c<<C)|(d<<D)
   #define VALUe10( a,A, b,B, c,C, d,D, e,E)                    (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)
   #define VALUe12( a,A, b,B, c,C, d,D, e,E, f,F)               (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)
   #define VALUe14( a,A, b,B, c,C, d,D, e,E, f,F, g,G)          (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)|(g<<G)
   #define VALUe16( a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H)     (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)|(g<<G)|(h<<H)
   #define VALUE1(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H,...) (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)|(g<<G)|(h<<H)| VALUE0(__VA_ARGS__) // 16
   #define VALUE2(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H,...) (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)|(g<<G)|(h<<H)| VALUE1(__VA_ARGS__) // 24
   #define VALUE3(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H,...) (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)|(g<<G)|(h<<H)| VALUE2(__VA_ARGS__) // 32
   #define VALUE4(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H,...) (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)|(g<<G)|(h<<H)| VALUE3(__VA_ARGS__) // 40
   #define VALUE5(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H,...) (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)|(g<<G)|(h<<H)| VALUE4(__VA_ARGS__) // 48
   #define VALUE6(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H,...) (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)|(g<<G)|(h<<H)| VALUE5(__VA_ARGS__) // 56
   #define VALUE7(  a,A, b,B, c,C, d,D, e,E, f,F, g,G, h,H,...) (a<<A)|(b<<B)|(c<<C)|(d<<D)|(e<<E)|(f<<F)|(g<<G)|(h<<H)| VALUE6(__VA_ARGS__) // 64



  

// ----- bitsToNumRev              --impacchetta fino a 64 bits in un numero invertendoli  , il primo è il meno significativo
   #define bitsToNumRev(...) packBTNR(__VA_ARGS__)                                               // permette l'espansione degli argomenti
   #define packBTNR(    ...) concatena(packBTNR,SEGMENT16_(__VA_ARGS__))(__VA_ARGS__)             // SEGMENT16_ restituisce il pack da espandere                                   //
   #define packBTNR0(   ...) concatena(packBTNR0_,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)          //
   #define packBTNR0_1( a)                                (((a&1)<<0))                                                                             
   #define packBTNR0_2( a,b)                              (((a&1)<<0)|((b&1)<<1))                                                                  
   #define packBTNR0_3( a,b,c)                            (((a&1)<<0)|((b&1)<<1)|((c&1)<<2))                                                       
   #define packBTNR0_4( a,b,c,d)                          (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3))
   #define packBTNR0_5( a,b,c,d,e)                        (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4))                                 
   #define packBTNR0_6( a,b,c,d,e,f)                      (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5))                      
   #define packBTNR0_7( a,b,c,d,e,f,g)                    (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6))           
   #define packBTNR0_8( a,b,c,d,e,f,g,h)                  (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7))
   #define packBTNR0_9( a,b,c,d,e,f,g,h, A)               (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)| ((A&1)<<8))
   #define packBTNR0_10(a,b,c,d,e,f,g,h, A,B)             (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)| ((A&1)<<8)|((B&1)<<9))
   #define packBTNR0_11(a,b,c,d,e,f,g,h, A,B,C)           (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)| ((A&1)<<8)|((B&1)<<9)|((C&1)<<10))
   #define packBTNR0_12(a,b,c,d,e,f,g,h, A,B,C,D)         (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)| ((A&1)<<8)|((B&1)<<9)|((C&1)<<10)|((D&1)<<11))
   #define packBTNR0_13(a,b,c,d,e,f,g,h, A,B,C,D,E)       (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)| ((A&1)<<8)|((B&1)<<9)|((C&1)<<10)|((D&1)<<11)|((E&1)<<12))
   #define packBTNR0_14(a,b,c,d,e,f,g,h, A,B,C,D,E,F)     (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)| ((A&1)<<8)|((B&1)<<9)|((C&1)<<10)|((D&1)<<11)|((E&1)<<12)|((F&1)<<13))
   #define packBTNR0_15(a,b,c,d,e,f,g,h, A,B,C,D,E,F,G)   (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)| ((A&1)<<8)|((B&1)<<9)|((C&1)<<10)|((D&1)<<11)|((E&1)<<12)|((F&1)<<13)|((G&1)<<14))
   #define packBTNR0_16(a,b,c,d,e,f,g,h, A,B,C,D,E,F,G,H) (((a&1)<<0)|((b&1)<<1)|((c&1)<<2)|((d&1)<<3)|((e&1)<<4)|((f&1)<<5)|((g&1)<<6)|((h&1)<<7)| ((A&1)<<8)|((B&1)<<9)|((C&1)<<10)|((D&1)<<11)|((E&1)<<12)|((F&1)<<13)|((G&1)<<14)|((H&1)<<15))
   #define packBTNR1(   a,b,c,d,e,f,g,h, A,B,C,D,E,F,G,H,...) (65536    * packBTNR0(__VA_ARGS__) + packBTNR0_16(a,b,c,d,e,f,g,h, A,B,C,D,E,F,G,H)) // uint32_t
   #define packBTNR2(   a,b,c,d,e,f,g,h, A,B,C,D,E,F,G,H,...) (65536ULL * packBTNR1(__VA_ARGS__) + packBTNR0_16(a,b,c,d,e,f,g,h, A,B,C,D,E,F,G,H)) // uint48_t non esiste diventa uint64_t
   #define packBTNR3(   a,b,c,d,e,f,g,h, A,B,C,D,E,F,G,H,...) (65536ULL * packBTNR2(__VA_ARGS__) + packBTNR0_16(a,b,c,d,e,f,g,h, A,B,C,D,E,F,G,H)) // uint64_t

// ----- BITS                      --
   template <typename T> T bitReverse(T x) {T r=0;uint8_t b=sizeof(T)*8-1; for_n_to(b){ if(x&(T(1)<<n)){ r|=(T(1)<<(b-n));}} return r;}
   template <typename T> T bitReverse(T x, uint8_t b){T r=0;               for_n_to(b){ if(x&(T(1)<<n)){ r|=(T(1)<<(b-n));}} return r;} //b numeroBits-1 : b=8→9 ,il bit 0 è il primo

   #undef  bitRead                                    // tolgo quelle predefinite che operano fino a 32 bit
   #undef  bitSet
   #undef  bitClear
   #undef  bitClear
   #undef  bitToggle                                  // e aggiungo queste che si adattano automaticamente alla 
   #undef  bitWrite                                   // dimensione della variabile rendendo l'esecuzione piu veloce
   #undef  bit
   
   template <typename T> inline T      bitmask(             uint8_t b)       { return T(1)<<b ;}                       // auto a=bit<16>(3) a sarà di 16 bit il 3° sarà 1
   //template <typename T> inline void   bitSet(         T& a,uint8_t b)       { a|= bitmask<T>(b); }
   //template <typename T> inline void   bitClear(       T& a,uint8_t b)       { a&=~bitmask<T>(b); }
   //template <typename T> inline void   bitWrite(       T& a,uint8_t b,bool v){ if(v) bitSet(a,b); else bitClear(a,b);}
   //template <typename T> inline void   bitToggle(      T& a,uint8_t b)       { a^= bitmask<T>(b); }
   template <typename T> inline void   bitSet(         T& a,uint8_t b)       { a|= T(1)<<b; }
   template <typename T> inline void   bitClear(       T& a,uint8_t b)       { a&=~(T(1)<<b); }
   template <typename T> inline void   bitWrite(       T& a,uint8_t b,bool v){ if(v) a|=T(1)<<b; else a&=~(T(1)<<b);}
   template <typename T> inline bool   bitRead(  const T& a,uint8_t b)       { return  (a>>b)&T(1); }
   template <>           inline bool   bitRead<uint8_t>(const uint8_t& a, uint8_t b){ return (a>>b)&1;}                  //specializzazione a 8 bit
   template <typename T> inline void   bitToggle(      T& a,uint8_t b)       { a^= T(1)<<b; }
   template <typename T> inline bool   bit(      const T& a,uint8_t b)       { return  (a>>b)&T(1); }                   // bool a=bit(var,3)    a=terzo bit di var
   template <typename T> inline void   bit(            T& a,uint8_t b,bool v){ if(v) a|=T(1)<<b; else a&=~(T(1)<<b);}   // uc var; bit(var,3,1) mette a 1 il terzo bit di var

   #define   b1(...)   macronumargs(b1,__VA_ARGS__)        // set boolean 1 nel bit n di a
   #define   b11(a)       bitSet(a,n);                         
   #define   b12(a,b)     bitSet(a,n);bitSet(b,n);             
   #define   b13(a,b,c)   bitSet(a,n);bitSet(b,n);bitSet(c,n); 
   #define   b14(a,b,c,d) bitSet(a,n);bitSet(b,n);bitSet(c,n);bitSet(d,n);  
   #define   b0(...)   macronumargs(b0,__VA_ARGS__)        // clear boolean 0 nel bit n di a
   #define   b01(a)       bitClear(a,n);                               
   #define   b02(a,b)     bitClear(a,n);bitClear(b,n);              
   #define   b03(a,b,c)   bitClear(a,n);bitClear(b,n);bitClear(c,n);
   #define   b04(a,b,c,d) bitClear(a,n);bitClear(b,n);bitClear(c,n);bitClear(d,n);
   #define   br(a)        bit(a,n)                            // boolean read nel bit n di  a
   #define   bw(a,v)      bit(a,n,v);                         // boolean write val nel bit n di a
   #define  ifb(a)     if(bit(a,n))                           // If boolean=1 nel bit n di a
   #define ifnb(a)    if(!bit(a,n))                           // if boolean=0 nel bit n di a



// ----- STRING                    --
   template<typename T> static inline void arrcpy(T* dst,const T src[],size_t len){ for(size_t i=0;i<len;i++) dst[i]=src[i];} // Copia array tipizzato da RAM a RAM (accesso diretto) migliore di memcpy , per esempio puo copiare strutture

   template <size_t N> inline void safe_strncpy(char (&dst)[N],const char* src)                                    { strncpy(dst,src,N-1);    dst[N-1]='\0'    ;}
   template <size_t N> inline void safe_strncpy(char (&dst)[N],const char* src,size_t num){size_t n=(num<N?num:N-1); strncpy(dst,src,n);dst[n]='\0';} //Copia al massimo num caratteri da src in dst, senza superare la capacità di dst, e garantendo il terminatore \0.
   template <size_t N> inline void safe_strncpy(char (&dst)[N],const char* src,size_t da,size_t a) { if(a<da)return; safe_strncpy(dst,src+da,a-da+1); }

   template <size_t N> inline bool safe_strncat(char (&dst)[N],const char* src,size_t num) {size_t dl=strlen(dst); if(dl>=N)  return false;      // buffer già pieno
                               size_t space=N-dl-1; size_t copyLen=(num<space)? num: space; safe_strncpy(dst+dl,src,copyLen); return (copyLen == num);}
   template <size_t N> inline bool safe_strncat(char (&dst)[N],const char* src,size_t da,size_t a){ if(a<da)return 0; safe_strncat(dst,src+da,a-da+1); return 1;}
 
   #define STRING_EQUALS(a, b)         (strcmp((a),(b))==0) 
   #define STRING_CLEAR(s)                s[0]='\0'
   #define STRING_IS_EMPTY(s)          ((s)[0]=='\0') 
   #define INIT_BUFFER(buf, val)       do{strncpy((buf),(val),sizeof(buf));(buf)[sizeof(buf)-1]='\0';}while(0)

// ----- LETTURA DA FLASH SU AVR ARDUINO UN MEGA ECC... --------------già compatibile con altre piattaforme----------------
  #ifdef __AVR__                             // Rilevamento piattaforma macro per lettura da flash su AVR
   #include <avr/pgmspace.h>
   #define f_const     const PROGMEM                      // memoria programma per variabili globali o statiche  (static const PROGMEM)
   #define flash(type,var) const type var PROGMEM         // memoria programma per variabili globali o statiche  (static const PROGMEM)
   static inline uc    f_get(const uc   * arr,size_t i){return pgm_read_byte(arr + i); }  // legge array in flash
   static inline ui    f_get(const ui   * arr,size_t i){return pgm_read_word(arr + i); }
   static inline ul    f_get(const ul   * arr,size_t i){return pgm_read_dword(arr + i);}
   static inline sc    f_get(const sc   * arr,size_t i){return static_cast<sc>pgm_read_byte(arr + i); }
   static inline si    f_get(const si   * arr,size_t i){return static_cast<si>pgm_read_word(arr + i); }
   static inline sl    f_get(const sl   * arr,size_t i){return static_cast<sl>pgm_read_dword(arr + i);}
   static inline char  f_get(const char * arr,size_t i){return static_cast<char>(pgm_read_byte(arr + i));}
   static inline float f_get(const float* arr,size_t i){return pgm_read_float(arr + i);}
   static inline uc    f_get(const uc   * p)           {return pgm_read_byte(p); }                     // legge variabile in flash
   static inline ui    f_get(const ui   * p)           {return pgm_read_word(p); }                     // utile solo se il puntatore è noto a compile-time e punta a flash
   static inline ul    f_get(const ul   * p)           {return pgm_read_dword(p);}
   static inline sc    f_get(const sc   * p)           {return static_cast<sc>(pgm_read_byte(p)); }    // ma non servono a molto : io puntatore è in ram e costa
   static inline si    f_get(const si   * p)           {return static_cast<si>pgm_read_word(p); }
   static inline sl    f_get(const sl   * p)           {return static_cast<sl>pgm_read_dword(p);}
   static inline float f_get(const float* p)           {return pgm_read_float(p);}
   static inline char  f_get(const char * p)           {return static_cast<char>(pgm_read_byte(p));}
   // --- stringhe in PROGMEM
   using F_String = const __FlashStringHelper*;
   static inline F_String f_getS(PGM_P p)              {return reinterpret_cast<const __FlashStringHelper*>(p);}   // ottiene direttamente la stringa 
   static inline size_t   f_strlen(PGM_P p)            {size_t len=0;while(pgm_read_byte(p+len))++len;return len;} 
   static inline void     f_strncpy(char* dst,const char* src,size_t len) {if(len==0)return; size_t i=0;                                        for(;i+1<len;++i)     {char c=pgm_read_byte(src+i); if(!c)break; dst[i]=c;} dst[i]='\0';}
   static inline void     f_memcpy( void* dst,const void* src,size_t len) {uc* d=static_cast<uc*>(dst); const uc* s=static_cast<const uc*>(src); for(size_t i=0;i<len;++i) d[i]=pgm_read_byte(s+i);} // Copia generica da flash a RAM (byte per byte)
   template<typename T,typename S>                                        
   static inline void     f_arrcpy(T* dst, const S* src, size_t len)      {for(size_t i=0;i<len;++i) dst[i]=f_get(src,i);} // Copia array tipizzato da flash a RAM (usa f_get)
  
  #else                                                                       // nel caso non si usi AVR per compatibilità queste funzioni
   #define f_const     const                                                  // memoria programma
   #define flash(type,var) const type var        // memoria programma per variabili globali o statiche  (static const PROGMEM)
   static inline uc    f_get(const uc    arr[], size_t i) {return arr[i];}
   static inline ui    f_get(const ui    arr[], size_t i) {return arr[i];}
   static inline ul    f_get(const ul    arr[], size_t i) {return arr[i];}
   static inline sc    f_get(const sc    arr[], size_t i) {return arr[i];}
   static inline si    f_get(const si    arr[], size_t i) {return arr[i];}
   static inline sl    f_get(const sl    arr[], size_t i) {return arr[i];}
   static inline char  f_get(const char  arr[], size_t i) {return arr[i];}
   static inline float f_get(const float arr[], size_t i) {return arr[i];}
   static inline uc    f_get(const uc   * p)              {return *p;}                     // legge variabile in flash
   static inline ui    f_get(const ui   * p)              {return *p;}                     // utile solo se il puntatore è noto a compile-time e punta a flash
   static inline ul    f_get(const ul   * p)              {return *p;}
   static inline sc    f_get(const sc   * p)              {return *p;}   // ma non servono a molto : io puntatore è in ram e costa
   static inline si    f_get(const si   * p)              {return *p;}
   static inline sl    f_get(const sl   * p)              {return *p;}
   static inline float f_get(const float* p)              {return *p;}
   static inline char  f_get(const char * p)              {return *p;}
   // --- stringhe in PROGMEM
   using F_String = const char*;
   static inline F_String f_getS(const char* p)           {return  p;}
   static inline size_t f_strlen(const char * p)          {return strlen(p);}
   static inline void   f_strncpy(char* dst, const char* src, size_t l){if(l==0)return; size_t n=(strlen(src)<(l-1))?strlen(src):(l-1); memcpy(dst,src,n); dst[n]='\0'; }
   static inline void   f_memcpy(void* dst, const void* src, size_t len) {memcpy(dst, src, len);} // Copia generica da RAM a RAM
   template<typename T,typename S> static inline void f_arrcpy(T* dst, const S* src, size_t len){for(size_t i = 0;i<len;++i)dst[i]=src[i];} // Copia array tipizzato da RAM a RAM (accesso diretto)
  #endif

// ----- SERIAL.PRINT              --funzioni Serial.print con piu elementi (non usare con parametri opzionali: Serial.print(78, BIN)→"1001110")
                                          inline void Sp()                                     { Serial.print(""); }
   template<typename T>                   inline void Sp(const T& value)                       { Serial.print(value); }
   template<typename T, typename... Args> inline void Sp(const T& first, const Args&... rest)  { Serial.print(first); Sp(rest...); }
                                          inline void Spt()                                    { Serial.print("\t"); }
   template<typename T>                   inline void Spt(const T& value)                      { Serial.print(value);Serial.print("\t"); }
   template<typename T, typename... Args> inline void Spt(const T& first, const Args&... rest) { Serial.print(first); Serial.print("\t"); Spt(rest...); }
                                          inline void Sptn()                                   { Serial.print("\n"); }
   template<typename T>                   inline void Sptn(const T& value)                     { Serial.print(value);Serial.print("\n"); }
   template<typename T, typename... Args> inline void Sptn(const T& first, const Args&... rest){ Serial.print(first); Serial.print("\t"); Spt(rest...); }
                                          inline void Spn()                                    { Serial.println(); }
   template<typename T>                   inline void Spn(const T& value)                      { Serial.println(value); }
   template<typename T, typename... Args> inline void Spn(const T& first, const Args&... rest) { Serial.println(first); Spn(rest...); }
   // separatore specificato   ""=nessun separatore   "\t"=Tabulazione   "\n"= new line
   template<typename T>                   inline void Sps(const T& first)                      { Sp(first);}
   template<typename T, typename... Args> inline void Sps(const char* s, const T& first, const Args&... args) { Sp(first); Sp(s); Sps(s, args...); }  // Sps(", ","LUCA","PIETRO","MATTEO","PAOLO") ⟶ LUCA, PIETRO, MATTEO, PAOLO
// ----- SERIAL.WRITE              --funzioni Serial.write per trasmettere intere variabili, array o liste
   template<typename T>           inline void Sw(const T& v)          {Serial.write(reinterpret_cast<const uint8_t*>(&v),   sizeof(T));}  //trasmette i byte di v  (&v Serial.Write vuole un indirizzo)    int b=10:                     Sw(b); Sw(20);   → 10 20   - In deduzione template, l’array non decade a puntatore:T = int[4].
   template<typename T>           inline void Sw(const T* v, size_t N){Serial.write(reinterpret_cast<const uint8_t*>(v) , N*sizeof(T));}  //trasmette n elementi partendo da un puntatore                  float b[3]={1.1,2.2,3.3,4.4}; Sw(b+1,2);       → 2.2 3.3 
   template<typename T, size_t N> inline void Sw(const T (&v)[N])     {Serial.write(reinterpret_cast<const uint8_t*>(v) , N*sizeof(T));}  //trasmette tutto un array di dimensione nota N                  int   b[] ={10,15,100};       SW(b);           → 10 15 100
   template<typename OutType, typename... Args> inline void Swn(Args... args){OutType a[]={static_cast<OutType>(args)... }; Sw(a);}       //invia con Serial.write la lista nel formato scelto:                                          Swn<uint_32>(10,12345645,1,b) → 10 12345645 1 123 
// ----- ESEMPI                    --
   void f_esempi(){
     Sp(       "anni",15,"altezza",151,"cm"); Spn();  // "anni15altezza151cm"              <cr>  
     Spt(      "anni",15,"altezza",151,"cm"); Spn();  // "anni 15  altezza 151 cm"         <cr>
     Sps(" | ","anni",15,"altezza",151,"cm"); Spn();  // "anni | 15 | altezza | 151 | cm"  <cr>
     Spn(      "anni",15,"altezza",151,"cm");         // "anni <cr> 15 <cr> altezza <cr> 151 <cr> cm <cr> "
     Spn(F("ciao da flash"));                         // "ciao da flash" <cr>             non utilizza RAM

     //const char str1[] PROGMEM = "ciao da flash";   // non è compatibile con board non avr
      flash(char, str1[])= "ciao da flash";          // comapatibile con tutte
     Sp(F("str1   : "), f_getS(str1)  , "\r\n",       // "str1   : ciao da flash" <cr>
        F("str1[1]: "), f_get(str1,1) , "\r\n",       // "str1[1]: i" <cr>                  Spn(str1[1]); errato perchè accede alla Ram
        F("lungh  : "), f_strlen(str1), "\r\n");      // "lungh  : 13" <cr>
                                                      //
     char str2[10]={};                                // riserva 10 bytes in Ram( 9 caratteri + \0)
     f_strncpy(str2,str1,6);                          // copia da flash in Ram 6 bytes
     Sp(F("str2   : "), str2 );     Spn();            // "str2   : ciao d"  <cr> 
     Sp(f_getS(str1), ", ", str2);  Spn();            // "ciao da flash, ciao d"  <cr>
     
     flash(ui, tabella[]) = {100, 200, 300};          // l'array di tipo F non copiato in Ram
     ui x=f_get(tabella,2);                           // estrae l'elemento dall'array in flash
     Spt(f_get(tabella,1)+1, x+1);                    // "201 301"
     Spt(f_get(tabella+1)+1, x+1);                    // "201 301"

     ui tabellaRam[4]={};
     f_arrcpy(tabellaRam,tabella,3);                  // copia in Ram 3 elementi Flash
     // Sw(tabella,3);                                // Serial.write non accetta puntatori a flash
     Sw(f_get(str1,0));                               // "c"
     Sw(x);                                           // 1 64   Ordine little-endian: byte meno significativo prima
     Sw(tabellaRam+1,2);                              // 0 200 1 64
     Sw(tabellaRam);                                  // 0 100 0 200 1 64 00 00

     #define marr1(x) ARRAY(x, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64)
     #define marr2(x) ARRAY(x, 5,10,30,50,80)
     #define marr3(x) ARRAY(x, "sono","sempre","io")
     #define marr4(x) ARRAY(x, a,20,"anni")
     Sptn(marr1(2), marr2(2), marr3(1));              // 3   30  "sempre" 
     int a;
     a=10; Sptn(marr4(0), marr4(2) );                 // 10  anni
     a= 5; Sptn(marr4(0), marr4(2) );                 // 5   anni
     a=40; Sptn(marr4(1), marr4(2) );                 // 20  anni

   
   
   }

