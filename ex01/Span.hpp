/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:15:27 by gpinilla          #+#    #+#             */
/*   Updated: 2024/12/19 17:16:44 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <limits>

class Span {
private:
    unsigned int max_size;
    std::vector<int> numbers;
    Span();

public:
    // Constructor
    explicit Span(unsigned int N);

    // Destructor
    ~Span();

    // Copia
    Span(const Span& other);
    Span& operator=(const Span& other);

    // Métodos
    void addNumber(int number);
    template <typename Iterator>
    void addNumberRange(Iterator begin, Iterator end);

    int shortestSpan() const;
    int longestSpan() const;

    // Excepciones personalizadas
    class FullSpanException : public std::exception {
    public:
        const char* what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#include "Span.tpp"

#endif
