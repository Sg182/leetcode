#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char i : s){

            switch (i) {
                case '(':
                case '{':
                case '[':
                stk.push(i);
                break;
                case ')':
                    if (stk.empty() || stk.top()!= '('){
                        return false;
                }
                    stk.pop();
                    break;
                case '}':
                    if (stk.empty() || stk.top()!= '{') return false;
                    stk.pop();
                    break;

                case ']':
                    if (stk.empty() || stk.top()!= '[') return false;
                    stk.pop();
                    break;
                default:
                    return false;
            }
        }

    return stk.empty();
    }   

};