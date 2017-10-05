#include "unit_tests/mocks/mock_files_manager.h"
#include "webLib/base_class/base_class.h"

TEST(BaseClassTest, initialize) {
  NiceMock<MockFilesManager> *filesMngr = new NiceMock<MockFilesManager>();

  EXPECT_CALL(*filesMngr, readFromFile()).Times(1);

  BaseClass *baseClass = new BaseClass(filesMngr);
  EXPECT_EQ(filesMngr->mockExpectedFileData.wallet, baseClass->getWallet());

  EXPECT_CALL(*filesMngr, writeToFile(filesMngr->mockStringData)).Times(1);
  delete baseClass;
}
