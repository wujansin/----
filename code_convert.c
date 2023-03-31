#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "code_convert.h"

//"12345678ABCDEF" -> 0x12, 0x34, 0x56, 0x78, 0xAB, 0xCD, 0xEF
int HexStr2Byte(const char *hexStr, unsigned char *byte, int byteLen)
{
    int i = 0;
    for (i = 0; i < byteLen; i++)
    {
        if (hexStr[i * 2] >= '0' && hexStr[i * 2] <= '9')
        {
            byte[i] = (hexStr[i * 2] - '0') << 4;
        }
        else if (hexStr[i * 2] >= 'A' && hexStr[i * 2] <= 'F')
        {
            byte[i] = (hexStr[i * 2] - 'A' + 10) << 4;
        }
        else if (hexStr[i * 2] >= 'a' && hexStr[i * 2] <= 'f')
        {
            byte[i] = (hexStr[i * 2] - 'a' + 10) << 4;
        }
        else
        {
            return -1;
        }
        if (hexStr[i * 2 + 1] >= '0' && hexStr[i * 2 + 1] <= '9')
        {
            byte[i] |= (hexStr[i * 2 + 1] - '0');
        }
        else if (hexStr[i * 2 + 1] >= 'A' && hexStr[i * 2 + 1] <= 'F')
        {
            byte[i] |= (hexStr[i * 2 + 1] - 'A' + 10);
        }
        else if (hexStr[i * 2 + 1] >= 'a' && hexStr[i * 2 + 1] <= 'f')
        {
            byte[i] |= (hexStr[i * 2 + 1] - 'a' + 10);
        }
        else
        {
            return -1;
        }
    }
    return 0;
}



int Byte2HexStr(const unsigned char *byte, int byteLen, char *hexStr)
{
    int i = 0;
    for (i = 0; i < byteLen; i++)
    {
         snprintf(hexStr + i * 2, 3, "%02X", byte[i]);
    }
    return 0;
}

//輸入byte陣列，列印出16進位的字串,每行16個byte,每個byte以空白隔開  
void printHex(unsigned char *data, int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("%02X ", data[i]);
        if ((i + 1) % 16 == 0)
        {   
            printf("\n");   
        }   
    }   
    printf("\n");   
}   
        