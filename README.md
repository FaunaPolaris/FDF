# graphics
## minilibx graphical projects  

## DEPENDENCIES  

- minilibx (graphical library based on X11 used in 42);  
    To sucesfully compile the programs you should initialize the submodules of this repository, then run the *configure* program inside of the minilinx folder.  
- libft (1.2.1);  

## DESCRIPTION  

This repository is my first graphical exploration; created as the repository for the *fdf* project of the 42 curriculun, you can compile and run it and other programs:  
- fdf;
    This program will receive one parameter which will be a .fdf file representing a map already parsed such as:  

    1 2 3 4 5   
    0 1 2 3 4  
    0 0 1 2 3  
    0 0 0 1 2  
    0 0 0 0 1  

    The program will project the map in a isometric view, taking its *x* and *y* position from its lireal positions on the grid, and its *z* postion based on the number described; aditionally, each position on the map can specify a color in the format "1,0xFFFFFF", if no color is specified, white will be used as a default; colors are lerped between points on the map.  
    test maps can be found on 'utils/maps', or created manually, note that a valid map has the same ammount of collumns and rows.  

- Conway;  
    This program will receive three parameters: [screen width] [screen height] [starting cells]; utilizing the minilibx, the program will open a screen and project on the screen [starting cells] pixels on random positions, then, start to update the screen seeing each pixel as a cell to behave according to Conway's Game of Life rules.  
    know bug: The wireframe structure from libft 1.2.1 have a left-right adjacency issue, causing cells to multiply rapidly when reaching the right side of the screen.  

- Butterfly;  
    This program will project onto a window the butterfly formula, drawing it slowly.  

- Perlin;  
    This is a simple test program which will open perlin noise pattern screens.  
