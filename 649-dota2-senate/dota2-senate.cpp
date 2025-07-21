class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int d = 0, r = 0;
        for (char c : senate) {
            q.push(c);
        }
        while (q.size() >1) {
            if(r>= q.size() || d>= q.size()){
                if(r>d) return "Radiant";
                else return "Dire";
            }
            char temp = q.front();
            q.pop();
            if (temp == 'D') {
                if (r > 0) {
                    r--;
                } else {
                    d++;
                    q.push(temp);
                }
            } else {
                if (d > 0) {
                    d--;
                } else {
                    r++;
                    q.push(temp);
                }
            }
        }
        if (q.front() == 'R')
            return "Radiant";
        return "Dire";
    }
};