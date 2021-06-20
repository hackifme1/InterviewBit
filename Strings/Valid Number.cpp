// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Note: It is intended for some problems to be ambiguous. You should gather all requirements up front before implementing one.

Please think of all the corner cases and clarifications yourself.

Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?

For this problem, no.

Is 0.1e10 valid?

Yes

-01.1e-10?

Yes

Hexadecimal numbers like 0xFF?

Not for the purpose of this problem

(. not followed by a digit)?

No

Can exponent have decimal numbers? 3e0.1?

Not for this problem.

Is 1f ( floating point number with f as prefix ) valid?

Not for this problem.

How about 1000LL or 1000L ( C++ representation for long and long long numbers )?

Not for this problem.

How about integers preceded by 00 or 0? like 008?

Yes for this problem

*/


Cpp code :

int cnt(string str,char ch){
    int n = str.size();
    int count = 0;

    for(int i=0; i<n; i++)
    {
        if(str[i] == ch)
        count++;
    }

    return count;
}

int Solution::isNumber(const string A) {
    int n = A.size();
    int r = n,x = 0;
    string s = A;

    for(int i=0;i<n;i++)
    {
        if(s[i] == ' ')
        {
            s.erase(i,1);
            i-=1;
            n-=1;
            x++;
        }
    }

    if(x == r)
    return 0;
    
    int cnte = cnt(s,'e');
    int cntdec = cnt(s,'.');
    int cntmin = cnt(s,'-');
    
    if(cnte > 1 || cntdec > 1 || cntmin > 2)
    return 0;

    if(cnte == 0 && cntmin > 1)
    return 0;
    
    int posn_e = s.find("e");
    int posn_d = s.find(".");
    int posn_minsgn = s.find("-");
    int posn_minexp = s.rfind("-");
   
   if(posn_d != string::npos)
   {
    if((s[posn_d+1]-'0') < 0 || (s[posn_d+1]-'0') > 9)
    return 0;
   }
   
    if(posn_e != string::npos)
    {
        if(posn_d > posn_e)
        return 0;
    }

    if(posn_minexp == posn_minsgn)
    {
       if(posn_minsgn != string::npos && posn_minsgn != 0)
       return 0; 
    }
    else
    {
        if(posn_minsgn != string::npos && posn_minsgn != 0)
        return 0;

        if(posn_minexp != string::npos && posn_minexp != posn_e + 1)
        return 0;
    }
    
    for(int i=0; i<n; i++)
    {
        if(s[i] != 'e' && s[i] != '.' && s[i] != '-' && (s[i] - '0' <0 || s[i] - '0' > 9))
        return 0;
    }

    return 1;
   }
