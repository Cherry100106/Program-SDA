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

void TampilkanWarga(Kota daftarKota[], int jumlahKota, const char *namaKota) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].NamaKota, namaKota) == 0) {
            printf("Warga di kota %s:\n", namaKota);
            DataWarga *curr = daftarKota[i].nextWarga;
            if (curr == NULL) {
                printf("  Tidak ada warga\n");
            }
            while (curr != NULL) {
                printf("  - %s\n", curr->namaWarga);
                curr = curr->next;
            }
            return;
        }
    }
    printf("Kota '%s' tidak ditemukan.\n", namaKota);
}

void TampilkanSemua(Kota daftarKota[], int jumlahKota) {
    if (jumlahKota == 0) {
        printf("Belum ada kota.\n");
        return;
    }

    for (int i = 0; i < jumlahKota; i++) {
        printf("Kota: %s\n", daftarKota[i].NamaKota);
        DataWarga *curr = daftarKota[i].nextWarga;
        if (curr == NULL) {
            printf("  Tidak ada warga\n");
        } else {
            while (curr != NULL) {
                printf("  - %s\n", curr->namaWarga);
                curr = curr->next;
            }
        }
    }
}
