#include <iostream>
#include <string>
int main ()
{
    using namespace std;
    string word;
    char temp;
    string word2;
    int num;

    cout << "Enter a word: ";
    cin >> word;
    word2 = word;

    int i, j;
    for (j = 0, i = word.size() - 1; j < i; --i, ++j)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }

    cout << "word = " << word << endl;
    cout << "Temp = " << temp << endl;
    cout << "word2 = " << word2 << endl;

    if (word2 == word)
        cout << "Your entered word is palindrome" << endl;
    else
        cout << "Your entered word is not palindrome" << endl;

    word = word * 2;
    num = word * 2;
    cout << "now word = " << word << endl;
    cout << "word = " << num << endl;

    return 0;

}
