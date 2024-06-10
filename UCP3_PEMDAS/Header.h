#ifndef PERUSAHAAN_H
#define PERUSAHAAN_H
#include <vector>

class perusahaan {
public:
    string nama;
    vector<karyawan*> daftar_karyawan;

    perusahaan(string pNama) :nama(pNama) {
        cout << "perusahaan \"" << nama << "\" ada\n";
    }
    ~perusahaan() {
        cout << "perusahaan \"" << nama << "\" tidak ada\n";
    }
    void tambahKaryawan(karyawan*);
    void cetakKaryawan();
};

void perusahaan::tambahKaryawan(karyawan* pKaryawan) {
    daftar_karyawan.push_back(pKaryawan);
    pKaryawan->tambahPerusahaan(this);
}

void perusahaan::cetakKaryawan() {
    cout << "Daftar Karyawan Proyek sistem informasi \"" << this->nama << "\":\n";
    for (auto& a : daftar_karyawan) {
        cout << a->nama << "\n";
    }

    cout << endl;

}
#endif
