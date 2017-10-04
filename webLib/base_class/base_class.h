#pragma once
#include "webLib/file_reader/file_reader.h"
#include "webLib/helpers/defines.h"

class BaseClass {
public:
  BaseClass(FileReader *fileReader);
  BaseClass() : BaseClass(new FileReader()){};
  ~BaseClass() { delete fileReader; }
  uint32_t getBalance() { return fileData.balance; }

protected:
  FileData fileData = {};
  FileReader *fileReader = nullptr;
};
