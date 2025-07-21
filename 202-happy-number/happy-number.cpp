class Solution {
public:
    int getDigitSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) 
    {
        if(n==1 || n==7) return true;
        unordered_set<int> st;
        st.insert(n);
        int N = getDigitSquareSum(n);
        while(!st.count(N)){
            if(N==1) return true;
            st.insert(N);
            N = getDigitSquareSum(N);
        }
        return false;
    }
};