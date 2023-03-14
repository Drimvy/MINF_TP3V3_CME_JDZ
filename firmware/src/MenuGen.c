// Tp3  manipulation MenuGen avec PEC12
// C. HUBER  10/02/2015 pour SLO2 2014-2015
// Fichier MenuGen.c
// Gestion du menu  du gÃ?Â©nÃ?Â©rateur
// Traitement cyclique Ã?Â  10 ms



#include <stdint.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include "MenuGen.h"
#include "Generateur.h"

#include "DefMenuGen.h"
#include "Mc32DriverLcd.h"
#include "bsp.h"
#include "GesPec12.h"


#define MAX_ECH 100

E_MENU SELECTION_MENU;
S_No_save Val;
// Structure pour les traitement du Pec12
S_Pec12_Descriptor Pec12;
S_S9_Descriptor S9;

// Initialisation du menu et des parametres
void MENU_Initialize(S_ParamGen *pParam)
{   
     //INIT DE TOUTES LES VALEURS DE GESTION
    //Valeur on deja ete init dans void  GENSIG_Initialize(S_ParamGen *pParam)
    // INIT valeur pour l'affichage
    //recuperer la valeur de la frequence, l'enregister sur la variable
    //recuperer la valeur de la frequence, l'enregister sur la variable
    Val.Forme = pParam->Forme;
    Val.Frequence = pParam->Frequence;
    Val.Amplitude = pParam->Amplitude;
    Val.Frequence = abs(pParam->Frequence);
   
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
    printf_lcd("%d", pParam->Frequence);
    
    //ligne 3
    lcd_gotoxy(2,3);    
    printf_lcd("Ampl[mV]"); 
    lcd_gotoxy(13,3);
    printf_lcd("%d", pParam->Amplitude);
    
    //ligne 4
    lcd_gotoxy(2,4);    
    printf_lcd("Offset[mV]");  
    lcd_gotoxy(13,4);
    printf_lcd("%d", (int)pParam->Offset);
   
    //initaliser premiemiere parametre aÂ  pointer dans le menu
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
    lcd_gotoxy(2,1);
    printf_lcd("Forme");         
    lcd_gotoxy(13,1);
    printf_lcd("%d", pParam->Forme);
    
    //ligne 2
    lcd_gotoxy(2,2);    
    printf_lcd("Freq[Hz]"); 
    lcd_gotoxy(13,2);
    printf_lcd("%d", pParam->Frequence);
    
    //ligne 3
    lcd_gotoxy(2,3);    
    printf_lcd("Ampl[mV]"); 
    lcd_gotoxy(13,3);
    printf_lcd("%d", pParam->Amplitude);
    
    //ligne 4
    lcd_gotoxy(2,4);    
    printf_lcd("Offset[mV]");  
    lcd_gotoxy(13,4);
    printf_lcd("%d", pParam->Offset);
}

// Execution du menu, appel cyclique depuis l'application
void MENU_Execute(S_ParamGen *pParam)
{
   
    //initalisation des variable
    uint8_t static Timer_2Sec = 0;
    uint8_t static MAJ_LCD = 0;
    
    
    //ENREGSTRER DANS LA FLASH//
    
    if (S9.OK == 1)
    {
        //afficher le menu sauvgarde
        Menu_Sauvgarde();
        MAJ_LCD = 1;
        //si le meintiens du bouton S9 >= à  2 sec
        if (Timer_2Sec >= 199)
        {
            //clear LCD
            Clear_LCD();
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
        //mettre à jour l'afficgage si le menu de sauvagrde a été activé
        if (MAJ_LCD == 1)
        {
            //clear LCD
            Clear_LCD();
            //afficher menu principal
            Menu_interface(pParam);
            //remettre les variable à 0
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
                
                //Tester si une touche est active
                if((Pec12.Inc == 1)||(Pec12.Dec == 1)||(Pec12.OK == 1))
                {
                    //incrementer choix du menu
                    if (Pec12.Inc == 1)
                    {
                        //modifier la sÃ©lection du menu
                        SELECTION_MENU = MENU_FREQU;
                    }
                    //decrementer choix du menu
                    else if (Pec12.Dec == 1)
                    {
                        //modifier la sÃ©lection du menu
                        SELECTION_MENU = MENU_OFFSET;
                    }
                    //Valider le choix
                    else if (Pec12.OK == 1)
                    {
                        //modifier la valeur 
                        SELECTION_MENU = MENU_FORME_VALEUR;
                    }
                    //effacer "*"
                    lcd_gotoxy( 1, 1);
                    printf_lcd(" ");
                }

            break;       
            }

            // Menu modifier la Forme de signal //
            case MENU_FORME_VALEUR:
            {
                lcd_gotoxy(1,1);
                printf_lcd("?");
                
                //Tester si une touche est active
                if((Pec12.Inc == 1)||(Pec12.Dec == 1))
                {
                    //Test si incrementer la forme
                    if (Pec12.Inc == 1)
                    {
                        //test si egal aÂ la Singnal carree
                        if(Val.Forme == 3)
                        {
                            Val.Forme = 0;
                        }
                        //sinon incrementer pour obtenir la nouvelle forme
                        else
                        {
                            Val.Forme ++;
                        }  
                    }
                    //decrementer la frome
                    else
                    {
                        //test si egal Signal Sinus
                        if(Val.Forme ==  0)
                        {
                            Val.Forme = 3;
                        }
                        //sinon decrementer pour obtenir la nouvelle forme
                        else
                        {
                            Val.Forme --;
                        }
                    }
                    //supprimer les caractère sur la 2ere ligne
                    lcd_ClearLine(1);
                    //afficher "?Forme"
                    lcd_gotoxy(1,1);
                    printf_lcd("?Forme");
                    //afficher valeur
                    lcd_gotoxy(13,1);
                    printf_lcd("%d", Val.Forme);
                }
                //Tester si une touche est active
                if((Pec12.ESC == 1)||(Pec12.OK == 1))
                {
                    //si on appuye sur ok
                    if (Pec12.OK == 1)
                    {
                        //sauvgarder la nouvelle valeur
                        pParam->Forme = Val.Forme; 
                        //Mettre a jour forme signal
                        GENSIG_UpdateSignal(pParam);
                    }
                    //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire                    
                    else 
                    {
                        //Récuperer la valeur de base
                        Val.Forme = pParam->Forme;
                    }
                    //GESTION AFFICHAGE//
                    //supprimer les caractère sur la 2ere ligne
                    lcd_ClearLine(1);
                    //afficher "*Forme"
                    lcd_gotoxy(1,1);
                    printf_lcd("*Forme"); 
                    //afficher valeur
                    lcd_gotoxy(13,1);
                    printf_lcd("%d", Val.Forme);
                    
                    //retourner sur le menu selection 
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
                //Tester si une touche est active
                if((Pec12.Inc == 1)||(Pec12.Dec == 1)||(Pec12.OK == 1))
                {
                    //incrementer choix du menu
                    if (Pec12.Inc == 1)
                    {  
                        //modifier la sÃ©lection du menu
                        SELECTION_MENU = MENU_AMPLI;
                    }
                    //decrementer choix du menu
                    else if (Pec12.Dec == 1)
                    {
                        //modifier la sÃ©lection du menu
                        SELECTION_MENU = MENU_FORME;
                    }
                    //Valider le choix
                    else if (Pec12.OK == 1)
                    {
                        //modifier la valeur
                        SELECTION_MENU = MENU_FREQU_VALEUR;
                    }
                    //effacer "*"
                    lcd_gotoxy( 1, 2);
                    printf_lcd(" ");
                }
            break;       
            }
            // Menu modifier la frequence du signal //
            case MENU_FREQU_VALEUR:
            {
                //afiicher un "?" sur la 2 eme ligne, la premiere colonne
                lcd_gotoxy(1,2);
                printf_lcd("?");
                

                //Tester si une touche est active
                if((Pec12.Inc == 1)||(Pec12.Dec == 1))
                {
                    if (Pec12.Inc == 1)
                    {
                        //test si superieur ou egal a la frequence max
                        if(Val.Frequence >= 2000 )
                        {
                            Val.Frequence = 2000;                        
                        }
                        //sinon incrementer par pas de 20
                        else
                        {
                            Val.Frequence = Val.Frequence +20;
                        }                        
                    }
                    
                    //decrementer la valeur de la frequence
                    else
                    {
                        //test si inferieur ou Ã©gal aÂ la frequence min
                        if(Val.Frequence <= 20 )
                        {
                            Val.Frequence = 20;
                        }
                        //sinon decrementer par pas de 20
                        else
                        {
                            //recuperer l'ancienne valeur
                            Val.Frequence = Val.Frequence -20;
                        }
                    }
                    //GESTION AFFICHAGE//
                    //supprimer les caractère sur la 2ere ligne
                    lcd_ClearLine(2);
                    //afficher "?Freq[Hz]"
                    lcd_gotoxy(1,2);
                    printf_lcd("?Freq[Hz]");
                    //afficher valeur
                    lcd_gotoxy(13,2);
                    printf_lcd("%d", Val.Frequence);
                }
                //Tester si une touche est active
                if((Pec12.ESC == 1)||(Pec12.OK == 1))
                {
                    //si on appuye sur ok
                    if (Pec12.OK == 1)
                    {
                        //sauvgarder la nouvelle valeur 
                        pParam->Frequence = Val.Frequence;
                        GENSIG_UpdatePeriode(pParam);
                    }
                    //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire
                    else 
                    {
                        Val.Frequence = pParam->Frequence;
                    }
                    //GESTION AFFICHAGE//
                    //supprimer les caractère sur la 2ere ligne
                    lcd_ClearLine(2);
                    //afficher "?Freq[Hz]"
                    lcd_gotoxy(1,2);
                    printf_lcd("*Freq[Hz]"); 
                    //afficher valeur
                    lcd_gotoxy(13,2);
                    printf_lcd("%d", Val.Frequence);
                    //retourner sur le menu selection 
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
                //Tester si une touche est active
                if((Pec12.Inc == 1)||(Pec12.Dec == 1)||(Pec12.OK == 1))
                {
                    //incrementer choix du menu
                    if (Pec12.Inc == 1)
                    {
                        //modifier la sÃ©lection du menu
                        SELECTION_MENU = MENU_OFFSET;
                    }
                    //decrementer choix du menu
                    else if (Pec12.Dec == 1)
                    {
                        //modifier la sÃ©lection du menu
                        SELECTION_MENU = MENU_FREQU;
                    }
                    //Valider le choix
                    else if (Pec12.OK == 1)
                    {  
                        //modifier la valeur
                        SELECTION_MENU = MENU_AMPLI_VALEUR;
                    }
                    //effacer "*"
                    lcd_gotoxy( 1, 3);
                    printf_lcd(" ");
                }
            break;       
            }
            // Menu modifier l'amplitude du signal //
            case MENU_AMPLI_VALEUR:
            {
                //afiicher un "?" sur la 3 eme ligne, 1a 1 ere colonne
                lcd_gotoxy(1,3);
                printf_lcd("?");
               
                //Tester si une touche est active
                if((Pec12.Inc == 1)||(Pec12.Dec == 1))
                {
                    //incrementer la valeur de l'amplitude 
                    if (Pec12.Inc == 1)
                    {
                        //test si superieur ou egal aÂ  l'amplitude max
                        if(Val.Amplitude >= 10000 )
                        {
                            Val.Amplitude = 10000;
                        }
                        //sinon incrementer par pas de 100
                        else
                        {
                            Val.Amplitude = Val.Amplitude +100;
                        } 
                    }
                    //decrementer la valeur de l'amplitude 
                    else
                    {
                        //test si inferieur ou egal eÂ  l'amplitude min
                        if(Val.Amplitude <= 0 )
                        {
                            Val.Amplitude = 0;
                        }
                        //sinon decrementer par pas de 100
                        else
                        {
                            Val.Amplitude = Val.Amplitude -100;
                        }
                    }
                    //GESTION AFFICHAGE//
                    //supprimer les caractère sur la 3ere ligne
                    lcd_ClearLine(3);
                    //afficher "?Ampl[mV]"
                    lcd_gotoxy(1,3);
                    printf_lcd("?Ampl[mV]");
                    //afficher valeur
                    lcd_gotoxy(13,3);
                    printf_lcd("%3d", Val.Amplitude);
                }
                //Tester si une touche est active
                if((Pec12.ESC == 1)||(Pec12.OK == 1))
                {
                    //si on appuye sur ok
                    if (Pec12.OK == 1)
                    {
                        //sauvgarder la nouvelle valeur 
                         pParam->Amplitude = Val.Amplitude;
                         
                        //mettre à jour l'amplitude du signal
                        GENSIG_UpdateSignal(pParam);

                    }
                    //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire                     
                    else 
                    {
                        //Récuperer la valeur de base
                        Val.Amplitude = pParam->Amplitude;
                    }
                    //GESTION AFFICHAGE//
                    //supprimer les caractère sur la 2ere ligne
                    lcd_ClearLine(3);
                    //afficher "*Ampl[mV]"
                    lcd_gotoxy(1,3);
                    printf_lcd("*Ampl[mV]"); 
                    //afficher valeur
                    lcd_gotoxy(13,3);
                    printf_lcd("%d", Val.Amplitude);
                    
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
                
                //Tester si une touche est active
                if((Pec12.Inc == 1)||(Pec12.Dec == 1)||(Pec12.OK == 1))
                {
                    //incrementer choix du menu
                    if (Pec12.Inc == 1)
                    {
                        //modifier la sÃ©lection du menu
                        SELECTION_MENU = MENU_FORME;
                    }
                    //decrementer choix du menu
                    else if (Pec12.Dec == 1)
                    {
                        //modifier la sÃ©lection du menu
                        SELECTION_MENU = MENU_AMPLI;
                    }
                    //Valider le choix
                    else if (Pec12.OK == 1)
                    {
                        //modifier la valeur
                        SELECTION_MENU = MENU_OFFSET_VALEUR;
                    }
                    //effacer "*"
                    lcd_gotoxy( 1, 4);
                    printf_lcd(" ");
                }
                    
            break;       
            }
            // Menu modifier l'offset du signal //
            case MENU_OFFSET_VALEUR:
            {
                //afiicher un "?" sur la 4 eme ligne, 1 ere colonne
                lcd_gotoxy(1,4);
                printf_lcd("?");
                
                //Tester si une touche est active
                if((Pec12.Inc == 1)||(Pec12.Dec == 1))
                {

                    //incrementer la valeur de l'offset 
                    if (Pec12.Inc == 1)
                    {
                        //test si supperieur ou egal e l'offset max
                        if(Val.Offset >= 5000 )
                        {
                            Val.Offset = (5000);
                        }
                        //sinon incrementer par pas de 100
                        else
                        {
                            Val.Offset = (Val.Offset +100);
                        } 
                    }
                    //decrementer la valeur de l'offset
                    else
                    {
                        //test si inferieur ou egal aÂ  l'offset min
                        if(Val.Offset <= -5000 )
                        {
                            Val.Offset = (-5000);
                        }
                        //sinon decrementer par pas de 100
                        else
                        {
                            Val.Offset = (Val.Offset -100);
                        }
                    }
                    //GESTION AFFICHAGE//
                    //supprimer les caractère sur la 4ere ligne
                    lcd_ClearLine(4);
                    //afficher "?Offset[mV]"
                    lcd_gotoxy(1,4);
                    printf_lcd("?Offset[mV]");
                    //afficher valeur
                    lcd_gotoxy(13,4);
                    printf_lcd("%d", Val.Offset);
                }
                if((Pec12.ESC == 1)||(Pec12.OK == 1))
                {
                    //si on appuye sur ok
                    if (Pec12.OK == 1)
                    {

                        //sauvgarder la nouvelle valeur 
                        pParam->Offset = Val.Offset;
                    
                        //mettre à jour l'offset du signal
                        GENSIG_UpdateSignal(pParam);
                    }
                    //si on appuye sur esc, retourne sur affichage principal et garde l'ancienne val en memoire 
                    else 
                    {
                        //Récuperer la valeur de base
                        Val.Offset = pParam->Offset;
                    }
                    //GESTION AFFICHAGE//
                    //supprimer les caractère sur la 4ere ligne
                    lcd_ClearLine(4);
                    //afficher "*Offset[mV]"
                    lcd_gotoxy(1,4);
                    printf_lcd("*Offset[mV]");
                    //afficher valeur
                    lcd_gotoxy(13,4);
                    printf_lcd("%d", Val.Offset);
                    
                    //retourner sur la selection de l'offset
                    SELECTION_MENU = MENU_OFFSET;
                }

            break;       
            }        
        }
    }
    
    Pec12ClearOK();
    Pec12ClearESC();
    Pec12ClearMinus();
    Pec12ClearPlus();
}




