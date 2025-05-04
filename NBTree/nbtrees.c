#include <stdio.h>
#include "nbtrees.h"

void Create_tree(Isi_Tree X, int Jml_Node){

    //Index 0
    X[0].info='A';
    X[0].FirstSon=1;
    X[0].NextBrother=-1;
    X[0].Parent=-1;

    //Index 1
    X[1].info='B';
    X[1].FirstSon=3;
    X[1].NextBrother=2;
    X[1].Parent=0;

    //Index 2
    X[2].info='C';
    X[2].FirstSon=5;
    X[2].NextBrother=-1;
    X[2].Parent=0;

    //Index 3
    X[3].info='D';
    X[3].FirstSon=-1;
    X[3].NextBrother=4;
    X[3].Parent=1;

    //Index 4
    X[4].info='E';
    X[4].FirstSon=8;
    X[4].NextBrother=-1;
    X[4].Parent=1;

    //Index 5
    X[5].info='F';
    X[5].FirstSon=-1;
    X[5].NextBrother=6;
    X[5].Parent=2;

    //Index 6
    X[6].info='G';
    X[6].FirstSon=-1;
    X[6].NextBrother=7;
    X[6].Parent=2;

    //Index 7
    X[7].info='H';
    X[7].FirstSon=-1;
    X[7].NextBrother=-1;
    X[7].Parent=2;

    //Index 8
    X[8].info='I';
    X[8].FirstSon=-1;
    X[8].NextBrother=9;
    X[8].Parent=4;

    //Index 9
    X[9].info='J';
    X[9].FirstSon=-1;
    X[9].NextBrother=-1;
    X[9].Parent=4;
}

boolean IsEmpty (Isi_Tree P){
    return P[0].info == '\0';
}

void PrintTree (Isi_Tree P){
    for (int i= 1;i<=jml_maks;i++)
    {
        printf("--> Indeks ke-%d\n",i);
        printf("-----------------------------------\n");
        printf("info array ke %d         : %c\n",i,P[i].info);
        printf("first son array ke %d    : %d\n",i,P[i].FirstSon);
        printf("next brother array ke %d : %d\n",i,P[i].NextBrother);
        printf("parent array ke %d       : %d\n",i,P[i].Parent);
    }
}

int Root(Isi_Tree P){
    for (int i = 1; i <= jml_maks; i++){
        if (P[i].Parent == -1 && P[i].info != 0){
            return i;
        }
    }
    return -1;
}

void InOrderRek(Isi_Tree P, int idx){
    if (idx == - 1) return;
    int child = P[idx].FirstSon;
    if (child != -1){
        InOrderRek(P, child);
    }
    printf("%c", P[idx].info);

    if (child != -1){
        child = P[child].NextBrother;
        while (child != -1){
            InOrderRek(P, child);
            child = P[child].NextBrother;
        }
    }
}

void InOrder(Isi_Tree P){
    int root = Root(P);
    InOrderRek (P, root);
    printf("\n");
}

boolean Search (Isi_Tree P, infotype X){
    for (int i = 1; i <= jml_maks; i++){
        if (P[i].info == X) return true;
    }
    return false;
}

int nbElmt(Isi_Tree P){
    int count = 0;
    for (int i = 1; i <= jml_maks; i++){
        if (P[i].info != 0) count++;
    }
}

int nbDaun(Isi_Tree P){
    int daun = 0;
    for (int i = 1; i <= jml_maks; i++){
        if (P[i].info != 0 && P[i].FirstSon == -1)daun++;
    }
    return daun;
}

void Level_order(Isi_Tree P, int Maks_node) {
    int queue[jml_maks];
    int front = 0, rear = 0;

    int root = Root(P);
    if (root == -1) return;

    queue[rear++] = root;

    while (front < rear) {
        int curr = queue[front++];
        printf("%c ", P[curr].info);

        int child = P[curr].FirstSon;
        while (child != -1) {
            queue[rear++] = child;
            child = P[child].NextBrother;
        }
    }
    printf("\n");
}