// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string, 

find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/


Cpp code :

int Solution::lengthOfLongestSubstring(string A) {
        int  n = A.size();
        unordered_set<char> set;

		int l = 0, r = 0, res = 0;
    
		while( l<n && r<n)
		{
			if(set.find(A[r]) == set.end())
			{
				set.insert(A[r++]); 
				res = max(res, r-l); 
			}
			else
			{
				set.erase(A[l++]);
			}
		}
        
        return res;
}
