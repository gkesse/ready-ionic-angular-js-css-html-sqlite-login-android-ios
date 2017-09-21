//===============================================
#include "GProcess.h"
#include "GExit.h"
//===============================================
int main(int argc, char** argv) {
    GExit::Instance()->addFn(GExit::callback);
    GExit::Instance()->init();
    GProcess::Instance()->setAppName("C:\\Program Files (x86)\\CMake\\bin\\CMake-Gui.exe");
    GProcess::Instance()->createProcess();
    return 0;
}
//===============================================
