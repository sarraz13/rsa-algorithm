#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LSTPRIMP.h"
NOEUDP noeudCreerP(ELEMENTP e){
    NOEUDP n;
    n =(NOEUDP)malloc(sizeof(structNoeud1));
    if(!n){
        printf ("\nPlus d'espace");
    }
    else{
        elementAffecterP(&n->info, e);
        n->suivant = NULL;
    }
    return n;
}
void noeudDetruireP(NOEUDP n){
    elementDetruireP(n->info);
    free(n);
}
LISTEP listeCreerP(void) {
    LISTEP L;
    L=(LISTEP)malloc(sizeof(listephrase));
    if (! L)
        printf("\nProblème de mémoire");
    else {
        L->lg = 0;
        L->tete = NULL; /* initialiser la tête */
    }
    return(L);
}
void listeDetruireP(LISTEP L){
    int i;
    NOEUDP p, q;
    q= L->tete;
    for(i = 1;i <= L->lg; i++) {
        p=q;
        q=q->suivant;
        noeudDetruireP(p);
    }
    free(L);
}
int insererP (LISTEP L, ELEMENTP e, int pos){
    int succee=1;
    int i;
    NOEUDP n, p, q; // c des pointeurs sur noeud c equivalent à:
    // structNoeud * n
    if (estSatureeP(L)){
        printf ("\nListe saturée");
        succee=0;
    }
    else {
        if ((pos < 1) || (pos > L->lg + 1)) {
            printf ("\nPosition invalide");
            succee=0;
        }
        else {
            n=noeudCreerP (e);
            /*on est sûr que la réservation va se faire car la mémoire n'est pas saturée*/
            if (pos == 1) /*insertion en tête de liste*/{
                n->suivant=L->tete;
                L->tete = n;
            }
        else{
            q= L->tete;
            for (i=1; i<pos; i++) {
                p = q;
                q = q->suivant;
            }
            // q désigne l’élément de rang pos et p son prédécesseur
            p->suivant=n;
            n->suivant=q;
        }
        (L->lg)++;
        }
    }
    return succee;
}
int supprimerP (LISTEP L, int pos ){
    int i;
    int succee=1;
    NOEUDP p, q;
    if (estVideP(L)) {
        printf ("\nListe vide");
        succee=0;
    }
    else {
        if ((pos < 1) || (pos > L->lg)) {
            printf ("\nPosition invalide");
            succee=0;
        }
        else{
            q = L->tete;
            /*suppression en tête de liste*/
            if (pos == 1)
                L->tete=L->tete->suivant;
            else { /*cas général (pos > 1) */
                for (i=1; i<pos; i++) {
                    p = q;
                    q = q->suivant;
                }
                p->suivant=q->suivant;
            }
            // q désigne l’élément de rang pos et p son prédécesseur
            noeudDetruireP(q);
            (L->lg)--;
        }
    }
    return succee;
}
ELEMENTP recupererP(LISTEP L, int pos) {
    /* s'il ya une erreur on affiche un message et on retourne un element vide */
    ELEMENTP elt= elementCreerP();
    int i;
    NOEUDP p;
    if (estVideP(L))
        printf ("\nListe vide");
    else {
        if ((pos < 1) || (pos > L->lg))
        printf ("\nPosition invalide");
        else {
            p= L->tete;
            for (i=1; i<pos; i++)
                p = p->suivant;
            elementAffecterP(&elt,p->info);
        }
    }
    return(elt);
}
LISTEP listeCopierP(LISTEP L){
    LISTEP LR = listeCreerP();
    int i;
    ELEMENTP elt;
    for(i = 1;i <= L->lg; i++) {
        elt=elementCreerP();
        elementCopierP(&elt, recupererP(L,i));
        insererP(LR,elt, i);
    }
    return LR;
}
int listeComparerP (LISTEP L1,LISTEP L2 ){
    int test= 1;
    int i=1;
    if (listeTailleP(L1) != listeTailleP(L2)) test= 0;
    while ((i<=listeTailleP(L1)) && (test)) {
        if (elementComparerP(recupererP(L1,i),recupererP(L2,i))!=0)
            test=0;
        i++;
    }
    return test;
}
void listeAfficherP(LISTEP L){
    int i=1;
    NOEUDP p;
    p= L->tete;
    for(i = 1;i <= L->lg; i++) {
        elementAfficherP(p->info);
        p= p->suivant;
    }
}
int estVideP(LISTEP L) {
    return (L->lg == 0);
}
int estSatureeP(LISTEP L) {
    NOEUDP temp;
    int saturee = 1; /* on suppose mémoire saturée */
    temp = (NOEUDP) malloc ( sizeof ( structNoeud1 ) );
    if(temp != NULL) {
        saturee = 0; /* mémoire non saturée */
        free(temp);
    }
    return saturee;
}
int listeTailleP(LISTEP L) {
    return (L->lg);
}
