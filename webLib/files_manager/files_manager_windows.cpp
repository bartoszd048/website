#include "webLib/files_manager/files_manager.h"
#include <windows.h>

void FilesManager::openAndLockFile(std::string filename) {
  OVERLAPPED overlapped = {};
  do {
    fileHandle = CreateFile(filename.c_str(), GENERIC_READ | GENERIC_WRITE, 0,
                            NULL, OPEN_EXISTING, 0, NULL);
  } while ((int)fileHandle == -1);

  LockFileEx(fileHandle, LOCKFILE_EXCLUSIVE_LOCK, 0, sizeof(FileData), 0,
             &overlapped);
}

std::string FilesManager::readFromFile() {
  OVERLAPPED overlapped = {};
  DWORD read = 0;
  char str[1024] = {};
  ReadFile(fileHandle, str, 1024, &read, &overlapped);
  return std::string(str);
}

void FilesManager::writeToFile(std::string &data) {
  OVERLAPPED overlapped = {};
  DWORD written = 0;

  WriteFile(fileHandle, data.c_str(), data.length(), &written, &overlapped);
}

void FilesManager::unlockAndCloseFile() {
  UnlockFile(fileHandle, 0, 0, sizeof(FileData), 0);
  CloseHandle(fileHandle);
}
