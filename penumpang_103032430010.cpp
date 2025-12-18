#include <iostream>
#include "penumpang.h"
using namespace std;

void deleteFirstPenumpang(listPenumpang &L, adrPenumpang &P){
    if(L.first == nullptr){
        P = nullptr;
    } else {
        P = L.first;
        if(L.first == L.last){
            L.first = L.last = nullptr;
        } else {
            L.first = P->next;
            L.first->prev = nullptr;
        }
        P->next = nullptr;
    }
}

void deleteLastPenumpang(listPenumpang &L, adrPenumpang &P){
    if(L.first == nullptr){
        P = nullptr;
    } else {
        P = L.last;
        if(L.first == L.last){
            L.first = L.last = nullptr;
        } else {
            L.last = P->prev;
            L.last->next = nullptr;
        }
        P->prev = nullptr;
    }
}

void deleteAfterPenumpang(listPenumpang &L, adrPenumpang Prec, adrPenumpang &P){
    if(Prec == nullptr || Prec->next == nullptr){
        P = nullptr;
    } else {
        P = Prec->next;
        Prec->next = P->next;
        if(P->next != nullptr){
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = P->prev = nullptr;
    }
}

adrPenumpang findPenumpang(listPenumpang L, string nama){
    adrPenumpang P = L.first;
    while(P != nullptr){
        if(P->info.nama == nama){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void showPenumpang(listPenumpang L){
    adrPenumpang P = L.first;
    while(P != nullptr){
        cout << "Nama   : " << P->info.nama << endl;
        cout << "Tujuan : " << P->info.tujuan << endl;
        cout << endl;
        P = P->next;
    }
}
