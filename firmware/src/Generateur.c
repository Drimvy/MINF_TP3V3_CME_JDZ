// Canevas manipulation GenSig avec menu
// C. HUBER  09/02/2015
// Fichier Generateur.C
// Gestion  du gÃ©nÃ©rateur

// PrÃ©vu pour signal de 40 echantillons

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

// Initialisation du  gÃ©nÃ©rateur
void  GENSIG_Initialize(S_ParamGen *pParam)
{           
    pParam->Amplitude = 10000;

    pParam->Forme = SignalDentDeScie;

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
            
                if else (i < 25 )
                {
                    //calcul pour la pente montante du triangle (du centre Ã  la val max)
                    tb_Amplitude[i] = pParam->Amplitude * a * i + VAL_TIC_MAX + Offset;
                }
                
                if else ((i < 75) && (i >= 25))
                {
                    //calcul pour la pente descendante du triangle (de la val max- la val min)
                    tb_Amplitude[i] = pParam->Amplitude * (-a) * i + VAL_TIC_MAX + Ampli.Nb_Tic + Offset;
                }
                
                if else (i >= 75 )
                {
                    //calcul pour la pente montante du triangle (de la val min au centre)
                    tb_Amplitude[i] = pParam->Amplitude * a * (i - 100)+VAL_TIC_MAX + Offset ;
                }
            }
            
    
}          
            
            
            
            
   /*         pParam->Amplitude = 10000;
    pParam->Forme = SignalDentDeScie;
    pParam->Frequence = 100;
    pParam->Offset = 0;   
}
  

// Mise Ã  jour de la periode d'Ã©chantillonage
void  GENSIG_UpdatePeriode(S_ParamGen *pParam)
{

    
=======
    //intitialiser la constatante de la pente
    uint8_t const a = VAL_TIC_MAX/25;
>>>>>>> 300fa792971a28a2326f394be92566d66254b983
    //initaliser la variable
    uint16_t static Periode = 0;
    
    //---Calculer la pÃ©riode en fonction de la frÃ©quence entrÃ©e comme paramÃ¨tre----/   
    //diviser par le nombre d'echantillon afin 
    //d'obtenir la bonne frÃ©quence pour la gÃ©nÃ©ration dusignal
    Periode = (1/(pParam->Frequence));
    // diviser la pÃ©ride par MAX_ECH pour obtenir la pÃ©riode dÃ©chantillonnage
    Periode = Periode/MAX_ECH;
    //Convertir la periode en "timer compteur" pour le timer 3
    Periode = (Periode * 8000 / 0.0001) - 1;
    
    //modifier la periode du timer 3
    PLIB_TMR_Period16BitSet(TMR_ID_3, Periode);
}

// Mise Ã  jour du signal (forme, amplitude, offset)
void  GENSIG_UpdateSignal(S_ParamGen *pParam)
{
<<<<<<< HEAD
    //déclaration de....
    S_Amplitude Ampli;
    //intialisation de la variable statique offset
    uint16_t Offset;
    
    //initialisation de l'incrément
=======
    //dÃ©claration de....
    S_Amplitude Ampli;
    //intialisation de la variable statique offset
    uint16_t static Offset = 0;
    //initialisation de l'incrÃ©ment
>>>>>>> 300fa792971a28a2326f394be92566d66254b983
    int i;
    
    //gestion de l'amplitude 
    Ampli.Nb_Tic = (pParam->Amplitude * VAL_TIC_MAX /10000);
    Ampli.Min = (VAL_TIC_MAX/2)-(Ampli.Nb_Tic/2);
    Ampli.Max =(VAL_TIC_MAX/2)+(Ampli.Nb_Tic/2);
    
    //gestion de l'offest
    Offset = (pParam->Offset*(VAL_TIC_MAX)/5000);
            
    
    //---Gestion de la seclection des formes des signaux---/ 
    //SÃ©lection forme
    switch (pParam->Forme)
    {
    //---Entrer l'amplitude dans le tableau pour obtenir un sinus---/  
<<<<<<< HEAD
        case SignalSinus:
=======
        case "SignalSinus":
>>>>>>> 300fa792971a28a2326f394be92566d66254b983
        {
        //boucle for pour remplire le tableau 
            for( i = 0; i < 100; i++)
            {
            //calcul pour obtenir un sinus
                tb_Amplitude[i] = (Ampli.Nb_Tic/1.28)*(4/M_PI * sin( M_PI *(3.6*i)/180))+VAL_TIC_MAX+ Offset;
            }
        
         break;
        }
<<<<<<< HEAD
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
                    //calcul pour la pente montante du triangle (du centre à la val max)
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
=======
    //---Entrer l'amplitude dans le tableau pour obtenir un triangle---/
        case "SignalTriangle":
        {
            //boucle for pour remplire le tableau 
            for(i = 0; i < 100; i++)
            {
            
                if else (i < 25 )
                {
                    //calcul pour la pente montante du triangle (du centre Ã  la val max)
                    tb_Amplitude[i] = pParam->Amplitude * a * i + VAL_TIC_MAX + Offset;
                }
                
                if else ((i < 75) && (i >= 25))
                {
                    //calcul pour la pente descendante du triangle (de la val max- la val min)
                    tb_Amplitude[i] = pParam->Amplitude * (-a) * i + VAL_TIC_MAX + Ampli.Nb_Tic + Offset;
                }
                
                if else (i >= 75 )
                {
                    //calcul pour la pente montante du triangle (de la val min au centre)
                    tb_Amplitude[i] = pParam->Amplitude * a * (i - 100)+VAL_TIC_MAX + Offset ;
>>>>>>> 300fa792971a28a2326f394be92566d66254b983
                }
            }
            
        break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un dent de scie---/     
        case SignalDentDeScie:
        {
            //initialiser la variable Sted
            uint16_t static Step;
            
<<<<<<< HEAD
            //déterminer la valeur de step 
=======
            //dÃ©terminer la valeur de step 
>>>>>>> 300fa792971a28a2326f394be92566d66254b983
            Step = ((Ampli.Nb_Tic*2) / MAX_ECH);
            
            //boucle for pour remplire le tableau 
            for( i = 0; i < 100; i++)
            {
<<<<<<< HEAD
                //calcul pour rénérer un dent de cie
=======
                //calcul pour rÃ©nÃ©rer un dent de cie
>>>>>>> 300fa792971a28a2326f394be92566d66254b983
                tb_Amplitude[i] = (Step * i)+ Ampli.Min + Offset;
            }

        break;
        }
    //---Entrer l'amplitude dans le tableau pour obtenir un carrÃ©e---/
        
        //ne fonctionne pas du tout
        case SignalCarre:
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
        
   
}


// Execution du gÃ©nÃ©rateur
// Fonction appelÃ©e dans Int timer3 (cycle variable variable)

// Version provisoire pour test du DAC Ã  modifier
void  GENSIG_Execute(void)
{
    //Initaliser EchNb Ã  0 en static
   static uint16_t EchNb = 0;
<<<<<<< HEAD
   //Si la valeur max est dépasser; saturation
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
   //incrémenter EchNb 
   EchNb++;
   //si EchNB est supperieur à 100  
   EchNb = EchNb % MAX_ECH;
  
   
=======
   //Si la valeur max est dÃ©passer; saturation
   if(tb_Amplitude[EchNb] > (VAL_TIC_MAX*2)-1)
   {
       //obtien la valeur max (65536) dans son tableau
       tb_Amplitude[EchNb] = (VAL_TIC_MAX*2)-1;
   }
   //incrire la valeur de notre tableau dans le DAC sur le channel 0
   SPI_WriteToDac(0, tb_Amplitude[EchNb]);
   //incrÃ©menter EchNb 
   EchNb++;
   //si EchNB est supperieur Ã  100  
   EchNb = EchNb % MAX_ECH;
    
   //-----ancien code----
   //const uint16_t Step = (65536 / MAX_ECH);
   
   //pourquoi il est Ã  0?
   //SPI_WriteToDac(0, Step * EchNb );      // sur canal 0
   //EchNb++;
   
  
   
   
>>>>>>> 300fa792971a28a2326f394be92566d66254b983
}
