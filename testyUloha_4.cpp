// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

using namespace ::testing;

#include "1_napoj.h"
#include "3_automat.h"

TEST(TestThirdTask, minceNaSumu) {
    Automat mojAutomat;
    ASSERT_EQ(10,mojAutomat.minceNaSumu(2,0,0,0,0,0));
}

TEST(TestThirdTask, minceNaSumuZaporneCislo) {
    Automat mojAutomat;
    ASSERT_EQ(0,mojAutomat.minceNaSumu(-2,0,0,0,0,0));
}

TEST(TestThirdTask, minceNaZoznam) {
    Automat mojAutomat;
    int zoznam[6];
    mojAutomat.minceNaZoznam(2,0,0,0,0,0,zoznam);
    ASSERT_EQ(2,zoznam[0]);
}

TEST(TestThirdTask, viemeVyrobitNapoj) {
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky();
    ASSERT_TRUE(mojAutomat.viemeVyrobitNapoj(0, ""));
}

TEST(TestThirdTask, viemeVyrobitNapoj2) { //mali by sme vediet vyrobit 142kusov malej kávy pri nastavení klasických hodnôt
    Automat mojAutomat(1000,1000,1000,1000,1000,1000,1000);
    //kavy je 1000g a mala kava si berie 7g
    mojAutomat.naplnHoKlasicky();
    for(int i = 0; i < 140; i++) {
        mojAutomat.odratajSurovinyZAutomatu(0, "");
    }
    // 140 * 7 = 980 a 1000 - 980 je 20
    ASSERT_EQ(20, mojAutomat.vratMnozstvoSuroviny("kava"));
}

TEST(TestThirdTask, viemeVyrobitNapoj3) {
    Automat mojAutomat(1000,1001,1000,1000,1000,1000,1000);
    //kavy je 1001g a mala kava si berie 7g
    mojAutomat.naplnHoKlasicky();
    for(int i = 0; i < 143; i++) { //mali by sme vediet vyrobit 143kusov malej kávy pri nastavení kavy na 1001g
        mojAutomat.odratajSurovinyZAutomatu(0, "");
    }
    ASSERT_EQ(0, mojAutomat.vratMnozstvoSuroviny("kava"));
    ASSERT_FALSE(mojAutomat.viemeVyrobitNapoj(0, ""));
}