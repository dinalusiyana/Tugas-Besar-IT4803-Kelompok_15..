#include <iostream>
#include "main.h"
using namespace std;

void menuUser(listBis &LB, listPenumpang &LP, listRelasi &LR){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU USER =====\n";
        cout << "1. Lihat Bis\n";
        cout << "2. Lihat Penumpang\n";
        cout << "3. Lihat Relasi\n";
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
            showAllRelasi(LR);
            system("pause");
        }
    }
}
