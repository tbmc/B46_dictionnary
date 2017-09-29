#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arbres.h"

// Fonctions "private"

/**
 * @brief The Arbre struct Structure représentant un maillon d'un arbre
 */
struct Arbre
{
    /**
     * @brief clef Clef correspondant à la définition
     */
    Clef clef;

    /**
     * @brief def Définition correspondant à la clef
     */
    Definition def;

    /**
     * @brief fg Pointeur vers le fils gauche
     */
    struct Arbre *fg;

    /**
     * @brief fd Pointeur vers le fils droit
     */
    struct Arbre *fd;

    /**
     * @brief parent Pointeur vers le parent.
     * Ce pointeur n'est plus nécessaire depuis que l'on a refait la fonction supprimer
     */
    //struct Arbre *parent;
};

/**
 * @brief Arbre_noeud_plus_droite Trouve le noeud le plus à droite dans l'arbre
 * @param arbre Noeud à partir duquel chercher le noeud le plus à droite
 * @return Un pointeur vers le noeud le plus à droite, null si non trouvé
 *
 * Plus nécessaire depuis que l'on a refait la fonction supprimer
 *
 */
Dictionnaire_arbre Arbre_noeud_plus_droite(Dictionnaire_arbre arbre)
{
    if(arbre == null)
        return null;
    if(arbre->fd != null)
        return Arbre_noeud_plus_droite(arbre->fd);
    return arbre;
}

/**
 * @brief Arbre_parent_plus_droite Trouve le noeud le plus à droite et renvoie son parent
 * @param parent Parent du noeud arbre passé en paramètre
 * @param arbre arbre dans lequel chercher le fils le plus à droite
 * @return Parent du noeud le plus à droite de l'arbre
 */
Dictionnaire_arbre Arbre_parent_plus_droite(Dictionnaire_arbre parent, Dictionnaire_arbre arbre)
{
    if(arbre == null)
        return null;
    if(arbre->fd != null)
        return Arbre_parent_plus_droite(arbre, arbre->fd);
    return parent;
}

/**
 * @brief Arbre_noeud_clef Trouve un noeud à partir de sa clé
 * @param racine Noeud à partir duquel on va chercher le noeud
 * @param clef Clef à rechercher dans les noeux
 * @return Un pointeur vers le noeud correspondant à clef, null si non trouvé
 */
Dictionnaire_arbre Arbre_noeud_clef(Dictionnaire_arbre racine, const Clef clef)
{
    Dictionnaire_arbre a, b;
    if(racine == null)
        return null;
    if(strcmp(racine->clef, clef) == 0)
        return racine;
    a = Arbre_noeud_clef(racine->fg, clef);
    b = Arbre_noeud_clef(racine->fd, clef);
    if(a == null && b == null)
        return null;
    return a == null ? b : a;
}

/**
 * @brief Arbre_add_debut Ajoute tous les noeuds commençant par début à la liste de sortie
 * @param arbre Arbre dans lequel chercher
 * @param sortie Arbre de sortie dans lequel on vont être stockés les noeuds trouvés
 * @param debut Clef à trouver dans l'arbre d'entré
 */
void Arbre_add_debut(Dictionnaire_arbre arbre, Dictionnaire_arbre sortie, Clef debut)
{
    if(arbre == null)
        return;
    if(strstr(arbre->clef, debut) == arbre->clef)
        sortie = Arbre_inserer(sortie, arbre->clef, arbre->def);
    //cmp = strcmp(arbre->clef, debut);
    Arbre_add_debut(arbre->fg, sortie, debut);
    Arbre_add_debut(arbre->fd, sortie, debut);
}

/**
 * @brief Arbre_new Alloue un nouvel arbre et initialise ses champs
 * @param parent Parent du nouvel arbre
 * @param clef Clef du nouvel arbre
 * @param def Définition du nouvel arbre
 * @return Un pointeur sur le nouvel arbre
 */
Dictionnaire_arbre Arbre_new(Clef clef, Definition def)
{
    Dictionnaire_arbre arbre = malloc(sizeof(struct Arbre));
    arbre->fg = null;
    arbre->fd = null;
    /**
     * Plus nécessaire
     */
    //arbre->parent = parent;
    arbre->clef = clef;
    arbre->def = def;
    return arbre;
}

/**
 * @brief Arbre_free_noeud Libère la mémoire d'un noeud
 * @param arbre Noeud à désallouer
 */
void Arbre_free_noeud(Dictionnaire_arbre arbre)
{
    if(arbre == null)
        return;
    arbre->fg = null;
    arbre->fd = null;
    /**
     * Plus nécessaire
     */
    //arbre->parent = null;
    clef_free(arbre->clef);
    definition_free(arbre->def);
    free(arbre);
}


// Fonctions "public"

void Arbre_free(Dictionnaire_arbre a)
{
    if(a == null)
        return;
    //printf("free : %s\n", a->clef);
    clef_free(a->clef);
    definition_free(a->def);
    Arbre_free(a->fd);
    Arbre_free(a->fg);
    free(a);
}

void Arbre_print(Dictionnaire_arbre a)
{
    if(a == null)
        return;
    printf("%s | %s\n", a->clef, a->def);
    Arbre_print(a->fg);
    Arbre_print(a->fd);
}

Dictionnaire_arbre Arbre_inserer_pointeur(Dictionnaire_arbre dico, Clef clef, Definition def)
{
    int cmp;
    if(dico == null)
        return Arbre_new(clef, def);
    if(dico->clef == null || dico->def == null)
    {
        dico->clef = clef;
        dico->def = def;
        return dico;
    }
    cmp = strcmp(dico->clef, clef);
    if(cmp == 0)
        return null;
    if(cmp > 0)
    {
        if(dico->fg == null)
            dico->fg = Arbre_new(clef, def);
        else
            Arbre_inserer_pointeur(dico->fg, clef, def);
    }
    else
    {
        if(dico->fd == null)
            dico->fd = Arbre_new(clef, def);
        else
            Arbre_inserer_pointeur(dico->fd, clef, def);
    }
    return dico;
}

Dictionnaire_arbre Arbre_inserer(Dictionnaire_arbre dico, Clef clef, Definition def)
{
    return Arbre_inserer_pointeur(dico, clef_new(clef), definition_new(def));
}

/**
 * Ceci est l'ancienne implémentation de la fonction supprimer
 * que vous aviez testé.
 * On l'a refaite pour qu'il ne soit plus nécessaire d'avoir
 * un pointeur vers le parent dans la structure Arbre.
 *
 */
/*
Dictionnaire_arbre Arbre_supprimer(Dictionnaire_arbre arbre, Clef clef)
{
    Dictionnaire_arbre temp = null, fils_droite = null;
    if(arbre == null)
        return null;
    if(strcmp(arbre->clef, clef) == 0)
    {
        if(arbre->fd == null)
        {
            temp = arbre->fg;
            Arbre_free_noeud(arbre);
            return temp;
        }
        else if(arbre->fg == null)
        {
            temp = arbre->fd;
            Arbre_free_noeud(arbre);
            return temp;
        }
        else
        {
            fils_droite = Arbre_noeud_plus_droite(arbre->fg);
            if(fils_droite == arbre->fg)
            {
                fils_droite->fd = arbre->fd;
                Arbre_free_noeud(arbre);
                return fils_droite;
            }
            else
            {
                fils_droite->parent->fd = fils_droite->fg;
                fils_droite->fg = arbre->fg;
                fils_droite->fd = arbre->fd;

                Arbre_free_noeud(arbre);
                return fils_droite;
            }
        }
        return temp;
    }
    arbre->fg = Arbre_supprimer(arbre->fg, clef);
    arbre->fd = Arbre_supprimer(arbre->fd, clef);
    return arbre;
}
*/

Dictionnaire_arbre Arbre_supprimer(Dictionnaire_arbre arbre, Clef clef)
{
    Dictionnaire_arbre temp, fils_droite, parent;
    if(arbre == null)
        return null;
    if(strcmp(arbre->clef, clef) == 0)
    {
        if(arbre->fd == null)
        {
            temp = arbre->fg;
            Arbre_free_noeud(arbre);
            return temp;
        }
        else if(arbre->fg == null)
        {
            temp = arbre->fd;
            Arbre_free_noeud(arbre);
            return temp;
        }
        else
        {
            parent = Arbre_parent_plus_droite(arbre, arbre->fg);
            fils_droite = parent->fd;
            if(fils_droite == arbre->fg)
            {
                fils_droite->fd = arbre->fd;
                Arbre_free_noeud(arbre);
                return fils_droite;
            }
            else
            {
                parent->fd = fils_droite->fg;
                fils_droite->fg = arbre->fg;
                fils_droite->fd = arbre->fd;

                Arbre_free_noeud(arbre);
                return fils_droite;
            }
        }
        return temp;
    }
    arbre->fg = Arbre_supprimer(arbre->fg, clef);
    arbre->fd = Arbre_supprimer(arbre->fd, clef);
    return arbre;
}

Definition Arbre_rechercher_definition(Dictionnaire_arbre arbre, Clef clef)
{
    Dictionnaire_arbre a = Arbre_noeud_clef(arbre, clef);
    if(a == null)
        return null;
    return a->def;
}

Dictionnaire_arbre Arbre_rechercher_approximatif(Dictionnaire_arbre arbre, Clef debut)
{
    Dictionnaire_arbre sortie = Arbre_new(null, null);
    Arbre_add_debut(arbre, sortie, debut);
    return sortie;
}





























