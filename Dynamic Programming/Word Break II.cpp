// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Note : Make sure the strings are sorted in your result.

Input Format:

The first argument is a string, A.
The second argument is an array of strings, B.


Output Format:

Return a vector of strings representing the answer as described in the problem statement.


Constraints:

1 <= len(A) <= 50
1 <= len(B) <= 25
1 <= len(B[i]) <= 20


Examples:

Input 1:
    A = "b"
    B = ["aabbb"]

Output 1:
    []

Input 2:
    A = "catsanddog",
    B = ["cat", "cats", "and", "sand", "dog"]

Output 2:
    ["cat sand dog", "cats and dog"]

*/


Cpp code :

vector<string> Solution::wordBreak(string s, vector<string> &B) {
        int n = s.size();
        
        unordered_set<string> wordSet(B.begin(), B.end());
        
        vector<vector<string>> dp(n + 1, vector<string>());
        
        dp[0].push_back("");
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                string str = s.substr(j, i - j);
                
                if(dp[j].size() > 0 && wordSet.find(str) != wordSet.end())
                {
                    for(string str1 : dp[j])
                    {
                        dp[i].push_back(str1 + (str1 == "" ? "" : " ") + str);
                    }
                }
            }
        }

        sort(dp[n].begin(),dp[n].end());

        return dp[n];
}
