#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;
        int right = 0;
        int tatol =nums1.size()+nums2.size(); 
        int mdl = (nums1.size()+nums2.size()+1)/2;

        nums1.emplace_back(INT32_MAX);
        nums2.emplace_back(INT32_MAX);

        vector<int> nums;
        nums.reserve(nums1.size()+nums2.size());

        while(nums.size() <= mdl && left < nums1.size() && right < nums2.size()) {
            if (nums1[left] <= nums2[right]) {
                nums.emplace_back(nums1[left]);
                left++;
            } else {
                nums.emplace_back(nums2[right]);
                right++;
            }
        }
        
        if (tatol % 2==0) {
            int idx = tatol/2;
            return (nums[idx-1]+nums[idx])/2.0;
        } else {
            int idx = tatol/2;
            return nums[idx];
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    Solution solution;
    double m = solution.findMedianSortedArrays(nums1, nums2);
    cout << m << endl;
    return 1;
}

