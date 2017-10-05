#include "webLib/base_class/base_class.h"
#include <cgicc/Cgicc.h>
#include <cgicc/HTMLClasses.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <iostream>

using namespace std;
using namespace cgicc;

int main(int argc, char **argv, char **envp) {
  BaseClass baseClass;
  cout << HTTPHTMLHeader() << endl; // Content-type: text/html

  cout << html() << head(title("Title")) << endl;
  cout << body() << endl;

  cout << "Wallet: " << baseClass.getWallet() << endl;

  cout << body() << html() << endl;
}
