#include <iostream>
#include <cstring>  /* strcpy */

using namespace std;

#include "1_napoj.h"

//1.uloha
bool Napojn::jeNastaveny() const {
    if (nazov.empty()){
        return false;
    }
    return true;
}

bool Napojn::nastavitNapoj(const string &nazov1, const int *vlastnosti1, int numberOfRows) {
  if (numberOfRows != 9){ //ak nam nesedi velkost array
      return false;
  }
  if (nazov1.empty()){ //ak je prazdny nazov napoja
      return false;
  }
  if ((vlastnosti1[7] <= 0) || (vlastnosti1[8] <= 0)){
      return false; //cena ani velkost nemoze byt nula (index 7 a 8)
  }
  for(int i = 0; i < 9; i++) { // nic nemoze byt menej ako nula
      if (vlastnosti1[i] < 0){
          return false;
      }
  }
  //string v type int asi nemusim kontrolovat
  nazov = nazov1;
  for(int i = 0; i < 9; i++) {
      vlastnosti[i] = vlastnosti1[i];
    }
  return true;
}

bool Napojn::nastavitNapoj(const string &nazovNapoja, const int cukor, const int kava, const int bujon, const int whisky, const int cokolada, const int mlieko, const int caj, const int cena, const int objem) {
    int vlastnosti1[9];

    vlastnosti1[0] = cukor;
    vlastnosti1[1] = kava;
    vlastnosti1[2] = bujon;
    vlastnosti1[3] = whisky;
    vlastnosti1[4] = cokolada;
    vlastnosti1[5] = mlieko;
    vlastnosti1[6] = caj;
    vlastnosti1[7] = cena;
    vlastnosti1[8] = objem;


    if (nazovNapoja.empty()){ //ak je prazdny nazov napoja
        return false;
    }
    if ((vlastnosti1[7] <= 0) || (vlastnosti1[8] <= 0)){
        return false; //cena ani velkost nemoze byt nula (index 7 a 8)
    }
    for(int i : vlastnosti1) { // nic nemoze byt menej ako nula
        if (i < 0){
            return false;
        }
    }
    //string v type int asi nemusim kontrolovat
    nazov = nazovNapoja;
    for(int i = 0; i < 9; i++) {
        vlastnosti[i] = vlastnosti1[i];
    }
    return true;
}

string Napojn::menoNapoja() const { // vrati string (nazov napoja)
    if (nazov.empty()){
        return "";
    }
    return nazov;
}

TypNapoja Napoj::vratTypNapoja() const {
    return NAPOJ;
}

string Napoj::vratTypNapojaMeno() const {
    return "Napoj";
}

int Napoj::vratMnozstvoSurovinyN(int index) const {
    if (jeNastaveny() && index <= 9){
        return vlastnosti[index];
    }
    return 0;
}