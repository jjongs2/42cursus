#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include "ICharacter.hpp"

class AMateria {
 public:
  virtual AMateria* clone(void) const = 0;

  AMateria();
  explicit AMateria(const std::string& type);
  AMateria(const AMateria& origin);
  AMateria& operator=(const AMateria& origin);
  virtual ~AMateria();

  const std::string& getType(void) const;
  void setType(const std::string& type);

  virtual void use(ICharacter& target) = 0;

 protected:
  std::string type_;
};

#endif
