# Compiler và cờ biên dịch
CC = g++
CFLAGS = -Wall -g -I./header

# Thư mục chứa tệp nguồn, tệp đối tượng và tệp thực thi
SRC_DIR = ./source
OUT_DIR = ./out

# Tệp nguồn và tệp đối tượng
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Document.cpp $(SRC_DIR)/Book.cpp $(SRC_DIR)/Journal.cpp $(SRC_DIR)/Newspaper.cpp $(SRC_DIR)/ManagerDocument.cpp
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OUT_DIR)/%.o,$(SOURCES))

# Tên tệp thực thi
TARGET = $(OUT_DIR)/main.exe

# Quy tắc mặc định
all: $(OUT_DIR) $(TARGET)

# Tạo thư mục out nếu chưa tồn tại
$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# Quy tắc tạo tệp thực thi
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Quy tắc tạo tệp đối tượng từ tệp nguồn .cpp
$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Quy tắc dọn dẹp
clean:
	rm -rf $(OUT_DIR)
