
#include <iostream>
#include <string>

bool IsKPeriodic(const std::string& str, int K)
{
    if (K < 1) return false;
    if (str.size() % K != 0) return false;

    std::string buff = str.substr(0, K);

    for (size_t i = 0; i < str.size(); i += K)
    {
        for (size_t j = 0; j < K; j++)
        {
            if (buff[j] != str[i + j]) return false;
        }
    }

    return true;

}

void testIsKPeriodic(const std::string& str, int K)
{
    if (IsKPeriodic(str, K))
        std::cout << "IsKPeriodic(\"" << str << "\", " << K << ") = true" << "\n";
    else
        std::cout << "IsKPeriodic(\"" << str << "\", " << K << ") = false" << "\n";
}

int main()
{
    testIsKPeriodic("abcabcabcabc", 1);
    testIsKPeriodic("abcabcabcabc", 2);
    testIsKPeriodic("abcabcabcabc", 3);
    testIsKPeriodic("abcabcabcabc", 4);
    testIsKPeriodic("abcabcabcabc", 5);
    testIsKPeriodic("abcabcabcabc", 6);
    testIsKPeriodic("abcabcabcabc", 7);
    testIsKPeriodic("abcabcabcabc", 8);
    testIsKPeriodic("abcabcabcabc", 12);
    testIsKPeriodic("abcabcabcabc", 88);
    std::cout << "\n";

    testIsKPeriodic("abcdabcdabcdabcd", 4);
    testIsKPeriodic("123412341234", 4);
    testIsKPeriodic("123456 123456 ", 7);
    testIsKPeriodic("qwerty, qwerty, qwerty, ", 24);
    testIsKPeriodic("qwerty, qwerty, qwerty, ", 8);
    testIsKPeriodic("qwerty,qwerty,qwerty,", 7);
    testIsKPeriodic("qqqqqqqq", 2);
    testIsKPeriodic("qazwdferfwe", 1);
    testIsKPeriodic("qazwdferfweqazwdferfwe", 2);

}
