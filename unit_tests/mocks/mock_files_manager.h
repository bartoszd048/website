#pragma once
#include "webLib/files_manager/files_manager.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace ::testing;

class MockFilesManager : public FilesManager {
public:
  MockFilesManager();
  MOCK_METHOD1(openAndLockFile, void(std::string filename));
  MOCK_METHOD0(readFromFile, std::string());
  // MOCK_METHOD1(writeToFile, void(FileData &fileData));
  MOCK_METHOD0(unlockAndCloseFile, void());

  std::string mockStringData = "";
  FileData mockExpectedFileData = {};
};
