#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>

/*
5
January 12, 2012
March 19, 2012
August 12, 2899
August 12, 2901
August 12, 2000
August 12, 2005
February 29, 2004
February 29, 2012
February 29, 2000
February 29, 2000000000
*/

using namespace std;

string month_str[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int search_0229(long beginY, int beginM, int beginD, long endY, int endM, int endD) {
    int conut = 0;
    long beginY_ = beginY;
    for (long i = beginY; i <= endY; ++i) {
        if ((i%100 != 0 && i%4==0) || (i%400 == 0)) {
            beginY_ = i+4;
            if (beginM < 2 || (beginM == 2 && beginD <= 29)) {
                conut++;
            }
            break;
        }
    }

    for (long i = beginY_; i <= endY; i+=4) {
        if ((i%100 != 0 && i%4 == 0) || (i%400 == 0)) {
            conut++;
            if (i == endY) {
                if ((endM < 2 || (endM == 2 && endD < 29))) {
                    conut--;
                }
            }
        }
    }

    return conut;
}

int search_0229_2(long beginY, int beginM, int beginD, long endY, int endM, int endD) {
    long _Y1 = (beginY+50)/100, _Y2 = endY/100;
    if (_Y1 == _Y2) {
        return search_0229(beginY, beginM, beginD, endY, endM, endD);
    } else {
        int count = 0;
        // each 100 years
        for (long i = _Y1; i < _Y2; ++i) {
            if (i%4 == 0) count+=25;
            else count+=24;
        }
        // begin->_Y1*100
        long gap = _Y1*100 - beginY;
        if (gap == 0) {
            if (_Y1%4 == 0 && !(beginM < 2 || (beginM == 2 && beginD <= 29))) {
                count--;
            }
        } else {
            count += (gap-1)/4;
            if ((beginY%100 != 0 && beginY%4 == 0) || (beginY%400 == 0)) {
                if ((beginM < 2 || (beginM == 2 && beginD <= 29))) {
                    count++;
                }
            }
        }
        // Y2*100->end
        gap = endY - _Y2*100;
        if (gap == 0) {
            if (_Y2%4==0 && (beginM > 2 || (beginM == 2 && beginD == 29))) {
                count++;
            }
        } else {
            count += (gap - 1) / 4;
            if ((endY % 100 != 0 && endY % 4 == 0) || (endY % 400 == 0)) {
                if (endM > 2) {
                    count++;
                }
            }
        }
        return count;
    }
}

int main() {
    int N = 0;
    cin >> N;
    vector<int> ress;
    for (int i = 0; i < N; ++i) {
        char month1[10], month2[10];
        int day1 = 0, day2 = 0, monthv1 = -1, monthv2 = -1;
        long year1 = 0, year2 = 0;
        scanf("%s %d, %ld", month1, &day1, &year1);
        scanf("%s %d, %ld", month2, &day2, &year2);
        for (int j = 0; j < 12; ++j) {
            if (!strcmp(month1, month_str[j].c_str())) {
                monthv1 = j+1;
            }
            if (!strcmp(month2, month_str[j].c_str())) {
                monthv2 = j+1;
            }
            if (monthv1 != -1 && monthv2 != -1) break;
        }

        int count = search_0229_2(year1, monthv1, day1, year2, monthv2, day2);
        ress.emplace_back(count);
    }

    for (int i = 0; i < ress.size(); i++) {
        printf("Case #%d: %d\n", i, ress[i]);
    }
    return 0;
}