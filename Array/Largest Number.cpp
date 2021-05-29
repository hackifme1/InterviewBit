// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/


Cpp code :

bool comp(string str1, string str2)
{
    string s = str1.append(str2);
    string s2 = str2.append(str1);
    
    return(s.compare(s2)>s2.compare(s));
}

string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> str;
    
    for(int i=0;i<n;i++)
    {
        str.push_back(to_string(A[i]));
    }
    
    sort(str.begin(),str.end(),comp);
    
    string res = "";
    
    for(int i=0;i<str.size();i++)
    {
        res+=str[i];
    }
    
    bool flag = true;
    int sz = res.size();
    for(int i=0;i<sz;i++)
    {
        if(res[i]!='0')
        {
            flag = false;
            break;
        }
    }
    if(flag == true)
    res = "0";
    
    return res;
    
}
