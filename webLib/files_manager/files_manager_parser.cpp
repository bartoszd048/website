#include "webLib/files_manager/files_manager.h"

void FilesManager::parseFile(std::string &str, FileData &fileData) {
  size_t lineStart = 0;
  size_t valueStart = 0;
  size_t valueStop = 0;

  auto findSubstr = [&](std::string substring) {
    lineStart = str.find(substring, valueStop);
    valueStart = lineStart + substring.length();
    valueStop = str.find("\r\n", valueStop) + 2;
    return str.substr(valueStart, valueStop - valueStart - 2);
  };

  fileData.wallet = std::stoi(findSubstr("wallet:"));
  fileData.salary = std::stoi(findSubstr("salary:"));
  auto numExp = std::stoi(findSubstr("numExp:"));

  Expense exp = {};
  for (int i = 0; i < numExp; i++) {
    exp.name = findSubstr("expName:");
    exp.done = !!std::stoi(findSubstr("expDone:"));
    exp.value = std::stoi(findSubstr("expValue:"));
    fileData.expenses.push_back(exp);
  }
}
