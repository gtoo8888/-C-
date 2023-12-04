#define __STDC_FORMAT_MACROS
#include <iostream>
#include <inttypes.h>  


extern "C" {
#include "libavcodec/avcodec.h"

#include "libavutil/opt.h"
}

// 参考例子doc\examples\encode_video.c
// ./encode_video [视频路径] [编码器名称]
// ./encode_video ./test.mp4 mpeg4
// ./ffplay 播放当前视频
// ./ffplay ./test.mp4

int main(int argc, char* argv[])
{
    const char *filename, *codec_name;
    const AVCodec *codec;
    AVCodecContext *context = NULL;
    int i, ret, x, y;
    FILE *f;
    AVFrame *frame;
    AVPacket *pkt;
    uint8_t encode[] = { 0,0,1,0xb7 };

    if (argc <= 2) {
        fprintf(stderr, "Usage: %s <output file> <codec name>\n", argv[0]);
        exit(0);
    }
    filename = argv[1];
    codec_name = argv[2];
    
    codec = avcodec_find_encoder_by_name(codec_name);
    if (!codec) {
        fprintf(stderr, "Codec '%s' not found\n", codec_name);
        exit(1);
    }
    context = avcodec_alloc_context3(codec);
    if (!context) {
        fprintf(stderr, "Could not allocate video codec context\n");
        exit(1);
    }

    pkt = av_packet_alloc();
    if (!pkt) {
        exit(1);
    }

    context->bit_rate = 400000;
    context->width = 352;
    context->height = 288;
    AVRational timebase = { 1, 25 }; // 只能用普通初始化
    context->time_base = timebase;
    //context->framerate = (AVRational){ 25, 1 }; // VS2017不能使用复合字面量初始化
    AVRational framerate = { 25, 1 };
    context->framerate = framerate;



    system("pause");
}

