
#include "QT_Challenge.hpp"

// Requires ErrorHandling.cpp

class Message_Class {
public:
    char msg[];


protected:

private:



};


DWORD readFromSerialPort(HANDLE hSerial, uint8_t* buffer, int buffersize)
{
    DWORD dwBytesRead = 0;
    if (!ReadFile(hSerial, buffer, buffersize, &dwBytesRead, NULL)) {
        //handle error
        ErrorExit(GetProc);
    }
    else {
        dwBytesRead = ReadFile(hSerial, buffer, buffersize, &dwBytesRead, NULL);

    }
    return dwBytesRead;
}

DWORD writeToSerialPort(HANDLE hSerial, uint8_t* data, int length)
{

    DWORD dwBytesRead = data;
    if (!WriteFile(hSerial, data, length, &dwBytesRead, NULL)) {
        ErrorExit(GetProc);
    }
    else {
        dwBytesRead = ReadFile(hSerial, buffer, buffersize, &dwBytesRead, NULL);
    }
    return dwBytesRead;
}

void closeSerialPort(HANDLE hSerial)
{
    CloseHandle(hSerial);
}