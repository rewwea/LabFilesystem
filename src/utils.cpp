#include "../src/include/utils.h"
#include <iostream>
#include <fstream>
#include <ctime>

// Создание директории
void createDirectory(const fs::path& path) {
    if (!fs::exists(path)) {
        fs::create_directory(path);
        std::cout << "Директория '" << path.string() << "' создана.\n";
    } else {
        std::cout << "Директория '" << path.string() << "' уже существует.\n";
    }
}

// Создание файлов
void createFiles(const fs::path& dir) {
    for (int i = 1; i <= 5; ++i) {
        fs::path filePath = dir / ("file" + std::to_string(i) + ".txt");
        std::ofstream file(filePath);
        file << "Содержимое файла file" << i << ".txt\n";
        file.close();
        std::cout << "Файл '" << filePath.filename().string() << "' создан.\n";
    }
}

// Переименование файлов
void renameFiles(const fs::path& dir) {
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            fs::path oldPath = entry.path();
            fs::path newPath = oldPath.parent_path() / ("renamed_" + oldPath.filename().string());
            fs::rename(oldPath, newPath);
            std::cout << "Файл переименован: '" << oldPath.filename().string() << "' -> '" << newPath.filename().string() << "'\n";
        }
    }
}

// Копирование файлов
void copyFiles(const fs::path& source, const fs::path& destination) {
    for (const auto& entry : fs::directory_iterator(source)) {
        if (entry.is_regular_file()) {
            fs::path srcPath = entry.path();
            fs::path destPath = destination / srcPath.filename();
            fs::copy_file(srcPath, destPath, fs::copy_options::overwrite_existing);
            std::cout << "Файл скопирован: '" << srcPath.filename().string() << "' -> '" << destPath.filename().string() << "'\n";
        }
    }
}

// Удаление файлов
void removeFiles(const fs::path& dir) {
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            fs::remove(entry.path());
            std::cout << "Файл удален: '" << entry.path().filename().string() << "'\n";
        }
    }
}

// Анализ файлов
void analyzeFiles(const fs::path& dir) {
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            fs::path filePath = entry.path();
            std::cout << "Имя файла: " << filePath.filename().string() << "\n";
            std::cout << "Размер файла: " << fs::file_size(filePath) << " байт\n";
            std::time_t lastWriteTime = fs::last_write_time(filePath).time_since_epoch().count();
            std::cout << "Дата последнего изменения: " << std::ctime(&lastWriteTime);
        }
    }
}

// Рекурсивный обход директории
void recursiveDirectoryTraversal(const fs::path& dir) {
    for (const auto& entry : fs::recursive_directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            std::cout << "Файл: " << entry.path().string() << "\n";
        } else if (entry.is_directory()) {
            std::cout << "Директория: " << entry.path().string() << "\n";
        }
    }
}