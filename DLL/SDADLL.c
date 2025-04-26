#include "sdadll.h"

DataWarga* BuatWargaBaru(const char *namaWarga) {
    DataWarga *newWarga = (DataWarga*)malloc(sizeof(DataWarga));
    if (!newWarga) {
        printf("Gagal alokasi memori untuk warga baru!\n");
        return NULL;
    }
    strcpy(newWarga->namaWarga, namaWarga);
    newWarga->next = NULL;
    return newWarga;
}

Kota* BuatKotaBaru(const char *namaKota) {
    Kota *newKota = (Kota*)malloc(sizeof(Kota));
    if (!newKota) {
        printf("Gagal alokasi memori untuk kota baru!\n");
        return NULL;
    }
    strcpy(newKota->NamaKota, namaKota);
    newKota->nextWarga = NULL;
    newKota->nextKota = NULL;
    return newKota;
}

void EntryData(Kota **firstKota, const char *namaKota) {
    Kota *newKota = BuatKotaBaru(namaKota);
    if (!newKota) return;

    if (*firstKota == NULL) {
        *firstKota = newKota;
    } else {
        Kota *curr = *firstKota;
        while (curr->nextKota != NULL) {
            curr = curr->nextKota;
        }
        curr->nextKota = newKota;
    }
    printf("\nKota '%s' berhasil ditambahkan.\n", namaKota);
}

void HapusSemuaWarga(DataWarga **firstWarga) {
    DataWarga *curr = *firstWarga;
    while (curr != NULL) {
        DataWarga *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *firstWarga = NULL;
}

void HapusKota(Kota **firstKota, const char *namaKota) {
    Kota *curr = *firstKota;
    Kota *prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->NamaKota, namaKota) == 0) {
            if (prev == NULL) {
                *firstKota = curr->nextKota;
            } else {
                prev->nextKota = curr->nextKota;
            }
            HapusSemuaWarga(&curr->nextWarga);
            free(curr);
            printf("\nKota '%s' berhasil dihapus beserta semua warganya.\n", namaKota);
            return;
        }
        prev = curr;
        curr = curr->nextKota;
    }
    printf("\nKota '%s' tidak ditemukan.\n", namaKota);
}

void TampilkanSemua(Kota *firstKota) {
    if (firstKota == NULL) {
        printf("\nBelum ada kota.\n");
        return;
    }

    Kota *currKota = firstKota;
    while (currKota != NULL) {
        printf("\nKota: %s\n", currKota->NamaKota);
        DataWarga *currWarga = currKota->nextWarga;
        if (currWarga == NULL) {
            printf("  Tidak ada warga\n");
        } else {
            while (currWarga != NULL) {
                printf("  - %s\n", currWarga->namaWarga);
                currWarga = currWarga->next;
            }
        }
        currKota = currKota->nextKota;
    }
}

void TampilkanWarga(Kota *firstKota, const char *namaKota) {
    Kota *curr = firstKota;
    while (curr != NULL) {
        if (strcmp(curr->NamaKota, namaKota) == 0) {
            printf("\nWarga di kota %s:\n", namaKota);
            DataWarga *currWarga = curr->nextWarga;
            if (currWarga == NULL) {
                printf("  Tidak ada warga\n");
            } else {
                while (currWarga != NULL) {
                    printf("  - %s\n", currWarga->namaWarga);
                    currWarga = currWarga->next;
                }
            }
            return;
        }
        curr = curr->nextKota;
    }
    printf("\nKota '%s' tidak ditemukan.\n", namaKota);
}

void TambahWarga(Kota *kota, const char *namaWarga) {
    DataWarga *newWarga = BuatWargaBaru(namaWarga);
    if (!newWarga) return;

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

void TambahWargaKeKota(Kota *firstKota, const char *namaKota, const char *namaWarga) {
    Kota *curr = firstKota;
    while (curr != NULL) {
        if (strcmp(curr->NamaKota, namaKota) == 0) {
            TambahWarga(curr, namaWarga);
            return;
        }
        curr = curr->nextKota;
    }
    printf("\nKota '%s' tidak ditemukan.\n", namaKota);
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

void HapusWargaDariKota(Kota *firstKota, const char *namaKota, const char *namaWarga) {
    Kota *curr = firstKota;
    while (curr != NULL) {
        if (strcmp(curr->NamaKota, namaKota) == 0) {
            HapusWarga(curr, namaWarga);
            return;
        }
        curr = curr->nextKota;
    }
    printf("\nKota '%s' tidak ditemukan.\n", namaKota);
}

