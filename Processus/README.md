# Processus

Un **Processus** est un programme en cours d'exécution auquel est associé  
un environnement processeur et un environnement mémoire.

# Création d'un processus

Pour créer un processus, sous Windows:
* Définissez le chemin complet du processus **appName**
* Créez le processus avec la méthode **CreateProcess()**

# Code source
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

# Résultats
![Resultats](https://raw.githubusercontent.com/gkesse/ReadyThread/master/Processus/img/Terminal.png)
![Resultats](https://raw.githubusercontent.com/gkesse/ReadyThread/master/Processus/img/Processus.png)

# Voir Aussi

* [ReadyThread](https://github.com/gkesse/ReadyThread "ReadyThread")  
* [Processus](https://github.com/gkesse/ReadyThread/tree/master/Processus "Processus")  
