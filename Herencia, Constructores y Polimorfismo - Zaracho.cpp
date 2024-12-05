#include <iostream>
#include <stdlib.h>
using namespace std;

class Persona {
    private:
        string nombre;
        int edad;
    public:
        Persona(string, int);
        virtual void MostrarInfo();
};

Persona::Persona(string _nombre, int _edad) {
    nombre = _nombre;
    edad = _edad;
}

void Persona::MostrarInfo() {
    cout << "---------------------- " << endl;
    cout << "Los datos de la persona son: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "---------------------- " << endl;
}

class Operario : public Persona {
    private:
        string profesion;
        float sueldo;
    public:
        Operario(string, int, string, float);
        void MostrarInfo();
};

Operario::Operario(string _nombre, int _edad, string _profesion, float _sueldo) : Persona(_nombre, _edad) {
    profesion = _profesion;
    sueldo = _sueldo;
}

void Operario::MostrarInfo() {
    cout << "---------------------- " << endl;
    Persona::MostrarInfo();
    cout << "Profesion: " << profesion << endl;
    cout << "Sueldo: " << sueldo << endl;
    cout << "---------------------- " << endl;
}

class Empresario : public Persona {
    private:
        string nombreEmpresa;
        float costosMensuales;
        float gananciasMensuales;
    public:
        Empresario(string, int, string, float, float);
        void MostrarInfo();
};

Empresario::Empresario(string _nombre, int _edad, string _nombreEmpresa, float _costosMensuales, float _gananciasMensuales) : Persona(_nombre, _edad) {
    nombreEmpresa = _nombreEmpresa;
    costosMensuales = _costosMensuales;
    gananciasMensuales = _gananciasMensuales;
}

void Empresario::MostrarInfo() {
    cout << "---------------------- " << endl;
    Persona::MostrarInfo();
    cout << "El nombre de la empresa es: " << nombreEmpresa << endl;
    cout << "Los costos mensuales son: " << costosMensuales << endl;
    cout << "Las ganancias mensuales son: " << gananciasMensuales << endl;
    cout << "---------------------- " << endl;
}

int main() {
    Persona *vector[3];
    vector[0] = new Operario("Elias", 17, "Electronico", 56000);
    vector[1] = new Empresario("Benjamin", 43, "Novatella", 20000, 50000);
    vector[2] = new Persona("Joaquin", 24);
    
    vector[0]->MostrarInfo();
    vector[1]->MostrarInfo();
    vector[2]->MostrarInfo();

    return 0;
}
