#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;

bool isPalindrome(const string& input) {
    stack<char> s;
    queue<char> q;
    
    for (char c : input) {
        if (isalnum(c)) {
            char lowerC = tolower(c);
            s.push(lowerC);
            q.push(lowerC);
        }
    }
    
    // Comparaison des caractères
    while (!s.empty() && !q.empty()) {
        if (s.top() != q.front()) {
            return false;
        }
        s.pop();
        q.pop();
    }
    
    return true;
}

int main() {
    cout << boolalpha;
    cout << "Is 'racecar' a palindrome? " << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? " << isPalindrome("hello") << endl;
    return 0;
}