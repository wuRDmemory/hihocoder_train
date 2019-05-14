#include <iostream>

using namespace std;

class Solution {
public:
    string table[4][9]={
        {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, // 0~9
        {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // 10～90
        {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // 100~900
        {"M", "MM", "MMM", "MMM", "MMM", "MMM", "MMM", "MMM", "MMM"}
    };

    string intToRoman(int num) {
        string res="";
        int i=0;
        while(num!=0) {
            int residual = num%10;
            // cout << num << " " << residual << endl;
            if (residual!=0) {
                string cur = table[i][residual-1];
                res = cur+res;
            }
            num = num/10;
            i++;
        }
        return res;
    }
};
int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    Solution solution;
    cout << solution.intToRoman(num) << endl;
    return 1;
}
