#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "code_convert.h"
#include <sys/stat.h>
#include <fcntl.h>


void main(void)
{
    //string to hex 
    char test[] = "0123456789ABCDEF";
    char *hexStr = (char *)malloc(strlen(test)/2);
    HexStr2Byte(test, hexStr, strlen(test));
    printf("String To Hex = ");
    for(int i = 0; i < strlen(test)/2; i++)
    {
        printf("0x%02X ", (unsigned char)hexStr[i]);
    }
    printf("\n");
    free(hexStr);
    //Hex to String
    char test2[] = {0x12, 0x34, 0x56, 0x78, 0xAB, 0xCD, 0xEF};
    char *str = (char *)malloc(sizeof(test2)*2 + 1);
    Byte2HexStr(test2, sizeof(test2), str);
    printf("hexstr = %s \n", str);
    free(str);

    //列印00~FF
    char test3[256]={0};
    for(int i=0;i<256;i++)
        test3[i]=i;
    printHex(test3, sizeof(test3));   
    
    //從文字檔讀取內容, 列印文字內容
    struct stat sb;
    FILE *fp = fopen("test.txt", "r");
    if(fp == NULL)
    {
        printf("File open error!\n");
        return;
    } 
    
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (fstat(fd, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    printf("file size = %ld \n", sb.st_size);

    char *buf = (char *)malloc(sb.st_size);
    fread(buf, 1, 1024, fp);
    printf("buf =%s\n", buf); 
  

    //從文字檔讀取數字內容, 數字用逗號分隔, 取出數字,存入byte buffer
    char *token = strtok(buf, ",");
    int i = 0;
    unsigned char *byte = (unsigned char *)malloc(1024);
    unsigned char sbyte;
    while(token != NULL)
    {        
        HexStr2Byte(token, &sbyte, 1);
        byte[i] = sbyte;
        token = strtok(NULL, ",");
        i++;
    }
    printf("byte = ");
    for(int j = 0; j < i; j++)
    {
        printf("0x%02X ", byte[j]);
    }
    printf("\n");
    free(buf);
    free(byte);
    fclose(fp);
    
    
}