/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:05:25 by amejdoub          #+#    #+#             */
/*   Updated: 2024/08/10 11:30:18 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
PhoneBook::PhoneBook()
{
    // std::cout << "phone just created !\n";
}
Contact::Contact()
{
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    time_stamp = tv.tv_usec;
}
std::string not_empty(std::string str)
{
    if (str.empty())
    {
        std::cout << "an entry cannot be empty !\n";
        exit (1);
    }
    return (str);
}
void PhoneBook::Add()
{
    bool found = false;
    std::string first, last, number, ds, nickname;
    int i = 0;
    // first name
    std::cout << "first name : ";
    std::getline(std::cin, first);
    first = not_empty(first);
    // last name
    std::cout << "last name : ";
    std::getline(std::cin, last);
    last = not_empty(last);
    // nickname
    std::cout << "nickname : ";
    std::getline(std::cin, nickname);
    nickname = not_empty(nickname);
    // number
    std::cout << "number : ";
    std::getline(std::cin, number);
    number = not_empty(number);
    // darkest secret
    std::cout << "darkest secret : ";
    std::getline(std::cin, ds);
    ds = not_empty(ds);
    for (i = 0; i < 8; i++)
    {
        if (contacts[i].first_name.empty())
        {
            found = true;
            contacts[i].first_name = first;
            contacts[i].last_name = last;
            contacts[i].darkest_secret = ds;
            contacts[i].nickname = nickname;
            contacts[i].phone_number = number;
            break;
        }
    }
    if (!found)
    {
        int index = 0;
        long min = 0;
        for (i = 0; i < 8; i++)
        {
            if (i == 0 || contacts[i].time_stamp < min)
            {
                min = contacts[i].time_stamp;
                index = i;
            }
        }
        // std::cout << "the last one is " << contacts[i].first_name << "\n";
        contacts[index].first_name = first;
        contacts[index].last_name = last;
        contacts[index].darkest_secret = ds;
        contacts[index].nickname = nickname;
        contacts[index].phone_number = number;
    }
}

int main()
{
    std::string command;
    PhoneBook book;
    while (1)
    {
    std::cout << "Commands :";
    std::getline(std::cin, command);
    // std::cin >> command;
    // std::cout << "command is " << command << "---\n";
    if (command.empty())
    {
        std::cout << "yes\n";
        exit (0);
    }
    if (command == "\n")
    {
        std::cout << "opop\n";
    }
    if (command == "ADD")
    {
        book.Add();
    }
    if (command == "EXIT")
        exit (0);
    else
    {
        std::cout << "command not found !\n";
    }
    for (int i = 0; i < 8; i++) {
        if (!book.contacts[i].first_name.empty()) {
            std::cout << "--" << book.contacts[i].first_name << "--\n";
        }
    }
    }
}