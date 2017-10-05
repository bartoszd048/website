#pragma once
#include "webLib/helpers/defines.h"

class FilesManager {
public:
  virtual ~FilesManager() = default;
  void obtainData(std::string file, FileData &fileData);
  void updateFile(std::string file, FileData &fileData);

protected:
  // os specific
  virtual void openAndLockFile(std::string filename);
  virtual std::string readFromFile();
  virtual void writeToFile(std::string &data);
  virtual void unlockAndCloseFile();

  void *fileHandle = nullptr;
  void parseFile(std::string &str, FileData &fileData);
  std::string parseToString(FileData &fileData);
};
