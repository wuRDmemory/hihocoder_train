#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        string str = to_string(x);
        int left = 0, right = str.length()-1;
        while(left <= right) {
            if (str[left] != str[right]) {
                return false;
            } else {
                left ++;
                right --;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    int i=atoi(argv[1]);
    Solution solution;
    cout << solution.isPalindrome(i) << endl;
    return 1;
}
