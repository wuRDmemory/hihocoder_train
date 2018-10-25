#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

/*
6 2 2 20
F 2 3
M 7 6
M 3 2
F 9 9
M 2 2
F 8 7
*/

using namespace std;

struct Manager_Cell {
    int V, S;
    set<int> pointer;

    bool operator<(const Manager_Cell& other) const {
        set<int> _pointer(pointer);
        for (auto& it : other.pointer) {
            _pointer.insert(it);
        }
        return _pointer.size()>pointer.size();
    }
};

set<Manager_Cell> male_manager, female_manager;

int build_bag(vector<pair<int, pair<int, int> > >& candidates, int B, int req, set<Manager_Cell>& manager) {
    // bag用于记录价值，bag1用于记录他们的工资
    int bag[B+1] = {0}, bag1[B+1] = {0};
    // 记录每个cell的人员是谁
    set<int> status[B+1];
    for (int j = 0; j < B; ++j) {
        status[j].clear();
    }

    for (int idx = 0; idx < candidates.size(); idx++) {
        int id = candidates[idx].first;
        auto& people = candidates[idx].second;
        for (int i = B; i >= 0 ; --i) {
            if (i >= people.second) {
                // 如果原先的状态没有现在的好
                // 则更新set和V S
                if (bag[i] <= bag[i-people.second]+people.first) {
                    bag[i] = bag[i-people.second]+people.first;
                    bag1[i] = bag1[i-people.second]+people.second;
                    status[i] = status[i-people.second];
                    status[i].insert(id);
                }
            }

            if (status[i].size() == req) {
                Manager_Cell cell{bag[i], bag1[i], status[i]};
                manager.insert(cell);
            }
        }
    }

    return 1;
}


int main() {
    int N = 0, X = 0, Y = 0, B = 0;
    cin >> N >> X >> Y >> B;
    vector<pair<int, pair<int, int> > > candidate_male, candidate_female;
    candidate_male.reserve(X);
    candidate_female.reserve(Y);
    int m_n = 1;
    for (int i = 0; i < N; ++i) {
        char G = 'M';
        int V = 0, S = 0;
        cin >> G >> V >> S;
        if (G == 'M')
            candidate_male.emplace_back(make_pair(m_n++, make_pair(V, S)));
        else
            candidate_female.emplace_back(make_pair(m_n++, make_pair(V, S)));
    }

    sort(candidate_male.begin(), candidate_male.end(), [](const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b){
        return a.second.second < b.second.second;
    });
    sort(candidate_female.begin(), candidate_female.end(), [](const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b){
        return a.second.second < b.second.second;
    });

    build_bag(  candidate_male, B, X,   male_manager);
    build_bag(candidate_female, B, Y, female_manager);

    int best_score = 0;
    int less_pay = 999;
    vector<set<int> > record;
    for (auto& iter1 : male_manager) {
        for (auto& iter2 : female_manager) {
            if (iter1.S + iter2.S > B)
                continue;

            if (iter1.V + iter2.V >= best_score) {
                set<int> ids;
                for (auto& it : iter1.pointer)
                    ids.insert(it);
                for (auto& it : iter2.pointer)
                    ids.insert(it);
                if (less_pay > iter1.S + iter2.S || best_score < iter1.V + iter2.V) {
                    record.clear();
                }
                record.emplace_back(ids);
                best_score = iter1.V + iter2.V;
                less_pay = iter1.S + iter2.S;
            }
        }
    }

    cout << best_score << " " << less_pay << endl;
    for (auto& iter : record) {
        for (auto& it : iter) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}