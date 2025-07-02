#include <string>
using std::string;


class SimilarChecker {
 public:
  double stringLengthChecker(const string &string1, const string &string2){
    int longLen;
    int shortLen;
    int gap;
    double result;

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
    if (gap == 0) return 60;

    result = 60 - (60 * gap / shortLen);
    return result;
  }
};