/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:05:25 by amejdoub          #+#    #+#             */
/*   Updated: 2024/08/08 15:11:26 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
PhoneBook::PhoneBook()
{
    // std::cout << "phone just created !\n";
}
Contact::Contact()
{
    // std::cout << "contact\n";
}

void add(PhoneBook& book)
{
    bool found = false;
    std::string first, last, number, ds, nickname;
    int i = 0;
    while (1)
    {
        if (i == 0)
        {
            std::cout << "first name :";
            std::cin >> first;
        }
        if (i == 1)
        {
            std::cout << "last name :";
            std::cin >> last;
        }
        if (i == 2)
        {
            std::cout << "nickname :";
            std::cin >> nickname;
        }
        if (i == 3)
        {
            std::cout << "number :";
            std::cin >> number;
        }
        if (i == 4)
        {
            std::cout << "darkest secret :\n";
            std::cin >> ds;
        }
        i++;
        if (i >= 4)
            break;
    }
    for (int i = 0; i < 8; i++)
    {
        if (book.contacts[i].first_name.empty())
        {
            // std::cout << "yes\n";
            found = true;
            book.contacts[i].first_name = first;
            // std::cout << book.contacts[i].first_name << "\n";
            book.contacts[i].last_name = last;
            book.contacts[i].darkest_secret = ds;
            book.contacts[i].nickname = nickname;
            book.contacts[i].phone_number = number;
            break;
        }
    }
    // if (!found)
    // {

    // }
}

int main()
{
    std::string command;
    std::string hello = "hello";
    PhoneBook book;
    std::cout << "Commands :";
    std::cin >> command;
    if (command == "ADD")
    {
        add(book);
    }
    for (int i = 0; i < 8; i++) {
        if (!book.contacts[i].first_name.empty()) {
            std::cout << book.contacts[i].first_name << "\n";
        }
    }
}