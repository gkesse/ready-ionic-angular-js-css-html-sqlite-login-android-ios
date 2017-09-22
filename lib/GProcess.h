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
    void setModName(const string& modName);

public:
    void createProcess();
    void createModule();
    void releaseModule();

private:
    static GProcess* m_instance;
    string m_appName;
    string m_modName;
    STARTUPINFO m_startupInfo;
    PROCESS_INFORMATION m_processInformation;
    ulong m_pid;
    HMODULE m_hDLL;
};
//===============================================
#endif
//===============================================
