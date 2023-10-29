#define __STDC_FORMAT_MACROS
#include <iostream>
#include <inttypes.h>  


extern "C" {
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavformat/avio.h"
}

// 原来的宏定义
//#define av_err2str(errnum) \
//    av_make_error_string((char[AV_ERROR_MAX_STRING_SIZE]){0}, AV_ERROR_MAX_STRING_SIZE, errnum)
char av_error[AV_ERROR_MAX_STRING_SIZE] = { 0 };
#define av_err2str(errnum) av_make_error_string(av_error, AV_ERROR_MAX_STRING_SIZE, errnum)


static const char *type_string(int type)
{
    switch (type) {
    case AVIO_ENTRY_DIRECTORY:
        return "<DIR>";
    case AVIO_ENTRY_FILE:
        return "<FILE>";
    case AVIO_ENTRY_BLOCK_DEVICE:
        return "<BLOCK DEVICE>";
    case AVIO_ENTRY_CHARACTER_DEVICE:
        return "<CHARACTER DEVICE>";
    case AVIO_ENTRY_NAMED_PIPE:
        return "<PIPE>";
    case AVIO_ENTRY_SYMBOLIC_LINK:
        return "<LINK>";
    case AVIO_ENTRY_SOCKET:
        return "<SOCKET>";
    case AVIO_ENTRY_SERVER:
        return "<SERVER>";
    case AVIO_ENTRY_SHARE:
        return "<SHARE>";
    case AVIO_ENTRY_WORKGROUP:
        return "<WORKGROUP>";
    case AVIO_ENTRY_UNKNOWN:
    default:
        break;
    }
    return "<UNKNOWN>";
}


static void usage(const char *program_name) {
    fprintf(stderr, "usage: %s input_dir\n"
        "API example program to show how to list files in directory "
        "accessed through AVIOContext.\n", program_name);
}

static int list_op(const char *input_dir) {
    AVIODirEntry *entry = NULL;
    AVIODirContext *ctx = NULL;
    int cnt, ret;
    char filemode[4], uid_and_gid[20];

    // 注意Windows下会返回-40，也就是Function not implement，方法未实现，也就是说windows下不支持此方法
    if ((ret = avio_open_dir(&ctx, input_dir, NULL)) < 0) {
        av_log(NULL, AV_LOG_DEBUG, "Cannot open directory: %s.\n", av_err2str(ret));
        avio_close_dir(&ctx);
        return ret;
    }

    cnt = 0;
    while (1) {
        if ((ret = avio_read_dir(ctx, &entry)) < 0) {
            av_log(NULL, AV_LOG_ERROR, "Cannot list directory: %s.\n", av_err2str(ret));
            avio_close_dir(&ctx);
            return ret;
        }
        if (!entry)
            break;
        if (entry->filemode == -1) {
            snprintf(filemode, 4, "???");
        } else {
            //snprintf(filemode, 4, "%3"PRIo64, entry->filemode);
        }
        //PRId64这是一种跨平台的书写方式，主要是为了同时支持32位和64位操作系统。
        //snprintf(uid_and_gid, 20, "%"PRId64"(%"PRId64")", entry->user_id, entry->group_id);
        if (cnt == 0) {
            av_log(NULL, AV_LOG_INFO, "%-9s %12s %30s %10s %s %16s %16s %16s\n",
                "TYPE", "SIZE", "NAME", "UID(GID)", "UGO", "MODIFIED",
                "ACCESSED", "STATUS_CHANGED");
        }
        //av_log(NULL, AV_LOG_INFO, "%-9s %12"PRID64" %30s %10s %s %16"PRID64" %16"PRID64" %16"PRID64"\n",
        //    type_string(entry->type),
        //    entry->size,
        //    entry->name,
        //    uid_and_gid,
        //    filemode,
        //    entry->modification_timestamp,
        //    entry->access_timestamp,
        //    entry->status_change_timestamp);
        avio_free_directory_entry(&entry);
        cnt++;
    }
}

int main(int argc, char* argv[])
{
    std::cout << "FFmpeg Test1 avio\n";

    int ret;
    av_log_set_level(AV_LOG_DEBUG);

    if (argc < 2) {
        usage(argv[0]);
        system("pause");
        return 1;
    }

    avformat_network_init(); // 初始化网络库

    ret = list_op(argv[1]);

    avformat_network_deinit();  // 反初始化网络库
    system("pause");
}

