#ifndef LEXICALERROREXCEPTION_HPP_
#define LEXICALERROREXCEPTION_HPP_

#include <string>
#include <exception>

class LexicalErrorException : public std::exception {
    public:
        explicit LexicalErrorException(const std::string &msg) noexcept : Msg(msg) {}
        const char *what() const noexcept override {
            return Msg.data();
        }

    private:
        std::string Msg;
};


#endif /* !LEXICALERROREXCEPTION_HPP_ */
