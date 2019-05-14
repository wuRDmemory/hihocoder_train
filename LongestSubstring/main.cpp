#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char, int> char_idx_map;
//         int max_len = -1;
//         for (int i=0;i<s.size(); i++) {
//             char c = s[i];
//             auto iter = char_idx_map.find(c);
//             if (iter != char_idx_map.end()) {
//                 max_len = max(i - iter->second, max_len);
//                 for (auto b = char_idx_map.begin(); b!=iter;) {
//                     b = char_idx_map.erase(b);
//                 }
//             } else {
//                 char_idx_map[c] = i;
//             }
//         }
//         if (max_len < 0) {
//             max_len = s.size();
//         }
//         return max_len;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        unordered_map<char, int> char_idx_map;
        int max_len = -1;
        int bbegin = -1;
        for (int i=0;i<s.size(); i++) {
            char c = s[i];
            auto iter = char_idx_map.find(c);
            if (iter != char_idx_map.end()) {
                if (iter->second > bbegin) {
                    bbegin = iter->second;
                }
                max_len = max(i - bbegin, max_len);
                iter->second = i;
            } else {
                char_idx_map[c] = i;
                max_len = max(max_len, i-bbegin);
            }
        }
        // max_len = max((int)s.size()-bbegin, max_len);
        return max_len;
    }
};

int main(int argc, char* argv[]) {
    string str(argv[1]);
    cout << str << endl;
    Solution solution;
    int max_len = solution.lengthOfLongestSubstring(str);
    cout << max_len << endl;
    return 1;
}
