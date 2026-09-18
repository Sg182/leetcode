#include<iostream>
#include<vector>

using namespace std;


class MyCircularQueue {

private:
    vector<int> q;
    int front;
    int rear;
    int count;
    int capacity;
public:
     
    MyCircularQueue(int k) {

        capacity = k;
        q.resize(k);
        front = 0;
        front = 0;
        rear = 0;
        count = 0;
    }
    
    bool enQueue(int value) {

        if (count == capacity){
            return false;
        }

        q[rear] = value;
        rear = (rear + 1)% capacity;

        count++;

        return true;
        
    }
    
    bool deQueue() {
        if (count == 0){
            return false;
        }
        front = (front + 1)% capacity;
        count--;
        return true;
    }
    
    int Front() {

        if (count == 0){
            return -1;
        }

        return q[front];
        
    }
    
    int Rear() {
        if (count == 0){
            return -1;
        }
        int last = (rear-1 + capacity)%capacity;
        return q[last];
        
    }
    
    bool isEmpty() {
        if (count == 0){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    bool isFull() {
        if (count != capacity){
            return false;
        }
        else{
            return true;
        }
        
    }
};

int main(){

    MyCircularQueue cq(5);

    cq.enQueue(5);
    cq.enQueue(6);

    cout << "Front = " << cq.Front() << endl;
    cout << "count = " << cq.Rear() << endl;

    


    return 0;
}