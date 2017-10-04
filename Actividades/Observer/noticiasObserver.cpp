#import <iostream>
#import <string>
#import <vector>
using namespace std;

class Observer{
protected:
    string name;
public:
    void newNews(string news){
        cout << name << endl;
        cout << "\t" << news << endl;
    }
};

class Subject{
protected:
    string name;
    vector<Observer> observers;
public:
    void addObserver(Observer o){
        observers.push_back(o);
    }
    void notify(string n){
        for (int i = 0; i < observers.size(); i++) {
            string s = name + ": " + n;
            observers[i].newNews(s);
        }
    }
};

class MVS: public Observer{
public:
    MVS(){
        name = "MVS";
    }
};

class Televisa: public Observer{
public:
    Televisa(){
        name = "Televisa";
    }
};

class RadioRed: public Observer{
public:
    RadioRed(){
        name = "Radio Red";
    }
};

class Internacionales: public Observer{
public:
    Internacionales(){
        name = "Internacionales";
    }
};

class Trump: public Subject{
public:
    Trump(){
        name = "Trump";
    }
};

class Pena: public Subject{
public:
    Pena(){
        name = "Pena";
    }
};

class Coreano: public Subject{
public:
    Coreano(){
        name = "Coreano";
    }
};

int main(int argc, char const *argv[]) {

    MVS mvs;
    Televisa televisa;
    RadioRed radio;
    Internacionales internacionales;

    Trump trump;
    Pena pena;
    Coreano coreano;

    trump.addObserver(mvs);
    trump.addObserver(televisa);
    trump.addObserver(radio);
    trump.addObserver(internacionales);

    pena.addObserver(televisa);
    pena.addObserver(radio);

    coreano.addObserver(internacionales);

    trump.notify("Soy Trump");
    pena.notify("Soy Peña");
    coreano.notify("Soy Lee");


    return 0;
}
