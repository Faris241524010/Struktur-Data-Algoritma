#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nama.h"

Nama* buatNamaBaru(char *nama) {
    Nama *baru = (Nama*)malloc(sizeof(Nama));
    if (baru != NULL) {
        strcpy(baru->nm, nama);
        baru->q = NULL;
    }
    return baru;
}

void tambahNama(Nama **head, char *nama) {
    Nama *baru = buatNamaBaru(nama);
    if (*head == NULL) {
        *head = baru;
    } else {
        Nama *bantu = *head;
        while (bantu->q != NULL) {
            bantu = bantu->q;
        }
        bantu->q = baru;
    }
}

void hapusSemuaNama(Nama **head) {
    Nama *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->q;
        free(temp);
    }
}

void tampilkanNama(Nama *head) {
    Nama *bantu = head;
    while (bantu != NULL) {
        printf("- %s\n", bantu->nm);
        bantu = bantu->q;
    }
}

int hitungNama(Nama *head) {
    int count = 0;
    Nama *bantu = head;
    while (bantu != NULL) {
        count++;
        bantu = bantu->q;
    }
    return count;
}