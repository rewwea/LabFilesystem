#pragma once

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

// Функции для работы с файловой системой
void createDirectory(const fs::path& path);
void createFiles(const fs::path& dir);
void renameFiles(const fs::path& dir);
void copyFiles(const fs::path& source, const fs::path& destination);
void removeFiles(const fs::path& dir);
void analyzeFiles(const fs::path& dir);
void recursiveDirectoryTraversal(const fs::path& dir);