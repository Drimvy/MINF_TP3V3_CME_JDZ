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

//enumeration gestion aafichage
typedef enum  { MENU_FORME, MENU_FORME_VALEUR, MENU_FREQU, MENU_FREQU_VALEUR, MENU_AMPLI, MENU_AMPLI_VALEUR, MENU_OFFSET, MENU_OFFSET_VALEUR} E_MENU;

//structure pour les valeur pas encore sauvgarder
typedef struct {
      uint8_t Forme;
      uint16_t Frequence;
      uint16_t Amplitude;
      int16_t Offset;

} S_No_save;

////////////*prototype de fonction*//////////
// Initialisation du menu et des parametres
void MENU_Initialize(S_ParamGen *pParam);
//gere l'affichage LCD pour le menu principal
void Menu_interface(S_ParamGen *pParam);
// Execution du menu, appel cyclique depuis l'application
void MENU_Execute(S_ParamGen *pParam);
/*Design menu de sauvgade*/
void Menu_Sauvgarde();
/*Design menu de sauvgade OK*/
void Sauvgarde_OK();
/*Design menu de sauvgade ANNULER*/
void Sauvgarde_ANNULE();
/*Supprimer toutes les ligne du LCD*/
void Clear_LCD();
/*gestion de l'affichage avec le PEG12*/
void Menu_GESTION_PEG12(S_ParamGen *pParam);            

#endif




  
   







