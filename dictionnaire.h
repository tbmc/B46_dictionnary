#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include "autre.h"

// Différents types possibles de Dictionnaire
typedef enum {LISTE, ARBRE, TABLE} DICTIONNARY_TYPE;

typedef struct Dictionnaire * Dictionnaire;

/**
 * @brief nouveau Créer un nouveau dictionnaire
 * @param type Type du dictionnaire à créer
 * @return Le nouveau dictionnaire créé
 */
Dictionnaire nouveau(DICTIONNARY_TYPE type);

/**
 * @brief desallouer Désalloue la mémoire d'un dictionnaire
 * @param dico Dictionnaire à désallouer
 */
void desallouer(Dictionnaire dico);

/**
 * @brief inserer Insère une nouvelle paire (clef, définition)
 * dans le dictionnaire
 * @param dico Dictionnaire dans lequel insérer la paire
 * @param clef Clef de la nouvelle paire
 * @param def Définition de la nouvelle paire
 * @return Dictionnaire contenant la nouvelle paire
 */
Dictionnaire inserer(Dictionnaire dico, Clef clef, Definition def);

/**
 * @brief inserer_pointeur Insère une nouvelle paire (clef, définition)
 * dans le dictionnaire, mais ces paires sont stockées uniquement par
 * copie de pointeur, il ne faut donc pas les désallouer après avoir
 * appelé cette fonction
 * @param dico Dictionnaire dans lequel insérer la nouvelle paire
 * @param clef Clef de la nouvelle paire
 * @param def Définition de la nouvelle paire
 * @return Dictionnaire contenant la nouvelle paire
 */
Dictionnaire inserer_pointeur(Dictionnaire dico, Clef clef, Definition def);

/**
 * @brief supprimer Supprime une paire du dictionnaire
 * @param dico Dictionnaire dans lequel supprimer la paire
 * @param clef Clef de la paire à supprimer
 * @return Dictionnaire avec la nouvelle paire en moins
 */
Dictionnaire supprimer(Dictionnaire dico, Clef clef);

/**
 * @brief rechercher_definition Recherche une définition à partir de sa clef
 * @param dico Dictionnaire dans lequel rechercher la définition
 * @param clef Clef de la définition à rechercher
 * @return Définition correspondante à la clef, NULL si non trouvée
 */
Definition rechercher_definition(Dictionnaire dico, Clef clef);

/**
 * @brief rechercher_definition_approximatif Recherche toutes les clefs commençant
 * par une certaines chaines de caractères
 * @param dico Dictionnaire dans lequel rechercher les définitions
 * @param debut Chaines de caractères par laquelle doivent commencer les clef
 * @return Dictionnaire contenant toutes les paire (clef, définition) dont la clef
 * commence par 'début'
 */
Dictionnaire rechercher_definition_approximatif(Dictionnaire dico, const Clef debut);

/**
 * @brief afficher Affiche un dictionnaire
 * @param dico Dictionnaire à afficher
 */
void afficher(Dictionnaire dico);

/**
 * @brief type_dictionnaire_ok Informe si le type du dictionnaire est valide ou non
 * @param dico Dictionnaire à tester
 * @return un booleen informant si le dictionnaire est valide
 */
bool type_dictionnaire_ok(Dictionnaire dico);













#endif // DICTIONNAIRE_H
