/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:05:39 by amejdoub          #+#    #+#             */
/*   Updated: 2024/08/09 11:59:34 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_H
#define PHONE_H
#include <string>
#include <sys/time.h>  
#include <iostream>
class Contact
{
    public :
        Contact();
        std::string phone_number;
        std::string first_name;
        std::string last_name;
        std::string darkest_secret;
        std::string nickname;
        long long time_stamp;
};


class PhoneBook
{
    public :
        void Add();
        PhoneBook();
        Contact contacts[8];
};

#endif