#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char sentence[n + 1];
    cin.getline(sentence, n + 1);
    cin.ignore();

    int current_word = 0, largest_word = 0, maxEnd = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\0')
        {
            if (largest_word < current_word)
            {
                largest_word = current_word;
                maxEnd = i - 1;
            }
            current_word = 0;
        }
        else
        {
            current_word++;
        }
    }

    cout << largest_word << endl;
    for (int i = maxEnd - largest_word + 1; i <= maxEnd; i++)
    {
        cout << sentence[i];
    }
}