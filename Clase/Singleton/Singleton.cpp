/* Singleton class
Analisis y Modelacion de Software
23/08/17*/

#include <string>
#include <iostream>

using namespace std;

class Singleton{
protected:
    static Singleton* instance;
private:
    Singleton(){
    }
public:
    static Singleton* getInstance(){
        if (!instance) {
            instance = new Singleton;
        }
        return instance;
    }
    void operation(){
        cout << "Direccion de Singleton: " << instance << endl;
    }
};

Singleton* Singleton::instance = 0;

int main(int argc, char const *argv[]) {

    Singleton* instance = Singleton::getInstance();
    instance->operation();

    Singleton* instance2 = Singleton::getInstance();
    instance2->operation();

    Singleton* instance3 = Singleton::getInstance();
    instance3->operation();

    return 0;
}
