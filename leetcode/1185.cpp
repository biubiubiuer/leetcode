#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

inline bool isRun(int y) {
    if (y & 400 || (y >> 2) && !(y & 100)) return true;
    else return false;
}

int main(){
    
    int day, month, year;
    scanf("%d %d %d", &day, &month, &year);

    int disyear = year - 1970;

    vector<string> weekOfDay = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

    int res = 0;
    for (int i = 1; i <= disyear; i ++ ) {
        for (int j = 1; j <= month; j ++ ) {
            if (i == disyear) {
                if (isRun(i)) {
                    if (j == month) {
                        res += day;
                        break;
                    }
                    else {
                        if (j == 2) res += 29;
                        else if (j == 7 || j == 8) res += 31;
                        else if (j & 1) res += 31;
                        else res += 30;
                    }
                }
                else {
                    if (j == month) {
                        res += day;
                        break;
                    }
                    else {
                        if (j == 2) res += 28;
                        else if (j == 7 || j == 8) res += 31;
                        else if (j & 1) res += 31;
                        else res += 30;
                    }
                }
            }
            else {
                if (isRun(i)) res += 366;
                else res += 365;
            }
        }
    }

    int x = res % 7;
    cout << weekOfDay[x] << endl;

  
    return 0;
}