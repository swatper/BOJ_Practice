#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int numOfp = 0;
    int numOfy = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'p' || s[i] == 'P')
            ++numOfp;
        else if(s[i] == 'y' || s[i] == 'Y')
            ++numOfy;
    }
    
    return numOfp == numOfy;
}