#include "webLib/base_class/base_class.h"

BaseClass::BaseClass(FilesManager *filesManager) {
  this->filesManager.reset(filesManager);

  filesManager->obtainData("data", fileData);
}

ParamVec BaseClass::createParamVec(std::string name, std::string val) {
  return ParamVec({
      {"name", name},
      {"value", val},
  });
}
