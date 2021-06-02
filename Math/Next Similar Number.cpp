// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement 
Given a number A in a form of string.
You have to find the smallest number that has same set of digits as A and is greater than A.
If A is the greatest possible number with its set of digits, then return -1.
Problem Constraints
1 <= A <= 10100000
A doesn't contain leading zeroes.
Input Format
First and only argument is an numeric string denoting the number A.
Output Format
Return a string denoting the smallest number greater than A with same set of digits , if A is the largest possible then return -1.
Example Input
Input 1:
 A = "218765"
 
Input 2:
 A = "4321"
Example Output
Output 1:
 "251678"
 
Output 2:
 "-1"
Example Explanation
Explanation 1:
 The smallest number greater then 218765 with same set of digits is 251678.
 
Explanation 2:
 The given number is the largest possible number with given set of digits so we will return -1.
*/


Cpp code :

string Solution::solve(string A) {
    
    bool flag = next_permutation(A.begin(),A.end());
    if(flag == false)
    return "-1";
    else
    return A;
}

// or

string Solution::solve(string A) {
    
  int n = A.size();
  int f = 0;
  string res = "";
  int indx;
  
  for(int i=n-1;i>0;i--)
  {
      if((A[i-1]-'0')<(A[i]-'0'))
      {
          indx = i;
          f = 1;
          break;
      }
  }
  
  if(f == 0)
  return "-1";
  
  int minm = INT_MAX;
  int it;
  for(int i=indx;i<n;i++)
  {
      if(((A[i]-'0')>(A[indx-1])-'0')&&(A[i]-'0')<minm)
      {
          minm = A[i]-'0';
          it = i;
      }
  }
  swap(A[indx-1],A[it]);
  
  sort(A.begin()+indx,A.end());
  
  return A;
}
