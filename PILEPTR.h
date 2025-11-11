#ifndef PILEPTR_H_INCLUDED
#define PILEPTR_H_INCLUDED
#include "ELTPRIMCL.h"
typedef struct structNoeud {
    ELEMENT info;
    struct structNoeud * suivant;
} structNoeud, * NOEUD;

typedef struct {
    NOEUD tete; /* Sommet de la pile */
} laStruct,*Pile;
#endif // PILEPTR_H_INCLUDED
