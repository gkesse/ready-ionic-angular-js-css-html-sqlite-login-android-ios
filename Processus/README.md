# Processus

Un **Processus** est un programme en cours d'exécution auquel est associé 
un environnement processeur et un environnement mémoire.

La gestion d'un processus nécessite les actions suivantes:
* Créez le processus
* Utilisez le processus

# Création d'un processus

Pour créer un processus, sous Windows:
* Utilisez la méthode **CreateProcess()**
```
//===============================================
void GProcess::createProcess() {
    wstring m_wsTmp = wstring(m_appName.begin(), m_appName.end());
    LPCWSTR m_ws = m_wsTmp.c_str();

    BOOL m_res = CreateProcess(
                m_ws, NULL, NULL,
                NULL, FALSE, NULL, NULL, NULL, &m_startupInfo,
                &m_processInformation);

    if(m_res == 0) {
        cout << "ERROR : The process isn't created...\n";
        exit(0);
    }

    cout << "SUCCESS : The process is created...\n";
}
//===============================================
```

# Voir Aussi

* [ReadyThread](https://github.com/gkesse/ReadyThread "ReadyThread")  
* [Processus](https://github.com/gkesse/ReadyThread/tree/master/Processus "Processus")  
