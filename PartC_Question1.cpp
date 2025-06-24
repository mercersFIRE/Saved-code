#include <bits/stdc++.h>
using namespace std;

int N = 1000;
using Matrix = vector<vector<int>>;

Matrix generate() {
    Matrix mat(N, vector<int>(N));
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(0, 100);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            mat[i][j] = dist(rng);
    return mat;
}

void save(Matrix &mat, const string &filename) {
    ofstream out(filename);
    for (auto &row : mat) {
        for (int val : row) out << val << ' ';
        out << '\n';
    }
}

void multiply(Matrix &C, Matrix &A, Matrix &B, int l, int r) {
    for (int i = l; i < r; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
}

int main() {
    Matrix A = generate();
    Matrix B = generate();
    Matrix C(N, vector<int>(N));

    save(A, "matrix_A.txt");
    save(B, "matrix_B.txt");

    auto st = chrono::high_resolution_clock::now();

    // Launching 4 threads to parallelize matrix multiplication
    // The problem is parallel and that is why each row can be computed independently.
    // 1000 rows devided equally among 4 threads (250 each) for simplicity.
    // This avoids complexity while still utilizing multicore CPUs.
    thread t1(multiply, ref(C), ref(A), ref(B), 0, 250);
    thread t2(multiply, ref(C), ref(A), ref(B), 250, 500);
    thread t3(multiply, ref(C), ref(A), ref(B), 500, 750);
    thread t4(multiply, ref(C), ref(A), ref(B), 750, 1000);

    t1.join(); t2.join(); t3.join(); t4.join();

    auto et = chrono::high_resolution_clock::now();
    cout<< "Time: " << chrono::duration<double>(et - st).count() << "s\n";

    save(C, "matrix_C.txt");
    return 0;
}
