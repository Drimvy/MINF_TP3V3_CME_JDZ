// Canevas manipulation GenSig avec menu
// C. HUBER  09/02/2015
// Fichier Generateur.C
// Gestion  du générateur

// Prévu pour signal de 40 echantillons

// Migration sur PIC32 30.04.2014 C. Huber


#include "Generateur.h"
#include "DefMenuGen.h"
#include "Mc32gestSpiDac.h"
#include "driver/tmr/drv_tmr_static.h"

// T.P. 2016 100 echantillons
#define MAX_ECH 100

int tb_Amplitude[MAX_ECH];

// Initialisation du  générateur
void  GENSIG_Initialize(S_ParamGen *pParam)
{
    
    
}
  

// Mise à jour de la periode d'échantillonage
void  GENSIG_UpdatePeriode(S_ParamGen *pParam)
{
    int periode;
    periode = 1/(*pParam->Frequence);
    PLIB_TMR_Period16BitSet(TMR_ID_3, periode);
}

// Mise à jour du signal (forme, amplitude, offset)
void  GENSIG_UpdateSignal(S_ParamGen *pParam)
{
    
            
    switch (pParam.Forme)
    {
            
        case SignalSinus:
        {
          
        
         break;
        }
        case SignalTriangle:
        {
            
        break;
        }
        case SignalDentDeScie:
        {
        
        break;
        }
        case SignalCarre:
        {
        
        break;
        }
    }
        
   
}


// Execution du générateur
// Fonction appelée dans Int timer3 (cycle variable variable)

// Version provisoire pour test du DAC à modifier
void  GENSIG_Execute(void)
{
    //Initaliser EchNb à 0 en static
   static uint16_t EchNb = 0;
   //initialiser les steps
   const uint16_t Step = 65535 / MAX_ECH;

   SPI_WriteToDac(0, Step * EchNb );      // sur canal 0
   EchNb++;
   //si EchNB est supperieur à 100 
   if(EchNb > MAX_ECH)
   {
       //remettre à 0
       EchNb = 0;
   }
   //EchNb = EchNb % MAX_ECH;
}
