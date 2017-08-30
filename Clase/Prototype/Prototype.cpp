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

class Princesa: public Personaje{
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
    Personaje* clone(){
        // Constructor for copying
        return new Princesa(*this);
    }
};

class Villano: public Personaje{
public:
    Villano(string n){
        nombre = n;
    }
    // Copy Constructor
    Villano(const Villano& p){
        nombre = p.nombre;
        telefono = p.telefono;
        correo = p.correo;
        mundo = new Mundo(p.mundo->nombreMundo);
    }
    void secuestrar(){ cout << "te atrapé" << endl; }
    Personaje* clone(){
        return new Villano(*this);
    }
};

class Heroe: public Personaje{
public:
    Heroe(string n){
        nombre = n;
    }
    // Copy Constructor
    Heroe(const Heroe& p){
        nombre = p.nombre;
        telefono = p.telefono;
        correo = p.correo;
        mundo = new Mundo(p.mundo->nombreMundo);
    }
    void salvar(){ cout << "te salvé" << endl; }
    Personaje* clone(){
        return new Heroe(*this);
    }
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
