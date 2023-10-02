#include <bits/stdc++.h>
using namespace std;
class peace
{
public:
    int x;

    peace(){//Inbuilt default constructor will die either you create parameterised or normal constructor
        cout<<"default constructor is called"<<endl;
    }

    //Parametarised constructor
    peace(int x){
        (*this).x=x; //this will have adress of the object through which peace function is bieng called
        cout<<"Inside"<<endl;
        cout<<this<<endl;
        // this->x=x;
    }
};
int main()

{
    
    cout<<"Before"<<endl;
    peace *p1 = new peace; //peace *p1 = new peace();
    cout<<"After"<<endl;
    peace h1(5);
    cout<<&h1<<endl;
    cout<<"Outside class"<<endl;
    cout<<h1.x<<endl;
    return 0;
}