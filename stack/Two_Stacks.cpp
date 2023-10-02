#include <bits/stdc++.h> 
class TwoStack {
    int* arr;
    int size;
    int topindex1;
    int topindex2;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->size=s;
        topindex1=-1;
        topindex2=s;
        arr=new int[size];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(topindex1+1<topindex2){
            arr[++topindex1]=num;
        }
        else{
            return;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(topindex2-1>topindex1){
            arr[--topindex2]=num;
        }
        else{
            return;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(topindex1>-1){
            topindex1--;
            return arr[topindex1+1];
        }
        else{
            return -1 ;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(topindex2<size){
            topindex2++;
            return arr[topindex2-1];
        }
        else{
            return -1;
        }
    }
};