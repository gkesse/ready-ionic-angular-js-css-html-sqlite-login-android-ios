//===============================================
#ifndef _GProcess_
#define _GProcess_
//===============================================
#ifndef UNICODE
#define UNICODE
#endif
//===============================================
#include "GTypeDef.h"
#include <iostream>
#include <string>
#include <windows.h>
//===============================================
using namespace std;
//===============================================
class GProcess {
private:
    GProcess();

public:
    ~GProcess();
    static GProcess* Instance();
    
public:
    void setAppName(const string& appName);

public:
    void createProcess();

private:
    static GProcess* m_instance;
    string m_appName;
    STARTUPINFO m_startupInfo;
    PROCESS_INFORMATION m_processInformation;
    ulong m_pid;
};
//===============================================
#endif
//===============================================
