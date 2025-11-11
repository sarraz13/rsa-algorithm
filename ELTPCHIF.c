#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ELTPRIMPC.h"

ELEMENTPC elementCreerPC() {
    ELEMENTPC e = (ELEMENTPC)malloc(sizeof(phrasechif));

    return e;
}
void elementDetruirePC(ELEMENTPC e) {
    free(e);
}
void elementLirePC(ELEMENTPC* e) {
    printf("Saisir la phrase chiffree : ");
    gets((*e)->phrase);
}

void elementAfficherPC(ELEMENTPC e) {
	printf("%s\n", e->phrase);
}
void elementAffecterPC(ELEMENTPC* e1, ELEMENTPC e2) {
    *e1=e2;
}
void elementCopierPC(ELEMENTPC *e1, ELEMENTPC e2) {
	strcpy((*e1)->phrase,e2->phrase);
}
int elementComparerPC(ELEMENTPC e1, ELEMENTPC e2) {
	return (strcmp(e1->phrase, e2->phrase)==0);
}
