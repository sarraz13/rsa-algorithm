#ifndef ELTPRIMPC_H_INCLUDED
#define ELTPRIMPC_H_INCLUDED
#include "ELTSDDPC.h"
ELEMENTPC elementCreerPC(void);
void elementDetruirePC(ELEMENTPC);
void elementLirePC(ELEMENTPC*);
void elementAfficherPC(ELEMENTPC);
void elementAffecterPC(ELEMENTPC* , ELEMENTPC );
void elementCopierPC(ELEMENTPC *, ELEMENTPC );
int elementComparerPC(ELEMENTPC , ELEMENTPC );
#endif // ELTPRIMPC_H_INCLUDED
