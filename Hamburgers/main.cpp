/*input
BBBSSC
6 4 1
1 2 3
4
*/

//
//  main.cpp
//  Hamburgers
//
//  Created by Nirmaljot Singh Bhasin on 12/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

string s;
lli nb, ns, nc;
lli pb, ps, pc;
lli cb, cs, cc;
lli r;

bool f(lli x) {
    lli costB = max(0ll, cb * x - nb) * pb;
    lli costS = max(0ll, cs * x - ns) * ps;
    lli costC = max(0ll, cc * x - nc) * pc;

    return costB + costS + costC <= r;
}

int main(int argc, const char *argv[]) {
    cin >> s;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'B') {
            ++cb;
        } else if (s[i] == 'S') {
            ++cs;
        } else {
            ++cc;
        }
    }

    lli lo = 0, hi = 1e13;

    while (lo + 1 < hi) {
        lli mid = lo + ((hi - lo) >> 1);
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << endl;
    return 0;
}
