#pragma once
#include "webLib/files_manager/files_manager.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace ::testing;

class MockFilesManager : public FilesManager {
public:
  MockFilesManager();
  ~MockFilesManager() { unlockAndCloseFile(); };
  MOCK_METHOD1(openAndLockFile, void(std::string filename));
  MOCK_METHOD1(readFromFile, void(FileData &fileData));
  MOCK_METHOD1(writeToFile, void(FileData &fileData));
  MOCK_METHOD0(unlockAndCloseFile, void());
  FileData mockFileData = {123};
};
