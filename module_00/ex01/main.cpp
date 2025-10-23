/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:40:18 by meandrad          #+#    #+#             */
/*   Updated: 2025/10/22 22:55:00 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string>

std::string input(const std::string &promptInput){
	bool valid;
	
	std::string input;
	valid = false;
	while(!valid){
		std::cout << promptInput;
		std::getline(std::cin, input);
		if ((!input.empty())){
			valid = true;
		}
		else{
			std::cout << "\nError: All fields must be filled!" << std::endl;
		}
	}
	return (input);
}

int main(){
	PhoneBook	phonebook;
	Contact		newContact;
	std::string	command;

	std::cout << "This is you PhoneBook program!" << std::endl;
	std::cout << "Chose a command available: ADD, SEARCH or EXIT" << std::endl;
	while(true){
		
		std::cout << "\nSelect a command: ";
		std::getline(std::cin, command);
		if (command == "ADD"){
			newContact.setFirstName(input("\nEnter First Name: "));
			newContact.setLastName(input("Enter Last Name: "));
			newContact.setNickname(input("Enter Nickname: "));
			newContact.setPhoneNumber(input("Enter Phone Number: "));
			newContact.setDarkestSecret(input("Enter Darkest Secret: "));
			if (newContact.check()){
				phonebook.addContact(newContact);
				std::cout << "\nContact added!" << std::endl;
			}
		}
		if (command == "SEARCH"){
			phonebook.searchContact();
		}
		if (command == "EXIT"){
			std::cout << "\nExiting PhoneBook!" << std::endl;
			break ;
		}
		else{}
	}
	return (0);
}