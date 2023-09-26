/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:54:47 by syluiset          #+#    #+#             */
/*   Updated: 2023/09/26 12:03:02 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    std::cout << "HumanB construct\n";
	return ;
}

HumanB::~HumanB( void)
{
    std::cout << "HumanB destroyed\n";
	return ;
}

void HumanB::attack( void ) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
    this->_weapon = &weapon;
	return ;
}

Weapon HumanB::getWeapon( void )
{
	return (*(this->_weapon));
}


The error message you provided indicates a heap-use-after-free error detected by the AddressSanitizer. This error occurs when you try to access memory that has already been deallocated. The AddressSanitizer provides detailed information about the error, including the stack trace and the locations where the memory was allocated and freed.

Here are some key points to understand from the error message:

The error occurred in the Weapon::getType() function at line 35 of Weapon.cpp.
The error was triggered by a call to memcpy in the std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>:: _M_construct function, which is part of the standard library implementation.
The memory at address 0x603000000190 was accessed, but it was already freed by a call to operator delete in the destructor of Weapon at line 27 of Weapon.cpp.
To fix this issue, you need to ensure that you are not accessing memory that has already been freed. Here are a few steps you can take:

Double-check your code to ensure that you are not attempting to access the Weapon object after it has been deleted.
Make sure that you are not copying or assigning the Weapon object without properly managing the memory.
If you are using any containers or data structures that hold pointers to Weapon objects, ensure that you remove the pointers from the container before deleting the Weapon objects.
Additionally, you can consider using smart pointers such as std::shared_ptr or std::unique_ptr to manage the lifetime of dynamically allocated objects. These smart pointers provide automatic memory management and can help prevent use-after-free errors.

Remember that the AddressSanitizer is a powerful tool for detecting memory errors, but it is not a substitute for writing correct code. It is important to carefully review your code and ensure that you are properly managing memory and object lifetimes.