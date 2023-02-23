// Tp3  manipulation MenuGen avec PEC12
// C. HUBER  10/02/2015 pour SLO2 2014-2015
// Fichier MenuGen.c
// Gestion du menu  du générateur
// Traitement cyclique à 10 ms



#include <stdint.h>                   
#include <stdbool.h>
#include "MenuGen.h"

<<<<<<< HEAD
#include "DefMenuGen.h"
#include "Mc32DriverLcd.h"
#include "bsp.h"

=======
>>>>>>> c3d542c1bcf1366d822d56c3708f938bb63ed1ad

#define MAX_ECH 100

// Initialisation du menu et des paramètres
void MENU_Initialize(S_ParamGen *pParam)
{
      //INIT DE TOUTES LES VALEURS DE GESTION
    pParam->Forme = SignalSinus;
    pParam->Frequence = 100;        //Hz
    pParam->Amplitude = 100;        //mV
    pParam->Offset = 0;             //mV
    
    
    //AFFICHAGE DU MENU INITIAL
    lcd_bl_on();
    
    lcd_gotoxy(2,1);
    printf_lcd("Forme = %c", &pParam->Forme);         //ligne 1
    
    lcd_gotoxy(2,2);    
    printf_lcd("Freq [Hz] = %d", &pParam->Frequence); //ligne 2
    
    lcd_gotoxy(2,3);    
    printf_lcd("Ampl [mV] = %d", &pParam->Amplitude); //ligne 3
    
    lcd_gotoxy(2,4);    
    printf_lcd("Offset [mV] = %d", &pParam->Offset);  //ligne 4
}


// Execution du menu, appel cyclique depuis l'application
void MENU_Execute(S_ParamGen *pParam)
{
    /*static uint16_t EchNb = 0;
    const uint16_t step = 65535 / MAX_ECH;
    SPI_WriteToDac(0,step*EchNb);
    EchNb ++;
<<<<<<< HEAD
    EchNb = EchNb % MAX_ECH;
    
    //UTILISANT LES FONCTIONS DU PEC12 + BTN -> REPONDS AUX REGLAGES DE L'UTILISATEUR
    //ET APPELLE LES FCT DE MàJ DU GENERATEUR
    
    //FCT PREVUE POUR UN APPEL CYCLIQUE -> BASEE SUR UNE MACHINE D'ETAT + NON-BLOQUANTE
    
    
    
=======
    EchNb = EchNb % MAX_ECH;*/
>>>>>>> c3d542c1bcf1366d822d56c3708f938bb63ed1ad
}




