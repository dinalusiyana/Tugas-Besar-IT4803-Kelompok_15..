#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED
#include "bis.h"
#include "penumpang.h"

typedef struct elmRelasi *adrRelasi;
struct elmRelasi{
    adrBis parent;
    adrPenumpang child;
    adrRelasi next;
    adrRelasi prev;
};
struct listRelasi{
    adrRelasi first;
    adrRelasi last;
};
void createListRelasi(listRelasi &L);
adrRelasi createElmRelasi(adrBis P, adrPenumpang C);

void insertFirstRelasi(listRelasi &L, adrRelasi R);
void insertLastRelasi(listRelasi &L, adrRelasi R);
void insertAfterRelasi(listRelasi &L, adrRelasi Prec, adrRelasi R);

void deleteFirstRelasi(listRelasi &L, adrRelasi &R);
void deleteLastRelasi(listRelasi &L, adrRelasi &R);
void deleteAfterRelasi(listRelasi &L, adrRelasi Prec, adrRelasi &R);

void showPenumpangDariBis(listRelasi L, adrBis P);
void showBisDariPenumpang(listRelasi L, adrPenumpang C);
void showAllRelasi(listRelasi L);

adrRelasi findRelasiByBis(listRelasi L, adrBis P);
adrRelasi findRelasiByPenumpang(listRelasi L, adrPenumpang C);

int countPenumpangDariBis(listRelasi L, adrBis P);
int countBisDariPenumpang(listRelasi L, adrPenumpang C);
int countBisTanpaPenumpang(listRelasi L, listBis LB);
int countPenumpangTanpaBis(listRelasi L, listPenumpang LP);

void editRelasi(listRelasi &L, adrBis oldBus, adrPenumpang C, adrBis newBus);

#endif // RELATION_H_INCLUDED
