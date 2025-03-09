#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Nama = Farell Daffa Aditya \n");
    printf("NIM = 241511008\n");
    address list;
    Create_Node(&list);
    printf("Buat Linked List Awal: ");
    Tampil_List(list);
    Isi_Node(100, &list);
    printf("Buat node baru dan diisi dengan nilai 100: \n");
    Tampil_List(list);
    Add_Akhir(&list, 10);
    printf("Menambahkan node diakhir linked list dengan nilai 10: \n");
    Tampil_List(list);
    Add_Akhir(&list, 20);
    printf("Menambahkan node diakhir linked list dengan nilai 20: \n");
    Tampil_List(list);
    Add_Akhir(&list, 30);
    printf("Menambahkan node diakhir linked list dengan nilai 30: \n");
    Tampil_List(list);
    Add_Awal(&list, 5);
    printf("Menambahkan node diawal linked list dengan nilai 5: \n");
    Tampil_List(list);
    Add_Awal(&list, 300);
    printf("Menambahkan node diawal linked list dengan nilai 300: \n");
    Tampil_List(list);
    Add_Tengah(&list, 15, 3);
    printf("Menyisipkan node pada linked list pada posisi ke-3 dengan nilai 15: \n");
    Tampil_List(list);
    Add_Tengah(&list, 500, 6);
    printf("Menyisipkan node pada linked list pada posisi ke-6 dengan nilai 500: \n");
    Tampil_List(list);
    printf("Jumlah Node: %d\n", jumtot_Node(list));
    printf("Nilai Max: %d\n", node_Max(list));
    printf("Rata-rata: %.2f\n", rata2Node(list));
    printf("Mencari nilai 20 dalam linked list: \n");
    cariNode(list, 20);
    printf("Mencari nilai 1000 dalam linked list: \n");
    cariNode(list, 1000);
    printf("Menghapus node awal dari linked list: \n");
    hapus_NodeAwal(&list);
    printf("Setelah hapus awal: ");
    Tampil_List(list);
    printf("Menghapus node akhir dari linked list: \n");
    hapus_NodeAkhir(&list);
    printf("Setelah hapus akhir: ");
    Tampil_List(list);
    printf("Menghapus node pada posisi ke-2 dari linked list: \n");
    hapus_node(&list, 2);
    printf("Setelah menghapus posisi ke-2: \n");
    Tampil_List(list);
    printf("Menukar urutan node dalam linked list: \n");
    tukar_Node(&list);
    printf("Setelah ditukar: ");
    Tampil_List(list);
    return 0;
}
