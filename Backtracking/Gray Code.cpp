// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

There might be multiple gray code sequences possible for a given n.

Return any such sequence.

*/


Cpp code :

int bin_dec(string n)
{
    int val = 0;
 
    int temp = 1;
 
    int sz = n.size();

    for (int i = sz - 1; i >= 0; i--) 
    {
        if (n[i] == '1')
            val += temp;
            
        temp = temp * 2;
    }
 
    return val;
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        vector<string> ans;
        vector<int> res;      
        if (A <= 0)
            return res;

        ans.push_back("0");
        ans.push_back("1");

        int i, j;

        for (i = 2; i < (1<<A); i = i<<1)
        {
            for (j = i-1 ; j >= 0 ; j--)
                ans.push_back(ans[j]);

            for (j = 0 ; j < i ; j++)
                ans[j] = "1" + ans[j];

            for (j = i ; j < 2*i ; j++)
                ans[j] = "0" + ans[j];
        }

        for(int i=0;i<ans.size();i++)
        res.push_back(bin_dec(ans[i]));
        
        return res;
}
