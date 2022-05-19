#ifndef PARSEEXCEPTION_HPP
#define PARSEEXCEPTION_HPP

#include <exception>
#include <string>

class ParseException : public std::exception
{
  private:
    std::string message_;

  public:
    ParseException(std::string message) : message_(message) {}

    const char* what() const noexcept override
    {
      return message_.c_str();
    }
};

#endif //PARSEEXCEPTION_HPP
