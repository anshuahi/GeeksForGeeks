/*
GeeksForGeeks-POTD: Divisor Game

POTD Link: https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1

Approach
    1. n modulo 2 == 0

*/
class Solution
{
public:
    bool divisorGame(int n)
    {
        return n % 2 == 0;
    }
};
