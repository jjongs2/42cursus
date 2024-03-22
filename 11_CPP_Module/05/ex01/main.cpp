#include "Form.hpp"

int main(void) {
  try {
    Bureaucrat foo("Foo", 150);
    Bureaucrat bar("Bar", 1);
    Form form("1급", 1, 1);
    // Form form("특급", 0);
    std::cout << form << '\n';

    foo.signForm(form);
    std::cout << '\n' << form << '\n';

    bar.signForm(form);
    std::cout << '\n' << form;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
