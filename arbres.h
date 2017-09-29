#ifndef ARBRES_H
#define ARBRES_H

#include "autre.h"

typedef struct Arbre * Dictionnaire_arbre;

/**
 * @brief Arbre_free Libère un arbre entier
 * @param a Arbre à libérer
 */
void Arbre_free(Dictionnaire_arbre a);

/**
 * @brief Arbre_print Affiche tout le contenu d'un arbre
 * @param a Arbre à afficher
 */
void Arbre_print(Dictionnaire_arbre a);

/**
 * @brief Arbre_inserer Insère un nouveau noeud dans l'arbre
 * @param dico Arbre dans lequel insérer le nouveau noeud
 * @param clef Clef du nouveau noeud
 * @param def Définition du nouveau noeud
 * @return Arbre avec le nouveau noeud inséré
 */
Dictionnaire_arbre Arbre_inserer(Dictionnaire_arbre dico, Clef clef, Definition def);

/**
 * @brief Arbre_inserer_pointeur Insère un nouveau noeud dans l'arbre
 * @param dico Arbre dans lequel insérer le nouveau noeud
 * @param clef Clef du nouveau noeud
 * @param def Définition du nouveau noeud
 * @return Arbre avec le nouveau noeud inséré
 *
 * les pointeurs clef et def sont copié mais pas les valeurs vers lesquels ils pointent
 * ils ne faut donc pas les libérer après les avoir passé en paramètre
 *
 */
Dictionnaire_arbre Arbre_inserer_pointeur(Dictionnaire_arbre dico, Clef clef, Definition def);

/**
 * @brief Arbre_supprimer Supprime un noeud dans un arbre
 * @param arbre Arbre dans lequel supprimer le noeud
 * @param clef Clef du noeud à supprimer
 * @return Arbre avec le noeud qui a été supprimé
 */
Dictionnaire_arbre Arbre_supprimer(Dictionnaire_arbre arbre, Clef clef);

/**
 * @brief Arbre_rechercher_definition Recherche une définition dans un arbre
 * @param arbre Arbre dans lequel rechercher la clef
 * @param clef Clef de la définition à trouver
 * @return Définition correspondant à la clef
 */
Definition Arbre_rechercher_definition(Dictionnaire_arbre arbre, Clef clef);

/**
 * @brief Arbre_rechercher_approximatif Recherche tous les termes commençant par début
 * @param arbre Arbre dans lequel rechercher les termes
 * @param debut Clef par lequel doit commencer tous les termes retournés dans le dictionnaire
 * @return Arbre avec tous les noeud avec une définition commençant par début
 */
Dictionnaire_arbre Arbre_rechercher_approximatif(Dictionnaire_arbre arbre, Clef debut);

#endif // ARBRES_H
