/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:29:56 by meandrad          #+#    #+#             */
/*   Updated: 2025/10/17 23:38:43 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(){
}

void Contact::setFirstName(const std::string &firstName){
	this->firstName = firstName;
}
void Contact::setLastName(const std::string &lastName){
	this->lastName = lastName;
}
void Contact::setNickname(const std::string &nickname){
	this->nickname = nickname;
}
void Contact::setPhoneNumber(const std::string &phoneNumber){
	this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string &darkestSecret){
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const{
	return(firstName);
}
std::string Contact::getLastName() const{
	return(lastName);
}
std::string Contact::getNickname() const{
	return(nickname);
}
std::string Contact::getPhoneNumber() const{
	return(phoneNumber);
}
std::string Contact::getDarkestSecret() const{
	return(darkestSecret);
}

bool Contact::check() const{
	return (!firstName.empty() && !lastName.empty() && !nickname.empty() &&
			!phoneNumber.empty() && !darkestSecret.empty());
}
