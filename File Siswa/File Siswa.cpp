#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Nilai {
    float Mtk;
    float IPA;
    float BIndo;
    float BIng;
    float nilaiAkhir;
    float Tugas_Mtk;
    float Tugas_IPA;
    float Tugas_BIndo;
    float Tugas_BIng;
    float UTS_Mtk;
    float UTS_IPA;
    float UTS_BIndo;
    float UTS_BIng;
    float UAS_Mtk;
    float UAS_IPA;
    float UAS_BIndo;
    float UAS_BIng;
};

struct TanggalLahir {
    int hari;
    int bulan;
    int tahun;
};

struct Siswa {
    string nama;
    string NISN;
    string jurusan;
    int umur;
    int absen;
    TanggalLahir tgl;
    Nilai n;
};

float hitungNilaiAkhir(
    float Tugas_Mtk, float Tugas_IPA, float Tugas_BIndo, float Tugas_BIng,
    float UTS_Mtk, float UTS_IPA, float UTS_BIndo, float UTS_BIng,
    float UAS_Mtk, float UAS_IPA, float UAS_BIndo, float UAS_BIng) {
    
    float Mtk   = (Tugas_Mtk * 0.25f) + (UTS_Mtk * 0.35f) + (UAS_Mtk * 0.40f);
    float IPA   = (Tugas_IPA * 0.25f) + (UTS_IPA * 0.35f) + (UAS_IPA * 0.40f);
    float BIndo = (Tugas_BIndo * 0.25f) + (UTS_BIndo * 0.35f) + (UAS_BIndo * 0.40f);
    float BIng  = (Tugas_BIng * 0.25f) + (UTS_BIng * 0.35f) + (UAS_BIng * 0.40f);

    return (Mtk * 0.35f) + (IPA * 0.25f) + (BIng * 0.20f) + (BIndo * 0.20f);
}

void inputData(Siswa &s, int nomor) {
    cout << "======DATA SISWA " << nomor << "======\n";
    cout << "Masukkan nama: ";
    cin >> s.nama;
    cout << "Masukkan NISN: ";
    cin >> s.NISN;
    cout << "Masukkan absen: ";
    cin >> s.absen;
    cout << "Masukkan umur: ";
    cin >> s.umur;
    cout << "Masukkan jurusan: ";
    cin >> s.jurusan;
    cout << "Masukkan tanggal lahir (hari bulan tahun): ";
    cin >> s.tgl.hari >> s.tgl.bulan >> s.tgl.tahun;
    cout << endl;
}

void inputNilai(Siswa &s) {
    cout << "---MASUKKAN NILAI TUGAS---" << endl;
    cout << "Matematika: ";
    cin >> s.n.Tugas_Mtk;
    cout << "IPA: ";
    cin >> s.n.Tugas_IPA;
    cout << "Bahasa Indonesia: ";
    cin >> s.n.Tugas_BIndo;
    cout << "Bahasa Inggris: ";
    cin >> s.n.Tugas_BIng;

    cout << "\n---MASUKKAN NILAI UTS---" << endl;
    cout << "Matematika: ";
    cin >> s.n.UTS_Mtk;
    cout << "IPA: ";
    cin >> s.n.UTS_IPA;
    cout << "Bahasa Indonesia: ";
    cin >> s.n.UTS_BIndo;
    cout << "Bahasa Inggris: ";
    cin >> s.n.UTS_BIng;

    cout << "\n---MASUKKAN NILAI UAS---" << endl;
    cout << "Matematika: ";
    cin >> s.n.UAS_Mtk;
    cout << "IPA: ";
    cin >> s.n.UAS_IPA;
    cout << "Bahasa Indonesia: ";
    cin >> s.n.UAS_BIndo;
    cout << "Bahasa Inggris: ";
    cin >> s.n.UAS_BIng;

    s.n.Mtk = (s.n.Tugas_Mtk * 0.25f) + (s.n.UTS_Mtk * 0.35f) + (s.n.UAS_Mtk * 0.40f);
    s.n.IPA = (s.n.Tugas_IPA * 0.25f) + (s.n.UTS_IPA * 0.35f) + (s.n.UAS_IPA * 0.40f);
    s.n.BIndo = (s.n.Tugas_BIndo * 0.25f) + (s.n.UTS_BIndo * 0.35f) + (s.n.UAS_BIndo * 0.40f);
    s.n.BIng = (s.n.Tugas_BIng * 0.25f) + (s.n.UTS_BIng * 0.35f) + (s.n.UAS_BIng * 0.40f);

    s.n.nilaiAkhir = (s.n.Mtk * 0.35f) + (s.n.IPA * 0.25f) + (s.n.BIng * 0.20f) + (s.n.BIndo * 0.20f);
}

void simpanDataKeFile(Siswa s) {
    ofstream file("siswa.txt", ios::app);
    if (file.is_open()) {
        file << "Nama        : " << s.nama << endl;
        file << "Absen       : " << s.absen << endl;
        file << "NISN        : " << s.NISN << endl;
        file << "Umur        : " << s.umur << endl;
        file << "Jurusan     : " << s.jurusan << endl;
        file << "Tanggal Lhr : " << s.tgl.hari << "-" << s.tgl.bulan << "-" << s.tgl.tahun << endl;
        file << "Nilai Mtk   : " << s.n.Mtk << endl;
        file << "Nilai IPA   : " << s.n.IPA << endl;
        file << "Nilai B.Ind : " << s.n.BIndo << endl;
        file << "Nilai B.Ing : " << s.n.BIng << endl;
        file << "Nilai Akhir : " << s.n.nilaiAkhir << endl;
        file << "============================\n";
        file.close();
    } else {
        cout << "Gagal menyimpan data!\n";
    }
}

void tampilSemuaData() {
    ifstream file("siswa.txt");
    if (!file.is_open()) {
        cout << "File tidak ditemukan!\n";
        return;
    }

    string baris;
    cout << "\n===== SEMUA DATA SISWA =====\n";
    while (getline(file, baris)) {
        cout << baris << endl;
    }
    file.close();
    cout << "=============================\n";
}

void cariSiswa() {
    ifstream file("siswa.txt");
    if (!file.is_open()) {
        cout << "File tidak ditemukan!\n";
        return;
    }

    string cariNISN;
    cout << "Masukkan NISN yang ingin dicari: ";
    getline(cin >> ws, cariNISN);

    string line;
    bool ditemukan = false;

    string nama, NISN, jurusan;
    int absen = 0, kelas = 0, umur = 0;
    int hari = 0, bulan = 0, tahun = 0;
    float mtk = 0, ipa = 0, indo = 0, ing = 0, nilaiAkhir = 0;

    while (getline(file, line)) {
        if (line.find("Nama") != string::npos)
            nama = line.substr(line.find(":") + 2);
        else if (line.find("NISN") != string::npos)
            NISN = line.substr(line.find(":") + 2);
        else if (line.find("Absen") != string::npos)
            absen = stoi(line.substr(line.find(":") + 2));
        else if (line.find("Kelas") != string::npos)
            kelas = stoi(line.substr(line.find(":") + 2));
        else if (line.find("Umur") != string::npos)
            umur = stoi(line.substr(line.find(":") + 2));
        else if (line.find("Jurusan") != string::npos)
            jurusan = line.substr(line.find(":") + 2);
        else if (line.find("Tanggal Lhr") != string::npos)
            sscanf(line.c_str(), "Tanggal Lhr : %d-%d-%d", &hari, &bulan, &tahun);
        else if (line.find("Nilai Mtk") != string::npos)
            mtk = stof(line.substr(line.find(":") + 2));
        else if (line.find("Nilai IPA") != string::npos)
            ipa = stof(line.substr(line.find(":") + 2));
        else if (line.find("Nilai B.Ind") != string::npos)
            indo = stof(line.substr(line.find(":") + 2));
        else if (line.find("Nilai B.Ing") != string::npos)
            ing = stof(line.substr(line.find(":") + 2));
        else if (line.find("Nilai Akhir") != string::npos)
            nilaiAkhir = stof(line.substr(line.find(":") + 2));
        else if (line.find("============================") != string::npos) {
            if (NISN == cariNISN) {
                ditemukan = true;
                cout << "\n===== DATA DITEMUKAN =====\n";
                cout << "Nama        : " << nama << endl;
                cout << "Absen       : " << absen << endl;
                cout << "NISN        : " << NISN << endl;
                cout << "Umur        : " << umur << endl;
                cout << "Jurusan     : " << jurusan << endl;
                cout << "Tanggal Lhr : " << hari << "-" << bulan << "-" << tahun << endl;
                cout << "Nilai Mtk   : " << mtk << endl;
                cout << "Nilai IPA   : " << ipa << endl;
                cout << "Nilai B.Ind : " << indo << endl;
                cout << "Nilai B.Ing : " << ing << endl;
                cout << "Nilai Akhir : " << nilaiAkhir << endl;
                cout << "============================\n";
                break;
            }
            nama = NISN = jurusan = "";
            absen = kelas = umur = hari = bulan = tahun = 0;
            mtk = ipa = indo = ing = nilaiAkhir = 0;
        }
    }

    if (!ditemukan)
        cout << "\nData dengan NISN " << cariNISN << " tidak ditemukan!\n";

    file.close();
}

void rankingSiswa() {
    ifstream file("siswa.txt");
    if (!file.is_open()) {
        cout << "File tidak ditemukan!\n";
        return;
    }

    Siswa s[100];
    int jumlah = 0;
    string line;

    while (getline(file, line)) {
        if (line.find("Nama") != string::npos) {
            s[jumlah].nama = line.substr(line.find(":") + 2);
        } else if (line.find("Absen") != string::npos) {
            s[jumlah].absen = stoi(line.substr(line.find(":") + 2));
        } else if (line.find("NISN") != string::npos) {
            s[jumlah].NISN = line.substr(line.find(":") + 2);
        } else if (line.find("Umur") != string::npos) {
            s[jumlah].umur = stoi(line.substr(line.find(":") + 2));
        } else if (line.find("Jurusan") != string::npos) {
            s[jumlah].jurusan = line.substr(line.find(":") + 2);
        } else if (line.find("Nilai Akhir") != string::npos) {
            s[jumlah].n.nilaiAkhir = stof(line.substr(line.find(":") + 2));
        } else if (line.find("============================") != string::npos) {
            jumlah++;
        }
    }
    file.close();

    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (s[i].n.nilaiAkhir < s[j].n.nilaiAkhir) {
                Siswa temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    cout << "\n===== RANKING SISWA =====\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Ranking " << i + 1 << endl;
        cout << "Nama        : " << s[i].nama << endl;
        cout << "NISN        : " << s[i].NISN << endl;
        cout << "Absen       : " << s[i].absen << endl;
        cout << "Jurusan     : " << s[i].jurusan << endl;
        cout << "Nilai Akhir : " << s[i].n.nilaiAkhir << endl;
        cout << "--------------------------\n";
    }
    cout << "==========================\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n===== MENU DATA SISWA =====\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Data Berdasarkan NISN\n";
        cout << "4. Tampilkan Ranking Nilai Akhir\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int jumlah;
            cout << "Masukkan jumlah siswa: ";
            cin >> jumlah;
            Siswa s[jumlah];

            for (int i = 0; i < jumlah; i++) {
                inputData(s[i], i + 1);
                inputNilai(s[i]);
                s[i].n.nilaiAkhir = hitungNilaiAkhir(s[i].n.Tugas_Mtk, s[i].n.Tugas_IPA, s[i].n.Tugas_BIndo, s[i].n.Tugas_BIng,
                                                     s[i].n.UTS_Mtk, s[i].n.UTS_IPA, s[i].n.UTS_BIndo, s[i].n.UTS_BIng,
                                                     s[i].n.UAS_Mtk, s[i].n.UAS_IPA, s[i].n.UAS_BIndo, s[i].n.UAS_BIng);
                simpanDataKeFile(s[i]);
            }
            cout << "Data berhasil disimpan!\n";
        }
        else if (pilihan == 2) {
            tampilSemuaData();
        }
        else if (pilihan == 3) {
            cariSiswa();
        }
        else if (pilihan == 4) {
            rankingSiswa();
        }
        else if (pilihan == 5) {
            cout << "Keluar dari program...\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}