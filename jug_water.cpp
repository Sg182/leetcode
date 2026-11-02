#include<iostream>
#include<numeric>


// FOR THIS PROBLEM x + y >= target
using namespace std;

class Solution {
public:

    int gcd(int x, int y){
        while(y!=0){
        int remainder = x % y;
        x = y;
        y = remainder;
        }
        return x;



    }
    bool canMeasureWater(int x, int y, int target) {

        if (target == 0) return true;

        if (target > x + y) return false;

        int g = gcd(x,y);

        return g!= 0 && target % g == 0;
    }
        
};


int main(){

    int x = 2;
    int y = 5;
    int target = 4;

    Solution s;
    cout << s.canMeasureWater(x,y, target)<< endl;
}