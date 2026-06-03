#ifndef COLORS_H
#define COLORS_H

#include <string_view>

namespace Colors {
inline constexpr std::string_view green = "\x1b[32m";
inline constexpr std::string_view red = "\x1b[31;1m";
inline constexpr std::string_view blue = "\x1b[34m";
inline constexpr std::string_view yellow = "\x1b[0;33m";
inline constexpr std::string_view reset = "\x1b[0m";
} // namespace Colors

#endif
