#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#include "3_automat.h"

int Automat::kolkoMoznosti( int S[], int m, int n ) //O(n) lineárna zložitosť
{
    int table[n+1];

    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];

    return table[n];
}

bool Automat::kupNapoj(int cisloproduktu, const string &predvolba,const string &kluc, int patcentov, int desatcentov, int dvadsatcentov, int patdesiatcentov, int euro, int dvaeura){
    if ((predvolba != "ano") && (predvolba != "nie") && (predvolba != "nic")){
        return false;
        //tu sa meno len mnozstvo cukru
    }
    if ((kluc != "mam") && (kluc != "nemam")){
        return false;
        //tu sa meni suma na fixnú sumu
    }
    if (kolkoNapojov() != 10){
        return false;
    }
    if ((cisloproduktu > 9) || (cisloproduktu < 0)){
        return false;
    }
    if (!viemeVyrobitNapoj(cisloproduktu, predvolba)){
        return false;
    }

    int kredit;

    kredit = minceNaSumu(patcentov,desatcentov,dvadsatcentov,patdesiatcentov,euro,dvaeura);

    Napoj* n = vratNapoj(cisloproduktu);
    if (!n->jeNastaveny()){return false;}
    int cena_napoja = n->vratMnozstvoSurovinyN(7);

    if (kluc == "mam"){cena_napoja = 25;}
    if (kredit < cena_napoja){return false;}
    else if (kredit == cena_napoja) { //ked sa hodi presnea suma

        odratajSurovinyZAutomatu(cisloproduktu,predvolba);

        a_patcentov += patcentov;
        a_desatcentov += desatcentov;
        a_dvadsatcentov += dvadsatcentov;
        a_patdesiatcentov += patdesiatcentov;
        a_euro += euro;
        a_dvaeura += dvaeura;

        return true;

    } else if (kredit > cena_napoja) {
        if (kredit <= 200){ //ked sa hodi 2 eura a menej, ale nie presne suma napoja
            //zoberiem si vsetky peniaze a budem sa mu snazit vydat vydavok

            a_patcentov += patcentov;
            a_desatcentov += desatcentov;
            a_dvadsatcentov += dvadsatcentov;
            a_patdesiatcentov += patdesiatcentov;
            a_euro += euro;
            a_dvaeura += dvaeura;

            int kolko_vydat = kredit - cena_napoja;
            int arr[] = {5,10,20,50,100,200};
            int kolko_moznosti = kolkoMoznosti(arr,6,kolko_vydat);
            for(int i = 0; i < kolko_moznosti; i++) {
                if (viemOdratat(vsetkyKombinacie[kolko_vydat][i])) {
                    odrataj(vsetkyKombinacie[kolko_vydat][i]);
                    break;
                }
            }
            return true;
        } else { //to je keby hodil viac ako 2€, co by realne nenastalo, ale u mna moze :)
            //tu si zoberiem zo vsetkych penazi iba 2€ (to si vlastne rezervujem)

            const int x[6] = {patcentov,desatcentov,dvadsatcentov,patdesiatcentov,euro,dvaeura};
            for(int i = 0; i < 293; i++) {
                if (viemOdratat2(x,vsetkyKombinacie[200][i])) {
                    a_patcentov += vsetkyKombinacie[200][i][0];
                    a_desatcentov += vsetkyKombinacie[200][i][1];
                    a_dvadsatcentov += vsetkyKombinacie[200][i][2];
                    a_patdesiatcentov += vsetkyKombinacie[200][i][3];
                    a_euro += vsetkyKombinacie[200][i][4];
                    a_dvaeura += vsetkyKombinacie[200][i][5];
                    break;
                }
            }

            int kolko_vydat = 200 - cena_napoja;
            int arr[] = {5,10,20,50,100,200};
            int kolko_moznosti = kolkoMoznosti(arr,6,kolko_vydat);
            for(int i = 0; i < kolko_moznosti; i++) {
                if (viemOdratat(vsetkyKombinacie[kolko_vydat][i])) {
                    odrataj(vsetkyKombinacie[kolko_vydat][i]);
                    break;
                }
            }

            return true;
        }
    }
    return false;
}

