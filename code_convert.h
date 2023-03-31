#ifndef _CODE_CONVERT_H_
#define _CODE_CONVERT_H_
extern int HexStr2Byte(const char *hexStr, unsigned char *byte, int byteLen);
extern int Byte2HexStr(const unsigned char *byte, int byteLen, char *hexStr);
extern void printHex(unsigned char *data, int len);
#endif