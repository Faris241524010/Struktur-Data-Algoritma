#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"
#include "nama.h"

int main() {
    Kota *daftarKota = NULL;
    int pilihan;
    char namaKota[20], namaOrang[20];
    Kota *target;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Entry data kota\n");
        printf("2. Entry data nama per kota\n");
        printf("3. Hapus kota\n");
        printf("4. Tampilkan semua data\n");
        printf("5. Tampilkan nama per kota tertentu\n");
        printf("6. Hitung jumlah kota dan nama (opsional)\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar(); // untuk menangani newline

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                tambahKota(&daftarKota, namaKota);
                break;

            case 2:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                target = cariKota(daftarKota, namaKota);
                if (target != NULL) {
                    printf("Masukkan nama orang: ");
                    fgets(namaOrang, sizeof(namaOrang), stdin);
                    namaOrang[strcspn(namaOrang, "\n")] = '\0';
                    tambahNama(&(target->p), namaOrang);
                } else {
                    printf("Kota tidak ditemukan.\n");
                }
                break;

            case 3:
                printf("Masukkan nama kota yang akan dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                hapusKota(&daftarKota, namaKota);
                printf("Kota dan seluruh nama berhasil dihapus.\n");
                break;

            case 4:
                tampilkanSemuaKota(daftarKota);
                break;

            case 5:
                printf("Masukkan nama kota yang ingin ditampilkan: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                target = cariKota(daftarKota, namaKota);
                if (target != NULL) {
                    printf("Daftar nama di %s:\n", target->kt);
                    tampilkanNama(target->p);
                } else {
                    printf("Kota tidak ditemukan.\n");
                }
                break;

            case 6:
                printf("Jumlah kota: %d\n", hitungJumlahKota(daftarKota));
                printf("Total nama: %d\n", hitungJumlahSemuaNama(daftarKota));
                break;

            case 0:
                printf("Terima kasih.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 0);

    // Bersihkan memori semua kota dan nama
    while (daftarKota != NULL) {
        hapusKota(&daftarKota, daftarKota->kt);
    }

    return 0;
}