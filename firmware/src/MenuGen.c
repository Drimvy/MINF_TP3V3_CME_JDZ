// Tp3  manipulation MenuGen avec PEC12
// C. HUBER  10/02/2015 pour SLO2 2014-2015
// Fichier MenuGen.c
// Gestion du menu  du gÃ©nÃ©rateur
// Traitement cyclique Ã  10 ms



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
// Structure pour les traitement du Pec12
S_Pec12_Descriptor Pec12;
S_S9_Descriptor S9;

// Initialisation du menu et des parametres
void MENU_Initialize(S_ParamGen *pParam)
{   
     //INIT DE TOUTES LES VALEURS DE GESTION
    //Valeur on deja ete init dans void  GENSIG_Initialize(S_ParamGen *pParam)
    Clear_LCD();   
    //AFFICHAGE DU MENU INITIAL
    //Ligne 1
    lcd_bl_on();    
    lcd_gotoxy(2,1);
    printf_lcd("Forme");         
    lcd_gotoxy(13,1);
    printf_lcd("%d", pParam->Forme);
    
    //ligne 2
    lcd_gotoxy(2,2);    
    printf_lcd("Freq[Hz]"); 
    lcd_gotoxy(13,2);
    printf_lcd("%.3d", pParam->Frequence);
    
    //ligne 3
    lcd_gotoxy(2,3);    
    printf_lcd("Ampl[mV]"); 
    lcd_gotoxy(13,3);
    printf_lcd("%.4d", pParam->Amplitude);
    
    //ligne 4
    lcd_gotoxy(2,4);    
    printf_lcd("Offset[mV]");  
    lcd_gotoxy(13,4);
    printf_lcd("%.4d", (int)pParam->Offset);
   
    //initaliser premiemiere parametre a  pointer dans le menu
    SELECTION_MENU = MENU_FORME;
    
}

/*Design menu de sauvgade*/
void Menu_Sauvgarde()
{
    Clear_LCD();
    lcd_gotoxy(6,2);    
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

void Menu_interface(S_ParamGen *pParam)
{
    Clear_LCD();
    lcd_gotoxy(2,1);
    printf_lcd("Forme");         
    lcd_gotoxy(13,1);
    printf_lcd("%d", pParam->Forme);
    
    //ligne 2
    lcd_gotoxy(2,2);    
    printf_lcd("Freq[Hz]"); 
    lcd_gotoxy(13,2);
    printf_lcd("%.3d", pParam->Frequence);
    
    //ligne 3
    lcd_gotoxy(2,3);    
    printf_lcd("Ampl[mV]"); 
    lcd_gotoxy(13,3);
    printf_lcd("%.4d", pParam->Amplitude);
    
    //ligne 4
    lcd_gotoxy(2,4);    
    printf_lcd("Offset[mV]");  
    lcd_gotoxy(13,4);
    printf_lcd("%.4d", pParam->Offset);
}

// Execution du menu, appel cyclique depuis l'application
void MENU_Execute(S_ParamGen *pParam)
{
    uint8_t static Timer_2Sec = 0;
    int16_t Val_No_Save = 0;
    uint8_t static MAJ_LCD = 0;
    //enregister dans la flash
    if (S9.OK == 1)
    {
        //si le meintiens du bouton S9 > à 2 sec
        Menu_Sauvgarde();
        MAJ_LCD = 1;
        if (Timer_2Sec >= 199)
        {
            //enregistrer dans la flash
            Menu_interface(pParam);
            Timer_2Sec = 0;
        }
        else
        {
            Timer_2Sec ++;
        }        
        
    }
    else
    {
        if (MAJ_LCD == 1)
        {
            Menu_interface(pParam);
            Timer_2Sec = 0;
            MAJ_LCD = 0;
        }
        
        switch (SELECTION_MENU)
        {
            //Menu Forme//
            case MENU_FORME:
            {
                //ecrire sur la premiere ligne de la premiere colonne "*" du LCD
                lcd_gotoxy(1,1);
                printf_lcd("*");
                //incrementer choix du menu
                if (Pec12.Inc == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 1);
                    printf_lcd(" ");
                    //modifier la sélection du menu
                    SELECTION_MENU = MENU_FREQU;
                }
                //decrementer choix du menu
                else if (Pec12.Dec == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 1);
                    printf_lcd(" ");
                    //modifier la sélection du menu
                    SELECTION_MENU = MENU_OFFSET;
                }
                //Valider le choix
                else if (Pec12.OK == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 1);
                    printf_lcd(" ");
                    //modifier la valeur 
                    SELECTION_MENU = MENU_FORME_VALEUR;
                }

            break;       
            }

            // Menu modifier la Forme de signal //
            case MENU_FORME_VALEUR:
            {
                lcd_gotoxy(1,1);
                printf_lcd("?");
                Val_No_Save = pParam->Forme;
                //incrementer la forme
                if (Pec12.Inc == 1)
                {
                    //test si egal a la Singnal carree
                    if(Val_No_Save == 4)
                    {
                        Val_No_Save = 1;
                        lcd_gotoxy(13,1);
                        printf_lcd("%d", Val_No_Save);
                    }
                    //sinon incrementer pour obtenir la nouvelle forme
                    else
                    {
                        Forme_No_Save = Forme_No_Save + 1;
                        lcd_gotoxy(13,1);
                        printf_lcd("%d", Val_No_Save);
                    } 
                }
                //decrementer la frome
                else if (Pec12.Dec == 1)
                {
                    //test si egal Signal Sinus
                    if(Val_No_Save == 1 )
                    {
                        Val_No_Save = 4;
                        lcd_gotoxy(13,1);
                        printf_lcd("%d", Val_No_Save);
                    }
                    //sinon decrementer pour obtenir la nouvelle forme
                    else
                    {
                        Val_No_Save = Val_No_Save - 1;
                        lcd_gotoxy(13,1);
                        printf_lcd("%d", Val_No_Save);
                    }
                }
                //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne forme en memoire
                if (Pec12.ESC == 1)
                {
                    //retourner sur le menu selection 
                    SELECTION_MENU = MENU_FORME;
                    
                    //effacer "?"
                    lcd_gotoxy( 1, 1);
                    printf_lcd(" ");
                }

                else if (Pec12.OK == 1)
                {              
                    //sauvgarder la nouvelle valeur
                    pParam->Forme = Forme_No_Save;

                    //retoure au menu principal
                    MENU_Initialize(pParam);
                    //retourner sur la selection forme
                    SELECTION_MENU = MENU_FORME;
                    
                    //effacer "?"
                    lcd_gotoxy( 1, 1);
                    printf_lcd(" ");
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
                if (Pec12.Inc == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 2);
                    printf_lcd(" ");
                    //modifier la sélection du menu
                    SELECTION_MENU = MENU_AMPLI;
                }
                //decrementer choix du menu
                else if (Pec12.Dec == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 2);
                    printf_lcd(" ");
                    //modifier la sélection du menu
                    SELECTION_MENU = MENU_FORME;
                }
                //Valider le choix
                else if (Pec12.OK == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 2);
                    printf_lcd(" ");
                    //modifier la valeur
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
                Val_No_Save = Val_No_Save;

                //incrementer la valeur de la frÃ©quence
                if (Pec12.Inc == 1)
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
                        lcd_gotoxy(13,2);
                        printf_lcd("%.3d", Val_No_Save);
                    } 
                }
                //decrementer la valeur de la frequence
                else if (Pec12.Dec == 1)
                {
                    //test si inferieur ou égal a la frequence min
                    if(Val_No_Save <= 20 )
                    {
                        Val_No_Save = 20;
                    }
                    //sinon decrementer par pas de 20
                    else
                    {
                        Val_No_Save = Val_No_Save -20;
                        lcd_gotoxy(13,2);
                        printf_lcd("%.3d", Val_No_Save);
                    }
                }
                //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire 
                if (Pec12.ESC == 1)
                {
                    //retourner sur le menu selection 
                    SELECTION_MENU = MENU_FREQU;
                    //effacer "?"
                    lcd_gotoxy( 1, 2);
                    printf_lcd(" ");
                }
                //si on appuye sur ok
                else if (Pec12.OK == 1)
                {
                    //sauvgarder la nouvelle valeur 
                    pParam->Frequence = Forme_No_Save;
                   //retoure au menu principal
                    MENU_Initialize(pParam);
                    //retourner sur la selection frequence
                    SELECTION_MENU = MENU_FREQU;
                    
                    //effacer "?"
                    lcd_gotoxy( 1, 2);
                    printf_lcd(" ");
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
                if (Pec12.Inc == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 3);
                    printf_lcd(" ");
                    //modifier la sélection du menu
                    SELECTION_MENU = MENU_OFFSET;
                }
                //decrementer choix du menu
                else if (Pec12.Dec == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 3);
                    printf_lcd(" ");
                    //modifier la sélection du menu
                    SELECTION_MENU = MENU_FREQU;
                }
                //Valider le choix
                else if (Pec12.OK == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 2);
                    printf_lcd(" ");
                    //modifier la valeur
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
                if (Pec12.Inc == 1)
                {
                    //test si superieur ou egal a  l'amplitude max
                    if(Val_No_Save >= 10000 )
                    {
                        Val_No_Save = 2000;
                    }
                    //sinon incrementer par pas de 100
                    else
                    {
                        Val_No_Save = Val_No_Save +100;
                        lcd_gotoxy(13,3);
                        printf_lcd("%.4d", Val_No_Save);
                    } 
                }
                //decrementer la valeur de l'amplitude 
                else if (Pec12.Dec == 1)
                {
                    //test si inferieur ou egal e  l'amplitude min
                    if(Val_No_Save <= 0 )
                    {
                        Val_No_Save = 0;
                    }
                    //sinon decrementer par pas de 100
                    else
                    {
                        Val_No_Save = Val_No_Save -100;
                        lcd_gotoxy(13,3);
                        printf_lcd("%.4d", Val_No_Save);
                    }
                }
                //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire 
                if (Pec12.ESC == 1)
                {
                    //retourner sur le menu selection 
                    SELECTION_MENU = MENU_AMPLI;
                    
                    //effacer "?"
                    lcd_gotoxy( 1, 3);
                    printf_lcd(" ");
                }
                //si on appuye sur ok
                else if (Pec12.OK == 1)
                {
                    //sauvgarder la nouvelle valeur 
                     pParam->Amplitude = Forme_No_Save;
                    //retoure au menu principal
                    MENU_Initialize(pParam);
                    //retourner sur la selection de l'amplitude
                    SELECTION_MENU = MENU_AMPLI;
                    
                    //effacer "?"
                    lcd_gotoxy( 1, 3);
                    printf_lcd(" ");
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
                if (Pec12.Inc == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 4);
                    printf_lcd(" ");
                    //modifier la sélection du menu
                    SELECTION_MENU = MENU_FORME;
                }
                //decrementer choix du menu
                else if (Pec12.Dec == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 4);
                    printf_lcd(" ");
                    //modifier la sélection du menu
                    SELECTION_MENU = MENU_AMPLI;
                }
                //Valider le choix
                else if (Pec12.OK == 1)
                {
                    //effacer "*"
                    lcd_gotoxy( 1, 4);
                    printf_lcd(" ");
                    //modifier la valeur
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
                if (Pec12.Inc == 1)
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
                        lcd_gotoxy(13,4);
                        printf_lcd("%.4d", abs(Val_No_Save));
                    } 
                }
                //decrementer la valeur de l'offset
                else if (Pec12.Dec == 1)
                {
                    //test si inferieur ou egal a  l'offset min
                    if(Val_No_Save <= -5000 )
                    {
                        Val_No_Save = -5000;
                    }
                    //sinon decrementer par pas de 100
                    else
                    {
                        Val_No_Save = Val_No_Save -100;
                        lcd_gotoxy(13,4);
                        printf_lcd("%.4d", abs(Val_No_Save));
                    }
                }
                //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire 
                if (Pec12.ESC == 1)
                {
                    //retourner sur le menu selection 
                    SELECTION_MENU = MENU_OFFSET;
                    
                    //effacer "?"
                    lcd_gotoxy( 1, 4);
                    printf_lcd(" ");
                }
                //si on appuye sur ok
                else if (Pec12.OK == 1)
                {

                    //sauvgarder la nouvelle valeur 
                    pParam->Amplitude = Forme_No_Save;

                    //retoure au menu principal
                    MENU_Initialize(pParam);
                    //retourner sur la selection de l'offset
                    SELECTION_MENU = MENU_OFFSET;
                    
                    //effacer "?"
                    lcd_gotoxy( 1, 4);
                    printf_lcd(" ");
                }

            break;       
            }        
        }
    }
}




