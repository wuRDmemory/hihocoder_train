#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        if (nums.empty()) {
            return target;
        }
        
        int min_ret = 0;
        int min_dis = INT32_MAX;
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size(); i++) {
            if (i<2) continue;
            int res = target - nums[i];
            int left=0, right=i-1;
            while(left < right) {
                int sum = nums[left]+nums[right];
                int abs_dis = abs(sum - res);
                if (abs_dis < min_dis) {
                    min_dis = abs_dis;
                    min_ret = sum+nums[i];
                }
                if (sum < res) {
                    left++;
                } else if (sum > res) {
                    right--;
                } else {
                    break;
                }
            }
            // printf("%d, %d, %d, %d, %d\n", min_v, min_ret, nums[left], nums[right], nums[i]);
        }
        return min_ret;
    }
};

int main(int argc, char* argv[]) {
    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums = {1,2,4,8,16,32,64,128};// {-1,2,1,-4};
    int target = 82;
    Solution solution;
    cout << solution.threeSumClosest(nums,target) << endl;

    return 1;
}
