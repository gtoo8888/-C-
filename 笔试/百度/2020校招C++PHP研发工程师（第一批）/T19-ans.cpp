#include <bits/stdc++.h>

typedef std::pair<int, int> PAII;
using namespace std;

struct Money {
    long long x;
    int y;

    bool operator<(Money m2) const {
        return x < m2.x;
    }
};

istream &operator>>(istream &is, Money &money) {
    is >> money.x >> money.y;
    return is;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;
    long long totalSum = 0L;
    vector<Money> moneyGroup(n);
    unordered_map<int,int> modMoney;

    for (int i = 0; i < n; ++i) {
        cin >> moneyGroup[i];
        totalSum += moneyGroup[i].x * moneyGroup[i].y;
    }
    if (totalSum < m) {
        cout << 0 << endl;
    } else {

        sort(moneyGroup.begin(), moneyGroup.end());

        long long ans = 0;
        while (1) {
            long long rest = m;
            for (int i = n - 1; i >= 0 && rest > 0; --i) {
                if (moneyGroup[i].y == 0)
                    continue;
                // 有个整除关系感觉没用到。
                // 先用大钱的思路没错，但是用小钱补的时候，小钱能提供更多的容错率

                auto need = rest / moneyGroup[i].x;
                if (need > moneyGroup[i].y) {
                    need = moneyGroup[i].y - 1;
                }
                rest -= need * moneyGroup[i].x;
                moneyGroup[i].y -= need;
            }

            for (int i = 0; i < n && rest > 0; ++i) {
                if (moneyGroup[i].y == 0)
                    continue;
                auto need = max((int)(rest / moneyGroup[i].x),1);
                if (need > moneyGroup[i].y) {
                    need = moneyGroup[i].y;
                }

                rest -= need * moneyGroup[i].x;
                moneyGroup[i].y -= need;
            }
            if (rest > 0)
                break;
            ++ans;
        }
        cout << ans;
    }
}