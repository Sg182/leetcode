#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class RecentCounter {
public:

    vector<int> out;
    int count;
    int front;
    int rear;
    queue<int> q;

    RecentCounter() {

        while (!q.empty()) {
        q.pop();
}

    }
    
    int ping(int t) {

        int count = 0;
        int len = q.size();
        int max = t;
        int min = t - 3000;
        q.push(t);


        while (!q.empty() && q.front()< min){
                q.pop();
                 
            }
            count = q.size();
            
            out.push_back(count);

        return count;
            
    }   


};


int main(){

    return 0;
}