#include "autre.h"

Clef clef_new(const char * value)
{
    Clef clef;
    if(value == null)
        return null;
    clef = malloc(strlen(value)+1);
    strcpy(clef, value);
    return clef;
}

Definition definition_new(const char * value)
{
    Definition def;
    if(value == null)
        return null;
    def = malloc(strlen(value)+1);
    strcpy(def, value);
    return def;
}


void clef_free(Clef c)
{
    if(c != null)
        free(c);
}

void definition_free(Definition d)
{
    if(d != null)
        free(d);
}

void println(const char *s, const char *s2)
{
    if(s == null)
        printf("NULL\n");
    else
        printf("%s | %s\n", s, s2);
}





















