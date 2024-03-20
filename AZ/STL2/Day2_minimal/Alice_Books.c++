/*Alice and Books

Time-Limit: 10 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Alice read N books. The i-th book has Ai pages. After every book Alice reads, you have to tell the largest integer B such that Alice has read B books that have at least B pages.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array. 
The second line of each test case contains N space-separated integers.


Output Format

For each test case, print N integers, A1, A2, ... AN, where Ai is the largest integer B such that Alice has read B books that have at least B pages after reading the i-th book.


Constraints

1≤ T ≤ 100
1≤ N ≤ 105
1≤ Ai ≤ 105


Sample Input 1

4

4

2 1 4 4

2

5 1

5

1 3 2 3 5

4

3 3 3 3


Sample Output 1

1 1 2 2

1 1

1 1 2 2 3

1 2 3 3


Note

In the first test case of the example, Alice reads N=4 books.
After reading the 1st book, she has read 1 book with at least 1 page i.e. book with page 2.
After reading the 2nd book, the answer remains the same as she has read 1 book with at least 1 page.
After reading the 3rd book, she has read 2 books with at least 2 pages i.e. book with pages 2 and 4.
After reading the 4th book, the answer remains the same as she has read 2 books with at least 2 pages.

In the third test case of the example, Alice reads N=5 books.
After reading the 1st book, she has read 1 book with at least 1 page i.e. book with page 1.
After reading the 2nd book, the answer remains the same as she has read 1 book with at least 1 page.
After reading the 3rd book, she has read 2 books with at least 2 pages i.e. book with pages 2 and 3.
After reading the 4th book, the answer remains the same as she has read 2 books with at least 2 pages.
After reading the 3rd book, she has read 3 books with at least 3 pages i.e. book with pages 3,3 and 5.*/

#include <bits/stdc++.h>
using namespace std;
int work()
{
    map<int, int> m;
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        for (int j = 1; j <= val; j++)
        {
            m[j]++;
        }

        int ma = -1e9;
        if (!m.empty())
        {
            for (auto it = m.begin(); it != m.end(); it++)
            {
                int k = it->first;
                int v = it->second;
                if (v >= k)
                {
                    ma = max(ma, k);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
        }

        ans.push_back(ma);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}