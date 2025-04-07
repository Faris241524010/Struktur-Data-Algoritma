Initial folder
# Program Representasi Data Kota dan Nama (Doubly & Singly Linked List)

Program ini merepresentasikan data himpunan kota dan daftar nama penduduknya menggunakan struktur **doubly linked list** untuk kota dan **singly linked list** untuk nama.

## Fitur
- Entry data kota (doubly linked list)
- Entry data nama per kota (singly linked list)
- Delete kota (beserta semua nama)
- Tampilkan semua data
- Tampilkan data nama berdasarkan kota
- Hitung jumlah kota dan total nama (opsional)

## Struktur File

| File       | Deskripsi |
|------------|-----------|
| `main.c`   | Program utama berisi menu interaktif untuk menjalankan fitur-fitur yang tersedia. |
| `kota.h`   | Header untuk ADT kota (doubly linked list), berisi definisi struct dan deklarasi fungsi. |
| `kota.c`   | Implementasi fungsi-fungsi terkait kota seperti tambah, hapus, cari, dan tampil. |
| `nama.h`   | Header untuk ADT nama (singly linked list), berisi definisi struct dan deklarasi fungsi. |
| `nama.c`   | Implementasi fungsi-fungsi untuk mengelola daftar nama per kota. |

## Cara Compile
Jika menggunakan GCC:
```bash
gcc main.c kota.c nama.c -o program
./program
