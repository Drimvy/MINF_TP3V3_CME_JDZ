#ifndef MenuGen_h
#define MenuGen_h

// Tp3  manipulation MenuGen avec PEC12
// C. HUBER  03.02.2016
// Fichier MenuGen.h
// Gestion du menu  du générateur
// Traitement cyclique à 1 ms du Pec12


#include <stdbool.h>
#include <stdint.h>
#include "DefMenuGen.h"

typedef enum  { MENU_FORME, MENU_FORME_VALEUR, MENU_FREQU, MENU_FREQU_VALEUR, MENU_AMPLI, MENU_AMPLI_VALEUR, MENU_OFFSET, MENU_OFFSET_VALEUR} E_MENU;


void MENU_Initialize(S_ParamGen *pParam);

void Menu_Sauvgarde();

void Clear_LCD();

void MENU_Execute(S_ParamGen *pParam);

#endif




  
   







