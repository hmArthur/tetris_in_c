
````markdown
# Tetris C - Raylib

A **Tetris** game written in **C** using [Raylib](https://www.raylib.com/) with support for **Linux**, **Windows**, and **Web (WASM)**.

---

## Prerequisites

### Linux
- GCC or Clang
- [Raylib](https://github.com/raysan5/raylib) compiled for desktop
- [Emscripten](https://emscripten.org/) (for Web builds)

```bash
# Install dependencies on Ubuntu/Debian
sudo apt install build-essential cmake python3
````

### Windows

* MinGW (to compile C on Windows) **or** Visual Studio
* Raylib precompiled for Windows
* Emscripten (optional, for Web builds)

---

## Running on Linux

```bash
# Compile
gcc *.c -o tetris_c -Wall -std=c99 -lraylib -lm

# Run
./tetris_c
```

---

## Running on Windows

With **MinGW**:

```powershell
gcc *.c -o tetris_c.exe -Wall -std=c99 -I path\to\raylib\include -L path\to\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm
.\tetris_c.exe
```

## Running in the Browser (WebAssembly)

### 1. Compile Raylib for Web

```bash
cd path/to/raylib/src
make clean
emmake make PLATFORM=PLATFORM_WEB
```

### 2. Compile the game for Web

```bash
emcc -o tetris_c.html *.c \
  -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os \
  -I. \
  -I ~/raylib/src \
  -I ~/raylib/src/external \
  -L. \
  -L ~/raylib/src \
  -s USE_GLFW=3 \
  -s ASYNCIFY \
  -s TOTAL_MEMORY=67108864 \
  -s FORCE_FILESYSTEM=1 \
  --shell-file ~/raylib/src/shell.html \
  ~/raylib/src/web/libraylib.a \
  -DPLATFORM_WEB \
  -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]' \
  -s EXPORTED_RUNTIME_METHODS=ccall \
  -s MINIFY_HTML=0
```

### 3. Run locally

With **Python 3**:

```bash
python3 -m http.server 8080
```

Then open in your browser:

```
http://localhost:8080/tetris_c.html
```

