#pragma once

//1.uloha

enum TypNapoja { WRONG_TYPE, NAPOJ };
const string TypNapoja_s[] {"Napoj_nenastaveny", "Napoj"};

class Napojn { //Nenastaveny napoj (prázdne políčko)
    string nazov; //nazov napoja
    // aké suroviny potrebuje na 1ks
    /*
     ... ak tam bude 0 znamena to že to nepotrebuje
     ... cena ani velkost nemoze byt nula (6 a 7)
     
     0 = cukor, standarna porcia 4g
     1 = kava, pomleta, standarna porcia 7g
     2 = bujon, resp. vegeta, standarna porcia ?g
     3 = whisky, esencia, standarna porcia ?g
     4 = cokolada praskova, standarna porcia ?g
     5 = mlieko, susene, standarna porcia ?g
     6 = caj
     7 = cena v centoch
     8 = velkost v ml (150ml / 75ml) ...velke / male ...(objem nápoja).tu asi max 150ml kvoli poharu

     */

public:
    bool jeNastaveny() const ;
    bool nastavitNapoj(const string &nazov1, const int *vlastnosti1, int numberOfRows);
    bool nastavitNapoj(const string &nazovNapoja, int cukor, int kava, int bujon, int whisky, int cokolada, int mlieko, int caj, int cena, int objem);
    string menoNapoja() const ;
    virtual TypNapoja vratTypNapoja() const { return WRONG_TYPE;};
    virtual string vratTypNapojaMeno() const { return TypNapoja_s[WRONG_TYPE];};

    bool resetniNapoj();
    virtual int vratMnozstvoSurovinyN(int index) const { return WRONG_TYPE;};

    int vlastnosti[9];
};

class Napoj : public Napojn {
public:
    TypNapoja vratTypNapoja() const override ;
    string vratTypNapojaMeno() const override;
    int vratMnozstvoSurovinyN(int index) const override;
};


const string DUMMY_STRING = "";
const int DUMMY_INT = -999;
const bool DUMMY_BOOL = false;
