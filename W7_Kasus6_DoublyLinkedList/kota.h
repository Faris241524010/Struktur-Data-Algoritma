#ifndef KOTA_H
#define KOTA_H

#include "nama.h"

typedef struct kota {
    char kt[20];
    struct kota *prev;
    struct kota *next;
    Nama *p;  // pointer ke linked list nama
} Kota;

// Fungsi ADT Kota
Kota* buatKotaBaru(char *namaKota);
void tambahKota(Kota **head, char *namaKota);
Kota* cariKota(Kota *head, char *namaKota);
void hapusKota(Kota **head, char *namaKota);
void tampilkanSemuaKota(Kota *head);
int hitungJumlahKota(Kota *head);
int hitungJumlahSemuaNama(Kota *head);

#endif