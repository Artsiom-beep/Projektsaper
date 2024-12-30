# Указываем компилятор
CC = gcc

# Флаги для компилятора
CFLAGS = -Wall -g

# Исходные файлы
SRC = proj.c sotw.c

# Название исполнимого файла
OUT = project_output

# Правила для компиляции
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

# Очистка собранных файлов
clean:
	rm -f $(OUT)
