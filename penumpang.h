#ifndef PENUMPANG_H_INCLUDED
#define PENUMPANG_H_INCLUDED

#include <string>
using namespace std;

struct Penumpang {
    string nama;
    string tujuan;
};

typedef struct elmPenumpang *adrPenumpang;

struct elmPenumpang {
    Penumpang info;
    adrPenumpang next;
    adrPenumpang prev;
};

struct listPenumpang {
    adrPenumpang first;
    adrPenumpang last;
};

void createListPenumpang(listPenumpang &L);
adrPenumpang createElmPenumpang(Penumpang x);

void insertFirstPenumpang(listPenumpang &L, adrPenumpang P);
void insertLastPenumpang(listPenumpang &L, adrPenumpang P);
void insertAfterPenumpang(listPenumpang &L, adrPenumpang Prec, adrPenumpang P);

void deleteFirstPenumpang(listPenumpang &L, adrPenumpang &P);
void deleteLastPenumpang(listPenumpang &L, adrPenumpang &P);
void deleteAfterPenumpang(listPenumpang &L, adrPenumpang Prec, adrPenumpang &P);

adrPenumpang findPenumpang(listPenumpang L, string nama);
void showPenumpang(listPenumpang L);

#endif
