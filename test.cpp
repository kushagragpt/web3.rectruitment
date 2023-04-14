
#include <iostream>
#include <cmath>
using namespace std;

class Cars{
    public:
    string make;
    string model;
    int year;
    int speed;
    int x;
    int y;

    Cars(string amake,string amodel,int ayear, int aspeed, int ax,int ay){
        amake=make;
        amodel=model;
        ayear=year;
        aspeed=speed;
        ax=x;
        ay=y;
    }

    void accelerate(int speed_increment){
        speed=speed+speed_increment;
    }

    void brake(int speed_decrement){
        speed=speed-speed_decrement;
    }

    void move(){
        x=x+speed;
        y=y+speed;
    }

    bool detect_collision(Cars *car2){
        int a= x - car2->x;
        int b= y - car2->y;
        int distance=sqrt(a*a + b*b);
        if(distance == 0){
            return true;
        }
        else{
            return false;
        }
    }

    void time_to_collision(Cars *car2){
        int relspeed=speed - car2->speed;
        double time=fabs(x - car2->x);
        if(relspeed==0){
            cout<<"INFINITE";
        }
        else{
            cout<<time;
        }
        
    }

};
int main (){
    
    Cars car1("Hyundai","Alto",1998,50,0,0);
    Cars car2("Maruti","Creta",1898,70,50,50);
    car1.accelerate(10);
    car2.brake(20);
    car1.move();
    car2.move();
    bool collision=car1.detect_collision(&car2);
    cout<<collision<<endl;
    car1.time_to_collision(&car2);



   return 0; 
}