#import <iostream>
#import <string>
using namespace std;

class Motor{
    int potencia;
    int numSerie;
public:
    // Motor() = default;
    Motor(int p, int n){
        potencia = p;
        numSerie = n;
    }

    int getPotencia(){ return potencia; }
    int getNumSerie(){ return numSerie; }

};

class Alas{
    string marca;
    int numSerie;
    int hiper;
    int spoilers;
public:
    // Alas() = default;
    Alas(string m, int n, int h, int s){
        marca = m;
        numSerie = n;
        hiper = h;
        spoilers = s;
    }

    string getMarca() { return marca; }
    int getNumSerie() { return numSerie; }
    int getHiper() { return hiper; }
    int getSpoilers() { return spoilers; }

};

class Builder;

class Avion{

    Motor* motor;
    Alas* alas;
    string marca;
    string modelo;
    int numSerie;

public:
    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    int getNumSerie() { return numSerie; }
    Motor* getMotor() { return motor; }
    Alas* getAlas() { return alas; }

    void setAlas(Alas* a){ alas = a; }
    void setMotor(Motor* m){ motor = m; }
    void setMarca(string m){ marca = m; }
    void setModelo(string m){ modelo = m; }
    void setNumSerie(int s){ numSerie = s; }
};

class Builder{
protected:
    Avion* avion;
public:
    Avion* getAvion(){ return avion; }
    void createAvion(){
        avion = new Avion;
        Motor* motor = buildMotor();
        avion->setMotor(motor);
        Alas* alas = buildAlas();
        avion->setAlas(alas);
        avion->setMarca(buildMarca());
        avion->setModelo(buildModelo());
        avion->setNumSerie(buildNumSerie());

    }
    virtual Motor* buildMotor() = 0;
    virtual Alas* buildAlas() = 0;
    virtual string buildMarca() = 0;
    virtual string buildModelo() = 0;
    virtual int buildNumSerie() = 0;

};

class BoeingBuilder: public Builder{
public:
    Motor* buildMotor(){
        Motor* motor = new Motor(10000,111111);
        return motor;
    }

    Alas* buildAlas(){
        Alas* alas = new Alas("Boeing",111112,1234,2);
        return alas;
    }
    string buildMarca(){
        return "Boeing";
    }
    string buildModelo(){
        return "747";
    }
    int buildNumSerie(){
        return 111311;
    }
};

class Director{
    Builder* builder;
public:
    void setBuilder(string tipoAvion){
        if (tipoAvion == "Boeing"){
            builder = new BoeingBuilder;
        }
    }
    Avion* getAvion(){
        return builder->getAvion();
    }
    void construct(){
        builder->createAvion();
    }
};

int main(int argc, char const *argv[]) {

    Director d;
    d.setBuilder("Boeing");
    d.construct();

    Avion* avion = d.getAvion();

    cout << avion->getModelo() << endl;

    return 0;
}
