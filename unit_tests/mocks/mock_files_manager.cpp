#include "unit_tests/mocks/mock_files_manager.h"

MockFilesManager::MockFilesManager() : FilesManager() {
  mockFileData.wallet = 123;

  ON_CALL(*this, readFromFile(_)).WillByDefault(SetArgReferee<0>(mockFileData));
}
