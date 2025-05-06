#include <stdio.h>
#include <stdlib.h>
#include "nbtrees.h"

int main() {
    Isi_Tree pohon;
    char cari;
    char data1, data2;
    int lvl;
    int pilihan;
    
    Create_tree(pohon, jml_maks);

    do {
        printf("\n=== MENU POHON NON-BINER ===\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal LevelOrder\n");
        printf("5. Print Tree\n");
        printf("6. Search Node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level Node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 Node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                printf("\nTraversal PreOrder: ");
                PreOrder(pohon);
                break;
            case 2:
                printf("\nTraversal InOrder: ");
                InOrder(pohon);
                break;
            case 3:
                printf("\nTraversal PostOrder: ");
                PostOrder(pohon);
                break;
            case 4:
                printf("\nTraversal LevelOrder: ");
                LevelOrder(pohon, jml_maks);
                break;
            case 5:
                printf("\nStruktur Tree:\n");
                PrintTree(pohon);
                break;
            case 6:
                printf("\nMasukkan huruf node yang dicari: ");
                scanf(" %c", &cari);
                if (Search(pohon, cari)) {
                    printf("Node '%c' ditemukan.\n", cari);
                } else {
                    printf("Node '%c' tidak ditemukan.\n", cari);
                }
                break;
            case 7:
                printf("\nJumlah daun: %d\n", nbDaun(pohon));
                break;
            case 8:
                printf("\nMasukkan node yang ingin dicari levelnya: ");
                scanf(" %c", &cari);
                lvl = Level(pohon, cari);
                printf("Level dari node '%c' adalah: %d\n", cari, lvl);
                break;
            case 9:
                printf("\nKedalaman tree: %d\n", Depth(pohon));
                break;
            case 10:
                printf("\nMasukkan 2 node untuk dibandingkan (contoh: B J): ");
                scanf(" %c %c", &data1, &data2);
                if (!Search(pohon, data1) || !Search(pohon, data2)) {
                    printf("Salah satu atau kedua node tidak ditemukan.\n");
                } else {
                    char maksimum = Max(data1, data2);
                    printf("Node dengan nilai maksimum secara ASCII adalah: %c\n", maksimum);
                }
                break;
            case 11:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 11);

    return 0;
}

