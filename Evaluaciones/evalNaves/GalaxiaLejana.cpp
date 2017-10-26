/* Segunda evlacuación
Analisis y Modelacion de Software
25/09/17*/

#include <string>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#define SIZE 10

class GeneralObject{
protected:
  int x;
  int y;
  int id;
  string type;
  bool alive;
public:
    GeneralObject(){
        alive = true;
        x = rand() % SIZE;
        y = rand() % SIZE;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getId(){
        return id;
    }
    void move(int _x, int _y){
        x = _x;
        y = _y;
    }
    void collided(){
        alive = false;
    }
    bool isAlive(){
        return alive;
    }
    void setId(int _id){
        id = _id;
    }
    string getType(){
        return type;
    }
};

class ObjectIterator;

class ObjectCollection{
protected:
    GeneralObject *array[12];
    int size;
    int cont;
public:
    friend class ObjectIterator;
    ObjectCollection(){
        cont = 0;
        size = 12;
    }
    void add(GeneralObject* value){
        if(cont <= size){
            array[cont++] = value;
            value->setId(cont);
            return;
        }
        cout << "Ya no hay espacio para agregar el elemento" << endl;
    }
    ObjectIterator* getIterator();

    GeneralObject* at(int position){
        return array[position];
    }

};

class ObjectIterator{
protected:
    ObjectCollection collection;
    int cont;
public:
    ObjectIterator(const ObjectCollection& coll){
        collection = coll;
        cont = 0;
    }

    bool hasNext(){
        if(cont < collection.cont){
            return true;
        }
        return false;
    }

    GeneralObject* next(){
        return collection.at(cont++);
    }

    int index(){
        return cont;
    }
};

ObjectIterator* ObjectCollection::getIterator(){
    return new ObjectIterator(*this);
}

class Board{
protected:
    ObjectCollection objects;
    int board[SIZE][SIZE];
public:
    Board(){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = 0;
            }
        }
    }
    void addObserver(GeneralObject* o){
        objects.add(o);
    }
    void moveBoard(){
        ObjectIterator* it = objects.getIterator();
        GeneralObject* object;

        cout << endl;

        while(it->hasNext()){
            object = it->next();
            if(object->isAlive()){
                int prevX = object->getX();
                int prevY = object->getY();

                int diffX = 0;
                int diffY = 0;

                int movement = rand() % 8;

                if(prevX == 9 && (movement > 4)){

                    movement -= 4;

                }

                if(prevY == 9){
                    if (movement < 2){
                        movement += 4;
                    }

                    if (movement > 6){
                        movement -= 4;
                    }
                }

                if(prevX == 0 && (movement > 0 && movement < 4)){

                    movement += 4;

                }

                if(prevY == 0){
                    if (movement > 2 && movement < 6){
                        movement -= 3;
                    }
                }

                switch (movement) {
                    case 0:
                    diffY++;
                    break;
                    case 1:
                    diffX--;
                    diffY++;
                    break;
                    case 2:
                    diffX--;
                    break;
                    case 3:
                    diffX--;
                    diffY--;
                    break;
                    case 4:
                    diffY--;
                    break;
                    case 5:
                    diffX++;
                    diffY--;
                    break;
                    case 6:
                    diffX++;
                    break;
                    case 7:
                    diffX++;
                    diffY++;
                    break;
                    default:
                    break;
                }

                int x = prevX + diffX;
                int y = prevY + diffY;

                // If this position in board is equal to -1, it means this position is blocked
                while(board[x][y] == -1){
                    movement = rand() % 8;

                    if(prevX == 9 && (movement > 4)){

                        movement -= 4;

                    }

                    if(prevY == 9){
                        if (movement < 2){
                            movement += 4;
                        }

                        if (movement > 6){
                            movement -= 4;
                        }
                    }

                    if(prevX == 0 && (movement > 0 && movement < 4)){

                        movement += 4;

                    }

                    if(prevY == 0){
                        if (movement > 2 && movement < 6){
                            movement -= 3;
                        }
                    }

                    switch (movement) {
                        case 0:
                        diffY++;
                        break;
                        case 1:
                        diffX--;
                        diffY++;
                        break;
                        case 2:
                        diffX--;
                        break;
                        case 3:
                        diffX--;
                        diffY--;
                        break;
                        case 4:
                        diffY--;
                        break;
                        case 5:
                        diffX++;
                        diffY--;
                        break;
                        case 6:
                        diffX++;
                        break;
                        case 7:
                        diffX++;
                        diffY++;
                        break;
                        default:
                        break;
                    }

                    x = prevX + diffX;
                    y = prevY + diffY;
                }

                board[prevX][prevY] = 0;

                object->move(x,y);

                cout << "\t" << object->getId() << ": \tPosition: " << x << " , " << y << "\n\t\tType: " << object->getType() << endl;

                bool collision = board[x][y] > 0 ? true : false;

                GeneralObject* otherObject = objects.at(board[x][y] - 1);

                board[x][y] = object->getId();

                if(collision){
                    // Collision
                    object->collided();
                    otherObject->collided();
                    cout << "Collided " << object->getId() << " with " << otherObject->getId() << endl;
                    board[x][y] = -1;
                    cout << "COLLISION DETECTED:\n\tBetween " << object->getId() << " and " << otherObject->getId() << "\n\tIn ( " << x << " , " << y << " )" << endl;
                }

            }
            cout << endl;

            // cout << "(" << x << " , " << y << ")" << endl;

        }

        cout << endl;

        delete it;
    }

    void printBoard(){
        cout << endl;
        for (int i = 0; i < SIZE; i++) {
            if(i == 0){
                cout << "     0  1  2  3  4  5  6  7  8  9 " << endl;
                cout << "  --------------------------------" << endl;
            }
            cout << i << " | ";
            for (int j = 0; j < SIZE; j++) {
                if(board[i][j] < 10 && board[i][j] > -1){
                    cout << " " << board[i][j] << " ";
                }else{
                    cout << board[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

template<typename T>
class Object: public GeneralObject{
protected:
    static T* instance;

    Object(){
    }
public:
    static T* getInstance(){
        if (!instance) {
            instance = new T;
        }
        return instance;
    }
};

template<typename T>
T* Object<T>::instance = NULL;

class ExplorationSpacecraft: public Object<ExplorationSpacecraft>{
public:
    ExplorationSpacecraft(){
        type = "Planet exploration ships";
    }
};

class ColonizationSpacecraft: public Object<ColonizationSpacecraft>{
public:
    ColonizationSpacecraft(){
        type = "Colonization ships";
    }
};

class ObservationSpacecraft: public Object<ObservationSpacecraft>{
public:
    ObservationSpacecraft(){
        type = "Planet observation ships";
    }
};

class StonyAsteroid: public Object<StonyAsteroid>{
public:
    StonyAsteroid(){
        type = "Stony meteorites";
    }
};

class IronAsteroid: public Object<IronAsteroid>{
public:
    IronAsteroid(){
        type = "Iron meteorites";
    }
};

class DesertPlanet: public Object<DesertPlanet>{
public:
    DesertPlanet(){
        type = "Desert planet";
    }
};

class EarthPlanet: public Object<EarthPlanet>{
public:
    EarthPlanet(){
        type = "Earth analog";
    }
};

/*class Spacecraft: public Object<Spacecraft>{
public:
    Spacecraft(){
        type = rand() % 3;
    }
};

class Asteroid: public Object<Asteroid>{
public:
    Asteroid(){
        type = rand() % 2;
    }
};

class Planet: public Object<Planet>{
public:
    Planet(){
        type = rand() % 2;
    }
};*/

int main(int argc, char const *argv[]) {

    /* initialize random seed: */
    srand (time(NULL));

    // string types[3] = {"Planet exploration ships", "Colonization ships", "Planet observation ships"}

    // int universe[SIZE][SIZE];

    Board universe;

    // for (int i = 0; i < 4; i++) {
    //     /* code */
    // }

    ExplorationSpacecraft* eSpacecraft = ExplorationSpacecraft::getInstance();
    ColonizationSpacecraft* cSpacecraft = ColonizationSpacecraft::getInstance();
    ObservationSpacecraft* oSpacecraft = ObservationSpacecraft::getInstance();


    StonyAsteroid* sAsteroid = StonyAsteroid::getInstance();
    IronAsteroid* iAsteroid = IronAsteroid::getInstance();


    DesertPlanet* dPlanet = DesertPlanet::getInstance();
    EarthPlanet* ePlanet = EarthPlanet::getInstance();


    universe.addObserver(eSpacecraft);
    universe.addObserver(cSpacecraft);
    universe.addObserver(oSpacecraft);
    universe.addObserver(sAsteroid);
    universe.addObserver(iAsteroid);
    universe.addObserver(dPlanet);
    universe.addObserver(ePlanet);

    char ans = 'y';

    while(ans == 'y'){
        universe.moveBoard();
        universe.printBoard();
        cout << "Make move? (y/n)";
        cin >> ans;
    }

    // Singleton* instance2 = Singleton::getInstance();
    // instance2->operation();
    //
    // Singleton* instance3 = Singleton::getInstance();
    // instance3->operation();

    return 0;
}
