#ifndef LEXICALERROREXCEPTION_HPP_
#define LEXICALERROREXCEPTION_HPP_

#include <string>
#include <exception>

class LexicalErrorException : public std::exception {
    public:
        explicit LexicalErrorException(
            const std::size_t &lineIndex,
            const std::size_t charIndex
        ) noexcept :
            _lineIndex(lineIndex), _charIndex(charIndex) {}

        void setLineIndex(const std::size_t &index) noexcept {
            _lineIndex = index;
        }

        void setCharIndex(const std::size_t &index) noexcept {
            _charIndex = index;
        }

        const char *what() const noexcept override {
            return (
                std::string("Lexical analysis error found at line ") +
                std::to_string(_lineIndex) + " column " + std::to_string(_charIndex)
            ).c_str();
        }

    private:
        std::size_t _lineIndex = 0;
        std::size_t _charIndex = 0;
};


#endif /* !LEXICALERROREXCEPTION_HPP_ */
