#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign_idx = -1;
        int start = -1, end = str.length();
        for (int i=0; i<str.length(); i++) {
            if (start == -1) {
                if (str[i]=='-' || str[i] == '+') {
                    if (sign_idx!=-1) {
                        return 0;
                    }
                    sign_idx = i;
                } else if ((str[i] >= '0' && str[i] <= '9')) {
                    if (sign_idx == -1 || sign_idx == i-1) {
                        start = i;
                    } else {
                        return 0;
                    }
                } else if (str[i]!=' ') {
                    return 0;
                } 
            } else {
                if (!(str[i] >= '0' && str[i] <= '9')) {
                    end = i;
                    break;
                }
            }
        }
        if (start < 0) {
            return 0;
        }
        char sign = 1;
        if (sign_idx != -1) {
            sign = str[sign_idx]=='-' ? -1 : 1;
        }

        string resstr = str.substr(start, end-start);
        long d = sign*atol(resstr.c_str());
        if (d > INT32_MAX) {
            return INT32_MAX;
        } else if (d < INT32_MIN) {
            return INT32_MIN;
        } else {
            return d;
        }
    }
};

class Solution1 {
public:
    int myAtoi(string str) {
        int sign = 1;
        int i=0;
        long res = 0;
        while (i<str.length() && str[i]==' ') {
            i++;
        }

        if (i<str.length() && (str[i]=='-' || str[i] == '+')) {
            sign = str[i]=='-'? -1 : 1;
            i++;
        }
        while (i<str.length() && str[i] >= '0' && str[i] <= '9') {
            if (res > INT32_MAX/10 || (res >= INT32_MAX/10 && str[i]-'0'>7)) {
                if (sign==1) return INT32_MAX;
                else return INT32_MIN;
            } 
            res = res*10 + (str[i]-'0');
            i++;
        }
        return res*sign;
    }
};

int main(int argc, char* argv[]) {
    string str(argv[1]);
    Solution1 solution;
    cout << solution.myAtoi(str) << endl;
    return 1;
}
