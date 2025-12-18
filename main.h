#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "bis.h"
#include "penumpang.h"
#include "relation.h"

void menuAdmin(listBis &LB, listPenumpang &LP, listRelasi &LR);
void menuUser(listBis &LB, listPenumpang &LP, listRelasi &LR);

void menuBis(listBis &LB);
void menuPenumpang(listPenumpang &LP);
void menuRelasi(listBis &LB, listPenumpang &LP, listRelasi &LR);

void initDummyData(listBis &LB, listPenumpang &LP, listRelasi &LR);

#endif
