#!/bin/bash

# Проверка наличия аргументов
if [ $# -ne 2 ]; then
    echo "Использование: $0 файл1 файл2"
    exit 1
fi

file1="$1"
file2="$2"

# Проверка существования файлов
if [ ! -f "$file1" ]; then
    echo "Файл '$file1' не существует."
    exit 1
fi

if [ ! -f "$file2" ]; then
    echo "Файл '$file2' не существует."
    exit 1
fi

# Сравнение файлов с помощью команды diff
diff "$file1" "$file2"

# Проверка кода возврата diff
if [ $? -eq 0 ]; then
    echo "Файлы идентичны."
else
    echo "Файлы различаются."
fi

