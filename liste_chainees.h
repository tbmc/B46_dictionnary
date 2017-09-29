#ifndef LISTECHAINEES_H
#define LISTECHAINEES_H

#include "autre.h"

typedef struct ListesChainees * Dictionnaire_Liste;


/**
 * @brief dictionnaire_new Créer un nouveau dictionnaire
 * @param c Clé de la première valeur du dictionnaire
 * @param def Définition de la première valeur du dictionnaire
 * @return Le dictionnaire créé
 *
 * Les valeurs c et def peuvent être NULL
 * dans ce cas là, elles seront définis
 * lors de la première insertion dans
 * le dictionnaire.
 *
 */
Dictionnaire_Liste ListeChainee_dictionnaire_new(const Clef c, const Definition def);

/**
 * @brief dictionnaire_free_all Libère la mémoire de tous les maillons suivant
 * du dictionnaire
 * @param d Dicticnnaire contenant les maillons à libérer
 */
void ListeChainee_dictionnaire_free_all(Dictionnaire_Liste dictionnaire);

/**
 * @brief dictionnaire_print Affiche tous les maillons du dictionnaire avec
 * une paire <clef|définition> par ligne
 * @param d Dictionnaire contenant les maillons à afficher
 */
void ListeChainee_dictionnaire_print(Dictionnaire_Liste dictionnaire);

/**
 * @brief ListeChainee_inserer Insére un nouveau maillon au début du dictionnaire,
 * ce nouveau maillon contient ensuite la paire <c|def>
 * @param dico Dictionnaire dans lequel on ajoute le maillon (au début)
 * @param c Clé à ajouter dans le maillon
 * @param def Définition à ajouter dans le maillon
 * @return Le dictionnaire avec le nouveau maillon
 */
Dictionnaire_Liste ListeChainee_inserer(Dictionnaire_Liste dico, const Clef clef, const Definition def);

/**
 * @brief ListeChainee_inserer_pointeur Insére un nouveau maillon au début du dictionnaire,
 * ce nouveau maillon contient ensuite les pointeurs passés en paramètres
 * @param dico Dictionnaire dans lequel on ajoute le maillon (au début)
 * @param clef Pointeur à ajouter dans le maillon
 * @param def Pointeur à ajouter dans le maillon
 * @return Le dictionnaire avec le nouveau maillon
 */
Dictionnaire_Liste ListeChainee_inserer_pointeur(Dictionnaire_Liste dico, Clef clef, Definition def);

/**
 * @brief ListeChainee_supprimer Supprime un maillon du dictionnaire
 * @param d Dictionnaire dans lequel supprimer le maillon
 * @param c Clef du maillon à supprimer
 * @return Dictionnaire avec le maillon supplémentaire
 */
Dictionnaire_Liste ListeChainee_supprimer(Dictionnaire_Liste dictionnaire, Clef clef);

/**
 * @brief ListeChainee_recherche_definition Recherche la clef dans tous les maillons du
 * dictionnaire
 * @param d Dictionnaire dans lequel rechercher la clef
 * @param c Clef à rechercher dans le dictionnaire
 * @return Définition correspondante à la clef, NULL si clef non trouvée
 */
Definition ListeChainee_rechercher_definition(Dictionnaire_Liste dictionnaire, Clef clef);

/**
 * @brief ListeChainee_recherche_approximatif Recherche dans un dictionnaire, toutes les
 * clés commençant par une chaine de caractère
 * @param d Dictionnaire dans lequel rechercher les clés
 * @param debut Chaine de caractères devant correspondre au début des chaines dans lesquels
 * on recherche
 * @return Dictionnaire contenant uniquement les paires <clef|définition> pour lesquels
 * la clef commence par <debut>
 */
Dictionnaire_Liste ListeChainee_rechercher_approximatif(Dictionnaire_Liste dico, const Clef debut);

/**
 * @brief ListeChainee_get Fonction permettant de récupérer la valeur clef et def
 * d'un maillon d'une liste chainée
 * @param element Element pour lequel on retourne les valeurs
 * @param p Paire contenant les valeurs
 * @return Element suivant dans la liste chainée
 */
Dictionnaire_Liste ListeChainee_get(Dictionnaire_Liste element, Paire *paire);






















#endif // LISTECHAINEES_H
