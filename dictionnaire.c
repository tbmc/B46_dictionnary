#include "liste_chainees.h"
#include "arbres.h"
#include "table_hash.h"

#include "dictionnaire.h"

typedef union
{
    Dictionnaire_Liste liste;
    Dictionnaire_arbre arbre;
    Dictionnaire_table table;
}
Union_dictionnaires;

/**
 * @brief The Dictionnaire struct Structure contenant le type du dictionnaire
 * ainsi qu'une adresse vers le dictionnaire, par contre cette structure
 * ne peut contenir qu'une seule adresse à la foie
 */
struct Dictionnaire
{
    Union_dictionnaires dictionnaires;
    DICTIONNARY_TYPE type;
};

Dictionnaire nouveau(DICTIONNARY_TYPE type)
{
    Dictionnaire dico = malloc(sizeof(struct Dictionnaire));
    if(type == LISTE)
    {
        dico->dictionnaires.liste = null;
        dico->type = type;
    }
    else if(type == ARBRE)
    {
        dico->dictionnaires.arbre = null;
        dico->type = type;
    }
    else if(type == TABLE)
    {
        dico->dictionnaires.table = null;
        dico->type = type;
    }
    else
        return null;
    return dico;
}

void desallouer(Dictionnaire dico)
{
    if(dico == null)
        return;
    if(dico->type == LISTE)
        ListeChainee_dictionnaire_free_all(dico->dictionnaires.liste);
    else if(dico->type == ARBRE)
        Arbre_free(dico->dictionnaires.arbre);
    else if(dico->type == TABLE)
        Table_free(dico->dictionnaires.table);
    free(dico);
}

Dictionnaire inserer(Dictionnaire dico, Clef clef, Definition def)
{
    /*
     * Dans un union les variables utilisent le même espace mémoire
     * et des pointeurs ont tous la même taille, on peut donc les utiliser
     * de cette manière
     */
    Union_dictionnaires test;
    Dictionnaire sortie;
    if(!type_dictionnaire_ok(dico))
        return null;
    if(dico->type == LISTE)
        test.liste = ListeChainee_inserer(dico->dictionnaires.liste, clef, def);
    else if(dico->type == ARBRE)
        test.arbre = Arbre_inserer(dico->dictionnaires.arbre, clef, def);
    else if(dico->type == TABLE)
        test.table = Table_inserer(dico->dictionnaires.table, clef, def);
    if(test.liste == null)
        return null;
    sortie = nouveau(dico->type);
    sortie->dictionnaires.liste = test.liste;
    /*
     * Pour éviter les fuites de mémoire vu que l'on retourne le dictionnaire à utiliser
     */
    free(dico);
    return sortie;
}

Dictionnaire inserer_pointeur(Dictionnaire dico, Clef clef, Definition def)
{
    Union_dictionnaires test;
    Dictionnaire sortie;
    if(!type_dictionnaire_ok(dico))
        return null;
    if(dico->type == LISTE)
        test.liste = ListeChainee_inserer_pointeur(dico->dictionnaires.liste, clef, def);
    else if(dico->type == ARBRE)
        test.arbre = Arbre_inserer_pointeur(dico->dictionnaires.arbre, clef, def);
    else if(dico->type == TABLE)
        test.table = Table_inserer_pointeur(dico->dictionnaires.table, clef, def);
    if(test.liste == null)
        return null;
    sortie = nouveau(dico->type);
    sortie->dictionnaires.liste = test.liste;
    free(dico);
    return sortie;
}

Dictionnaire supprimer(Dictionnaire dico, Clef clef)
{
    Union_dictionnaires test;
    Dictionnaire sortie;
    if(!type_dictionnaire_ok(dico))
        return null;
    if(dico->type == LISTE)
        test.liste = ListeChainee_supprimer(dico->dictionnaires.liste, clef);
    else if(dico->type == ARBRE)
        test.arbre = Arbre_supprimer(dico->dictionnaires.arbre, clef);
    else if(dico->type == TABLE)
        test.table = Table_supprimer(dico->dictionnaires.table, clef);
    if(test.liste == null)
        return null;
    sortie = nouveau(dico->type);
    sortie->dictionnaires.liste = test.liste;
    free(dico);
    return sortie;
}

Definition rechercher_definition(Dictionnaire dico, Clef clef)
{
    if(dico->type == LISTE)
        return ListeChainee_rechercher_definition(dico->dictionnaires.liste, clef);
    else if(dico->type == ARBRE)
        return Arbre_rechercher_definition(dico->dictionnaires.arbre, clef);
    else if(dico->type == TABLE)
        return Table_rechercher_definition(dico->dictionnaires.table, clef);
    return null;
}

Dictionnaire rechercher_definition_approximatif(Dictionnaire dico, const Clef debut)
{
    Dictionnaire d = nouveau(dico->type);
    if(dico->type == LISTE)
    {
        d->dictionnaires.liste = ListeChainee_rechercher_approximatif(dico->dictionnaires.liste, debut);
        return d;
    }
    else if(dico->type == ARBRE)
    {
        d->dictionnaires.arbre = Arbre_rechercher_approximatif(dico->dictionnaires.arbre, debut);
        return d;
    }else if(dico->type == TABLE)
    {
        d->dictionnaires.table = Table_rechercher_definition_approximatif(dico->dictionnaires.table, debut);
        return d;
    }
    return null;
}

void afficher(Dictionnaire dico)
{
    if(dico->type == LISTE)
        ListeChainee_dictionnaire_print(dico->dictionnaires.liste);
    else if(dico->type == ARBRE)
        Arbre_print(dico->dictionnaires.arbre);
    else if(dico->type == TABLE)
        Table_print(dico->dictionnaires.table);
    printf("\n");
}

bool type_dictionnaire_ok(Dictionnaire dico)
{
    DICTIONNARY_TYPE type = dico->type;
    if(type == LISTE)
        return true;
    if(type == ARBRE)
        return true;
    if(type == TABLE)
        return true;
    return false;
}































