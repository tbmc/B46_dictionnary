#ifndef TABLE_HASH_H
#define TABLE_HASH_H

#include "autre.h"
#include "liste_chainees.h"

/**
 * @brief Dictionnaire_table Une table de hashage, n'est ici rien
 * d'autre qu'un tableau de ListesChainees
 */
typedef Dictionnaire_Liste * Dictionnaire_table;

/**
 * @brief uInt inutile, mais plus court à écrire
 */
typedef unsigned int uInt;

/**
 * @brief Table_free Permet de désallouer une table de hashage
 * @param dico Table à désallouer
 */
void Table_free(Dictionnaire_table dico);

/**
 * @brief Table_print Affiche une table de hashage
 * @param table Table à afficher
 */
void Table_print(Dictionnaire_table table);

/**
 * @brief Table_inserer_pointeur Insère une nouvelle paire (clef, définition)
 * dans la table de hashage, mais ces paires sont stockées uniquement par
 * copie de pointeur, il ne faut donc pas les désallouer après avoir
 * appelé cette fonction
 * @param dico Table dans laquelle insérer la nouvelle paire
 * @param clef Clef de la nouvelle paire
 * @param def Définition de la nouvelle paire
 * @return Table contenant la nouvelle paire
 */
Dictionnaire_table Table_inserer_pointeur(Dictionnaire_table dico, Clef clef, Definition def);

/**
 * @brief Table_inserer Insère une nouvelle paire (clef, définition)
 * dans la table de hashage
 * @param dico Table dans laquelle insérer la nouvelle paire
 * @param clef Clef de la nouvelle paire
 * @param def Définition de la nouvelle paire
 * @return Table contenant la nouvelle paire
 */
Dictionnaire_table Table_inserer(Dictionnaire_table dico, Clef clef, Definition def);

/**
 * @brief Table_supprimer Supprime une paire de la table de hashage
 * @param dico Table dans laquelle supprimer la paire
 * @param clef Clef de la paire à supprimer
 * @return Table dans laquelle la paire a été supprimée
 */
Dictionnaire_table Table_supprimer(Dictionnaire_table dico, Clef clef);

/**
 * @brief Table_rechercher_definition Recherche une définition à partir de sa clef
 * @param table Table dans laquelle rechercher la définition
 * @param clef Clef de la définition à rechercher
 * @return Définition correspondante à la clef, NULL si non trouvée
 */
Definition Table_rechercher_definition(Dictionnaire_table table, Clef clef);

/**
 * @brief Table_rechercher_definition_approximatif Recherche toutes les paires
 * dans lesquelles la clef commence par une certaine chaine de caractères
 * @param table Table dans laquelle rechercher les paires
 * @param debut Chaines de caractères par laquelle doivent commencer les clefs
 * @return Nouvelle table de hashage contenant toutes les paires commençant par 'debut'
 */
Dictionnaire_table Table_rechercher_definition_approximatif(Dictionnaire_table table, Clef debut);










#endif // TABLE_HASH_H
