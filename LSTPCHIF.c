#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LSTPRIMPC.h"
NOEUDpc noeudCreerPC(ELEMENTPC e){
    NOEUDpc n;
    n =(NOEUDpc)malloc(sizeof(structNoeud2));
    if(!n){
        printf ("\nPlus d'espace");
    }
    else{
        elementAffecterPC(&n->info, e);
        n->suivant = NULL;
    }
    return n;
}
void noeudDetruirePC(NOEUDpc n){
    elementDetruirePC(n->info);
    free(n);
}
LISTEPC listeCreerPC(void) {
    LISTEPC L;
    L=(LISTEPC)malloc(sizeof(listephrasechif));
    if (! L)
        printf("\nProblème de mémoire");
    else {
        L->lg = 0;
        L->tete = NULL; /* initialiser la tête */
    }
    return(L);
}
void listeDetruirePC(LISTEPC L){
    int i;
    NOEUDpc p, q;
    q= L->tete;
    for(i = 1;i <= L->lg; i++) {
        p=q;
        q=q->suivant;
        noeudDetruirePC(p);
    }
    free(L);
}
int insererPC (LISTEPC L, ELEMENTPC e, int pos){
    int succee=1;
    int i;
    NOEUDpc n, p, q; // c des pointeurs sur noeud c equivalent à:
    // structNoeud * n
    if (estSatureePC(L)){
        printf ("\nListe saturée");
        succee=0;
    }
    else {
        if ((pos < 1) || (pos > L->lg + 1)) {
            printf ("\nPosition invalide");
            succee=0;
        }
        else {
            n=noeudCreerPC (e);
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
int supprimerPC (LISTEPC L, int pos ){
    int i;
    int succee=1;
    NOEUDpc p, q;
    if (estVidePC(L)) {
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
            noeudDetruirePC(q);
            (L->lg)--;
        }
    }
    return succee;
}
ELEMENTPC recupererPC(LISTEPC L, int pos) {
    /* s'il ya une erreur on affiche un message et on retourne un element vide */
    ELEMENTPC elt= elementCreerPC();
    int i;
    NOEUDpc p;
    if (estVidePC(L))
        printf ("\nListe vide");
    else {
        if ((pos < 1) || (pos > L->lg))
        printf ("\nPosition invalide");
        else {
            p= L->tete;
            for (i=1; i<pos; i++)
                p = p->suivant;
            elementAffecterPC(&elt,p->info);
        }
    }
    return(elt);
}
LISTEPC listeCopierPC(LISTEPC L){
    LISTEPC LR = listeCreerPC();
    int i;
    ELEMENTPC elt;
    for(i = 1;i <= L->lg; i++) {
        elt=elementCreerPC();
        elementCopierPC(&elt, recupererPC(L,i));
        insererPC(LR,elt, i);
    }
    return LR;
}
int listeComparerPC (LISTEPC L1,LISTEPC L2 ){
    int test= 1;
    int i=1;
    if (listeTaillePC(L1) != listeTaillePC(L2)) test= 0;
    while ((i<=listeTaillePC(L1)) && (test)) {
        if (elementComparerPC(recupererPC(L1,i),recupererPC(L2,i))!=0)
            test=0;
        i++;
    }
    return test;
}
void listeAfficherPC(LISTEPC L){
    int i=1;
    NOEUDpc p;
    p= L->tete;
    for(i = 1;i <= L->lg; i++) {
        elementAfficherPC(p->info);
        p= p->suivant;
    }
}
int estVidePC(LISTEPC L) {
    return (L->lg == 0);
}
int estSatureePC(LISTEPC L) {
    NOEUDpc temp;
    int saturee = 1; /* on suppose mémoire saturée */
    temp = (NOEUDpc) malloc ( sizeof ( structNoeud2 ) );
    if(temp != NULL) {
        saturee = 0; /* mémoire non saturée */
        free(temp);
    }
    return saturee;
}
int listeTaillePC(LISTEPC L) {
    return (L->lg);
}
