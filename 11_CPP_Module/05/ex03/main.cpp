#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  try {
    Intern someRandomIntern;

    // AForm* not_exist = someRandomIntern.makeForm("휴학신청서", "Kijsong");
    // std::cout << '\n' << *not_exist << '\n';

    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Gaepo-dong");
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Kijsong");
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

    std::cout << '\n' << *scf;
    std::cout << '\n' << *rrf;
    std::cout << '\n' << *ppf;

    delete scf;
    delete rrf;
    delete ppf;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
