#include "gmock/gmock.h"
#include "similarityChecker.cpp"

using namespace testing;

class SimilarCheckerFixture : public testing::Test {
 public:
  SimilarChecker similarch;
  void characterLengthChecker(const string& firstString, const string& SecondString, double expected){
    double acutal = similarch.stringLengthChecker(firstString, SecondString);
    EXPECT_EQ(expected, acutal);
  }
  
  void countingTheNumberSameAlpha(const string& firstString,
                                  const string& SecondString, int expected) {
    int acutal = similarch.countTheAlpha(firstString, SecondString);
    EXPECT_EQ(expected, acutal);
  }
};

TEST_F(SimilarCheckerFixture, LengthGapChecker0) {
  characterLengthChecker("AAAA", "AB",0);
}

TEST_F(SimilarCheckerFixture, LengthGapChecker60_CASE1) {
  characterLengthChecker("DSA", "ADS", 60);
}

TEST_F(SimilarCheckerFixture, LengthGapCheckerPart_CASE1) {
  characterLengthChecker("AAABB", "BAA", 20);
}

TEST_F(SimilarCheckerFixture, LengthGapCheckerPart_CASE2) {
  characterLengthChecker("AA", "AAE", 30);
}

TEST_F(SimilarCheckerFixture, CountTheNumberAlpha_Same_Case1) {
  countingTheNumberSameAlpha("DSA", "ADS", 40);
}

TEST_F(SimilarCheckerFixture, CountTheNumberAlpha_Zero) {
  countingTheNumberSameAlpha("A", "BB", 0);
}

TEST_F(SimilarCheckerFixture, CountTheNumberAlpha_Same_Case2) {
  countingTheNumberSameAlpha("AAABB", "BA", 40);
}
TEST_F(SimilarCheckerFixture, CountTheNumberAlpha_Part_Case1) {
  countingTheNumberSameAlpha("AA", "AAE", 20);
}



int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}