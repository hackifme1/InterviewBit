// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.

11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,

the sequence is 11.

*/


Cpp code :

string Solution::countAndSay(int A) {
        if (A == 0) 
        return ""; 
        
    	if (A == 1) 
        return "1";
    	
        string res = "1";
    	string str;
    
    	for (int i = 1; i < A; i++)
        {        
    		int len = res.size();
        	
            for (int j = 0; j < len; j++)
            {  
    		    
    		   int cnt = 1;     

				while ((j + 1 < len) && (res[j] == res[j + 1]))
                {
					cnt++;    
					j++;        
				}
                
    			str += to_string(cnt) + res[j];
    		}
    
    		res = str;
    		str = "";
    
    	}
    
    	return res;
}
