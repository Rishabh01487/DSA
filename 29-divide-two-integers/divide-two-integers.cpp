class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long res = 0;

        for (int i = 31; i >= 0; --i) {
            if ((b << i) <= a) {
                a -= (b << i);
                res |= (1LL << i);
            }
        }

        res = sign == 1 ? res : -res;

        return (int)res;
    }
};