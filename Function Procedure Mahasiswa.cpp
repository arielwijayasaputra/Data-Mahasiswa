#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama, jurusan;
    int umur;
    int hari, bulan, tahun;
    float tugas, uts, uas, nilaiakhir;
};

float hitungNilaiAkhir(float tugas, float uts, float uas) {
    return (tugas * 0.3) + (uts * 0.35) + (uas * 0.35);
}

void inputData(Mahasiswa &m, int nomor) {
    cout << "======DATA MAHASISWA " << nomor << "======\n" << endl;
    cout << "Masukkan nama: ";
    cin >> m.nama;
    cout << "Masukkan umur: ";
    cin >> m.umur;
    cout << "Masukkan jurusan: ";
    cin >> m.jurusan;
    cout << "Masukkan tanggal lahir: ";
    cin >> m.hari;
    cout << "Masukkan bulan lahir: ";
    cin >> m.bulan;
    cout << "Masukkan tahun lahir: ";
    cin >> m.tahun;
    cout << endl;
}

void inputNilai(Mahasiswa &m) {
    cout << "---MASUKKAN NILAI---\n" << endl;
    cout << "Masukkan nilai tugas: ";
    cin >> m.tugas;
    cout << "Masukkan nilai uts: ";
    cin >> m.uts;
    cout << "Masukkan nilai uas: ";
    cin >> m.uas;
    cout << endl;
}

void tampilData(Mahasiswa m, int nomor) {
    cout << "[]>>>>>>> DATA MAHASISWA " << nomor << " <<<<<<<[]\n" << endl;
    cout << "Nama : " << m.nama << endl;
    cout << "Umur : " << m.umur << endl;
    cout << "Jurusan : " << m.jurusan << endl;
    cout << "Tanggal Lahir : " << m.hari << " " << m.bulan << " " << m.tahun << endl;
    cout << endl;

    cout << "[]>>>>>>> NILAI MAHASISWA <<<<<<<[]\n" << endl;
    cout << "Nilai Tugas : " << m.tugas << endl;
    cout << "Nilai UTS : " << m.uts << endl;
    cout << "Nilai UAS : " << m.uas << endl;
    cout << "Nilai Akhir : " << m.nilaiakhir << endl;
    cout << "============================\n" << endl;
}

int main() {
    int jmhs;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jmhs;
    cout << endl;

    Mahasiswa m1[jmhs];
    for (int i = 0; i < jmhs; i++) {
        inputData(m1[i], i + 1);
        inputNilai(m1[i]);
        m1[i].nilaiakhir = hitungNilaiAkhir(m1[i].tugas, m1[i].uts, m1[i].uas);
        tampilData(m1[i], i + 1);
    }

    return 0;
}