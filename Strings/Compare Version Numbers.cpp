// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

*/

Cpp code :

int Solution::compareVersion(string A, string B) {
    unsigned long long int  n1 = A.size(); 
    unsigned long long int n2 = B.size();
    int i = 0, j=0;
        
    unsigned long long int temp1 = 0;
    unsigned long long int temp2 = 0;
        
    while(i<n1 || j<n2)
    {
        while(i<n1 && A[i]!='.')
        {
            temp1 = temp1*10+(A[i]-'0');
            i++;
        }
        
        while(j<n2 && B[j]!='.')
        {
            temp2 = temp2*10+(B[j]-'0');;
            j++;
        }
        
        if(temp1>temp2) 
        return 1;
        else if(temp1 < temp2) 
        return -1;
        
        temp1 = 0;
        temp2 = 0;
        i++;
        j++;
    }
    
    return 0;
}
