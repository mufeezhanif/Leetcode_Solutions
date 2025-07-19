class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
            return 1;
        int count = 0, i = -1;
        vector<int> v(n, 0);
        while (count != n - 1) {
            int curr = 0;
            while (curr != k) {
                i = (i + 1) % n;
                if (v[i] == 0) {
                    curr++;
                }
            }
            v[i] = -1;
            count++;
        }
        while (v[i] != 0) {
            i = (i + 1) % n;
        }
        return i + 1;
    }
};