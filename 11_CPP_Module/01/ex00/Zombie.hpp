#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  explicit Zombie(const std::string& name);
  virtual ~Zombie();

  void announce(void);

 private:
  std::string name_;
};

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

#endif
