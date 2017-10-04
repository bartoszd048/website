#include "webLib/base_class/base_class.h"

BaseClass::BaseClass(FileReader *fileReader) {
  this->fileReader.reset(fileReader);

  fileReader->openAndLockFile("data");
  fileReader->readFromFile(fileData);
}
