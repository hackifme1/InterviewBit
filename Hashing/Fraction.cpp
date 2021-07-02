// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"

*/


Cpp code :

string Solution::fractionToDecimal(int A, int B) {
        if(B == 0)
            return "";
        
        if(A == 0) 
            return "0"; 
        
        unordered_map<long, int> ump;
        string res;
        
        long quo = abs((long)A / (long)B);
        int sgn = 1;

        if(A < 0 )
        sgn = -1*sgn;

        if(B < 0 )
        sgn = -1*sgn;

        if(sgn == -1)
        res+='-';

        res += to_string(quo);

        long rem = abs((long)A % (long)B);

        if(rem == 0) 
        return res;
        
        res += ".";
        
        while(rem)
        {
            ump[rem] = res.size();
            rem *= 10;
            res += to_string(rem / abs((long)B));
            rem %= abs((long)B);
            if(ump.find(rem) != ump.end())
            {
                res.insert(ump[rem], "(");
                res += ")";
                break;
            }
        }
        
        return res;
}
