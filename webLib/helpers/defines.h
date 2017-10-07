#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

typedef std::vector<std::pair<std::string, std::string>> ParamVec;

struct Expense {
  std::string name;
  bool done;
  uint32_t value;
};

struct FileData {
  uint32_t wallet;
  uint32_t salary;
  std::vector<Expense> expenses;
};
