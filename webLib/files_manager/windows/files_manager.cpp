#include "webLib/files_manager/files_manager.h"
#include <windows.h>

void FilesManager::openAndLockFile(std::string filename) {
  this->fileName = filename;
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
  } while ((int)handle == -1);
}

void FilesManager::readFromFile(FileData &fileData) {
  OVERLAPPED overlapped = {};
  DWORD read = 0;
  char str[1024] = {};
  ReadFile(fileHandle, str, 1024, &read, &overlapped);
  parseFile(std::string(str), fileData);
}

void FilesManager::writeToFile(FileData &fileData) {
  OVERLAPPED overlapped = {};
  DWORD written = 0;
  WriteFile(fileHandle, &fileData, sizeof(FileData), &written, &overlapped);
}

void FilesManager::unlockAndCloseFile() {
  UnlockFile(fileHandle, 0, 0, sizeof(FileData), 0);
  CloseHandle(fileHandle);
}
