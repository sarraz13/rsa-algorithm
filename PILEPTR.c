#include <stdlib.h>
#include <stdio.h>
#include "PILEPRIM.h"
NOEUD NoeudCreer(ELEMENT e) {
    NOEUD n;
    n = (NOEUD) malloc(sizeof(structNoeud));
    if(!n)
        printf ("\n Plus d'espace");
    else {
        elementAffecter(&n->info, e);
        n->suivant = NULL;
    }
    return n;
}
void NoeudDetruire(NOEUD n){
    elementDetruire(n->info);
    free(n);
}
Pile PileCreer(void) {
    Pile P;
    P = (Pile) malloc(sizeof(laStruct));
    if(!P)
        printf(" \nProblème de mémoire") ;
    else
        P->tete = NULL;
    return(P);
}
void PileDetruire(Pile P){
    NOEUD n = P->tete;
    while (n!= NULL){
        P->tete=n->suivant;
        NoeudDetruire(n);
        n = P->tete;
    }
    free(P);
}
int EstVide(Pile P) {
    return (P->tete == NULL);
}
int EstSaturee(Pile P) {
    NOEUD temp;
    int saturee = 1; /* on suppose mémoire saturée */
    temp = (NOEUD) malloc ( sizeof ( structNoeud ) );
    if(temp != NULL) {
        saturee = 0; /* mémoire non saturée */
        free(temp);
    }
    return saturee;
}
int PileTaille(Pile P) {
    int taille = 0;
    NOEUD n;
    n = P->tete;
    while (n != NULL) {
        taille++;
        n = n->suivant ;
    }
    return(taille);
}
ELEMENT Sommet(Pile P) {
    ELEMENT elt= elementCreer();
    if (EstVide(P))
        printf (" \n Pile vide");
    else
        elt=(P->tete)->info;
    return(elt);
}
int Empiler (Pile P, ELEMENT e) {
    int succes=1;
    NOEUD n;
    if (EstSaturee(P)){
        printf ("\n Pile saturée");
        succes=0;
    }
    else{
        n=NoeudCreer(e);
        n->suivant = P->tete;
        P->tete = n;
    }
    return(succes);
}
ELEMENT Depiler (Pile P) {
    ELEMENT elt;
    NOEUD n;
    if (EstVide(P)) {
        printf ("\n Pile vide");
        elt= elementCreer();
    }
    else {
        n = P->tete;
        elementCopier(&elt, n ->info);
        P->tete= n->suivant;
        NoeudDetruire(n);
    }
    return (elt);
}
void PileAfficher(Pile P) {
    NOEUD n;
    n= P->tete;
    while (n != NULL){
        elementAfficher(n->info);
        n = n->suivant;
    }
}
Pile PileCopier(Pile P){
    Pile PR = PileCreer();
    ELEMENT elt;
    NOEUD n1, n2, n3;
    n1 = P->tete;
    while (n1 != NULL) {
        elt=elementCreer();
        elementCopier(&elt, n1->info);
        n2 = NoeudCreer(elt);
        if (n1 == P->tete){
            PR->tete = n2;
            n3 = n2;
        }
        else{
            n3->suivant = n2;
            n3 = n2;
        }
        n1 = n1->suivant;
    }
    return PR;
}
int PileComparer (Pile P1, Pile P2 ){
    int test= 1;
    NOEUD n1 = P1->tete;
    NOEUD n2 = P2->tete;
    if (PileTaille(P1) != PileTaille(P2))
        test= 0;
    while ((n1!=NULL) && (test)) {
        if (elementComparer(n1->info, n2->info)!=0)
            test=0;
        else{
            n1 = n1->suivant;
            n2 = n2->suivant;
        }
    }
    return test;
}
