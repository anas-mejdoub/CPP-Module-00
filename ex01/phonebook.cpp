/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:05:25 by amejdoub          #+#    #+#             */
/*   Updated: 2024/08/26 16:19:26 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
PhoneBook::PhoneBook()
{
    next_index = 0;
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
void print_content(std ::string str)
{
    // std::cout << "|";
                if (str.length() < 10)
                {
                    for (int x = 0; x < 13 - (int )str.length(); x++)
                        std::cout << " ";
                    std::cout << str;
                    std::cout << "|";
                }
                else
                {
                    for (int x = 0; x < 10; x++)
                    {
                        std::cout << str[x];
                    }
                    std::cout << ".  |";
                }
}
void PhoneBook::Search()
{

    std::cout << "----------------------------------------------------------------------\n";
    std::cout << "| FIRST NAME  |   LAST NAME |   NICKNAME  |    NUMBER   | DARK SECRET |\n";
    std::cout << "|_____________|_____________|_____________|_____________|_____________|\n";    
        for (int i = 0; i < 8; i++)
        {

            if (!contacts[i].darkest_secret.empty())
            {
                std::cout << "|";
                // if (contacts[i].first_name.length() < 10)
                // {
                //     for (int x = 0; x < 13 - (int )contacts[i].first_name.length(); x++)
                //         std::cout << " ";
                //     std::cout << contacts[i].first_name;
                //     std::cout << "|";
                // }
                // else
                // {
                //     for (int x = 0; x < 10; x++)
                //     {
                //         std::cout << contacts[i].first_name[x];
                //     }
                //     std::cout << ".  |";
                // }
                print_content(contacts[i].first_name);
                print_content(contacts[i].last_name);
                print_content(contacts[i].nickname);
                print_content(contacts[i].phone_number);
                print_content(contacts[i].darkest_secret);
                std::cout << "\n|_____________|_____________|_____________|_____________|_____________|\n"; 
            }
        }
}

void PhoneBook::Add()
{
    // bool found = false;
    std::string first, last, number, ds, nickname;
    // int i = 0;
    
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
    contacts[next_index].first_name = first;
    contacts[next_index].last_name = last;
    contacts[next_index].darkest_secret = ds;
    contacts[next_index].nickname = nickname;
    contacts[next_index].phone_number = number;
    if (next_index < 7)
        next_index++;
    else
        next_index = 0;
}

int main()
{
    std::string command;
    PhoneBook book;
    while (1)
    {
    std::cout << "Commands :";
    std::getline(std::cin, command);
    
    // if (std::c)
    // {
    //     std::cout << "command not found !\n";
    // }
    /*else*/ if (command == "ADD")
    {
        book.Add();
    }
    else if (command == "EXIT")
        exit (0);
    else if (command == "SEARCH")
    {
        book.Search();
    }
    else
    {
        std::cout << "command not found !\n";
    }
    // for (int i = 0; i < 8; i++) {
    //     if (!book.contacts[i].first_name.empty()) {
    //         std::cout << "--" << book.contacts[i].first_name << "--\n";
    //     }
    // }
    }
}