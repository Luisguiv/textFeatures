#ifndef CLASSMAT_H
#define CLASSMAT_H


#include <string>
#include "dataTypes.h" // importing structures;
#define MAX 350 // maximum of words;

using namespace std;

class featuresMat{
    public:
        listFeatures feat[350];
        listLetters word;
        char allWords[MAX][20];
        char lines[10000];

        featuresMat(); // construct;
        //
        void fitDoc(char allWords[][20], char lines[10000]);
        bool checkEmpty(char allWords[][20]);
        // features collection;
        int countChars(char allWords[][20], listFeatures *feat);
        int countVows(char allWords[][20], listFeatures *feat);
        int countCons(listFeatures *feat);
        // int function as bool;
        int isUpCase(char allWords[][20], listFeatures *feat);
        int isNonTerm(char allWords[][20], listFeatures *feat);
        // x and y;
        void comparisonXY(char allWords[][20], listFeatures *feat, listLetters word);
        //
        void getDoc(listFeatures *feat);
        //
        ~featuresMat(); // destruct;
};

#endif // CLASSMAT_H
