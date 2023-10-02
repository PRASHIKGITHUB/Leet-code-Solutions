#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
class Queue
{
public:
    int *arr;
    int start;
    int rear;
    int size;
    Queue()
    {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        start = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (rear == start)
        { // rear pointer donotes next free space
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (!(rear==size))
        {
            arr[rear] = data;
            rear++;
        }
        else
        {
            return;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        int curr;
        if (rear==start)
        {
            return -1;
        }
        else
        {
            curr = arr[start];
            arr[start] = -1;
            start++;
            if (start == rear)
            {
                start = 0;
                rear = 0;
            }
            return curr;
        }
    }

    int front()
    {
        if (start==rear)
        {
            return -1;
        }
        else
        {
            return arr[start];
        }
    }
};