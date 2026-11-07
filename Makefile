NAME        = HumanGL
CC          = clang++
# CFLAGS      = -Wall -Wextra -Werror -std=c++17
CFLAGS      = -Wall -Wextra -std=c++17
IFLAGS      = -Iinclude -Iinclude/Members

SRC_DIR     = src
OBJ_DIR     = .obj

SRC         = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp)
OBJ         = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
CMD         = $(OBJ:%.o=%.o.json)

LIBS        = -lglfw -lGL -lGLEW


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) -o $(NAME) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -MJ $@.json -o $@ -c $<

$(OBJ_DIR)/Members%.o: $(SRC_DIR)/Members%.cpp
	@mkdir -p $(OBJ_DIR)/Members
	$(CC) $(CFLAGS) $(IFLAGS) -MJ $@.json -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run format

run: $(NAME)
	./$(NAME)

format:
	clang-format -i $(SRC)

db: $(OBJ)
	sed -e '1s/^/[\'$$'\n''/' -e '$$s/,$$/\'$$'\n'']/' $(CMD) > compile_commands.json
