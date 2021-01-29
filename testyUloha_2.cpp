// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

using namespace ::testing;

#include "1_napoj.h"

TEST(TestSecondTask, TypIzby) {
	Napoj kava;
	ASSERT_EQ("Napoj", kava.vratTypNapojaMeno());
}

TEST(TestSecondTask, ResetniNenastavenyNapoj) {
    Napoj kava;
	ASSERT_FALSE(kava.resetniNapoj());
}

TEST(TestSecondTask, ResetniNapoj) {
    Napoj kava;
    kava.nastavitNapoj("Mala kava", 4,7,0,0,0,0,0,30,75);
	ASSERT_TRUE(kava.resetniNapoj());
}

TEST(TestSecondTask, NazovResetnutehoNapoja) {
    Napoj kava;
    kava.nastavitNapoj("Mala kava", 4,7,0,0,0,0,0,30,75);
    kava.resetniNapoj();
	ASSERT_EQ("", kava.menoNapoja());
}