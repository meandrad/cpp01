/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 23:40:04 by meandrad          #+#    #+#             */
/*   Updated: 2025/10/22 21:52:01 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook{
	private:
		static const int MAX_CONTACTS = 8;
		Contact	contacts[MAX_CONTACTS];
		int	totalContacts;
		int	currentIndex;

		void displayHeader() const;
		std::string truncate(const std::string &s) const;

	public:
		PhoneBook();
		
		void addContact(const Contact &newContact);
		void searchContact() const;
		void displayList() const;
		void displayContact(int index) const;

};

#endif