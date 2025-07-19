class Solution {
public:
    int findTheWinner(int n, int k) {
        // ARRAY SOLUTION
        //  if (n == 1)
        //      return 1;
        //  int count = 0, i = -1;
        //  vector<int> v(n, 0);
        //  while (count != n - 1) {
        //      int curr = 0;
        //      while (curr != k) {
        //          i = (i + 1) % n;
        //          if (v[i] == 0) {
        //              curr++;
        //          }
        //      }
        //      v[i] = -1;
        //      count++;
        //  }
        //  while (v[i] != 0) {
        //      i = (i + 1) % n;
        //  }
        //  return i + 1;

        // QUEUE SOLUTION
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
        while (q.size() != 1) {
            for (int i = 1; i < k; ++i) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};