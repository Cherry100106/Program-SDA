#include "sda.h"

void HapusSemuaWarga(Kota *kota) {
    DataWarga *curr = kota->nextWarga;
    while (curr != NULL) {
        DataWarga *temp = curr;
        curr = curr->next;
        free(temp);
    }
    kota->nextWarga = NULL;
}

void HapusKota(Kota daftarKota[], int *jumlahKota, const char *namaKota) {
    for (int i = 0; i < *jumlahKota; i++) {
        if (strcmp(daftarKota[i].NamaKota, namaKota) == 0) {
            HapusSemuaWarga(&daftarKota[i]);

            // geser geser
            for (int j = i; j < *jumlahKota - 1; j++) {
                daftarKota[j] = daftarKota[j + 1];
            }
            (*jumlahKota)--;

            printf("Kota '%s' dan seluruh warganya berhasil dihapus.\n", namaKota);
            return;
        }
    }
    printf("Kota '%s' tidak ditemukan.\n", namaKota);
}

