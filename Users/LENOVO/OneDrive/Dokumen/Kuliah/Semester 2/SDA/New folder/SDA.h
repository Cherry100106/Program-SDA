#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KOTA 5
#define MAX_NAMA 100


typedef struct Kota{
    char NamaKota[MAX_NAMA];
    DataWarga *nextWarga;
} Kota;

typedef struct DataWarga{
    char namaWarga[MAX_NAMA];
    struct DataWarga *next;
} DataWarga;