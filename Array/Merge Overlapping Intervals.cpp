// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

*/


Cpp code :

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool comp(Interval i1, Interval i2)
 {
     return i1.start<i2.start;
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(),A.end(),comp);
    
    int n = A.size();
    
    vector<Interval> res;
    res.push_back(A[0]);
    
    for(int i=1;i<n;i++)
    {
        if(res[res.size()-1].end>=A[i].start)
        {
            res[res.size()-1].end = max(res[res.size()-1].end,A[i].end);
        }
        else
        res.push_back(A[i]);
    }
    
    return res;
  
}
