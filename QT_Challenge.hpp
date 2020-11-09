// Header for QT challenge 

//#include "Message_parsing.cpp"
//#include "ErrorHandling.cpp"
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <strsafe.h>
#include <atlbase.h>
#include <assert.h>
#include <string.h>


extern LPTSTR GetProc;

// MessageParsing.cpp

class Message_Class
{
public:
	uint8_t msg[8];
	DWORD readFromSerialPort(HANDLE hSerial, uint8_t* buffer, int buffersize);
	DWORD writeToSerialPort(HANDLE hSerial, uint8_t* data, int length);
	void closeSerialPort(HANDLE hSerial);

protected:

private:
};

// ErrorHandling.cpp


extern void ErrorExit(LPTSTR lpszFunction);