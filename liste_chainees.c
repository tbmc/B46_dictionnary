#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "liste_chainees.h"

// Fonctions "private"

/**
 * @brief The ListeChainees struct Structure étant un maillon d'une liste chainée.
 */
struct ListesChainees
{
    Clef clef;
    Definition definition;
    struct ListesChainees * suivant;
};

/**
 * @brief dictionnaire_free Libère la mémoire d'un maillon dictionnaire et uniquement 1
 * @param d Maillon à libérer
 */
void ListeChainee_dictionnaire_free(Dictionnaire_Liste d)
{
    if(d == NULL)
        return;
    clef_free(d->clef);
    definition_free(d->definition);
    free(d);
}




// Fonctions "public"



Dictionnaire_Liste ListeChainee_dictionnaire_new(const Clef c, const Definition def)
{
    Dictionnaire_Liste d = malloc(sizeof(struct ListesChainees));

    if(c == NULL && def == NULL)
    {
        d->clef = NULL;
        d->definition = NULL;
    }
    else
    {
        d->clef = c;
        d->definition =def;
    }
    d->suivant = NULL;
    return d;
}

void ListeChainee_dictionnaire_free_all(Dictionnaire_Liste dictionnaire)
{
    Dictionnaire_Liste temp = dictionnaire, suivant = NULL;
    while(temp != NULL)
    {
        clef_free(temp->clef);
        definition_free(temp->definition);
        suivant = temp->suivant;
        free(temp);
        temp = suivant;
    }
}

void ListeChainee_dictionnaire_print(Dictionnaire_Liste dictionnaire)
{
    Dictionnaire_Liste temp = dictionnaire;
    if(dictionnaire->clef == null || dictionnaire->definition == null)
        return;
    while(temp != NULL)
    {
        printf("%s : %s\n", temp->clef, temp->definition);
        temp = temp->suivant;
    }
    printf("\n");
}

Dictionnaire_Liste ListeChainee_inserer(Dictionnaire_Liste dico, const Clef clef, const Definition def)
{
    return ListeChainee_inserer_pointeur(dico, clef_new(clef), definition_new(def));
}

Dictionnaire_Liste ListeChainee_inserer_pointeur(Dictionnaire_Liste dico, Clef clef, Definition def)
{
    Dictionnaire_Liste d = ListeChainee_dictionnaire_new(clef, def);
    if(dico == null)
        return d;
    if(dico->clef == NULL || dico->definition == NULL)
    {
        ListeChainee_dictionnaire_free(dico);
        return d;
    }
    d->suivant = dico;
    return d;
}

Dictionnaire_Liste ListeChainee_supprimer(Dictionnaire_Liste dictionnaire, Clef clef)
{
    Dictionnaire_Liste temp = dictionnaire, a = NULL, b = NULL;
    int v = 1;
    if(dictionnaire == NULL)
        return NULL;
    if(dictionnaire->suivant == NULL && strcmp(temp->clef, clef) == 0)
    {
        ListeChainee_dictionnaire_free(dictionnaire);
        return NULL;
    }
    while(temp != NULL && v != 0)
    {
        v = strcmp(temp->clef, clef);
        b = a;
        a = temp;
        temp = temp->suivant;
    }
    if(v != 0)
    {
        return NULL;
    }
    if(b == NULL)
    {
        ListeChainee_dictionnaire_free(a);
        return temp;
    }
    b->suivant = temp;
    ListeChainee_dictionnaire_free(a);

    return dictionnaire;
}

Definition ListeChainee_rechercher_definition(Dictionnaire_Liste dictionnaire, Clef clef)
{
    Dictionnaire_Liste temp = dictionnaire, a = NULL;
    int v = 1;
    if(dictionnaire == NULL)
        return NULL;

    while(temp != NULL && v != 0)
    {
        v = strcmp(temp->clef, clef);
        a = temp;
        temp = temp->suivant;
    }
    if(v != 0)
        return NULL;
    if(a == NULL)
        return NULL; // On sait jamais, mieux vaut trop que pas assez
    return a->definition;
}

Dictionnaire_Liste ListeChainee_rechercher_approximatif(Dictionnaire_Liste dico, const Clef debut)
{
    Dictionnaire_Liste sortie, temp;

    if(dico == null || dico->clef == null || dico->definition == null)
        return null;

    sortie = ListeChainee_dictionnaire_new(null, null);
    temp = dico;
    while(temp != NULL)
    {
        if(strstr(temp->clef, debut) == temp->clef)
            sortie = ListeChainee_inserer(sortie, temp->clef, temp->definition);
        temp = temp->suivant;
    }
    return sortie;
}

Dictionnaire_Liste ListeChainee_get(Dictionnaire_Liste element, Paire *paire)
{
    if(element == null)
    {
        paire->clef = null;
        paire->def = null;
        return null;
    }
    paire->clef = element->clef;
    paire->def = element->definition;
    return element->suivant;
}





































