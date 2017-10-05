#pragma once
#include "webLib/helpers/defines.h"

class FilesManager {
public:
  virtual ~FilesManager() { unlockAndCloseFile(); }
  virtual void openAndLockFile(std::string filename);
  virtual void readFromFile(FileData &fileData);
  virtual void writeToFile(FileData &fileData);
  virtual void unlockAndCloseFile();

protected:
  void parseFile(std::string &str, FileData &fileData);
  std::string fileName = "";
  void *fileHandle = nullptr;
};
