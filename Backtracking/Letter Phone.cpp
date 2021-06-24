// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

The digit 0 maps to 0 itself.

The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.

*/


Cpp code :

string mp[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
 
void solve(vector<string> &res, string A, int n, int indx, string str)
{
    if(indx == n)
    {
        res.push_back(str);
        return;
    }
    
    int d = A[indx]-'0';
    
    for(int j=0; j<mp[d].size(); j++)
    {
        str.push_back(mp[d][j]);
        
        solve(res,A,n,indx+1,str);
        
        str.pop_back();
    }
 
}
 
vector<string> Solution::letterCombinations(string A) {
    int n = A.size();
    vector<string> res={};
    string str;
    
    solve(res,A,n,0,str);
    
    return res;
}
