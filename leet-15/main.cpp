#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int> > ret;
//         if (nums.empty()) {
//             return ret;
//         }

//         set<vector<int> > results;
//         unordered_map<int, int> maps;
//         for (int i=0; i<nums.size(); i++) {
//             if (i >= 2) {
//                 unordered_map<int, int> maps_copy = maps;
//                 int res = 0-nums[i];
//                 for (auto& pair: maps_copy) {
//                     int res_1 = res-pair.first;
//                     pair.second -= 1;
//                     if (maps_copy.find(res_1)!=maps_copy.end() && maps_copy[res_1]>0) {
//                         // cout << nums[i] << " " << pair.first << " " << res_1 << endl;
//                         int a = max(nums[i], max(pair.first, res_1));
//                         int c = min(nums[i], min(pair.first, res_1));
//                         int b = 0-a-c;
//                         vector<int> numss = {c, b, a};
//                         results.insert(numss);
//                     }
//                     pair.second += 1;
//                 }
//             }
            
//             if (maps.find(nums[i]) == maps.end()) {
//                 maps.insert(make_pair(nums[i], 1));
//             } else {
//                 maps[nums[i]]++;
//             }
//         }
        
//         for (auto begin = results.begin(); begin != results.end(); begin++) {
//             ret.emplace_back(*begin);
//         }
//         return ret;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if (nums.empty()) {
            return ret;
        }
        sort(nums.begin(), nums.end());
        set<vector<int> > results;
        for (int i=0;i<nums.size(); i++) {
            if (i < 2) continue;
            int res = -nums[i];
            int left=0, right=i-1;
            while (left < right) {
                int sum = nums[left]+nums[right];
                if (sum < res) {
                    left++;
                } else if (sum > res) {
                    right--;
                } else {
                    vector<int> elem = {nums[left], nums[right], nums[i]};
                    // ret.emplace_back(elem);
                    results.insert(elem);

                    while(left < right && nums[left] == elem[0]) left++;
                    while(left < right && nums[right] == elem[1]) right--;
                }
            }

        } 
        for (auto begin = results.begin(); begin != results.end(); begin++) {
            ret.emplace_back(*begin);
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums = {0,0,0,0};
    Solution solution;
    vector<vector<int> > res = solution.threeSum(nums);

    for (auto& vs : res) {
        for (int v : vs) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 1;
}
