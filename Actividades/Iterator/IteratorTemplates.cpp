#import <iostream>
#import <string>

using namespace std;

template <class T>
class Iterator;

template <class T>
class Collection{
protected:
    T* array;
    int size;
    int cont;
public:
    friend class Iterator<T>;
    Collection(){
        size = 10;
        array = new T(size);
        cont = 0;
    }
    void add(T value){
        if(cont <= size){
            array[cont++] = value;
            return;
        }
        cout << "Ya no hay espacio para agregar el elemento" << endl;
    }
    Iterator<T>* getIterator();

    T at(int position){
        return array[position];
    }

};

template <class T>
class Iterator{
protected:
    Collection<T> collection;
    int cont;
public:
    Iterator(const Collection<T>& coll){
        collection = coll;
        cont = 0;
    }

    bool hasNext(){
        if(cont < collection.cont){
            return true;
        }
        return false;
    }

    T next(){
        return collection.at(cont++);
    }
};

template <class T>
Iterator<T>* Collection<T>::getIterator(){
    return new Iterator<T>(*this);
}

template <class T, class Function>
void find_if(Collection<T> collection, Function func){
    Iterator<T>* it = collection.getIterator();
    T next;
    while(it->hasNext()){
        next = it->next();
        if(func(next)){
            cout << next << endl;
        }
    }
    delete it;
}

template <class T>
bool even(T number){
    if(number % 2 == 0){
        return true;
    }

    return false;
}

int main(int argc, char const *argv[]) {

    Collection<int> i;
    i.add(1);
    i.add(4);
    i.add(2);
    i.add(3);

    // Iterator<int>* it = i.getIterator();
    // while(it->hasNext()){
    //     // cout << it->next() << endl;
    // }

    find_if<int, bool(*)(int)>(i,even);

    // delete it;
    return 0;
}
