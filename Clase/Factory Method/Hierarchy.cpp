/* Hierarchy class
Analisis y Modelacion de Software
23/08/17*/

#include <string>
#include <iostream>

using namespace std;

class Product{
public:
    void operation(){
        cout << "product operation" << endl;
    }
    void operation2(){
        cout << "product operation2" << endl;
    }
};

class Creator{
private:
    // This has to be implemented by the children
    virtual Product* createProduct(int type) = 0;
public:
    Product* factoryMethod(int type){
        Product *product = createProduct(type);
        product->operation();
        return product;
    }
};

class CreatorA: public Creator {
public:
    Product* createProduct(int type){
        if (type == 1){
            return new Product;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[]) {

    // FIXME: Creator should be singleton
    // FIXME: Creators implemented with private constructor
    // Creator *c = new Creator;

    Creator *c = new CreatorA;
    Product *product = c->factoryMethod(1);
    product->operation2();

    delete product;
    delete c;

    return 0;
}
