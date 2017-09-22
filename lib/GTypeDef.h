//===============================================
#ifndef _GTypeDef_
#define _GTypeDef_
//===============================================
#include <windows.h>
#include <Winternl.h>
//===============================================
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
//===============================================
typedef NTSTATUS (NTAPI* GNtQueryInformationProcess)(
        IN HANDLE ProcessHandle,
        IN PROCESSINFOCLASS ProcessInformationClass,
        OUT PVOID ProcessInformation,
        IN ULONG ProcessInformationLength,
        OUT PULONG ReturnLength OPTIONAL);
//===============================================
#endif
//===============================================
