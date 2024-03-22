#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>

class Weapon {
 public:
  explicit Weapon(const std::string& type);

  const std::string& getType(void) const;
  void setType(const std::string& type);

 private:
  std::string type_;
};

#endif
