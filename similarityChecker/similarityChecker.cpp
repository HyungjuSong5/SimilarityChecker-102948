#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class SimilarChecker {
 public:
  double countTheAlpha(const string &firstString, const string &secondString) {
    double result = 0;
    if (isCheckSameSring(firstString, secondString)) return 40;

    int totalAlphCnt = 0;
    int sameAlphaCnt = 0;

    unordered_set<char> firstStringChar;
    unordered_set<char> secondStringChar;
    unordered_set<char> totalStringChar;

    for (char ch : firstString) {
      firstStringChar.insert(ch);
      totalStringChar.insert(ch);
    }
    for (char ch : secondString) {
      secondStringChar.insert(ch);
      totalStringChar.insert(ch);
    }

    totalAlphCnt = totalStringChar.size();

    for (char charInStr1 : firstStringChar) {
      for (char charInStr2 : secondStringChar) {
        if (charInStr1 == charInStr2) sameAlphaCnt++;
      }
    }

    result = ((double)sameAlphaCnt / (double)totalAlphCnt) * 40;
    return result;
  }

  bool isCheckSameSring(const string &string1, const string &string2) {
    if (string1 == string2) return true;
    return false;
  }

  double stringLengthChecker(const string &string1, const string &string2) {
    int longLen;
    int shortLen;
    int gap;
    double result;

    if (isCheckSameSring(string1, string2)) return 60;

    if (string1.size() > string2.size()) {
      if (string1.size() >= string2.size() * 2) return 0;
      longLen = string1.size();
      shortLen = string2.size();
    } else {
      if (string2.size() >= string1.size() * 2) return 0;
      longLen = string2.size();
      shortLen = string1.size();
    }

    gap = longLen - shortLen;

    result = 60 - (60 * (1.0) * gap / shortLen);
    return result;
  }
};