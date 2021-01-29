#include <iostream>

using namespace std;

#include "3_automat.h"

//3.uloha
Automat::Automat(const int vlastnosti[], int numberOfRows) {
    if (numberOfRows != 7){ //ak nam nesedi velkost array
        return;
    }
    for(int i = 0; i < 7; i++) { // nic nemoze byt nula a menej ako nula
        if (vlastnosti[i] <= 0){
            return;
        }
    }

    je_nastaveny = true;

    //nastavuje clenske premenne
    a_cukor = vlastnosti[0];
    a_kava = vlastnosti[1];
    a_whisky = vlastnosti[2];
    a_bujon = vlastnosti[3];
    a_cokolada = vlastnosti[4];
    a_mlieko = vlastnosti[5];
    a_caj = vlastnosti[6];

    //dynamicky alokuje pole pre vsetky napoje
    napoje = new Napoj[10];
    /*for (int i = 0; i < 10; i++) {
        napoje[i] = new Napoj;
    }*/

}

Automat::Automat(const int cukor, const int kava, const int whisky, const int bujon, const int cokolada, const int mlieko, const int caj){
    int vlastnosti[7];

    vlastnosti[0] = cukor;
    vlastnosti[1] = kava;
    vlastnosti[2] = whisky;
    vlastnosti[3] = bujon;
    vlastnosti[4] = cokolada;
    vlastnosti[5] = mlieko;
    vlastnosti[6] = caj;

    for(int i : vlastnosti) { // nic nemoze byt nula a menej ako nula
        if (i <= 0){
            return;
        }
    }

    je_nastaveny = true;

    //nastavuje clenske premenne
    a_cukor = vlastnosti[0];
    a_kava = vlastnosti[1];
    a_whisky = vlastnosti[2];
    a_bujon = vlastnosti[3];
    a_cokolada = vlastnosti[4];
    a_mlieko = vlastnosti[5];
    a_caj = vlastnosti[6];

    //dynamicky alokuje pole pre vsetky napoje
    napoje = new Napoj[10];
}

Automat::Automat() : Automat(vlastnosti1,7) { // Konštruktor v konštruktore
}

Automat::~Automat() {
    if (napoje == nullptr)
        return;
    /*
    int i;
    for (i=0; i<10; i++){
        delete[] napoje[i];
    }*/
    delete[] napoje;
}

bool Automat::naplnHoKlasicky(){
    if (kolkoNastavenychNapojov() != 0){
        return false;}
    nastavNapoj("kava",4,7,0,0,0,0,0,30,75);
    nastavNapoj("velka kava",4,14,0,0,0,0,0,30,150);
    nastavNapoj("kapucino",4,14,0,0,0,7,0,40,150);
    nastavNapoj("kapucino s cokoladov",4,14,0,0,7,7,0,40,150);
    nastavNapoj("mliecna kava",4,14,0,0,0,7,0,40,150);
    nastavNapoj("kava s cokoladov",4,14,0,0,7,0,0,40,150);
    nastavNapoj("citronovy caj",4,0,0,0,0,0,7,30,150);
    nastavNapoj("cokolada",4,0,0,0,7,7,0,40,150);
    nastavNapoj("irish cream",4,14,0,7,0,7,0,40,150);
    nastavNapoj("polievka",0,0,7,0,0,0,0,40,150);

    return true;
}

void Automat::naplnHoKlasicky2(){
    //if (kolkoNastavenychNapojov() != 0){
      //  return false;}
    a_patcentov = 9;
    a_desatcentov = 9;
    a_dvadsatcentov = 9;
    a_patdesiatcentov = 9;
    a_euro = 9;
    a_dvaeura = 9;

    //return true;
}

string Automat::vratMiNazovNapoja(int index) const{
    if (index > 9){
        return "";
    }
    if (index + 1 <= kolkoNastavenychNapojov()){
        return napoje[index].menoNapoja();}
    return "";
}

int Automat::kolkoNapojov() const{
    if (je_nastaveny){return 10;}
    return 0;
}

int Automat::kolkoNastavenychNapojov() const{
    if (kolkoNapojov() == 0){
        return -999;
    }
    int pocitadlo = 0;
    for(int i = 0; i < 10; i++) {
        if (napoje[i].jeNastaveny()){
            pocitadlo++;
        }
    }
    return pocitadlo;
}

int Automat::kolkoNenastavenychNapojov() const{
    if (kolkoNapojov() == 0){
        return -999;
    }
    int pocitadlo = 0;
    for(int i = 0; i < 10; i++) {
        if (!napoje[i].jeNastaveny()){
            pocitadlo++;
        }
    }
    return pocitadlo;
}

bool Automat::nastavNapoj(const string &nazov1, const int vlastnosti2[], int numberOfRows){
    if (vratNapoj() == nullptr){
        return false;
    }
    return vratNapoj()->nastavitNapoj(nazov1, vlastnosti2, numberOfRows);
}

bool Automat::nastavNapoj(const string &nazovNapoja, const int cukor, const int kava, const int bujon, const int whisky, const int cokolada, const int mlieko, const int caj, const int cena, const int objem){
    if (vratNapoj() == nullptr){
        return false;
    }
    return vratNapoj()->nastavitNapoj(nazovNapoja, cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem);
}

int Automat::vratMnozstvoSuroviny(int index) const {
    switch (index) {
        case 0:
            return a_cukor;
        case 1:
            return a_kava;
        case 2:
            return a_whisky;
        case 3:
            return a_bujon;
        case 4:
            return a_cokolada;
        case 5:
            return a_mlieko;
        case 6:
            return a_caj;
        default:
            return -999;
    }
}

int Automat::vratMnozstvoSuroviny(const string &nazov) const {
    if (nazov == "cukor"){
        return a_cukor;}
    else if (nazov == "kava"){
        return a_kava;}
    else if (nazov == "whisky"){
        return a_whisky;}
    else if (nazov == "bujon"){
        return a_bujon;}
    else if (nazov == "cokolada"){
        return a_cokolada;}
    else if (nazov == "mlieko"){
        return a_mlieko;}
    else if (nazov == "caj"){
        return a_caj;}
    else {
        return -999;
    }
}

Napoj * Automat::vratNapoj() const {
    for(int i = 0; i < 10; i++) {
        if (!napoje[i].jeNastaveny()){
            return &napoje[i];
        }
    }
   /* Napoj *napoj = new Napoj;
    return napoj;*/
    return nullptr;
}

Napoj * Automat::vratNapoj(int index) const{
    if (index > 9){
        return nullptr;
    }
    if (index + 1 <= kolkoNastavenychNapojov()){
        return &napoje[index];
    }
    return nullptr;
}

int Automat::vratMnozstvoMinci(string &minca) {
    if (minca == "5c") {return a_patcentov;}
    if (minca == "10c") {return a_desatcentov;}
    if (minca == "50c") {return a_patdesiatcentov;}
    if (minca == "1€") {return a_euro;}
    if (minca == "2€") {return a_dvaeura;}
    return -999;
}

int Automat::vratZostatokVAtomate(){
    return minceNaSumu(a_patcentov,a_desatcentov,a_dvadsatcentov,a_patdesiatcentov,a_euro,a_dvaeura);
}

void Automat::nastavMince(int patcentov, int desatcentov, int dvadsatcentov, int patdesiatcentov, int euro, int dvaeura){
    if ((patcentov >= 0) && (desatcentov >= 0) && (dvadsatcentov >= 0) && (patdesiatcentov >= 0) && (euro >= 0) && (dvaeura >= 0)){
        a_patcentov = patcentov;
        a_desatcentov = desatcentov;
        a_dvadsatcentov = dvadsatcentov;
        a_patdesiatcentov = patdesiatcentov;
        a_euro = euro;
        a_dvaeura = dvaeura;
    }
}

bool Automat::viemOdratat(const int mince[6]) {
    int d_patcentov = a_patcentov;
    int d_desatcentov = a_desatcentov;
    int d_dvadsatcentov = a_dvadsatcentov;
    int d_patdesiatcentov = a_patdesiatcentov;
    int d_euro = a_euro;
    int d_dvaeura = a_dvaeura;

    if((d_patcentov - mince[0] < 0) || (d_desatcentov  - mince[1] < 0) || (d_dvadsatcentov  - mince[2] < 0)
       || (d_patdesiatcentov  - mince[3] < 0) || (d_euro  - mince[4] < 0) || (d_dvaeura  - mince[5] < 0)){
        return false;
    }
    return true;
}

bool Automat::viemOdratat2(const int mince2[6], const int mince[6]) {
    int d_patcentov = mince2[0];
    int d_desatcentov = mince2[1];
    int d_dvadsatcentov = mince2[2];
    int d_patdesiatcentov = mince2[3];
    int d_euro = mince2[4];
    int d_dvaeura = mince2[5];

    if((d_patcentov - mince[0] < 0) || (d_desatcentov  - mince[1] < 0) || (d_dvadsatcentov  - mince[2] < 0)
       || (d_patdesiatcentov  - mince[3] < 0) || (d_euro  - mince[4] < 0) || (d_dvaeura  - mince[5] < 0)){
        return false;
    }
    return true;
}

void Automat::odrataj(const int mince[6]) {
    a_patcentov -= mince[0];
    a_desatcentov -= mince[1];
    a_dvadsatcentov -= mince[2];
    a_patdesiatcentov -= mince[3];
    a_euro -= mince[4];
    a_dvaeura -= mince[5];
}
