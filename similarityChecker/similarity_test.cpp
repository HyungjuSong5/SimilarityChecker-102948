#include "gmock/gmock.h"
#include "similarityChecker.cpp"

using namespace testing;

class SimilarCheckerFixture : public testing::Test {
 public:
  SimilarChecker similarch;
  void SimilarCheckerApp(const string& firstString, const string& SecondString, double expected){
    double acutal = similarch.stringLengthChecker(firstString, SecondString);
    EXPECT_EQ(expected, acutal);
  }
};

TEST_F(SimilarCheckerFixture, LengthGapChecker0) {
  SimilarCheckerApp("AAAA", "AB",0);
}

TEST_F(SimilarCheckerFixture, LengthGapChecker60_CASE1) {
  SimilarCheckerApp("DSA", "ADS", 60);
}

TEST_F(SimilarCheckerFixture, LengthGapCheckerPart_CASE1) {
  SimilarCheckerApp("AAABB", "BAA", 20);
}

TEST_F(SimilarCheckerFixture, LengthGapCheckerPart_CASE2) {
  SimilarCheckerApp("AA", "AAE", 30);
}
int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}