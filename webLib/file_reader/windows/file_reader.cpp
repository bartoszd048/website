#include "webLib/file_reader/file_reader.h"
#include <windows.h>

void FileReader::openAndLockFile(std::string filename) {
  OVERLAPPED overlapped = {};
  HANDLE handle = 0;
  do {
    handle = CreateFile(filename.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL,
                        OPEN_EXISTING, 0, NULL);
    if ((int)handle != -1) {
      fileHandle = handle;

      LockFileEx(fileHandle, LOCKFILE_EXCLUSIVE_LOCK, 0, sizeof(FileData), 0,
                 &overlapped);
    }
  } while ((int)handle != -1);
}

void FileReader::readFromFile(FileData &fileData) {
  OVERLAPPED overlapped = {};
  DWORD read = 0;
  ReadFile(fileHandle, &fileData, sizeof(FileData), &read, &overlapped);
}

void FileReader::unlockAndCloseFile() {
  UnlockFile(fileHandle, 0, 0, sizeof(FileData), 0);
  CloseHandle(fileHandle);
}
