#include <iostream>
#include "relation.h"
using namespace std;

void createListRelasi(listRelasi &L){
    L.first = nullptr;
    L.last = nullptr;
}
adrRelasi createElmRelasi(adrBis P, adrPenumpang C){
    adrRelasi R = new elmRelasi;
    R->parent = P;
    R->child = C;
    R->next = nullptr;
    R->prev = nullptr;
    return R;
}

void insertFirstRelasi(listRelasi &L, adrRelasi R){
    if(L.first == nullptr){
        L.first = R;
        L.last = R;
    } else {
        R->next = L.first;
        L.first->prev = R;
        L.first = R;
    }
}

void insertLastRelasi(listRelasi &L, adrRelasi R){
    if(L.first == nullptr){
        L.first = R;
        L.last = R;
    } else {
        L.last->next = R;
        R->prev = L.last;
        L.last = R;
    }
}

void insertAfterRelasi(listRelasi &L, adrRelasi Prec, adrRelasi R){
    if(Prec != nullptr){
        R->next = Prec->next;
        R->prev = Prec;

        if(Prec->next != NULL){
            Prec->next->prev = R;
        } else {
            L.last = R;
        }

        Prec->next = R;
    }
}

void deleteFirstRelasi(listRelasi &L, adrRelasi &R){
    R = L.first;
    if(R != nullptr){
        if(L.first == L.last){
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = R->next;
            L.first->prev = nullptr;
        }
        R->next = nullptr;
        R->prev = nullptr;
    }
}

void deleteLastRelasi(listRelasi &L, adrRelasi &R){
    R = L.last;
    if(R != nullptr){
        if(L.first == L.last){
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.last = R->prev;
            L.last->next = nullptr;
        }
        R->next = nullptr;
        R->prev = nullptr;
    }
}

void deleteAfterRelasi(listRelasi &L, adrRelasi Prec, adrRelasi &R){
    if(Prec != nullptr){
        R = Prec->next;
        if(R != nullptr){
            Prec->next = R->next;

            if(R->next != nullptr){
                R->next->prev = Prec;
            } else {
                L.last = Prec;
            }

            R->next = nullptr;
            R->prev = nullptr;
        }
    }
}

adrRelasi findRelasiByPenumpang(listRelasi L, adrPenumpang C){
    adrRelasi R = L.first;
    while(R != nullptr){
        if(R->child == C){
            return R;
        }
        R = R->next;
    }
    return nullptr;
}

adrRelasi findRelasiByBis(listRelasi L, adrBis P){
    adrRelasi R = L.first;
    while(R != nullptr){
        if(R->parent == P){
            return R;
        }
        R = R->next;
    }
    return nullptr;
}


void showPenumpangDariBis(listRelasi L, adrBis P){
    adrRelasi R = L.first;
    cout << "Penumpang dari Bis " << P->info.namaBis << ":\n";
    while(R != nullptr){
        if(R->parent == P){
            cout << "- " << R->child->info.nama << " (Tujuan: " << R->child->info.tujuan << ")\n";
        }
        R = R->next;
    }
}

void showBisDariPenumpang(listRelasi L, adrPenumpang C){
    adrRelasi R = L.first;
    cout << "Bis yang dinaiki " << C->info.nama << ":\n";
    while(R != nullptr){
        if(R->child == C){
            cout << "- " << R->parent->info.namaBis << "\n";
        }
        R = R->next;
    }
}

void showAllRelasi(listRelasi L){
    adrRelasi R = L.first;
    while(R != nullptr){
        cout << "[Bis: " << R->parent->info.namaBis
             << " -> Penumpang: " << R->child->info.nama << "]\n";
        R = R->next;
    }
}

int countPenumpangDariBis(listRelasi L, adrBis P){
    adrRelasi R = L.first;
    int count = 0;
    while(R != nullptr){
        if(R->parent == P){
            count = count + 1;
        }
        R = R->next;
    }
    return count;
}

int countBisDariPenumpang(listRelasi L, adrPenumpang C){
    adrRelasi R = L.first;
    int count = 0;
    while(R != nullptr){
        if(R->child == C){
            count = count + 1;
        }
        R = R->next;
    }
    return count;
}

int countBisTanpaPenumpang(listRelasi L, listBis LB){
    adrBis P = LB.first;
    int count = 0;

    while(P != nullptr){
        int ada = 0;
        adrRelasi R = L.first;

        while(R != nullptr){
            if(R->parent == P){
                ada = 1;
            }
            R = R->next;
        }

        if(ada == 0){
            count = count + 1;
        }

        P = P->next;
    }

    return count;
}

int countPenumpangTanpaBis(listRelasi L, listPenumpang LP){
    adrPenumpang C = LP.first;
    int count = 0;

    while(C != nullptr){
        int ada = 0;
        adrRelasi R = L.first;

        while(R != nullptr){
            if(R->child == C){
                ada = 1;
            }
            R = R->next;
        }

        if(ada == 0){
            count = count + 1;
        }

        C = C->next;
    }

    return count;
}

void editRelasi(listRelasi &L, adrBis oldBus, adrPenumpang C, adrBis newBus) {
    if (L.first == nullptr) {
        cout << "List relasi kosong.\n";
        return;
    }

    adrRelasi R = L.first;
    bool found = false;

    while (R != nullptr && found == false) {
        if (R->parent == oldBus && R->child == C) {
            found = true;
        } else {
            R = R->next;
        }
    }

    if (found == false) {
        cout << "Relasi tidak ditemukan.\n";
        return;
    }

    adrRelasi temp;
    if (R == L.first) {
        deleteFirstRelasi(L, temp);
    } else if (R->next == nullptr) {
        deleteLastRelasi(L, temp);
    } else {
        deleteAfterRelasi(L, R->prev, temp);
    }

    adrRelasi baru = createElmRelasi(newBus, C);
    insertLastRelasi(L, baru);

    cout << "Relasi berhasil diedit.\n";
}
