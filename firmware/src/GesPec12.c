// GesPec12.c  Canevas pour rÃ©alisation  
// C. HUBER    09/02/2015

// Fonctions pour la gestion du Pec12
//
//
// Principe : Il est nÃ©cessaire d'appeler cycliquement la fonction ScanPec12
//            avec un cycle de 1 ms
//
//  Pour la gestion du Pec12, il y a 9 fonctions Ã  disposition :
//       Pec12IsPlus       true indique un nouveau incrÃ©ment
//       Pec12IsMinus      true indique un nouveau dÃ©crÃ©ment
//       Pec12IsOK         true indique action OK
//       Pec12IsESC        true indique action ESC
//       Pec12NoActivity   true indique abscence d'activitÃ© sur PEC12
//  Fonctions pour quittance des indications
//       Pec12ClearPlus    annule indication d'incrÃ©ment
//       Pec12ClearMinus   annule indication de dÃ©crÃ©ment
//       Pec12ClearOK      annule indication action OK
//       Pec12ClearESC     annule indication action ESC
//
//
//---------------------------------------------------------------------------


// dÃ©finitions des types qui seront utilisÃ©s dans cette application

#include "GesPec12.h"
#include "Mc32Debounce.h"
#include "Mc32DriverLcd.h"
#include <stdint.h>
#include "bsp.h"

#define AFK_TIME 5000 //DurÃ©e d'inactivitÃ© avant d'Ã©taindre le rÃ©tro-Ã©clairage

// Descripteur des sinaux
S_SwitchDescriptor DescrA;
S_SwitchDescriptor DescrB;
S_SwitchDescriptor DescrPB;


// Structure pour les traitement du Pec12
S_Pec12_Descriptor Pec12;
S_S9_Descriptor S9;


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Principe utilisation des fonctions
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//
// ScanPec12 (bool ValA, bool ValB, bool ValPB)
//              Routine effectuant la gestion du Pec12
//              recoit la valeur des signaux et du boutons
//
// s'appuie sur le descripteur global.
// AprÃ¨s l'appel le descripteur est mis Ã  jour

// Comportement du PEC12
// =====================

// Attention 1 cran gÃ©nÃ¨re une pulse complÃ¨te (les 4 combinaisons)
// D'ou traitement uniquement au flanc descendand de B

// Dans le sens horaire CW:
//     __________                       __________________
// A:            |_____________________|        
//     ____________________                      _________
// B:                      |____________________|
// Dans le sens anti-horaire CCW:
//     ___________________                       _________
// A:                     |_____________________|                    
//     __________                      ________________
// B:            |____________________|


void Pec12Init (void)
{
   // Initialisation des descripteurs de touches Pec12
   DebounceInit(&DescrA);
   DebounceInit(&DescrB);
   DebounceInit(&DescrPB);
   
   // Init de la structure PEc12
    Pec12.Inc = 0;             // événement incrément  
    Pec12.Dec = 0;             // événement décrément 
    Pec12.OK = 0;              // événement action OK
    Pec12.ESC = 0;             // événement action ESC
    Pec12.NoActivity = 0;      // Indication d'activité
    Pec12.PressDuration = 0;   // Pour durée pression du P.B.
    Pec12.InactivityDuration = 0; // Durée inactivité
  
 } // Pec12Init


void ScanPec12 (bool ValA, bool ValB, bool ValPB)
{   
    //Traitement ainti-rebond sur A, B et PB
    DoDebounce (&DescrA, ValA);
    DoDebounce (&DescrB, ValB);
    DoDebounce (&DescrPB, ValPB);
    

       //=================================//
      // Detection Increment / Decrement //
     //=================================//
//    //Detection flanc descendant sur B
//    if(((DescrB.bits.KeyPrevInputValue == 0) && (DescrB.bits.KeyValue == 1) && (DescrA.bits.KeyValue == 1)) //
//        ||((DescrB.bits.KeyPrevInputValue == 1) && (DescrB.bits.KeyValue == 0) && (DescrA.bits.KeyValue == 0)))
//            
//    {
//        Pec12.Inc = 1;
//    }
//    
//    else if (((DescrB.bits.KeyPrevInputValue == 0) && (DescrB.bits.KeyValue == 1) && (DescrA.bits.KeyValue == 0)) //
//        ||((DescrB.bits.KeyPrevInputValue == 1) && (DescrB.bits.KeyValue == 0) && (DescrA.bits.KeyValue == 1 )))
//                
//    {
//        Pec12.Dec = 1;
//    }
       
    
    //Detection flanc descendant sur B
    if(DebounceIsPressed(&DescrB))
    {
        
        // Quittance de l'Ã©vÃ©nement
        DebounceClearPressed(&DescrB);
        
        if ( DebounceGetInput (&DescrA) == 0)
        {
           // Si A = 0 : situation CW = incrÃ©ment
           Pec12.Inc = 1;
        } 
         else
        {
            //decrementer la valeur
            Pec12.Dec = 1;
        }
    }
    
       //===========================//
      // Traitement du Push Button //
     //===========================//
    
//    if(DescrPB.bits.KeyPrevInputValue == 1)
//    {
//        Pec12.OK = 0;   
//        Pec12.ESC = 0;
//    }
//    else if(DescrPB.bits.KeyPrevInputValue == 0)
//    {
//        Pec12.PressDuration ++;
//    }
//    if ((Pec12.PressDuration >= 25) && (DescrPB.bits.KeyPrevInputValue == 1))
//    {
//        Pec12.ESC = 1;
//        Pec12.PressDuration = 0;
//    }
//    else if ((Pec12.PressDuration < 25)&&(Pec12.PressDuration > 0) && (DescrPB.bits.KeyPrevInputValue == 1))
//    {
//        Pec12.OK = 1;
//        Pec12.PressDuration = 0;
//    }
    
    //tester sur le pec est relacher
    if(DebounceIsPressed(&DescrPB)) //appui
    {
        DebounceClearPressed(&DescrPB);
        Pec12.PressDuration = 0;
    } 
   //teste si le bouton est appuyer
    else if(DebounceGetInput(&DescrPB) == 0) //maintien appuyé
    {
       // incrementer la duree de la pression
        Pec12.PressDuration++;
    }
   //tester si le bouton est relacher
    else if (DebounceIsReleased(&DescrPB))//relachement
    {
        DebounceClearReleased(&DescrPB);
        if (Pec12.PressDuration < 500)// si appi est inférieur à 500ms OK
        {
            Pec12.OK = 1;   //appui bref
        }
            
        else
        {
            Pec12.ESC = 1;  //appui long  
        }
    };

        
  
    
           //====================//
          //  Gestion BoutonS9  //
         //====================//
    //tester si le bouton est appyuer
    if(S_OK == 0)
    {
        S9.OK = 1;
    }
    else
    {
        //Affacer la valleur de S9
        S9.OK = 0;
    }
    
            //====================//
            // Gestion inactivite //
            //====================//
    
    

    //Increment ou reset du compteur AFK
    if((Pec12.Inc ==0) && (Pec12.Dec == 0) && (DescrPB.bits.KeyPrevInputValue == 1)&&(S9.OK == 0))
    {
        //Test durÃ©e d'inactivitÃ© > 5sec
        if(Pec12.InactivityDuration >= AFK_TIME)
        {
            //Pec12.InactivityDuration = 0;
            lcd_bl_off();
            Pec12.NoActivity = 1;
        }
        else
        {
           //incrémenter la duree l'inactive
            Pec12.InactivityDuration ++;
        }
    }
    
    else
    {
       //arreter l'inactiviter de LCD 
        if (Pec12.NoActivity == 1)
        {
           Pec12ClearInactivity();
           lcd_bl_on();  
        }
       //arreter le compteur
        Pec12.InactivityDuration = 0;
    }    
} //end of ScanPec12







//       Pec12IsPlus       true indique un nouveau increment
bool Pec12IsPlus    (void) {
   return (Pec12.Inc);
}

//       Pec12IsMinus      true indique un nouveau decrement
bool Pec12IsMinus    (void) {
   return (Pec12.Dec);
}

//       Pec12IsOK         true indique action OK
bool Pec12IsOK    (void) {
   return (Pec12.OK);
}

//       Pec12IsESC        true indique action ESC
bool Pec12IsESC    (void) {
   return (Pec12.ESC);
}

//       Pec12NoActivity   true indique abscence d'activite sur PEC12
bool Pec12NoActivity    (void) {
   return (Pec12.NoActivity);
}

bool S9_OK (void){
    return(S9.OK);
}


//  Fonctions pour quittance des indications
//       Pec12ClearPlus    annule indication d'incrÃ©ment
void Pec12ClearPlus   (void) {
   Pec12.Inc = 0;
}

//       Pec12ClearMinus   annule indication de dÃ©crÃ©ment
void Pec12ClearMinus   (void) {
   Pec12.Dec = 0;
}

//       Pec12ClearOK      annule indication action OK
void Pec12ClearOK   (void) {
   Pec12.OK = 0;
}

//       Pec12ClearESC     annule indication action ESC
void Pec12ClearESC   (void) {
   Pec12.ESC = 0;
}
//       Pec12ClearInactivity      annule indication action Inactivite
void Pec12ClearInactivity   (void) {
  Pec12.NoActivity = 0;
  Pec12.InactivityDuration = 0;
}
//       S9ClearOK     annule indication OK de S9
void S9ClearOK (void){
    S9.OK = 0;
}

