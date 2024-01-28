# Instalacja Qt creator
Aby zainstalować QT creator należy:
1. Wejść na stronę https://www.qt.io/download-open-source
2. Pobrać QT Online Installer
3. Założyć konto QT.
4. Przprowadzać instalację Zaznaczać:
   -Że nie używa się QT dla firmy
   -Custom instalation
5. Dla instalacji na Windowsa 64 bit, w zakładce Select components wybrać:
   - Qt 5.15.2:
     - MinGW 8.1.0 64-bit
   - Developer and Designer Tools:
     - Qt Creator 12.0.1
     - Qt Creator 12.0.1 CDB Debugger Support
     - Debugging Tools for Windows
     - Cmake 3.27.7
     - Ninja 1.10.2
6. Dokończyć instalację
# Otwarcie i skompilowanie projektu
Aby po raz pierwszy zbudować program należy:
1. W Qt Creatorze kliknąć Plik->Otwórz plik lub projekt.
2. Zaznaczyć cały wszykie pliki w folderze eBuggyDisplay.
3. Jako kompilator zastosować Qt 5.15.2 MinGW 64 bit
4. Kliknąć praym na projekt i kliknąć "Dodaj istniejące pliki" i wybrać te które się nie dodały:
   - can.cpp
   - can.h
   - resources.qrc
   - zmienne.h
5. W lewym dolnym rogu znajdują ikony do uruchomienia, zbudowania i uruchomienia oraz samego zbudawania programu.
Po wciśnięciu "Rozpicznij Debugowanie projektu startowego" powinien wyświetlić się program.
