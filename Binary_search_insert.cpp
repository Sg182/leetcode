#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left;
        int right;
        int mid;
        int size = nums.size();

        left  = 0;
        right = size - 1;

        while (left <= right){

            mid = (left + right)/2;
            if (nums[mid] == target){
                return mid;
                }
            else if (nums[mid] < target){
                left = mid + 1;
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }

        }


    return left;  // IF THE TARGET IS NOT PRESENT. IT RETURNS THE INDEX IT SHOULD BELONG
        }         // TO ON A SORTED ARRAY.
    };


int main(){

    vector<int> nums = {1, 3, 5, 6};

    Solution sol;
    cout << "The index is "<< sol.searchInsert(nums, 8) << endl;
}
