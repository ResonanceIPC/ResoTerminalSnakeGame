int request_width(void);
int request_speed(void);
int request_height(void);
int request_density(void);
int request_pattern(void);
char request_dead_symbol(void);
char request_alive_symbol(void);
char request_dead_color(void);
char request_alive_color(void);
char ** request_born_neighbours(void);
char ** request_survive_neighbours(void);
int get_option_to_edit(Model model);
int display_main_menu();
void display_start_animation(int,int);
int display_default_models_menu();
void display_help();

extern int SCREEN_HEIGHT;
extern int SCREEN_WIDTH;