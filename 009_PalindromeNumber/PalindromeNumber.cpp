#include "iostream"
#include <cmath>

bool isPalindrome(int x);
int getNumLength(int n);

int main(void) 
{
    std::cout << "009 - Palindrome Number\n\n";

    std::cout << "Test Case 1: 121\nExpected: True\n";
    bool result = isPalindrome(121);
    std::cout << "Result: " << result;

    std::cout << "\n\n\nTest Case 2: 77888877\nExpected: True\n";
    result = isPalindrome(77888877);
    std::cout << "Result: " << result << "\n";

    std::cout << "\n\n\nTest Case 3: 123\nExpected: False\n";
    result = isPalindrome(123);
    std::cout << "Result: " << result << "\n";
    
    return 0;
}

int getNumLength(int n)
{
    int size = trunc(log10(n)) + 1;

    return size;
}

bool isPalindrome(int x)
{
    // Edge Case: If number is negative, false
    if (x < 0)
    {
        return false;
    }

    if (x < 10)
    {
        return true;
    }

    int length = getNumLength(x);

    bool odd = (length % 2 == 1) ? true : false;

    int limit = floor(length / 2);

    bool isGood = true;

    // Odd - Don't need to calculate middle
    if (odd)
    {
        int j = limit*2;
        for (int i = 0; i < limit; i++)
        {
            isGood = ((int)floor(x / pow(10,i)) % 10 == (int)floor(x / pow(10,j)) % 10) ? true : false;

            if (isGood)
            {
                j--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    // Even

    int j = limit*2-1;
    for (int i = 0; i < limit; i++)
    {
        isGood = ((int)floor(x / pow(10,i)) % 10 == (int)floor(x / pow(10,j)) % 10) ? true : false;

        if (isGood)
        {
            j--;
        }
        else
        {
            return false;
        }
    }

    return true;
}
