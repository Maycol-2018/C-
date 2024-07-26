#include <iostream>

using namespace std;

string leer(string mensaje)
{
    string aux;
    cout<<mensaje;
    getline(cin,aux);
    return aux;
}

void tienda_productos()
{
    string name, profesion;
    int age, tam;

    tam= stoi(leer("Ingrese el numero de personas: "));

    string arreNom[tam];
    int arreAge[tam];
    string arreProf[tam];

    for(int i=0; i<tam; i++)
    {
        cout<<"\n~ Estudiante "<<i+1<<endl;
        arreNom[i] = leer("Ingrese el nombre: ");
        arreAge[i] = stoi(leer("Ingrese la edad: "));
        arreProf[i] = leer("Ingrese la carrera: ");
    }

    int menor=0;
    int mayor=0;
    for(int i=0; i<tam; i++)
    {
        if(arreAge[i]<18)
        {
            menor ++;
        }
        else
        {
            if(arreAge[i]>25)
            {
                mayor++;
            }
        }
    }

    mayor = (mayor*100)/tam;

    string nom;
    int ult;
    string salida ="  Nombre\tProfesion\n";
    for(int i=0; i<tam; i++)
    {
        nom = arreNom[i];
        ult = nom.length()-1;

        if(nom[ult]=='a' || nom[ult]=='A')
        {
            // Establecer un ancho fijo (14) para las columnas. Se agrega tantos espacios hagan falta para el
            // ancho fijo. 14 son los espacios ocupados por "Nombre (6)" y "\t=8 espacios"
            salida += "- " + nom + string(14 - nom.length(), ' ') + arreProf[i] + "\n";
        }
    }



    cout<<"\n_____Informacion_____\n";
    cout<<"Estudiantes menores de edad -> "<<menor<<endl;
    cout<<"\nNombres de estudiantes que terminan en 'a' \n"<<salida;
    cout<<"Porcentaje de estuiantes mayores de 25 anhos -> "<<mayor<<"%"<<endl;
}

int main()
{
    tienda_productos();
    return 0;
}


