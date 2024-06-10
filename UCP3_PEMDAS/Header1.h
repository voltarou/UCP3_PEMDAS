#ifndef KARYAWAN_H
#define KARYAWAN_H
#include <vector>

class karyawan {
public:
    string nama;
    vector<perusahaan*> daftar_perusahaan;
    karyawan(string pNama) :nama(pNama) {
        cout << "karyawan \"" << nama << "\" ada\n";
    }
    ~karyawan() {
        cout << "karyawan \"" << nama << "\" tidak ada\n";
    }
    void tambahPerusahaan(perusahaan*);
    void cetakPerusahaan();
};

void karyawan::tambahPerusahaan(perusahaan* pPerusahaan) {
    daftar_perusahaan.push_back(pPerusahaan);
}

void karyawan::cetakPerusahaan() {
    cout << "Daftar Karyawan Proyek Sistem Keamanan \"" << this->nama << "\":\n";
    for (auto& a : daftar_perusahaan) {
        cout << a->nama << "\n";
    }
    cout << endl;
}
#endif
