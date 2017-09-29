#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table_hash.h"

// Table du tableau de la table de hashage
#define HASH_TABLE_SIZE (50000)

// Fonctions "private"

/**
 * @brief Table_hash Retourne le hash de str
 * @param str chaine de caractères à hasher
 * @param size_str taille de la chaine str
 * @return hash de la chaine str
 */
uInt Table_hash(const char *str, int size_str)
{
    int i, s = 0;
    for(i = 0; i < size_str; i++)
        s += (unsigned char)str[i];
    return s % HASH_TABLE_SIZE;
}

Dictionnaire_table Table_new()
{
    Dictionnaire_table dico = malloc(sizeof(Dictionnaire_Liste) * HASH_TABLE_SIZE);
    int i;
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        dico[i] = (Dictionnaire_Liste)ListeChainee_dictionnaire_new(null, null);
    }
    return dico;
}


// Fonctions "public"

void Table_free(Dictionnaire_table dico)
{
    int i;
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        ListeChainee_dictionnaire_free_all(dico[i]);
    }
    free(dico);
}

void Table_print(Dictionnaire_table table)
{
    int i;
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        ListeChainee_dictionnaire_print(table[i]);
    }
    printf("\n");
}

Dictionnaire_table Table_inserer_pointeur(Dictionnaire_table dico, Clef clef, Definition def)
{
    int size_clef;
    uInt hash;

    if(clef == null || def == null)
        return dico;

    size_clef = (int)strlen(clef);
    hash = Table_hash(clef, size_clef);

    if(dico == null)
        dico = Table_new();
    dico[hash] = ListeChainee_inserer_pointeur(dico[hash], clef, def);
    return dico;
}

Dictionnaire_table Table_inserer(Dictionnaire_table dico, Clef clef, Definition def)
{
    return Table_inserer_pointeur(dico, clef_new(clef), definition_new(def));
}

Dictionnaire_table Table_supprimer(Dictionnaire_table dico, Clef clef)
{
    int size_clef = (int)strlen(clef);
    Dictionnaire_Liste sortie;
    uInt hash = Table_hash(clef, size_clef);
    sortie = ListeChainee_supprimer(dico[hash], clef);
    if(sortie == null)
        return null;
    dico[hash] = sortie;
    return dico;
}

Definition Table_rechercher_definition(Dictionnaire_table table, Clef clef)
{
    int size_clef = (int)strlen(clef);
    uInt hash = Table_hash(clef, size_clef);
    return ListeChainee_rechercher_definition(table[hash], clef);
}

Dictionnaire_table Table_rechercher_definition_approximatif(Dictionnaire_table table, Clef debut)
{
    int i;
    Dictionnaire_Liste temp, SUPPRIMEZ_MOI;
    Dictionnaire_table sortie = null;
    Paire p;
    for(i = 0; i < HASH_TABLE_SIZE; i++)
    {
        temp = ListeChainee_rechercher_approximatif(table[i], debut);
        SUPPRIMEZ_MOI = temp;
        while(temp != null)
        {
            temp = ListeChainee_get(temp, &p);
            sortie = Table_inserer(sortie, p.clef, p.def);
        }
        ListeChainee_dictionnaire_free_all(SUPPRIMEZ_MOI);
    }
    return sortie;
}





























