/*input
5 3
6 3 4 0 2
*/

//
//  main.cpp
//  To Add or Not to Add
//
//  Created by Nirmaljot Singh Bhasin on 13/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <algorithm>
#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli arr[MAXN], sum[MAXN];

lli f(lli l, lli r, lli k) {
    return (r - l + 1) * arr[r] - (sum[r] - sum[l - 1]) <= k;
}

int main(int argc, const char *argv[]) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + arr[i];
    }

    lli cnt = 1, val = arr[1];
    for (int i = 2; i <= n; ++i) {
        lli lo = 1, hi = i;
        while (lo < hi) {
            lli mid = lo + ((hi - lo) >> 1);
            if (f(mid, i, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        if (i - lo + 1 > cnt) {
            cnt = i - lo + 1;
            val = arr[i];
        }
    }

    cout << cnt << " " << val << endl;
    return 0;
}
