#include <iostream>
#include "bis.h"
using namespace std;

void deleteFirst(listBis &L, adrBis &P){
    if(L.first == nullptr){
        P = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLast(listBis &L, adrBis &P){
    if(L.first == nullptr){
        P = nullptr;
    } else if(L.first->next == nullptr){
        P = L.first;
        L.first = nullptr;
    } else {
        adrBis Q = L.first;
        while(Q->next->next != nullptr){
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfter(listBis &L, adrBis Prec, adrBis &P){
    if(Prec == nullptr || Prec->next == nullptr){
        P = nullptr;
    } else {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

adrBis findBis(listBis L, string Carinama){
    adrBis P = L.first;
    while(P != nullptr){
        if(P->info.namaBis == Carinama){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void showAllBis(listBis L){
    adrBis P = L.first;
    while(P != nullptr){
        cout << "Nama Bis  : " << P->info.namaBis << endl;
        cout << "Rute      : " << P->info.rute << endl;
        cout << "Kapasitas : " << P->info.kapasitas << endl;
        cout << endl;
        P = P->next;
    }
}
