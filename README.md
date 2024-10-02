# Python to UML Diagram Generator Using C++

## 📜 Overview

Welcome to the **Python to UML Diagram Generator Using C++**! This project allows you to parse Python classes, extract their methods and inheritance relationships, and generate UML diagrams in the DOT format. By leveraging C++ for parsing, this tool provides a seamless bridge between Python's dynamic nature and the robust capabilities of C++ for visualization.

## 🚀 Features

- **Class Parsing**: Automatically analyzes Python classes and their relationships.
- **Method Extraction**: Retrieves methods for each class, including constructors.
- **Inheritance Visualization**: Displays class hierarchies using directed edges in the UML diagram.
- **DOT Format Output**: Generates output in DOT format, easily convertible to images using Graphviz.
- **Customizable**: Easily modify the parsing logic to accommodate additional Python features.

## 💻 Prerequisites

Before you begin, ensure you have the following installed:

- **C++ Compiler**: Ensure you have a working C++ compiler (like g++, clang++, or MSVC).
- **CMake**: A tool to build your C++ project.
- **Graphviz**: For visualizing DOT files. Install Graphviz from [here](https://graphviz.gitlab.io/download/).
- **nlohmann/json**: A C++ library for handling JSON. You can include it via CMake or download it from [GitHub](https://github.com/nlohmann/json).


## 📦 Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/python-to-uml-generator.git
   cd python-to-uml-generator
