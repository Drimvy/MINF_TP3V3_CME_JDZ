// Tp3  manipulation MenuGen avec PEC12
// C. HUBER  10/02/2015 pour SLO2 2014-2015
// Fichier MenuGen.c
// Gestion du menu  du g√©n√©rateur
// Traitement cyclique √† 10 ms



#include <stdint.h>                   
#include <stdbool.h>
#include "MenuGen.h"

#include "DefMenuGen.h"
#include "Mc32DriverLcd.h"
#include "bsp.h"
#include "GesPec12.h"
#include <string.h>


#define MAX_ECH 100

E_MENU SELECTION_MENU;
E_FormesSignal Forme_No_Save;

// Initialisation du menu et des parametres
void MENU_Initialize(S_ParamGen *pParam)
{   
     /* //INIT DE TOUTES LES VALEURS DE GESTION
    //Valeur on deja ete init dans void  GENSIG_Initialize(S_ParamGen *pParam)
     
    pParam->Forme = SignalDentDeScie;
    pParam->Frequence = 100;        //Hz
    pParam->Amplitude = 10000;        //mV
    pParam->Offset = 0;             //mV*/
        
    //AFFICHAGE DU MENU INITIAL
    //Ligne 1
    lcd_bl_on();    
    lcd_gotoxy(2,1);
    printf_lcd("Forme");         
    lcd_gotoxy(17,1);
    printf_lcd("%c", pParam->Forme);
    
    //ligne 2
    lcd_gotoxy(2,2);    
    printf_lcd("Freq [Hz]"); 
    lcd_gotoxy(17,2);
    printf_lcd("%4d", pParam->Forme);
    
    //ligne 3
    lcd_gotoxy(2,3);    
    printf_lcd("Ampl [mV]"); 
    lcd_gotoxy(17,3);
    printf_lcd("%4d", pParam->Forme);
    
    //ligne 4
    lcd_gotoxy(2,4);    
    printf_lcd("Offset [mV]");  
    lcd_gotoxy(17,4);
    printf_lcd("%4d", pParam->Forme);
   
    //initaliser premiemiere parametre a† pointer dans le menu
    SELECTION_MENU = MENU_FORME;
    
}

/*Design menu de sauvgade*/
void Menu_Sauvgarde()
{

    Clear_LCD();
    lcd_gotoxy(4,2);    
    printf_lcd("Sauvgarde?"); //ligne 2
    lcd_gotoxy(5,3);    
    printf_lcd("(appui long)"); //ligne 2

   /*   //INIT DE TOUTES LES VALEURS DE GESTION
    pParam->Forme = SignalSinus;
    pParam->Frequence = 100;        //Hz
    pParam->Amplitude = 100;        //mV
    pParam->Offset = 0;             //mV*/
      
}

/*Supprimer toutes les ligne du LCD*/
void Clear_LCD()
{
    lcd_ClearLine(1);
    lcd_ClearLine(2);
    lcd_ClearLine(3);
    lcd_ClearLine(4);
}

// Execution du menu, appel cyclique depuis l'application
void MENU_Execute(S_ParamGen *pParam)
{
    int16_t Val_No_Save = 0;
    switch (SELECTION_MENU)
    {
        //Menu Forme//
        case MENU_FORME:
        {
            //ecrire sur la premiere ligne de la premiere colonne "*" du LCD
            lcd_gotoxy(1,1);
            printf_lcd("*");
            //incrementer choix du menu
            if (Pec12IsPlus() == 1)
            {
                SELECTION_MENU = MENU_FREQU;
            }
            //decrementer choix du menu
            else if (Pec12IsMinus() == 1)
            {
                SELECTION_MENU = MENU_OFFSET;
            }
            //Valider le choix
            else if (Pec12IsOK() == 1)
            {
                SELECTION_MENU = MENU_FORME_VALEUR;
            }
            //enregister dans la flash
            /*else if (S9_OK == 1)
            {
                
            }*/
            
            
        break;       
        }
        // Menu modifier la Forme de signal //
        case MENU_FORME_VALEUR:
        {
            lcd_gotoxy(1,1);
            printf_lcd("?");
            Forme_No_Save = pParam->Forme;
            //incrementer la forme
            if (Pec12IsPlus() == 1)
            {
                //test si egal a†la Singnal carree
                if(Forme_No_Save == SignalCarre )
                {
                    Forme_No_Save = SignalSinus;
                }
                //sinon incrementer pour obtenir la nouvelle forme
                else
                {
                    Forme_No_Save = Forme_No_Save + 1;
                } 
            }
            //decrementer la frome
            else if (Pec12IsMinus() == 1)
            {
                //test si egal Signal Sinus
                if(Forme_No_Save == SignalSinus )
                {
                    Forme_No_Save = SignalCarre;
                }
                //sinon decrementer pour obtenir la nouvelle forme
                else
                {
                    Forme_No_Save = Forme_No_Save -1;
                }
            }
            //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne forme en memoire
            else if (Pec12IsESC() == 1)
            {
                SELECTION_MENU = MENU_FORME;
            }
            
            else if (Pec12IsOK() == 1)
            {              
                //sauvgarder la nouvelle valeur
                pParam->Forme = Forme_No_Save;
                    
                //retoure au menu principal
                MENU_Initialize(pParam);
                //retourner sur la selection forme
                SELECTION_MENU = MENU_FORME;
            }
            
        break;       
        }
        
        // Menu Frequence //
        case MENU_FREQU:
        {
            //ecrire sur la 2eme ligne de la premiere colonne "*" du LCD
            lcd_gotoxy(1,2);
            printf_lcd("*");
            //incrementer choix du menu
            if (Pec12IsPlus() == 1)
            {
                SELECTION_MENU = MENU_AMPLI;
            }
            //decrementer choix du menu
            else if (Pec12IsMinus() == 1)
            {
                SELECTION_MENU = MENU_FORME;
            }
            //Valider le choix
            else if (Pec12IsOK() == 1)
            {
                SELECTION_MENU = MENU_FREQU_VALEUR;
            }
        break;       
        }
        // Menu modifier la frequence du signal //
        case MENU_FREQU_VALEUR:
        {
            //afiicher un "?" sur la 2 eme ligne, la premiere colonne
            lcd_gotoxy(1,2);
            printf_lcd("?");
            //recuperer la valeur de la frequence, l'enregister sur la variable
            Val_No_Save = pParam->Frequence;
            
            //incrementer la valeur de la fr√©quence
            if (Pec12IsPlus() == 1)
            {
                //test si superieur ou egal a la frequence max
                if(Val_No_Save >= 2000 )
                {
                    Val_No_Save = 2000;
                }
                //sinon incrementer par pas de 20
                else
                {
                    Val_No_Save = Val_No_Save +20;
                } 
            }
            //decrementer la valeur de la frequence
            else if (Pec12IsMinus() == 1)
            {
                //test si inferieur ou Ègal a†la frequence min
                if(Val_No_Save <= 20 )
                {
                    Val_No_Save = 20;
                }
                //sinon decrementer par pas de 20
                else
                {
                    Val_No_Save = Val_No_Save -20;
                }
            }
            //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire 
            else if (Pec12IsESC() == 1)
            {
                SELECTION_MENU = MENU_FREQU;
            }
            //si on appuye sur ok
            else if (Pec12IsOK() == 1)
            {
                //sauvgarder la nouvelle valeur 
                pParam->Frequence = Forme_No_Save;
               //retoure au menu principal
                MENU_Initialize(pParam);
                //retourner sur la selection frequence
                SELECTION_MENU = MENU_FREQU;
            }
            
        break;       
        }
        // Menu Amplification //
        case MENU_AMPLI:
        {
            //ecrire sur la 3eme ligne de la premiere colonne "*" du LCD
            lcd_gotoxy(1,3);
            printf_lcd("*");
            //incrementer choix du menu
            if (Pec12IsPlus() == 1)
            {
                SELECTION_MENU = MENU_OFFSET;
            }
            //decrementer choix du menu
            else if (Pec12IsMinus() == 1)
            {
                SELECTION_MENU = MENU_FREQU;
            }
            //Valider le choix
            else if (Pec12IsOK() == 1)
            {
                SELECTION_MENU = MENU_AMPLI_VALEUR;
            }
        break;       
        }
        // Menu modifier l'amplitude du signal //
        case MENU_AMPLI_VALEUR:
        {
            //afiicher un "?" sur la 3 eme ligne, 1a 1 ere colonne
            lcd_gotoxy(1,3);
            printf_lcd("?");
            //recuperer la valeur de l'amplitude, l'enregister sur la variable
            Val_No_Save = pParam->Amplitude;
            
            //incrementer la valeur de l'amplitude 
            if (Pec12IsPlus() == 1)
            {
                //test si superieur ou egal a† l'amplitude max
                if(Val_No_Save >= 10000 )
                {
                    Val_No_Save = 2000;
                }
                //sinon incrementer par pas de 100
                else
                {
                    Val_No_Save = Val_No_Save +100;
                } 
            }
            //decrementer la valeur de l'amplitude 
            else if (Pec12IsMinus() == 1)
            {
                //test si inferieur ou egal e† l'amplitude min
                if(Val_No_Save <= 0 )
                {
                    Val_No_Save = 0;
                }
                //sinon decrementer par pas de 100
                else
                {
                    Val_No_Save = Val_No_Save -100;
                }
            }
            //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire 
            else if (Pec12IsESC() == 1)
            {
                SELECTION_MENU = MENU_AMPLI;
            }
            //si on appuye sur ok
            else if (Pec12IsOK() == 1)
            {
                //sauvgarder la nouvelle valeur 
                 pParam->Amplitude = Forme_No_Save;
                //retoure au menu principal
                MENU_Initialize(pParam);
                //retourner sur la selection de l'amplitude
                SELECTION_MENU = MENU_AMPLI;
            }
            
        break;       
        }
        
        // Menu OFFSET //
        case MENU_OFFSET:
        {
            //ecrire sur la 4eme ligne de la premiere colonne "*" du LCD
            lcd_gotoxy(1,4);
            printf_lcd("*");
            //incrementer choix du menu
            if (Pec12IsPlus() == 1)
            {
                SELECTION_MENU = MENU_FORME;
            }
            //decrementer choix du menu
            else if (Pec12IsMinus() == 1)
            {
                SELECTION_MENU = MENU_AMPLI;
            }
            //Valider le choix
            else if (Pec12IsOK() == 1)
            {
                SELECTION_MENU = MENU_OFFSET_VALEUR;
            }
        break;       
        }
        // Menu modifier l'offset du signal //
        case MENU_OFFSET_VALEUR:
        {
            //afiicher un "?" sur la 4 eme ligne, 1 ere colonne
            lcd_gotoxy(1,4);
            printf_lcd("?");
            //recuperer la valeur de l'offset, l'enregister sur la variable
            Val_No_Save = pParam->Offset;
            
            //incrementer la valeur de l'offset 
            if (Pec12IsPlus() == 1)
            {
                //test si supperieur ou egal e l'offset max
                if(Val_No_Save >= 5000 )
                {
                    Val_No_Save = 5000;
                }
                //sinon incrementer par pas de 100
                else
                {
                    Val_No_Save = Val_No_Save +100;
                } 
            }
            //decrementer la valeur de l'offset
            else if (Pec12IsMinus() == 1)
            {
                //test si inferieur ou egal √† l'offset min
                if(Val_No_Save <= -5000 )
                {
                    Val_No_Save = -5000;
                }
                //sinon decrementer par pas de 100
                else
                {
                    Val_No_Save = Val_No_Save -100;
                }
            }
            //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire 
            else if (Pec12IsESC() == 1)
            {
                SELECTION_MENU = MENU_OFFSET;
            }
            //si on appuye sur ok
            else if (Pec12IsOK() == 1)
            {
                
                //sauvgarder la nouvelle valeur 
                pParam->Amplitude = Forme_No_Save;
               
                //retoure au menu principal
                MENU_Initialize(pParam);
                //retourner sur la selection de l'offset
                SELECTION_MENU = MENU_OFFSET;;
            }
            
        break;       
        }        
   
    }

}




