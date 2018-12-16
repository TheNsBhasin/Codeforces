/*input
30
*/

//
//  main.cpp
//  Tetrahedron
//
//  Created by Nirmaljot Singh Bhasin on 08/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MOD = 1e9 + 7;

class Matrix {
    int row, col;
public:
    lli** data;
    Matrix(const int row, const int col) {
        this->row = row;
        this->col = col;
        data = new lli*[row];
        for (int i = 0; i < row; ++i) {
            data[i] = new lli[col];
            for (int j = 0; j < col; ++j) {
                data[i][j] = 0;
            }
        }
    }

    int getRowCount() {
        return row;
    }

    int getColCount() {
        return col;
    }

    static Matrix multiply(Matrix A, Matrix B) {
        Matrix result(A.getRowCount(), B.getColCount());
        for (int i = 0; i < A.getRowCount(); i++) {
            for (int j = 0; j < B.getRowCount(); j++) {
                for (int k = 0; k < B.getColCount(); k++)
                    result.data[i][k] = (result.data[i][k] + A.data[i][j] * B.data[j][k]) % MOD;
            }
        }
        return result;
    }

    static Matrix identityMatrix(int size) {
        Matrix I(size, size);
        for (int i = 0; i < size; ++i) {
            I.data[i][i] = 1;
        }
        return I;
    }

    Matrix power(int exp) {
        if (exp == 0) {
            return identityMatrix(row);
        }
        if (exp == 1) {
            return *this;
        }
        Matrix result = power(exp >> 1);
        result = multiply(result, result);
        if (exp & 1) {
            result = multiply(result, *this);
        }
        return result;
    }

    void display() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    Matrix matrix(2, 2);
    matrix.data[0][0] = 2;
    matrix.data[0][1] = 1;
    matrix.data[1][0] = 3;
    matrix.data[1][1] = 0;
    matrix = matrix.power(n);
    cout << matrix.data[1][1] << endl;
    return 0;
}
