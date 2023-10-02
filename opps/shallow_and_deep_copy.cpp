#include <bits/stdc++.h>
using namespace std;
class Hero
{
private:
    int health;

public:
    char *name;
    int level;
    //Copy constructor
    Hero(Hero &temp){
        char* ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->health=temp.health;
        this->level=temp.level;
    }
    Hero()
    {
        // cout << "Default constructor is called" << endl;
        name=new char[100];
    }
    

    void print()
    {
        cout << "Name: " << name << " ";
        cout << "health: " << health << " ";
        cout << "level: " << level << " ";
        cout<<endl;
    }

    void setname(char name[]){
        strcpy(this->name,name);
    }
    void setlevel(int level){
        this->level=level;
    }
    void sethealth(int health){
        this->health=health;
    }
};
int main()
{
    Hero h1;
    char name[] = "Babbar";
    h1.setname(name);
    h1.sethealth(100);
    h1.setlevel(54);
    h1.print();

    //use default copy constructor
    // cout<<"1"<<endl;
    // Hero h2;
    Hero h2=h1;
    
    
    // cout<<"1"<<endl;
    // h2.print();
    // h1.name[0]='G';
    
    h1.print();
    h2.print();
    return 0;
}