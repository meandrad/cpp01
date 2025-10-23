/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:39:58 by meandrad          #+#    #+#             */
/*   Updated: 2025/10/22 22:57:14 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(): totalContacts(0), currentIndex(0){
}

std::string PhoneBook::truncate(const std::string &s) const{
	if (s.length() > 10)
	{
		return (s.substr(0, 9) + ".");
	}
	return (s);
}

void PhoneBook::displayHeader() const{
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

	std::cout << "|" << std::setfill('-') << std::setw(10) << "-" << "-";
	std::cout << std::setw(10) << "" << "-";
	std::cout << std::setw(10) << "" << "-";
	std::cout << std::setw(10) << "" << "|" << std::endl;

	std::cout << std::setfill(' ');
}

void PhoneBook::searchContact() const{
	if (totalContacts == 0){
		std::cout << "\nThe PhoneBook is empty." << std::endl;
		return ;
	}
	displayList();
	int input;
	std::cout << "\nEnter a contact index for details: ";
	std::cin >> input;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "\nInvalid input. Please, enter a number" << std::endl;
		return ;
	}
	std::cin.ignore(10000, '\n');
	displayContact(input);
}

void PhoneBook::displayContact(int input) const{
	if (input < 0 || input >= totalContacts){
		std::cout << "Invalid index." << std::endl;
	}
	else{
		std::cout << "First Name: " << contacts[input].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[input].getLastName() << std::endl;
		std::cout << "Nickmame: " << contacts[input].getNickname() << std::endl;
		std::cout << "PhoneNumber: " << contacts[input].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[input].getDarkestSecret() << std::endl;
	}
}

void PhoneBook::displayList() const{
	displayHeader();
	for (int i = 0; i < totalContacts; i++){
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getNickname()) << "|" << std::endl;
	}
}

void PhoneBook::addContact(const Contact &newContact){
	contacts[currentIndex] = newContact;
	currentIndex = (currentIndex + 1) % MAX_CONTACTS;
	if (totalContacts < MAX_CONTACTS){
		totalContacts++;
	}
}