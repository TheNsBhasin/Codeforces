//
//  main.cpp
//  Arithmetic Progression
//
//  Created by Nirmaljot Singh Bhasin on 19/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int INF = 1e9 + 7;

lli arr[MAXN];
int n;

vector<lli> solve() {
    vector<lli> res;
    if (n == 1) {
        cout << -1 << endl;
        return res;
    }
    bool flag = true;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i - 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        res.push_back(arr[0]);
        return res;
    }
    sort(arr, arr + n);
    if (n == 2) {
        res.push_back(arr[0] - (arr[1] - arr[0]));
        lli mid = (arr[0] + arr[1]) >> 1;
        if ((mid << 1) == arr[0] + arr[1]) {
            res.push_back(mid);
        }
        res.push_back(arr[1] + (arr[1] - arr[0]));
        return res;
    }
    map<lli, lli> hm;
    for (int i = 1; i < n; ++i) {
        hm[arr[i] - arr[i - 1]]++;
    }
    if (hm.size() == 1) {
        res.push_back(arr[0] - (arr[1] - arr[0]));
        res.push_back(arr[n - 1] + (arr[1] - arr[0]));
        return res;
    } else if (hm.size() == 2) {
        map<lli, lli>::iterator it = hm.begin();
        lli slope = INF;
        for (auto &p : hm) {
            if (p.second == n - 2) {
                slope = p.first;
                break;
            }
        }
        if (slope != INF) {
            for (int i = 1; i < n; ++i) {
                if (arr[i] - arr[i - 1] != slope) {
                    if (arr[i - 1] + (slope << 1) == arr[i]) {
                        res.push_back(arr[i - 1] + slope);
                        return res;
                    }
                    break;
                }
            }
        }
    }
    cout << 0 << endl;
    return res;
}

int main(int argc, const char *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<lli> v = solve();
    if (v.size() != 0) {
        cout << v.size() << endl;
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) {
            cout << " ";
        }
    }
    return 0;
}
