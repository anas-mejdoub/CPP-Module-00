/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:05:25 by amejdoub          #+#    #+#             */
/*   Updated: 2024/08/31 11:51:08 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int PhoneBook::getNextIndex()
{
    return next_index;
}

void PhoneBook::setNextIndex(int index)
{
    next_index = index;
}

PhoneBook::PhoneBook()
{
    next_index = 0;
    // std::cout << "phone just created !\n";
}

Contact::Contact()
{
    
}

std::string Contact::getNumber()
{
    return phone_number;
}
std::string Contact::getFirstName()
{
    return first_name;
}
std::string Contact::getLastName()
{
    return last_name;
}
std::string Contact::getDarkSecret()
{
    return darkest_secret;
}
std::string Contact::getNickName()
{
    return nickname;
}

void Contact::setFirstName(std::string str)
{
    first_name = str;
}
void Contact::setLastName(std::string str)
{
    last_name = str;
}
void Contact::setDarkSecret(std::string str)
{
    darkest_secret = str;
}
void Contact::setNickName(std::string str)
{
    nickname = str;
}
void Contact::setNumber(std::string str)
{
    phone_number = str;
}
int space_str(std::string str)
{
    size_t i;
    for ( i = 0; i < str.length(); i++)
    {
        if ((str[i] != ' ' && str[i] != '\t'))
            return 0;
        if (i == 9)
            return 1;
    }
    return i == str.length() ? 1 : 0;
}
std::string not_empty(std::string str)
{
    if (str.empty() || space_str(str))
    {
        while (1)
        {
            std::cout << "\nan entry cannot be empty !\n:";
            std::getline(std::cin, str);
            if (std::cin.eof())
                exit(1); ;
            if (!str.empty())
                break ;
            
        }
    }
    return (str);
}
void print_content(std ::string str)
{
                if (str.length() <= 10)
                {
                    // std::cout << "<<<" << str <<">>>";
                    for (int x = 0; x < 13 - (int )str.length(); x++)
                        std::cout << " ";
                    std::cout << str;
                    std::cout << "|";
                }
                else
                {
                    std::cout << "  ";
                    for (int x = 0; x < 10; x++)
                    {
                        std::cout << str[x];
                    }
                    std::cout << ".|";
                }
}
int checkDigit(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return 1;
    }
    return 0;
}
std::string numberNotEmpty(std::string str)
{
    if (str.empty() || space_str(str) || checkDigit(str))
    {
        while (1)
        {
            std::cout << "\nwrong try again !\n:";
            std::getline(std::cin, str);
            if (std::cin.eof())
                exit(1); ;
            if (!str.empty() && !space_str(str) && !checkDigit(str))
                break ;
            
        }
    }
    return (str);
}
void PhoneBook::Search()
{

    std::cout << "---------------------------------------------------------\n";
    std::cout << "|     INDEX   |  FIRST NAME |   LAST NAME |  NICKNAME   |\n";
    std::cout << "|_____________|_____________|_____________|_____________|\n";    
        for (int i = 0; i < 8; i++)
        {

            if (!contacts[i].getFirstName().empty())
            {
                std::cout << "|";
                for (int x = 0; x < 12 ; x++)
                        std::cout << " ";
                    std::cout << i + 1;
                    std::cout << "|";
                print_content(contacts[i].getFirstName());
                print_content(contacts[i].getLastName());
                print_content(contacts[i].getNickName());
    std::cout << "\n|_____________|_____________|_____________|_____________|\n"; 
            }
        }
    if (contacts[0].getFirstName().empty())
    {
        std::cout << "your contacts book is empty !\n";
        return ;
    }
    std::string number;
    // int number;
    std::cout << "enter the index of a contacts : ";
    // std::cin >> number;
    std::getline(std::cin, number);
    number = numberNotEmpty(number);
    if (number.length() > 1 || number[0] < '1' || number[0] > getNextIndex() + '0')
        std::cout << "the number is not in range !\n";
    else
    {
        std::cout << "first name : " << contacts[(number[0] - '0') - 1].getFirstName() << "\n";
        std::cout << "lastt name : " << contacts[(number[0] - '0') - 1].getLastName() << "\n";
        std::cout << "nickname : " << contacts[(number[0] - '0') - 1].getNickName() << "\n";
        std::cout << "phone number : " << contacts[(number[0] - '0') - 1].getNumber() << "\n";
        std::cout << "darkest secret : " << contacts[(number[0] - '0') - 1].getDarkSecret() << "\n";
    }
}
int strnumber(std::string str)
{
    if (str.length() < 10)
        return 0;
    
    for (int i = 0;i < (int)str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '+')
            return 0;
        if (str[i] == '+' && i)
            return 0;
    }
    return 1;
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
    while (1)
    {
        if (!number.empty() && strnumber(number))
            break ;
        std::cout << "wrong number !\nnumber : ";
        std::getline(std::cin, number);
        number = not_empty(number);
}   

    // darkest secret
    std::cout << "darkest secret : ";
    std::getline(std::cin, ds);
    ds = not_empty(ds);
    contacts[getNextIndex()].setFirstName(first);
    contacts[getNextIndex()].setLastName(last);
    contacts[getNextIndex()].setDarkSecret(ds);
    contacts[getNextIndex()].setNickName(nickname);
    contacts[getNextIndex()].setNumber(number);
    if (getNextIndex() < 7)
        setNextIndex(getNextIndex());
    else
        setNextIndex(0);
}

int main()
{
    std::string command;
    PhoneBook book;
    while (1)
    {
        std::cout << "available commands : (ADD, SEARCH, EXIT)\n";
        std::cout << "enter a command :";
        std::getline(std::cin, command);
        
        if (std::cin.eof())
            break ;
        if (command == "ADD" || command == "add")
        {
            book.Add();
        }
        else if (command == "EXIT" || command == "exit")
            exit (0);
        else if (command == "SEARCH" || command == "search")
        {
            book.Search();
        }
        else
        {
            std::cout << "command not found !\n";
        }
    }
}