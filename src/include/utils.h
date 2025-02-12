#pragma once

#include <filesystem>
#include <map>
#include <string>

namespace fs = std::filesystem;

std::map<std::string, uintmax_t> buildFileMap(const fs::path& dir);

void saveMapToFile(const std::map<std::string, uintmax_t>& fileMap, const fs::path& filePath);

std::map<std::string, uintmax_t> loadMapFromFile(const fs::path& filePath);

void searchFile(const std::map<std::string, uintmax_t>& fileMap, const std::string& fileName);