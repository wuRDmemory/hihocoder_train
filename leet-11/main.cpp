#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int max_water = 0;
        while (left <= right) {
            int h = min(height[left], height[right]);
            max_water = max(max_water, h*(right-left));
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_water;
    }
};

int main(int argc, char* argv[]) {
    
    return 1;
}
