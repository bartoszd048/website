#include "cgicc/Cgicc.h"
#include <cgicc/HTMLClasses.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <iostream>

int main(int argc, char **argv, char **envp) {
  std::cout << cgicc::HTTPHTMLHeader() << std::endl;

  std::cout << cgicc::html() << cgicc::head() << cgicc::title("Hello World")
            << cgicc::head() << std::endl;
  std::cout << cgicc::body() << std::endl;

  std::cout << cgicc::h1("Title") << std::endl;
  std::cout << "Body" << std::endl;

  std::cout << cgicc::body() << cgicc::html() << std::endl;
}
