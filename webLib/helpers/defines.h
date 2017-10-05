#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

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
