#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <string>

class ClapTrap {
 public:
  ClapTrap();
  explicit ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& origin);
  ClapTrap& operator=(const ClapTrap& origin);
  ~ClapTrap();

  std::string getName(void) const;
  std::string getType(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getEnergyPoints(void) const;
  unsigned int getAttackDagmage(void) const;

  void setName(std::string& name);
  void setType(std::string& type);
  void setHitPoints(unsigned int hit_points);
  void setEnergyPoints(unsigned int energy_points);
  void setAttackDagmage(unsigned int attack_damage_);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void displayStatus(void);

 private:
  std::string name_;
  std::string type_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;
};

#endif
