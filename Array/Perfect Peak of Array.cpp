// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer array A of size N.

You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.

If it exists return 1 else return 0.

NOTE:

Do not consider the corner elements i.e A[0] and A[N-1] as the answer.


Problem Constraints
3 <= N <= 105

1 <= A[i] <= 109


Input Format
First and only argument is an integer array A containing N integers.

Output Format
Return 1 if there exist a element that is strictly greater than all the elements on left of it and strictly  smaller than all the elements on right of it else return 0.



Example Input
Input 1:

 A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
 
Input 2:

 A = [5, 1, 4, 4]


Example Output
Output 1:

 1
 
Output 2:

 0


Example Explanation
Explanation 1:

 A[4] = 6 is the element we are looking for.
 All elements on left of A[4] are smaller than it and all elements on right are greater.
 
Explanation 2:

 No such element exits.

*/


Cpp code :

int Solution::perfectPeak(vector<int> &A) {
      int n = A.size();
      bool flag;

      for(int i=1; i<n-1; i++) {
         
         flag = true ;
         int rit = i;
         int lft = i;
         
         while(true) {
            
            if(lft > 0)
               lft--;
            
            if(rit < n-1)
               rit++;
            
            if(A[i] <= A[lft] || A[i] >= A[rit]) 
            {                  
               flag = false;
               break;
            }
            
            if(rit == n-1 && lft == 0)
               break;
         }
         
         if(flag == true)
            return 1;
      }

      return 0;
}
