#ifndef LINUXDEFS_H
#define LINUXDEFS_H

#if defined (__linux__)
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

#define MAX_PATH          260
#define _MAX_PATH			MAX_PATH
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#define strcpy_s(dest, size, src) (strncpy((dest), (src), (size)))
#define sscanf_s(dest, format, ...)  (sscanf((dest),(format), (__VA_ARGS__) ))
#define strcat_s(dest, size, src) (strcat((dest), (src)))
#define sprintf_s snprintf
#define Sleep(miliseconds) (usleep((miliseconds*1000)))
//#define __int64 int64_t
//#define __int32 int32_t
#define MAXDWORD    0xffffffff  
//#define ULONG unsigned long
//#define UINT unsigned int
#ifndef FALSE
#define FALSE               0
#endif
#ifndef TRUE
#define TRUE                1
#endif
/*
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))double GetTickCount
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
*/
#define SOCKET_ERROR            (-1)
#define INFINITE            0xFFFFFFFF  // Infinite timeout
typedef void* HANDLE;
typedef int					 BOOL;
typedef unsigned int		 DWORD;
typedef signed int			 INT32;
typedef long                 LONG;
typedef uint64_t             UINT64;
typedef uint16_t             UINT;
//typedef char*				 BSTR;
//typedef std::size_t			size_t;
typedef uintptr_t DWORD_PTR;
typedef void* LPVOID;
typedef uint32_t* LPDWORD;
typedef unsigned char BYTE;
typedef int32_t __int32;
typedef int64_t __int64;

typedef pthread_mutex_t CRITICAL_SECTION;
typedef long LONG_PTR;
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define TEXT( A )               A

double GetTickCount(void);
void getLinuxAppDirectory(char* path);
#endif


#endif