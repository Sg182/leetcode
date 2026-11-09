
#include <iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {

        int head = 1;
        int step = 1;
        int remaining = n;
        bool left = true;

        while (remaining > 1) {

            if (left || remaining % 2 == 1) {
                head += step;
            }

            remaining /= 2;
            step *= 2;
            left = !left;
        }

        return head;
    }
};

int main() {
    Solution sol;

    cout << sol.lastRemaining(1) << endl;

    return 0;
}
