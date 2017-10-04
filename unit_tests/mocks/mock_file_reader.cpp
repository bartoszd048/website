#include "unit_tests/mocks/mock_file_reader.h"

MockFileReader::MockFileReader() : FileReader() {
  ON_CALL(*this, readFromFile(_)).WillByDefault(SetArgReferee<0>(mockFileData));
}
