#ifndef UTILS_HPP_
#define UTILS_HPP_

bool isKeyword(const std::string &input);
std::string str_transform(const std::string &str, int (*transform_func)(int v));

#endif /* !UTILS_HPP_ */
