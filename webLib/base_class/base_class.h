#pragma once
#include "webLib/helpers/defines.h"
#include "webLib/file_reader/file_reader.h"

class BaseClass {
public:
  BaseClass() = delete;
  BaseClass(std::string file);
  uint32_t getBalance() { return fileData.balance; }

protected:
  FileData fileData = {};
  std::unique_ptr<FileReader> fileReader;
};
