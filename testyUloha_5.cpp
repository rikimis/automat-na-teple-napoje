// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

using namespace ::testing;

#include "1_napoj.h"
#include "3_automat.h"


TEST(TestThirdTask, kup_predvolba) {
    Automat mojAutomat(1000,1001,1000,1000,1000,1000,1000);
    mojAutomat.naplnHoKlasicky(); //naplnuje napoje
    //cislonapoja, predvolba, kluc, a potom su mince
    ASSERT_FALSE(mojAutomat.kupNapoj(0,"ano","nemam",0,1,0,0,0,0));
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nie","nemam",0,3,0,0,0,0));
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",0,3,0,0,0,0));
    ASSERT_FALSE(mojAutomat.kupNapoj(0,"niccccc","nemam",0,3,0,0,0,0));
}

TEST(TestThirdTask, kup_kluc) {
    Automat mojAutomat(1000,1001,1000,1000,1000,1000,1000);
    mojAutomat.naplnHoKlasicky(); //naplnuje napoje
    //cislonapoja, predvolba, kluc, a potom su mince
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","mam",1,2,0,0,0,0));
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",0,3,0,0,0,0));
    ASSERT_FALSE(mojAutomat.kupNapoj(0,"nic","nemammmmm",0,3,0,0,0,0));
}

TEST(TestThirdTask, kup_cisloproduktu) {
    Automat mojAutomat(1000,1001,1000,1000,1000,1000,1000);
    mojAutomat.naplnHoKlasicky();//naplnuje napoje
    //cislonapoja, predvolba, kluc, a potom su mince
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","mam",1,2,0,0,0,0));
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",0,3,0,0,0,0));
    ASSERT_FALSE(mojAutomat.kupNapoj(20,"nic","nemam",0,3,0,0,0,0));
}

TEST(TestThirdTask, odratavanie_penazi) {
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky();//naplnuje napoje
    mojAutomat.naplnHoKlasicky2();//naplnuje "mince"
    ASSERT_EQ(3465,mojAutomat.vratZostatokVAtomate()); // v centoch
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",0,3,0,0,0,0));
    ASSERT_EQ(3495,mojAutomat.vratZostatokVAtomate()); // + 30 centov
}

TEST(TestThirdTask, pridavanie_minci) {
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky();//naplnuje napoje
    mojAutomat.naplnHoKlasicky2();//naplnuje "mince"
    string minca = "10c";
    ASSERT_EQ(9,mojAutomat.vratMnozstvoMinci(minca));
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",0,3,0,0,0,0));
    ASSERT_EQ(12,mojAutomat.vratMnozstvoMinci(minca)); // + tri desaatcentovky
}

TEST(TestThirdTask, pridavanie_minci2) {
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky();
    mojAutomat.nastavMince(9,10,9,9,9,9);
    string minca = "10c";
    ASSERT_EQ(10,mojAutomat.vratMnozstvoMinci(minca));
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",0,3,0,0,0,0));
    ASSERT_EQ(13,mojAutomat.vratMnozstvoMinci(minca)); // + tri desaatcentovky
}

TEST(TestThirdTask, viem_odratat) {
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky();
    mojAutomat.nastavMince(1,1,1,1,1,1);
    int mince[] = {1,1,1,1,1,1};
    ASSERT_TRUE(mojAutomat.viemOdratat(mince));
    mojAutomat.nastavMince(1,1,1,1,1,0);
    ASSERT_FALSE(mojAutomat.viemOdratat(mince));
}

TEST(TestThirdTask, viem_vydat) {
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky(); //napoje
    mojAutomat.nastavMince(1,0,1,1,1,1);
    ASSERT_EQ(375,mojAutomat.vratZostatokVAtomate()); //v centoch
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",0,4,0,0,0,0)); //vlozili sme 40centov (napoj stoji 30c)
    ASSERT_EQ(405,mojAutomat.vratZostatokVAtomate());//v centoch
    string minca = "10c";
    ASSERT_EQ(3,mojAutomat.vratMnozstvoMinci(minca));
}

TEST(TestThirdTask, viem_vydat2) {
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky(); //napoje
    mojAutomat.nastavMince(0,0,1,1,1,1);
    ASSERT_EQ(370,mojAutomat.vratZostatokVAtomate()); //v centoch
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",4,2,0,0,0,0)); //vlozili sme 40centov (napoj stoji 30c)
    ASSERT_EQ(400,mojAutomat.vratZostatokVAtomate());//v centoch
    string minca = "5c";
    ASSERT_EQ(2,mojAutomat.vratMnozstvoMinci(minca));
    minca = "10c";
    ASSERT_EQ(2,mojAutomat.vratMnozstvoMinci(minca));
}

TEST(TestThirdTask, viem_vydat3) { //tu nebude na vydaj.... napoj spravime ale nevydame
    string minca = "2€";
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky(); //napoje
    mojAutomat.nastavMince(0,0,0,0,0,0);
    ASSERT_EQ(0,mojAutomat.vratMnozstvoMinci(minca)); //nula 2€
    ASSERT_EQ(0,mojAutomat.vratZostatokVAtomate()); //v centoch
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",0,0,0,0,0,1)); //vlozili sme 2€ (napoj stoji 30 centov)
    ASSERT_EQ(200,mojAutomat.vratZostatokVAtomate());//v centoch
    ASSERT_EQ(1,mojAutomat.vratMnozstvoMinci(minca));//1x2€
}

TEST(TestThirdTask, viem_vydat4) { //tu tiež nebude na vydaj.... napoj spravime ale nevydame
    string minca = "2€";
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky(); //napoje
    mojAutomat.nastavMince(0,0,0,0,0,0);
    ASSERT_EQ(0,mojAutomat.vratMnozstvoMinci(minca)); //nula 2€
    ASSERT_EQ(0,mojAutomat.vratZostatokVAtomate()); //v centoch
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",1,0,0,0,0,1)); //vlozili sme 2,05€ (napoj stoji 30 centov)
    ASSERT_EQ(200,mojAutomat.vratZostatokVAtomate());// zobralo si iba 2€ z kreditu
    minca = "5c";
    ASSERT_EQ(0,mojAutomat.vratMnozstvoMinci(minca));// takze 0 x 5centov
}

TEST(TestThirdTask, final) { //tu vložíme 5€ a vydáme
    Automat mojAutomat;
    mojAutomat.naplnHoKlasicky(); //napoje
    mojAutomat.nastavMince(0,0,0,0,0,0);
    ASSERT_EQ(0,mojAutomat.vratZostatokVAtomate()); //v centoch
    ASSERT_TRUE(mojAutomat.kupNapoj(0,"nic","nemam",100,0,0,0,0,0)); //vlozili sme 5€ v 5 centovkách (napoj stoji 30 centov)
    ASSERT_EQ(30,mojAutomat.vratZostatokVAtomate());// zobralo si iba 30 centov z kreditu
    string minca = "5c";
    ASSERT_EQ(6,mojAutomat.vratMnozstvoMinci(minca));// takze 6 x 5centov
}

