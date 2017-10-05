#include "webLib/files_manager/files_manager.h"

void FilesManager::obtainData(std::string file, FileData &fileData) {
  openAndLockFile(file);
  auto stringData = readFromFile();
  unlockAndCloseFile();

  parseFile(stringData, fileData);
}

void FilesManager::updateFile(std::string file, FileData &fileData) {
  auto stringData = parseToString(fileData);

  openAndLockFile(file);
  writeToFile(stringData);
  unlockAndCloseFile();
}

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

  for (int i = 0; i < numExp; i++) {
    fileData.expenses.push_back({
        findSubstr("expName:"),
        !!std::stoi(findSubstr("expDone:")),
        static_cast<uint32_t>(std::stoi(findSubstr("expValue:"))),
    });
  }
}

std::string FilesManager::parseToString(FileData &fileData) {
  std::string retString = "wallet:" + std::to_string(fileData.wallet) + "\r\n" +
                          "salary:" + std::to_string(fileData.salary) + "\r\n" +
                          "numExp:" + std::to_string(fileData.expenses.size()) +
                          "\r\n";

  for (size_t i = 0; i < fileData.expenses.size(); i++) {
    auto exp = &fileData.expenses.at(i);
    retString += "expName:" + exp->name + "\r\n";
    retString += "expDone:" + std::to_string(exp->done) + "\r\n";
    retString += "expValue:" + std::to_string(exp->value) + "\r\n";
  }
  return retString;
}
