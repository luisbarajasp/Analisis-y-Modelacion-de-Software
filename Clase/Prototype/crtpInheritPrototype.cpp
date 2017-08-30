/* Prototype class
Analisis y Modelacion de Software
30/08/17*/

#include <iostream>
#include <string>
using namespace std;

class Mundo{
public:
    Mundo(string n){
        nombreMundo = n;
    }
    string nombreMundo;
};

class Personaje{
public:
    string nombre;
    int telefono;
    string correo;
    Mundo* mundo;
    virtual Personaje* clone() = 0;
};

template<class Base, class SubClass>
class Clone: public Base{
public:
    Base* clone(){
        return new SubClass(dynamic_cast<SubClass&>(*this));
    }
};

class Princesa: public Clone<Personaje, Princesa>{
public:
    Princesa(string n){
        nombre = n;
    }
    // Copy Constructor
    Princesa(const Princesa& p){
        nombre = p.nombre;
        telefono = p.telefono;
        correo = p.correo;
        mundo = new Mundo(p.mundo->nombreMundo);
    }
    void gritar(){ cout << "ahhhhh" << endl; }
};

int main(int argc, char const *argv[]) {

    Princesa* pri = new Princesa("Rapunzel");
    pri->correo = "princesasecuestrada@gmail.com";
    pri->telefono = 551234;
    pri->mundo = new Mundo("Paleta");

    Personaje* priClone = pri->clone();
    pri->mundo->nombreMundo = "Paleton";

    cout << priClone->nombre << endl;
    cout << priClone->correo << endl;
    cout << priClone->telefono << endl;
    cout << priClone->mundo->nombreMundo << endl;

    return 0;
}
