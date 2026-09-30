#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        double prod=1;
        int left = 0;
        int count = 0;

        if (k <= 1) {
            return 0;
        }

        for(int right = 0; right < nums.size(); right++){

            prod *= nums[right];

            while(prod >= k){
                prod = prod/nums[left];
                left++;

            }

            count+= right - left + 1;
        }


        return count;  
        

    }
};

int main(){

    Solution sol;

    vector<int> nums = {1,7,4,10,3};
    int k =15;

    int count  = sol.numSubarrayProductLessThanK(nums, k);
    cout << "The number of subarrays are "<< count << endl;
}