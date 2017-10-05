#include "unit_tests/mocks/mock_files_manager.h"

TEST(FilesManagerTest, obtainData) {
  FileData retFileData = {};
  NiceMock<MockFilesManager> filesMngr;

  InSequence is;
  EXPECT_CALL(filesMngr, openAndLockFile("data")).Times(1);
  EXPECT_CALL(filesMngr, readFromFile()).Times(1);
  EXPECT_CALL(filesMngr, unlockAndCloseFile()).Times(1);

  filesMngr.obtainData("data", retFileData);

  EXPECT_EQ(filesMngr.mockExpectedFileData.wallet, retFileData.wallet);
  EXPECT_EQ(filesMngr.mockExpectedFileData.salary, retFileData.salary);
  EXPECT_EQ(filesMngr.mockExpectedFileData.expenses.size(),
            retFileData.expenses.size());

  for (size_t i = 0; i < retFileData.expenses.size(); i++) {
    auto expectedExpense = filesMngr.mockExpectedFileData.expenses.at(i);
    auto retExpense = retFileData.expenses.at(i);
    EXPECT_TRUE(expectedExpense.name == retExpense.name);
    EXPECT_EQ(expectedExpense.value, retExpense.value);
    EXPECT_EQ(expectedExpense.done, retExpense.done);
  }
}
