# 🏰 Cub3D

## 📖 About

Cub3D is a graphic design project inspired by the world-famous Wolfenstein 3D game. This project is focused on creating a dynamic view inside a maze using raycasting techniques.

## 🎯 Objectives

- Create a 3D graphical representation of a maze from a first-person perspective
- Implement raycasting for rendering
- Handle different wall textures based on orientation
- Manage player movement and rotation
- Parse and validate map files

## 🛠️ Features

- Render a 3D maze using raycasting
- Display different textures for walls facing north, south, east, and west
- Implement distinct floor and ceiling colors
- Handle player movement (W, A, S, D keys) and camera rotation (left/right arrow keys)
- Parse .cub map files for scene description
- Manage window events (minimize, close)

## 🗺️ Map Format

The map must be composed of only 6 possible characters:
- `0` for empty space
- `1` for walls
- `N`, `S`, `E`, or `W` for the player's start position and orientation

Example:
```
111111
100101
101001
1100N1
111111
```

## 🚀 Usage

```
./cub3D path_to_map.cub
```

## ⚙️ Installation

1. Clone the repository:
   ```
   git clone https://github.com/your-username/cub3d.git
   ```
2. Navigate to the project folder:
   ```
   cd cub3d
   ```
3. Compile the project:
   ```
   make
   ```

## 🕹️ Controls

- `W`, `A`, `S`, `D`: Move the player
- `←`, `→`: Rotate the camera
- `ESC`: Exit the game

## 🖼️ Texture Configuration

In the .cub file, specify textures and colors as follows:

```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
```

Where `F` represents floor color and `C` represents ceiling color (RGB format).

---

Made with ❤️ as part of the 42 School curriculum.