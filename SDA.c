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

            printf("\nKota '%s' dan seluruh warganya berhasil dihapus.\n", namaKota);
            return;
        }
    }
    printf("\nKota '%s' tidak ditemukan.\n", namaKota);
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
    printf("\nKota '%s' tidak ditemukan.\n", namaKota);
}

void TampilkanSemua(Kota daftarKota[], int jumlahKota) {
    if (jumlahKota == 0) {
        printf("\nBelum ada kota.\n");
        return;
    }

    for (int i = 0; i < jumlahKota; i++) {
        printf("\nKota: %s\n", daftarKota[i].NamaKota);
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

DataWarga* BuatWargaBaru(const char *namaWarga) {
    DataWarga *newWarga = (DataWarga*)malloc(sizeof(DataWarga));
    if (newWarga == NULL) {
        printf("Gagal alokasi memori untuk warga baru!\n");
        return NULL;
    }
    strcpy(newWarga->namaWarga, namaWarga);
    newWarga->next = NULL;
    return newWarga;
}

void TambahWarga(Kota *kota, const char *namaWarga) {
    DataWarga *newWarga = BuatWargaBaru(namaWarga);
    if (newWarga == NULL) return;

    if (kota->nextWarga == NULL) {
        kota->nextWarga = newWarga;
    } else {
        DataWarga *curr = kota->nextWarga;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newWarga;
    }
    printf("\nWarga '%s' berhasil ditambahkan ke kota '%s'.\n", namaWarga, kota->NamaKota);
}

void TambahWargaKeKota(Kota daftarKota[], int jumlahKota, const char *namaKota, const char *namaWarga) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].NamaKota, namaKota) == 0) {
            TambahWarga(&daftarKota[i], namaWarga);
            return;
        }
    }
    printf("\nKota '%s' tidak ditemukan.\n", namaKota);
}

void EntryData(Kota daftarKota[], int *jumlahKota, const char *namaKota) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("Jumlah kota sudah mencapai batas maksimal!\n");
        return;
    }
    strcpy(daftarKota[*jumlahKota].NamaKota, namaKota);
    daftarKota[*jumlahKota].nextWarga = NULL;
    (*jumlahKota)++;
    printf("\nKota '%s' berhasil dimasukkan ke daftar.\n", namaKota);
}

void HapusWarga(Kota *kota, const char *namaWarga) {
    DataWarga *curr = kota->nextWarga;
    DataWarga *prev = NULL;
    
    while (curr != NULL) {
        if (strcmp(curr->namaWarga, namaWarga) == 0) {
            if (prev == NULL) {
                kota->nextWarga = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("\nWarga '%s' berhasil dihapus dari kota '%s'.\n", namaWarga, kota->NamaKota);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("\nWarga '%s' tidak ditemukan di kota '%s'.\n", namaWarga, kota->NamaKota);
}

void HapusWargaDariKota(Kota daftarKota[], int jumlahKota, const char *namaKota, const char *namaWarga) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].NamaKota, namaKota) == 0) {
            HapusWarga(&daftarKota[i], namaWarga);
            return;
        }
    }
    printf("\nKota '%s' tidak ditemukan.\n", namaKota);
}
