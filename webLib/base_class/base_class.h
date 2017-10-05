#pragma once
#include "webLib/files_manager/files_manager.h"
#include "webLib/helpers/defines.h"

class BaseClass {
public:
  BaseClass(FilesManager *filesManager);
  BaseClass() : BaseClass(new FilesManager()){};
  ~BaseClass() { filesManager->updateFile("data", fileData); }
  uint32_t getWallet() { return fileData.wallet; }

protected:
  FileData fileData = {};
  std::unique_ptr<FilesManager> filesManager;
};
