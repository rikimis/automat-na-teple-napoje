#include <iostream>

using namespace std;

#include "3_automat.h"

int Automat::minceNaSumu(int patcentov, int desatcentov, int dvadsatcentov, int patdesiatcentov, int euro, int dvaeura){
    int suma = 0;
    if ((patcentov >= 0) && (desatcentov >= 0) && (dvadsatcentov >= 0) && (patdesiatcentov >= 0) && (euro >= 0) && (dvaeura >= 0)){
        suma = ((patcentov * 5) + (desatcentov * 10) + (dvadsatcentov * 20) + (patdesiatcentov * 50) + (euro * 100) + (dvaeura * 200));
    }
    return suma;
}

void Automat::minceNaZoznam(int patcentov, int desatcentov, int dvadsatcentov, int patdesiatcentov, int euro, int dvaeura ,int zoznam[]){
    //int zoznam[6] = {0,0,0,0,0,0};
    if ((patcentov >= 0) && (desatcentov >= 0) && (dvadsatcentov >= 0) && (patdesiatcentov >= 0) && (euro >= 0) && (dvaeura >= 0)){
        zoznam[0] = patcentov;
        zoznam[1] = desatcentov;
        zoznam[2] = dvadsatcentov;
        zoznam[3] = patdesiatcentov;
        zoznam[4] = euro;
        zoznam[5] = dvaeura;
    } else {
        zoznam[0] = 0;
        zoznam[1] = 0;
        zoznam[2] = 0;
        zoznam[3] = 0;
        zoznam[4] = 0;
        zoznam[5] = 0;
    }
}

bool Automat::viemeVyrobitNapoj(int indexNapoja, const string &extraCukorAboZiadny){
    if (kolkoNapojov() != 10){
        return false;
    }
    if ((indexNapoja > 9) || (indexNapoja < 0)){
        return false;
    }
    if (indexNapoja + 1 <= kolkoNastavenychNapojov()){

        Napoj* n = vratNapoj(indexNapoja);
        if (!n->jeNastaveny()){return false;}

        int c_cukor = a_cukor;int c_kava = a_kava;
        int c_whisky = a_whisky;int c_bujon = a_bujon;
        int c_cokolada = a_cokolada;int c_mlieko = a_mlieko;
        int c_caj = a_caj;

        int p_cukor = n->vratMnozstvoSurovinyN(0);

        if (extraCukorAboZiadny == "ano"){ //extra cukor
            p_cukor += 2;
        }

        if (extraCukorAboZiadny == "nie"){ //ziadny cukor
            p_cukor = 0;
        }

        int p_kava = n->vratMnozstvoSurovinyN(1);
        int p_whisky = n->vratMnozstvoSurovinyN(2);
        int p_bujon = n->vratMnozstvoSurovinyN(3);
        int p_cokolada = n->vratMnozstvoSurovinyN(4);
        int p_mlieko = n->vratMnozstvoSurovinyN(5);
        int p_caj = n->vratMnozstvoSurovinyN(6);

        if ((c_cukor - p_cukor >= 0) && (c_kava - p_kava >= 0) && (c_whisky - p_whisky >= 0) && (c_bujon - p_bujon >= 0) &&
            (c_cokolada - p_cokolada >= 0) && (c_mlieko - p_mlieko >= 0) && (c_caj - p_caj >= 0)){
            return true;
        }
        return false;
    }
    return false;
}

void Automat::odratajSurovinyZAutomatu(int indexNapoja, const string &extraCukorAboZiadny){

        Napoj* n = vratNapoj(indexNapoja);

        int p_cukor = n->vratMnozstvoSurovinyN(0);
        if (extraCukorAboZiadny == "ano"){p_cukor += 2;}
        if (extraCukorAboZiadny == "nie"){p_cukor = 0;}
        int p_kava = n->vratMnozstvoSurovinyN(1);
        int p_whisky = n->vratMnozstvoSurovinyN(2);
        int p_bujon = n->vratMnozstvoSurovinyN(3);
        int p_cokolada = n->vratMnozstvoSurovinyN(4);
        int p_mlieko = n->vratMnozstvoSurovinyN(5);
        int p_caj = n->vratMnozstvoSurovinyN(6);

        int c_cukor = a_cukor;int c_kava = a_kava;int c_whisky = a_whisky;int c_bujon = a_bujon;
        int c_cokolada = a_cokolada;int c_mlieko = a_mlieko;int c_caj = a_caj;

        this->a_cukor = c_cukor - p_cukor;
        this->a_kava = c_kava - p_kava;
        this->a_whisky = c_whisky - p_whisky;
        this->a_bujon = c_bujon - p_bujon;
        this->a_cokolada = c_cokolada - p_cokolada;
        this->a_mlieko = c_mlieko - p_mlieko;
        this->a_caj = c_caj - p_caj;
}