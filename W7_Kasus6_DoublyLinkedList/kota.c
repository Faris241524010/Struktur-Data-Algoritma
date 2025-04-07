#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

Kota* buatKotaBaru(char *namaKota) {
    Kota *baru = (Kota*)malloc(sizeof(Kota));
    if (baru != NULL) {
        strcpy(baru->kt, namaKota);
        baru->prev = NULL;
        baru->next = NULL;
        baru->p = NULL;
    }
    return baru;
}

void tambahKota(Kota **head, char *namaKota) {
    Kota *baru = buatKotaBaru(namaKota);
    if (*head == NULL) {
        *head = baru;
    } else {
        Kota *bantu = *head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->prev = bantu;
    }
}

Kota* cariKota(Kota *head, char *namaKota) {
    Kota *bantu = head;
    while (bantu != NULL) {
        if (strcmp(bantu->kt, namaKota) == 0)
            return bantu;
        bantu = bantu->next;
    }
    return NULL;
}

void hapusKota(Kota **head, char *namaKota) {
    Kota *hapus = cariKota(*head, namaKota);
    if (hapus == NULL) return;

    if (hapus->prev != NULL)
        hapus->prev->next = hapus->next;
    else
        *head = hapus->next;

    if (hapus->next != NULL)
        hapus->next->prev = hapus->prev;

    hapusSemuaNama(&(hapus->p));
    free(hapus);
}

void tampilkanSemuaKota(Kota *head) {
    Kota *bantu = head;
    while (bantu != NULL) {
        printf("Kota: %s\n", bantu->kt);
        if (bantu->p != NULL) {
            tampilkanNama(bantu->p);
        } else {
            printf("- (belum ada nama)\n");
        }
        bantu = bantu->next;
    }
}

int hitungJumlahKota(Kota *head) {
    int count = 0;
    Kota *bantu = head;
    while (bantu != NULL) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

int hitungJumlahSemuaNama(Kota *head) {
    int total = 0;
    Kota *bantu = head;
    while (bantu != NULL) {
        total += hitungNama(bantu->p);
        bantu = bantu->next;
    }
    return total;
}