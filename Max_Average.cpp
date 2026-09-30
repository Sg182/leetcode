#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        deque<int> dq;
        double avg = 0;

        for(int i=0; i<k; i++){
            avg+= nums[i];
             
        }

        double maxavg = avg;

        for(int i = k; i < nums.size(); i++){
            avg = avg + nums[i] - nums[i-k];
            /*if (avg > maxavg){
                maxavg = avg;
            }*/
            maxavg = max(maxavg,avg);

        }

        return maxavg/k; 
        
    }
};


int main(){

    Solution sol;

    int k = 3;
    vector<int> num = {1,8,0,-2,12,-30,4};

    cout << sol.findMaxAverage(num,k) << endl;
    cout << "Length of num is " << num.size() << endl;

    int* p;
    int x = 4;
    p = &x;
    cout << "Address of x is " << p << " and inside it is "<< *p << endl;

}