class RecentCounter {
public:
    int i = 0;
    vector<int> v;
    RecentCounter() {}

    int ping(int t) {
        v.push_back(t);
        if (v.size() == 1)
            return 1;
        while (v[i] < (t - 3000)) {
            i++;
        }
        return v.size() -i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */