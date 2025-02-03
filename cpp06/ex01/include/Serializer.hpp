/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:09:08 by lboudjel          #+#    #+#             */
/*   Updated: 2025/02/03 15:53:11 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m" 

typedef struct Data {
    int age;
    std::string name;
    std::string city;
} Data;


class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &copy);
        ~Serializer();
        
        Serializer &operator=(const Serializer &copy);

    public:

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif 