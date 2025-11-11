#ifndef ELTPRIMCL_H_INCLUDED
#define ELTPRIMCL_H_INCLUDED
#include "ELTSDDCL.h"
ELEMENT elementCreer(void) ;
void elementLire(ELEMENT*);
void elementDetruire (ELEMENT);
void elementAfficher(ELEMENT);
void elementAffecter(ELEMENT*, ELEMENT);
void elementCopier(ELEMENT *, ELEMENT) ;
int elementComparer(ELEMENT, ELEMENT);
#endif // ELTPRIMCL_H_INCLUDED
