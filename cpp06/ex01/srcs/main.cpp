/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:43 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/03 19:24:48 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data ogData = {24, "Lydidou", "Sevran"};
    
    std::cout << YELLOW << "Original Data :\n" << RESET;
    std::cout << "name: " << ogData.name << "\nage: " << ogData.age << "\ncity: " << ogData.city << std::endl;
    
    Data *ogPtr = &ogData;
    std::cout << "\nog pointeur: " << ogPtr << std::endl;
    
    std::cout << BLUE << "\nSerialising Pointer :\n" << RESET;
	uintptr_t serializing = Serializer::serialize(ogPtr);
	std::cout << serializing << std::endl;
    
    std::cout << BLUE << "\nDeserialising Pointer :\n" << RESET;
	Data *dataPtr_2 = Serializer::deserialize(serializing);
	std::cout << "deserialized : " << dataPtr_2;
    std::cout << "\nname: " << dataPtr_2->name << "\nage: " << dataPtr_2->age << "\ncity: " << dataPtr_2->city << std::endl;
}