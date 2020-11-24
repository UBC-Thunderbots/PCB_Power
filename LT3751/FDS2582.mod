.SUBCKT FDS2582 2 1 3      
*Spice model for FDS2582
*Nom Temp=25 deg C        
*July 2002   

Ca 12 8 4.5e-10
Cb 15 14 5.0e-10
Cin 6 8 1.25e-9

Dbody 7 5 DbodyMOD
Dbreak 5 11 DbreakMOD
Dplcap 10 5 DplcapMOD

Ebreak 11 7 17 18 155.5
Eds 14 8 5 8 1
Egs 13 8 6 8 1
Esg 6 10 6 8 1
Evthres 6 21 19 8 1
Evtemp 20 6 18 22 1

It 8 17 1

Lgate 1 9 5.61e-9
Ldrain 2 5 1e-9
Lsource 3 7 1.98e-9

RLgate 1 9 56.1
RLdrain 2 5 10
RLsource 3 7 19.8

Mmed 16 6 8 8 MmedMOD
Mstro 16 6 8 8 MstroMOD 
Mweak 16 21 8 8 MweakMOD    

Rbreak 17 18 RbreakMOD 1
Rdrain 50 16 RdrainMOD 30.0e-3
Rgate 9 20 1.5
RSLC1 5 51 RSLCMOD 1e-6
RSLC2 5 50 1e3
Rsource 8 7 RsourceMOD 20.0e-3
Rvthres 22 8 Rvthresmod 1
Rvtemp 18 19 RvtempMOD 1
S1a 6 12 13 8 S1AMOD
S1b 13 12 13 8 S1BMOD
S2a 6 15 14 13 S2AMOD
S2b 13 15 14 13 S2BMOD

Vbat 22 19 DC 1

ESLC 51 50  VALUE={(V(5,51)/ABS(V(5,51)))*(PWR(V(5,51)/(1e-6*60),2.5))}

.MODEL DbodyMOD D (IS=2.4E-12 N=1.0 RS=10.0e-3 TRS1=2.1e-3 TRS2=4.7e-7
+ CJO=9.0e-10 M=0.64 TT=3.9e-8 XTI=4.6)
.MODEL DbreakMOD D (RS=1.0 TRS1=1.4e-3 TRS2=-5e-5)
.MODEL DplcapMOD D (CJO=2.8e-10 IS=1e-30 N=10 M=0.64)

.MODEL MmedMOD NMOS (VTO=3.5 KP=4.0 IS=1e-30 N=10 TOX=1 L=1u W=1u RG=1.5)
.MODEL MstroMOD NMOS (VTO=4.2 KP=50 IS=1e-30 N=10 TOX=1 L=1u W=1u)
.MODEL MweakMOD NMOS (VTO=2.92 KP=0.04 IS=1e-30 N=10 TOX=1 L=1u W=1u RG=15 RS=0.1) 

.MODEL RbreakMOD RES (TC1=1.1e-3 TC2=-1.0e-8)
.MODEL RdrainMOD RES (TC1=1.15e-2 TC2=3.0e-5)
.MODEL RSLCMOD RES (TC1=4.4e-3 TC2=2.9e-6)
.MODEL RsourceMOD RES (TC1=1e-3 TC2=1e-6)
.MODEL RvthresMOD RES (TC1=-3.9e-3 TC2=-1.6e-5)
.MODEL RvtempMOD RES (TC1=-3.5e-3 TC2=1.5e-6)

.MODEL S1AMOD VSWITCH (RON=1e-5 ROFF=0.1 VON=-3.0 VOFF=-2.0)
.MODEL S1BMOD VSWITCH (RON=1e-5 ROFF=0.1 VON=-2.0 VOFF=-3.0)
.MODEL S2AMOD VSWITCH (RON=1e-5 ROFF=0.1 VON=-1.5 VOFF=1.0)
.MODEL S2BMOD VSWITCH (RON=1e-5 ROFF=0.1 VON=1.0 VOFF=-1.5)
.ENDS

.SUBCKT FDS2582_THERMAL TH TL
*Thermal Model Subcircuit  July02
CTHERM1 TH 8 4.0e-4
CTHERM2 8 7 5.0e-3
CTHERM3 7 6 6.0e-2
CTHERM4 6 5 9.0e-2
CTHERM5 5 4 3.0e-1
CTHERM6 4 3 4.0e-1
CTHERM7 3 2 9.0e-1
CTHERM8 2 TL 2.0e0

RTHERM1 TH 8 5.0e-1
RTHERM2 8 7 6.0e-1
RTHERM3 7 6 4.0e0
RTHERM4 6 5 5.0e0
RTHERM5 5 4 8.0e0
RTHERM6 4 3 9.0e0
RTHERM7 3 2 15.0e0
RTHERM8 2 TL 23.0e0
.ends
