#include "unit_tests/mocks/mock_files_manager.h"
#include "webLib/base_class/base_class.h"

TEST(BaseClassTest, initialize) {
  NiceMock<MockFilesManager> *filesMngr = new NiceMock<MockFilesManager>();

  EXPECT_CALL(*filesMngr, readFromFile()).Times(1);

  BaseClass *baseClass = new BaseClass(filesMngr);

  EXPECT_CALL(*filesMngr, writeToFile(filesMngr->mockStringData)).Times(1);
  delete baseClass;
}

TEST(BaseClassTest, getParams) {
  NiceMock<MockFilesManager> *filesMngr = new NiceMock<MockFilesManager>();
  BaseClass baseClass(filesMngr);

  auto expectedFD = &filesMngr->mockExpectedFileData;

  auto compareVec = [&](ParamVec v, std::string name, std::string value) {
    EXPECT_EQ(2, v.size());
    auto pair = std::pair<std::string, std::string>("name", name);
    EXPECT_TRUE(pair == v.at(0));
    pair = std::pair<std::string, std::string>("value", value);
    EXPECT_TRUE(pair == v.at(1));
  };

  compareVec(baseClass.getWalletParams(), "wallet",
             std::to_string(expectedFD->wallet));

  compareVec(baseClass.getSalaryParams(), "salary",
             std::to_string(expectedFD->salary));

  for (size_t i = 0; i < expectedFD->expenses.size(); i++) {
    compareVec(baseClass.getExpenseNameParams(i),
               "expenseName" + std::to_string(i),
               expectedFD->expenses.at(i).name);

    compareVec(baseClass.getExpenseValueParams(i),
               "expenseValue" + std::to_string(i),
               std::to_string(expectedFD->expenses.at(i).value));

    compareVec(baseClass.getExpenseDoneParams(i),
               "expenseDone" + std::to_string(i),
               std::to_string(expectedFD->expenses.at(i).done));
  }
}
