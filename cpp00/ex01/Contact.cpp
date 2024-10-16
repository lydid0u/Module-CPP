/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Contact.cpp										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/16 15:11:30 by lboudjel		  #+#	#+#			 */
/*   Updated: 2024/10/16 18:18:23 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(){}

Contact::~Contact(){}

std::string Contact::GetFirstName(){
	return (FirstName);
}

std::string Contact::GetLastName(){
	return (LastName);
}

std::string Contact::GetNickname(){
	return (Nickname);
}

std::string Contact::GetPhoneNumber(){
	return (PhoneNumber);
}

std::string Contact::GetDarkestSecret(){
	return (DarkestSecret);
}

void	Contact::SetFirstName(std::string str){
	FirstName = str;
}

void	Contact::SetLastName(std::string str){
	LastName = str;
}

void	Contact::SetNickname(std::string str){
	Nickname = str;
}

void	Contact::SetPhoneNumber(std::string str){
	PhoneNumber = str;
}

void	Contact::SetDarkestSecret(std::string str){
	DarkestSecret = str;
}