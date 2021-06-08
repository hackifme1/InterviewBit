// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R

And then read line by line: PAHNAPLSIIGYIR

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D

and hence the answer would be ACBD.

*/


Cpp code :

string Solution::convert(string A, int B) {
    if(B==1)
            return A;
        int n = A.size();
        if(n<=B)
            return A;
        string str[B]; 
        
        for(int i=0;i<B;i++)
            str[i]="";
        
        string res="";
        int i=0,f=0;
        while(i<n)
        {
            int j;
            if(f==1)
                j=1;
            else
                j=0;
            
            while(j<B)
            {
                str[j]+=A[i];
                i++;
                j++;
                f=1;
                if(i==n)
                    break;
                
            }
            
            j=j-2;
            if(i==n)
                break;
            while(j>=0)
            {
                str[j]+=A[i];
                i++;
                j--;
                f=1;
                if(i==n)
                break;
                
            }
            
        }
        
        for(int k=0;k<B;k++)
            res+=str[k];
        
        return res;
}
