#include "Company.h"

Company::Company(){
    iterator = 0;
}

void Company::enterCorrespondence(){
    int code = 0;
    string adressee="";
    string neighborhood = "";
    string typeAdressee = "";
    bool flag = false;
    bool existingCode = false;

    do
    {
        code = stoi(read("Ingrese el codigo entre (100-999): "));
        if((code < 99) || (code > 999)){
            cout<<"Error!"<<endl;
        }
        if(iterator>0){
            for(int i=0; i<iterator; i++){
                if(code == arrayCorrespondence[i].getCode()){
                    cout<<"El codigo ya existe!!"<<endl;
                    existingCode = true;
                }
            }
        }
    } while ((code < 99) || (code > 999) || existingCode);

    do
    {
        adressee = read("Ingrese el nombre del destinatario: ");
        if(adressee == "")
            cout<<"Error! No se ha ingresado un destinatario\n";
    } while (adressee=="");

    do
    {
        neighborhood = read("Ingrese el barrio: ");
        if(neighborhood == "")
            cout<<"Error! No se ha ingresado un barrio\n";
    } while (neighborhood=="");

    do{
        typeAdressee = read("Ingrese el tipo de correspondencia: ");
        flag = verifyTypeCorrespondence(typeAdressee);
    }while(flag == false);

    if(iterator < 3){
        arrayCorrespondence[iterator] = Correspondence(code, adressee, neighborhood, typeAdressee);
        iterator ++;
        cout<<"Correspondencia ingresada con exito!!"<<endl;
    }
    else{
        cout<<"Error en el ingreso. No hay mas espacio en el arreglo"<<endl;
    }
}

void Company::totalCorrespondence(){
    int commercial = 0;
    int institutional = 0;
    int informal = 0;
    string neighborhood ="";
    string output = "";
    int quantityCorrespondence = 0;

    cout<<"\n****Cantidad de Correspondencia por tipo***\n";

    for(int i=0; i<iterator; i++){
        if(arrayCorrespondence[i].getTypeAdressee() == "comercial"){
            commercial++;
        }else if (arrayCorrespondence[i].getTypeAdressee() == "institucional")
        {
            institutional++;
        }
        else{
            informal++;
        }
    }

    cout<<"Comercial: "<<commercial<<
    "\nInstitucional: "<<institutional<<
    "\nInformal: "<<informal<<endl;

    neighborhood = read("Buscar por Barrio: ");

    for(int i=0; i<iterator; i++){
        if(arrayCorrespondence[i].getNeighborhood() == neighborhood){
            quantityCorrespondence++;
            output += arrayCorrespondence[i].getAdressee() + "\t" + to_string(arrayCorrespondence[i].getCode()) +
            "\t" + arrayCorrespondence[i].getTypeAdressee() + "\n";
        }
    }

    if(quantityCorrespondence != 0){
        cout<<"\nLa cantidad de correspondencia del Barrio "<<neighborhood<<" es -> "<<quantityCorrespondence<<endl;
        cout<<output<<endl;
    }
    else{
        cout<<"\nNo se ha encontrada entre las correspondencias el Barrio "<<neighborhood<<endl;
    }

}

bool Company::verifyTypeCorrespondence(string typeAdressee){
    for(int i=0; i<3; i++){
        if(typeAdressee == correspondence.getArrayTypeAdressee(i)){
            return true;
        }
    }
    cout<<"Tipo de correspondencia incorrecto!!"<<endl;
    return false;
}

Company::~Company(){}