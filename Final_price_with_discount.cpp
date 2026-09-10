/*You are given an integer array prices where prices[i] is the price of the ith item in a shop.


There is a special discount for items in the shop. If you buy the ith item, 
then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. 
Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, 
considering the special discount.*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{

    public:
    vector<int> finalPrices(vector<int>& prices) {

        vector<int> answers=prices;
        stack<int> s;

        for (int i=0; i< prices.size(); i++){

            while(!s.empty() && prices[i] <= prices[s.top()]){

                int j = s.top();
                s.pop();
                answers[j] = prices[j] - prices[i];
            }

            s.push(i);
        }
        return answers;

    }
     

};

int main(){

    vector<int> price = {10,1,1,6};
    Solution sol;
    
    vector<int> answer = sol.finalPrices(price);
    for (int x : answer){
        cout << x<< " ";
    }

}