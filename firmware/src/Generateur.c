// Canevas manipulation GenSig avec menu
// C. HUBER  09/02/2015
// Fichier Generateur.C
// Gestion  du g�n�rateur

// Pr�vu pour signal de 40 echantillons

// Migration sur PIC32 30.04.2014 C. Huber


#include "Generateur.h"
#include "DefMenuGen.h"
#include "Mc32gestSpiDac.h"
#include "driver/tmr/drv_tmr_static.h"

// T.P. 2016 100 echantillons
#define MAX_ECH 100

int tb_Amplitude[MAX_ECH];

// Initialisation du  g�n�rateur
void  GENSIG_Initialize(S_ParamGen *pParam)
{
    
    
}
  

// Mise � jour de la periode d'�chantillonage
void  GENSIG_UpdatePeriode(S_ParamGen *pParam)
{
    int periode;
    periode = 1/(*pParam->Frequence);
    PLIB_TMR_Period16BitSet(TMR_ID_3, periode);
}

// Mise � jour du signal (forme, amplitude, offset)
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


// Execution du g�n�rateur
// Fonction appel�e dans Int timer3 (cycle variable variable)

// Version provisoire pour test du DAC � modifier
void  GENSIG_Execute(void)
{
    //Initaliser EchNb � 0 en static
   static uint16_t EchNb = 0;
   //initialiser les steps
   const uint16_t Step = 65535 / MAX_ECH;

   SPI_WriteToDac(0, Step * EchNb );      // sur canal 0
   EchNb++;
   //si EchNB est supperieur � 100 
   if(EchNb > MAX_ECH)
   {
       //remettre � 0
       EchNb = 0;
   }
   //EchNb = EchNb % MAX_ECH;
}
