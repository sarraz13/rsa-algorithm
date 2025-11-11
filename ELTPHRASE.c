#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ELTPRIMP.h"

ELEMENTP elementCreerP() {
    ELEMENTP e = (ELEMENTP)malloc(sizeof(phrase));
    return e;
}
void elementDetruireP(ELEMENTP e) {
    free(e);
}
void elementLireP(ELEMENTP* e) {
    printf("Saisir la phrase : ");
    gets((*e)->phrase);
}

void elementAfficherP(ELEMENTP e) {
	printf("%s\n", e->phrase);
}
void elementAffecterP(ELEMENTP* e1, ELEMENTP e2) {
    *e1=e2;
}
void elementCopierP(ELEMENTP *e1, ELEMENTP e2) {
	strcpy((*e1)->phrase,e2->phrase);
}
int elementComparerP(ELEMENTP e1, ELEMENTP e2) {
	return (strcmp(e1->phrase, e2->phrase)==0);
}
