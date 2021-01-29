#include <iostream>
#include <cstring>  /* strcpy */

using namespace std;

#include "1_napoj.h"

bool Napojn::resetniNapoj() {
    if (!Napojn::jeNastaveny()){
        return false;
    }
    nazov.clear();
    for(int & i : vlastnosti) {
        i = 0;
    }
    return true;
}