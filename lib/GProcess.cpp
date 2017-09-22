//===============================================
#include "GProcess.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess() {
    m_startupInfo = {0};
    m_processInformation = {0};
}
//===============================================
GProcess::~GProcess() {
    
}
//===============================================
GProcess* GProcess::Instance() {
    if(m_instance == 0) {
        m_instance = new GProcess;
    }
    return m_instance;
}
//===============================================
void GProcess::setAppName(const string& appName) {
    m_appName = appName;
}
//===============================================
void GProcess::setModName(const string& modName) {
    m_modName = modName;
}
//===============================================
void GProcess::createProcess() {
    wstring m_wsTmp = wstring(m_appName.begin(), m_appName.end());
    LPCWSTR m_ws = m_wsTmp.c_str();

    int m_res = CreateProcess(
                m_ws, NULL, NULL,
                NULL, FALSE, NULL, NULL, NULL, &m_startupInfo,
                &m_processInformation);

    if(m_res == 0) {
        cout << "ERROR : CreateProcess()...\n";
        cout << "ERROR : CODE : " << GetLastError() << "\n";
        exit(0);
    }

    cout << "SUCCESS : CreateProcess()...\n";
    cout << "Application : " << m_appName << "\n";

    m_pid = m_processInformation.dwProcessId;
    cout << "PID : " << m_pid << "\n";
}
//===============================================
void GProcess::createModule() {
    wstring m_wsTmp = wstring(m_modName.begin(), m_modName.end());
    LPCWSTR m_ws = m_wsTmp.c_str();

    m_hDLL = LoadLibrary(m_ws);

    if(m_hDLL == 0) {
        cout << "ERROR : LoadLibrary()...\n";
        cout << "ERROR : CODE : " << GetLastError() << "\n";
        exit(0);
    }

    cout << "SUCCESS : LoadLibrary()...\n";
    cout << "Library : " << m_modName << "\n";

    GNtQueryInformationProcess NtQueryInformationProcess =
            (GNtQueryInformationProcess)GetProcAddress(
                m_hDLL, "NtQueryInformationProcess");

    if(NtQueryInformationProcess == 0) {
        cout << "ERROR : GetProcAddress()...\n";
        cout << "ERROR : CODE : " << GetLastError() << "\n";
        exit(0);
    }

    cout << "SUCCESS : GetProcAddress()...\n";

    PROCESS_BASIC_INFORMATION m_pbi;
    ulong m_length;

    NTSTATUS m_ntStatus = NtQueryInformationProcess(
                m_processInformation.hProcess,
                PROCESSINFOCLASS::ProcessBasicInformation,
                &m_pbi, sizeof(m_pbi), &m_length);

    if(NT_SUCCESS(m_ntStatus) == 0) {
        cout << "ERROR : NtQueryInformationProcess()...\n";
        cout << "ERROR : CODE : " << GetLastError() << "\n";
        releaseModule();
        exit(0);
    }


    cout << "SUCCESS : NtQueryInformationProcess()...\n";
    cout << "UniqueProcessId : " << m_pbi.UniqueProcessId << "\n";

    releaseModule();
}
//===============================================
void GProcess::releaseModule() {
    FreeLibrary(m_hDLL);
}
//===============================================
