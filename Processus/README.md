# Processus

Un **Processus** est un programme en cours d'exécution auquel est associé  
un environnement processeur et un environnement mémoire.

Un Processus contient au moins 1 Thread, le Thread principal  
ou plusieurs Threads, les Threads sécondaires.

# Programme de Test
```
GProcess::Instance()->setAppName("C:\\Program Files (x86)\\CMake\\bin\\CMake-Gui.exe");
GProcess::Instance()->createProcess();
GProcess::Instance()->setModName("C:\\Windows\\System32\\ntdll.dll");
GProcess::Instance()->createModule();
```

Création d'un processus:
```
wstring m_wsTmp = wstring(m_appName.begin(), m_appName.end());
LPCWSTR m_ws = m_wsTmp.c_str();

int m_res = CreateProcess(
            m_ws, NULL, NULL,
            NULL, FALSE, NULL, NULL, NULL, &m_startupInfo,
            &m_processInformation);
```

# Chargement d'un module
```
wstring m_wsTmp = wstring(m_modName.begin(), m_modName.end());
LPCWSTR m_ws = m_wsTmp.c_str();

m_hDLL = LoadLibrary(m_ws);
```

# Création d'un pointeur de fonction
```
typedef NTSTATUS (NTAPI* GNtQueryInformationProcess)(
        IN HANDLE ProcessHandle,
        IN PROCESSINFOCLASS ProcessInformationClass,
        OUT PVOID ProcessInformation,
        IN ULONG ProcessInformationLength,
        OUT PULONG ReturnLength OPTIONAL);
```

# Chargement d'une fonction
```
GNtQueryInformationProcess NtQueryInformationProcess =
        (GNtQueryInformationProcess)GetProcAddress(
            m_hDLL, "NtQueryInformationProcess");
```

# Exécution d'une fonction
```
NTSTATUS m_ntStatus = NtQueryInformationProcess(
            m_processInformation.hProcess,
            PROCESSINFOCLASS::ProcessBasicInformation,
            &m_pbi, sizeof(m_pbi), &m_length);
```

# Destruction d'un gestionnaire de module
```
NTSTATUS m_ntStatus = NtQueryInformationProcess(
            m_processInformation.hProcess,
            PROCESSINFOCLASS::ProcessBasicInformation,
            &m_pbi, sizeof(m_pbi), &m_length);
```

# Résultats
![Resultats](https://raw.githubusercontent.com/gkesse/ReadyThread/master/Processus/img/Terminal.png)
![Resultats](https://raw.githubusercontent.com/gkesse/ReadyThread/master/Processus/img/Processus.png)

# Voir Aussi

* [ReadyThread](https://github.com/gkesse/ReadyThread "ReadyThread")  
* [Processus](https://github.com/gkesse/ReadyThread/tree/master/Processus "Processus")  
