#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename Iterator>
void Span::addNumberRange(Iterator begin, Iterator end) {
    if (std::distance(begin, end) + numbers.size() > max_size) {
        throw FullSpanException();
    }
    numbers.insert(numbers.end(), begin, end);
}

#endif
