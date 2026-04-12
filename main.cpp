#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Barang {
    string id;
    string nama;
    string kategori;
    int stok;
    double harga;
};

class Gudang {
  private:
    vector<Barang> daftarBarang;

    int cariIndexById(const string& id) {
        for (int i = 0; i < static_cast<int>(daftarBarang.size()); i++) {
            if (daftarBarang[i].id == id) {
                return i;
            }
        }
        return -1;
    }

  public:
    void tambahData() {
        Barang barang;

        cout << "\n=== Tambah Data ===\n";
        cout << "ID        : ";
        cin >> barang.id;

        if (cariIndexById(barang.id) != -1) {
            cout << "ID sudah ada.\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nama      : ";
        getline(cin, barang.nama);

        cout << "Kategori  : ";
        getline(cin, barang.kategori);

        cout << "Stok      : ";
        cin >> barang.stok;

        cout << "Harga     : ";
        cin >> barang.harga;

        daftarBarang.push_back(barang);
        cout << "Data berhasil ditambahkan.\n";
    }

    void tampilkanData() {
        cout << "\n=== Data Gudang ===\n";

        if (daftarBarang.empty()) {
            cout << "Data masih kosong.\n";
            return;
        }

        cout << left << setw(10) << "ID"
             << setw(20) << "Nama"
             << setw(15) << "Kategori"
             << setw(10) << "Stok"
             << setw(12) << "Harga" << '\n';
        cout << string(67, '-') << '\n';

        for (const Barang& barang : daftarBarang) {
            cout << left << setw(10) << barang.id
                 << setw(20) << barang.nama
                 << setw(15) << barang.kategori
                 << setw(10) << barang.stok
                 << setw(12) << fixed << setprecision(2) << barang.harga << '\n';
        }
    }

    void updateData() {
        string id;
        cout << "\n=== Update Data ===\n";
        cout << "Masukkan ID barang: ";
        cin >> id;

        int index = cariIndexById(id);
        if (index == -1) {
            cout << "Data tidak ditemukan.\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nama baru      : ";
        getline(cin, daftarBarang[index].nama);

        cout << "Kategori baru  : ";
        getline(cin, daftarBarang[index].kategori);

        cout << "Stok baru      : ";
        cin >> daftarBarang[index].stok;

        cout << "Harga baru     : ";
        cin >> daftarBarang[index].harga;

        cout << "Data berhasil diupdate.\n";
    }

    void hapusData() {
        string id;
        cout << "\n=== Hapus Data ===\n";
        cout << "Masukkan ID barang: ";
        cin >> id;

        int index = cariIndexById(id);
        if (index == -1) {
            cout << "Data tidak ditemukan.\n";
            return;
        }

        daftarBarang.erase(daftarBarang.begin() + index);
        cout << "Data berhasil dihapus.\n";
    }

    void urutkanData() {
        if (daftarBarang.empty()) {
            cout << "\nData masih kosong.\n";
            return;
        }

        int pilihan;
        cout << "\n=== Sorting Data ===\n";
        cout << "1. ID\n";
        cout << "2. Nama\n";
        cout << "3. Stok\n";
        cout << "4. Harga\n";
        cout << "Pilih sorting: ";
        cin >> pilihan;

        for (int i = 0; i < static_cast<int>(daftarBarang.size()) - 1; i++) {
            for (int j = 0; j < static_cast<int>(daftarBarang.size()) - i - 1; j++) {
                bool tukar = false;

                if (pilihan == 1 && daftarBarang[j].id > daftarBarang[j + 1].id) {
                    tukar = true;
                } else if (pilihan == 2 && daftarBarang[j].nama > daftarBarang[j + 1].nama) {
                    tukar = true;
                } else if (pilihan == 3 && daftarBarang[j].stok > daftarBarang[j + 1].stok) {
                    tukar = true;
                } else if (pilihan == 4 && daftarBarang[j].harga > daftarBarang[j + 1].harga) {
                    tukar = true;
                }

                if (tukar) {
                    Barang temp = daftarBarang[j];
                    daftarBarang[j] = daftarBarang[j + 1];
                    daftarBarang[j + 1] = temp;
                }
            }
        }

        cout << "Data berhasil diurutkan.\n";
    }
};

int main() {
    Gudang gudang;
    int pilihan;

    do {
        cout << "\n=== Sistem Manajemen Gudang ===\n";
        cout << "1. Tambah data\n";
        cout << "2. Hapus data\n";
        cout << "3. Update data\n";
        cout << "4. Tampilkan data\n";
        cout << "5. Sorting data\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                gudang.tambahData();
                break;
            case 2:
                gudang.hapusData();
                break;
            case 3:
                gudang.updateData();
                break;
            case 4:
                gudang.tampilkanData();
                break;
            case 5:
                gudang.urutkanData();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Menu tidak valid.\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
