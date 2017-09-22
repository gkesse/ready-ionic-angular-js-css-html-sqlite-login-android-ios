//===============================================
#include "GProcess.h"
#include "GExit.h"
//===============================================
int main(int argc, char** argv) {
    GExit::Instance()->addFn(GExit::callback);
    GExit::Instance()->init();
    GProcess::Instance()->setAppName("C:\\Program Files (x86)\\CMake\\bin\\CMake-Gui.exe");
    GProcess::Instance()->createProcess();
    GProcess::Instance()->setModName("C:\\Windows\\System32\\ntdll.dll");
    GProcess::Instance()->createModule();
    return 0;
}
//===============================================
