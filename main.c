#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "LSTPRIMP.h"
#include "LSTPRIMPC.h"
#include "PILEPRIM.h"
int pgcd(int a, int b) {
    while (b != 0) {
        int x = b;
        b = a % b;
        a = x;
    }
    return a;
}
long long pomod(long long a, long long b, long long m){
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1){
            x = (x * y) % m;
        }
        y = (y * y) % m;
        b /= 2;
    }
    return x % m;
}
void chiffrement(ELEMENTP ch,int indice,Pile pilepublique,int N,int l,long long chif[],char caracteres[],LISTEPC LC){
    ELEMENTPC phc=elementCreerPC();
    phc->phrase[0] = '\0';
    int i;
    for(i=0;i<l;i++){
        caracteres[i]=ch->phrase[i];
        long long asc=ch->phrase[i];
        NOEUD som=pilepublique->tete;
        //elementAfficher(som->info);
        chif[i] = pomod(asc,(long long)som->info->y,(long long)som->info->x);
        char text[20];
        snprintf(text, sizeof(text), "%lld", chif[i]);
        strcat(phc->phrase, text);
    }
    insererPC(LC,phc,indice);
    printf("phrase chiffree : \n");
    elementAfficherPC(phc);
    printf("\n");
}
void dechiffrement(long long chif[],Pile pileprivee,int taille,int indice,int N){
    ELEMENTP ph = elementCreerP();
    ph->phrase[0] = '\0';
    NOEUD som=pileprivee->tete;
    int i;
    for(i=0;i<taille;i++){
        int c = pomod(chif[i], som->info->y, som->info->x);
        char car=c;
        ph->phrase[i]=car;
    }
    ph->phrase[i]='\0';
    printf("phrase dechiffree (verification) :\n");
    elementAfficherP(ph);
}
int main(){
    FILE *f;
    int N;
    printf("Saisir le nombre de lignes N : ");
    scanf("%i",&N);
    char ligne[1000];
    f = fopen("dic.txt", "r");
    if (f == NULL) {
        fprintf(stderr, "erreur fichier \n");
        return 1;
    }
    rewind(f);
    LISTEP L=listeCreerP();
    for (int i = 0; i < N; i++) {
        ELEMENTP ph=elementCreerP();
        if (fgets(ligne, sizeof(ligne), f) != NULL) {
            if (ligne[strlen(ligne) - 1] == '\n') {
                ligne[strlen(ligne) - 1] = '\0';
            }
            strcpy(ph->phrase,ligne);
            insererP(L,ph,i+1);
        }
    }
    fclose(f);


    srand(time(NULL));
    int nbprem[999];
    int i,j,nb,k=0;
    for(i=2;i<1000;i++){
        nb=0;
        for(j=2;j<i;j++){
            if(i%j==0){
                nb++;
            }
        }
        if(nb==0){
            nbprem[k]=i;
            k++;
        }
    }
    int p,q,n,F,e,test,d;
    LISTEPC LC=listeCreerPC();
    Pile pilePrivee=PileCreer();
    Pile pilePublique=PileCreer();
    for(i=0;i<N;i++){
        printf("Phrase %i : \n",i+1);
        elementAfficherP(recupererP(L,i+1));
        test=0;
        e=1;
        d=1;
        p=nbprem[rand() % k];
        q=nbprem[rand() % k];
        n=p*q;
        F=(p-1)*(q-1);
        //printf("n:%i\nF:%i\n",n,F);
        while(e<F && !test){
            e++;
            if(pgcd(e,F)==1){
                test=1;
            }
        }
        //printf("e:%i\n",e);
        while((d*e)%F!=1){
            d++;
        }
        //printf("p: %i\nq:%i\nd:%i\n",p,q,d);
        ELEMENT clepriv=elementCreer();
        clepriv->x=n;
        clepriv->y=e;
        ELEMENT clepub=elementCreer();
        clepub->x=n;
        clepub->y=d;
        Empiler(pilePrivee,clepriv);
        Empiler(pilePublique,clepub);
        printf("pile privee :\n");
        PileAfficher(pilePrivee);
        printf("pile publique :\n");
        PileAfficher(pilePublique);
        int l=strlen(recupererP(L,i+1)->phrase);
        char caracteres[l];
        long long chif[l];
        chiffrement(recupererP(L,i+1),i+1,pilePublique,N,l,chif,caracteres,LC);
        dechiffrement(chif,pilePrivee,l,i+1,N);
        printf("\n\n");
        printf("liste des phrases : \n");
        listeAfficherP(L);
        printf("liste des phrases chiffrees : \n");
        listeAfficherPC(LC);
        printf("\n\n");
    }
    return 0;
}
