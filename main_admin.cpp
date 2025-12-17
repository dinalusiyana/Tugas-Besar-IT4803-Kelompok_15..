#include <iostream>
#include "main.h"
using namespace std;

void menuAdmin(listBis &LB, listPenumpang &LP, listRelasi &LR){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU ADMIN =====\n";
        cout << "1. Data Bis\n";
        cout << "2. Data Penumpang\n";
        cout << "3. Relasi\n";
        cout << "0. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

        if(pilih == 1){
            menuBis(LB);
        }
        else if(pilih == 2){
            menuPenumpang(LP);
        }
        else if(pilih == 3){
            menuRelasi(LB, LP, LR);
        }
    }
}

/* ================= MENU BIS ================= */

void menuBis(listBis &LB){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU BIS =====\n";
        cout << "1. Insert Bis\n";
        cout << "2. Show Bis\n";
        cout << "3. Delete First\n";
        cout << "0. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

        if(pilih == 1){
            Bis x;
            cout << "Nama Bis  : "; cin >> x.namaBis;
            cout << "Rute      : "; cin >> x.rute;
            cout << "Kapasitas : "; cin >> x.kapasitas;

            insertLast(LB, createElement(x));
            cout << "Bis berhasil ditambahkan\n";
            system("pause");
        }
        else if(pilih == 2){
            showAllBis(LB);
            system("pause");
        }
        else if(pilih == 3){
            adrBis P;
            deleteFirst(LB, P);
            cout << "Bis berhasil dihapus\n";
            system("pause");
        }
    }
}

/* ================= MENU PENUMPANG ================= */

void menuPenumpang(listPenumpang &LP){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU PENUMPANG =====\n";
        cout << "1. Insert Penumpang\n";
        cout << "2. Show Penumpang\n";
        cout << "3. Delete First\n";
        cout << "0. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

        if(pilih == 1){
            Penumpang x;
            cout << "Nama   : "; cin >> x.nama;
            cout << "Tujuan : "; cin >> x.tujuan;

            insertLastPenumpang(LP, createElmPenumpang(x));
            cout << "Penumpang berhasil ditambahkan\n";
            system("pause");
        }
        else if(pilih == 2){
            showPenumpang(LP);
            system("pause");
        }
        else if(pilih == 3){
            adrPenumpang P;
            deleteFirstPenumpang(LP, P);
            cout << "Penumpang berhasil dihapus\n";
            system("pause");
        }
    }
}

/* ================= MENU RELASI ================= */

void menuRelasi(listBis &LB, listPenumpang &LP, listRelasi &LR){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU RELASI =====\n";
        cout << "1. Insert First Relasi\n";
        cout << "2. Insert Last Relasi\n";
        cout << "3. Delete First Relasi\n";
        cout << "4. Delete Last Relasi\n";
        cout << "5. Show All Relasi\n";
        cout << "6. Show Penumpang dari Bis\n";
        cout << "7. Show Bis dari Penumpang\n";
        cout << "8. Count Penumpang dari Bis\n";
        cout << "9. Count Bis dari Penumpang\n";
        cout << "10. Count Bis tanpa Penumpang\n";
        cout << "11. Count Penumpang tanpa Bis\n";
        cout << "0. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

        if(pilih == 1 || pilih == 2){
            string nb, np;
            cout << "Nama bis: "; cin >> nb;
            cout << "Nama penumpang: "; cin >> np;

            adrBis B = findBis(LB, nb);
            adrPenumpang P = findPenumpang(LP, np);

            if(B != nullptr && P != nullptr){
                adrRelasi R = createElmRelasi(B, P);
                if(pilih == 1) insertFirstRelasi(LR, R);
                else insertLastRelasi(LR, R);
                cout << "Relasi berhasil ditambahkan\n";
            } else {
                cout << "Bis / Penumpang tidak ditemukan\n";
            }
            system("pause");
        }
        else if(pilih == 5){
            showAllRelasi(LR);
            system("pause");
        }
        else if(pilih == 6){
            string nb;
            cout << "Nama bis: "; cin >> nb;
            adrBis B = findBis(LB, nb);
            if(B) showPenumpangDariBis(LR, B);
            else cout << "Bis tidak ditemukan\n";
            system("pause");
        }
        else if(pilih == 7){
            string np;
            cout << "Nama penumpang: "; cin >> np;
            adrPenumpang P = findPenumpang(LP, np);
            if(P) showBisDariPenumpang(LR, P);
            else cout << "Penumpang tidak ditemukan\n";
            system("pause");
        }
        else if(pilih == 8){
            string nb;
            cout << "Nama bis: "; cin >> nb;
            cout << countPenumpangDariBis(LR, findBis(LB, nb)) << endl;
            system("pause");
        }
        else if(pilih == 9){
            string np;
            cout << "Nama penumpang: "; cin >> np;
            cout << countBisDariPenumpang(LR, findPenumpang(LP, np)) << endl;
            system("pause");
        }
        else if(pilih == 10){
            cout << countBisTanpaPenumpang(LR, LB) << endl;
            system("pause");
        }
        else if(pilih == 11){
            cout << countPenumpangTanpaBis(LR, LP) << endl;
            system("pause");
        }
    }
}
