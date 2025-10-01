//
// Created by leonw on 25.09.2025.
//

#ifndef C3PO_FILEUTIL_HPP
#define C3PO_FILEUTIL_HPP
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>


class FileUtil
{
public:
    static std::string read_file(const std::string& path) {
        std::ifstream in(path, std::ios::binary);
        if (!in) throw std::runtime_error("Failed to open file: " + path);
        return std::string(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
    }
};


#endif //C3PO_FILEUTIL_HPP