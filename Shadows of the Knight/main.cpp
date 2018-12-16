//
//  main.cpp
//  Shadows of the Knight
//
//  Created by Nirmaljot Singh Bhasin on 01/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main(int argc, const char * argv[]) {
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H;
    int N; // maximum number of turns before game over.
    cin >> N;
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    int left = 0, right = W - 1;
    int top = 0, bottom = H - 1;
    cout << X0 << " " << Y0 << endl;
    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir;
        if (bombDir.length() > 1) {
            if (bombDir[1] == 'L') {
                right = X0  - 1;
            } else if (bombDir[1] == 'R') {
                left = X0 + 1;
            }
            if (bombDir[0] == 'U') {
                bottom = Y0 - 1;
            } else {
                top = Y0 + 1;
            }
        } else {
            if (bombDir[0] == 'L') {
                right = X0  - 1;
            } else if (bombDir[0] == 'R') {
                left = X0 + 1;
            } else if (bombDir[0] == 'U') {
                bottom = Y0 - 1;
            } else {
                top = Y0 + 1;
            }
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        X0 = left + ((right - left) >> 1);
        Y0 = top + ((bottom - top) >> 1);
        
        cerr << left << " " << right << " " << top << " " << bottom << " " << endl;
        // the location of the next window Batman should jump to.
        cout << X0 << " " << Y0 << endl;
    }
    return 0;
}
