
# 3D Transformation System

**Author:** Saurabh Chikate  
**Language:** C++  
**Domain:** 3D Geometry / CAD / Graphics  

---

## 🚀 Project Overview

The **3D Transformation System** is a C++ application that performs 3D geometric transformations using **vectors** and **matrices**.  
It allows you to apply **translation, rotation, and scaling** on 3D points, demonstrating fundamental concepts used in CAD and visualization software.

Key highlights:  
- Implementation of **Matrix4x4** and **Vector3D** classes.  
- Operator overloading for **matrix-vector** and **matrix-matrix** operations.  
- Strong use of **OOP principles** (encapsulation, static methods, constructors).  
- Handles **homogeneous coordinates** for transformations.  

---

## 🛠 Features

- Translate, scale, and rotate a 3D vector.  
- Combine multiple transformations in any order.  
- Interactive console input for dynamic testing.  
- Easy-to-read output of transformed vectors.  

---

## 💻 How to Run

1. Clone or download the project.
2. Ensure you have the following files:
   - `vector3d.h`
   - `matrix4x4.h`
   - `main.cpp`
3. Compile using a C++ compiler (e.g., g++):
   ```bash
   g++ main.cpp -o Transform3D
````

4. Run the program:

   ```bash
   ./Transform3D
   ```
5. Follow the on-screen prompts to input vectors and apply transformations.

---

## 🧩 Example

```
Enter vector (x y z): 1 2 3
Choose Transformation: 2
Enter scale (sx sy sz): 2 2 2
Choose Transformation: 1
Enter translation (tx ty tz): 1 0 0
Choose Transformation: 6
Original Vector: Vector3D(1, 2, 3)
Transformed Vector: Vector3D(3, 4, 6)
```

---

## 📚 Skills Demonstrated

* C++ programming & OOP
* Operator overloading
* 3D vector and matrix mathematics
* Understanding of CAD/graphics transformation principles

---

## ✨ Author

**Saurabh Chikate**
Passionate about C++ and 3D geometry transformations, exploring CAD and graphics programming.
