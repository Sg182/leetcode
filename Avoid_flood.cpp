/* LLETCODE : Your country has 109 lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water.
 If it rains over a lake that is full of water,
 there will be a flood. Your goal is to avoid floods in any lake.

Given an integer array rains where:

rains[i] > 0 means there will be rains over the rains[i] lake.
rains[i] == 0 means there are no rains this day and you must choose one lake this day and dry it.
Return an array ans where:

ans.length == rains.length
ans[i] == -1 if rains[i] > 0.
ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. 
If it is impossible to avoid flood return an empty array.*/

#include<iostream>
#include<set>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int size = rains.size();
        vector<int> ans(size);
         

        unordered_map<int,int> lastRain;
        set<int> dryDays;

        for (int i=0; i< size; i++){

            if (rains[i] == 0){
                dryDays.insert(i);
            }

            else{

                int lake = rains[i];
                ans[i] = -1;

                //CHECK IF THE RAIN HAPPENS ON LAKE i AGAIN
                if (lastRain.find(lake) != lastRain.end()){
                    int previous_day = lastRain[lake];  //RETURNS THE LAST DAY
                                                        // OF RAIN

                    auto it = dryDays.upper_bound(previous_day);

                    if(it == dryDays.end()){
                        return {};
                    }
                    
                    int dryDay = *it;
                    ans[dryDay] = lake;
                    dryDays.erase(*it);

                }

            lastRain[lake] = i; //RECORD THE CURRENT LAKE AND DATE
            }   
    
}       return ans;
}};


int main(){

    vector<int> rains = {1,2,0,0,2,1};

    Solution sol;
    vector<int> ans = sol.avoidFlood(rains);
    for ( int x : ans ){
        cout << x;
         
    };
    
    return 0;
};