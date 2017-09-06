/* Compumarte class
Analisis y Modelacion de Software
06/08/17*/

#include <iostream>
#include <string>
using namespace std;

class Computadora{
private:
    string tipo;
public:
    void seleccionComponentes() { cout << "Selección de componentes" << endl; }
    void ensambladoComponentes() { cout << "Ensamblado de componentes" << endl; }
    void instalacionSoftware() { cout << "Instalación y configuración de Software" << endl; }
    void empaquetado() { cout << "Instalación y configuración de Software" << endl; }
    void setTipo(string t) { tipo = t; }
    string getTipo() { return tipo; }
    template <class Tipo>
    Tipo* factoryMethod(){
        return new Tipo;
    }
};

class Desktop: public Computadora{
private:
    Desktop();
};
class Laptop: public Computadora{
private:
    Laptop();
};
class Netbook: public Computadora{
private:
    Netbook();
};
class Tablet: public Computadora{
private:
    Tablet();
};
class Server_Rack: public Computadora{
private:
    Server_Rack();
};
class Server_Tower: public Computadora{
private:
    Server_Tower();
};

class Creacion{
public:
    Computadora* crear(int type){
        Computadora* c = new Computadora;
        Computadora* child = new Computadora;
        switch (type) {
            case 1:{
                child = c->Computadora::factoryMethod<Desktop>();
                child->setTipo("desktop");
                break;
            }
            case 2:{
                child = c->Computadora::factoryMethod<Laptop>();
                child->setTipo("laptop");
                break;
            }
            case 3:{
                child = c->Computadora::factoryMethod<Netbook>();
                child->setTipo("netbook");
                break;
            }
            case 4:{
                child = c->Computadora::factoryMethod<Tablet>();
                child->setTipo("tablet");
                break;
            }
            case 5:{
                child = c->Computadora::factoryMethod<Server_Rack>();
                child->setTipo("server rack");
                break;
            }
            case 6:{
                child = c->Computadora::factoryMethod<Server_Tower>();
                child->setTipo("server tower");
                break;
            }
            default:{
                child = c->Computadora::factoryMethod<Laptop>();
                child->setTipo("laptop");
                break;
            }
        }
        return child;
    }
};

int main(int argc, char const *argv[]) {
    Creacion* creacion = new Creacion();
    cout << "------------------------" << endl;
    cout << "|                       |" << endl;
    cout << "|          Menú         |" << endl;
    cout << "|                       |" << endl;
    cout << "| 1) Desktop            |" << endl;
    cout << "| 2) Laptop             |" << endl;
    cout << "| 3) Netboook           |" << endl;
    cout << "| 4) Tablet             |" << endl;
    cout << "| 5) Server Rack        |" << endl;
    cout << "| 6) Server Tower       |" << endl;
    cout << "|                       |" << endl;
    cout << "------------------------" << endl;
    int ans = 0;
    cin >> ans;
    Computadora* c = creacion->crear(ans);
    cout << c->getTipo() << endl;
    return 0;
}
