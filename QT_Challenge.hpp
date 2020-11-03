// Header for QT challenge 
// includes Message_Parsing.cpp

//#include "Message_parsing.cpp"
//#include "ErrorHandling.cpp"
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <strsafe.h>
#include <atlbase.h>
#include <assert.h>
#include <string.h>


LPTSTR GetProc = (TCHAR*)"GetProcessID";

// MessageParsing.cpp

extern class Message_Class;
extern DWORD readFromSerialPort(HANDLE hSerial, uint8_t* buffer, int buffersize);
extern DWORD writeToSerialPort(HANDLE hSerial, uint8_t* data, int length);
extern void closeSerialPort(HANDLE hSerial);

// ErrorHandling.cpp


extern void ErrorExit(LPTSTR lpszFunction);