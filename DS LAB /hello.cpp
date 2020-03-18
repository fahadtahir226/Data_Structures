#include <iostream>
using namespace std;

class Animals{
    string name;
    string voice;
    int maxHeight;
    int averageAge;
    public:
    Animals(string nam,string voic, int maxHight, int aveAge){
        name = nam;
        voice = voic;
        maxHeight = maxHight;
        averageAge = aveAge;
    }
};
class Mammal: public Animals {
    public:
    Mammal(string nam, string voic, int maxHight, int aveAge): Animals(nam, voic, maxHight,aveAge){

    }

    void feeding_milk(){
        cout<< "Feeding Milk from Mamma";
    };

};
class Reptile: public Animals {
    public:
    
    void shedSkin();
    void hibernate();
};
class Birds: public Animals {
    public:
    void fly();
};


int main(){
    Mammal M1("Bear", "Roar", 2, 70);
    M1.feeding_milk();
    return 0;
}