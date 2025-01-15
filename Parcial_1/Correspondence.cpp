#include "Correspondence.h"

Correspondence::Correspondence(){
    code = 0;
    adressee = "";
    neighborhood = "";
    typeAdressee = "";
    arrayTypeAdressee[0] ="comercial";
    arrayTypeAdressee[1] ="institucional";
    arrayTypeAdressee[2] ="informal";
    }

Correspondence::Correspondence(int code, string adressee, string neighborhood, string typeAdressee){
    this->code = code;
    this->adressee = adressee;
    this->neighborhood = neighborhood;
    this->typeAdressee = typeAdressee;
}

string Correspondence::getAdressee(){
    return this->adressee;
}

int Correspondence::getCode(){
    return this->code;
}

string Correspondence::getArrayTypeAdressee(int index){
    if(index>=0 && index<3){
        return arrayTypeAdressee[index];
    }
    else{
        return "Indice fuera de rango\n";
    }
}

string Correspondence::getTypeAdressee(){
    return this->typeAdressee;
}

string Correspondence::getNeighborhood(){
    return this->neighborhood;
}
Correspondence::~Correspondence(){}