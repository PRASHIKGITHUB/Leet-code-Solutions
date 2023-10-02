#include <bits/stdc++.h>
using namespace std;
class hero
{

public:
    char level;
    int health;

    void Sethealth(int x){
        health=x;
    }
    void setlevel(char l){
        level=l;
    }
    hero(int x,char l){
        level=l;
        health=x;
    }
    hero(hero &temp){ //Default copy constructor is dead now
    //passing by reference is very important otherwise it will stuck in infinite loop
    this->health=temp.health;
    this->level=temp.level;
    }
};
int main()
{
    hero h1(100,'l');
    
    cout<<h1.health<<endl;
    cout<<h1.level<<endl;

    hero h2(h1);//This is copy constructor and it's default
//  h2.health=h1.health
//  h2.level=h1.level
//  these are the operations will be done by copy constructor

    cout<<h2.health<<endl;
    cout<<h2.level<<endl;


    return 0;
}