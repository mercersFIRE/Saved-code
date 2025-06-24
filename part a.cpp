#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int N = 10;
int X = 2;

void generate(string &filename) {
    ofstream out(filename,ios::binary);
    mt19937_64 rng(random_device{}());
    uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    for (int i = 0; i < N; ++i) {
        int num = dist(rng);
        cout<<num<<" ";
        out.write(reinterpret_cast<char*>(&num), sizeof(int));
    }

    out.close();
    cout << "\nGenerated " << N << " numbers in " << filename << "\n";
}

vector<int> select(string &filename) {
    ifstream in(filename, ios::binary);
    vector<int> selected;

    for (int i = 0; i < X; ++i) {
        int ind = rand()%(N);
        in.seekg(ind * sizeof(int), ios::beg);

        int num;
        in.read(reinterpret_cast<char*>(&num), sizeof(int));
        selected.push_back(num);
    }

    in.close();
    return selected;
}

void sortandwrite(vector<int> &numbers, string &filename) {
    vector<int> sorted = numbers;
    sort(sorted.begin(), sorted.end());

    int pos = 0, neg = 0;
    for (int n : sorted) {
        cout<<n<<" ";
        (n >= 0? pos:neg)++;
    }

    ofstream out(filename, ios::binary);

    for (int &n : sorted) {
        out.write(reinterpret_cast<char*>(&n), sizeof(int));
    }
    long long delimiter = 0xFFFFFFFF;
    out.write(reinterpret_cast<char*>(&delimiter), sizeof(int));
    out.write(reinterpret_cast<char*>(&pos), sizeof(int));
    out.write(reinterpret_cast<char*>(&neg), sizeof(int));

    out.close();
    cout << "\nWrote "<<numbers.size()<<" sorted numbers and counts to " << filename << "\n";
}

int main() {
    string file1 = "random1";
    string file2 = "random2";

    generate(file1);
    vector<int> selected = select(file1);
    sortandwrite(selected, file2);

    return 0;
}
