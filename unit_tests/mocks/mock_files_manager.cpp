#include "unit_tests/mocks/mock_files_manager.h"

MockFilesManager::MockFilesManager() : FilesManager() {
  mockStringData = "wallet:123\r\nsalary:456\r\nnumExp:3\r\n\
expName:name1\r\nexpDone:0\r\nexpValue:678\r\n\
expName:name2\r\nexpDone:1\r\nexpValue:678\r\n\
expName:name3\r\nexpDone:0\r\nexpValue:912\r\n\
";

  mockExpectedFileData.wallet = 123;
  mockExpectedFileData.salary = 456;
  mockExpectedFileData.expenses.push_back({"name1", false, 678});
  mockExpectedFileData.expenses.push_back({"name2", true, 678});
  mockExpectedFileData.expenses.push_back({"name3", false, 912});

  ON_CALL(*this, readFromFile()).WillByDefault(Return(mockStringData));
}
