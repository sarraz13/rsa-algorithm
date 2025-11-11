#ifndef LSTPHRASE_H_INCLUDED
#define LSTPHRASE_H_INCLUDED
#include "ELTPRIMP.h"
typedef struct structNoeud1 {
    ELEMENTP info;
    struct structNoeud1 * suivant;
} structNoeud1, * NOEUDP;
typedef struct{
    NOEUDP tete;
    int lg;
}listephrase,*LISTEP;
#endif // LSTPHRASE_H_INCLUDED
