#include <iostream>
#include <windows.h>

int main() {
    // Путь к приложению narek.exe
    std::string narekPath = "C:\\Users\\homel\\AppData\\Local\\narek\\narek.exe";

    // Команда для выполнения npm start без отображения окна cmd
    std::string npmCommand = "cmd.exe /C \"cd /d C:\\narek-express && npm start\"";

    // Компиляция команд в формат, который понимает Windows Shell
    const char* narekPathChar = narekPath.c_str();
    const char* npmCommandChar = npmCommand.c_str();

    // Запуск npm start без отображения окна
    ShellExecute(NULL, "open", "cmd.exe", "/C start /B \"\" cmd.exe /C \"cd /d C:\\narek-express && npm start\"", NULL, SW_HIDE);

    // Запуск приложения narek.exe без отображения окна
    ShellExecute(NULL, "open", narekPathChar, NULL, NULL, SW_HIDE);

    return 0;
}
