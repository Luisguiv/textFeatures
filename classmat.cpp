#include "classmat.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;

featuresMat::featuresMat(){
    cout<<"Objeto Criado"<<endl;
}

//

void featuresMat::fitDoc(char allWords[][20], char lines[10000]){
    allWords=NULL;

    fstream myFile;
    vector<string> paragraphs;
    // int count=0;

    myFile.open("text.txt", ios::in);
    if(myFile.is_open()){
        string lines;

        while(getline(myFile, lines)){
            paragraphs.push_back(lines);
        }
    myFile.close();
    }

    // transforming vector<string> to char* array;
    copy(paragraphs.begin(), paragraphs.end(), lines);

    // making into a matrix;
    int i=0;
    int lin=0, col=0;
    while(lines[i]!='\0'){
        if(lines[i]!='\n') allWords[lin][col++]=lines[i];
        else lin++; col=0;
    }
}

bool featuresMat::checkEmpty(char allWords[][20]){ // must pass through fitDoc;
    if(allWords==NULL){
        return true;
    }
    else return false;
}

int featuresMat::countChars(char allWords[][20], listFeatures *feat){
    int i=0, j=0, k=0;

    for(i=0; i<4; i++){ // through paragraphs;
        for(j=0; allWords[i][j]!='\n'; j++){ // through letters;
            if(isalpha(allWords[i][j])) feat[k].charNum+=1;
            else k++;
        }
    }
    return 0;
}

int featuresMat::countVows(char allWords[][20], listFeatures *feat){
    int i=0, j=0, k=0;

    for(i=0; i<4; i++){ // through paragraphs;
        for(j=0; allWords[i][j]!='\n'; j++){ // through letters;
            if(isalpha(allWords[i][j])){
                feat[k].vog += (allWords[i][j] == 'a' || allWords[i][j] == 'e' || allWords[i][j] == 'i' || allWords[i][j] == 'o' || allWords[i][j] == 'u');
                feat[k].vog += (allWords[i][j] == 'A' || allWords[i][j] == 'E' || allWords[i][j] == 'I' || allWords[i][j] == 'O' || allWords[i][j] == 'U');
            }
            else k++;
        }
    }
    return 0;
}

int featuresMat::countCons(listFeatures *feat){
    int k=0;

    while(k<MAX) feat[k].cons = feat[k].charNum-feat[k].vog; k++; // consonants = totalNumCharacters-numVowels;

    return 0;
}

int featuresMat::isUpCase(char allWords[][20], listFeatures *feat){ // if word is on upper case;
    int i=0, j=0, k=0;

    for(i=0; i<4; i++){
        for(j=0; allWords[i][j]!='\n'; j++){
            if(isalpha(allWords[i][j])){
                if(isupper(allWords[i][j])) feat[k].upCase=true;
            }
            else k++;
        }
    }
    return 0;
}

int featuresMat::isNonTerm(char allWords[][20], listFeatures *feat){ // if it is a non terminal word;
    int i, j, k=0;

    for(i=0; i<4; i++){
        for(j=0; allWords[i][j]!='\n'; j++){
            if(isalpha(allWords[i][j]));
                else{
                    if(allWords[i][j]=='.' || allWords[i][j]==','){
                    feat[k].nt=false;
                    }
                    else feat[k++].nt=true;
                }
        }
    }
    return 0;
}

void featuresMat::comparisonXY(char allWords[][20], listFeatures *feat, listLetters word){ // x and y value for a word;
    int i=0, j=0, k=0;
    int lin, col;

    for(i=0; i<4; i++){
        if(j>0){
            for(j=j+1; allWords[i][j]!=' ' || allWords[i][j]!=',' || allWords[i][j]!='.' || allWords[i][j]!='\n'; j++){
                if(isalpha(allWords[i][j])){
                    for(lin=0; lin<3; lin++){
                        for(col=0; col<9; col++){
                            if(allWords[i][j]==word.letters[lin][col]){
                                feat[k].xValue+=col;
                                feat[k].yValue+=lin;
                            }
                        }
                    }
                }
                else k++;
            }
        }
    }
}

void featuresMat::getDoc(listFeatures *feat){ // generate the matrix in a .txt file;
    fstream outFile;

    outFile.open("matrix.txt", ios::out); // write;
    if(outFile.is_open()){
        for(int i=0; i<350; i++){
            outFile<< feat[i].charNum << feat[i].vog << feat[i].cons << feat[i].upCase << feat[i].nt << feat[i].xValue << feat[i].yValue << endl;
        }
    }
    outFile.close();
}

featuresMat::~featuresMat(){
    cout<<"Objeto Destruido"<<endl;
}
