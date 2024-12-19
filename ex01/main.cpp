/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:19:19 by gpinilla          #+#    #+#             */
/*   Updated: 2024/12/19 17:21:42 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Añadir números extra usando iteradores
        std::vector<int> extra_numbers;
        extra_numbers.push_back(100);
        extra_numbers.push_back(200);
        extra_numbers.push_back(300);

        sp.addNumberRange(extra_numbers.begin(), extra_numbers.end());

        std::cout << "Shortest span after adding extra numbers: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span after adding extra numbers: " << sp.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
