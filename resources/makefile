# make file configured for EGR111 workspace
# see https://dev.to/talhabalaj/setup-visual-studio-code-for-multi-file-c-projects-1jpi
# 3/16/2025 - updated

# ******* Requirements ******
# 1. Included launch.json and tasks.json files provided
# 2. Add bin folder. Compiled binary is here as main
# 3. Only one main() function with int return
# 4. Use subdirectories as required
# 5. *** src_dir must be updated ***

src_dir = ./week09/multi_files

CC	  := gcc
C_FLAGS := -ggdb -Wextra -Wall

BIN	 := bin
SRC	 := $(src_dir)
INCLUDE := $(src_dir)

LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.c 
	$(CC) $(C_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	@if [ -d $(BIN) ]; then \
		rm -rf $(BIN)/*; \
		echo "Cleaned the bin directory"; \
	else \
		echo "Bin directory does not exist"; \
	fi

