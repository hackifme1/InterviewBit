// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .



Input Format
First argument is an integer array A containing arrival time of booking.

Second argument is an integer array B containing departure time of booking.

Third argument is an integer C denoting the count of rooms.

Output Format
Return True if there are enough rooms for N bookings else return False.

Return 0/1 for C programs.


Example Input
Input 1:

 A = [1, 3, 5]
 B = [2, 6, 8]
 C = 1


Example Output
Output 1:

 0


Example Explanation
Explanation 1:
At day = 5, there are 2 guests in the hotel. But I have only one room.

*/


Cpp code :

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());

    int guest = 1;

    for(int i = 1, j = 0; i<n && j<n; )
    {
        if(arrive[i] >= depart[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
            guest++;
        }
    }

    if(guest > K)
    return false;

    return true;
}
