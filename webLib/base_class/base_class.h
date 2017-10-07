#pragma once
#include "webLib/files_manager/files_manager.h"
#include "webLib/helpers/defines.h"

class BaseClass {
public:
  BaseClass(FilesManager *filesManager);
  BaseClass() : BaseClass(new FilesManager()){};
  ~BaseClass() { filesManager->updateFile("data", fileData); }

  ParamVec getWalletParams() {
    return createParamVec("wallet", std::to_string(fileData.wallet));
  }

  ParamVec getSalaryParams() {
    return createParamVec("salary", std::to_string(fileData.salary));
  }

  ParamVec getExpenseNameParams(size_t i) {
    return createParamVec("expenseName" + std::to_string(i),
                          fileData.expenses.at(i).name);
  }
  ParamVec getExpenseValueParams(size_t i) {
    return createParamVec("expenseValue" + std::to_string(i),
                          std::to_string(fileData.expenses.at(i).value));
  }
  ParamVec getExpenseDoneParams(size_t i) {
    return createParamVec("expenseDone" + std::to_string(i),
                          std::to_string(fileData.expenses.at(i).done));
  }

  size_t getNumExpenses() { return fileData.expenses.size(); }

protected:
  ParamVec createParamVec(std::string name, std::string val);
  FileData fileData = {};
  std::unique_ptr<FilesManager> filesManager;
};
