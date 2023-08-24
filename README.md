# libgraph
Version history
- 0.2.2 (map) 
	- changed functions:  
		/src  
		- fp_open_map;  
		- fp_draw_map;  
		/graphics  
		- fp_putline;  
	-new MACROS:  
		- SCALE;   
- 0.2.1 (map)  
	- new library "fdf.h";  
	- new functions:  
		/src  
		- fp_open_map;  
		- fp_close_map;  
		- fp_draw_map;  
	- new structs:  
		t_map;  
- 0.1.7 (libft);  
	- linked libft to Makefile;  
- 0.1.6 (The Cube);  
	- new functions:  
		/graphics  
		- fp_putline;  
		- fp_set_all;  
- 0.1.5 (The Cube);
	- new functions:  
		/graphics  
		- fp_putvector;  
		- fp_rect;  
		- fp_rotxvector;  
- 0.1.4 (True butterfly)  
	- inverted the Y for the formula of the butterfly;  
	- Corrected order of operations in formula;  
- 0.1.3 (The butterfly effect)  
	- new functions:  
		/graphics  
		- fp_find_center;  
		- fp_butterfly;
	- new headers:  
		- colors.h;  
		- formulas.h;  
	- new executable:  
		- formulas;  
		- mlx_test;  
- 0.1.2 (learning mlx)  
	- new functions:  
		/graphics  
		- fp_putpixel;  
	- fixed:  
		/graphics  
		- fp_graphical_end;  
- 0.1.1 (learning mlx)  
	- new functions:  
		/graphics  
		- fp_graphical_init;  
		- fp_graphical_end (leaking);  
	- new headers:
		- libgraph;  
	- new MACROS:  
		- WIDTH;  
		- HEIGHT;  
