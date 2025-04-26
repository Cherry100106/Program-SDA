#include "sda.h"

int main() {
    Kota daftarKota[MAX_KOTA];
    int jumlahKota = 0;
    char namaKota[MAX_NAMA];
    char namaWarga[MAX_NAMA];
    int pilihan;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Warga\n");
        printf("3. Tampilkan Semua Kota dan Warga\n");
        printf("4. Tampilkan warga dalam 1 kota\n");
        printf("5. Hapus Warga\n");
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
                EntryData(daftarKota, &jumlahKota, namaKota);
                break;
                
            case 2:
                printf("\nMasukkan nama kota: ");
                fgets(namaKota, MAX_NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama warga: ");
                fgets(namaWarga, MAX_NAMA, stdin);
                namaWarga[strcspn(namaWarga, "\n")] = 0;
                TambahWargaKeKota(daftarKota, jumlahKota, namaKota, namaWarga);
                break;
                
            case 3:
                TampilkanSemua(daftarKota, jumlahKota);
                break;

            case 4:
                printf("\nMasukkan nama kota: ");
                fgets(namaKota, MAX_NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                TampilkanWarga(daftarKota, jumlahKota, namaKota);
                break;
                
            case 5:
                printf("\nMasukkan nama kota tempat tinggal warga: ");
                fgets(namaKota, MAX_NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama warga yang akan dihapus: ");
                fgets(namaWarga, MAX_NAMA, stdin);
                namaWarga[strcspn(namaWarga, "\n")] = 0;
                HapusWargaDariKota(daftarKota, jumlahKota, namaKota, namaWarga);
                break;
                
            case 6:
                printf("\nMasukkan nama kota yang mau dihapus: ");
                fgets(namaKota, MAX_NAMA, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                HapusKota(daftarKota, &jumlahKota, namaKota);
                break;
                
            case 7:
                printf("Keluar dari program.\n");
                return 0;
                
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    }
}
