#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.find('.', 0)==string::npos && p.find('*',0)==string::npos) {
            return s==p;
        }
        int idx1 = 0, idx2 = 0;
        bool stop = false;
        while (idx1<s.length()) {
            if (idx2>=p.length()) {
                cout << "???" << endl;
                cout << p.length() << " " << idx2 << " " << idx1 << endl;
                return false;
            }
            if (s[idx1] == p[idx2]) {
                idx1++; idx2++;
            } else {
                if (p[idx2]=='.') {
                    if (idx2+1 < p.length() && p[idx2+1]=='*') {
                        p.insert(idx2, 1, '.');   
                    }
                    p[idx2] = s[idx1];
                    idx1++; idx2++;
                } else if (p[idx2]=='*') {
                    if (idx2-1 >= 0 && p[idx2-1]==s[idx1]) {
                        p.insert(idx2, 1, '*');
                        p[idx2] = s[idx1];
                        idx1++; idx2++;
                    } else if (idx2+1 < p.length() && (p[idx2+1]==s[idx1] || p[idx2+1]=='.')) {
                        idx2++;
                    } else {
                        cout << "asdsd23231 " << s << " " << p <<  endl;
                        return false;
                    }
                } else if(idx2+1 < p.length() && p[idx2+1]=='*') {
                    cout << "asd11" << " " << idx1 << " " << idx2 << endl;
                    idx2 += 2;
                } else {
                    return false;
                }
            }
        }
        return s.back()==p.back() || p.back()=='.' || p.back()=='*';
    }
};

int main(int argc, char* argv[]) {
    string str_s(argv[1]);
    string str_p(argv[2]);

    Solution solution;
    cout << solution.isMatch(str_s, str_p) << endl;

    return 1;
}
