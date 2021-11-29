#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <ctype.h>
#include "classmat.h"

using namespace std;

#define MAX 350 // number of words;

int main(){
    featuresMat Feats;

    // fit the document;
    Feats.fitDoc(Feats.allWords, Feats.lines);
    // check if it is empty;
    if(Feats.checkEmpty(Feats.allWords)) return 0;
        else{
            // count chars;
            Feats.countChars(Feats.allWords, Feats.feat);
            // count vowels;
            Feats.countVows(Feats.allWords, Feats.feat);
            // count consonants;
            Feats.countCons(Feats.feat);
            // is upper;
            Feats.isUpCase(Feats.allWords, Feats.feat);
            // is non terminal;
            Feats.isNonTerm(Feats.allWords, Feats.feat);
            // adress x and y values;
            Feats.comparisonXY(Feats.allWords, Feats.feat, Feats.word);
            // get the document;
            Feats.getDoc(Feats.feat);
        }
    return 0;
}
