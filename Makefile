
.PHONY: default
default: build

c_source_files := $(shell find src -name *.c)
c_object_files := $(patsubst src/%.c, build/%.o, $(c_source_files))

CPLUS_INCLUDE_PATH := include

OUT_NAME := MP2IChess

$(c_object_files): build/%.o : src/%.c
	@mkdir -p $(dir $@) && \
	gcc -g -c -pthread -I $(CPLUS_INCLUDE_PATH) $(patsubst build/%.o, src/%.c, $@) -o $@

.PHONY: build
build: $(c_object_files)
	@echo "[C Files] :"
	@echo $(c_source_files)
	@echo "[C OBJ Files] :"
	@echo $(c_object_files)
	@gcc -g -o $(OUT_NAME) $(c_object_files)

CLEAN:
	@rm -rfv build/
	@mkdir build
	@echo "CLEAN"