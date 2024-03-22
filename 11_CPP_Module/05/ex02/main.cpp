#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  try {
    Bureaucrat foo("Foo", 150);
    Bureaucrat bar("Bar", 1);
    ShrubberyCreationForm sc("Gaepo-dong");
    RobotomyRequestForm rr("Kijsong");
    PresidentialPardonForm pp("Bender");

    std::cout << sc << '\n';
    std::cout << rr << '\n';
    std::cout << pp << '\n';

    foo.signForm(sc);
    bar.executeForm(sc);
    std::cout << '\n';

    bar.signForm(sc);
    bar.signForm(rr);
    bar.signForm(pp);
    std::cout << '\n';

    std::cout << "[ ShrubberyCreationForm ]\n";
    bar.executeForm(sc);

    std::cout << "\n[ RobotomyRequestForm ]\n";
    bar.executeForm(rr);

    std::cout << "\n[ PresidentialPardonForm ]\n";
    bar.executeForm(pp);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
