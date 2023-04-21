#ifndef L1_PROJETC_SHAPE_H
#define L1_PROJETC_SHAPE_H

typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;


typedef struct {
    int pos_x;
    int pos_y;
}Point;

typedef struct {
    Point *p1;
    Point *p2;
}Line;

typedef struct {
    Point * p;
    int length;
}Square;

typedef struct {
    Point * p;
    int width;
    int height;
}Rectangle;

typedef struct {
    Point * p;
    int radius;
}Circle;

typedef struct {
    int n;
    Point ** points; // tableau 1D dynamique de Point*
}Polygon;

typedef struct {
    unsigned int id; // identifiant unique de la forme
    SHAPE_TYPE shape_type; // type de la forme pointé
    void *ptrShape; // pointeur sur n'importe quelle forme
}Shape;

#define SHAPE_MAX 100 // Nombre maximum de formes
#define BOOL int
typedef struct area {
    unsigned int width; // Nombre de pixels en largeur ou nombre de colonnes (axe y)
    unsigned int height; // Nombre de pixels en hauteur ou nombre de lignes (axe x)
    BOOL** mat; // Matrice des pixels de taille (width * height)
    Shape* shapes[SHAPE_MAX]; // Tableau des formes;
    int nb_shape; // Nombre de formes dans le tableau shapes (taille logique)
} Area;

typedef struct {
    int px;
    int py;
} Pixel;



Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radus);
Shape *create_polygon_shape(int lst[], int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);



#endif //L1_PROJETC_SHAPE_H
