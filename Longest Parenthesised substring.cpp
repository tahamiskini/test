#include <bits/stdc++.h>
using namespace std;

int longestParenthesisedSubstring(const string& S) {
  int n = S.length();
    vector<int> dp(n + 1, 0);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(S[i] == ')') {
            if(!st.empty()) {
                int top = st.top();
                st.pop();
                dp[i + 1] = dp[top - 1] + i - top + 2;
            }
        } else if(S[i] == '(') {
            st.push(i + 1);
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    return (ans == 0) ? -1: ans; 
}
   
int main() {
    string S;
    cin >> S;
    cout << longestParenthesisedSubstring(S) << "\n";
    return 0;
}
