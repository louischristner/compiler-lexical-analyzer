#ifndef SYNTAXERROREXCEPTION_HPP_
#define SYNTAXERROREXCEPTION_HPP_

#include <string>
#include <exception>

class SyntaxErrorException : public std::exception {
    public:
        explicit SyntaxErrorException(
            const std::size_t &lineIndex,
            const std::size_t &columnIndex
        ) noexcept :
            _lineIndex(lineIndex), _columnIndex(columnIndex), _exceptionName("syntax") {}

        void setLineIndex(const std::size_t &index) noexcept {
            _lineIndex = index;
        }

        void setColumnIndex(const std::size_t &index) noexcept {
            _columnIndex = index;
        }

        std::size_t getLineIndex() const noexcept {
            return _lineIndex;
        }

        std::size_t getColumnIndex() const noexcept {
            return _columnIndex;
        }

        std::string getExceptionName() const noexcept {
            return _exceptionName;
        }

    private:
        std::size_t _lineIndex;
        std::size_t _columnIndex;
        std::string _exceptionName;
};


#endif /* !SYNTAXERROREXCEPTION_HPP_ */
