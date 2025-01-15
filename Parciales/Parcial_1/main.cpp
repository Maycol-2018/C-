#include "Company.h"


void menu(){
    cout<<"\n____Empresa de Correos____"<<
    "\n1- Ingresar Correspondencia"<<
    "\n2- Total Correpondencia por Tipo"<<
    "\n3- Salir"<<endl;
}

void start(){
    Company company;
    int option = 0;
    do
    {
        menu();
        option = stoi(read("\nIngrese una opcion -> "));
        switch (option)
        {
        case 1:
            company.enterCorrespondence();
            break;
        case 2:
            company.totalCorrespondence();
            break;
        case 3:
            cout<<"Saliendo ...."<<endl;
            break;
        default:
            cout<<"Opcion incorrecta!"<<endl;
            break;
        }
    } while (option!=3);
    
}       

int main(){
    start();
    return 0;
}