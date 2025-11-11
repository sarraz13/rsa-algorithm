#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ELTPRIMCL.h"

ELEMENT elementCreer() {
    ELEMENT e = (ELEMENT)malloc(sizeof(cle));
    return e;
}
void elementDetruire(ELEMENT e) {
    free(e);
}
void elementLire(ELEMENT* e) {
    printf("Saisir x : ");
    scanf("%i",&( (*e)->x));
    printf("Saisir y : ");
    scanf("%i",&( (*e)->y));
}

void elementAfficher(ELEMENT e) {
	printf("(%i,%i)\n", e->x,e->y);
}
void elementAffecter(ELEMENT* e1, ELEMENT e2) {
    *e1=e2;
}
void elementCopier(ELEMENT *e1, ELEMENT e2) {
    (*e1)->x=e2->x;
    (*e1)->y=e2->y;
}
int elementComparer(ELEMENT e1, ELEMENT e2) {
	return (e1->x==e2->x && e1->y==e2->y);
}
