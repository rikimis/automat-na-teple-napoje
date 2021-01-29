// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

using namespace ::testing;

#include "1_napoj.h"
#include "3_automat.h"

TEST(TestThirdTask, automat) {
    //0cukor, 1kava, 2bujon, 3whisky, 4cokolada, 5mlieko, 6caj
    int v[7] = {1000,1000,1000,1000,1000,1000,1000}; //v gramoch
	Automat mojAutomat(v,7);
	ASSERT_EQ(10, mojAutomat.kolkoNapojov());
}

TEST(TestThirdTask, kratsiArray) {
    //0cukor, 1kava, 2bujon, 3whisky, 4cokolada, 5mlieko, 6caj
    int v[6] = {1000,1000,1000,1000,1000,1000}; //v gramoch
    Automat mojAutomat(v,6);
    ASSERT_EQ(0, mojAutomat.kolkoNapojov());
}

TEST(TestThirdTask, minusVsurovinach) {
    Automat mojAutomat(1000,1000,1000,1000,1000,1000,-1000);
    ASSERT_EQ(0, mojAutomat.kolkoNapojov());
}

TEST(TestThirdTask, automat2) {
    Automat mojAutomat(1000,1000,1000,1000,1000,1000,1000); //alebo iba Automat mojAutomat;
    ASSERT_EQ(10, mojAutomat.kolkoNapojov());
}

TEST(TestThirdTask, automat2minus) {
    Automat mojAutomat(1000,1000,1000,1000,1000,1000,-1000);
    ASSERT_EQ(0, mojAutomat.kolkoNapojov());
}

TEST(TestThirdTask, automat1) {
    Automat mojAutomat; //standardne ja všetko max. 1000 g
    ASSERT_EQ(10, mojAutomat.kolkoNapojov());
}


TEST(TestThirdTask, automatKolkuCukru) {
    Automat mojAutomat(2000,1000,1000,1000,1000,1000,1000);
    ASSERT_EQ(2000, mojAutomat.vratMnozstvoSuroviny(0));
}

TEST(TestThirdTask, automatKolkuCukru1) {
    Automat mojAutomat;
    //0cukor, 1kava, 2bujon, 3whisky, 4cokolada, 5mlieko, 6caj
    ASSERT_EQ(1000, mojAutomat.vratMnozstvoSuroviny(0));
}

TEST(TestThirdTask, automatKolkuCukru2) {
    Automat mojAutomat(1000,1000,1000,1000,1000,1000,1000); //alebo iba Automat mojAutomat;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj
    ASSERT_EQ(1000, mojAutomat.vratMnozstvoSuroviny("cukor"));
}

TEST(TestThirdTask, automatKolkuCukru3) {
    Automat mojAutomat;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj
    ASSERT_EQ(-999, mojAutomat.vratMnozstvoSuroviny("cukorrrrrr"));
}

TEST(TestThirdTask, 10xnapoj) {
    Automat mojAutomat(1000,1000,1000,1000,1000,1000,1000); //alebo iba Automat mojAutomat;
    //0cukor, 1kava, 2bujon, 3whisky, 4cokolada, 5mlieko, 6caj
    int vlastnosti1[9] = {4,7,0,0,0,0,0,30,75}; //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    for(int i = 0; i < 10; i++) {
        ASSERT_TRUE(mojAutomat.nastavNapoj("kava",vlastnosti1,9));
    }
}

TEST(TestThirdTask, 11xnapoj) {
    Automat mojAutomat;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    for(int i = 0; i < 11; i++) {
        if (i == 10){
            ASSERT_FALSE(mojAutomat.nastavNapoj("kava",4,7,0,0,0,0,0,30,75));
        }
        else {
            ASSERT_TRUE(mojAutomat.nastavNapoj("kava",4,7,0,0,0,0,0,30,75));
        }

    }
}

TEST(TestThirdTask, nastavimeFullAutomat10) {
    Automat mojAutomat;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    string nazvy[10] = {"kava","velka kava", "kapucino", "kapucino s cokoladov",
                       "mliecna kava", "kava s cokoladov", "citronovy caj",
                       "cokolada", "irish cream", "polievka"};
    int vlastnosti[10][9] = {{4,7,0,0,0,0,0,30,75},{4,14,0,0,0,0,0,30,150},
                             {4,14,0,0,0,7,0,40,150},{4,14,0,0,7,7,0,40,150},
                             {4,14,0,0,0,7,0,40,150},{4,14,0,0,7,0,0,40,150},
                             {4,0,0,0,0,0,7,30,150},{4,0,0,0,7,7,0,40,150},
                             {4,14,0,7,0,7,0,40,150},{0,0,7,0,0,0,0,40,150}};
    for(int i = 0; i < 10; i++) {
        ASSERT_TRUE(mojAutomat.nastavNapoj(nazvy[i],vlastnosti[i],9));
    }
    ASSERT_EQ("kapucino s cokoladov", mojAutomat.vratMiNazovNapoja(3));
}

TEST(TestThirdTask, nastavimeFullAutomat11) {
    Automat mojAutomat;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    string nazvy[11] = {"kava","velka kava", "kapucino", "kapucino s cokoladov",
                        "mliecna kava", "kava s cokoladov", "citronovy caj",
                        "cokolada", "irish cream", "polievka", "nic"};
    int vlastnosti[11][9] = {{4,7,0,0,0,0,0,30,75},{4,14,0,0,0,0,0,30,150},
                             {4,14,0,0,0,7,0,40,150},{4,14,0,0,7,7,0,40,150},
                             {4,14,0,0,0,7,0,40,150},{4,14,0,0,7,0,0,40,150},
                             {4,0,0,0,0,0,7,30,150},{4,0,0,0,7,7,0,40,150},
                             {4,14,0,7,0,7,0,40,150},{0,0,7,0,0,0,0,40,150},{0,0,7,0,0,0,0,40,150}};
    for(int i = 0; i < 11; i++) {
        if (i == 10){
            ASSERT_FALSE(mojAutomat.nastavNapoj(nazvy[i],vlastnosti[i],9));
        }
        else {
            ASSERT_TRUE(mojAutomat.nastavNapoj(nazvy[i],vlastnosti[i],9));
        }
    }
    ASSERT_EQ(10, mojAutomat.kolkoNastavenychNapojov());
    ASSERT_EQ(0, mojAutomat.kolkoNenastavenychNapojov());
    ASSERT_EQ("mliecna kava", mojAutomat.vratMiNazovNapoja(4));
}

TEST(TestThirdTask, nastavimeAutomat8) {
    Automat mojAutomat;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    string nazvy[10] = {"kava","velka kava", "kapucino", "kapucino s cokoladov",
                        "mliecna kava", "kava s cokoladov", "citronovy caj",
                        "cokolada", "irish cream", "polievka"};
    int vlastnosti[10][9] = {{4,7,0,0,0,0,0,30,75},{4,14,0,0,0,0,0,30,150},
                             {4,14,0,0,0,7,0,40,150},{4,14,0,0,7,7,0,40,150},
                             {4,14,0,0,0,7,0,40,150},{4,14,0,0,7,0,0,40,150},
                             {4,0,0,0,0,0,7,30,150},{4,0,0,0,7,7,0,40,150},
                             {4,14,0,7,0,7,0,40,150},{0,0,7,0,0,0,0,40,150}};
    for(int i = 0; i < 8; i++) {
        ASSERT_TRUE(mojAutomat.nastavNapoj(nazvy[i],vlastnosti[i],9));
    }
    ASSERT_EQ(8, mojAutomat.kolkoNastavenychNapojov());
    ASSERT_EQ(2, mojAutomat.kolkoNenastavenychNapojov());
    ASSERT_EQ("kava s cokoladov", mojAutomat.vratMiNazovNapoja(5));
}

TEST(TestThirdTask, nastavimeFullAutomatAutomaticky1) {
    Automat mojAutomat(1000,1000,1000,1000,1000,1000,1000);
    mojAutomat.nastavNapoj("kava",4,7,0,0,0,0,0,30,75);
    mojAutomat.nastavNapoj("velka kava",4,14,0,0,0,0,0,30,150);
    mojAutomat.nastavNapoj("kapucino",4,14,0,0,0,7,0,40,150);
    mojAutomat.nastavNapoj("kapucino s cokoladov",4,14,0,0,7,7,0,40,150);
    mojAutomat.nastavNapoj("mliecna kava",4,14,0,0,0,7,0,40,150);
    mojAutomat.nastavNapoj("kava s cokoladov",4,14,0,0,7,0,0,40,150);
    mojAutomat.nastavNapoj("citronovy caj",4,0,0,0,0,0,7,30,150);
    mojAutomat.nastavNapoj("cokolada",4,0,0,0,7,7,0,40,150);
    mojAutomat.nastavNapoj("irish cream",4,14,0,7,0,7,0,40,150);
    mojAutomat.nastavNapoj("polievka",0,0,7,0,0,0,0,40,150);
    ASSERT_EQ(10, mojAutomat.kolkoNastavenychNapojov());
    ASSERT_EQ(0, mojAutomat.kolkoNenastavenychNapojov());
    ASSERT_EQ("cokolada", mojAutomat.vratMiNazovNapoja(7));
}

TEST(TestThirdTask, nastavimeFullAutomatAutomaticky2) {
    Automat mojAutomat;
    ASSERT_TRUE(mojAutomat.naplnHoKlasicky());
    ASSERT_EQ(10, mojAutomat.kolkoNastavenychNapojov());
    ASSERT_EQ(0, mojAutomat.kolkoNenastavenychNapojov());
    ASSERT_EQ("cokolada", mojAutomat.vratMiNazovNapoja(7));
}