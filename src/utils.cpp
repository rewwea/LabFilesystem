#include "../include/utils.h"
#include <fstream>
#include <iostream>

std::map<std::string, uintmax_t> buildFileMap(const fs::path& dir) {
    std::map<std::string, uintmax_t> fileMap;
    for (const auto& entry : fs::recursive_directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            fileMap[entry.path().filename().string()] = fs::file_size(entry.path());
        }
    }
    return fileMap;
}

void saveMapToFile(const std::map<std::string, uintmax_t>& fileMap, const fs::path& filePath) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи: " << filePath.string() << "\n";
        return;
    }
    for (const auto& [name, size] : fileMap) {
        file << name << " " << size << "\n";
    }
    file.close();
    std::cout << "Данные успешно сохранены в файл: " << filePath.string() << "\n";
}

std::map<std::string, uintmax_t> loadMapFromFile(const fs::path& filePath) {
    std::map<std::string, uintmax_t> fileMap;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения: " << filePath.string() << "\n";
        return fileMap;
    }
    std::string name;
    uintmax_t size;
    while (file >> name >> size) {
        fileMap[name] = size;
    }
    file.close();
    std::cout << "Данные успешно загружены из файла: " << filePath.string() << "\n";
    return fileMap;
}

void searchFile(const std::map<std::string, uintmax_t>& fileMap, const std::string& fileName) {
    auto it = fileMap.find(fileName);
    if (it != fileMap.end()) {
        std::cout << "Файл '" << it->first << "' найден. Размер: " << it->second << " байт.\n";
    } else {
        std::cout << "Файл '" << fileName << "' не найден.\n";
    }
}