#include <stdio.h>
#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node){
    
    //Index 0
    X[0].info='o';
    X[0].FirstSon=-1;
    X[0].NextBrother=-1;
    X[0].Parent=-1;

    //Index 1
    X[1].info='A';
    X[1].FirstSon=-1;
    X[1].NextBrother=-1;
    X[1].Parent=-1;

    //Index 2
    X[2].info='B';
    X[2].FirstSon=-1;
    X[2].NextBrother=-1;
    X[2].Parent=-1;

    //Index 3
    X[3].info='C';
    X[3].FirstSon=-1;
    X[3].NextBrother=-1;
    X[3].Parent=-1;

    //Index 4
    X[4].info='D';
    X[4].FirstSon=-1;
    X[4].NextBrother=-1;
    X[4].Parent=-1;

    //Index 5
    X[5].info='E';
    X[5].FirstSon=-1;
    X[5].NextBrother=-1;
    X[5].Parent=-1;

    //Index 6
    X[6].info='F';
    X[6].FirstSon=-1;
    X[6].NextBrother=-1;
    X[6].Parent=-1;

    //Index 7
    X[7].info='G';
    X[7].FirstSon=-1;
    X[7].NextBrother=-1;
    X[7].Parent=-1;

    //Index 8
    X[8].info='H';
    X[8].FirstSon=-1;
    X[8].NextBrother=-1;
    X[8].Parent=-1;

    //Index 9
    X[9].info='I';
    X[9].FirstSon=-1;
    X[9].NextBrother=-1;
    X[9].Parent=-1;

    //Index 10
    X[10].info='J';
    X[10].FirstSon=-1;
    X[10].NextBrother=-1;
    X[10].Parent=-1;
}

boolean IsEmpty (Isi_Tree P){
    return P[jml_maks+1].info==0;
}

void PrintTree (Isi_Tree P){
    for (int i= 1;i<=jml_maks;i++)
    {
        printf("--> Indeks ke-%d\n",i);
        printf("-----------------------------------\n");
        printf("info array ke %d         : %d\n",i,P->info);
        printf("first son array ke %d    : %d\n",i,P->FirstSon);
        printf("next brother array ke %d : %d\n",i,P->NextBrother);
        printf("parent array ke %d       : %d\n",i,P->Parent);
    }
}