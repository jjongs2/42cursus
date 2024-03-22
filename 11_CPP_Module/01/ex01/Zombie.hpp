#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  Zombie();
  explicit Zombie(const std::string& name);
  virtual ~Zombie();

  void setName(const std::string& name);

  void announce(void);

 private:
  std::string name_;
};

Zombie* zombieHorde(const int N, const std::string& name);

#endif
