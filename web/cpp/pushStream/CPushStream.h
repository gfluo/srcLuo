#include <string>
#include <iostream>
#include <vector>

using namespace std;
class CPushStream{
 public:
  CPushStream(){};
  ~CPushStream(){};

 private:
  ///推流输入源
  vector<string> input_urls;
  ///输出源
  string output_url;

  bool push();
};
