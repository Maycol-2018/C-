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

void numeroPerfecto()
{
    int num, sumatoria;
    cout<<"_____Numero Perfecto_____\n\n";
    do
    {
        num = stoi(leer("Ingrese un numero: "));
        if(num<0)
        {
            cout<<"El numero debe ser mayor a cero"<<endl;
        }
    }while (num<0);
    
    sumatoria = 0;
    for(int i=1; i<num; i++)
    {
        if(num%i==0)
        sumatoria += i;
    }

    cout<<"Suma de los divisores del "<<num<<" -> "<<sumatoria<<"\n";
    if(sumatoria == num)
    {
        cout<<"El numero "<<num<<" es un numero Perfecto"<<endl;
    }
    else
    {
        cout<<"El numero "<<num<<" NO es un numero Perfecto"<<endl;
    }
}


void menu()
{
    int opc=0;
    do
    {
        cout<<"\n_______Menu_______\n"<<
        "\n1. Informacion estudiantil"<<
        "\n2. Numero perfecto"<<
        "\n3. Restaurante universitario"<<
        "\n4. Salir"<<endl;

        opc = stoi(leer("Ingrese una opcion -> "));
        switch(opc)
        {
            case 1: tienda_productos();
                    break;
            case 2: numeroPerfecto();
                    break;
            case 3: break;
            case 4: cout<<"Saliendo del menu .....\n";
                    break;
            default: cout<<"Opcion incorrecta\n";
        }
    }while(opc != 4);


}
int main()
{
    menu();
    return 0;
}


