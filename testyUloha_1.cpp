// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

#include "1_napoj.h"

using namespace ::testing;

//Uloha 1.
TEST(TestFirstTask, NenastavenyNapoj) {
	Napojn kava;
	ASSERT_FALSE(kava.jeNastaveny());
}
TEST(TestFirstTask, NazovZiadny) {
	Napojn kava;
	ASSERT_EQ("", kava.menoNapoja());
}
TEST(TestFirstTask, NastavitNapoj) {
    Napojn kava;
    int vlastnosti1[9] = {4,7,0,0,0,0,0,30,75}; //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
	ASSERT_TRUE(kava.nastavitNapoj("Mala kava", vlastnosti1, 9));
}

TEST(TestFirstTask, NastavitNapoj1) {
    Napojn kava;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    ASSERT_TRUE(kava.nastavitNapoj("Mala kava",4,7,0,0,0,0,0,30,75));
}

TEST(TestFirstTask, NapojBezMena) {
    Napojn kava;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    ASSERT_FALSE(kava.nastavitNapoj("", 4,7,0,0,0,0,0,30,75));
	ASSERT_FALSE(kava.jeNastaveny());
}

TEST(TestFirstTask, NastavenyNapoj) {
    Napojn kava;
    kava.nastavitNapoj("Mala kava", 4,7,0,0,0,0,0,30,75);
    ASSERT_TRUE(kava.jeNastaveny());
}
TEST(TestFirstTask, NazovSaZhoduje) {
    Napojn kava;
    kava.nastavitNapoj("Mala kava", 4,7,0,0,0,0,0,30,75);
	ASSERT_EQ("Mala kava", kava.menoNapoja());
}

TEST(TestFirstTask, CenaNula) {
    Napojn kava;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    ASSERT_FALSE(kava.nastavitNapoj("Mala kava", 4,7,0,0,0,0,0,0,75));
}

TEST(TestFirstTask, ObjemNula) {
    Napojn kava;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    ASSERT_FALSE(kava.nastavitNapoj("Mala kava", 4,7,0,0,0,0,0,30,0));
}

TEST(TestFirstTask, MinusoveCislo) {
    Napojn kava;
    //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    ASSERT_FALSE(kava.nastavitNapoj("Mala kava", 4,-7,0,0,0,0,0,30,75));
}

TEST(TestFirstTask, KratsiArray) {
    Napojn kava;
    int vlastnosti1[7] = {4,-7,0,0,0,0,30}; //cukor, kava, bujon, whisky, cokolada, mlieko, caj, cena, objem
    ASSERT_FALSE(kava.nastavitNapoj("Mala kava", vlastnosti1, 7));
}