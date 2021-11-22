/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <ctime>

using namespace std;

class Matrix {

private:
    int N;
    int **a;

public:
    Matrix(int N, bool _Forward);
    void output();
};

Matrix::Matrix(int N, bool _Forward) {
    this->N = N;
    int m = 1;
    a = new int* [N];

    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    if(N % 2 != 0){
            a[(N / 2)][(N / 2)] = (N * N);
        }

    if (_Forward){

        for(int i = 0; i < (N / 2); i++){
            for(int j = i; j < (N - i); j++){
                a[i][j] = m;
                m++;
            }
            for(int j = 1; j < (N - i - i); j++){
                a[(j + i)][(N - i) - 1] = m;
                m++;
            }
            for(int j = (N - 2) - i; j >= i; j--){
                a[(N - i) - 1][(j)] = m;
                m++;
            }
            for(int j = ((N - i) - 2); j > i; j--){
                a[j][i] = m;
                m++;
            }
        }
    }

    else{
        for(int j = 0; j < (N / 2); j++){
            for(int i = j; i < (N - j); i++){
                a[i][j] = m;
                m++;
            }

            for(int i = 1; i < (N - j - j); i++){
                a[(N - j) - 1][(i + j)] = m;
                m++;
            }

            for(int i = (N - 2) - j; i >= j; i--){
                a[(i)][(N - j) - 1] = m;
                m++;
            }

            for(int i = ((N - j) - 2); i > j; i--){
                a[j][i] = m;
                m++;
            }
        }

    }

}

void Matrix::output() {
   cout << endl;
     for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++){
            cout << a[i][j] << " " ;
        }
        cout << a[i][N - 1] << endl;
    }
}


int main()
{
    srand(time(0));
    int N;
    bool F;
    N  = 3 + rand() % 8;
    cout << "N=" << N << endl;

    F = rand() % 2;

    Matrix A(N, F);

    A.output();

    return 0;

}
