#ifndef CORRESPONDENCE_H
#define CORRESPONDENCE_H

#include <iostream>
#include <string>
using namespace std;

class Correspondence{
    private: 
    int code;
    string adressee;
    string neighborhood;
    string arrayTypeAdressee[3];
    string typeAdressee;

    public:
    Correspondence();
    Correspondence(int, string, string, string);
    string getAdressee();
    int getCode();
    string getArrayTypeAdressee(int);
    string getTypeAdressee();
    string getNeighborhood();

    ~Correspondence();
};
#else
class Correspondence;
#endif