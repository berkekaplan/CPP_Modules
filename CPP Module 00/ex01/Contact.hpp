#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
    std::string secret_;
    std::string firstName_;
    std::string lastName_;
    std::string nickname_;
    std::string phoneNumber_;

public:
    void setSecret(const std::string str);
    void setFirstName(const std::string str);
    void setLastName(const std::string str);
    void setNickname(const std::string str);
    void setPhoneNumber(const std::string str);

    std::string getSecret(void) const;
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickname(void) const;
    std::string getPhoneNumber(void) const;
};

#endif