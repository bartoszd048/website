#include "unit_tests/mocks/mock_file_reader.h"
#include "webLib/base_class/base_class.h"

TEST(BaseClassTest, initialize) {
  NiceMock<MockFileReader> *fileReader = new NiceMock<MockFileReader>();

  EXPECT_CALL(*fileReader, openAndLockFile("data")).Times(1);
  EXPECT_CALL(*fileReader, readFromFile(_)).Times(1);

  BaseClass *baseClass = new BaseClass(fileReader);
  EXPECT_EQ(fileReader->mockFileData.balance, baseClass->getBalance());

  EXPECT_CALL(*fileReader, unlockAndCloseFile()).Times(1);
  delete baseClass;
}
