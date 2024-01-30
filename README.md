# FDF
## What is it?
FDF, short for Fil de Fer (french for Wireframe), is a graphical program to display wireframe models from a text file.
The program uses the minilibx library for the graphic display.

## How to use
Clone the repo and run ```make```, the binary will be compiled under the name ```fdf```.

You can run the program by using ```./fdf input_file```.
Where ```input_file``` is a text file in the correct format (see below), otherwise an error will be displayed.

## Accepted files (.fdf)
1. A map is defined by the contents of a file.
2. Maps should contain only numbers, whitespaces (ascii 32), and newlines (ascii 10).
3. Each number represents a vertex on the model. The X,Y coordinates are taken from the Column,Row position in the file respectively.
4. The Z coordinate is taken from the value of the number.
5. Maps have to be rectangles (so all lines have to be the same length, and yes [squares are indeed rectangles](https://math.okstate.edu/geoset/Projects/Ideas/SquareRect.htm)).
6. Colors can be given to maps in uppercase hexadecimal format, following each number by a comma (```10,0xFF22FF```).
7. There are multiple example maps in the ```maps``` folder, for more ideas.
