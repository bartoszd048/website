#include "unit_tests/mocks/mock_files_manager.h"
#include "webLib/base_class/base_class.h"

TEST(BaseClassTest, initialize) {
  NiceMock<MockFilesManager> *filesMngr = new NiceMock<MockFilesManager>();
  InSequence is;

  EXPECT_CALL(*filesMngr, openAndLockFile("data")).Times(1);
  EXPECT_CALL(*filesMngr, readFromFile(_)).Times(1);

  BaseClass *baseClass = new BaseClass(filesMngr);
  EXPECT_EQ(filesMngr->mockFileData.balance, baseClass->getBalance());

  EXPECT_CALL(*filesMngr, writeToFile(_)).Times(1);
  EXPECT_CALL(*filesMngr, unlockAndCloseFile()).Times(1);
  delete baseClass;
}
