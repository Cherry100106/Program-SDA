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

