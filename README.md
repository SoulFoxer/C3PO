# C3PO Interpreter

C3PO is a small experimental interpreter for a custom programming language that I'm building from scratch.  
The main goal of this project is to **learn by doing** — to understand the full process of implementing a programming language, from lexing and parsing to AST generation and interpretation.

## Supported Syntax

### Variable Declarations
```c
var x = 42;
var name = "Claude";
var count = 100;
var message = "Hello World";
```

### Mixed Programs
```c
TODO
```

## Supported Data Types

- **Integer** - `42`, `100`, `0`
- **String** - `"Hello"`, `"C3PO"`

## Example Output

**Input:**
```c
var x = 42;
var name = "Alice";
```

**AST Output:**
```
VariableDeclarationStatement(x = 42)
VariableDeclarationStatement(name = "Alice")
```

## Roadmap

**Completed:**
- [x] Variable declarations (int, string)
- [x] String literals support
- [x] For loop blocks
- [x] Lexer and Parser

**Planned:**
- [ ] Arithmetic expressions (`+`, `-`, `*`, `/`)
- [ ] Conditional statements (`if`, `else`)
- [ ] Print statements
- [ ] Actual interpretation/execution
- [ ] Symbol table and scope management
- [ ] Function declarations and calls
- [ ] Arrays and data structures

## Goals

- Explore the internals of interpreters (lexing, parsing, AST, semantic analysis, and execution)
- Build a simple but functional language to experiment with new ideas
- Keep the code modular and easy to extend as the language evolves
- Learn C++ best practices through hands-on implementation

## Building the Project
```bash
mkdir build
cd build
cmake ..
make
./C3PO
```

## License

MIT License - See [LICENSE](LICENSE) file for details