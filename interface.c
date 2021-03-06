#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fichier.h"

#include "interface.h"

#define TEMP_SIZE (500)

void espaces()
{
    printf("\n\n\n\n");
}

int scanf_number()
{
    char temp[TEMP_SIZE];
    scanf("%s", temp);
    return atoi(temp);
}

DICTIONNARY_TYPE interface_menu()
{
    int i = 0;
    espaces();
    while(!(0 < i && i < 4))
    {
        printf("Bienvenue!\n\n");
        printf("Voici les différents modes : \n");
        printf("1 : Liste chainée\n2 : Arbre binaire de recherche\n3 : Table de hashage\n");
        printf("4 : Quitter\n");
        printf("Veuilliez choisir un mode : ");
        i = scanf_number();
        if(i == 4)
            exit(EXIT_SUCCESS);
        if(!(0 < i && i <= 3))
        {
            espaces();
            printf("Mauvais choix!\n");
        }
    }
    switch(i)
    {
    case 1:
        return LISTE;
    case 2:
        return ARBRE;
    case 3:
        return TABLE;
    default:
        return LISTE; // impossible, mais on est jamais trop prudent
    }
}

int select_command(char *clef, char *def)
{
    int i = 0;
    while(!(0 < i && i <= 5))
    {
        printf("Liste des commandes : \n");
        printf("1 : insérer\n2 : supprimer\n");
        printf("3 : Rechercher une définition\n");
        printf("4 : Rechercher approximativement une définition\n");
        printf("5 : Quitter\n");

        printf("Choisissez une commande : ");
        i = scanf_number();
        if(!(0 < i && i <= 5))
        {
            printf("Mauvaise commande!\n");
            espaces();
        }
    }
    if(i != 5)
    {
        printf("Entrer la clef : ");
        scanf("%s", clef);
        printf("\n");
    }
    if(i == 1)
    {
        printf("Entrer la définition : ");
        scanf("%s", def);
        printf("\n\n");
    }
    else if(!(2 <= i && i <= 5))
    {
        printf("Mauvaise commande!");
        espaces();
    }

    return i;
}

void lancer_interface()
{
    Dictionnaire dico = null, dico_test;
    DICTIONNARY_TYPE type;
    char clef[TEMP_SIZE], def[TEMP_SIZE];
    Definition out;
    int commande = 0;

    type = interface_menu();
    printf("\nChargement du dictionnaire...\n\n");
    dico = fichier_lire_fichier("DataFiles/B46_wiktionnaire.dat", type);
    while(commande != 5)
    {
        commande = select_command(clef, def);
        switch(commande)
        {
        case 1:
            dico_test = inserer(dico, clef, def);
            if(dico_test != null)
            {
                dico = dico_test;
                printf("Inséré avec succès!\n");
            }
            else
            {
                printf("Erreur dans l'insertion.\n");
            }
            break;
        case 2:
            dico_test = supprimer(dico, clef);
            if(dico_test != null)
            {
                dico = dico_test;
                printf("Supprimé avec succès!\n");
            }
            else
            {
                printf("Erreur!\n");
            }
            break;
        case 3:
            out = rechercher_definition(dico, clef);
            if(out != null)
            {
                printf("Recherche : \n%s\n", out);
            }
            else
            {
                printf("Erreur! Terme non trouvé!\n");
            }
            break;
        case 4:
            dico_test = rechercher_definition_approximatif(dico, clef);
            if(dico_test != null)
            {
                afficher(dico_test);
                desallouer(dico_test);
            }
            else
            {
                printf("Erreur! Debut non trouvé!\n");
            }
            break;
        case 5:
            break;
        default:
            printf("Erreur!\n");
            break;
        }
        if(commande != 5)
        {
            espaces();
        }
    }
    desallouer(dico);
}

























