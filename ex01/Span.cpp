/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:16:00 by gpinilla          #+#    #+#             */
/*   Updated: 2024/12/19 17:18:25 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : max_size(N) {}

// Destructor
Span::~Span() {}

// Constructor de copia
Span::Span(const Span& other) : max_size(other.max_size), numbers(other.numbers) {}

// Operador de asignación
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        max_size = other.max_size;
        numbers = other.numbers;
    }
    return *this;
}

// Añadir un número
void Span::addNumber(int number) {
    if (numbers.size() >= max_size) {
        throw FullSpanException();
    }
    numbers.push_back(number);
}

// Encontrar la menor distancia
int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int> sorted_numbers = numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted_numbers.size(); ++i) {
        int diff = sorted_numbers[i] - sorted_numbers[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

// Encontrar la mayor distancia
int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw NoSpanException();
    }

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());

    return max - min;
}

// Excepción: Span lleno
const char* Span::FullSpanException::what() const throw() {
    return "Span is full, cannot add more numbers.";
}

// Excepción: No hay suficiente información para un span
const char* Span::NoSpanException::what() const throw() {
    return "Not enough numbers to calculate a span.";
}
