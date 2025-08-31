#include <iostream>
using namespace std;

bool areAnagrams(const char* str1, const char* str2) {
    int count[256] = {0}; 

    for (int i = 0; str1[i] != '\0'; i++)
        count[(char)str1[i]]++;

    
    for (int i = 0; str2[i] != '\0'; i++)
        count[(char)str2[i]]--;

    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}

int main() {
    char str1[] = "cab";
    char str2[] = "abc";

    bool isAnagram = areAnagrams(str1, str2);

    cout << (isAnagram ? "True" : "False") << endl;

    return 0;
}