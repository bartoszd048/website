#pragma once
#include "webLib/helpers/defines.h"

class FileReader {
public:
  ~FileReader() { closeAndUnlockFile(); }
  void openAndLockFile(std::string filename);
  void readFromFile(FileData &fileData);
  void closeAndUnlockFile();
  void *fileHandle = nullptr;
};
