#pragma once
#include <Windows.h>

// Функция для скрытия/показа каретки
void CursorHide(BOOL bVisible=0, DWORD dwSize=1)
{
  HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
  // Get console handle
  hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);

  // Hide console cursor
  CONSOLE_CURSOR_INFO cursorInfo;
  cursorInfo.dwSize = dwSize;
  cursorInfo.bVisible = bVisible;
  SetConsoleCursorInfo(hOUTPUT, &cursorInfo);
}

void SetColor(WORD wAttributes) {// функция для смена цвета
  HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hOUTPUT, wAttributes);
}

// Функция для выбора позиции
void SetPos(int x, int y) {// функция для установки позиции каретки по координатам
  COORD cd;
  cd.X = x;
  cd.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}



typedef BOOL(WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);
typedef BOOL(WINAPI *SETCURRENTCONSOLEFONTEX)(HANDLE, BOOL, PCONSOLE_FONT_INFOEX);
SETCONSOLEFONT SetConsoleFont;

void start(int row=30, int column=60)
{
  OSVERSIONINFOEX osvi;
  CONSOLE_FONT_INFOEX cfon;
  ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
  osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  GetVersionEx((OSVERSIONINFO *)&osvi);
  HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");
  if (osvi.dwMajorVersion<6) {
    SetConsoleFont = (SETCONSOLEFONT)GetProcAddress(hmod, "SetConsoleFont");
    if (!SetConsoleFont) { exit(1); }
    SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), 10);
  }
  else
  {
    if (!SetCurrentConsoleFontEx) { exit(1); }
    ZeroMemory(&cfon, sizeof(CONSOLE_FONT_INFOEX));
    cfon.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    //GetCurrentConsoleFontEx(
    //  GetStdHandle(STD_OUTPUT_HANDLE),0, &cfon);
    cfon.FontFamily = 54;
    cfon.nFont = 20;
    cfon.dwFontSize.X = 15;
    cfon.dwFontSize.Y = 20;
    cfon.FontWeight = 400;
    wcscpy(cfon.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(
      GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfon);
  }
  char buf[256] = { 0 };
  sprintf(buf, "mode con cols=%d lines=%d", column, row);
  system(buf);
  system("cls");
  CursorHide();
}
