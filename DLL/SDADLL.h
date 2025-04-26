#ifndef SDADLL_H
#define SDADLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMA 50

typedef struct DataWarga {
    char namaWarga[MAX_NAMA];
    struct DataWarga *next;
} DataWarga;

typedef struct Kota {
    char NamaKota[MAX_NAMA];
    DataWarga *nextWarga;
    struct Kota *nextKota;
} Kota;

void EntryData(Kota **firstKota, const char *namaKota);
void HapusKota(Kota **firstKota, const char *namaKota);
void TampilkanSemua(Kota *firstKota);
void TampilkanWarga(Kota *firstKota, const char *namaKota);
void TambahWarga(Kota *kota, const char *namaWarga);
void TambahWargaKeKota(Kota *firstKota, const char *namaKota, const char *namaWarga);
void HapusWarga(Kota *kota, const char *namaWarga);
void HapusWargaDariKota(Kota *firstKota, const char *namaKota, const char *namaWarga);
void HapusSemuaWarga(DataWarga **firstWarga);

#endif

