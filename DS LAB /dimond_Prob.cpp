#include <iostream>
using namespace std;



//************************** K181354     K180286     K180150 ****************************



class Vehicles{
    string name, modle;

    public:
    Vehicles(string nam,string Model){
        name = nam;
        modle = Model;
        cout<<"Vehicles constructor"<<endl;

    }
};
class Cars: virtual public Vehicles {
    public:
    void ac(){

    }
    Cars(string nam,string modl): Vehicles(nam,modl){
            cout<<"Car constructor"<<endl;
    }

};
class Bikes: virtual public Vehicles {
    public:
    Bikes(string nam,string modl): Vehicles(nam,modl){
        cout<<"Bike constructor"<<endl;
    }
    void One_Vehile(){

    }

};


class Rickshaw: public Cars, public Bikes {
public :
    Rickshaw(string nam,string modl): Cars(nam,modl), Bikes(nam,modl), Vehicles(nam,modl) {
        cout<< "Rickshaw Constructor"<<endl ;
    }
};


int main(){
    Rickshaw R1("CNG", "2018");
    
    return 0;
}