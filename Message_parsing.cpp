
#include "QT_Challenge.hpp"


// Requires ErrorHandling.cpp from QT_Challenge.hpp


uint8_t msg[8] = { 0, 0, 0, 0, 0, 0, 0, 0};

DWORD Message_Class::readFromSerialPort(HANDLE hSerial, uint8_t* buffer, int buffersize)
{
	DWORD dwBytesRead = 8; //  Same as dcbSerialParams.ByteSize
	if (!ReadFile(hSerial, buffer, buffersize, &dwBytesRead, NULL)) {
		//handle error
		ErrorExit(GetProc);
	}
	else {
		dwBytesRead = ReadFile(hSerial, buffer, buffersize, &dwBytesRead, NULL);
		/*
		for (int i = 0; i < (dwBytesRead + 1); i++) 
		{
			msg[i] = buffer[i];
		}
		*/
	}
	return dwBytesRead;
}

DWORD Message_Class::writeToSerialPort(HANDLE hSerial, uint8_t* data, int length)
{

	DWORD dwBytesRead = 8; //  Same as dcbSerialParams.ByteSize
	if (!WriteFile(hSerial, data, length, &dwBytesRead, NULL)) {
		ErrorExit(GetProc);
	}
	else {
		dwBytesRead = WriteFile(hSerial, data, length, &dwBytesRead, NULL);
	}
	return dwBytesRead;
}

void Message_Class::closeSerialPort(HANDLE hSerial)
{
	CloseHandle(hSerial);
}