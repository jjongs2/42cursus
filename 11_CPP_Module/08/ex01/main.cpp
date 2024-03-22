#include <ctime>
#include <iostream>

#include "Span.hpp"

int main(void) {
  try {
    Span sp = Span(5);
    Span sp2(sp);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << '\n';
    std::cout << sp.longestSpan() << '\n';
    std::cout << '\n';

    const int sp_size = sp.size();

    Span span(kSpanSize);
    span.insert(span.begin(), sp.begin(), sp.end());
    std::cout << "[ Insert ]\n";
    span.print(0, sp_size);
    for (int i = sp_size; i < kSpanSize; ++i) {
      span.addNumber(i);
    }
    std::cout << '\n';

    std::srand(std::clock());
    std::random_shuffle(span.begin(), span.end());
    std::cout << "[ Random ]\n";
    span.print(0, 10);
    std::cout << '\n';

    std::cout << "Shortest Span: " << span.shortestSpan() << '\n'
              << "Longest Span: " << span.longestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << kErrors[kPrefix] << e.what() << std::endl;
    return 1;
  }
  return 0;
}
