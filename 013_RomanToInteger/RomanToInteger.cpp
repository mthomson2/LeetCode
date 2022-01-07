#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

int romanToInt(std::string s);

enum Roman { M=1000, D=500, C=100, L=50, X=10, V=5, I=1 };

int main(void) 
{
    std::cout << "013 - Roman to Integer\n\n";

    std::cout << "Test Case 1: III\nExpected: 3\n";
    int result = romanToInt("III");
    std::cout << "Result: " << result;

    std::cout << "\n\n\nTest Case 1.2: IX\nExpected: 9\n";
    result = romanToInt("IX");
    std::cout << "Result: " << result << "\n";

    std::cout << "\n\n\nTest Case 1.1: IV\nExpected: 4\n";
    result = romanToInt("IV");
    std::cout << "Result: " << result << "\n";

    std::cout << "\n\n\nTest Case 2: LVIII\nExpected: 58\n";
    result = romanToInt("LVIII");
    std::cout << "Result: " << result << "\n";

    std::cout << "\n\n\nTest Case 3: MCMXCIV\nExpected: 1994\n";
    result = romanToInt("MCMXCIV");
    std::cout << "Result: " << result << "\n";
    
    return 0;
}

int romanToInt(std::string s) 
{
    char arr[s.length()];
    int localsum = 0;
    int globalsum = 0;
    char previous_char;
    bool reset = 0;

    int n = s.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());
 
    for (int i = 0; i < n; i++)
    {
        // Handle I 
        if (char_array[i] == 'I')
        {
            if (previous_char != 'I')
            {
                globalsum += localsum;
                localsum = 0;
            }

            localsum += 1;
            previous_char = 'I';
        }

        // Handle V
        if (char_array[i] == 'V')
        {
            if (previous_char == 'I')
            {
                localsum = -localsum; 
                reset = 1;
            }
            else
            {
                globalsum += localsum; 
                localsum = 0;
            }

            localsum += 5;
        }

        // Handle X 
        if (char_array[i] == 'X')
        {
            if (previous_char == 'I')
            {
                localsum = -localsum; 
                reset = 1;
            }
            else
            {
                globalsum += localsum; 
                localsum = 0;
            }

            previous_char = 'X';
            localsum += 10;
        }

        // Handle L
        if (char_array[i] == 'L')
        {
            if (previous_char == 'X')
            {
                localsum = -localsum; 
                reset = 1;
            }
            else
            {
                globalsum += localsum; 
                localsum = 0;
            }

            localsum += 50;
        }

        // Handle C 
        if (char_array[i] == 'C')
        {
            if (previous_char == 'X')
            {
                localsum = -localsum; 
                reset = 1;
            }
            else
            {
                globalsum += localsum; 
                localsum = 0;
            }

            previous_char = 'C';
            localsum += 100;
        }

        // Handle D 
        if (char_array[i] == 'D')
        {
            if (previous_char == 'C')
            {
                localsum = -localsum; 
                reset = 1;
            }
            else
            {
                globalsum += localsum; 
                localsum = 0;
            }

            localsum += 500;
        }

        // Handle M 
        if (char_array[i] == 'M')
        {
            if (previous_char == 'C')
            {
                localsum = -localsum; 
                reset = 1;
            }
            else
            {
                globalsum += localsum; 
                localsum = 0;
            }

            localsum += 1000;
        }

        // Reset after a section is complete 
        if (reset)
        {
            globalsum += localsum;
            localsum = 0;
            reset = 0;
        }

    }

    globalsum += localsum;

    return globalsum;
}