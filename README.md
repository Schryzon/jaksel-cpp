# Jaksel-C++

<p align="center">
  <a href="https://repository-images.githubusercontent.com/961297003/f8a1d42f-aa97-41f2-a3b6-ac3e50134d1c">
    <img src="https://repository-images.githubusercontent.com/961297003/f8a1d42f-aa97-41f2-a3b6-ac3e50134d1c" alt="Repository Thumbnail"/>
  </a>
</p>

A creative C++ interpreter that converts "Jaksel slang" into valid C++ code. This project takes custom `.jaksel` files written in a playful, slang-inspired language and translates them into standard C++ code. It then automatically compiles and runs the generated code, allowing for a seamless and hidden-in-plain-sight coding experience.

## Features

- **Jaksel Slang Interpreter:** Translates custom slang (e.g., "which is", "spill", "begitulah") into valid C++ tokens.
- **File Conversion:** Reads from a `.jaksel` file, converts each line into C++ code, and writes the result to a standard `.cpp` file.
- **Automated Compilation:** Automatically compiles the generated C++ code using g++.
- **Creative Syntax:** Designed with fun, non-standard keywords to give a fresh twist on traditional programming.
- **Docker Support:** The project has been successfully built and tested using Docker for a reproducible build environment.

## Getting Started

### Prerequisites

- **C++ Compiler:** Make sure you have g++ installed and added to your system's PATH (if building locally).
- **Git:** For cloning the repository and version control.
- **Docker:** To build and run the interpreter in a containerized environment.
- **C++ Standard:** This project is built using C++17.

### Installation

#### Option 1: Building Locally

1. Clone the repository:
   ```bash
   git clone https://github.com/Schryzon/jaksel-cpp.git
   cd jaksel-cpp
   ```
2. Build the project by following the instructions in the usage section below.

#### Option 2: Building with Docker

1. **Install Docker:**  
   - [Docker Desktop for Windows/Mac](https://www.docker.com/products/docker-desktop)  
   - For Linux, follow your distribution’s Docker installation guide.

2. **Build the Docker Image:**
   ```bash
   docker build -t jaksel-cpp .
   ```
3. **Run the Docker Container:**
   ```bash
   docker run -it --rm jaksel-cpp
   ```
   This command starts the interpreter in an isolated environment.

## Usage

1. **Prepare your `.jaksel` file:**

   Create a file named `main.jaksel` in the repository root and add your Jaksel slang code. For example:

   ```plaintext
   # Example Jaksel Code
   gimme <iostream>
   yang std;
   int a is 12 which is
   spill "The value of a is: " then a enter
   begitulah 0 which is
   ```

2. **Convert and Compile (Locally):**

   Run the main interpreter program to convert your `.jaksel` file to standard C++ and compile it automatically:

   ```bash
   ./JakselInterpreter
   ```

   This command will:
   - Read the `main.jaksel` file.
   - Generate an `output.cpp` file with the converted code.
   - Compile `output.cpp` into an executable (`output.exe` on Windows or `output` on Linux/macOS).
   - Run the generated executable and display the program output.

3. **Run the Executable Manually (Optional):**

   If needed, you can run the generated executable manually:
   - On Windows:
     ```bash
     output.exe
     ```
   - On Linux/macOS:
     ```bash
     ./output
     ```

4. **Convert and Compile (Docker):**

   If using Docker (recommended for a reproducible build):
   - Follow the Docker build instructions above.
   - Running the container will automatically execute your interpreter, which reads `main.jaksel`, converts it, compiles it, and runs the resulting executable.

## Jaksel Slang Keywords

The interpreter uses a predefined mapping of Jaksel slang to standard C++ tokens. Here are some examples:

| Jaksel Slang             | C++ Translation      |
|--------------------------|----------------------|
| "which is"               | `;`                  |
| "spill"                  | `std::cout <<`       |
| "begitulah"              | `return`             |
| "kalo"                   | `if`                 |
| "gitu"                   | `else`               |
| "nomer"                  | `int`                |
| "nonbinary"              | `bool`               |
| "selama"                 | `while`              |
| "plus"                   | `+`                  |
| "mines"                  | `-`                  |
| "is"                     | `=`                  |
| "enter"                  | `std::endl`          |
| "start oi"               | `{`                  |
| "thats literally it"     | `}`                  |
| "mana woi"               | `std::cin >>`        |
| "coba"                   | `for`                |
| "gimme"                  | `#include`           |
| "yang"                   | `using namespace`    |
| "letter"                 | `char`               |
| "sama"                   | `==`                 |
| "ga ada"/"gak ada"       | `nullptr`            |
| "gak"                    | `!`                  |
| "floaty boi"             | `float`              |
| "desimal"                | `double`             |
| "then"                   | `<<`                 |

You can expand or modify these mappings in the source code file `JakselMappings.cpp` as needed.

## Contributing

Contributions are welcome! If you have ideas for more Jaksel slang keywords or improvements to the interpreter, feel free to fork the repository and submit a pull request.

## License

This project is licensed under the **Creative Commons v1.0** License.

## Acknowledgments

- Inspired by creative approaches to language design and code transformation.
- Although creative, the hilarious syntax rules are utterly diabolical 🤣.
- Thanks to all contributors who help keep this project innovative and fun.

#### Happy coding, may creativity continues flowing in every line of code!