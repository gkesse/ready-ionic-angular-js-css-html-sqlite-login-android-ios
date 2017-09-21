//===============================================
#ifndef _GExit_
#define _GExit_
//===============================================
#include <iostream>
#include <vector>
#include <stdlib.h>
//===============================================
using namespace std;
//===============================================
class GExit {
private:
    GExit();

public:
    ~GExit();
    static GExit* Instance();
    
public:
    void addFn(void(*pFn)());

public:
    void init();

public:
    static void callback();

private:
    static GExit* m_instance;
    vector<void(*)()> m_fnMap;
};
//===============================================
#endif
//===============================================
