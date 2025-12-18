#include <iostream>
#include "bis.h"
#include "penumpang.h"
#include "main.h"

using namespace std;

int main(){
    listBis LB;
    listPenumpang LP;
    listRelasi LR;

    createList(LB);
    createListPenumpang(LP);
    createListRelasi(LR);
    initDummyData(LB, LP, LR);

    int option = -99;

    while (option != 0) {
        system("cls");
        cout << "============ Menu ============ " << endl;
        cout << "|| 1. Admin                 ||" << endl;
        cout << "|| 2. User                  ||" << endl;
        cout << "|| 0. Exit                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Pilih : ";
        cin >> option;

        if (option == 1) {
            menuAdmin(LB, LP, LR);
        }
        else if (option == 2) {
            menuUser(LB, LP, LR);
        }
        else {
            cout << "Pilihan tidak tersedia." << endl;
            system("pause");
        }
    }

    return 0;
}
void initDummyData(listBis &LB, listPenumpang &LP, listRelasi &LR){

    /* ================= DUMMY BIS ================= */
    Bis b1 = {"Bis_A", "Bandung", 2};
    Bis b2 = {"Bis_B", "Bandung", 3};
    Bis b3 = {"Bis_C", "Jakarta", 2};
    Bis b4 = {"Bis_D", "Surabaya", 1};

    adrBis B1 = createElement(b1);
    adrBis B2 = createElement(b2);
    adrBis B3 = createElement(b3);
    adrBis B4 = createElement(b4);

    insertLast(LB, B1);
    insertLast(LB, B2);
    insertLast(LB, B3);
    insertLast(LB, B4);

    /* ================= DUMMY PENUMPANG ================= */
    Penumpang p1 = {"Asep", "Bandung"};
    Penumpang p2 = {"Budi", "Bandung"};
    Penumpang p3 = {"Cecep", "Jakarta"};
    Penumpang p4 = {"Udin", "Surabaya"};
    Penumpang p5 = {"Neneng", "Bandung"};
    Penumpang p6 = {"Beben", "Jakarta"};

    adrPenumpang P1 = createElmPenumpang(p1);
    adrPenumpang P2 = createElmPenumpang(p2);
    adrPenumpang P3 = createElmPenumpang(p3);
    adrPenumpang P4 = createElmPenumpang(p4);
    adrPenumpang P5 = createElmPenumpang(p5);
    adrPenumpang P6 = createElmPenumpang(p6);

    insertLastPenumpang(LP, P1);
    insertLastPenumpang(LP, P2);
    insertLastPenumpang(LP, P3);
    insertLastPenumpang(LP, P4);
    insertLastPenumpang(LP, P5);
    insertLastPenumpang(LP, P6);

    /* ================= DUMMY RELASI ================= */
    // Bandung
    insertLastRelasi(LR, createElmRelasi(B1, P1)); // Andi -> BisA
    insertLastRelasi(LR, createElmRelasi(B1, P2)); // Budi -> BisA
    insertLastRelasi(LR, createElmRelasi(B2, P5)); // Eko  -> BisB

    // Jakarta
    insertLastRelasi(LR, createElmRelasi(B3, P3)); // Cici -> BisC
    insertLastRelasi(LR, createElmRelasi(B3, P6)); // Fina -> BisC

    // Surabaya
    insertLastRelasi(LR, createElmRelasi(B4, P4)); // Dina -> BisD
}
