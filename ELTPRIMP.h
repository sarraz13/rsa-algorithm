#ifndef ELTPRIMP_H_INCLUDED
#define ELTPRIMP_H_INCLUDED
#include "ELTSDDP.h"
ELEMENTP elementCreerP(void);
void elementDetruireP(ELEMENTP);
void elementLireP(ELEMENTP*);
void elementAfficherP(ELEMENTP);
void elementAffecterP(ELEMENTP* , ELEMENTP );
void elementCopierP(ELEMENTP *, ELEMENTP );
int elementComparerP(ELEMENTP , ELEMENTP );
#endif // ELTPRIMP_H_INCLUDED
