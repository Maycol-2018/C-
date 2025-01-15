#ifndef COMPANY_H
#define COMPANY_H

#include "Correspondence.h"

inline string read(string msg){
    string aux;
    cout<<msg;
    getline(cin, aux);
    return aux;
}

class Company{
    private:
    Correspondence correspondence;
    Correspondence arrayCorrespondence[3];
    int iterator;

    public:
    Company();
    void enterCorrespondence();
    void totalCorrespondence();
    bool verifyTypeCorrespondence(string);
    ~Company();
};
#else
class Correspondence;
#endif