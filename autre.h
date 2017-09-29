#ifndef AUTRE_H
#define AUTRE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0
#define null NULL

#define BUFFER_SIZE (10000)

/**
 * @brief Clef
 */
typedef char * Clef;

/**
 * @brief Definition
 */
typedef char * Definition;

/**
 * @brief clef_new Créer une nouvelle clé
 * @param value Valeur de la nouvelle clé
 * @return Clé créée
 */
Clef clef_new(const char *value);

/**
 * @brief clef_free Libère la mémoire d'une clé
 * @param c clef à libérer
 */
void clef_free(Clef c);

/**
 * @brief definition_new Créer une nouvelle définition
 * @param value Valeur de la nouvelle définition
 * @return La nouvelle définition
 */
Definition definition_new(const char * value);

/**
 * @brief definition_free Libère la mémoire d'une définition
 * @param d Définition à libérer
 */
void definition_free(Definition d);

/**
 * @brief Structure contenant une clef et une définition
 * Cette structure est utilisée uniquement pour retourner
 * deux variables au lieu d'une seule
 *
 */
typedef struct
{
    Clef clef;
    Definition def;
    bool non_null;
}
Paire;

/**
 * @brief println affiche deux chaines, séparées par un pipe
 * utile uniquement pour le debug
 * @param s
 * @param s2
 */
void println(const char *s, const char *s2);


#endif // AUTRE_H
