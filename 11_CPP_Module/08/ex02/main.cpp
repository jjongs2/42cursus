#include "MutantStack.hpp"

int main(void) {
  MutantStack<int> mstack;
  std::cout << std::boolalpha << "empty: " << mstack.empty() << '\n';

  mstack.push(5);
  mstack.push(17);
  std::cout << "top: " << mstack.top() << '\n';

  mstack.pop();
  std::cout << "size: " << mstack.size() << '\n';
  std::cout << '\n';

  mstack.push(3);
  mstack.push(2);
  mstack.push(737);
  mstack.push(42);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  std::cout << "[ mstack ]\n";
  print(it, ite);
  std::cout << '\n';

  std::stack<int> s(mstack);
  std::cout << "top: " << s.top() << '\n';
  std::cout << '\n';

  MutantStack<int>::reverse_iterator rit = mstack.rbegin();
  MutantStack<int>::reverse_iterator rite = mstack.rend();
  std::cout << "[ reverse mstack ]\n";
  print(rit, rite);
  return 0;
}
