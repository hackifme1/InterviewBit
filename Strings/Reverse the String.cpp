// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.



Input Format

The only argument given is string A.

Output Format

Return the string A after reversing the string word by word.

For Example

Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"

*/


Cpp code :

string Solution::solve(string A) {
    vector<string> v;
    int n = A.size();
    
    string str = "";
    string res = "";
    for(int i=0;i<n;i++)
    {
        if(A[i]==' ')
        {
            v.push_back(str);
            str ="";
            continue;
        }
        else
        str+=A[i];
    }
    if(A[n-1]!=' ')
    v.push_back(str);
    
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]=="")
        continue;
        else
        res+=v[i];
        if(i!=0)
        res+=' ';
    }
    if(v[0]=="")
    res.pop_back();
    return res;
}
