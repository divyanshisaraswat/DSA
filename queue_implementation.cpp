#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int frontIndex;
    int rear;
    int size;
public:
    Queue() {
        // Implement the Constructor
        size= 1000001;
        arr= new int[size];
       frontIndex=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(frontIndex== rear){
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size){
            cout<<"Queue is full"<<endl;
        }
        else {
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
       if(frontIndex == rear){
          return -1;
       }
       else {
           int ans=arr[frontIndex];
           arr[frontIndex] =-1;
           frontIndex++;
           if(frontIndex==rear){
               frontIndex=0;
               rear=0;
           }
           return ans;
       }
    }

    int front() {
        if(frontIndex==rear){
            return -1;
        }
        else {
            return arr[frontIndex];
        }
    }
};
