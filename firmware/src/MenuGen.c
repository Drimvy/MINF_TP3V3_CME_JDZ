// Tp3  manipulation MenuGen avec PEC12
// C. HUBER  10/02/2015 pour SLO2 2014-2015
// Fichier MenuGen.c
// Gestion du menu  du générateur
// Traitement cyclique à 10 ms



#include <stdint.h>                   
#include <stdbool.h>
#include "MenuGen.h"

#include "DefMenuGen.h"
#include "Mc32DriverLcd.h"
#include "bsp.h"
#include "GesPec12.h"


#define MAX_ECH 100

E_MENU SELECTION_MENU;
// Initialisation du menu et des paramètres
void MENU_Initialize(S_ParamGen *pParam)
{   
     /* //INIT DE TOUTES LES VALEURS DE GESTION
    //Valeur on déja été init dans void  GENSIG_Initialize(S_ParamGen *pParam)
     
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
   
    //initaliser première paramètre à pointer dans le menu
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
    char Forme_No_Save;
    int16_t Val_No_Save;
    switch (SELECTION_MENU)
    {
        case MENU_FORME:
        {
            lcd_gotoxy(1,1);
            printf_lcd("*");
            if (Pec12IsPlus == 1)
            {
                SELECTION_MENU = MENU_FREQU;
            }
            else if (Pec12IsMinus == 1)
            {
                SELECTION_MENU = MENU_OFFSET;
            }
            else if (Pec12IsOK == 1)
            {
                SELECTION_MENU = MENU_FORME_VALEUR;
            }
            /*else if (Pec12IsESC == 1)
            {
                SELECTION_MENU = MENU_FORME;
            }*/
            
        break;       
        }
        case MENU_FORME_VALEUR:
        {
            lcd_gotoxy(1,1);
            printf_lcd("?");
            Forme_No_Save = pParam->Forme;
            //incrementer la forme
            if (Pec12IsPlus == 1)
            {
                //test si égal à la ...
                if(Forme_No_Save == "SignalCarre" )
                {
                    Val_No_Save = "SignalSinus";
                }
                //sinon incrémenter pour obtenir la nouvelle forme
                else
                {
                    Forme_No_Save = Forme_No_Save + 1;
                } 
            }
            //décrementer la frome
            else if (Pec12IsMinus == 1)
            {
                //test si égal ...
                if(Val_No_Save == "SignalSinus" )
                {
                    Val_No_Save = "SignalCarre";
                }
                //sinon décrémenter pour obtenir la nouvelle forme
                else
                {
                    Forme_No_Save = Forme_No_Save -1;
                }
            }
            //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne forme en mémoire
            else if (Pec12IsESC == 1)
            {
                SELECTION_MENU = MENU_FORME;
            }
            
            else if (Pec12IsOK == 1)
            {
                //afficher le menu de sauvgarde
                Menu_Sauvgarde();
                //si on meintiens 2 sec ou plus le bouton OK
                if (Pec12.PressDuration >= 2sec)
                {
                    //sauvgarder la nouvelle valeur
                    pParam->Forme = Forme_No_Save;
                    
                }
                //ne pas suavgarder la nouvelle valeur
                else 
                {                   
                }
                //retoure au menu principal
                MENU_Initialize(S_ParamGen *pParam);
                //retourner sur la selection forme
                SELECTION_MENU = MENU_FORME;
            }
            
        break;       
        }
        
        
        case MENU_FREQU:
        {
            lcd_gotoxy(1,2);
            printf_lcd("*");  
            if (Pec12IsPlus == 1)
            {
                SELECTION_MENU = MENU_AMPLI;
            }
            else if (Pec12IsMinus == 1)
            {
                SELECTION_MENU = MENU_FORME;
            }
            else if (Pec12IsOK == 1)
            {
                SELECTION_MENU = MENU_FREQU_VALEUR;
            }
        break;       
        }
        
        case MENU_FREQU_VALEUR:
        {
            //afiicher un "?" sur la 2 ème ligne, 1 ère colonne
            lcd_gotoxy(1,2);
            printf_lcd("?");
            //récuperer la valeur de la fréquence, l'enregister sur la variable
            Forme_No_Save = pParam->Frequence;
            
            //incrementer la valeur de la fréquence
            if (Pec12IsPlus == 1)
            {
                //test si suppérieur ou égal à la fréquence max
                if(Val_No_Save >= 2000 )
                {
                    Val_No_Save = 2000;
                }
                //sinon incrémenter par pas de 20
                else
                {
                    Val_No_Save = Val_No_Save +20;
                } 
            }
            //décrementer la valeur de la fréquence
            else if (Pec12IsMinus == 1)
            {
                //test si inférieur ou égal à la fréquence min
                if(Val_No_Save <= 20 )
                {
                    Val_No_Save = 20;
                }
                //sinon décrémenter par pas de 20
                else
                {
                    Val_No_Save = Val_No_Save -20;
                }
            }
            //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en mémoire 
            else if (Pec12IsESC == 1)
            {
                SELECTION_MENU = MENU_FREQU;
            }
            //si on appuye sur ok
            else if (Pec12IsOK == 1)
            {
                //afficher le menu de sauvgarde
                Menu_Sauvgarde();
                //si on meintiens 2 sec ou plus le bouton OK
                if (Pec12.PressDuration >= 2sec)
                {
                    //sauvgarder la nouvelle valeur 
                    pParam->Frequence = Forme_No_Save;
                }
                //sinon ne pas suavgarder la nouvelle valeur
                else 
                {
                }
               //retoure au menu principal
                MENU_Initialize(S_ParamGen *pParam);
                //retourner sur la selection frequence
                SELECTION_MENU = MENU_FREQU;
            }
            
        break;       
        }
        
        case MENU_AMPLI:
        {
            lcd_gotoxy(1,3);
            printf_lcd("*");
            if (Pec12IsPlus == 1)
            {
                SELECTION_MENU = MENU_OFFSET;
            }
            else if (Pec12IsMinus == 1)
            {
                SELECTION_MENU = MENU_FREQU;
            }
            else if (Pec12IsOK == 1)
            {
                SELECTION_MENU = MENU_AMPLI_VALEUR;
            }
        break;       
        }
        case MENU_AMPLI_VALEUR:
        {
            //afiicher un "?" sur la 3 ème ligne, 1 ère colonne
            lcd_gotoxy(1,3);
            printf_lcd("?");
            //récuperer la valeur de l'amplitude, l'enregister sur la variable
            Forme_No_Save = pParam->Amplitude;
            
            //incrementer la valeur de l'amplitude 
            if (Pec12IsPlus == 1)
            {
                //test si suppérieur ou égal à l'amplitude max
                if(Val_No_Save >= 10000 )
                {
                    Val_No_Save = 2000;
                }
                //sinon incrémenter par pas de 100
                else
                {
                    Val_No_Save = Val_No_Save +100;
                } 
            }
            //décrementer la valeur de l'amplitude 
            else if (Pec12IsMinus == 1)
            {
                //test si inférieur ou égal à l'amplitude min
                if(Val_No_Save <= 0 )
                {
                    Val_No_Save = 0;
                }
                //sinon décrémenter par pas de 100
                else
                {
                    Val_No_Save = Val_No_Save -100;
                }
            }
            //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en mémoire 
            else if (Pec12IsESC == 1)
            {
                SELECTION_MENU = MENU_AMPLI;
            }
            //si on appuye sur ok
            else if (Pec12IsOK == 1)
            {
                //afficher le menu de sauvgarde
                Menu_Sauvgarde();
                //si on meintiens 2 sec ou plus le bouton OK
                if (Pec12.PressDuration >= 2sec)
                {
                    //sauvgarder la nouvelle valeur 
                    pParam->Amplitude = Forme_No_Save;
                }
                //sinon ne pas suavgarder la nouvelle valeur
                else 
                {
                }
               //retoure au menu principal
                MENU_Initialize(S_ParamGen *pParam);
                //retourner sur la selection de l'amplitude
                SELECTION_MENU = MENU_AMPLI;
            }
            
        break;       
        }
        
        
        case MENU_OFFSET:
        {
            if (Pec12IsPlus == 1)
            {
                SELECTION_MENU = MENU_FORME;
            }
            else if (Pec12IsMinus == 1)
            {
                SELECTION_MENU = MENU_AMPLI;
            }
            else if (Pec12IsOK == 1)
            {
                SELECTION_MENU = MENU_OFFSET_VALEUR;
            }
        break;       
        }
        case MENU_OFFSET_VALEUR:
        {
            //afiicher un "?" sur la 4 ème ligne, 1 ère colonne
            lcd_gotoxy(1,4);
            printf_lcd("?");
            //récuperer la valeur de l'offset, l'enregister sur la variable
            Forme_No_Save = pParam->Offset;
            
            //incrementer la valeur de l'amplitude 
            if (Pec12IsPlus == 1)
            {
                //test si suppérieur ou égal à l'offset max
                if(Val_No_Save >= 5000 )
                {
                    Val_No_Save = 5000;
                }
                //sinon incrémenter par pas de 100
                else
                {
                    Val_No_Save = Val_No_Save +100;
                } 
            }
            //décrementer la valeur de l'offset
            else if (Pec12IsMinus == 1)
            {
                //test si inférieur ou égal à l'offset min
                if(Val_No_Save <= -5000 )
                {
                    Val_No_Save = -5000;
                }
                //sinon décrémenter par pas de 100
                else
                {
                    Val_No_Save = Val_No_Save -100;
                }
            }
            //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en mémoire 
            else if (Pec12IsESC == 1)
            {
                SELECTION_MENU = MENU_OFFSET;
            }
            //si on appuye sur ok
            else if (Pec12IsOK == 1)
            {
                //afficher le menu de sauvgarde
                Menu_Sauvgarde();
                //si on meintiens 2 sec ou plus le bouton OK
                if (Pec12.PressDuration >= 2sec)
                {
                    //sauvgarder la nouvelle valeur 
                    pParam->Amplitude = Forme_No_Save;
                }
                //sinon ne pas suavgarder la nouvelle valeur
                else 
                {
                }
               //retoure au menu principal
                MENU_Initialize(S_ParamGen *pParam);
                //retourner sur la selection de l'offset
                SELECTION_MENU = MENU_OFFSET;;
            }
            
        break;       
        }        
   
    }
   
}




