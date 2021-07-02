// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample
case for clarification.

Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp'

Note:  All inputs will be in lower-case.

Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 

dog and god are another set of anagrams which correspond to index 2 and 3.

The indices are 1 based ( the first element has index 1 instead of index 0).

Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] 
if i < j.

*/


Cpp code :

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
        int n = A.size();
        
        unordered_map<string,vector<int>> ump;
        
        for(int i=0;i<n;i++)
        {
            string temp = A[i];
            sort(temp.begin(),temp.end());
            ump[temp].push_back(i + 1);
        }
        
        vector<vector<int>> res;
        
        for(auto itm : ump)
        {
            res.push_back(itm.second);
        }
        
        return res;
}
