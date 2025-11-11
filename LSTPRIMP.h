#ifndef LSTPRIMP_H_INCLUDED
#define LSTPRIMP_H_INCLUDED
#include "LSTSDDP.h"
NOEUDP noeudCreerP(ELEMENTP);
void noeudDetruireP(NOEUDP);
LISTEP listeCreerP(void);
void listeDetruireP(LISTEP);
int estVideP(LISTEP);
int estSatureeP(LISTEP);
int listeTailleP(LISTEP);
ELEMENTP recupererP(LISTEP, int);
int insererP(LISTEP, ELEMENTP,int);
int supprimerP(LISTEP, int);
void listeAfficherP(LISTEP);
LISTEP listeCopierP(LISTEP);
int listeComparerP(LISTEP, LISTEP);
#endif // LSTPRIMP_H_INCLUDED
