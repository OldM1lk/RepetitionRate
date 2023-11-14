
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
  ifstream file("input.txt");
  
  string text;
  map<char, int> LetterFrequency;
  map<string, int> TwoLetterFrequency;

  if (file.is_open()) {
    while (getline(file, text)) {
      for (char c : text) {
        if (isalpha(c)) {
          c = tolower(c);
          ++LetterFrequency[c];
        }
      }

      for (size_t TwoLettersIndex = 0; TwoLettersIndex < text.size() - 1; ++TwoLettersIndex) {
        string TwoLetters = text.substr(TwoLettersIndex, 2);
        if (isalpha(TwoLetters[0]) && isalpha(TwoLetters[1])) {
          TwoLetters[0] = tolower(TwoLetters[0]);
          TwoLetters[1] = tolower(TwoLetters[1]);
          ++TwoLetterFrequency[TwoLetters];
        }
      }
    }
    
  file.close();

  cout << "Letter Frequency:" << endl;
  for (const auto& pair : LetterFrequency) {
    cout << pair.first << ": " << pair.second << endl;
  }

  cout << "\nTwo-Letter Combination Frequency:" << endl;
  for (const auto& pair : TwoLetterFrequency) {
    cout << pair.first << ": " << pair.second << endl;
  }
  
  } else {
    cout << "Unable to open file" << endl;
  }
  
  return 0;
}
