#include <string>
#include <iostream>
#include <vector>

extern "C"
{
#include <libavformat/avformat.h>
#include <libavutil/mathematics.h>
#include <libavutil/time.h>
};

using namespace std;
class CPushStream{
 public:
  CPushStream(){};
  ~CPushStream(){};

  int start();
 private:
  ///推流输入源
  vector<string> input_urls;
  ///输出源
  string output_url;

  bool push();
};
