#include <iostream>
#include "main.h"
#include "relation.h"

using namespace std;

void menuUser(listBis &LB, listPenumpang &LP, listRelasi &LR){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU USER =====\n";
        cout << "1. Lihat Semua Bis\n";
        cout << "2. Lihat Semua Penumpang\n";
        cout << "3. Lihat Relasi Bis ke Penumpang\n";
        cout << "4. Lihat Relasi Penumpang ke Bis\n";
        cout << "0. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

        if(pilih == 1){
            showAllBis(LB);
            system("pause");
        }
        else if(pilih == 2){
            showPenumpang(LP);
            system("pause");
        }
        else if(pilih == 3){
            showRelasiBisKePenumpang(LB, LR);
            system("pause");
        }
        else if(pilih == 4){
            showRelasiPenumpangKeBis(LP, LR);
            system("pause");
        }
    }
}
