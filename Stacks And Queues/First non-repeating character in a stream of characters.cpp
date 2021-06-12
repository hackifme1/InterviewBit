// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character 
is found then append '#' at the end of B.


Problem Constraints
1 <= length of the string <= 100000


Input Format
The only argument given is string A.

Output Format
Return a string B after processing the stream of lowercase alphabets A.

Example Input
Input 1:

 A = "abadbc"
 
Input 2:

 A = "abcabc"


Example Output
Output 1:

 "aabbdd"
 
Output 2:

 "aaabc#"


Example Explanation
Explanation 1:

    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "aba"    -   first non repeating character 'b'
    "abad"   -   first non repeating character 'b'
    "abadb"  -   first non repeating character 'd'
    "abadbc" -   first non repeating character 'd'
    
Explanation 2:

    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "abc"    -   first non repeating character 'a'
    "abca"   -   first non repeating character 'b'
    "abcab"  -   first non repeating character 'c'
    "abcabc" -   no non repeating character so '#'

*/


Cpp code :

string Solution::solve(string A) {
    int n = A.size();
    string B ="";
    queue<char> qu;
    int fq[26] = {0};
    
    for(int i=0;i<n;i++)
    {
        qu.push(A[i]);
        fq[A[i]-'a']++;
        
        while(!qu.empty())
        {
            if(fq[qu.front()-'a']>1)
            {
                qu.pop();
            }
            else
            {
                B.push_back(qu.front());
                break;
            }
        }
        if(qu.empty()){
            B.push_back('#');
        }
    }
    
    return B;
}
