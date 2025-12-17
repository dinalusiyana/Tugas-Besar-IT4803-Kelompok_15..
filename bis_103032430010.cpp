#include <iostream>
#include "bis.h"
using namespace std;


void createList(listBis &L){
    L.first = nullptr;
}

adrBis createElement(Bis x){
    adrBis P = new elmBis;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirst(listBis &L, adrBis P){
    P->next = L.first;
    L.first = P;
}

void insertLast(listBis &L, adrBis P){
    if(L.first == nullptr){
        L.first = P;
    } else {
        adrBis Q = L.first;
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertAfter(listBis &L, adrBis Prec, adrBis P){
    if(Prec != nullptr){
        P->next = Prec->next;
        Prec->next = P;
    }
}
