#include<iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> in;
    stack<int> out;

public:
    MyQueue() {
    }

    void push(int x) {
        in.push(x);
    }

    int pop() {

        if (out.empty()) {

            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        int value = out.top();
        out.pop();

        return value;
    }

    int peek() {

        if (out.empty()) {

            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};


int main(){

    MyQueue que;
    que.push(2);
    que.push(81);
    que.pop();
    

    

    cout << que.peek() << endl;

    struct Particle{
        double mass;
        double velocity;

        double Kinetic_energy(){
            return 0.5*mass*velocity*velocity;
        }

    };

    Particle p{2,5};
    cout << p.Kinetic_energy() << endl;

    return 0;
}