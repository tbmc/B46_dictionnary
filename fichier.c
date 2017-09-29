#include <stdlib.h>
#include <string.h>

#include "fichier.h"


Fichier fichier_new(const char * path, const char * mode)
{
    Fichier f = malloc(sizeof(struct Fichier_structure));
    f->f = fopen(path, mode);
    if(f->f == null)
        return null;
    f->buffer = malloc(BUFFER_SIZE);
    return f;
}

void fichier_free(Fichier f)
{
    fclose(f->f);
    free(f->buffer);
    free(f);
}

Paire fichier_read_next_line(Fichier f)
{

    // Lecture d'une ligne du fichier
    char * r = fgets(f->buffer, BUFFER_SIZE, f->f);
    char *first;
    int i, length, lbuffer;
    Paire p = {null, null, false};
    if(f->buffer == null || r == null)
    {
        p.non_null = false;
        return p;
    }
    else
        p.non_null = true;

    lbuffer = (int)strlen(f->buffer);

    // Parsing de la ligne lue
    first = strchr(f->buffer, '|');
    length = (int)(first - f->buffer);

    // Clef
    Clef clef = malloc(length + 1);
    for(i = 0; i < length; i++)
    {
        clef[i] = f->buffer[i];
    }
    clef[length] = '\0';
    p.clef = clef;

    // Définition
    Definition def = malloc(lbuffer - length);
    first++;
    for(i = 0; i < lbuffer - (length + 1); i++)
    {
        def[i] = first[i];
    }
    def[lbuffer - (length + 1)] = '\0';
    p.def = def;

    return p;
}


Dictionnaire fichier_lire_fichier(const char *path, DICTIONNARY_TYPE type_dico)
{
    Fichier f = null;
    Paire p;
    Dictionnaire dico = null;
    if(!(type_dico == LISTE  || type_dico == ARBRE || type_dico == TABLE))
        return null;
    f = fichier_new(path, "r");
    if(f == null)
        return null;
    dico = nouveau(type_dico);
    p = fichier_read_next_line(f);
    while(p.non_null != false)
    {
        dico = inserer_pointeur(dico, p.clef, p.def);
        p = fichier_read_next_line(f);
    }
    fichier_free(f);
    return dico;
}


























