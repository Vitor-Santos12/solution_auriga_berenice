## Tasks: Forest Fire

### Overview

This project involves developing a C++ program that simulates forest fire detection using airplanes. The program reads input data representing airplane flight paths over a square forest area and determines if the entire area was fully observed.

### Project Structure

```
Task1_Forest_Fire/
├── CODE/
│   ├── data/
│   │   ├── INPUT
│   │   ├── OUTPUT
│   ├── input_file_generator.h
│   └── input_file_verifier.h
│   └── main.cpp
├── doc/
│   ├── distance_expression.png
│   ├── Solution.MD
│   ├── Test LW photo.jpg
│   └── Test_task1_LW.MD
└── README.MD

```

### Directories 

* [Task1: Forest Fire](Task1_Forest_Fire/doc/Test_task1_LW.MD)
* [Solution](Task1_Forest_Fire/doc/Solution.MD)

### About the Generate INPUT file function

This line code generate a new "INPUT" file every run. 
```cpp
generateInputFile("Task1_Forest_Fire/CODE/data/INPUT");
``` 
If you choose to main the last INPUT file comment it. 
```cpp
//generateInputFile("Task1_Forest_Fire/CODE/data/INPUT");
``` 