#include <stdio.h>
#include <string.h>

int a, b, c;

char *solve(int _a, int _b, int _c)
{
    if (_a >= _b + _c || _b >= _a + _c || _c >= _a + _b) 
        return ("Invalid");
    else if (_a == _b && _b == _c)
        return ("Equilateral");
    else if (_a == _b || _b == _c || _c == _a) 
        return ("Isosceles");
    else 
        return ("Scalene");
}

int main() 
{
    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        
        printf(solve(a, b, c));
    }
    return 0;
}