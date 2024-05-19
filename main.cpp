#include <iostream>
#include <iomanip>
using namespace std;

int gaji_pokok_per_jam, gaji_lembur_per_jam, jam_kerja_pokok;
int x, jdata, pilih_menu;
string nama[100];
int lama_kerja[100];
int jam_lembur[100], gaji_pokok[100], gaji_lembur[100], total_gaji[100];

void wait()
{
  cout << "Press enter to continue...";
  cin.ignore();
  cin.get();
}

void hitung_gaji(int index)
{
  gaji_pokok_per_jam = 5000;
  gaji_lembur_per_jam = 7500;
  jam_kerja_pokok = 6;

  jam_lembur[index] = lama_kerja[index] - jam_kerja_pokok;

  if (jam_lembur[index] < 0)
  {
    jam_lembur[index] = 0;
  }

  gaji_pokok[index] = jam_kerja_pokok * gaji_pokok_per_jam;
  gaji_lembur[index] = jam_lembur[index] * gaji_lembur_per_jam;
  total_gaji[index] = gaji_pokok[index] + gaji_lembur[index];
}

void isi_data()
{
  char ulang;
  jdata = 0;
  x = 0;
  ulang = 'Y';

  while (ulang == 'Y' || ulang == 'y')
  {
    system("clear");
    cout << "Data ke                  : " << x + 1;
    cout << endl;
    cout << "Masukkan Nama            : ";
    cin >> nama[x];
    cout << "Masukkan Lama Jam Kerja  : ";
    cin >> lama_kerja[x];

    hitung_gaji(x);

    jdata++;
    x++;
    cout << endl;
    cout << "Masih Ada Data Lagi (Y/T) : ";
    cin >> ulang;
  }
}

void tambah_data()
{
  char ulang = 'Y';

  while (ulang == 'Y' || ulang == 'y')
  {
    system("clear");
    cout << "Data ke                  : " << x + 1;
    cout << endl;
    cout << "Masukkan Nama            : ";
    cin >> nama[jdata];
    cout << "Masukkan Lama Jam Kerja  : ";
    cin >> lama_kerja[jdata];

    hitung_gaji(jdata);

    jdata++;

    cout << endl;
    cout << "Masih Ada Data Lagi (Y/T) : ";
    cin >> ulang;
  }
}

void cari_data()
{
  string nama_cari;
  char ulang = 'Y';
  bool ditemukan = false;

  while (ulang == 'Y' || ulang == 'y')
  {
    system("clear");
    cout << "Masukkan nama karyawan : ";
    cin >> nama_cari;
    cout << endl;

    for (x = 0; x < jdata; x++)
    {
      if (nama[x] == nama_cari)
      {
        ditemukan = true;

        cout << "Nama         : " << nama[x] << endl;
        cout << "Lama Kerja   : " << lama_kerja[x] << " jam" << endl;
        cout << "Jam Lembur   : " << jam_lembur[x] << " jam" << endl;
        cout << "Gaji Pokok   : " << gaji_pokok[x] << endl;
        cout << "Gaji Lembur  : " << gaji_lembur[x] << endl;
        cout << "Total Gaji   : " << total_gaji[x] << endl;
        break;
      }
      else
      {
        ditemukan = false;
      }
    }

    if (!ditemukan)
    {
      cout << "Karyawan dengan nama '" << nama_cari << "' tidak ditemukan." << endl;
    }

    cout << endl;
    cout << "Mau cari Data Lagi (Y/T) : ";
    cin >> ulang;
  }
}

void ubah_data()
{
  string nama_ubah;
  char ulang = 'Y';
  bool ditemukan = false;

  while (ulang == 'Y' || ulang == 'y')
  {
    system("clear");

    cout << "Masukkan nama karyawan : ";
    cin >> nama_ubah;
    cout << endl;

    for (x = 0; x < jdata; x++)
    {
      if (nama[x] == nama_ubah)
      {
        ditemukan = true;

        cout << "Masukkan nama baru : ";
        cin >> nama[x];
        cout << "Lama jam kerja     : ";
        cin >> lama_kerja[x];

        hitung_gaji(x);

        cout << endl;
        cout << "Data berhasil diubah." << endl;
        break;
      }
      else
      {
        ditemukan = false;
      }
    }

    if (!ditemukan)
    {
      cout << "Karyawan dengan nama '" << nama_ubah << "' tidak ditemukan." << endl;
    }

    cout << endl;
    cout << "Mau cari Data Lagi (Y/T) : ";
    cin >> ulang;
  }
}

void cetak_data()
{
  int jumlah_gaji_pokok = 0;
  int jumlah_gaji_lembur = 0;
  int jumlah_gaji_total = 0;

  system("clear");
  cout << setw(58) << setfill(' ') << "DAFTAR GAJI KARYAWAN" << endl;
  cout << setw(60) << setfill(' ') << "PT. MEGAH BANGUN PERKASA" << endl;
  cout << "============================================================================================" << endl;
  cout << "| NO  | NAMA KARYAWAN    | LAMA KERJA | JAM LEMBUR | GAJI POKOK | GAJI LEMBUR | TOTAL GAJI |" << endl;
  cout << "--------------------------------------------------------------------------------------------" << endl;

  if (jdata)
  {
    for (x = 0; x < jdata; x++)
    {
      jumlah_gaji_pokok += gaji_pokok[x];
      jumlah_gaji_lembur += gaji_lembur[x];
      jumlah_gaji_total += total_gaji[x];

      cout << "| " << setw(3) << right << x + 1 << " | "
           << setw(16) << left << nama[x] << " | "
           << setw(10) << right << lama_kerja[x] << " | "
           << setw(10) << right << jam_lembur[x] << " | "
           << setw(10) << right << gaji_pokok[x] << " | "
           << setw(11) << right << gaji_lembur[x] << " | "
           << setw(10) << right << total_gaji[x] << " |" << endl;
    }
  }
  else
  {
    cout << "|" << setw(50) << setfill(' ') << "TIDAK ADA DATA" << setw(41) << setfill(' ') << "|" << endl;
  }
  cout << "--------------------------------------------------------------------------------------------" << endl;
  cout << "| " << setw(3) << right << " "
       << setw(24) << right << "JUMLAH" << " "
       << setw(23) << right << " | "
       << setw(10) << right << jumlah_gaji_pokok << " | "
       << setw(11) << right << jumlah_gaji_lembur << " | "
       << setw(10) << right << jumlah_gaji_total << " |" << endl;
  cout << "============================================================================================" << endl;
  cout << endl;
  wait();
}

int main()
{
  while (true)
  {
    system("clear");
    cout << ":: MENU UTAMA ::" << endl;
    cout << "~~" << endl;
    cout << "1. ISI DATA" << endl;
    cout << "2. TAMBAH DATA" << endl;
    cout << "3. CARI DATA" << endl;
    cout << "4. UBAH DATA" << endl;
    cout << "5. CETAK DATA" << endl;
    cout << "~~" << endl;
    cout << "0. KELUAR" << endl;
    cout << endl;
    cout << "Pilihan  : ";
    cin >> pilih_menu;

    switch (pilih_menu)
    {
    case 1:
      if (jdata > 0)
      {
        char konfirmasi;
        cout << "Data sudah ada. Mengisi data baru akan mereset data yang ada. Lanjutkan? (Y/T): ";
        cin >> konfirmasi;
        if (konfirmasi == 'y' || konfirmasi == 'Y')
        {
          isi_data();
        }
      }
      else
      {
        isi_data();
      }
      break;
    case 2:
      tambah_data();
      break;
    case 3:
      cari_data();
      break;
    case 4:
      ubah_data();
      break;
    case 5:
      cetak_data();
      break;
    case 0:
      cout << endl;
      cout << "Terima kasih!" << endl;
      return 0;
    default:
      cout << endl;
      cout << "Pilihan tidak valid!" << endl;
      cout << endl;
      wait();
    }
  }
}
