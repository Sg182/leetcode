#include<iostream>
#include<algorithm> //FOR min AND max

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int area1 = (ax2 - ax1)*(ay2 - ay1);
        int area2 = (by2 - by1)*(bx2 - bx1);

        int x1_ovr = max(ax1, bx1);
        int x2_ovr = min(ax2, bx2);

        int y2_ovr = min(ay2, by2);
        int y1_ovr = max(ay1, by1);

        int width = max(0, x2_ovr-x1_ovr);
        int height = max(0, y2_ovr - y1_ovr); //OVERLAP IN y DIRECTION
        

        return area1 + area2 - width*height;


        
    }
};

int main(){

    Solution rec;
    int ax1 = -2; 
    int ay1 = -2; 
    int ax2 = 2; 
    int ay2 = 2; int bx1 = -2; int by1 = -2; int bx2 = 2; int by2 = 2;

    cout << "THE AREA IS " << rec.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
}