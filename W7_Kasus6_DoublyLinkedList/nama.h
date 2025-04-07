#ifndef NAMA_H
#define NAMA_H

typedef struct nama {
    char nm[20];
    struct nama *q;
} Nama;

// Fungsi-fungsi ADT Nama
Nama* buatNamaBaru(char *nama);
void tambahNama(Nama **head, char *nama);
void hapusSemuaNama(Nama **head);
void tampilkanNama(Nama *head);
int hitungNama(Nama *head); // Opsional

#endif