#ifndef LSTPCHIF_H_INCLUDED
#define LSTPCHIF_H_INCLUDED
#include "ELTPRIMPC.h"
typedef struct structNoeud2 {
    ELEMENTPC info;
    struct structNoeud2 * suivant;
} structNoeud2, *NOEUDpc ;
typedef struct{
    NOEUDpc tete;
    int lg;
}listephrasechif,*LISTEPC;
#endif // LSTPCHIF_H_INCLUDED
