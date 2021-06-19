// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given two binary strings, return their sum (also a binary string).

Example:

a = "100"
b = "11"

Return a + b = “111”.

*/


Cpp code :

string Solution::addBinary(string A, string B) {
    int n = A.size();
    int m = B.size();
    
    if(m>n)
    {
        swap(A,B);
        swap(m,n);
    }
    
    string res = "";
    
    int carr = 0;
    int diff = n - m;
    
    string temp = "";
    
    while(diff--) 
    temp+='0';
    
    B = temp + B;
    
    for(int i=n-1;i>=0;i--)
    {
        int sum = (A[i]-'0') + (B[i]-'0') + carr;
        
        if(sum == 2)
        {
            carr = 1;
            res+='0';
        }
        else if(sum == 3)
        {
            res+='1';
            carr = 1;
        }
        else if(sum == 1)
        {
            res+='1';
            carr = 0;
        }
        else 
        res+='0';
    }
    
    if(carr) 
    res+='1';
    
    reverse(res.begin(),res.end());
    
    return res;
}
