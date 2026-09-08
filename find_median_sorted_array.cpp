#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int size_1 = nums1.size();
        int size_2 = nums2.size();
        int total_size = size_1 + size_2;
        double median;
        

        vector<int> merged_num;

        int i = size_1;
        int j = 0;
         

        while (i < total_size){
            nums1.push_back(nums2[j]);
            j++;
            i++;
        }

        sort(nums1.begin(), nums1.end());  // sort the array

        if (total_size % 2 == 0){
            median = 0.5*(nums1[total_size/2-1] + nums1[(total_size/2)]);
        }
        else{
            median = nums1[total_size/2];
        }

        return median;

        
    }
};

int main(){

    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {8,7};


    Solution sol;

    double median = sol.findMedianSortedArrays(nums1,nums2);

    cout << "The meadian is "<< median  << endl;
     
    return 0;
}