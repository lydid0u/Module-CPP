/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Contact.hpp										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lboudjel <lboudjel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/16 15:30:44 by lboudjel		  #+#	#+#			 */
/*   Updated: 2024/10/16 18:03:59 by lboudjel		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
	Contact(void);
	~Contact(void);
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickname();
	std::string GetPhoneNumber();
	std::string GetDarkestSecret();
	void	SetFirstName(std::string);
	void	SetLastName(std::string);
	void	SetNickname(std::string);
	void	SetPhoneNumber(std::string);
	void	SetDarkestSecret(std::string);
	
	private:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string PhoneNumber;
	std::string	DarkestSecret;
};

#endif