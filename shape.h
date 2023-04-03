//
// Created by 33611 on 24/03/2023.
//



#ifndef L1_PROJETC_SHAPE_H
#define L1_PROJETC_SHAPE_H



Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radus);
Shape *create_polygon_shape(int lst[], int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);


unsigned int get_next_id();


#endif //L1_PROJETC_SHAPE_H
