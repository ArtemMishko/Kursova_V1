#define NOMINMAX     // Виправлення проблеми з неоднозначністю byte
#define WIN32_LEAN_AND_MEAN  // Зменшення конфліктів заголовних файлів

#include "LibraryKafedraLL.h"

using namespace System;
using namespace System::Windows::Forms;

// Точка входу в програму
[STAThread]
int main() {
    // Встановлення локалі для коректного відображення кирилиці
    setlocale(LC_ALL, "Ukrainian");

    // Запуск Windows Forms додатку
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Library::LibraryForm());

    return 0;
}