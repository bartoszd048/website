#include "webLib/hw.h"

void hw() {
  std::cout << cgicc::HTTPHTMLHeader() << std::endl;

  std::cout << cgicc::html() << cgicc::head() << cgicc::title("Hello World")
            << cgicc::head() << std::endl;
  std::cout << cgicc::body() << std::endl;

  std::cout << cgicc::h1("Title") << std::endl;
  std::cout << "Body" << std::endl;

  std::cout << cgicc::body() << cgicc::html() << std::endl;
}
