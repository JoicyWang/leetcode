#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if ((n == 0) && (n == 1))
            return 0;
        vector<bool> num(n, true);
        int res = 0;
        for (int i = 2; i * i < n; i++) {
            if (!num[i]) continue;
            for (int j = i * i; j < n; j += i) {
                num[j] = false;
            }
        }
        for (int i = 2; i < n; i++) {
            if (num[i]) res++;
        }
        return res;
    }
};