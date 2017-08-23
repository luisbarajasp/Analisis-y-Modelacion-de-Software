/* Clock class
Analisis y Modelacion de Software
23/08/17*/

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Clock{
protected:
    static Clock* instance;
private:
    Clock(){
    }
public:
    static Clock* getInstance(){
        if (!instance) {
            instance = new Clock;
        }
        return instance;
    }
    void operation(){
        time_t t = time(0);   // get time now
        struct tm * timeinfo;
        timeinfo = localtime (&t);
        cout << asctime(timeinfo) << endl;
    }
};

Clock* Clock::instance = 0;

int main(int argc, char const *argv[]) {

    Clock* instance = Clock::getInstance();
    instance->operation();

    return 0;
}
