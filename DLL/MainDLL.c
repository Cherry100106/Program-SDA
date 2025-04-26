#include "sdadll.h"

int main() {
    Kota *firstKota = NULL;
    char namaKota[MAX_NAMA];
    char namaWarga[MAX_NAMA];
    int pilihan;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Warga ke Kota\n");
        printf("3. Tampilkan Semua Kota dan Warganya\n");
        printf("4. Tampilkan Warga dalam Satu Kota\n");
        printf("5. Hapus Warga dari Kota\n");
        printf("6. Hapus Kota\n");
        printf("7. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                printf("\nMasukkan nama kota: ");
                fgets(namaKota, MAX_NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                EntryData(&firstKota, namaKota);
                break;

            case 2:
                printf("\nMasukkan nama kota: ");
                fgets(namaKota, MAX_NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama warga: ");
                fgets(namaWarga, MAX_NAMA, stdin);
                namaWarga[strcspn(namaWarga, "\n")] = 0;
                TambahWargaKeKota(firstKota, namaKota, namaWarga);
                break;

            case 3:
                TampilkanSemua(firstKota);
                break;

            case 4:
                printf("\nMasukkan nama kota: ");
                fgets(namaKota, MAX_NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                TampilkanWarga(firstKota, namaKota);
                break;

            case 5:
                printf("\nMasukkan nama kota: ");
                fgets(namaKota, MAX_NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama warga: ");
                fgets(namaWarga, MAX_NAMA, stdin);
                namaWarga[strcspn(namaWarga, "\n")] = 0;
                HapusWargaDariKota(firstKota, namaKota, namaWarga);
                break;

            case 6:
                printf("\nMasukkan nama kota yang mau dihapus: ");
                fgets(namaKota, MAX_NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                HapusKota(&firstKota, namaKota);
                break;

            case 7:
                printf("Keluar dari program.\n");
                return 0;

            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    }
}

