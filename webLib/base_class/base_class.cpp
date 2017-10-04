#include "webLib/base_class/base_class.h"

BaseClass::BaseClass(std::string filename) {
  fileReader.reset(new FileReader());
  fileReader->openAndLockFile(filename);
  fileReader->readFromFile(fileData);
}
