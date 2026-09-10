#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {

        stack<int> s;

        int depth;
        int maxlength = 0;
        int i =0;

        while(i < input.size()){

            depth = 0;

            while(i < input.size() && input[i]=='\t'){

                depth++;
                i++;
                }
            int start = i;
            
            // GET THE FILE/DIRECTORY NAME
            while(i < input.size() && input[i]!='\n'){
                 i++;
            }
            string name = input.substr(start, i - start);

            while(s.size()> depth){
                s.pop();
            }

            int current_length = name.size();

            // PUSH THE CURRENT PATH LENGTH
            if (!s.empty()){
                current_length += s.top()+1;
            }

            if (name.find(".") != string::npos){
                maxlength = max(maxlength, current_length);

            }
            else{
                s.push(current_length);
            }

            i++;

        }
        return maxlength;


        
    }
};


int main(){

    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    Solution sol;
    
    int maxl = sol.lengthLongestPath(input);
    cout << maxl <<endl;
     

}