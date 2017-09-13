#import <iostream>
using namespace std;

class IntIterator;

class IntCollection{
protected:
    int* array;
    int size;
    int cont;
public:
    friend class IntIterator;
    IntCollection(){
        size = 10;
        array = new int(size);
        cont = 0;
    }
    void add(int value){
        if(cont <= size){
            array[cont++] = value;
            return;
        }
        cout << "Ya no hay espacio para agregar el elemento" << endl;
    }
    IntIterator* getIterator();

    int at(int position){
        return array[position];
    }

};

class IntIterator{
protected:
    IntCollection collection;
    int cont;
public:
    IntIterator(const IntCollection& coll){
        collection = coll;
        cont = 0;
    }

    bool hasNext(){
        if(cont < collection.cont){
            return true;
        }
        return false;
    }

    int next(){
        return collection.at(cont++);
    }
};

IntIterator* IntCollection::getIterator(){
    return new IntIterator(*this);
}

int main(int argc, char const *argv[]) {

    IntCollection i;
    i.add(1);
    i.add(4);
    i.add(2);
    i.add(3);

    IntIterator* it = i.getIterator();
    while(it->hasNext()){
        cout << it->next() << endl;
    }

    delete it;
    return 0;
}
