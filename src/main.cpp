#include "utils.h"

int main() {
    fs::path labDir = "Lab_Filesystem";
    fs::path backupDir = labDir / "Backup";

    // Часть 1
    createDirectory(labDir);
    createFiles(labDir);
    renameFiles(labDir);
    createDirectory(backupDir);
    copyFiles(labDir, backupDir);
    removeFiles(labDir);

    // Часть 2
    analyzeFiles(backupDir);
    recursiveDirectoryTraversal(labDir);

    return 0;
}