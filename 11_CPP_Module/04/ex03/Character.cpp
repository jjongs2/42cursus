#include "Character.hpp"

#include <cstring>

Character::Character() : name_(kUndefined) {
  std::memset(this->materias_, 0, sizeof(this->materias_));
}

Character::Character(const std::string& name) : name_(name) {
  std::memset(this->materias_, 0, sizeof(this->materias_));
}

Character::Character(const Character& origin) { *this = origin; }

Character& Character::operator=(const Character& origin) {
  if (this != &origin) {
    this->name_ = origin.getName();
    for (int i = 0; i < kNumOfMaterias; ++i) {
      this->materias_[i] = origin.getMateria(i);
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < kNumOfMaterias; ++i) {
    if (this->materias_[i]) {
      delete this->materias_[i];
      this->materias_[i] = NULL;
    }
  }
}

const std::string& Character::getName(void) const { return this->name_; }

AMateria* Character::getMateria(const int index) const {
  if (index < 0 || index >= kNumOfMaterias) {
    return NULL;
  }
  return this->materias_[index];
}

void Character::setName(const std::string& name) { this->name_ = name; }

void Character::setMateria(const int index, AMateria* materia) {
  if (index < 0 || index >= kNumOfMaterias) return;
  this->materias_[index] = materia;
}

void Character::equip(AMateria* materia) {
  for (int i = 0; i < kNumOfMaterias; ++i) {
    if (!this->materias_[i]) {
      this->materias_[i] = materia;
      return;
    }
  }
}

void Character::unequip(int index) {
  if (index < 0 || index >= kNumOfMaterias) return;
  this->materias_[index] = NULL;
}

void Character::use(int index, ICharacter& target) {
  if (index < 0 || index >= kNumOfMaterias || !this->materias_[index]) return;
  this->materias_[index]->use(target);
}
