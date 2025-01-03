# Compiler và cờ biên dịch
CC = g++
CFLAGS = -Wall -g -I./header

# Thư mục chứa tệp nguồn, tệp đối tượng và tệp thực thi
SRC_DIR = ./source
OUT_DIR = ./out

# Tìm tất cả các tệp nguồn .cpp trong thư mục source
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Tạo danh sách tệp đối tượng từ danh sách tệp nguồn
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
