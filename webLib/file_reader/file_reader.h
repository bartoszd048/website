#pragma once
#include "webLib/helpers/defines.h"

class FileReader {
public:
  virtual ~FileReader() { unlockAndCloseFile(); }
  virtual void openAndLockFile(std::string filename);
  virtual void readFromFile(FileData &fileData);
  virtual void unlockAndCloseFile();

protected:
  void *fileHandle = nullptr;
};
