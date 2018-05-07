#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#if 0

int find_sub_str(string& origin) {

    int max_cnt = 0;
    string revert_str(origin);
    reverse(revert_str.begin(), revert_str.end());
    for (int i = 0; i < origin.length(); ++i) {
        for (int j = i+3; j <= origin.length(); ++j) {
            string sub = origin.substr(i, j-i);
            if (revert_str.find(sub.c_str(), i) != string::npos)
                max_cnt = std::max(max_cnt, j-i);
        }
        if (max_cnt == origin.length()-i)
            break;
    }
    return max_cnt;
}
#else

int find_sub_str(string& origin) {
    string str;
    int origin_len = origin.length();
    str.resize(origin_len*2+3);

    str[0] = '$';
    str[1] = '#';

    for (int i = 0; i < origin_len; ++i) {
        str[i*2+2] = origin[i];
        str[i*2+3] = '#';
    }
    str[origin_len*2+2] = '@';

    int new_str_len = str.length();
    int* p = new int[new_str_len];
    p[1] = 1;
    int id = 1;
    int max_LPS = 1;
    for (int i = 1; i < new_str_len-1; i++) {
        if (p[id] + id - 1 > i) {
            p[i] = std::min(p[id]+id-i, p[2*id-i]);
        } else {
            p[i] = 1;
        }

        while(str[i-p[i]] == str[i+p[i]])
            p[i]++;

        if (p[i]+i >= p[id]+id) {
            id = i;
        }

        max_LPS = std::max(max_LPS, p[id]);
    }

    delete(p);
    return max_LPS-1;
}

#endif

int main() {
    int N = 0;
    cin >> N;
    vector<int> cnts;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        int c = find_sub_str(str);
        cnts.push_back(c);
    }
    for (int j = 0; j < cnts.size(); ++j) {
        cout<<cnts[j]<<endl;
    }
    return 0;
}