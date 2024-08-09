/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:05:25 by amejdoub          #+#    #+#             */
/*   Updated: 2024/08/09 11:52:41 by amejdoub         ###   ########.fr       */
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
        while (1)
        {
            if (!str.empty())
                break;
            std::cout << "an entry cannot be empty !\n";
            std::cin >> str;
        }
    }
    return (str);
}
void add(PhoneBook& book)
{
    bool found = false;
    std::string first, last, number, ds, nickname;
    int i = 0;
    // first name
    std::cout << "first name :";
    std::cin >> first;
    first = not_empty(first);
    // last name
    std::cout << "last name :";
    std::cin >> last;
    last = not_empty(last);
    // nickname
    std::cout << "nickname :";
    std::cin >> nickname;
    nickname = not_empty(nickname);
    // number
    std::cout << "number :";
    std::cin >> number;
    number = not_empty(number);
    // darkest secret
    std::cout << "darkest secret :\n";
    std::cin >> ds;
    ds = not_empty(ds);
    for (i = 0; i < 8; i++)
    {
        if (book.contacts[i].first_name.empty())
        {
            found = true;
            book.contacts[i].first_name = first;
            book.contacts[i].last_name = last;
            book.contacts[i].darkest_secret = ds;
            book.contacts[i].nickname = nickname;
            book.contacts[i].phone_number = number;
            break;
        }
    }
    if (!found)
    {
        int index = 0;
        long min = 0;
        for (i = 0; i < 8; i++)
        {
            if (i == 0 || book.contacts[i].time_stamp < min)
            {
                min = book.contacts[i].time_stamp;
                index = i;
            }
        }
        // std::cout << "the last one is " << book.contacts[i].first_name << "\n";
        book.contacts[index].first_name = first;
        book.contacts[index].last_name = last;
        book.contacts[index].darkest_secret = ds;
        book.contacts[index].nickname = nickname;
        book.contacts[index].phone_number = number;
    }
}

int main()
{
    std::string command;
    std::string hello = "hello";
    PhoneBook book;
    while (1)
    {
    std::cout << "Commands :";
    std::cin >> command;
    if (command.empty())
        return (0);
    if (command == "ADD")
    {
        add(book);
    }
    if (command == "EXIT")
        exit (0);
    for (int i = 0; i < 8; i++) {
        if (!book.contacts[i].first_name.empty()) {
            std::cout << "--" << book.contacts[i].first_name << "--\n";
        }
    }
    }
}