#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("V0.1 \n Usage: %s <time adjustment>\n", argv[0]);
        printf("  - Use +x to increase time by x milliseconds.\n");
        printf("  - Use -x to decrease time by x milliseconds.\n");
        return 1;
    }

    // 获取当前时间
    struct timeval currentTime;
    if (gettimeofday(&currentTime, NULL) != 0) {
        perror("Failed to get current time");
        return 1;
    }

    // 解析命令行参数
    double adjustment;
    if (sscanf(argv[1], "%lf", &adjustment) != 1) {
        printf("Invalid time adjustment: %s\n", argv[1]);
        return 1;
    }

    // 计算新的时间
    double adjustedTime = (double)currentTime.tv_sec * 1000.0 + (double)currentTime.tv_usec / 1000.0 + adjustment;
    long newSec = (long)(adjustedTime / 1000);
    long newUsec = (long)(adjustedTime * 1000) % 1000000;

    // 更新时间
    struct timeval newTime;
    newTime.tv_sec = newSec;
    newTime.tv_usec = newUsec;

    // 设置新时间
    if (settimeofday(&newTime, NULL) != 0) {
        perror("Failed to set new time");
        return 1;
    }

    printf("Adjusted time by %.2lf milliseconds.\n", adjustment);
    return 0;
}

