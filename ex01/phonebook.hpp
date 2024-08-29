/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:05:39 by amejdoub          #+#    #+#             */
/*   Updated: 2024/08/29 19:43:43 by amejdoub         ###   ########.fr       */
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
        std::string getNumber();
        std::string getFirstName();
        std::string getLastName();
        std::string getDarkSecret();
        std::string getNickName();
        void setNumber(std::string str);
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setDarkSecret(std::string str);
        void setNickName(std::string str);
    private :
        std::string phone_number;
        std::string first_name;
        std::string last_name;
        std::string darkest_secret;
        std::string nickname;
};


class PhoneBook
{
    private :
        int  next_index;
    public :
        // void getContact();
        // void setContact();
        int getNextIndex();
        void setNextIndex(int index);
        void Add();
        void Search();
        PhoneBook();
        // int next_index;
        Contact contacts[8];
};

#endif