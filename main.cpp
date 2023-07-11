#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

// STRUCT
struct Queue
{
    int datacountantrian[100];
    string datanama[100];
    string datapoliantrian[100];
    string dataumur[100];
    int depan;
    int belakang;
};
//DEKLARASI QUEUE

Queue antrian;
Queue umur;
Queue nama;
Queue poli;

// DEKLARASI GLOBAL VARIABLE
int pilihmenu, pilihpoli, dataantrian, i;
string datanama, dataumur, datapoli, pilihcetak;

// QUEUE

// CEK APAKAH ANTRIAN KOSONG
int isEmpty()
{
    if (antrian.belakang == -1)
        return 1;
    else
        return 0;
}
// CEK APAKAH ANTRIAN PENUH
int isFull()
{
    if (antrian.belakang == 100)
        return 1;
    else
        return 0;
}
// VOID DENGAN PARAMETER REFERENCE
void PushQueue(int countantrianpar, const string& datanamapar, const string& datapoliantrianpar, const string& dataumurpar)
{
    if (isEmpty() == 1)
    {
        antrian.depan = antrian.belakang = 0;
        nama.depan = nama.belakang = 0;
        poli.depan = poli.belakang = 0;
        umur.depan = umur.belakang = 0;
        antrian.datacountantrian[antrian.belakang] = countantrianpar;
        nama.datanama[nama.belakang] = datanamapar;
        poli.datapoliantrian[poli.belakang] = datapoliantrianpar;
        umur.dataumur[umur.belakang] = dataumurpar;
        cout << "Data anda telah masuk. Silahkan menunggu panggilan" << endl;
    }

    else if (isFull() == 0)
    {
        antrian.belakang++;
        nama.belakang++;
        poli.belakang++;
        umur.belakang++;
        antrian.datacountantrian[antrian.belakang] = countantrianpar;
        nama.datanama[nama.belakang] = datanamapar;
        poli.datapoliantrian[poli.belakang] = datapoliantrianpar;
        umur.dataumur[umur.belakang] = dataumurpar;
        cout << "Data anda telah masuk. Silahkan menunggu panggilan." << endl;
    }
    else if(isFull() == 1) 
    {
        cout<<"Antrian Penuh " <<endl;
    }
}

int pullqueue()
{
    if (isEmpty() == 0)
    {
        int countantrian;
        string namaqueue, poliqueue;
        countantrian = antrian.datacountantrian[antrian.depan];
        namaqueue = nama.datanama[nama.depan];
        poliqueue = poli.datapoliantrian[poli.depan];
        for (i = antrian.depan; i < antrian.belakang; i++)
        {
            //memasukan data pada index depan
            antrian.datacountantrian[i] = antrian.datacountantrian[i + 1];
            nama.datanama[i] = nama.datanama[i + 1];
            poli.datapoliantrian[i] = poli.datapoliantrian[i + 1];
            umur.dataumur[i] = umur.dataumur[i + 1];
        }
        //mengurangi nilai tail
        antrian.belakang--;
        nama.belakang--;
        poli.belakang--;
        umur.belakang--;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Antrian No. " << countantrian << " dengan nama " << namaqueue << " silahkan memasuki " << poliqueue << "!" << endl;
        cout << "--------------------------------------------------------------" << endl;
        return countantrian;
    }

    else
    {
        // Mengembalikan nilai yang menandakan antrian kosong
        return -1;
    }
}

void programdimulai()
{
    antrian.depan = antrian.belakang = -1;
    nama.depan = nama.belakang = -1;
    poli.depan = poli.belakang = -1;
    umur.depan = umur.belakang = -1;
}

int main()
{
    int Countantrian;
    programdimulai();
    Countantrian = 1;
menu:
    system("cls");
    system("Color 70");
    cout << "+--------------------------------+" << endl;
    cout << "|     + PENDAFTARAN PASIEN +     |" << endl;
    cout << "+----+---------------------------+" << endl;
    cout << "| No | Layanan                   |" << endl;
    cout << "+----+---------------------------+" << endl;
    cout << "| 1. | Pendaftaran               |" << endl;
    cout << "| 2. | Daftar Antrian            |" << endl;
    cout << "| 3. | Panggil Antrian           |" << endl;
    cout << "| 4. | Keluar                    |" << endl;
    cout << "+----+---------------------------+" << endl;
    cout << endl;
    cout << "Silahkan pilih menu [1, 2, 3, 4]: ";
    cin >> pilihmenu;

    if (pilihmenu == 1)
    {
        system("cls");
        dataantrian = Countantrian;
        cout << "+--------------------------------+" << endl;
        cout << "|     + PENDAFTARAN PASIEN +     |" << endl;
        cout << "+--------------------------------+" << endl;
        cout << "Nama\t\t: ";
        cin >> datanama;
        cout << "Umur\t\t: ";
        cin >> dataumur;
        cout << "Poli Berobat\t: 1. Poli Umum" << endl;
        cout << "\t\t  2. Poli Anak" << endl;
        cout << "\t\t  3. Poli THT" << endl;
        cout << "\t\t  4. Poli Gigi" << endl;
        cout << endl;

    poli:
        cout << "Silahkan pilih poli [1, 2, 3, 4] : ";
        cin >> pilihpoli;

        if (pilihpoli == 1)
        {
            datapoli = "Poli Umum";
        }

        else if (pilihpoli == 2)
        {
            datapoli = "Poli Anak";
        }

        else if (pilihpoli == 3)
        {
            datapoli = "Poli THT";
        }

        else if (pilihpoli == 4)
        {
            datapoli = "Poli Gigi";
        }

        else
        {
            cout << "Pilihan salah" << endl;
            goto poli;
        }

        cout << endl;
        cout << "+--------------------------------+" << endl;
        cout << "|           No. Antrian          |" << endl;
        cout << "|                " << Countantrian << "               |" << endl;
        cout << "+--------------------------------+" << endl;

        PushQueue(dataantrian, datanama, datapoli, dataumur);
        Countantrian++;
    cetak:
        cout << "Cetak tiket? (Y/T) : ";
        cin >> pilihcetak;
        if (pilihcetak == "Y" || pilihcetak == "y")
        {
            ofstream tiket;
            tiket.open("D:\\TiketAntrian.txt");
            tiket << "+--------------------------------+" << endl;
            tiket << "|     + PENDAFTARAN PASIEN +     |" << endl;
            tiket << "+--------------------------------+" << endl;
            tiket << "Nama\t\t: " << datanama << endl;
            tiket << "Umur\t\t: " << dataumur << endl;
            tiket << "Poli Berobat\t: " << datapoli << endl;

            tiket << "+--------------------------------+" << endl;
            tiket << "|           No. Antrian          |" << endl;
            tiket << "|                " << dataantrian << "               |" << endl;
            tiket << "+--------------------------------+" << endl;
            tiket.close();
        }
        else if (pilihcetak == "T" || pilihcetak == "t")
        {
            goto menu;
        }
        else
        {
            cout << "Pilihan salah" << endl;
            goto cetak;
        }

        cout << "Tekan apapun untuk kembali";
        _getch();
        goto menu;
    }

    else if (pilihmenu == 2)
    {
        system("cls");
        cout << "+---------------------------------------+" << endl;
        cout << "| No\tNama\tUmur\tPoli Berobat    |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << endl;
        for (i = antrian.depan; i <= antrian.belakang; i++)
        {
            cout << "  " << antrian.datacountantrian[i] << "\t" << nama.datanama[i] << "\t" << umur.dataumur[i] << "\t" << poli.datapoliantrian[i] << endl;

        }
        cout << endl;
        cout << "Tekan apapun untuk kembali";
        _getch();
        goto menu;

    }

    else if (pilihmenu == 3)
    {
        int pullantrian = pullqueue();
        if (pullantrian == -1) {
            cout << "Antrian kosong" << endl;


        }
        cout << "Tekan apapun untuk kembali";
        _getch();
        goto menu;

    }

    else if (pilihmenu == 4)
    {
        exit(0);
    }

    return 0;
}
