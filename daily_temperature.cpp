
#include<iostream>
#include<vector>
#include<stack>
using namespace std;



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

         
        stack<int> st;
        int size = temperatures.size();
        vector<int> answer(size,0);
        int i;
        
        for(i = 0; i < size; i++){
             
            while (!st.empty() && temperatures[i]>temperatures[st.top()]){
                 
                answer[st.top()] = i - st.top();
                st.pop();

            }

            st.push(i);
             

        }
        return answer;
        
    }
};

int main(){

    cout <<"THIS IS A STACK PROBLEM"<< endl;
    return 0;
}