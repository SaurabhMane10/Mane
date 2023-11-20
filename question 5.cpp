#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort(int envelopes[][2], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (envelopes[j][0] > envelopes[j + 1][0] ||
                (envelopes[j][0] == envelopes[j + 1][0] && envelopes[j][1] < envelopes[j + 1][1])) {
                swap(envelopes[j][0], envelopes[j + 1][0]);
                swap(envelopes[j][1], envelopes[j + 1][1]);
            }
        }
    }
}

int max(int envelopes[][2], int n) {
    if (n == 0) {
        return 0;
    }

    sort(envelopes, n);

    int dp[1000];
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[i][1] > envelopes[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxlen = dp[0];
    for (int i = 1; i < n; ++i) {
        maxlen = max(maxlen, dp[i]);
    }

    return maxlen;
}

int main() {
    int N;
    cout << "Enter the number of envelopes: ";
    cin >> N;

    int envelopes[1000][2];


    for (int i = 0; i < N; ++i) {
        cout << "Enter the width and height of envelope " << i + 1 << ": ";
        cin >> envelopes[i][0] >> envelopes[i][1];
    }


    cout << "Maximum number of envelops you can Russian doll is " << max(envelopes, N) << endl;

    return 0;
}
