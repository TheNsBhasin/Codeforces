//
//  main.cpp
//  Xenia and Bit Operations
//
//  Created by Nirmaljot Singh Bhasin on 13/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 1 << 17;

lli arr[MAXN], tree[MAXN << 1], lvl[MAXN << 1];

void build(lli lo, lli hi, lli i) {
    if (lo > hi) {
        return;
    }
    if (lo == hi) {
        tree[i] = arr[lo];
        lvl[i] = 1;
        return;
    }

    lli mid = lo + ((hi - lo) >> 1);
    build(lo, mid, 2 * i + 1);
    build(mid + 1, hi, 2 * i + 2);

    lvl[i] = lvl[2 * i + 1] + 1;

    if (lvl[i] & 1) {
        tree[i] = tree[2 * i + 1] ^ tree[2 * i + 2];
    } else {
        tree[i] = tree[2 * i + 1] | tree[2 * i + 2];
    }
}

void update(lli lo, lli hi, lli i, lli idx, lli val) {
    if (lo > hi) {
        return;
    }

    if (lo == hi) {
        tree[i] = val;
        return;
    }

    lli mid = lo + ((hi - lo) >> 1);

    if (lo <= idx && idx <= mid) {
        update(lo, mid, 2 * i + 1, idx, val);
    } else {
        update(mid + 1, hi, 2 * i + 2, idx, val);
    }

    if (lvl[i] & 1) {
        tree[i] = tree[2 * i + 1] ^ tree[2 * i + 2];
    } else {
        tree[i] = tree[2 * i + 1] | tree[2 * i + 2];
    }
}

int main(int argc, const char *argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < (1 << n); ++i) {
        cin >> arr[i];
    }

    build(0, (1 << n) - 1, 0);

    for (int i = 0; i < m; ++i) {
        lli idx, val;
        cin >> idx >> val;
        --idx;
        update(0, (1 << n) - 1, 0, idx, val);
        cout << tree[0] << endl;
    }
    return 0;
}
