#include <stdio.h>
#include "nbtrees.h"

int main() {
    Isi_Tree pohon;
    Create_tree(pohon, 10);
    
    printf("Isi Tree:\n");
    PrintTree(pohon);

    printf("\nPreOrder: ");
    PreOrder(pohon);

    printf("\nInOrder: ");
    InOrder(pohon);

    printf("\nPostOrder: ");
    PostOrder(pohon);

    printf("\nLevel Order: ");
    LevelOrder(pohon, 10);

    printf("\nDepth: %d\n", Depth(pohon));
    printf("\nLevel dari simpul E: %d\n", Level(pohon, 'E'));

    return 0;
}

