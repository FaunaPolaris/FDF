# graphics

Graphical library for opening and drawing on a window, using the minilibx as a base for simplicity, the library was initially developed with the FDF project of the 42 school in mind, but focused on modularity and versatility for working with vectors.  

Version history 
- 0.5.1 (perlin noise);  
	- new functions:  
		- perlin_nowl;  
	- new programs:  
		-perlin;  
- 0.5.0 (window managment);  
	- graphics functions overhaul to open multiple windows;  
		- deleted functions: graphics_init graphics_end;  
		- new functions:
			- win_new;  
			- win_close;
		- new program:  
			- ./conway [width] [height] [cell_count]  
- 0.4.4 (math order);  
	- renamed functions:  
		- mtx_tovec;	-> vec_from_mtx;  
		- mtx_centerv	-> vec_center;  
		- mtx_newv	-> vec_new;  
		- mtx_isometry	-> vec_isometry; 
	- additions:   
		matrix.h:  
		- t_constants {double, double};  
		- mtx_init;  
		
- 0.4.3 (artisian tools);  
	- moved functions:  
		to libft:  
		- fp_lerp;
		- fp_lerpcolor;  
		from graphics to matrix:  
		- fp_isometric -> mtx_isometry;  
		- fp_unit_vector -> mtx_unitv;  
		- fp_find_center -> mtx_centerv;  
	- renamed functions:  
		- fp_graphical_init -> graphics_init;  
		- fp_graphical_end -> graphics_end;  
		- fp_butterfly -> draw_butterfly;  
		- fp_set_all -> draw_clean;  
	- new functions:  
		graphics/ 
		- draw_pixel;   
		- draw_point	
		- draw_line;  
		- draw_square;  
		- draw_plane;  
		- draw_cube;	
		- draw_circle;  
		- draw_fill;  
		- draw_update;  
	- new tests:  
		- tool_test; 
- 0.4.2 (back to the matrix);  
	- new functions:  
		matrix/  
		- mtx_fromv;  
		- mtx_tovec;  
		- mtx_rotate;  
- 0.4.1 (lerping)  
	- new function:  
		graphics/  
		- fp_lerp;  
		- fp_lerpcolor;  
		matrix/  
		- fp_mtx_fromv;  
	- new test:  
		- lerp_test;  
- 0.4.0 (matrix)  
	- new header:  
		- matrix.h;   
	matrix functions:  
		- mtx_new;  
		- mtx_identity;  
		- mtx_multiply;   
		- mtx_fill;  
		- mtx_print;  
		- mtx_free;  
		- mtx_null;  
	new test:  
		- mtx_test;  
	OBS: ALL OTHER TESTS REMOVED;  
- 0.3.6 (rotation)  
	- new functions:  
		/graphics  
		- mtx_multiply3d;   
		- mtx_identity3;  
	- changed functions:  
		- fdf_draw_map;  
- 0.3.5 (hook)  
	- new functions:  
		/graphics  
		- fp_applymatrix;  
		- mtx_rotate;   
	- new tests:  
		- loop_rotate;   
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
