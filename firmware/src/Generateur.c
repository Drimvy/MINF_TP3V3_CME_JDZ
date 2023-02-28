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
#include <stdint.h>
#include <math.h>

// T.P. 2016 100 echantillons
#define MAX_ECH 100
#define VAL_TIC_MAX 32768

int tb_Amplitude[MAX_ECH];

// Initialisation du  générateur
void  GENSIG_Initialize(S_ParamGen *pParam)
{ 
    pParam->Amplitude = 10000;
    S_Amplitude Ampli;
    uint16_t static Offset = 0;
    int i;

    
    //gestion de l'amplitude 
    Ampli.Nb_Tic = (pParam->Amplitude * VAL_TIC_MAX /10000);
    Ampli.Min = (VAL_TIC_MAX)-(Ampli.Nb_Tic);
    Ampli.Max =(VAL_TIC_MAX-1)+(Ampli.Nb_Tic);
    
     //gestion de l'offest
    Offset = (pParam->Offset*(VAL_TIC_MAX/10000));

 //test
    
            
      for(i = 0; i < 100; i++)
            {
          
                uint8_t a = 0;
                if(i < 25 )
                {
                    a = (Ampli.Nb_Tic/10000)/24;       
                    tb_Amplitude[i] =  pParam->Amplitude *(a*i)+ VAL_TIC_MAX + Offset ;      
                }
                else if((i >= 25) && (i < 75))
                {
                    tb_Amplitude[i] = pParam->Amplitude *(a*i)+ VAL_TIC_MAX + VAL_TIC_MAX*2 + Offset ;
                }
                else if( i >= 75)
                {
                    tb_Amplitude[i] = pParam->Amplitude *(a*(i-75))+ Offset ;
                }
            }
            
    
}          
            
            
            
            
   /*         pParam->Amplitude = 10000;
    pParam->Forme = "SignalDentDeScie";
    pParam->Frequence = 100;
    pParam->Offset = 0;
    
}
  

// Mise à jour de la periode d'échantillonage
void  GENSIG_UpdatePeriode(S_ParamGen *pParam)
{
    //initaliser la variable
    uint16_t static Periode = 0;
    
    //---Calculer la période en fonction de la fréquence entrée comme paramètre----/   
    //diviser par le nombre d'echantillon afin 
    //d'obtenir la bonne fréquence pour la génération dusignal
    Periode = (1/(pParam->Frequence));
    // diviser la péride par MAX_ECH pour obtenir la période déchantillonnage
    Periode = Periode/MAX_ECH;
    //Convertir la periode en "timer compteur" pour le timer 3
    Periode = (Periode * 8000 / 0.0001) - 1;
    
    //modifier la periode du timer 3
    PLIB_TMR_Period16BitSet(TMR_ID_3, Periode);
}

// Mise à jour du signal (forme, amplitude, offset)
void  GENSIG_UpdateSignal(S_ParamGen *pParam)
{
    S_Amplitude Ampli;
    uint16_t static Offset = 0;
    int i;
    
    //gestion de l'amplitude 
    Ampli.Nb_Tic = (pParam->Amplitude * VAL_TIC_MAX /10000);
    Ampli.Min = (VAL_TIC_MAX/2)-(Ampli.Nb_Tic/2);
    Ampli.Max =(VAL_TIC_MAX/2)+(Ampli.Nb_Tic/2);
    
    //gestion de l'offest
    Offset = (pParam->Offset*(VAL_TIC_MAX)/5000);
            
    
    //---Gestion de la seclection des formes des signaux---/ 
    //Sélection forme
    switch (pParam->Forme)
    {
    //---Entrer l'amplitude dans le tableau pour obtenir un sinus---/
    
   //pas encore parfait pas à améliorer   
        case "SignalSinus":
        {
            for( i = 0; i < 100; i++)
            {
                tb_Amplitude[i] = (Ampli.Nb_Tic/1.28)*(4/M_PI * sin( M_PI *(3.6*i)/180))+VAL_TIC_MAX+ Offset;
            }
        
         break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un triangle---/ 
        
        //pas encore parfait pas à 0 exactement
        case "SignalTriangle":
        {
            
            for(i = 0; i < 100; i++)
            {
                if(i < 50 )
                {
                    tb_Amplitude[i] = (Ampli.Nb_Tic/(MAX_ECH/2)*i)+Ampli.Min+Offset ;
                }
                else
                {
                    tb_Amplitude[i] = ((Ampli.Nb_Tic/50)*(49-(i-50)))+Ampli.Min+ Offset ;
                }
                
            }
            
        break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un dent de scie---/     
        case "SignalDentDeScie":
        {
            uint16_t static Step;
            Step = ((Ampli.Nb_Tic*2) / MAX_ECH);
            
            for( i = 0; i < 100; i++)
            {
                tb_Amplitude[i] = (Step * i)+ Ampli.Min + Offset;
            }

        break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un carrée---/
        
        //ne fonctionne pas du tout
        case "SignalCarre":
        {
            for( i = 0; i < 100; i++)
            {
                if(i < 50 )
                {
                    tb_Amplitude[i] = Ampli.Max +Offset ;
                }
                else
                {
                    tb_Amplitude[i] = Ampli.Min +Offset;
                }                   

            } 
        
        break;
        }
    }
        
   
}*/


// Execution du générateur
// Fonction appelée dans Int timer3 (cycle variable variable)

// Version provisoire pour test du DAC à modifier
void  GENSIG_Execute(void)
{
    //Initaliser EchNb à 0 en static
   static uint16_t EchNb = 0;
   //initialiser les steps
   if(tb_Amplitude[EchNb] > (VAL_TIC_MAX*2)-1)
   {
       tb_Amplitude[EchNb] = (VAL_TIC_MAX*2)-1;
   }
   SPI_WriteToDac(0, tb_Amplitude[EchNb]);
   EchNb++;
   
   
   //-----ancien code----
   //const uint16_t Step = (65536 / MAX_ECH);
   
   //pourquoi il est à 0?
   //SPI_WriteToDac(0, Step * EchNb );      // sur canal 0
   //EchNb++;
   //si EchNB est supperieur à 100 
   /*if(EchNb > MAX_ECH)
   {
       //remettre à 0
       EchNb = 0;
   }*/
   EchNb = EchNb % MAX_ECH;
}
