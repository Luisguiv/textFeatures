#ifndef DATATYPES_H
#define DATATYPES_H

#include <stdio.h>
#include <string.h>

// list of features for each word;
typedef struct fea{
    // feats quanti;
    unsigned int charNum; // num characters;
    unsigned int vog; // num vowels;
    unsigned int cons; // num consonants;
    unsigned int freq; // frequency, for bow model;
    long long int xValue; // x value for word;
    long long int yValue; // y value for word;
    // feats quali;
    // one hot encoding based boolean usage;
    int upCase; // uppercase word;
    int nt; // non-terminal word;
} listFeatures;

// struct for comparison;
typedef struct let{
    // must after features analysis, being that the text needs to be on uppercase;
    char letters[3][9]={
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'},
        {'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 0} // the last element must not be ignored;
    }; // the lines and collumns represents the x and y axis;
} listLetters;

#endif // DATATYPES_H
