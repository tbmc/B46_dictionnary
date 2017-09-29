#ifndef FICHIER_H
#define FICHIER_H

#include <stdio.h>

#include "autre.h"
#include "dictionnaire.h"

/**
 * @brief The Fichier_structure struct Structure contenant une structure FILE
 * ainsi qu'une chaine de caractère qui va servir de tampon à la lecture du fichier
 * la stocker dans la structure permet de ne pas la réallouer à chaque appel de la
 * fonction
 */
struct Fichier_structure
{
    FILE * f;
    char * buffer;
};
typedef struct Fichier_structure * Fichier;


/**
 * @brief file_new Ouvre un fichier et initialise le buffer
 * @param path Chemin du fichier
 * @param mode Mode d'ouverture (les mêmes que fopen de stdio.h)
 * @return Une structure contenant le buffer initialisé et le fichier
 */
Fichier fichier_new(const char * path, const char * mode);

/**
 * @brief file_free Ferme le fichier et désalloue le buffer
 * @param f Structure à désallouer
 */
void fichier_free(Fichier f);

/**
 * @brief file_read_next_line Lie la ligne suivant du dictionnaire
 * @param f Fichier à lire
 * @return Paire contenant le terme à définir et la définition
 */
Paire fichier_read_next_line(Fichier f);

Dictionnaire fichier_lire_fichier(const char * path, DICTIONNARY_TYPE type_dico);



#endif // FICHIER_H
