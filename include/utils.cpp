//
// Created by beyon on 3/10/2024.
//

#include "utils.h"

std::vector<char> Utils::ReadFile(const std::string_view& filename){
    std::ifstream file(filename.data(), std::ios::ate | std::ios::binary);

    if (!file.is_open()) {
        spdlog::error("");
        exit(1);
    }

    size_t fsize = static_cast<size_t>(file.tellg());
    std::vector<char> buf(fsize);

    file.seekg(0);

    file.read(buf.data(), fsize);

    file.close();

    return buf;
}
