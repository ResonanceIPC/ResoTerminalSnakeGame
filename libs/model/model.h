// Declaring new type for model
extern struct Model active_model;

// Declaring functions for global use
void set_default_active_model();

// Declaring model as struct
struct Model {
    int height;
    int width;
    int speed;
    char empty_char;
    char border_char;
    char snake_char;
    char apple_char;
    int empty_char_color;
    int border_char_color;
    int snake_char_color;
    int apple_char_color;
    int horizontal_border_width;
    int vertical_border_width;
    int selftouch;
};