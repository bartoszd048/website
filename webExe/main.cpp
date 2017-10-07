#include "webLib/base_class/base_class.h"
#include <cgicc/Cgicc.h>
#include <cgicc/HTMLClasses.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <iostream>

using namespace std;
using namespace cgicc;

template <typename T> T obj(ParamVec v) {
  HTMLAttributeList attr;
  for (auto e : v) {
    attr.set(e.first, e.second);
  }
  return T(attr);
}

template <typename T> void out(T t) { cout << t << endl; }

template <typename T> void out(T t, string param, string value) {
  t.set(param, value);
  out(t);
}

int main(int argc, char **argv, char **envp) {
  BaseClass baseClass;

  out(HTTPHTMLHeader());
  out(html());
  out(head(title("Title")));
  out(body());

  out(form(), "method", "post");
  out(table());

  out(tr());
  out(td("Wallet"));
  out(td(obj<input>(baseClass.getWalletParams())));
  out(tr());

  out(tr());
  out(td("Salary"));
  out(td(obj<input>(baseClass.getSalaryParams())));
  out(tr());

  for (size_t i = 0; i < baseClass.getNumExpenses(); i++) {
    out(tr());
    out(td("Expense " + std::to_string(i)));
    out(td(obj<input>(baseClass.getExpenseNameParams(i))));
    out(td(obj<input>(baseClass.getExpenseValueParams(i))));
    out(td(obj<input>(baseClass.getExpenseDoneParams(i))));
    out(tr());
  }

  out(table());

  out(obj<button>({{"type", "submit"}}));
  out("Submit");
  out(button());

  out(form());

  out(body());
  out(html());
}
