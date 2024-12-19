/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:54:34 by gpinilla          #+#    #+#             */
/*   Updated: 2024/12/19 16:56:30 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    try {
        // Prueba con std::vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::vector<int>::iterator vecIt = easyfind(vec, 3);
        std::cout << "Found in vector: " << *vecIt << std::endl;

        // Prueba con std::list
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        std::list<int>::iterator lstIt = easyfind(lst, 40);
        std::cout << "Found in list: " << *lstIt << std::endl;

        // Caso no encontrado
        std::cout << "Trying to find 99 in vector..." << std::endl;
        easyfind(vec, 99); // Lanzará una excepción
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

