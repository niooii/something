//
// Created by beyon on 3/10/2024.
//

#ifndef UTILS_H
#define UTILS_H

#include <string_view>
#include <vector>
#include <fstream>
#include <spdlog/spdlog.h>

class Utils {
    std::vector<char> ReadFile(const std::string_view& filename);
};



#endif //UTILS_H
