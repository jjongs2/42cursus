#include "MateriaSource.hpp"

#include <cstring>

MateriaSource::MateriaSource() {
  std::memset(this->materias_, 0, sizeof(this->materias_));
}

MateriaSource::MateriaSource(const MateriaSource& origin) { *this = origin; }

MateriaSource& MateriaSource::operator=(const MateriaSource& origin) {
  for (int i = 0; i < kNumOfMaterias; ++i) {
    this->materias_[i] = origin.getMateria(i);
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < kNumOfMaterias; ++i) {
    if (this->materias_[i]) {
      delete this->materias_[i];
      this->materias_[i] = NULL;
    }
  }
}

AMateria* MateriaSource::getMateria(const int index) const {
  if (index < 0 || index >= kNumOfMaterias) {
    return NULL;
  }
  return this->materias_[index];
}

void MateriaSource::setMateria(const int index, AMateria* materia) {
  if (index < 0 || index >= kNumOfMaterias) return;
  this->materias_[index] = materia;
}

void MateriaSource::learnMateria(AMateria* materia) {
  for (int i = 0; i < kNumOfMaterias; ++i) {
    if (!this->materias_[i]) {
      this->materias_[i] = materia;
      return;
    }
  }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (int i = 0; i < kNumOfMaterias; ++i) {
    if (this->materias_[i] && this->materias_[i]->getType() == type) {
      return this->materias_[i]->clone();
    }
  }
  return NULL;
}
