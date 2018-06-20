#include <iostream>
#include <vector>
#include <string>

using namespace std;

string remove_string_first(const string& input) {
    string out;
    string dp_input(input);
    dp_input.push_back('D');
    for (int i = 0; i < input.size(); i=i) {
        if (dp_input[i] != dp_input[i+1]) {
            out.push_back(dp_input[i]);
            i++;
        } else {
            char ref = dp_input[i];
            while (ref == dp_input[++i]);
        }
    }
    return out;
}

int remove_string_second(const string& input) {
    if (input.size() <= 3) {
        return 2;
    }
    int out = 2;
    for (int i = 0; i < input.size()-2; ++i) {
        if (input[i] == input[i+2]) {
            out = 4;
            break;
        }
    }
    return out;
}

int get_score(const string& input) {
    if (input.size() <= 1) {
        return input.size() + 1;
    } else {
        string res_str(input);
        string last_res_str(res_str);
        while ((res_str = remove_string_first(res_str))!=last_res_str) {
            last_res_str = res_str;
        }
        if (res_str.empty()) {
            return input.size()+1;
        }
        if (res_str == input) {
            return 2;
        }
        int out = input.size() - res_str.size();
        return out + remove_string_second(res_str);
    }
}

int main() {
//    int N=0;
//    cin >> N;
//    vector<string> inputs;
//    for (int i = 0; i < N; ++i) {
//        string str;
//        cin >> str;
//        inputs.push_back(str);
//    }
//
//    for (int j = 0; j < N; ++j) {
//        cout << get_score(inputs[j]) <<endl;
//    }
    try {
        *(int*) 0 = 0;
    } catch (exception& e) {
        std::cout << "asdads" << e.what();
    }

    return 0;
}