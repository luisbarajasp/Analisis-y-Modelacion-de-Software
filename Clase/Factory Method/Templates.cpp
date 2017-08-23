/* Hierarchy class
Analisis y Modelacion de Software
23/08/17*/

#include <string>
#include <iostream>

using namespace std;

class FactoryProduct{
public:
    template <class Prod>
    Prod* factoryMethod(){
        return new Prod;
    }
};

class ProductA: public FactoryProduct {
public:
    void operation(){
        cout << "producto A" << endl;
    }
};

int main(int argc, char const *argv[]) {

    FactoryProduct* p = new FactoryProduct;
    ProductA* a = p->factoryMethod<ProductA>();
    a->operation();

    return 0;
}
