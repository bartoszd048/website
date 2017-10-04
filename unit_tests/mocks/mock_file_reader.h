#pragma once
#include "webLib/file_reader/file_reader.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace ::testing;

class MockFileReader : public FileReader {
public:
  MockFileReader();
  ~MockFileReader() { unlockAndCloseFile(); };
  MOCK_METHOD1(openAndLockFile, void(std::string filename));
  MOCK_METHOD1(readFromFile, void(FileData &fileData));
  MOCK_METHOD0(unlockAndCloseFile, void());
  FileData mockFileData = {123};
};
