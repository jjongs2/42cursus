#include "Bureaucrat.hpp"

int main(void) {
  try {
    // Bureaucrat low("Low", 151);
    Bureaucrat foo("Foo", 149);
    Bureaucrat bar("Bar", 2);
    // Bureaucrat high("High", 0);

    // foo.decreaseGrade();
    foo.decreaseGrade();
    std::cout << foo << '\n';

    // bar.increaseGrade();
    bar.increaseGrade();
    std::cout << bar << '\n';
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
