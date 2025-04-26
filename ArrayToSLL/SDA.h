#ifndef SDA_H
#define SDA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KOTA 5
#define MAX_NAMA 50


typedef struct DataWarga{
    char namaWarga[MAX_NAMA];
    struct DataWarga *next;
} DataWarga;

typedef struct Kota{
    char NamaKota[MAX_NAMA];
    DataWarga *nextWarga;
} Kota;


void HapusSemuaWarga(Kota *kota);
void HapusKota(Kota daftarKota[], int *jumlahKota, const char *namaKota);
void TampilkanWarga(Kota daftarKota[], int jumlahKota, const char *namaKota);
void TampilkanSemua(Kota daftarKota[], int jumlahKota);
void BuatWarga(Kota *kota, const char *namaWarga);
void TambahWarga(Kota *kota, const char *namaWarga);
void TambahWargaKeKota(Kota daftarKota[], int jumlahKota, const char *namaKota, const char *namaWarga);
void EntryData(Kota daftarKota[], int *jumlahKota, const char *namaKota);
void HapusWarga(Kota *kota, const char *namaWarga);
void HapusWargaDariKota(Kota daftarKota[], int jumlahKota, const char *namaKota, const char *namaWarga);

#endif
