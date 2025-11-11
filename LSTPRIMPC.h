#ifndef LSTPRIMPC_H_INCLUDED
#define LSTPRIMPC_H_INCLUDED
#include "LSTSDDPC.h"
NOEUDpc noeudCreerPC(ELEMENTPC);
void noeudDetruirePC(NOEUDpc);
LISTEPC listeCreerPC(void);
void listeDetruirePC(LISTEPC);
int estVidePC(LISTEPC);
int estSatureePC(LISTEPC);
int listeTaillePC(LISTEPC);
ELEMENTPC recupererPC(LISTEPC, int);
int insererPC(LISTEPC, ELEMENTPC,int);
int supprimerPC(LISTEPC, int);
void listeAfficherPC(LISTEPC);
LISTEPC listeCopierPC(LISTEPC);
int listeComparerPC(LISTEPC, LISTEPC);
#endif // LSTPRIMPC_H_INCLUDED
