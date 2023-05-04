#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 1024

// 统计字符数的函数
int count_chars(char* filename) {
    // 读取文件并统计字符数
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    int count = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        count++;
    }
    fclose(fp);
    return count;
    	
}

// 统计单词数的函数
int count_words(char* filename) {
    // 读取文件并统计单词数
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    int count = 0;
    char c;
    // 实现统计单词数的逻辑
    while ((c = fgetc(fp)) != EOF) {
        if (c == ' ' || c == ','){
            count++;
        }
	}
	count ++;
	
    fclose(fp);
    return count;
}


int main(int argc, char** argv) {
    // 获取命令行参数，包括控制参数和输入文件名
    char filename[MAX_FILENAME_LEN];
    strcpy(filename, argv[2]);
    
    // 判断控制参数
    int count;
    if (strcmp(argv[1], "-c") == 0) {
        count = count_chars(filename);
        printf("字符数：%d\n", count);
    } else if (strcmp(argv[1], "-w") == 0) {
        count = count_words(filename);
        printf("单词数：%d\n", count);
    } else {
        printf("Error: 无效的控制参数\n");
        exit(1);
    }
    
    return 0;
}
