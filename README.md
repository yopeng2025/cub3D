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
    * **Dynamic Lighting Logic**: To simulate a fixed **Southeastern Sun**, the parser handles specific texture assignments (NO, SO, EA, WE) to mimic realistic                                       light and shadow casting based on wall orientation.

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

## 🛠️ Usage & Compilation

### 1. Mandatory Part
```bash
make
./cub3D maps/map1.cub
```
### 2. Bonus Part
```bash
make bonus
./cub3D_bonus maps/map1.cub
```




