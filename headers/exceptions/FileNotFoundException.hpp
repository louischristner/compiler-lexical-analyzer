#ifndef FILENOTFOUNDEXCEPTION_HPP_
#define FILENOTFOUNDEXCEPTION_HPP_

#include <string>
#include <exception>

class FileNotFoundException : public std::exception {
    public:
        explicit FileNotFoundException(const std::string &msg) noexcept : _msg(msg) {}
        const char *what() const noexcept override {
            return _msg.data();
        }

    private:
        std::string _msg;
};


#endif /* !FILENOTFOUNDEXCEPTION_HPP_ */
