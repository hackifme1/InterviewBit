// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 


Input Format

The only argument given is integer A.

Output Format

Return a string denoting roman numeral version of A.


Constraints
1 <= A <= 3999


For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"

*/

Cpp code :

string Solution::intToRoman(int A) {
    int t = A/1000;
    string str = "";
    
    for(int i=0;i<t;i++)
    str+='M';
    
    int r = A%1000;
    if(r>=900)
   {
       str+="CM";
       r-=900;
   }
   
   if(r>=500)
   {
       str+='D';
       r-=500;
   }
   
   if(r>=400)
   {
       str+="CD";
       r-=400;
   }
   
   if(r>=100)
   {
       int t1 = r/100;
       
       for(int i=0;i<t1;i++)
       str+='C';
       
       r=r%100;
   }
   
   if(r>=90)
   {
       str+="XC";
       r-=90;
   }
   if(r>=50)
   {
       str+="L";
       r-=50;
   }
   if(r>=40)
   {
       str+="XL";
       r-=40;
   }
    
   if(r>=10)
   {
       int t2 = r/10;
       
       for(int i=0;i<t2;i++)
       {
           str+='X';
       }
       r = r%10;
   }
   if(r==9)
   {
       str+="IX";
       r-=9;
   }
   if(r>=5)
   {
       str+='V';
       r-=5;
   }
   if(r==4)
   {
       str+="IV";
       r-=4;
   }
   
   if(r>=1)
   {
       for(int i=0;i<r;i++)
       str+='I';
   }
   return str;
    
}
