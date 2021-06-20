// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)

*/


Cpp code :

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    
    if(A.length() > 12 || A.length() < 4)
    return ans;
    
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                for(int l=1;l<=3;l++)
                {
                    if(i+j+k+l > A.length() || i+j+k+l < A.length())
                    continue;
                    
                    string a = A.substr(0,i);
                    string b = A.substr(i,j);
                    string c = A.substr(i+j,k);
                    string d = A.substr(i+j+k,l);
                    
                    if( stoi(a)>255 || stoi(b)>255 || stoi(c)>255 || stoi(d)>255 ) 
                    continue;
                    
                    if( (a[0]=='0' && a.length() >1) || (b[0]=='0' && b.length() >1) || (c[0]=='0' && c.length() >1) || (d[0]=='0' && d.length() >1)) 
                    continue;
                    
                    ans.push_back(a + "." + b + "." + c + "." + d);
                }
            }
        }
    }
    
    return ans;
}
