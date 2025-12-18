#include <iostream>
#include "main.h"
using namespace std;

void menuAdmin(listBis &LB, listPenumpang &LP, listRelasi &LR){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU ADMIN =====\n";
        cout << "1. Data Bis\n";
        cout << "2. Data Penumpang\n";
        cout << "3. Relasi\n";
        cout << "0. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

        if(pilih == 1){
            menuBis(LB);
        }
        else if(pilih == 2){
            menuPenumpang(LP);
        }
        else if(pilih == 3){
            menuRelasi(LB, LP, LR);
        }
    }
}

/* ================= MENU BIS ================= */

void menuBis(listBis &LB){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU BIS =====\n";
        cout << "1. Insert First Bis\n";
        cout << "2. Insert Last Bis\n";
        cout << "3. Insert After Bis\n";
        cout << "4. Delete First Bis\n";
        cout << "5. Delete Last Bis\n";
        cout << "6. Delete After Bis\n";
        cout << "7. Find Bis\n";
        cout << "8. Show All Bis\n";
        cout << "0. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

        if(pilih == 1 || pilih == 2){
            Bis x;
            cout << "Nama Bis  : "; cin >> x.namaBis;
            cout << "Rute      : "; cin >> x.rute;
            cout << "Kapasitas : "; cin >> x.kapasitas;

            if(pilih == 1) insertFirst(LB, createElement(x));
            else insertLast(LB, createElement(x));
        }

        else if(pilih == 3){
            string nama;
            cout << "Sisip setelah bis: ";
            cin >> nama;
            adrBis prec = findBis(LB, nama);
            if(prec){
                Bis x;
                cout << "Nama Bis Baru  : "; cin >> x.namaBis;
                cout << "Rute           : "; cin >> x.rute;
                cout << "Kapasitas      : "; cin >> x.kapasitas;
                insertAfter(LB, prec, createElement(x));
            } else cout << "Bis tidak ditemukan\n";
            system("pause");
        }

        else if(pilih == 4){
            adrBis P;
            deleteFirst(LB, P);
            system("pause");
        }

        else if(pilih == 5){
            adrBis P;
            deleteLast(LB, P);
            system("pause");
        }

        else if(pilih == 6){
            string nama;
            cout << "Delete setelah bis: ";
            cin >> nama;
            adrBis prec = findBis(LB, nama);
            if(prec){
                adrBis P;
                deleteAfter(LB, prec, P);
            } else cout << "Bis tidak ditemukan\n";
            system("pause");
        }

        else if(pilih == 7){
            string nama;
            cout << "Cari Bis: ";
            cin >> nama;
            adrBis P = findBis(LB, nama);
            if(P){
                cout << "Nama     : " << P->info.namaBis << endl;
                cout << "Rute     : " << P->info.rute << endl;
                cout << "Kapasitas: " << P->info.kapasitas << endl;
            } else cout << "Bis tidak ditemukan\n";
            system("pause");
        }

        else if(pilih == 8){
            showAllBis(LB);
            system("pause");
        }
    }
}


/* ================= MENU PENUMPANG ================= */

void menuPenumpang(listPenumpang &LP){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU PENUMPANG =====\n";
        cout << "1. Insert First Penumpang\n";
        cout << "2. Insert Last Penumpang\n";
        cout << "3. Insert After Penumpang\n";
        cout << "4. Delete First Penumpang\n";
        cout << "5. Delete Last Penumpang\n";
        cout << "6. Delete After Penumpang\n";
        cout << "7. Find Penumpang\n";
        cout << "8. Show Penumpang\n";
        cout << "0. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

        if(pilih == 1 || pilih == 2){
            Penumpang x;
            cout << "Nama   : "; cin >> x.nama;
            cout << "Tujuan : "; cin >> x.tujuan;

            if(pilih == 1) insertFirstPenumpang(LP, createElmPenumpang(x));
            else insertLastPenumpang(LP, createElmPenumpang(x));
        }

        else if(pilih == 3){
            string nama;
            cout << "Sisip setelah penumpang: ";
            cin >> nama;
            adrPenumpang prec = findPenumpang(LP, nama);
            if(prec){
                Penumpang x;
                cout << "Nama   : "; cin >> x.nama;
                cout << "Tujuan : "; cin >> x.tujuan;
                insertAfterPenumpang(LP, prec, createElmPenumpang(x));
            } else cout << "Penumpang tidak ditemukan\n";
            system("pause");
        }

        else if(pilih == 4){
            adrPenumpang P;
            deleteFirstPenumpang(LP, P);
            system("pause");
        }

        else if(pilih == 5){
            adrPenumpang P;
            deleteLastPenumpang(LP, P);
            system("pause");
        }

        else if(pilih == 6){
            string nama;
            cout << "Delete setelah penumpang: ";
            cin >> nama;
            adrPenumpang prec = findPenumpang(LP, nama);
            if(prec){
                adrPenumpang P;
                deleteAfterPenumpang(LP, prec, P);
            } else cout << "Penumpang tidak ditemukan\n";
            system("pause");
        }

        else if(pilih == 7){
            string nama;
            cout << "Cari Penumpang: ";
            cin >> nama;
            adrPenumpang P = findPenumpang(LP, nama);
            if(P){
                cout << "Nama   : " << P->info.nama << endl;
                cout << "Tujuan : " << P->info.tujuan << endl;
            } else cout << "Penumpang tidak ditemukan\n";
            system("pause");
        }

        else if(pilih == 8){
            showPenumpang(LP);
            system("pause");
        }
    }
}


/* ================= MENU RELASI ================= */

void menuRelasi(listBis &LB, listPenumpang &LP, listRelasi &LR){
    int pilih = -1;

    while(pilih != 0){
        system("cls");
        cout << "===== MENU RELASI =====\n";
        cout << "1. Insert First Relasi\n";
        cout << "2. Insert Last Relasi\n";
        cout << "3. Insert After Relasi\n";
        cout << "4. Delete First Relasi\n";
        cout << "5. Delete Last Relasi\n";
        cout << "6. Delete After Relasi\n";
        cout << "7. Edit Relasi\n";
        cout << "8. Find Relasi by Bis\n";
        cout << "9. Find Relasi by Penumpang\n";
        cout << "10. Show All Relasi\n";
        cout << "11. Show Penumpang dari Bis\n";
        cout << "12. Show Bis dari Penumpang\n";
        cout << "13. Count Penumpang dari Bis\n";
        cout << "14. Count Bis dari Penumpang\n";
        cout << "15. Count Bis tanpa Penumpang\n";
        cout << "16. Count Penumpang tanpa Bis\n";
        cout << "0. Back\n";
        cout << "Pilih: ";
        cin >> pilih;

       /* ================= INSERT RELASI ================= */

    if(pilih >= 1 && pilih <= 3){
        string nb, np;
        cout << "Nama Bis       : "; cin >> nb;
        cout << "Nama Penumpang : "; cin >> np;

        adrBis B = findBis(LB, nb);
        adrPenumpang P = findPenumpang(LP, np);

        if(B != nullptr && P != nullptr){

            int jumlahBisPenumpang   = countBisDariPenumpang(LR, P);
            int jumlahPenumpangDiBis = countPenumpangDariBis(LR, B);

            if(jumlahBisPenumpang > 0){
                cout << " Penumpang sudah naik bis lain!\n";
            }
            else if(jumlahPenumpangDiBis >= B->info.kapasitas){
                cout << " Bis penuh!\n";
            }
            else if(P->info.tujuan != B->info.rute){
                cout << " Tujuan penumpang TIDAK sesuai dengan rute bis\n";
                cout << " Rekomendasi bis tujuan \"" << P->info.tujuan << "\":\n";

                adrBis Q = LB.first;
                bool ada = false;

                while(Q != nullptr){
                    if(Q->info.rute == P->info.tujuan &&
                       countPenumpangDariBis(LR, Q) < Q->info.kapasitas){

                        cout << "- " << Q->info.namaBis
                             << " (Sisa kursi: "
                             << Q->info.kapasitas - countPenumpangDariBis(LR, Q)
                             << ")\n";
                        ada = true;
                    }
                    Q = Q->next;
                }

                if(!ada){
                    cout << " Tidak ada bis yang tersedia untuk tujuan tersebut\n";
                }
            }
            else{
                adrRelasi R = createElmRelasi(B, P);

                if(pilih == 1){
                    insertFirstRelasi(LR, R);
                }
                else if(pilih == 2){
                    insertLastRelasi(LR, R);
                }
                else if(pilih == 3){
                    string nb2;
                    cout << "Insert setelah relasi dengan bis: ";
                    cin >> nb2;
                    adrRelasi prec = findRelasiByBis(LR, findBis(LB, nb2));
                    if(prec != nullptr){
                        insertAfterRelasi(LR, prec, R);
                    } else {
                        cout << "Relasi tidak ditemukan\n";
                        delete R;
                    }
                }

                cout << " Penumpang berhasil naik bis\n";
            }
        }
        else{
            cout << " Bis atau Penumpang tidak ditemukan\n";
        }

        system("pause");
    }


        /* ================= DELETE ================= */
        else if(pilih == 4){
            adrRelasi R;
            deleteFirstRelasi(LR, R);
            cout << "Relasi pertama dihapus\n";
            system("pause");
        }
        else if(pilih == 5){
            adrRelasi R;
            deleteLastRelasi(LR, R);
            cout << "Relasi terakhir dihapus\n";
            system("pause");
        }
        else if(pilih == 6){
            string nb;
            cout << "Delete setelah relasi bis: ";
            cin >> nb;
            adrRelasi prec = findRelasiByBis(LR, findBis(LB, nb));
            if(prec != nullptr){
                adrRelasi R;
                deleteAfterRelasi(LR, prec, R);
                cout << "Relasi berhasil dihapus\n";
            } else {
                cout << "Relasi tidak ditemukan\n";
            }
            system("pause");
        }

        /* ================= EDIT ================= */

        else if(pilih == 7){
            string bLama, p, bBaru;
            cout << "Bis Lama  : "; cin >> bLama;
            cout << "Penumpang : "; cin >> p;
            cout << "Bis Baru  : "; cin >> bBaru;

            adrBis bisLama = findBis(LB, bLama);
            adrPenumpang pen = findPenumpang(LP, p);
            adrBis bisBaru = findBis(LB, bBaru);

            if(bisLama && pen && bisBaru){

                int jumlahPenumpangBisBaru = countPenumpangDariBis(LR, bisBaru);

                if(bisBaru->info.rute != pen->info.tujuan){
                    cout << " Tujuan penumpang tidak sesuai dengan rute bis baru\n";
                }
                else if(jumlahPenumpangBisBaru >= bisBaru->info.kapasitas){
                    cout << " Bis tujuan penuh! Kapasitas: "
                         << bisBaru->info.kapasitas << endl;
                }
                else{
                    editRelasi(LR, bisLama, pen, bisBaru);
                    cout << " Relasi berhasil diedit\n";
                }
            }
            else{
                cout << " Data tidak ditemukan\n";
            }

            system("pause");
        }


        /* ================= FIND ================= */
        else if(pilih == 8){
            string nb;
            cout << "Cari relasi bis: ";
            cin >> nb;
            adrRelasi R = findRelasiByBis(LR, findBis(LB, nb));
            if(R){
                cout << "Bis       : " << R->parent->info.namaBis << endl;
                cout << "Penumpang : " << R->child->info.nama << endl;
            } else cout << "Relasi tidak ditemukan\n";
            system("pause");
        }
        else if(pilih == 9){
            string np;
            cout << "Cari relasi penumpang: ";
            cin >> np;
            adrRelasi R = findRelasiByPenumpang(LR, findPenumpang(LP, np));
            if(R){
                cout << "Penumpang : " << R->child->info.nama << endl;
                cout << "Bis       : " << R->parent->info.namaBis << endl;
            } else cout << "Relasi tidak ditemukan\n";
            system("pause");
        }

        /* ================= SHOW & COUNT ================= */
        else if(pilih == 10){
            showAllRelasi(LR);
            system("pause");
        }
        else if(pilih == 11){
            string nb;
            cout << "Nama Bis: "; cin >> nb;
            showPenumpangDariBis(LR, findBis(LB, nb));
            system("pause");
        }
        else if(pilih == 12){
            string np;
            cout << "Nama Penumpang: "; cin >> np;
            showBisDariPenumpang(LR, findPenumpang(LP, np));
            system("pause");
        }
        else if(pilih == 13){
            string nb;
            cout << "Nama Bis: "; cin >> nb;
            cout << "Jumlah Penumpang: "
                 << countPenumpangDariBis(LR, findBis(LB, nb)) << endl;
            system("pause");
        }
        else if(pilih == 14){
            string np;
            cout << "Nama Penumpang: "; cin >> np;
            cout << "Jumlah Bis: "
                 << countBisDariPenumpang(LR, findPenumpang(LP, np)) << endl;
            system("pause");
        }
        else if(pilih == 15){
            cout << "Bis tanpa penumpang: "
                 << countBisTanpaPenumpang(LR, LB) << endl;
            system("pause");
        }
        else if(pilih == 16){
            cout << "Penumpang tanpa bis: "
                 << countPenumpangTanpaBis(LR, LP) << endl;
            system("pause");
        }
    }
}
