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
#include <stdint.h>
#include <math.h>

// T.P. 2016 100 echantillons
#define MAX_ECH 100

int tb_Amplitude[MAX_ECH];

// Initialisation du  g�n�rateur
void  GENSIG_Initialize(S_ParamGen *pParam)
{ 
      
    pParam->Amplitude = 10000;
    pParam->Forme = "SignalDentDeScie";
    pParam->Frequence = 100;
    pParam->Offset = 0;
    
}
  

// Mise � jour de la periode d'�chantillonage
void  GENSIG_UpdatePeriode(S_ParamGen *pParam)
{
    //initaliser la variable
    uint16_t static Periode = 0;
    
    //---Calculer la p�riode en fonction de la fr�quence entr�e comme param�tre----/   
    //diviser par le nombre d'echantillon afin 
    //d'obtenir la bonne fr�quence pour la g�n�ration dusignal
    Periode = (1/(pParam->Frequence));
    // diviser la p�ride par MAX_ECH pour obtenir la p�riode d�chantillonnage
    Periode = Periode/MAX_ECH;
    //Convertir la periode en "timer compteur" pour le timer 3
    Periode = (Periode * 8000 / 0.0001) - 1;
    
    //modifier la periode du timer 3
    PLIB_TMR_Period16BitSet(TMR_ID_3, Periode);
}

// Mise � jour du signal (forme, amplitude, offset)
void  GENSIG_UpdateSignal(S_ParamGen *pParam)
{
    uint16_t static Ampli = 0;
    uint16_t static Offset = 0;
    int i;
    
    //---Gestion de la seclection des formes des signaux---/ 
    //S�lection forme
    switch (pParam->Forme)
    {
    //---Entrer l'amplitude dans le tableau pour obtenir un sinus---/
    
   //pas encore parfait pas � am�liorer   
        case "SignalSinus":
        {
            for( i = 0; i < 100; i++)
            {
                tb_Amplitude[i] = ((4/M_PI * sin( M_PI *(3.6*i)/180))*(65536/1.28))+ Offset;
            }
        
         break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un triangle---/ 
        
        //pas encore parfait pas � 0 exactement
        case "SignalTriangle":
        {
            
            for(i = 0; i < 100; i++)
            {
                if(i < 50 )
                {
                    tb_Amplitude[i] = (Ampli/(MAX_ECH/2)*i)+Offset ;
                }
                else
                {
                    tb_Amplitude[i] = ((Ampli/50)*(49-(i-50)))+ Offset ;
                }
                
            }
            
        break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un dent de scie---/     
        case "SignalDentDeScie":
        {
            uint16_t static Step;
            Step = (Ampli / MAX_ECH) ;
            
            for( i = 0; i < 100; i++)
            {
                tb_Amplitude[i] = (Step * i) + Offset;
            }

        break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un carr�e---/
        
        //ne fonctionne pas du tout
        case "SignalCarre":
        {
            for( i = 0; i < 100; i++)
            {
                if(i < 50 )
                {
                    tb_Amplitude[i] = (Ampli/2)+Offset ;
                }
                else
                {
                    tb_Amplitude[i] = ~((Ampli/2)+Offset) ;
                }
                
            }
        
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
   SPI_WriteToDac(0, tb_Amplitude[EchNb]);
   EchNb++;
   
   
   //-----ancien code----
   //const uint16_t Step = (65536 / MAX_ECH);
   
   //pourquoi il est � 0?
   //SPI_WriteToDac(0, Step * EchNb );      // sur canal 0
   //EchNb++;
   //si EchNB est supperieur � 100 
   /*if(EchNb > MAX_ECH)
   {
       //remettre � 0
       EchNb = 0;
   }*/
   EchNb = EchNb % MAX_ECH;
}
