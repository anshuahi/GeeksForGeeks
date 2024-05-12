/*
GeeksForGeeks-POTD: Minimum steps to destination

POTD Link: https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1

GitHub Solution Link- https://github.com/anshuahi/GeeksForGeeks/blob/master/ProblemOfTheDay/12_05_2024.cpp

Approach
    1. sum of first n natural numbers >= d

*/

class Solution
{
public:
    int minSteps(int d)
    {
        if (d <= 1)
            return d;
        int ans = 0;
        int steps = 0;
        while (ans < d)
        {
            steps++;
            ans += steps;
        }
        int rem = ans - d;
        if (rem == 0)
            return steps;
        if (rem % 2 == 0)
            return steps;
        if (steps % 2 == 0)
            return steps + 1;
        return steps + 2;
    }
};
