// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a set of reviews provided by the customers for different hotels and a string containing Good Words, you need to sort the reviews in descending order according to their 
Goodness Value (Higher goodness value first). We define the Goodness Value of a string as the number of Good Words in that string.

NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.

You are expected to use Trie in an Interview for such problems



Problem Constraints
1 <= No.of reviews <= 200
1 <= No. of words in a review <= 1000
1 <= Length of an individual review <= 10,000
1 <= Number of Good Words <= 10,000
1 <= Length of an individual Good Word <= 4
All the alphabets are lower case (a - z)


Input Format
First argument is a string A containing "Good Words" separated by "_" character
Second argument is a vector B of strings containing Hotel Reviews. Review strings are also separated by "_" character.

Output Format
Return a vector of integers which contain the original indexes of the reviews in the sorted order of reviews.


Example Input
Input 1:

 A = "cool_ice_wifi"
 B = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]


Example Output
Output 1:

 [2, 0, 1]


Example Explanation
Explanation 1:

 sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]

*/


Cpp code :

bool comp(const pair<int,int> &p1, const pair<int,int> &p2)
{
    if(p1.first!=p2.first)
        return (p1.first > p2.first);
    else
        return (p1.second < p2.second);
}

vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int> res;
    unordered_map<string,int> ump;

    stringstream ss(A);
    string s;

    while(getline(ss,s,'_'))
    ump[s]++;

    vector<pair<int,int>> v;

    for(int i=0;i<B.size();i++)
    {
        int cnt = 0;
        s.clear();
        stringstream ss1(B[i]);
        
        while(getline(ss1,s,'_'))
        {
            if(ump.find(s)!=ump.end())
            cnt++;
        }

        v.push_back(make_pair(cnt,i));
    }

    sort(v.begin(),v.end(),comp);

    for(int i=0;i<v.size();i++)
    res.push_back(v[i].second);

    return res;
}
