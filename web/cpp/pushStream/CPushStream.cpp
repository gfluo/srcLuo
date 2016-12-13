#include "CPushStream.h"

int CPushStream::start(){
  this->push();
  return -1;
}

bool CPushStream::push(){
  AVOutputFormat *ofmt = nullptr;
  AVFormatContext *ifmt_ctx0 = nullptr;
  AVFormatContext *ifmt_ctx1 = nullptr;
  AVFormatContext *ofmt_ctx = nullptr;

  AVPacket pkt;
  string input_url0, input_url1, output_url;
  int ret;
  input_url0 = "/home/luogf/instreams/chenxiang1.mp4";
  input_url1 = "/home/luogf/instreams/chenxiang.mp4";

  output_url = "rtmp://127.0.0.1:1935/myapp/livestream";

  av_register_all();
  avformat_network_init();
  ///检测输入url是否有效
  if(0 > avformat_open_input(&ifmt_ctx0, 
			     input_url0.c_str(), nullptr, nullptr)
     || 0 > avformat_open_input(&ifmt_ctx1, 
				input_url1.c_str(), nullptr, nullptr)){
    cout << "输入源打开失败\n";
  }

  ///检测输入url的streams信息
  if(0 > avformat_find_stream_info(ifmt_ctx0, 0)
     || 0 > avformat_find_stream_info(ifmt_ctx1, 0)){
    cout << "输入源获取stream info 失败\n";
  }

  ///video streams索引
  int video_index0 = -1, video_index1 = -1;
  for(size_t i; i < ifmt_ctx0->nb_streams; i++){
    if(AVMEDIA_TYPE_VIDEO ==
       ifmt_ctx0->streams[i]->codecpar->codec_type){
      video_index0 = i;
      break;
    }
  }

  for(size_t j; j < ifmt_ctx1->nb_streams; j++){
    if(AVMEDIA_TYPE_VIDEO ==
       ifmt_ctx1->streams[j]->codecpar->codec_type){
      video_index1 = j;
      break;
    }
  }

  av_dump_format(ifmt_ctx0, 0, input_url0.c_str(), 0);
  av_dump_format(ifmt_ctx1, 0, input_url1.c_str(), 0);

  return false;
}
