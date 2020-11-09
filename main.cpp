#include "QT_Challenge.hpp"

//using namespace std;

Message_Class MESS;


int main(int argc, char** argv)
{
    LPCWSTR portname = TEXT("COM1");
    DWORD  accessdirection = GENERIC_READ | GENERIC_WRITE;
    HANDLE hSerial = CreateFile(portname,       // Resource: https://docs.microsoft.com/en-us/windows/win32/devio/configuring-a-communications-resource
        accessdirection,
        0,      //  must be opened with exclusive-access
        0,      //  default security attributes
        OPEN_EXISTING,  //  must use OPEN_EXISTING
        0,      //  not overlapped I/O
        0);     //  hTemplate must be NULL for comm devices
    if (hSerial == INVALID_HANDLE_VALUE) {
        //call GetLastError(); to gain more information
        ErrorExit(GetProc);
    }
    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        //could not get the state of the comport
        ErrorExit(GetProc);
    }

    // Setup Communications Channel 
    dcbSerialParams.BaudRate = 115200;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    if (!SetCommState(hSerial, &dcbSerialParams)) {
        //analyse error
        ErrorExit(GetProc);
    }

    // Setup when the conneciton Timesout. Resource: https://docs.microsoft.com/en-us/windows/win32/api/winbase/ns-winbase-commtimeouts
    // So conneciton doesn't timeout one single empty communique
    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = 60;              // maximum time allowed to elapse before the arrival of the next byte on the communications line, in ms
    timeouts.ReadTotalTimeoutConstant = 60;         // constant used to calculate the total time-out period for read operations, in ms
    timeouts.ReadTotalTimeoutMultiplier = 10;       // multiplier used to calculate the total time-out period for read operations, in ms
    timeouts.WriteTotalTimeoutConstant = 60;        // constant used to calculate the total time-out period for write operations, in ms
    timeouts.WriteTotalTimeoutMultiplier = 10;      // multiplier used to calculate the total time-out period for write operations, in milliseconds
    if (!SetCommTimeouts(hSerial, &timeouts)) {
        //handle error
        ErrorExit(GetProc);
    }

    /*
    Do Comms
    */
    uint8_t* buffer = MESS.msg;
    int buffersize = 8;
    DWORD read_flag;

    while (TRUE) // Run Communications by polling
    {
        if (TRUE)
        {
            read_flag = MESS.readFromSerialPort(hSerial, buffer, buffersize);
            if ((read_flag != 0))
            {
                printf("%c \n", MESS.msg);
            }
            /*
            else if ((read_flag != 0) & (is_empty(msg)))
            {
                // End of file error
            }
            */
            else
            {
                // Generic Error
            }
        }
    }

    // End Program
    MESS.closeSerialPort(hSerial);
    return 0;
};