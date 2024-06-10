#include <iostream>
#include <vector>
using namespace std;

class perusahaan;
class proyek;
class karyawan {
public:
    string nama;
    vector<perusahaan*> daftar_perusahaan;
    vector<proyek*> daftar_proyek;
    karyawan(string pNama) :nama(pNama) {
        cout << "karyawan \"" << nama << "\" ada\n";
    }
    ~karyawan() {
        cout << "karyawan \"" << nama << "\" tidak ada\n";
    }
    void tambahPerusahaan(perusahaan*);
    void cetakPerusahaan();
    void tambahProyek(proyek*);
    void cetakProyek();
};

class proyek {
public:
    string nama;
    vector<karyawan*> daftar_karyawan;

    proyek(string pNama) :nama(pNama) {
        cout << "proyek \"" << nama << "\" ada\n";
    }
    ~proyek() {
        cout << "proyek \"" << nama << "\" tidak ada\n";
    }
    void tambahKaryawan(karyawan*);
    void cetakKaryawan();
};

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

void karyawan::tambahProyek(proyek* pProyek) {
    daftar_proyek.push_back(pProyek);

}

void karyawan::cetakProyek() {
    cout << "Daftar Karyawan Proyek Sistem Keamanan \"" << this->nama << "\":\n";
    for (auto& a : daftar_proyek) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

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

void proyek::tambahKaryawan(karyawan* pKaryawan) {
    daftar_karyawan.push_back(pKaryawan);
    pKaryawan->tambahProyek(this);
}

void proyek::cetakKaryawan() {
    cout << "Daftar Karyawan Proyek Sistem Keamanan \"" << this->nama << "\":\n";
    for (auto& a : daftar_karyawan) {
        cout << a->nama << "\n";

        cout << endl;
    }
}





int main()
{
    perusahaan* varPerusahaan = new perusahaan("PT.Maju Mundur");
    karyawan* varKaryawan1 = new karyawan("Budi");
    karyawan* varKaryawan2 = new karyawan("Andi");
    proyek* varproyek = new proyek("Proyek sistem keamanan");
    
    varproyek->tambahKaryawan(varKaryawan1);
    varPerusahaan->tambahKaryawan(varKaryawan1);
    varPerusahaan->tambahKaryawan(varKaryawan2);

    varPerusahaan->cetakKaryawan();
    varproyek->cetakKaryawan();

   
    

}

