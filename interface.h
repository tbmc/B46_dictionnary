#ifndef INTERFACE_H
#define INTERFACE_H

#include "dictionnaire.h"

/**
 * @brief espaces Permet d'afficher des espaces
 */
void espaces();

/**
 * @brief scanf_number Récupère un nombre
 * @return Nombre entré par l'utilisateur
 */
int scanf_number();

/**
 * @brief interface_menu Demande à l'utilisateur de choisir le type
 * de dictionnaire qu'il veut utiliser
 * @return Type de dictionnaire
 */
DICTIONNARY_TYPE interface_menu();

/**
 * @brief select_command Demande à l'utilisateur de choisir la commande à utiliser
 * @param clef Clef entrée par l'utilisateur quand c'est nécessaire
 * @param def Définition entrée par l'utilisateur quand c'est nécessaire
 * @return Nombre correspondant à la commande à utiliser
 */
int select_command(char *clef, char *def);

/**
 * @brief lancer_interface Lance l'interface
 */
void lancer_interface();







#endif // INTERFACE_H
