# cub3D - My First Raycaster with miniLibX

**Inspired by the world-famous 90's game Wolfenstein 3D, this project explores the Raycasting technique to create a dynamic 3D graphical interface with advanced game mechanics.**



## 🧠 Key Learning Objectives

* **🟢 Raycasting Engine**: Implementing the DDA (Digital Differential Analyzer) algorithm to transform a 2D grid into a 3D perspective.
* **🔵 Event Handling**: Managing complex keyboard/mouse inputs for fluid player movement and interaction.
* **🟡 Map Parsing**: Building a robust configuration parser for `.cub` files with comprehensive error handling.
* **🔴 Game Logic (Bonus)**: Implementing spatial awareness through a real-time Minimap and solid physics via Wall Collision.




## 📂 Project Breakdown

### 🟢 Part 1: Parsing & Validation
* **Goal**: Read and validate the `.cub` configuration file.
* **Concepts**:
    * **Textures & Colors**: Extracting wall paths and RGB values for floor/ceiling.
    * **Map Integrity**: Ensuring the map is fully enclosed by walls and the starting position is unique.

### 🔵 Part 2: Core Rendering
* **Goal**: High-performance pixel manipulation.
* **Concepts**:
    * **DDA Algorithm**: Efficiently calculating the distance to the nearest wall slice.
    * **Texture Mapping**: Correctly aligning 2D image pixels to 3D vertical wall projections.
    * **Fisheye Correction**: Using trigonometry to ensure perpendicular distance for a realistic view.



### 🟡 Part 3: Bonus Features (Implemented)
* **Goal**: Enhancing immersion and gameplay mechanics.
* **Features**:
    * **🗺️ Minimap**: A real-time 2D HUD overlay providing spatial orientation and displaying the player's current position/direction.
    * **🧱 Wall Collision**: Advanced movement logic that prevents the player from "phasing" through walls, calculated by checking the hitbox against the map grid.

### 🔴 Part 4: Technical Polish
* **Goal**: Stability and smooth performance.
* **Concepts**:
    * **Movement & Rotation**: Smooth $W, A, S, D$ and arrow key transitions.
    * **Memory Management**: Ensuring all MLX pointers and image buffers are properly freed on exit.


## 🚀 Technical Requirements
* **Graphics Library**: `miniLibX`.
* **Language**: C (Norminette compliant).
* **Compiler**: `cc` with `-Wall -Wextra -Werror`.
* **Math**: Vector arithmetic and Trigonometry (sin/cos).



### 💡 Implementation Details:
1. **Collision Logic**: Instead of just checking if the new `x, y` is a wall, I implemented a small "hitbox" buffer to ensure the player doesn't get stuck in the corners.
2. **Minimap Scaling**: The minimap uses a dedicated image buffer to render tiles and the player's position, scaled dynamically to maintain visibility without obstructing the main view.

