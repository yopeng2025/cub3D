# cub3D - Raycasting 3D Engine
![Demo](cub3D.gif)

A 3D maze rendering engine using raycasting. Renders first-person perspective with texture-mapped walls and real-time collision detection.


## Project Structure

```
src/
├── main.c                 # Entry point
├── parsing/              # Map/config parsing
├── raycasting/           # Ray casting engine
└── window/               # Graphics & input
```

## 1. Parsing 

**Loads configuration and validates map integrity:**

1. **Texture & Color Parsing** - Reads texture paths and RGB values
   ```c
   // Parse lines like: NO ./textures/north.xpm
   // Validates textures exist and sets floor/ceiling colors
   if (!parse_texture(fd, data, &n_line))  // Extract NO/SO/WE/EA paths
       return (false);
   if (!check_texture(data))  // Verify XPM files are valid
       return (false);
   ```

2. **Map Parsing & Validation**
   ```c
   if (!parse_map(fd, data, &n_line))  // Read 2D char grid
       return (false);
   if (!check_map(data))  // Verify surrounded by walls, one player spawn
       return (false);
   ```

3. **Player Detection** - Finds spawn position marked by N/S/E/W:
   - `N`: North-facing (0°)
   - `E`: East-facing (90°)
   - `S`: South-facing (180°)
   - `W`: West-facing (270°)

**Key validation:** Map must be rectangular, fully enclosed by walls (1), contain exactly one player spawn.

**Map format:**
```
NO ./textures/north.xpm      # Texture paths
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 80,160,90                  # Floor color (RGB)
C 135,206,235                # Ceiling color (RGB)

11111111111111111111111111111      # Map: 1=wall, 0=space, N/S/E/W=player
10000000000000010000000N00001
10000000000000010000000000001
11111111111111111111111111111
```

## 2. Raycasting

**Real-time 3D rendering using DDA (Digital Differential Analyzer):**

### Data Structures

Key struct for raycasting (from `struct.h`):
```c
typedef struct s_ray_casting {
    float ray_x;        // Ray origin x (from player position)
    float ray_y;        // Ray origin y
    float dir_x;        // Ray direction cos(angle)
    float dir_y;        // Ray direction -sin(angle)
    float ray_angle;    // Ray angle in radians
    
    int map_x;          // Current grid cell x
    int map_y;          // Current grid cell y
    float side_dist_x;  // Distance to next x grid line
    float side_dist_y;  // Distance to next y grid line
    float delta_dist_x; // Distance between x gridlines
    float delta_dist_y; // Distance between y gridlines
    int step_x;         // Direction to step (+1 or -1)
    int step_y;
    
    float wall_height;  // Computed height for drawing
    float tex_x;        // Texture x coordinate (0.0-1.0)
    int hit;            // 1 when ray hits wall
    int side;           // 0=vertical wall, 1=horizontal
} t_ray_casting;
```

### Algorithm Flow

```c
// Main casting loop - iterate over screen width
void raycasting(t_data *data) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // 1. Initialize ray from player position
        init_ray_casting(&rc, data, x);
        // ray_angle = player_rotation - (FOV/2) + (x * FOV/SCREEN_WIDTH)
        
        // 2. Cast DDA ray to find nearest wall
        perform_dda(&rc, data);
        // Step through grid cells until hitting wall
        
        // 3. Calculate perspective-corrected wall properties
        calculate_wall_properties(&rc, data);
        // Compute wall_height and texture coordinates
        
        // 4. Draw vertical column with texture
        draw_vertical_line(data, x, rc.wall_height, &rc);
    }
}
```

### DDA Ray Marching

```c
void perform_dda(t_ray_casting *rc, t_data *data) {
    rc->hit = 0;
    while (!rc->hit) {
        // Compare distances to next grid boundary (x or y)
        if (rc->side_dist_x < rc->side_dist_y) {
            rc->side_dist_x += rc->delta_dist_x;
            rc->map_x += rc->step_x;  // Move x cell
            rc->side = 0;  // Record x-side hit
        } else {
            rc->side_dist_y += rc->delta_dist_y;
            rc->map_y += rc->step_y;  // Move y cell
            rc->side = 1;  // Record y-side hit
        }
        // Check if current cell is wall (value '1' in map)
        if (data->map->map_2d[rc->map_y][rc->map_x] == '1')
            rc->hit = 1;
    }
}
```
**Why DDA?** Efficiently steps through grid while maintaining sub-pixel accuracy. O(n) where n = grid traversal steps (typically 10-40).

### Wall Distance & Texture Mapping

```c
void calculate_wall_properties(t_ray_casting *rc, t_data *data) {
    // Calculate perpendicular distance (prevents fish-eye)
    float ray_dist = calculate_wall_dist(rc);
    
    // Perspective correction: wall_height ∝ 1 / (distance * cos(angle_diff))
    float angle_diff = normalize_angle_diff(rc->ray_angle - player_rotation);
    rc->wall_height = SCREEN_HEIGHT / (ray_dist * cos(angle_diff)) * 0.75;
    
    // Calculate X position within texture (0.0 - 1.0)
    if (rc->side == 0)  // Hit vertical wall
        wall_hit_fraction = ray_y + ray_dist * dir_y;
    else                 // Hit horizontal wall
        wall_hit_fraction = ray_x + ray_dist * dir_x;
    rc->tex_x = wall_hit_fraction - floor(wall_hit_fraction);
    
    // Select texture based on wall direction
    // East-facing: TEXTURE_EA, West: TEXTURE_WE, etc.
    rc->texture_index = get_texture_index(rc);
}
```

### Rendering Textured Column

```c
// For each pixel in the column:
// - Map vertical screen position to texture V coordinate (0-texture_height)
// - Fetch RGB from texture[tex_x][tex_y]
// - Write to framebuffer
```

**Key insight:** Wall height inversely proportional to distance. Texture stretches
to fill the column, creating perspective illusion.



## Build

**Dependencies:**
```bash
# Ubuntu/Debian
sudo apt-get install -y libx11-dev libxext-dev libxrandr-dev libxinerama-dev libbsd-dev

# macOS
brew install x11
```

**Compile:**
```bash
make && ./cub3D map/1.cub
```

**Controls:** `W/A/S/D` = Move/Turn, `ESC` = Exit
