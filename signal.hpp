#pragma once

#include <Windows.h>

#include <iostream>

BOOL WINAPI consoleHandler(DWORD signal) {
  if (signal == CTRL_C_EVENT)
    printf("Ctrl-C handled\n"); // do cleanup

  return TRUE;
}

void CatcureSignal() { SetConsoleCtrlHandler(consoleHandler, TRUE); }
