#ifndef LEXICALERROREXCEPTION_HPP_
#define LEXICALERROREXCEPTION_HPP_

#include <string>
#include <exception>

class LexicalErrorException : public std::exception {
    public:
        explicit LexicalErrorException(
            const std::size_t &lineIndex,
            const std::size_t &columnIndex
        ) noexcept :
            _lineIndex(lineIndex), _columnIndex(columnIndex) {}

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

    private:
        std::size_t _lineIndex;
        std::size_t _columnIndex;
};


#endif /* !LEXICALERROREXCEPTION_HPP_ */
