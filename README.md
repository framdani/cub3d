## cub3d
A representation of a 3D first-person maze using raycasting, similar to Wolfenstein 3D.

## Prerequisites
The project runs using the MiniLibX. It can therefore only run in MacOS, preferably on a computer with a solid CPU.

## The mandatory part
To test the original game : [Wolfenstein](http://users.atw.hu/wolf3d/).

The basic program that was required to pass. It only includes wall textures and a sprite ; no floor/ceiling textures, no weapons, no enemies.

## Usage
```
# generate the executable
make

# To launch it
./cub3D maps/map.cub

# To save a screenshoot
./cub3D maps/map.cub --save
```
## controls

* You can move around the maze with <span color ="red">W</span> A S D.

* You can also rotate the view with the directional arrows ← and →.

* To exit the game, press ESC or click the red cross.

## Some resources

[Minilibx Documentation](https://harm-smits.github.io/42docs/libs/minilibx/events.html)

[Images in Minilibx](https://github.com/keuhdall/images_example)

[Raycasting](https://lodev.org/cgtutor/raycasting.html)

[BMP format](https://lmcnulty.gitlab.io/blog/bmp-output/)


