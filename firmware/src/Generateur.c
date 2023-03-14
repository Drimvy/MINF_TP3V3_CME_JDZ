
// Canevas manipulation GenSig avec menu
// C. HUBER  09/02/2015
// Fichier Generateur.C
// Gestion  du g�n�rateur

// Pr�vu pour signal de 40 echantillons

// Migration sur PIC32 30.04.2014 C. Huber

//version final le 07.03.2023 - CME 

#include "Generateur.h"
#include "DefMenuGen.h"
#include "Mc32gestSpiDac.h"
#include "driver/tmr/drv_tmr_static.h"
#include <stdint.h>
#include <math.h>

// T.P. 2016 100 echantillons
#define MAX_ECH 100
#define VAL_TIC_MAX 32768
//d�claration de....
S_Amplitude Ampli;
int tb_Amplitude[MAX_ECH];

// Initialisation du  g�n�rateur
void  GENSIG_Initialize(S_ParamGen *pParam)
{           
    pParam->Amplitude = 10000;
    pParam->Forme = 2;
    pParam->Frequence = 100;
    pParam->Offset = 0;   
}
  

// Mise � jour de la periode d'�chantillonage
void  GENSIG_UpdatePeriode(S_ParamGen *pParam)
{
    
    //initaliser la variable
    uint16_t Periode;
    
//    //---Calculer la p�riode en fonction de la fr�quence entr�e comme param�tre----/   
//    //diviser par le nombre d'echantillon afin 
//    //d'obtenir la bonne fr�quence pour la g�n�ration dusignal
//    Periode = (1/(pParam->Frequence));
//    // diviser la p�ride par MAX_ECH pour obtenir la p�riode d�chantillonnage
//    Periode = Periode/MAX_ECH;
//    //Convertir la periode en "timer compteur" pour le timer 3
//    Periode = ((Periode * 8000) / 0.0001) - 1;
    
    Periode =  (SYS_CLK_FREQ / ( (uint32_t)MAX_ECH * pParam->Frequence)) - 1;
            
            
    //modifier la periode du timer 3
    PLIB_TMR_Period16BitSet(TMR_ID_3, Periode);
}

// Mise � jour du signal (forme, amplitude, offset)
void  GENSIG_UpdateSignal(S_ParamGen *pParam)
{ 
    //intialisation de la variable statique offset
    uint16_t Offset;
    
    //initialisation de l'incr�ment
    int i;
    
    //gestion de l'amplitude 
    Ampli.Nb_Tic = (pParam->Amplitude * VAL_TIC_MAX /10000);
    Ampli.Min = (VAL_TIC_MAX)-(Ampli.Nb_Tic);
    Ampli.Max =((VAL_TIC_MAX)+(Ampli.Nb_Tic)-1);
    
    //gestion de l'offest
    Offset = (pParam->Offset*(VAL_TIC_MAX/2)/5000);
            
    
    //---Gestion de la seclection des formes des signaux---/ 
    //S�lection forme
    switch (pParam->Forme)
    {
    //---Entrer l'amplitude dans le tableau pour obtenir un sinus---/  
        case SignalSinus:
        {
        //boucle for pour remplire le tableau 
            for( i = 0; i < 100; i++)
            {
            //calcul pour obtenir un sinus
                tb_Amplitude[i] = (Ampli.Nb_Tic/1.28)*(4/M_PI * sin( M_PI *(3.6*i)/180))+VAL_TIC_MAX+ Offset;
            }
        
         break;
        }
         //---Entrer l'amplitude dans le tableau pour obtenir un triangle---/
        case SignalTriangle:
        {
            //intitialiser la constatante de la pente
            float const a = ((float)VAL_TIC_MAX/(float)10000)/(float)25;
            float const b = pParam->Amplitude * 65536/10000 + VAL_TIC_MAX;

            for(i = 0; i < 100; i++)
            {

                if (i < 25 )
                {
                    //calcul pour la pente montante du triangle (du centre � la val max)
                    tb_Amplitude[i] = (pParam->Amplitude * (a * i)) + VAL_TIC_MAX + Offset;
                }

                else if ((i < 75) && (i >= 25))
                {
                    //calcul pour la pente descendante du triangle (de la val max- la val min)
                    tb_Amplitude[i] = (pParam->Amplitude *( (-a) * i) )+ b + Offset;
                }

                else if (i >= 75 )
                {
                    //calcul pour la pente montante du triangle (de la val min au centre)
                    tb_Amplitude[i] = (pParam->Amplitude *( a * (i - 100)))+VAL_TIC_MAX + Offset ;
                }
            }
            
        break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un dent de scie---/     
        case SignalDentDeScie:
        {
            //initialiser la variable Sted
            uint16_t static Step;
            
            //d�terminer la valeur de step 
            Step = ((Ampli.Nb_Tic*2) / MAX_ECH);
            
            //boucle for pour remplire le tableau 
            for( i = 0; i < 100; i++)
            {
                //calcul pour r�n�rer un dent de cie
                tb_Amplitude[i] = (Step * i)+ Ampli.Min + Offset;
            }

        break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un carr�e---/
        
        //ne fonctionne pas du tout
        case SignalCarre:
        {
            for( i = 0; i < 100; i++)
            {
                if(i < 50 )
                {
                    tb_Amplitude[i] = Ampli.Max  +Offset ;
                }
                else
                {
                    tb_Amplitude[i] = Ampli.Min +Offset;
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
   //Si la valeur max est d�passer; saturation
   if(tb_Amplitude[EchNb] > (VAL_TIC_MAX*2)-1)
   {
       //obtien la valeur max (65535) dans son tableau
       tb_Amplitude[EchNb] = (VAL_TIC_MAX*2)-1;
   }
   
   else if (tb_Amplitude[EchNb] < 0)
   {
       //obtien la valeur max (65535) dans son tableau
       tb_Amplitude[EchNb] = 0;
   }
   //incrire la valeur de notre tableau dans le DAC sur le channel 0
   SPI_WriteToDac(0, tb_Amplitude[EchNb]);
   //incr�menter EchNb 
   EchNb++;
   //si EchNB est supperieur � 100  
   EchNb = EchNb % MAX_ECH;
  
   
}



