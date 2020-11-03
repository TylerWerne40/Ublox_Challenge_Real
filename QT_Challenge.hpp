// Header for QT challenge 
// includes Message_Parsing.cpp

//#include "Message_parsing.cpp"
//#include "ErrorHandling.cpp"



LPTSTR GetProc = (TCHAR*)"GetProcessID";

// MessageParsing.cpp

Message_Class Message_parser;
DWORD readFromSerialPort(HANDLE hSerial, uint8_t* buffer, int buffersize);
DWORD writeToSerialPort(HANDLE hSerial, uint8_t* data, int length);
void closeSerialPort(HANDLE hSerial);

// ErrorHandling.cpp


void ErrorExit(LPTSTR lpszFunction);