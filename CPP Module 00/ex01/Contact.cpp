#include "Contact.hpp"

void Contact::setSecret(const std::string str) { secret_ = str; }
void Contact::setFirstName(const std::string str) { firstName_ = str; }
void Contact::setLastName(const std::string str) { lastName_ = str; }
void Contact::setNickname(const std::string str) { nickname_ = str; }
void Contact::setPhoneNumber(const std::string str) { phoneNumber_ = str; }

std::string Contact::getSecret(void) const { return (secret_); }
std::string Contact::getFirstName(void) const { return (firstName_); }
std::string Contact::getLastName(void) const { return (lastName_); }
std::string Contact::getNickname(void) const { return (nickname_); }
std::string Contact::getPhoneNumber(void) const { return (phoneNumber_); }
