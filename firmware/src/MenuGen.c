// Tp3  manipulation MenuGen avec PEC12
// C. HUBER  10/02/2015 pour SLO2 2014-2015
// Fichier MenuGen.c
// Gestion du menu  du générateur
// Traitement cyclique à 10 ms



#include <stdint.h>                   
#include <stdbool.h>
#include "MenuGen.h"

#define MAX_ECH 100

// Initialisation du menu et des paramètres
void MENU_Initialize(S_ParamGen *pParam)
{
}


// Execution du menu, appel cyclique depuis l'application
void MENU_Execute(S_ParamGen *pParam)
{
    static uint16_t EchNb = 0;
    const uint16_t step = 65535 / MAX_ECH;
    SPI_WriteToDac(0,step*EchNb);
    EchNb ++;
    EchNb = EchNb % MAX_ECH;
}




