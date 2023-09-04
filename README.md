# libgraph

Graphical library for opening and drawing on a window, using the minilibx as a base for simplicity, the library was initially developed with the FDF project of the 42 school in mind, but focused on modularity and versatility for working with vectors.  

Version history
- 0.3.4 (wireframe)
	- fused functions:  
		- fdf_check_map + fdf_apply_depth:  
		- = fdf_read_map;
- 0.3.3 (wireframe)  
	- changed functions:  
		- fp_putline;  
		- fp_isometric;  
	- new test:  
		- map_test; 
	- new MACROS:  
		- PRECISION;  
		- HGHT_SCL; 
	- .PHONY += tests clean_tests re_tests;   
- 0.3.2 (wireframe)  
	- new functions:
		/fdf  
		- fdf_check_map;  
		- fdf_apply_depth;  
		- fdf_draw_map; 
		/graphics  
		- fp_new_frame;  
		- fp_erase_frame;   
	- structures:  
		/fdf.h  
		- t_fdfdata;  
		/libgraph.h  
		- t_wireframe + (int)color;
	- new tests:  
		- map_test;  
		- draw_test;  
- 0.3.1 (wireframe)  
	- obsolete functions:  
		/src -> obsolete  
		- fp_open_map;  
		- fp_draw_map;  
		- fp_close_map;  
	- new functions:  
		/graphics  
		- fp_new_frame;  
			- st_relate_center;  
			- st_relate_sides;  
		- fp_erase_frame;  
	- new structures:  
		/libgraph.h  
		- t_wireframe;  
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
