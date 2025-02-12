#include <iostream>
#include "../include/utils.h"

int main() {
    fs::path directory = "Lab_Filesystem"; 

    fs::path dataFile = "file_data.txt";  

    try {
        std::cout << "Обход директории и создание карты файлов...\n";
        std::map<std::string, uintmax_t> fileMap = buildFileMap(directory);

        std::cout << "Сохранение данных в файл...\n";
        saveMapToFile(fileMap, dataFile);

        std::cout << "Загрузка данных из файла...\n";
        std::map<std::string, uintmax_t> loadedMap = loadMapFromFile(dataFile);

        std::string searchName;
        std::cout << "Введите имя файла для поиска: ";
        std::cin >> searchName;
        searchFile(loadedMap, searchName);

    } catch (const fs::filesystem_error& e) {
        std::cerr << "Ошибка работы с файловой системой: " << e.what() << '\n';
    }

    return 0;
}